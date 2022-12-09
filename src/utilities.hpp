#ifndef UTILITIES_HPP_INCLUDED
#define UTILITIES_HPP_INCLUDED

#include <tuple>
#include <array>
#include "basic_types.hpp"

namespace utilities {
template<NumRepr::type_traits::unsigned_integral_c UINT_T>
using uintspair 	= typename std::array<UINT_T,2>;
template<NumRepr::type_traits::unsigned_integral_c UINT_T,UINT_T B>
using uintspairlist = typename std::array<uintspair<UINT_T>,B>;
template<NumRepr::type_traits::unsigned_integral_c UINT_T,UINT_T B>
using uintspairtbl	= typename std::array<uintspairlist<UINT_T,B>,B>;

/// template<class type_0, class type_1, ... , class type_Nm1>
/// struct apilamiento_de_tipos_t {
///    type_0     obj_0;
///    type_1     obj_1;
///    ......     .....
///    type_Nm1   obj_Nm1;
/// };
/// example:
/// apilamiento_de_tipos<int,std::string,double> objeto{1,"abc",2.98105};
/// objeto.obj_0   == 1;
/// objeto.obj_1   == "abc";
/// objeto.obj_Nm1 == 2.98105;
/// A partir del estandar de C++11
/// template<class ...type_i>
/// struct apilamiento_de_tipos_t {
///    type_0     obj_0; 	// sabemos type_i pero no type_0
///    type_1     obj_1; 	// sabemos type_i pero no type_1
///    ......     .....
///    type_Nm1   obj_Nm1;// sabemos type_i pero no type_Nm1
/// };
/// type_i es un PACK
/// tipo std::tupla<class ... Ts>;

template<typename...Ts>
struct pack2tuple {
	using tuple_type = std::tuple<Ts...>;
	static constexpr unsigned pack_size() noexcept {return (sizeof...(Ts));}
	constexpr tuple_type operator()(Ts&& ...args) noexcept {
		tuple_type  content = std::make_tuple(std::forward(args...));
		return  std::move(content);
	}
	template<unsigned K>
	using elem_type =  typename std::tuple_element<K,tuple_type>::type;
	template<unsigned J>
	static constexpr elem_type<J>::type get(Ts&& ...args) noexcept {
		tuple_type  content = std::make_tuple(std::forward(args...));
		elem_type<J> ret{std::get<J>(std::forward(content))};
		return ret;
	}
};
/// EXAMPLE
/// pack2tuple<int,std::string,double>; // tipo
/// pack2tuple<int,std::string,double>::tuple_type == std::tuple<int,std::string,double>; // tupla
/// using mi_tupla = pack2tuple<int,std::string,double>::tuple_type;
/// pack_size() devuelve 3
/// mi_tupla(2,"xyz",3.14159) devuelve la tupla {2,"xyz",3.14159} // por copia o por movimiento
/// elem_type<0> es int
/// elem_type<1> es std::string
/// elem_type<2> es double
/// get<0>(2,"xyz",3.14159) == 2;
/// get<1>(2,"xyz",3.14159) == "xyz";
/// get<2>(2,"xyz",3.14159) == 3.14159;

/// tuple_obj == mi_tupla(2,"xyz",3.14159) == {2,"xyz",3.14159}
/// head of tuple_obj is {2}
/// tail of tuple_obj is {"xyz",3.14159}
/// BEGIN: TEMPLATE GENERICO Y SUS ESPECIALIZACIONES

struct local_void_t {};

template<class Head_t,class...Tail_t>
struct for_each_same_type {
	using second_t = std::tuple_element<0,std::tuple<Tail_t...>>::type;
	constexpr static
	bool are_same_type_v = (
        (std::is_same_v<Head_t,second_t>)
		&&	(for_each_same_type<Tail_t...>::are_same_type_v)
	);
};

template<class Head_t>
struct for_each_same_type<Head_t> {
	constexpr static bool are_same_type_v = true;
};

template<typename...Ts>
concept all_are_the_same_type_c = requires(Ts...) {
	for_each_same_type<Ts...>::are_same_type_v;
};

template<typename...Ts>
concept there_is_one_or_more_c = requires(Ts...) {
	((sizeof...(Ts))>0);
};

/// END: 	TEMPLATE GENERICO Y SUS ESPECIALIZACIONES

template<typename...Ts>
	requires  (all_are_the_same_type_c<Ts...>&&there_is_one_or_more_c<Ts...>)
struct pack2array {
	using array_type = std::array<
						typename pack2tuple<Ts...>::elem_type<0>,
						(sizeof...(Ts))
					>;
	static constexpr std::size_t pack_size() noexcept {
		return (sizeof...(Ts));
	}

	constexpr array_type&& operator()(Ts&& ...args) const noexcept {
		constexpr array_type  content = array_type{std::forward(args...)};
		return  std::move(content);
	}

	using elem_type =  typename pack2tuple<Ts...>::elem_type<0>;

	template<std::size_t J>
	static constexpr elem_type get(Ts&& ...args) noexcept {
		constexpr array_type  content = {std::forward(args...)};
		constexpr elem_type ret{std::get<J>(std::forward(content))};
		return std::move(ret);
	}

	/// ESTA FUNCION AUXILIAR ES NECESARIA
	/// PARA UNA POSTERIOR EXPANSION DEL
	/// PARAMETER PACK

	template <std::size_t... I>
	static constexpr void for_each_impl(
		array_type& iarray,
		const Ts&...args,
		std::index_sequence<I...>
	) noexcept
	{
		( ( iarray[I] = std::get<I>( std::make_tuple(args...) ) ) , ...);
		return;
	}

	static constexpr
	void for_each(array_type& iarray,const Ts&...args) noexcept {
		constexpr unsigned size_of_pack{sizeof...(args)};
		for_each_impl(
			iarray,
			args...,
			std::make_index_sequence<size_of_pack>{}
		);
		return;
	}
};

template<class... Ts>
	requires	(
			  all_are_the_same_type_c<Ts...>
		&&	there_is_one_or_more_c<Ts...>
	)
void assign_with_order(
	auto& dest ,
	const Ts&... args
	) noexcept
{
	pack2array<Ts...>::for_each(dest,args...);
	return;
}
/// LA LLAMADA "REAL" ES
///
///			assign_with_order(dest,args...);
///
/// donde los "args" son de tipo "Ts" (que es uno solo, todos iguales entre si)
}

#endif // UTILITIES_HPP_INCLUDED
