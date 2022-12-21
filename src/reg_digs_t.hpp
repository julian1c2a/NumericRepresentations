#ifndef REG_DIGS_T_HPP_INCLUDED
#define REG_DIGS_T_HPP_INCLUDED

#include "dig_t.hpp"
#include "utilities.hpp"
#include "lexer_parser.hpp"

namespace NumRepr {

using type_traits::uint_type_for_radix_c;
using type_traits::suitable_base;

template<uint_type_for_radix_c UINT_T,UINT_T B,size_t L>
  requires ((suitable_base<UINT_T,B>())&&(L > 0))
struct reg_digs_t : protected std::array<dig_t<UINT_T,B>,L> {
public :

	using dig_t 				= dig_t<UINT_T,B>;

	template<size_t N>
		requires (N>0)
	using base_N_t      = std::array<dig_t,N>;

	using base_t				= base_N_t<L>;

	template<size_t N>
	using reg_N_digs_t  = reg_digs_t<UINT_T,B,N>;

	/// devolucion de punteros a la clase base
	inline const base_t* const const_base_this() const noexcept {
		return static_cast<const base_t* const>(this);
	}

	inline base_t* base_this() noexcept {
		return static_cast<base_t*>(this);
	}
	/// devolucion de referencias a la clase base
	inline base_t& r_base_cthis() noexcept {
		return (*base_this());
	}
	/// devolucion de copia de la clase base
	inline const base_t& cr_base_cthis() const noexcept {
		return (static_cast<const base_t&>(*const_base_this()));
	}

	inline base_t cp_base_cthis() const noexcept {
		return std::move(base_t{*(cr_base_cthis())});
	}
	/// devolucion de referencias de la clase actual
	inline reg_digs_t & r_cthis() noexcept {
		return (*this);
	}

	inline const reg_digs_t & cr_cthis() const noexcept {
		return (*this);
	}
	/// devolucion de copia de la clase actual
	inline reg_digs_t cp_cthis() const noexcept {
		return reg_digs_t{*this};
	}
	/// devoluciones por referencias y por copia de los elementos
	inline dig_t cp_cthis_at(size_t k) const noexcept {
		return cp_base_cthis()[k];
	}

	inline dig_t & r_cthis_at(size_t k) noexcept {
		return (r_base_cthis()[k]);
	}

	inline const dig_t & cr_cthis_at(size_t k) const noexcept {
		return (cr_base_cthis()[k]);
	}


public :

	using SIG_UINT_T = typename type_traits::sig_UInt_for_UInt_t<UINT_T>;
	using SIG_SINT_T = typename type_traits::sig_SInt_for_UInt_t<UINT_T>;

	template<binop_e op,size_t N>
	using res_base_N_op_t	=
		typename auxiliary_types::result_operation_t<base_N_t<N>,op,N>;

	template<binop_e op>
	using res_base_op_t		=
		typename auxiliary_types::result_operation_t<base_t,op,L>;

	static consteval dig_t		dig_0()			noexcept
	{return dig_t::dig_0();}
	static consteval dig_t		dig_1()			noexcept
	{return dig_t::dig_1();}
	static consteval dig_t		dig_Bm1()		noexcept
	{return dig_t::dig_Bm1();}
	static consteval dig_t 		dig_Bm2()		noexcept
	{return dig_t::dig_Bm2();}
	static consteval UINT_T		ui_0()			noexcept
	{return dig_t::ui_0();}
	static consteval UINT_T		ui_1() 			noexcept
	{return dig_t::ui_1();}
	static consteval UINT_T		ui_Bm1() 		noexcept
	{return B-1;}
	static consteval UINT_T		ui_B() 			noexcept
	{return B;}
	static consteval SIG_UINT_T	sui_0()		noexcept
	{return dig_t::sui_0();}
	static consteval SIG_UINT_T	sui_1() 	noexcept
	{return dig_t::sui_1();}
	static consteval SIG_UINT_T sui_Bm1() noexcept
	{return dig_t::sui_B()-1;}
	static consteval SIG_UINT_T	sui_B() 	noexcept
	{return dig_t::sui_B();}
	static consteval SIG_UINT_T sui_Bp1() noexcept
	{return dig_t::sui_B()+1;}
	static consteval SIG_SINT_T	ssi_0()		noexcept
	{return dig_t::ssi_0();}
	static consteval SIG_SINT_T	ssi_1() 	noexcept
	{return dig_t::ssi_1();}
	static consteval SIG_SINT_T ssi_Bm1() noexcept
	{return dig_t::ssi_B()-1;}
	static consteval SIG_SINT_T	ssi_B() 	noexcept
	{return dig_t::ssi_B();}
	static consteval SIG_SINT_T ssi_Bp1() noexcept
	{return dig_t::ssi_B()+1;}

	/// <summary>
	/// PARA EL TIPO-TEMPLATE BASE_N_T OBTENEMOS CONSTANTES INMEDIATAS
	/// TENEMOS CUIDADO DE CREAR UN RVALUE TEMPORAL
	/// </summary>

	template<size_t N>
	static consteval
	base_N_t<N>	regd_base_N_0() noexcept {
		base_N_t<N> ret;
		for(dig_t& dig : ret) {
			dig = dig_0();
		}
		return ret;
	}

	template<size_t N>
	static consteval
	base_N_t<N>	regd_base_N_1() noexcept {
		base_N_t<N> ret{regd_base_N_0<N>()};
		ret[0] = dig_1();
		return ret;
	}

	template<size_t N>
	static consteval
	base_N_t<N>	regd_base_N_Bm1() noexcept {
		base_N_t<N> ret{regd_base_N_0<N>()};
		ret[0] = dig_Bm1();
		return ret;
	}

	template<size_t N>
	static consteval
	base_N_t<N>	regd_base_N_B() noexcept {
		base_N_t<N> ret{regd_base_N_0<N>()};
		ret[1] = dig_1();
		return ret;
	}

	template<size_t N,size_t n>
		requires ((n>=0)&&(n < N))
	static consteval
	base_N_t<N>	regd_base_N_pow_n_B() noexcept {
		base_N_t<N> ret{regd_base_N_0<N>()};
		ret[n] = dig_1();
		return ret;
	}

	template<size_t N,size_t n>
		requires ((n>=0)&&(n < N))
	static consteval
	base_N_t<N>	regd_base_N_pow_n_B_m1() noexcept {
		base_N_t<N> ret{};
		for(size_t ix{0} ; ix < n ; ++ix) {
			ret[ix] = dig_Bm1();
		}
		for(size_t ix{n} ; ix < N ; ++ix) {
			ret[ix] = dig_0();
		}
		return ret;
	}

	/// <summary>
	/// IDEM QUE ANTES PERO CON EL TIPO BASE_T
	/// ESPECIALIZANDO AL TIPO BASE_N_T<L>
	/// DONDE BASE_T == BASE_N_T<L>
	/// TENEMOS CUIDADO DE CREAR UN RVALUE TEMPORAL
	/// </summary>

	static consteval
	base_t regd_base_0() noexcept {
		return base_t{regd_base_N_0<L>()};
	}

	static consteval
	base_t	regd_base_1() noexcept {
		return base_t{regd_base_N_1<L>()};
	}

	static consteval
	base_t	regd_base_Bm1() noexcept {
		return base_t{regd_base_N_Bm1<L>()};
	}

	static consteval
	base_t	regd_base_B() noexcept {
		return base_t{regd_base_N_B<L>()};
	}

	static consteval
	base_t	regd_base_pow_n_B()	noexcept {
		return base_t{regd_base_N_pow_n_B<L>()};
	}

	static consteval
	base_t	regd_base_pow_n_B_m1() noexcept	{
		return base_t{regd_base_N_pow_n_B_m1<L>()};
	}

	/// <summary>
	/// IDEM QUE ANTES PERO CON LA CLASE DERIVADA, LA ACTUAL
	/// TENEMOS CUIDADO DE CREAR UN RVALUE TEMPORAL
	/// </summary>

	static consteval
	reg_digs_t regd_0() noexcept {
		return reg_digs_t{regd_base_N_0<L>()};
	}

	static consteval
	reg_digs_t	regd_1() noexcept {
		return reg_digs_t{regd_base_1()};
	}

	static consteval
	reg_digs_t	regd_Bm1() noexcept {
		return reg_digs_t{regd_base_Bm1()};
	}

	static consteval
	reg_digs_t	regd_B() noexcept {
		return reg_digs_t{regd_base_B()};
	}

	static consteval
	reg_digs_t	regd_pow_n_B()	noexcept {
		return reg_digs_t{regd_base_pow_n_B()};
	}

	static consteval
	reg_digs_t	regd_pow_n_B_m1() noexcept	{
		return reg_digs_t{regd_base_pow_n_B_m1()};
	}

public :
	/// <summary>
	/// En este bloque hacemos esta clase wrapper como si fuese una clase derivada de base_t
	/// Para esto replicamos y sobrecargamos cada una de las funciones por defecto de std::array
	/// </summary>
	constexpr decltype(auto)begin()					noexcept
	{ return base_t::begin(); }
	constexpr decltype(auto)cbegin()	const	noexcept
	{ return base_t::cbegin(); }
	constexpr decltype(auto)end()						noexcept
	{ return base_t::end(); }
	constexpr decltype(auto)cend()		const	noexcept
	{ return base_t::cend(); }
	constexpr decltype(auto)rbegin()				noexcept
	{ return base_t::rbegin(); }
	constexpr decltype(auto)crbegin()	const	noexcept
	{ return base_t::crbegin(); }
	constexpr decltype(auto)rend()					noexcept
	{ return base_t::rend(); }
	constexpr decltype(auto)crend()		const	noexcept
	{ return base_t::crend(); }

	constexpr size_t	size()		const	noexcept
	{ return base_t::size(); }
	constexpr size_t	max_size()const	noexcept
	{ return base_t::max_size(); }
	constexpr bool	empty()			const	noexcept
	{ return base_t::empty(); }

	constexpr dig_t	front()	noexcept
	{ return (this->base_t::front()); }
	constexpr dig_t const&	front()	const	noexcept
	{ return (this->base_t::front()); }
	constexpr dig_t	back()	noexcept
	{ return (this->base_t::back()); }
	constexpr dig_t const&	back()	const	noexcept
	{ return (this->base_t::back()); }

	constexpr void	fill(const dig_t& value)	noexcept
	{ this->base_t::fill(value); }
	constexpr void	swap(base_t& other)	noexcept
	{ this->base_t::swap(*other.data()); }
	constexpr void  reverse() noexcept
	{ std::reverse(this->begin(),this->end()); }

	/// <summary>
	///
	///
	///
	///    Constructores de reg_digs_t
	///
	///
	///
	/// </summary>

public:

	/// <summary>
	/// Constructor por defecto (rellena de dig_t(0) todo el array)
	/// </summary>
	consteval inline
	reg_digs_t()
	noexcept : base_t{regd_base_0()} {}

private :
	/// <summary>
	/// Funcion miembro para generar un objeto tipo base_t y
	///	devolverlo desde un std::initializer_list<dig_t>
	/// </summary>
	/// <function name="make_base_t"></function>
	/// <param name="const std::initializer_list<dig_t>& larg"></param>
	/// <returns="rarg : base_t"></returns>
	static constexpr base_t make_base_t(const std::initializer_list<dig_t>& larg) {
		base_t rarg;
		if (larg.size() >= L) {
			auto itlist{larg.begin()};
			auto itcthis{rarg.begin()};
			const auto itcthisend{rarg.end()};
			while (itcthis != itcthisend) {
				*itcthis = *itlist;
				++itcthis;
				++itlist;
			}
		}
		else {
			auto itlist{larg.begin()};
			auto itcthis{rarg.begin()};
			const auto itlistend{larg.end()};
			const auto itcthisend{rarg.end()};
			while (itcthis != itlistend) {
				*itcthis = *itlist;
				++itcthis;
				++itlist;
			}
			while (itcthis != itcthisend) {
				*itcthis = dig_0();
				++itcthis;
			}
		}
		std::reverse(rarg.begin(),rarg.end());
		return rarg;
	}

public:
	/// <summary>
	/// Constructor por lista de digitos utilizando la función make_base_t
	/// </summary>
	constexpr inline
	reg_digs_t(const std::initializer_list<dig_t> & arg)
	noexcept : base_t{make_base_t(arg)} {}

	/// <summary>
	/// Constructor por argumentos tipo dig_t: deduce el tipo
	/// </summary>
	template<typename ... Ts>
		requires (std::is_same_v<Ts,dig_t>&&...)
	constexpr inline
	reg_digs_t(const Ts &... args)
	noexcept : base_t{(utilities::pack2array<Ts...>{})(args...)} {}

	/// CONSTRUCTOR COPIA DESDE EL TIPO BASE
	constexpr inline
	reg_digs_t(const base_t & rarg) noexcept : base_t{rarg} {}
	/// CONSTRUCTOR MOVIMIENTO DESDE EL TIPO BASE
	constexpr inline
	reg_digs_t(base_t && rarg) noexcept : base_t{std::move(rarg)} {}

	/// <summary>
	/// Constructor por Copia/Movimiento desde una
	/// sucesión variádica de dígitos dig_t
	/// </summary>

private:

	/// <summary>
	/// Función miembro (delegada) para copiar un
	///	objeto tipo base_t desde una referencia constante
	///	a un array cualquiera de dig_t
	/// </summary>
	/// <function name="copy_arg_N"></function>
	/// <param name="const base_N_t<N> & arg"></param>
	/// <returns="void"></returns>
	template<size_t N>
	constexpr inline
	void copy_arg_N(const base_N_t<N> & arg) noexcept {
		base_t& cthis{*(static_cast<base_t*>(this))};
		///< Z < W or Z == W
		constexpr auto Z{std::min(N,L)};
		constexpr auto W{std::max(N,L)};
		if constexpr (Z==L) {
			for(size_t ix{0} ; ix < Z ; ++ix)
				cthis[ix]=arg[ix];
		}
		else if constexpr (W==L) {
			for(size_t ix{0} ; ix < Z ; ++ix)
				cthis[ix]=arg[ix];
			for(size_t ix{Z} ; ix < W ; ++ix)
				cthis[ix]=dig_0();
		}
		else {
			cthis=arg;
		}
	}

	/// <summary>
	/// Función miembro (delegada) para mover un objeto tipo base_t desde una
	/// referencia derecha a un array cualquiera de dig_t
	/// </summary>
	/// <function name="copy_arg_N"></function>
	/// <param name="const base_N_t<N> & arg"></param>
	/// <returns="void"></returns>
	template<size_t N>
	constexpr inline
	void move_arg_N(base_N_t<N>&& arg) noexcept {
		base_t& cthis{static_cast<base_t*>(this)};
		///< Z < W or Z == W
		constexpr auto Z{std::min(N,L)};
		constexpr auto W{std::max(N,L)};
		if constexpr (Z==L) {
			for(size_t ix{0} ; ix < Z ; ++ix)
				cthis[ix]=std::move(arg[ix]);
		}
		else if constexpr (W==L) {
			for(size_t ix{0} ; ix < Z ; ++ix)
				cthis[ix]=std::move(arg[ix]);
			for(size_t ix{Z} ; ix < W ; ++ix)
				cthis[ix]=std::move(dig_0());
		}
		else {
			cthis=std::move(arg);
		}
	}

public:

	/// <summary>
	/// Constructor copia desde un array cualquiera de dígitos dig_t (usando copy_arg_N<N>)
	/// </summary>
	template<size_t N>
	constexpr inline
	reg_digs_t(const base_N_t<N> & arg)
	noexcept : base_t{copy_arg_N<N>(arg)} {}

	/// <summary>
	/// Constructor por movimiento desde un array cualquiera de dígitos dig_t (usando move_arg_N<N>)
	/// </summary>
	template<size_t N>
	constexpr inline
	reg_digs_t(const base_N_t<N> && arg)
	noexcept : base_t{move_arg_N<N>(std::move(arg))} {}

public :

	/// <summary="Función de normalización a dig_t (dígitos base B) que construye un objeto de tipo ">
	/// </summary>
	/// <summary="base_t desde una sucesion variadica de enteros cualquiera">
	/// </summary>
	/// <function name="normalize"></function>
	/// <param name="Ints_type ... digits_pow_i"></param>
	/// <returns="base_t"></returns>
	template<typename ... Ints_type>
		requires ((sizeof...(Ints_type)) == L)
	static constexpr inline
	base_t normalize(Ints_type ... digits_pow_i)
	noexcept {
	///< CREA UN STD_ARRAY DEL TIPO INT PASADO POR UN PACK DE ARGUMENTOS
	///< EL TAMANO ES EL DEL PACK DE ARGUMENTOS PASADO (MENOR O IGUAL QUE L)
		using pack_type 	= typename utilities::pack2array<Ints_type...>;
	///< DEVUELVE EL TIPO INTERNO DE ELEMENTO DEL ARRAY ANTERIOR
	///< [UN TIPO ENTERO]
		using unique_type = typename pack_type::elem_type;

	///< DEVUELVE EL TAMANO DEL ARRAY ANTERIOR (TAMAÑO == L)

	///< ELIGE ENTRE CUATRO TIPOS DE ENTEROS SEGUN TENGAN SIGNO O NO
	///< Y SU TAMANO
	///< SEA MAYOR O MENOR QUE EL PROPIO DE LA BASE UINT_T
	///< 		TIPO PROPIO ES : 									UINT_T
	///< 		TIPO PASADO COMO ARGUMENTO ES :  	UNIQUE_TYPE
	///< 		LOS TIPOS PASADOS EN LOS ARGUMENTOS HAN DE SER IGUALES ENTRE SI
	///< PARA EL INTERROGANTE CONDICIONAL UTILIZAMOS
	///< 		UNSIGNED_INTEGRAL_C<S>		PRIMERA PREGUNTA O MAS EXTERIOR
	///< 		IS_UNISGNED_SZ_GT_V<T,S>	PREGUNTAS SEGUNDAS O MAS INTERIORES
	///< PARA ELEGIR EL TIPO APROPIADO EN CADA CASO USAMOS
	///<		SIG_UINT_FOR_UINT_T<UINT_T>
	///<		SIG_UINT_FOR_UINT_T<UNIQUE_TYPE>
	///<		SIG_UINT_FOR_UINT_T<UINT_T>
	///<		SIG_UINT_FOR_SINT_T<UNIQUE_TYPE>
		using namespace NumRepr::type_traits;
		using SUInt_type =
			typename std::conditional_t<
				is_unsigned_type_v<UINT_T>,
					typename std::conditional_t<
							is_unsigned_type_v<unique_type>,
							typename std::conditional_t<
								gt_sz_v<UINT_T,unique_type>,
									sig_UInt_for_UInt_t<UINT_T>,
									sig_UInt_for_UInt_t<unique_type>
							>,
							typename std::conditional_t<
								gt_sz_v<UINT_T,unique_type>,
									sig_UInt_for_UInt_t<UINT_T>,
									sig_UInt_for_SInt_t<unique_type>
							>
					>,
					typename std::conditional_t<
							is_unsigned_type_v<unique_type>,
							typename std::conditional_t<
								ge_sz_v<UINT_T,unique_type>,
									sig_UInt_for_SInt_t<sig_SInt_for_UInt_t<UINT_T>>,
									sig_UInt_for_SInt_t<sig_SInt_for_UInt_t<unique_type>>
							>,
							typename std::conditional_t<
								gt_sz_v<UINT_T,unique_type>,
									sig_UInt_for_SInt_t<sig_SInt_for_UInt_t<UINT_T>>,
									sig_UInt_for_SInt_t<sig_SInt_for_SInt_t<unique_type>>
							>
					>
			>;
		std::array<SUInt_type,L> ret_array{((dig_t(digits_pow_i))())...};
		base_t ret;

		for (size_t ix{ 0 }; ix < L; ++ix) {
			ret[ix] = dig_t(ret_array[ix]);
		}

		return ret;
	}

public:

	/// <summary="Constructor copia desde una sucesión de objetos enteros variádica, normalizándolos">
	/// </summary>

	template<type_traits::integral_c ... Ints_type>
		requires ((sizeof...(Ints_type))==L)
	constexpr inline reg_digs_t(Ints_type ... dig_pow_i) noexcept :
		base_t(normalize<Ints_type...>((dig_t(dig_pow_i))()...)) {
			this->reverse();
		}

	///	<summary>
	/// Sobrecarga del operador copia
	/// </summary>

	/// OPERACION ASIGNACION POR COPIA REFERENCIA
	/// CONST _NO_ COPIABLE DESDE REG_N_DIGS_T EN LA IZQUIERDA
	template<size_t N>
	constexpr inline
	const reg_digs_t & operator = (const reg_N_digs_t<N> & arg) noexcept
	{
		if (this!= &arg)
			copy_arg_N<N>(arg);
		return (*this);
	}

	/// OPERACION ASIGNACION POR COPIA REFERENCIA
	/// DESDE REG_N_DIGS_T EN LA IZQUIERDA
	template<size_t N>
	constexpr inline
	reg_digs_t & operator = (reg_N_digs_t<N> & arg) noexcept
	{
		if (this != &arg)
			copy_arg_N<N>(arg);
		return (*this);
	}

	/// OPERACION ASIGNACION POR MOVIMIENTO
	/// DESDE REGS_N_DIGS_T EN LA QUE NO SE PUEDE COPIAR
	template<size_t N>
	constexpr inline
	const base_t & operator = (reg_N_digs_t<N>&& arg) noexcept
	{
		if (this != &arg)
			move_arg_N<N>(std::move(arg));
		return (*this);
	}

	/// OPERACION COPIA DESDE UN DIGITO (CONVERSION)
	constexpr inline
	reg_digs_t & operator = (const dig_t & arg)
	noexcept {
		if ((&(r_cthis(0)))!=(&arg)) {
			r_cthis().set_0();
			r_cthis(0) = arg;
		}
		return (*this);
	}

	/// OPERACION COPIA DESDE UN ENTERO (CONVERSION A LA BASE B)
	/// A UN REG_DIGS_T
	template<type_traits::integral_c Int_Type>
	constexpr inline
	const reg_digs_t& operator = (Int_Type arg) noexcept {
		using type_traits::maxbase;
		constexpr sint128_t B_128t_v{static_cast<sint128_t>(B)};
		constexpr bool puede_multiplicarse{
				(maxbase<sint128_t>()/B_128t_v) > 0
		};
		if ((&(this->m_dc)) != (&arg)) {
			sint128_t creg_g{static_cast<sint128_t>(arg)};
			sint128_t BasePowIx{B_128t_v};
			for(size_t k{1u} ; k < L ; ++k) {
				if constexpr (puede_multiplicarse)
					BasePowIx *= B_128t_v;
				else
					break;
			}
			while (creg_g < 0) {
				creg_g += BasePowIx;
			}
			for(size_t k{0u} ; k < L ; ++k){
				r_cthis(k) = dig_t(creg_g%B_128t_v);
				creg_g /= B_128t_v;
			}
		}
		return (cr_cthis());
	}

	///
	///       Algunas Conversiones
	///

	template<type_traits::integral_c Int_Type>
	/// SE PODRÍA HACER PARA UINT128_T
	constexpr inline operator Int_Type() const noexcept {
		using type_traits::maxbase;
		uint64_t retInt{0};
		uint64_t BasePowIx{1};
		for(size_t k{0} ; k < L ; ++k) {
			retInt += cr_cthis_at(k)*BasePowIx;
			BasePowIx *= B;
			if(	(k+1 < L)
						&&
					(maxbase<Int_Type>() < (retInt+((cr_cthis_at(k+1)*BasePowIx)))
				))
			{	return retInt; }
		}
		return retInt;
	}

private :
	/// <summary=" sobrecarga de las funciones miembro : ">
	/// constexpr dig_t* data() noexcept;
	/// </summary>
	/// <returns name="dig_t*"></returns>
	constexpr dig_t* data() noexcept {
		return (this->base_t::data());
	}

public :
	/// <summary=" sobrecarga de las funciones miembro : ">
	/// constexpr const dig_t* data() const noexcept;
	/// </summary>
	/// <returns name="const dig_t*"></returns>
	constexpr const dig_t* const data() const noexcept {
		return (static_cast<const dig_t*>(this->base_t::data()));
	}

	inline constexpr
	decltype(auto) cpy_data() const {
		return (*(this->base_t::data()));
	}

	///	<summary="Sobrecarga del const dig_t & operator[](size_t) const"></summary>
	const dig_t& operator[](size_t ix) const {
		return (cr_cthis_at(ix));
	}

	/// <summary="Sobrecarga del dig_t & operator[](size_t)"></summary>
	dig_t& operator[](size_t ix) {
		return (r_cthis_at(ix));
	}


	/// <summary>
	/// Funciones que ponen a constantes (constexpr) los objetos base_t
	/// </summary>
	/// <typeparam name="size_t"></typeparam>
	/// <nontypeparam name="N"></nontypeparam>
	/// <param name="this"></param>
	/// <returns name="void"></returns>

	constexpr inline
	void set_0() noexcept
	{	r_cthis().fill(dig_0());	}

	constexpr inline
	void set_1() noexcept
	{	r_cthis().fill(dig_0());
		r_cthis()[0].set_1();	}

	constexpr inline
	void set_Bm1() noexcept
	{	r_cthis().fill(dig_0());
		r_cthis()[0].set_Bm1();	}

	constexpr inline
	void set_dig(dig_t d) noexcept
	{	r_cthis().fill(d);
		r_cthis()[0] = d;	}

	constexpr inline
	void set_fill_dig(dig_t d) noexcept
	{	r_cthis().fill(d);	}

	constexpr inline
	void set_fill_1() noexcept
	{	r_cthis().fill(dig_1());	}


	constexpr inline
	void set_fill_Bm1() noexcept
	{	r_cthis().fill(dig_Bm1());	}


/// <summary>
///	"Funciones que ponen a constantes(constexpr) los objetos un subintervalo
/// o subrango de base_t cualquiera"
/// </summary>
/// <typeparam name="size_t"></typeparam>
/// <nontypeparam name="N_i"></nontypeparam>
/// <nontypeparam name="N_pf"></nontypeparam>
/// <param name="this"></param>
/// <returns name="void"></returns>

/// OPERACION DE PONER A VALOR DIG_0 DEL ARRAY
///	DESDE [N_0 , N_1) EN BASE_N_T<N>
	template<size_t N_i,size_t N_pf> 	// i  es inicio
																		// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	constexpr inline
	void set_interval_0() noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			r_cthis(ix).set_0();
	}

	/// OPERACION DE PONER A VALOR DIG_Bm1 DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_N_T<N>
	template<size_t N,size_t N_i,size_t N_pf> // i  es inicio
																						// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	constexpr inline
	void set_interval_Bm1() noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			r_cthis(ix).set_Bm1();
	}

	/// OPERACION DE PONER A VALOR DIG DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_T
	template<size_t N_i,size_t N_pf>	// i  es inicio
																		// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	constexpr inline
	void set_interval_dig(dig_t dig) noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			r_cthis(ix) = dig;
	}

	///<summary="Funciones comparativas con constantes tipo constexpr"></summary>
	///<param name="this"></param>
	///<returns="bool"></returns>

	inline constexpr
	bool is_0() const noexcept
	{
		auto it{this->cbegin()};
		const auto itend{this->cend()};
		while(it != itend) {
			if(it->is_not_0())
				return false;
			++it;
		}
		return true;
	}

	inline constexpr
	bool is_1() const noexcept {
		if (cr_cthis(0).is_not_1())
			return false;
		for(size_t ix{1} ; ix<L ; ++ix) {
			if(cr_cthis(ix).is_not_0())
				return false;
		}
		return true;
	}

	inline constexpr
	bool is_Bm1() const noexcept {
		if (cr_cthis(0).is_not_Bm1())
			return false;
		for(size_t ix{1} ; ix<L ; ++ix) {
			if(cr_cthis(ix).is_not_0())
				return false;
		}
		return true;
	}

	inline constexpr
	bool is_B() const noexcept
	{
		if constexpr (L == 1) return false;
		else {
			if (cr_cthis(0).is_not_0())
				return false;
			if (cr_cthis(1).is_not_1())
				return false;
			for (size_t ix{ 2 }; ix < L; ++ix) {
				if (cr_cthis(ix).is_not_0())
					return false;
			}
			return true;
		}
	}

	inline constexpr
	bool is_Bp1() const noexcept {
		if constexpr (L == 1) return false;
		else {
			if (cr_cthis(0).is_not_1())
				return false;
			if (cr_cthis(1).is_not_1())
				return false;
			for (size_t ix{ 2 }; ix < L; ++ix) {
				if (cr_cthis(ix).is_not_0())
					return false;
			}
			return true;
		}
	}

	template<size_t n>
		requires (n<L)
	inline constexpr
	bool is_B_pow_m1() const noexcept
	{
		if constexpr (n == 0) {
			return cr_cthis().is_0();
		}
		else if constexpr (n == 1) {
			return cr_cthis().is_Bm1();
		}
		else if constexpr (n == 2) {
			if (cr_cthis(1).is_not_Bm1() || cr_cthis(0).is_not_Bm1())
				return false;
			for(size_t ix{2} ; ix < L ; ++ix)
				if (cr_cthis(ix).is_not_0())
					return false;
			return true;
		}
		else {
			for(size_t ix{0} ; ix < n ; ++ix)
				if (cr_cthis(ix).is_not_Bm1())
					return false;
			for(size_t ix{n} ; ix < L ; ++ix)
				if (cr_cthis(ix).is_not_0())
					return false;
			return true;
		}
	}

	template<size_t n>
		requires (n<L-1)
	inline constexpr
	bool is_B_pow() const noexcept
	{
		if constexpr (n == 0) {
			if (cr_cthis(0).is_not_1())
				return false;
			for (size_t ix{1} ; ix < L ; ++ix)
				if (cr_cthis(ix).is_not_0())
					return false;
			return true;
		}
		else if constexpr (n == 1) {
			if (cr_cthis(0).is_not_0())
				return false;
			if (cr_cthis(1).is_not_1())
				return false;
			for (size_t ix{2} ; ix < L ; ++ix)
				if (cr_cthis(ix).is_not_0())
					return false;
			return true;
		}
		else if constexpr (n == 2) {
			if (cr_cthis(0).is_not_0() || cr_cthis(1).is_not_0())
				return false;
			if (cr_cthis(2).is_not_1())
				return false;
			for (size_t ix{3} ; ix < L ; ++ix)
				if (cr_cthis(ix).is_not_0())
					return false;
			return true;
		}
		else {
			for (size_t ix{0} ; ix < n ; ++ix)
				if (cr_cthis(ix).is_not_0())
					return false;
			if (cr_cthis(n).is_not_1())
				return false;
			for (size_t ix{n+1} ; ix < L ; ++ix)
				if (cr_cthis(ix).is_not_0())
					return false;
			return true;
		}
	}

	inline constexpr
	bool is_any_B_pow() const noexcept
	{
		const auto pred_not_0 = [](dig_t d){return (d.is_not_0());};
		const auto it{std::find_if(cr_cthis().cbegin(),cr_cthis().cend(),pred_not_0)};
		if (it != cr_cthis().cend()) {
			const int64_t card{std::count_if(cr_cthis().cbegin(),cr_cthis().cend(),pred_not_0)};
			if (card != 1)
				return false;
			else
				return (it->is_0());
		}
		return false;
	}

	inline constexpr
	bool is_filled_of_1() const noexcept {
		for (size_t ix{0} ; ix < L ; ++ix)
			if (cr_cthis(ix).is_not_1())
				return false;
		return true;
	}

	inline constexpr
	bool is_filled_of_Bm1() const noexcept {
		for (size_t ix{0} ; ix < L ; ++ix)
			if (cr_cthis_at(ix).is_not_Bm1())
				return false;
		return true;
	}

	inline constexpr
	bool is_filled_of(dig_t d) const {
		for (size_t ix{0} ; ix < L ; ++ix)
			if (cr_cthis(ix) != d)
				return false;
		return true;
	}

	///			STATIC FUNCTIONS : CONCATENATE REGISTERS AND DIGITS
	/// 		reg_digs_t<1>			cat(dig_t)
	/// 		reg_digs_t<1+1>		cat(dig_t,dig_t)
	/// 		reg_digs_t				cat(reg_digs_t)
	/// <M> reg_N_digs_t<L+M>	cat(reg_digs_t,reg_N_digs_t<M>)
	/// 		reg_N_digs_t<L+1>	cat(reg_digs_t,dig_t)
	/// 		reg_N_digs_t<1+L>	cat(dig_t,reg_digs_t)
	/// 		reg_N_digs_t<sizeof...(dig_pack)>
	///												cat(dig_t ... dig_pack) VARIADIC PACK

	/// STATIC REG_DIGS_T CAT(REG_DIGS_T)
	static constexpr inline
	reg_digs_t cat(const reg_digs_t & arg) noexcept
	{	return std::move(reg_digs_t{arg});	}

	/// STATIC <M> REG_N_DIGS_T<L+M> CAT(REG_DIGS_T,REG_N_DIGS_T<M>)
	template<size_t M>
	static constexpr inline
		reg_N_digs_t<L+M>
		cat(const reg_digs_t& larg,const reg_N_digs_t<M>& rarg)
	noexcept {
		base_N_t<L+M> ret;
		for(size_t ix{0} ; ix < L ; ++ix)
			ret[ix] = larg[ix];
		for(size_t ix{L} ; ix < M ; ++ix)
			ret[ix] = rarg[ix];
		return std::move(ret);
	}

	/// STATIC REG_DIGS_T<L+1> CAT(REG_DIGS_T,DIG_T)
	static constexpr inline
	reg_N_digs_t<L+1> cat(const reg_digs_t & larg,dig_t rarg)
	noexcept {
		reg_N_digs_t<L+1> ret;
		for(size_t ix{0} ; ix < L ; ++ix)
			ret[ix] = larg[ix];
		ret[L] = rarg;
		return std::move(ret);
	}

	/// REG_N_DIGS_T<1+L> CAT(DIG_T,REG_DIGS_T)
	static constexpr inline
	reg_N_digs_t<1+L> cat(dig_t larg,const reg_digs_t & rarg)
	noexcept {
		reg_N_digs_t<1+L> ret;
		ret[0] = larg;
		for(size_t ix{1} ; ix < L+1 ; ++ix)
			ret[ix] = rarg[ix-1];
		return std::move(ret);
	}

	/// STATIC REG_N_DIGS_T<1> CAT(DIG_T)
	static constexpr inline
	reg_N_digs_t<1> cat(dig_t larg) noexcept
	{	return std::move(reg_N_digs_t<1>{larg});	}

	/// STATIC REG_N_DIGS_T<1+1> CAT(DIG_T,DIG_T)
	static constexpr inline
	reg_N_digs_t<2> cat(dig_t larg,dig_t rarg) noexcept {
		reg_N_digs_t<2> ret;
		ret[0] = larg;
		ret[1] = rarg;
		return std::move(ret);
	}

	/// STATIC REG_N_DIGS_T<SIZEOF...(DIG_PACK)>
	/// CAT(DIG_T,DIG_T ... DIG_PACK) VARIADIC
	template<typename T0,typename ... Ts>
		requires (
			((std::is_same_v<Ts,dig_t>)&&...)&&
			(std::is_same_v<T0,dig_t>)
		)
	static constexpr inline
	reg_N_digs_t<1+(sizeof ... (Ts))>
				cat(T0 dig0,Ts ... dig_pack) noexcept {
		return cat(dig_0,dig_pack...);
	}

	/// STATIC REG_N_DIGS_T<L+1+(SIZEOF...(DIG_PACK))>
	/// CAT(REG_DIGS_T,DIG_T,DIG_T ... DIG_PACK) VARIADIC
	template<typename T,typename ... Ts>
		requires (
			((std::is_same_v<Ts,dig_t>)&&...)	&&
			(std::is_same_v<T,dig_t>)
		)
	static constexpr inline
	reg_N_digs_t<L+1+(sizeof ... (Ts))>
		cat(reg_digs_t larg,T dig,Ts ... dig_pack) noexcept {
		return cat(larg,cat(dig,dig_pack...));
	}

	/// STATIC REG_N_DIGS_T<L+1+(SIZEOF...(DIG_PACK))>
	/// CAT(DIG_T,DIG_T ... DIG_PACK,REG_DIGS_T) VARIADIC
	template<typename T,typename ... Ts>
		requires (
			((std::is_same_v<Ts,dig_t>)&&...)	&&
			(std::is_same_v<T,dig_t>)
		)
	static constexpr inline
		reg_N_digs_t<L+1+(sizeof ... (Ts))>
		cat(T dig,Ts ... dig_pack,reg_digs_t rarg)
	noexcept {
		return cat(cat(dig,dig_pack...),rarg);
	}

	/// STATIC REG_N_DIGS_T<SIZE_T N,SIZE_T ... N_PACK>
	/// CAT(REG_N_DIGS_T<N> LARG,
	///			REG_N_DIGS_T<N_PACK> ... RARG_PACK
	///		) VARIADIC PACK
	template<size_t N,size_t ... N_pack>
		requires ((N>0)&&((N_pack>0)&&...))
	static constexpr inline
		reg_N_digs_t<N+(...+(N_pack))>
		cat(reg_N_digs_t<N> larg,reg_N_digs_t<N_pack> ... rarg_pack)
		noexcept	{
		return cat(larg,rarg_pack...);
	}

		/// TAKE A SUBREGISTER OF A REGISTER OF DIGITS
	template<size_t ibegin,size_t iend>
		requires ((iend <= L)&&(ibegin < L)&&(ibegin != iend))
	constexpr inline
	reg_N_digs_t<(ibegin < iend)?(iend-ibegin):(ibegin-iend)>
	subregister() const noexcept {
		const reg_digs_t & cthis{*this};
		if constexpr (ibegin < iend) {
			reg_N_digs_t<iend-ibegin> ret;
			for(size_t ix{ibegin} ; ix < iend ; ++ix) {
				ret[ix-ibegin] = cthis[ix];
			}
			return ret;
		}
		else {
			reg_N_digs_t<iend-ibegin> ret;
			for(int64_t ix{iend} ; ix > ibegin-1 ; --ix) {
				ret[ix-ibegin] = cthis[L-1-ix];
			}
			return ret;
		}
	}

	/// OPERADORES ARITMETICOS
	///	C_B()  C_Bm1()
	///	mC_B() mC_Bm1()
	///	operator!() operator-()

	constexpr inline
	const reg_digs_t & mC_Bm1() noexcept {
		for(size_t ix{0} ; ix < L ; ++ix) {
				r_cthis(ix).mC_Bm1();
		}
		return (cr_cthis());
	}

	constexpr inline
	const reg_digs_t & mC_B() noexcept {
		r_cthis().mC_Bm1();
		for(size_t ix{0} ; ix < L ; ++ix) {
			if (r_cthis(ix).is_not_Bm1()) {
				++r_cthis(ix);
				return (cr_cthis());
			}
			else {
				r_cthis(ix).set_0();
			}
		}
		return (cr_cthis());
	}

	constexpr inline
	reg_digs_t C_Bm1() const noexcept
	{	return std::move(cp_cthis().mC_Bm1()); }

	constexpr inline
	reg_digs_t C_B() const noexcept
	{ return std::move(cp_cthis().mC_B());	}

	///	A partir de aquí no he hecho las sustituciones de
	/// const reg_digs_t & cthis{*this}; / reg_digs_t & cthis{*this}; / reg_digs_t cthis{*this};
	/// Por las correspondientes funciones cr_cthis() / r_cthis() / cp_cthis()

	constexpr inline
	reg_digs_t operator !() const noexcept
	{ return C_Bm1(); }

	constexpr inline
	reg_digs_t operator -() const noexcept
	{ return C_B();	}

public :
	/// OPERATORS >> >>= << <<= REM_B^n M_REM_B^n MER_B_N M_MER_B_N

	/// MULTIPLY BY THE BASE B (10) << <<=
	/// DIVIDE BY THE BASE B (10)	  >> >>=
	/// REMAINDER BY THE BASE B (10) REM_B_N M_REM_B_N
	/// MULTIPLICATIVE CARRY BY THE BASE B (10) MER_B_N M_MER_B_N
	constexpr inline
	reg_digs_t operator << (size_t n) const noexcept {
		for(int32_t ix{L-1-n} ; ix > -1 ; --ix) {
			cp_cthis(ix+n)	= cr_cthis(ix);
		}
		for(int32_t ix{0} ; ix < n ; ++ix) {
			cp_cthis(ix+n)	=	dig_0();
		}
		return std::move(cp_cthis());
	}

	/// TODO TO DO VOY POR AQUI CON EL TEMA DE LOS CTHIS

	constexpr inline
	const reg_digs_t & operator <<= (size_t n) noexcept {
		reg_digs_t & cthis{*this};
		for(int32_t ix{L-1-n} ; ix > -1 ; --ix) {
			cthis[ix+n]	= cthis[ix];
		}
		for(int32_t ix{0} ; ix < n ; ++ix) {
			cthis[ix]	= dig_0();
		}
		return (*this);
	}

	constexpr inline
	const reg_digs_t & operator >>= (size_t n) noexcept {
		reg_digs_t & cthis{*this};
		constexpr int64_t Ls = static_cast<int64_t>(L);
		const 		int64_t ns = static_cast<int64_t>(n);
		for(int64_t ix{0} ; ix < Ls-ns ; ++ix) {
			cthis[ix] 		= cthis[ix+n];
		}
		for(int64_t ix{Ls-ns} ; ix < Ls ; ++ix) {
			cthis[ix]		=	dig_0();
		}
		return (*this);
	}

	constexpr inline
	reg_digs_t operator >> (size_t n) const noexcept {
		reg_digs_t ret{*this};
		ret >>= n;
		return ret;
	}

	constexpr inline
	reg_digs_t rem_B(size_t n) const noexcept {
		reg_digs_t ret{*this};
		ret <<= L-n;
		return ret;
	}

	constexpr inline
	const reg_digs_t & m_rem_B(size_t n) noexcept {
		reg_digs_t & cthis{*this};
		cthis <<= L-n;
		return (*this);
	}


	constexpr inline
	reg_digs_t mer_B(size_t n) const noexcept {
		reg_digs_t ret{*this};
		ret >>= L-n;
		return std::move(ret);
	}

	constexpr inline
	const reg_digs_t & m_mer_B(size_t n) noexcept {
		reg_digs_t& cthis{*this};
		cthis >>= L-n;
		return (cthis);
	}

	constexpr inline
	const reg_digs_t & operator |= (const base_t & rarg) const noexcept {
		reg_digs_t& cthis{*this};
		for(size_t ix{0} ; ix < L ; ++ix) {
			cthis[ix] |= rarg[ix];
		}
		return (cthis);
	}

	constexpr inline
	reg_digs_t operator | (const reg_digs_t & rarg) const noexcept {
		reg_digs_t ret{*this};
		ret |= rarg;
		return std::move(ret);
	}

	constexpr inline
	const reg_digs_t& operator &= (const reg_digs_t & rarg) noexcept {
		reg_digs_t& cthis{*this};
		for(size_t ix{0} ; ix < L ; ++ix) {
			cthis[ix] &= rarg[ix];
		}
		return (cthis);
	}

	constexpr inline
	reg_digs_t operator & (const reg_digs_t & rarg) noexcept {
		reg_digs_t ret{*this};
		ret &= rarg;
		return std::move(ret);
	}

	/// NOS DEVUELVE EL ÍNDICE DEL DÍGITO NO 0 DE POTENCIA DE B MAS GRANDE
	/// NOS DEVUELVE 0 SI ES UN DÍGITO NO 0
	/// NOS DEVUELVE -1 SI ES EL DÍGITO 0
	/// CUALQUIER OTRO CASO NOS DARÁ MAYOR QUE 0
	inline constexpr
	int64_t index_of_MSDig() const noexcept {
		for(int64_t ix{L-1} ; ix > -1 ; --ix) {
			if (cr_cthis_at(ix).is_not_0())
				return ix;
		}
		return (-1);
	}

	///
	///
	/// SOBRECARGA DE LOS OPERADORES DE COMPARACION Y ORDEN
	///
	///

	/// COMPARACIONES ENTRE BASE_T Y DIG_T EN FORMA BASE_T @ DIG_T
	constexpr inline
	bool operator == (const dig_t& rarg) const noexcept {
		const reg_digs_t & cthis{*this};
		if (cthis[0] != rarg)
			return false;
		for(size_t ix{1} ; ix < L ; ++ix)
			if (cthis[ix].is_not_0())
				return false;
		return true;
	}

	constexpr inline
	bool operator != (const dig_t& rarg) const noexcept {
		const reg_digs_t & cthis{*this};
		for(size_t ix{1} ; ix < L ; ++ix)
			if (cthis[ix].is_not_0())
				return true;
		if (cthis[0] != rarg)
			return true;
		return false;

	}

	constexpr inline
	bool operator > (const dig_t& rarg) const noexcept {
		const reg_digs_t & cthis{*this};
		for(size_t ix{1} ; ix < L ; ++ix)
			if (cthis[ix].is_not_0())
				return true;
		if (cthis[0] > rarg)
			return true;
		return false;
	}

	constexpr inline
	bool operator < (const dig_t& rarg) const noexcept {
		const reg_digs_t & cthis{*this};
		for(size_t ix{1} ; ix < L ; ++ix)
			if (cthis[ix].is_not_0())
				return false;
		if (cthis[0] >= rarg)
			return false;
		return true;
	}

	constexpr inline
	bool operator >= (const dig_t& rarg) const noexcept {
		const reg_digs_t & cthis{*this};
		for(size_t ix{1} ; ix < L ; ++ix)
			if (cthis[ix].is_not_0())
				return true;
		if (cthis[0] >= rarg)
			return true;
		return false;
	}

	constexpr inline
	bool operator <= (const dig_t& rarg) const noexcept {
		const reg_digs_t & cthis{*this};
		for(size_t ix{1} ; ix < L ; ++ix)
			if (cthis[ix].is_not_0())
				return false;
		if (cthis[0] > rarg)
			return false;
		else
			return true;
	}

	/// COMPARACIONES ENTRE REG_DIGS_T Y REG_N_DIGS_T
	///	HETEROGENEOS EN GENERAL
	///	EN FORMA REG_DIGS_T @ REG_N_DIGS_T<M>
	template<size_t M>
	constexpr inline
	bool operator == (const reg_N_digs_t<M>& rarg) const noexcept {
		const reg_digs_t & cthis{*this};

		constexpr size_t P{std::min(L,M)};
		constexpr size_t Q{std::max(L,M)};
		constexpr bool L_gt_M{L>M};

		if constexpr (L!=M) {
			for (size_t ix{P} ; ix < Q ; ++ix) {
				if constexpr (L_gt_M) {
					if (cthis[ix].is_not_0())
						return false;
				}
				else {
					if (rarg[ix].is_not_0())
						return false;
				}
			}
		}
		for(size_t ix{0} ; ix < P ; ++ix)
			if (cthis[ix] != rarg[ix])
				return false;
		return true;
	}

	template<size_t M>
	constexpr inline
	bool operator != (const reg_N_digs_t<M>& rarg) const noexcept  {
		const reg_digs_t & cthis{*this};

		constexpr size_t P{std::min(L,M)};
		constexpr size_t Q{std::max(L,M)};
		constexpr bool L_gt_M{L>M};

		if constexpr (L!=M) {
			for (size_t ix{P} ; ix < Q ; ++ix) {
				if constexpr (L_gt_M) {
					if (cthis[ix].is_not_0())
						return true;
				}
				else {
					if (rarg[ix].is_not_0())
						return true;
				}
			}
		}
		for(size_t ix{0} ; ix < P ; ++ix)
			if (cthis[ix] != rarg[ix])
				return true;
		return false;
	}

	template<size_t M>
	constexpr inline
	bool operator > (const reg_N_digs_t<M>& rarg) const noexcept {
		const reg_digs_t & cthis{*this};
		constexpr size_t P{std::min(L,M)};
		constexpr size_t Q{std::max(L,M)};
		constexpr bool L_gt_M{L>M};

		if constexpr (L != M) {
			for(size_t ix{P} ; ix < Q ; ++ix) {
				if constexpr (L>M) {
					if (cthis[ix].is_not_0())
						return true;
				}
				else {
					if (rarg[ix].is_not_0())
						return false;
				}
			}
		}

		for(int32_t ix{L} ; ix > -1 ; --ix)
			if (cthis[ix] > rarg[ix])
				return true;
		return false;
	}

	template<size_t M>
	constexpr inline
	bool operator < (const reg_N_digs_t<M>& rarg) const noexcept {
		const reg_digs_t & cthis{*this};
		constexpr size_t P{std::min(L,M)};
		constexpr size_t Q{std::max(L,M)};
		constexpr bool L_gt_M{L>M};

		if constexpr (L != M) {
			for(size_t ix{P} ; ix < Q ; ++ix) {
				if constexpr (L_gt_M) {
					if (cthis[ix].is_not_0())
						return false;
				}
				else {
					if (rarg[ix].is_not_0())
						return true;
				}
			}
		}

		for(int32_t ix{L} ; ix > -1 ; --ix)
			if (cthis[ix] < rarg[ix])
				return true;
		return false;
	}

	template<size_t M>
	constexpr inline
	bool operator >= (const reg_N_digs_t<M>& rarg) const noexcept {
		const reg_digs_t & cthis{*this};
		return (!(cthis < rarg));	}

	template<size_t M>
	constexpr inline
	bool operator <= (const reg_N_digs_t<M>& rarg) const noexcept {
		const reg_digs_t & cthis{*this};
		return (!(cthis > rarg));	}

	/// OPERADOR COMPARACION SPACESHIP C++20

	template<size_t M>
	constexpr inline
	std::strong_ordering operator <=> (const reg_N_digs_t<M>& arg) const
	noexcept {
		const reg_digs_t& cthis{*this};
		if (cthis == arg)
			return std::strong_ordering::equal;
		else if (cthis < arg)
			return std::strong_ordering::less;
		else
			return std::strong_ordering::greater;
	}

	/// OPERADOR COMPARACION SPACESHIP C++20
	constexpr inline
	std::weak_ordering operator <=> (const dig_t & arg) const noexcept
	{
		const reg_digs_t& cthis{*this};
		if (cthis > arg)
			return std::weak_ordering::greater;
		else if (cthis < arg)
			return std::weak_ordering::less;
		else
			return std::weak_ordering::equivalent;
	}
	/// Funciones de ayuda para
  /// el parser/lexer del reg_digs_t

  static
  bool is_type_template_string_id(std::string in) noexcept {
    return	(
      (in == "reg_digs_t")||
			(in == "reg_digs_")||
			(in == "reg_digs")||
      (in == "reg_dig")||
      (in == "reg_di")||
      (in == "reg_d")||
      (in == "reg_")||
      (in == "reg")||
      (in == "re")||
      (in == "r")
    );
  }

  static
  std::string to_type_template_string_id() noexcept
  {	return std::string{"reg_digs"};	}

  static
  size_t size_of_type_template_string_id() noexcept
  {	return (to_type_template_string_id()).size();	}


  /// FUNCION GENERICA QUE CONSIGUE EL TOKEN TYPE PARA LA
  /// OBTENCION DEL OBJETO CORRESPONDIENTE POR TECLADO
  static
  bool get_type_template_string_id_token(std::istream& is)
  {
  	char input_char = type_traits::nullchar<char>;
    std::string old_input_string{""};
    std::string new_input_string{""};
    while(true) {
      is >> input_char;
      new_input_string += input_char;
      if (is_type_template_string_id(new_input_string)) {
        old_input_string = new_input_string;
      }
      else {
        std::cerr << "Has cometido un error, tenias que escribir "
        << "\" " << to_type_template_string_id()
        << " \"  y has escrito "
        << new_input_string << std::endl;
        std::cerr << "Considera que has escrito "
        << old_input_string
        << " y continua escribiendo a partir de ahi";
        new_input_string = old_input_string;
      }

      if (new_input_string==to_type_template_string_id())
        return true;
      else
        return false;
    }
  }
};

///< DEFINCION DE template<uint128_t Radix> digito_t{};
template<uint128_t B,size_t L>
using register_of_digits_t =
	reg_digs_t<
		type_traits::TypeFromIntNumber_t<B>,
		static_cast<type_traits::TypeFromIntNumber_t<B>>(B),
		L
	>;

/// STATIC BASE_N_T<N> 		CONCAT(BASE_N_T<N>)
/// STATIC BASE_N_T<N+M> 	CONCAT(BASE_N_T<N>,BASE_N_T<M>)
/// STATIC BASE_N_T<N+1> 	CONCAT(BASE_N_T<N>,DIG_T)
/// STATIC BASE_N_T<1+M> 	CONCAT(DIG_T,BASE_N_T<M>)
/// STATIC BASE_N_T<1> 		CONCAT(DIG_T)
/// STATIC BASE_N_T<1+1> 	CONCAT(DIG_T,DIG_T)
/// STATIC BASE_N_T<SIZEOF...(DIG_PACK)> CONCAT(DIG_T ... DIG_PACK) VARIADIC PACK

/// STATIC BASE_N_T<N> CONCAT(BASE_N_T<N>)
template<typename UInt_t, UInt_t B, size_t N>
	requires (N>0)
constexpr inline
reg_digs_t<UInt_t,B,N> concat(const reg_digs_t<UInt_t,B,N>& larg) noexcept
{
	return reg_digs_t<UInt_t,B,N>{larg};
}

/// STATIC BASE_N_T<N+M> CONCAT(BASE_N_T<N>,BASE_N_T<M>)
template<typename UInt_t, UInt_t B, size_t N,size_t M>
	requires (N>0)&&(M>0)
constexpr inline
reg_digs_t<UInt_t,B,N+M> concat(const reg_digs_t<UInt_t,B,N>& larg,const reg_digs_t<UInt_t,B,M>& rarg) noexcept
{
	reg_digs_t<UInt_t,B,N+M> ret;
	for(size_t ix{0} ; ix < N ; ++ix)
		ret[ix] = larg[ix];
	for(size_t ix{N} ; ix < M ; ++ix)
		ret[ix] = rarg[ix];
	return ret;
}

/// STATIC BASE_N_T<N+1> CONCAT(BASE_N_T<N>,DIG_T)
template<typename UInt_t, UInt_t B, size_t N>
	requires (N > 0)
constexpr inline
reg_digs_t<UInt_t,B,N+1> concat(const reg_digs_t<UInt_t,B,N>& larg,dig_t<UInt_t,B> rarg) noexcept
{
	reg_digs_t<UInt_t,B,N+1> ret;
	for(size_t ix{0} ; ix < N ; ++ix)
		ret[ix] = larg[ix];
	ret[N] = rarg;
	return ret;
}

/// STATIC BASE_N_T<1+M> CONCAT(DIG_T,BASE_N_T<M>)
template<typename UInt_t, UInt_t B, size_t M>
	requires (M > 0)
constexpr inline
reg_digs_t<UInt_t,B,1+M> concat(dig_t<UInt_t,B> larg, const reg_digs_t<UInt_t,B,M>& rarg) noexcept
{
	reg_digs_t<UInt_t,B,1+M> ret;
	ret[0] = larg;
	for(size_t ix{1} ; ix < M+1 ; ++ix)
		ret[ix] = rarg[ix-1];
	return ret;
}

/// STATIC BASE_N_T<1> CONCAT(DIG_T)
template<typename UInt_t, UInt_t B>
constexpr inline
reg_digs_t<UInt_t,B,1> concat(dig_t<UInt_t,B> larg) noexcept
{	return reg_digs_t<UInt_t,B,1>{larg};	}

/// STATIC BASE_N_T<1+1> CONCAT(DIG_T,DIG_T)
template<typename UInt_t, UInt_t B>
constexpr inline
reg_digs_t<UInt_t,B,2> concat(dig_t<UInt_t,B> larg,dig_t<UInt_t,B> rarg) noexcept
{
	reg_digs_t<UInt_t,B,2> ret;
	ret[0] = larg;
	ret[1] = rarg;
	return ret;
}

/// STATIC BASE_N_T<SIZEOF...(DIG_PACK)>
///		CONCAT(DIG_T,DIG_T ... DIG_PACK)
///	VARIADIC
template<typename UInt_t,UInt_t B,typename T0,typename ... Ts>
	requires (((std::is_same_v<Ts,dig_t<UInt_t,B>>)&&...)&&(std::is_same_v<T0,dig_t<UInt_t,B>>))
constexpr inline
reg_digs_t<UInt_t,B,1+(sizeof ... (Ts))> concat(T0 dig0,Ts ... dig_pack) noexcept {
	return concat(dig0,dig_pack...);
}

/// STATIC BASE_N_T<N+1+(SIZEOF...(DIG_PACK))>
///		CONCAT(BASE_N_T<N>,DIG_T,DIG_T ... DIG_PACK)
///	VARIADIC
template<typename UInt_t,UInt_t B,size_t N,typename T,typename ... Ts>
	requires (((std::is_same_v<Ts,dig_t<UInt_t,B>>)&&...)&&(std::is_same_v<T,dig_t<UInt_t,B>>)&&(N>0))
constexpr inline
reg_digs_t<UInt_t,B,N+1+(sizeof ... (Ts))> concat(reg_digs_t<UInt_t,B,N> larg,T dig,Ts ... dig_pack)
noexcept { return concat(larg,concat(dig,dig_pack...));	}

/// STATIC BASE_N_T<M+1+(SIZEOF...(DIG_PACK))>
///			CONCAT(DIG_T,DIG_T ... DIG_PACK,BASE_N_T<M>)
///	VARIADIC
template<typename UInt_t,UInt_t B,size_t M,typename T,typename ... Ts>
	requires ((std::is_same_v<Ts,dig_t<UInt_t,B>>)&&...)&&(std::is_same_v<T,dig_t<UInt_t,B>>)&&(M>0)
constexpr inline
reg_digs_t<UInt_t,B,M+1+(sizeof ... (Ts))> concat(T dig,Ts ... dig_pack,reg_digs_t<UInt_t,B,M> rarg)
noexcept { return concat(concat(dig,dig_pack...),rarg);	}

/// STATIC BASE_N_T<SIZE_T N,SIZE_T ... N_PACK>
///	CONCAT(BASE_N_T<N> LARG,BASE_N_T<N_PACK> ... RARG_PACK)
///	VARIADIC
template<typename UInt_t,UInt_t B,size_t N,size_t ... N_pack>
	requires ((N>0)&&((N_pack>0)&&...))
constexpr inline
reg_digs_t<UInt_t,B,N+(...+(N_pack))>
		concat(reg_digs_t<UInt_t,B,N> larg,reg_digs_t<UInt_t,B,N_pack> ... rarg_pack) noexcept
{	return concat(larg,rarg_pack...); }

template<uint_type_for_radix_c UINT_T,UINT_T B,size_t N>
  requires ((suitable_base<UINT_T,B>())&&(N > 0))
constexpr inline
reg_digs_t<UINT_T,B,N> operator << (
	const reg_digs_t<UINT_T,B,N>& larg,
	size_t n
	) noexcept {
	reg_digs_t<UINT_T,B,N> cparg{larg};
	for(std::int32_t ix{N-1-n} ; ix > -1 ; --ix) {
		cparg[ix+n]	= larg[ix];
	}
	for(std::int32_t ix{0} ; ix < n ; ++ix) {
		cparg[ix]		= dig_t<UINT_T,B>::dig_0();
	}
	return cparg;
}

template<uint_type_for_radix_c UINT_T,UINT_T B,size_t N>
  requires ((suitable_base<UINT_T,B>())&&(N > 0))
constexpr inline
const reg_digs_t<UINT_T,B,N> & operator <<= (
	reg_digs_t<UINT_T,B,N>& larg,
	size_t n
	) noexcept {
	for(std::int32_t ix{N-1-n} ; ix > -1 ; --ix) {
		larg[ix+n]	= larg[ix];
	}
	for(std::int32_t ix{0} ; ix < n ; ++ix) {
		larg[ix]	= dig_t<UINT_T,B>::dig_0();
	}
	return (larg);
}

template<uint_type_for_radix_c UINT_T,UINT_T B,size_t N>
  requires ((suitable_base<UINT_T,B>())&&(N > 0))
constexpr inline
const reg_digs_t<UINT_T,B,N> & operator >>= (
	reg_digs_t<UINT_T,B,N>& larg,
	size_t n
	) noexcept {
	for(std::int32_t ix{0} ; ix < N-n ; ++ix) {
		larg[ix] 		= larg[ix+n];
	}
	for(std::int32_t ix{N-n} ; ix < N ; ++ix) {
		larg[ix]		=	dig_t<UINT_T,B>::dig_0();
	}
	return (larg);
}

template<uint_type_for_radix_c UINT_T,UINT_T B,size_t N>
  requires ((suitable_base<UINT_T,B>())&&(N > 0))
constexpr inline
reg_digs_t<UINT_T,B,N> operator >> (
	const reg_digs_t<UINT_T,B,N> & larg,
	size_t n
	) noexcept {
	return (reg_digs_t<UINT_T,B,N>{larg}.ref_data() >>= n);
}

template<uint_type_for_radix_c UINT_T,UINT_T B,size_t N>
requires ((suitable_base<UINT_T,B>())&&(N > 0))
constexpr inline
reg_digs_t<UINT_T,B,N> rem_B(const reg_digs_t<UINT_T,B,N> & larg,size_t n) noexcept
{
	reg_digs_t<UINT_T,B,N> ret{larg};
	ret <<= N-n;
	return ret;
}

template<uint_type_for_radix_c UINT_T,UINT_T B,size_t N>
requires ((suitable_base<UINT_T,B>())&&(N > 0))
constexpr inline
const reg_digs_t<UINT_T,B,N> & m_rem_B(reg_digs_t<UINT_T,B,N>& larg,size_t n) noexcept
{
	larg <<= N-n;
	return (larg);
}

template<uint_type_for_radix_c UINT_T,UINT_T B,size_t N>
requires ((suitable_base<UINT_T,B>())&&(N > 0))
constexpr inline
reg_digs_t<UINT_T,B,N> mer_B(const reg_digs_t<UINT_T,B,N> & larg,size_t n) noexcept
{
	reg_digs_t<UINT_T,B,N> ret{larg};
	ret >>= N-n;
	return ret;
}

template<uint_type_for_radix_c UINT_T,UINT_T B,size_t N>
requires ((suitable_base<UINT_T,B>())&&(N > 0))
constexpr inline
const reg_digs_t<UINT_T,B,N> & m_mer_B(reg_digs_t<UINT_T,B,N>& larg,size_t n) noexcept
{
	larg >>= N-n;
	return (larg);
}

template<uint_type_for_radix_c UINT_T,UINT_T B,size_t N>
  requires ((suitable_base<UINT_T,B>())&&(N > 0))
constexpr inline
const reg_digs_t<UINT_T,B,N> & operator |= (
						reg_digs_t<UINT_T,B,N> & larg,
						const reg_digs_t<UINT_T,B,N> & rarg
) noexcept {
	for(size_t ix{0} ; ix < N ; ++ix) {
		larg[ix] |= rarg[ix];
	}
	return (larg);
}

template<uint_type_for_radix_c UINT_T,UINT_T B,size_t N>
  requires ((suitable_base<UINT_T,B>())&&(N > 0))
constexpr inline
reg_digs_t<UINT_T,B,N> operator | (
			const reg_digs_t<UINT_T,B,N> & larg,
			const reg_digs_t<UINT_T,B,N> & rarg
) noexcept {
	reg_digs_t ret{larg};
	ret |= rarg;
	return (ret);
}

template<uint_type_for_radix_c UINT_T,UINT_T B,size_t N>
  requires ((suitable_base<UINT_T,B>())&&(N > 0))
constexpr inline
const reg_digs_t<UINT_T,B,N> & operator &= (
	reg_digs_t<UINT_T,B,N> & larg,
	const reg_digs_t<UINT_T,B,N> & rarg
) noexcept {
	for(size_t ix{0} ; ix < N ; ++ix) {
		larg[ix] &= rarg[ix];
	}
	return (larg);
}

template<uint_type_for_radix_c UINT_T,UINT_T B,size_t N>
  requires ((suitable_base<UINT_T,B>())&&(N > 0))
constexpr inline
reg_digs_t<UINT_T,B,N> operator & (
		reg_digs_t<UINT_T,B,N> & larg,
		const reg_digs_t<UINT_T,B,N> & rarg
) noexcept {
	reg_digs_t<UINT_T,B,N> ret{larg};
	ret &= rarg;
	return (ret);
}

template<typename UINT_T,UINT_T B,size_t N>
constexpr inline
reg_digs_t<UINT_T,B,N> m_incr(reg_digs_t<UINT_T,B,N>& rarg) noexcept {
	//using SIG_UINT_T = typename type_traits::sig_UInt_for_UInt_t<UINT_T>;
	using dig_t			 = dig_t<UINT_T,B>;

	dig_t carry{dig_t::dig_0()};
	for(size_t i=0 ; i < N ; ++i) {
		if (i==0) {
			if (rarg[0].is_Bm1()) {
				rarg[0].set_0();
				carry.set_1();
			}
			else {
				++rarg[0];
				carry.set_0();
				break;
			}
		}
		else {
			if (carry.is_not_0()) {
				if (rarg[i].is_Bm1()) {
					rarg[i].set_0();
					carry.set_1();
				}
				else {
					++rarg[i];
					carry.set_0();
					break;
				}
			}
			else {
				carry.set_0();
				break;
			}
		}
	}
	return (rarg);
}

template<typename UINT_T,UINT_T B,size_t N>
	constexpr inline
	const reg_digs_t<UINT_T,B,N>&
	m_sum(
		reg_digs_t<UINT_T,B,N>& larg,
		const reg_digs_t<UINT_T,B,N>& rarg
	) noexcept
{
	//using SIG_UINT_T = typename type_traits::sig_UInt_for_UInt_t<UINT_T>;
	using dig_t			 = dig_t<UINT_T,B>;
	//using reg_digs_t = reg_digs_t<UINT_T,B,N>;

	dig_t carry{dig_t::dig_0()};
	for(size_t i=0 ; i < N ; ++i) {
		dig_t& left{larg[i]};
		const dig_t left_Bm1{left.C_Bm1()};
		const dig_t& right{rarg[i]};

		if constexpr (B > static_cast<UINT_T>(2u))
			if (carry.is_0())
				if (left_Bm1 >= right)
					carry.set_0();
				else
					carry.set_1();
			else {
				if(	left_Bm1.is_not_0() && right.is_not_Bm1()	)
					if  (--left_Bm1 > right)
						carry.set_0();
					else
						carry.set_1();
				else
					carry.set_1();
				++left;
			}
		else
			if (carry.is_0())
				if (left.is_0() || right.is_0())
					carry.set_0();
				else {
					carry.set_1();
					++left;
				}
			else
				if (left.is_1() || right.is_1()) {
					carry.set_1();
					++left;
				}
				else
					carry.set_0();
		left += right;
	}
	return (larg);
}

/// FUNCIONES DE IMPLEMENTACION DE LA DIVISION ENTRE DOS REGISTROS DE DIGITOS
/// BEGIN
template<typename UINT_T, UINT_T B, size_t N>
	requires (N>1)
constexpr inline
reg_digs_t<UINT_T,B,N> aprox_units_divB(const reg_digs_t<UINT_T,B,N>& arg) noexcept
///< PRECONDITIONS : ARG != 0 AND ARG != 1 >
{
	/// CASO EN QUE LA LONGITUD PERMANECE
	///  999 		; 998 	; 997 	; 996
	///  099,9 	; 099,8 ; 099,7 ; 099,6
	///  100		; 100		;	100		;	100
	using dig_t = dig_t<UINT_T,B>;
	reg_digs_t<UINT_T,B,N> cparg{arg};
	if ((cparg >> 1).is_0()) {
		return cparg;
	}
	else if ((cparg[0]<= dig_t{B/2})||(cparg.is_any_B_pow())) {
		cparg >>= 1;
		return cparg;
	}
	else if (cparg[N-1].is_not_Bm1()) {
		cparg >>= 1;
		m_incr(cparg);
		return cparg;
	}
	else {
		auto temp = arg.template subregister<1,N>();
		if (temp.is_filled_of_Bm1()){
			/// CPARG == Bm1 Bm1 Bm1 ... Bm1 Bm1 Bm1 d0<B/2
			cparg.set_0();
			cparg[N-1].set_1();
			return cparg;
		}
		else {
			/// CPARG == Bm1 dnm2 dnm3 ... d3 d2 d1 d0
			cparg >>= 1;
			m_incr(cparg);
			return cparg;
		}
	}
} ///< POSTCONDICION RET[N-1] == (DIG_1() | DIG_0())
	///< POSTCONDICION RET[N-1] == DIG_1() => RET[N-2,0] == REGD_N_0()

///< HAY QUE VER SI ES POTENCIA DE B : is_any_B_pow
template<typename UINT_T, UINT_T B, size_t N, size_t n>
	requires ((n > 0) && (n < N) && (N > 1)) /// N == SIZE_FROM n == SIZE_TO
constexpr inline
reg_digs_t<UINT_T,B,N> aprox_units_divB_n(const reg_digs_t<UINT_T,B,N>& arg) noexcept
{
	if constexpr (n == N-1){
		return aprox_units_divB<UINT_T,B,N>(arg);
	}
	else {
		reg_digs_t<UINT_T,B,N> cparg{arg}; // n = N-x => x = N-n
		for(size_t ix{0} ; ix < N-n ; ++ix) {
			cparg = aprox_units_divB<UINT_T,B,N>(cparg);
		}
		return cparg;
	}
}

///< FUNCION DE RECURSION PARA LA DIVISION
///< APROX_COC_REM APROXIMA REMAINDER A 2 DIGITOS Y DIVISOR A 1 DIGITO
template<typename UINT_T, UINT_T B, size_t N>
	requires (N > 0)
constexpr inline
/// std::array<SIG_UINT_T,2>{}[0] == COC
/// std::array<SIG_UINT_T,2>{}[1] == REM
/// PRECONDICION DSOR != 0 Y DSOR != 1
std::array<type_traits::sig_UInt_for_UInt_t<UINT_T>,2>
aprox_coc_rem(
		const reg_digs_t<UINT_T,B,N>& rem,
		const reg_digs_t<UINT_T,B,N>& dsor
) noexcept {
	using SIG_UINT_T = type_traits::sig_UInt_for_UInt_t<UINT_T>;

	std::array<SIG_UINT_T,2> ret;

	const size_t dsor_msb{static_cast<size_t>(dsor.index_of_MSDig())};
	const SIG_UINT_T rem_uint {SIG_UINT_T(rem)};
	const SIG_UINT_T dsor_uint {dsor[dsor_msb]()};

	SIG_UINT_T coc_calculado = rem_uint / dsor_uint;
	SIG_UINT_T rem_calculado = rem_uint % dsor_uint;

	if (dsor_msb==0) {/// CASO EXACTO
		/// SIZE(DIVISOR) == 1 DIGITO !=0 !=1
		//const SIG_UINT_T rem_uint {SIG_UINT_T(rem)};
		//const SIG_UINT_T dsor_uint {dsor[0]()};
		//SIG_UINT_T coc_calculado = rem_uint / dsor_uint;
		//SIG_UINT_T rem_calculado = rem_uint % dsor_uint;
		const SIG_UINT_T rem_aprox {SIG_UINT_T(dsor)*coc_calculado+rem_calculado};

		ret[1] = rem_calculado;
		ret[0] = coc_calculado;
		return ret;
	}
	else {
		/// SIZE(DIVISOR) >= 2
		/// 2545/278 o mayores
		reg_digs_t<UINT_T,B,N> dsor_red{dsor};
		uint64_t ix{0};
		for( ; ix < N ; ++ix) {
			dsor_red = aprox_units_divB<UINT_T,B,N>(dsor_red);
			if (dsor_red.template index_of_MSDig<UINT_T,B,N>() == 1)
				break;
		}
		reg_digs_t<UINT_T,B,N> rem_red{rem};

		for(int64_t iy{ix} ; iy > -1 ; --iy) {
			rem_red = aprox_units_divB<UINT_T,B,N>(rem_red);
		}

		const SIG_UINT_T dsor_uint {SIG_UINT_T(dsor_red)};
		const SIG_UINT_T rem_uint {SIG_UINT_T(rem_red)};
		const reg_digs_t<UINT_T,B,N> rem_aprox {
			dsor*dig_t{coc_calculado}+dig_t{rem_calculado}
		};

		if ((rem_aprox <= rem)&&(rem_aprox + dsor > rem)) {
			/// CORRECTO EN COC
			ret[1] = rem_calculado;
			ret[0] = coc_calculado;
			return ret;
		}
		else if (rem_aprox > rem) {
			/// NOS HEMOS PASADO EN EL COC
			--coc_calculado;
			rem_calculado += dsor_uint;
			return aprox_coc_rem<UINT_T,B,N>(rem,dsor,coc_calculado,rem_calculado);
		}
		else {
			/// NOS HEMOS QUEDADO CORTOS EN EL COC rem_aprox + dsor_uint <= rem
			++coc_calculado;
			rem_calculado -= dsor_uint;
			return aprox_coc_rem<UINT_T,B,N>(rem,dsor,coc_calculado,rem_calculado);
		}
	}
}

///< FUNCION DE RECURSION PARA LA DIVISION
///< SOBRECARGA DE LA ANTERIOR PARA LA RECURSION QUE NO SEA EL PRIMER CASO
template<typename UINT_T, UINT_T B, size_t N>
	requires (N > 0)
constexpr inline
/// std::array<SIG_UINT_T,2>{}[0] == COC
/// std::array<SIG_UINT_T,2>{}[1] == REM
/// PRECONDICION DSOR != 0 Y DSOR != 1
std::array<type_traits::sig_UInt_for_UInt_t<UINT_T>,2>
aprox_coc_rem(
		const reg_digs_t<UINT_T,B,N>& rem	  ,
		const reg_digs_t<UINT_T,B,N>& dsor	,
		type_traits::sig_UInt_for_UInt_t<UINT_T> coc_calculado 	,
		type_traits::sig_UInt_for_UInt_t<UINT_T> rem_calculado
	) noexcept
{ /// SUPONEMOS QUE REM TIENE TAMANO 1 o 2
	/// DSOR YA REDUCIDO TIENE TAMANO 1
	using SIG_UINT_T = type_traits::sig_UInt_for_UInt_t<UINT_T>;
	std::array<SIG_UINT_T,2> ret;
	const size_t dsor_msb{static_cast<size_t>(dsor.index_of_MSDig())};
	if (dsor_msb==0) {
		/// SIZE(DIVISOR) == 1 DIGITO !=0 !=1
		const SIG_UINT_T rem_aprox {SIG_UINT_T(dsor)*coc_calculado+rem_calculado};
		const SIG_UINT_T rem_uint {SIG_UINT_T(rem)};
		const SIG_UINT_T dsor_uint {dsor[0]()};
		if ((rem_aprox <= rem_uint)&&(rem_aprox + dsor_uint > rem_uint)) {
			/// CORRECTO EN COC
			ret[1] = rem_calculado;
			ret[0] = coc_calculado;
			return ret;
		}
		else if (rem_aprox > rem) {
			/// NOS HEMOS PASADO EN EL COC
			--coc_calculado;
			rem_calculado += dsor_uint;
			return aprox_coc_rem<UINT_T,B,N>(rem,dsor,coc_calculado,rem_calculado);
		}
		else {
			/// NOS HEMOS QUEDADO CORTOS EN EL COC rem_aprox + dsor_uint <= rem
			++coc_calculado;
			rem_calculado -= dsor_uint;
			return aprox_coc_rem<UINT_T,B,N>(rem,dsor,coc_calculado,rem_calculado);
		}
		/// 24/7
	}
	else {
		/// SIZE(DIVISOR) >= 2
		/// 2545/278 o mayores
		reg_digs_t<UINT_T,B,N> dsor_red{dsor};
		int32_t ix{0};
		for( ; ix < N ; ++ix) {
			dsor_red = aprox_units_divB<UINT_T,B,N>(dsor_red);
			if (dsor_red.template index_of_MSDig<UINT_T,B,N>() == 1)
				break;
		}
		reg_digs_t<UINT_T,B,N> rem_red{rem};
		for( ; ix > -1 ; --ix) {
			rem_red = aprox_units_divB<UINT_T,B,N>(rem_red);
		}

		const SIG_UINT_T dsor_uint {SIG_UINT_T(dsor_red)};
		const SIG_UINT_T rem_uint {SIG_UINT_T(rem_red)};
		const reg_digs_t<UINT_T,B,N> rem_aprox {dsor*dig_t{coc_calculado}+dig_t{rem_calculado}};

		if ((rem_aprox <= rem)&&(rem_aprox + dsor > rem)) {
			/// CORRECTO EN COC
			ret[1] = rem_calculado;
			ret[0] = coc_calculado;
			return ret;
		}
		else if (rem_aprox > rem) {
			/// NOS HEMOS PASADO EN EL COC
			--coc_calculado;
			rem_calculado += dsor_uint;
			return aprox_coc_rem<UINT_T,B,N>(rem,dsor,coc_calculado,rem_calculado);
		}
		else {
			/// NOS HEMOS QUEDADO CORTOS EN EL COC rem_aprox + dsor_uint <= rem
			++coc_calculado;
			rem_calculado -= dsor_uint;
			return aprox_coc_rem<UINT_T,B,N>(rem,dsor,coc_calculado,rem_calculado);
		}
	}
}
/// END

/// FUNCIONES DE IMPLEMENTACION DE LA DIVISION ENTRE DOS REGISTROS DE DIGITOS
template<typename UINT_T,UINT_T B,size_t N,size_t M>
	requires (N > 0)&&(M > 0)
constexpr inline
std::array<reg_digs_t<UINT_T,B,std::max(N,M)>,2>
fediv(
	const reg_digs_t<UINT_T,B,N> & larg,
	const reg_digs_t<UINT_T,B,M> & rarg
) noexcept {

	constexpr size_t MaxParam = std::max(N,M);
	using base_t = reg_digs_t<UINT_T,B,MaxParam>;
	using SIG_UINT_T = type_traits::sig_UInt_for_UInt_t<UINT_T>;

	using ret_type = std::array<base_t,2>;

	base_t dndo{larg};
	base_t dsor{rarg};

	const int32_t dsor_MSDig{larg.index_of_MSDig()};
		/// MOST SIGNIFICANT DIGIT DEL DIVISOR [DEL NUMERO NO DEL TIPO]
	const int32_t dndo_MSDig{rarg.index_of_MSDig()};
		/// MOST SIGNIFICANT DIGIT DEL DIVIDENDO [DEL NUMERO NO DEL TIPO]
	const size_t  dist_dndo_dsor{std::abs(dndo_MSDig-dndo_MSDig)};

	base_t rem{base_t::regd_0()};
	base_t coc{base_t::regd_0()};

	if (is_0(dsor)) {
		ret_type ret;
		ret[0] = std::move(coc);
		ret[1] = std::move(rem);
		return ret;
	}
	else if (is_1(dsor)) {
		ret_type ret;
		ret[0] = dndo;
		ret[1].set_0();
		return ret;
	}
	else if (dndo < dsor) {
		ret_type ret;
		ret[0].set_0();
		ret[1] = dndo;
		return ret;
	}
	else if (dndo == dsor) {
		ret_type ret;
		ret[0].set_1();
		ret[1].set_0();
		return ret;
	}
	else {
		int64_t pl_dndo{dndo_MSDig-dsor_MSDig+1};
		for(int64_t ix{dsor_MSDig},iy{dndo_MSDig} ; ix>-1 ; --ix,--iy) {
			rem[ix] = dndo[iy];
		}

		for(size_t numloops{0} ; numloops<dist_dndo_dsor ; ++numloops)
		{
			if (rem == dsor) {
				coc <<= 1;
				coc[0] = base_t::dig_1();
				rem = base_t::regd_0();
				--pl_dndo;
				rem[0] = dndo[pl_dndo];
			}
			else if (rem < dsor) {
				coc <<= 1;
				coc[0] = base_t::dig_0();
				rem <= 1;
				--pl_dndo;
				rem[0] = dndo[pl_dndo];
			}
			///	else if (rem >= dsor*dig_B()) {
			///		este caso no se deberia de dar nunca
			///	}
			else {
				auto ret{aprox_coc_rem<N>(rem,dsor)};
				SIG_UINT_T coc_dig{ret[0]};
				SIG_UINT_T rem_dig{ret[1]};

				coc <<= 1; 	// coc = coc * B
				coc[0] = dig_t(coc_dig); // coc = coc + D  ; B-1 >= D > 1
				--pl_dndo;
				rem <<= 1;
				rem[0] = dndo[pl_dndo];
			}
		}
		std::array<reg_digs_t<UINT_T,B,std::max(N,M)>,2> ret;
		ret[0] = coc;
		ret[1] = rem;
		return ret;
	}
}

  /// FUNCION QUE CONSIGUE EL TOKEN DIGITO
  template<type_traits::unsigned_integral_c UINT_T,UINT_T B>
  bool get_digit_token(std::istream& is,dig_t<UINT_T,B>& dig_value)
  {
    std::string old_input_string{""};
    std::string new_input_string{""};
    size_t index{0};
    char input_char = type_traits::nullchar<char>;
    UINT_T uint_value = 0;
    dig_value = dig_t<UINT_T,B>::dig_0();
    while(true) {
      is >> input_char;
      if ((index==0)&&(lex::is_separator(input_char))) {
        new_input_string += input_char;
        old_input_string = new_input_string;
        ++index;
      }
      else if ((index == 0)&&(! lex::is_separator(input_char))) {
        std::cerr << "Has cometido un error, tenias que "
        << " escribir \" " << '#' << " \"  y has escrito "
        << new_input_string << std::endl;
        std::cerr << "Considera que has escrito "
        << old_input_string
        << " y continua escribiendo a partir de ahi";
        new_input_string = old_input_string;
      }
      else if((index>=1) && lex::is_digit(input_char)) {
        if (lex::digit_value(input_char) < B) {
          new_input_string += input_char;
          uint_value *= B;
          uint_value += lex::digit_value(input_char);
          if (uint_value < B) {
            old_input_string = new_input_string;
            dig_value = dig_t<UINT_T,B>(uint_value);
            ++index;
          }
          else {
            old_input_string = "#";
            std::cerr << "Has cometido un error, tenias que "
            << "poner un valor menor que la base y has "
            << "puesto \" " << uint_value << " \" escrito como \" "
            << new_input_string << " \" " << std::endl;
            uint_value = 0;
            return false;
          }
        }
        else if((index>=1) &&
								! lex::is_digit(input_char) &&
								(input_char != '_')
					) {
          std::cerr << "El caracter "
										<< input_char
										<< " no es valido aqui "
										<< std::endl;
          uint_value = 0;
          return false;
        }
      }
      else if((index>1)&&(input_char == '_')) {
        return true;
      }
      else{
        std::cerr << "Has cometido un error, tenias que escribir "
        << " \" " << "#digdigdig..._"
        << " \"  y has escrito "
        << new_input_string << std::endl;
        uint_value = 0;
        return false;
      }
    }
  }

  /// FUNCION QUE CONSIGUE EL TOKEN BASE
  template<type_traits::unsigned_integral_c T,T B>
  bool get_radix_token(std::istream& is) {
    return dig_t<T,B>::get_radix_token(is);
  }

  template<type_traits::unsigned_integral_c T,T B,size_t L>
  bool get_digit_loop_token (
		std::istream& is,reg_digs_t<T,B,L>& value
	) noexcept {
		size_t idx{0};
		while(true) {
			if(idx < L) {
				if (get_digit_token(is,value[idx])) {
					++idx;
				}
				else {
					for(;idx < L;++idx) {
						value[idx] = 0;
					}
					std::cerr << " error consiguiendo el digito " << idx
										<< std::endl;
					std::cerr << " digitos a 0 a partir del indice = " << idx
										<< std::endl;
					return false;
				}
			}
			if (idx >= L)
				return true;
		}
	}

	///< SOLO HAY QUE DECLARAR digit_t<2> o digit_t<10> o ...
	template<type_traits::unsigned_integral_c T,T B,size_t L>
	bool read (std::istream& is,reg_digs_t<T,B,L>& value)
	noexcept {
		//std::cerr
		reg_digs_t<T,B,L> default_value{};
		bool type_token = reg_digs_t<T,B,L>::get_type_template_string_id_token(is);
		if (type_token) {
			if (get_digit_loop_token(is,value)) {
				if (dig_t<T,B>::get_radix_token(is)) {
					return true;
				}
				else {
					value = default_value;
					return false;
				}
			}
			else {
				value = default_value;
				return false;
			}
		} else {
			value = default_value;
			return false;
		}
	}

  ///< DEFINCION DE template<uint128_t Radix> digito_t{};
  using namespace type_traits;
	template<uint128_t B>
	using digit_t = dig_t<
			TypeFromIntNumber_t<static_cast<uint128_t>(B)>,
			static_cast<TypeFromIntNumber_t<static_cast<uint128_t>(B)>>(static_cast<uint128_t>(B))
		>;
	template<uint128_t B, size_t L>
	using register_digs_t = reg_digs_t<
			TypeFromIntNumber_t<static_cast<uint128_t>(B)>,
			static_cast<TypeFromIntNumber_t<static_cast<uint128_t>(B)>>(static_cast<uint128_t>(B)),
			L
	>;

	/// SOBRECARGA DE ISTREAM Y OSTREAM CON LOS OPERADORES DE DESPLAZAMEINTO
	template<typename Int_Type,Int_Type Base,size_t Length>
		requires (type_traits::suitable_base<Int_Type,Base>()&&(Length > 0))
	std::istream &
	operator >> (std::istream & is,reg_digs_t<Int_Type,Base,Length> & arg) {
		enum estado_e {
			e0ini	, e1r		, e1e		, e1g			, e1sep		,
			e1d		, e1i		, e2g		, e2start	, e2dig		,
			e2dp	, e2end	, e2B		, e3dig		, e0fin
		};
		/// STRING RECOGIDO DESDE LA ENTRADA ESTANDAR CIN
		constexpr size_t longitud_cadena{(Length+1)*static_cast<size_t>(std::ceil(std::log2(static_cast<long double>(Base))+1))+16};
		std::string sds{};
		sds.resize(longitud_cadena);
		sds.assign(longitud_cadena,'\0');
		/// TIPOS A SER UTILIZADOS EN LA FUNCIÓN: NOMBRE DE TIPOS CORTOS
		using inttype 		= typename type_traits::sig_UInt_for_UInt_t<Int_Type>;
		using dig_t 			= dig_t<Int_Type,Base>;
		using reg_digs_t 	= reg_digs_t<Int_Type,Base,Length>;
		/// INDICE QUE RECORRE EL STRING RECOGIDO DE ENTRADA
		size_t	indice{0};
		/// VARIABLES PARA ACCIONES EN LOS ESTADOS
		Int_Type digito{0};
		size_t longitud{0};
		inttype numero_base_recogido{0};
		/// VARIABLE DE RETORNO (BINDED TO THE ARG BY REFERENCE)
		reg_digs_t& numero_ret{arg};
		/// ESTADO ACTUAL
		estado_e est_act = e0ini;
		/// CARACTER QUE GUARDARA EL INDICADO POR EL INDICE DEL STRING RECOGIDO DESDE CIN
		char c = type_traits::nullchar<char>;
		/// RECOGEMOS DESDE LA ENTRADA EL STRING CON LA INFORMACION CODIFICADA
		is >> sds;
		/// MAQUINA DE ESTADOS FINITOS QUE HACE EL PARSE() DE LA ENTRADA
		do {
		c = sds[indice];
			switch(est_act) {
				case e0ini :
					{
						if (c=='r') {
							est_act = e1r;
						} else {
							est_act = e0ini;
						}
					}
					break;
				case e1r :
					{
						{
							if (c=='e') {
								est_act = e1e;
							}
							else {
								est_act = e0ini;
							}
						}
					}
					break;
				case e1e :
					{
						if (c=='g') {
							est_act = e1g;
						}
						else  {
							est_act = e0ini;
						}
					}
					break;
				case e1g :
					{
						if (c=='_') {
							est_act = e1sep;
						}
						else  {
							est_act = e0ini;
						}
					}
					break;
				case e1sep :
					{
						if (c=='d') {
							est_act = e1d;
						}
						else  {
							est_act = e0ini;
						}
					}
					break;
				case e1d :
					{
						if (c=='i') {
							est_act = e1i;
						}
						else  {
							est_act = e0ini;
						}
					}
					break;
				case e1i :
					{
						if (c=='g') {
							est_act = e2g;
						}
						else  {
							est_act = e0ini;
						}
					}
					break;
				case e2g :
					{
						if (c=='#') {
							est_act = e2start;
						}
						else  {
							est_act = e0ini;
						}
					}
					break;
				case e2start :
					{
						if (((c>='0')&&(c<='9'))&&(std::abs(c-'0')<Base)) {
							est_act = e2dig;
							digito = (c-'0');
							longitud = 0;
							numero_base_recogido = 0;
							numero_ret = reg_digs_t::regd_0();
						}
						else  {
							est_act = e0ini;
							digito = 0;
							longitud = 0;
							numero_base_recogido = 0;
							numero_ret = reg_digs_t::regd_0();
						}
					}
					break;
				case e2dig :
					{
						const bool dig_c {(c >= '0') && (c <= '9')};
						const bool dig_lt_Base{digito<Base};
						const bool c_es_dig_B {dig_c && dig_lt_Base};
						const bool dig_B_cdl {c_es_dig_B && (longitud <= Length-1)};
						const bool tt_dig_B_cdl {(c==':')&&dig_lt_Base&&(longitud <= Length-1)};
						const bool tf_dig_B_cdl {(c=='#')&&dig_lt_Base&&(longitud == Length-1)};
						if (dig_B_cdl) {
							digito *= 10;
							digito += (c-'0');
							est_act = e2dig;
						}
						else if (tt_dig_B_cdl) {
							est_act = e2dp;
						}
						else if (tf_dig_B_cdl) {
							est_act = e2end;
						}
						else  {
							est_act = e0ini;
							digito = 0;
							longitud = 0;
							numero_base_recogido = 0;
							numero_ret = reg_digs_t::regd_0();
						}
					}
					break;
				case e2dp :
					{
						const bool dig_c {(c >= '0') && (c <= '9')};
						const bool c_es_dig_B {(std::abs(c-'0')<Base) && (digito<Base)};
						const bool dig_B_cdl {dig_c && c_es_dig_B && (longitud < Length-1)};
						const bool rdig_B_cdl {dig_c && c_es_dig_B && dig_B_cdl};
						if (rdig_B_cdl) {
							est_act = e2dig;
							numero_ret[Length-1-longitud] = dig_t(digito);
							++longitud;
							digito = c-'0';
						}
						else  {
							est_act = e0ini;
							digito = 0;
							longitud = 0;
							numero_base_recogido = 0;
							indice = 0;
							numero_ret = reg_digs_t::regd_0();
						}
					}
					break;
				case e2end :
					{
						const bool c_es_sepfin {c == 'B'};
						const bool d_es_digB {digito < Base};
						const bool l_coincide {longitud == Length-1};// llega al cero ?
						const bool rdigB_cdl {c_es_sepfin && d_es_digB && l_coincide};
						if (rdigB_cdl) {
							est_act = e2B;
							numero_ret[Length-1-longitud] = dig_t(digito);
							digito = 0;
							longitud = 0;
						}
						else  {
							est_act = e0ini;
							indice = 0;
							digito = 0;
							longitud = 0;
							numero_ret = reg_digs_t::regd_0();
						}
					}
					break;
				case e2B :
					{
						if ((c >= '0')&&(c <= '9')) {
							est_act = e3dig;
							numero_base_recogido = c-'0';
							digito = 0;
						}
						else  {
							est_act = e0ini;
							digito = 0;
							longitud = 0;
							numero_base_recogido = 0;
							numero_ret = reg_digs_t::regd_0();
						}
					}
					break;
				case e3dig :
					{
						const bool espacio_c {c < 16};
						const bool digito_c {(c>='0') && (c<='9')};
						const bool num_base_lt_Base {numero_base_recogido < Base};
						const bool num_base_eq_Base {numero_base_recogido == Base};
						if (digito_c && num_base_lt_Base) {
							est_act = e3dig;
							numero_base_recogido *= 10;
							numero_base_recogido += (c-'0');
						}
						else if (espacio_c && num_base_eq_Base) {
							numero_base_recogido *= 10;
							numero_base_recogido += (c-'0');
								est_act = e0fin;
								numero_base_recogido = 0;
						}
						else  {
							est_act = e0ini;
							numero_base_recogido = 0;
						}
					}
					break;
				case e0fin :
					{
						est_act = e0fin;
					}
			}
			++indice;
		} while (est_act!=e0fin);

		return (is);
	}

	template<typename Int_Type,Int_Type Base,size_t Long>
		requires (type_traits::suitable_base<Int_Type,Base>())
	std::ostream &
	operator << (
			std::ostream & os,
			const reg_digs_t<Int_Type,Base,Long> & arg)
	{
		using inttype = ullint_t;
		os << "reg_dig#";
		for(int32_t ix{Long-1} ; ix > 0 ; --ix) {
				os << static_cast<inttype>(arg[ix]());
				os << ':';
		}
		os << static_cast<inttype>(arg[0]());
		os << "#B";
		os << static_cast<inttype>(Base);
		return (os);
	}

} // END NAMESPACE NUMREPR

#endif // REG_DIGS_T_HPP_INCLUDED
