#ifndef GET_HPP_INCLUDED
#define GET_HPP_INCLUDED

#include "memory_handler.hpp"


/// BEGIN ADECUACIÓN DEL MAKE_INTEGER_SEQUECE<N> PARA EL CASO ACTUAL
// using aliases for cleaner syntax
template<class T>
using Invoke = typename T::type;

template<std::uint64_t ... >
struct seq{
	using type = seq;
};

template<class S1, class S2>
struct concat;

template<std::uint64_t... I1, std::uint64_t... I2>
struct concat<seq<I1...>, seq<I2...>>
  : seq<I1..., ((sizeof...(I1))+I2)...>{};

template<class S1, class S2>
using Concat = Invoke<concat<S1, S2>>;

/// Concat<S1,S2> == typename concat<S1,S2>::type;

template<std::uint64_t N>
	requires(N<253)
struct gen_seq;

template<std::uint64_t N>
	requires(N<254)
using GenSeq = Invoke<gen_seq<N>>;

/// GenSeq<N> = gen_seq<N>::type;
/// N/3 , N%3 in {0,1,2}
/// N/3,N/3-( (N%3==2) ? 1 : 0 ),(N/3)-( (N%3!=0) ? 1 : 0 )

template<std::uint64_t N>
struct gen_seq : Concat<GenSeq<N/2>, GenSeq<N - N/2>>
{};

/// gen_seq<N> == concat<gen_seq<N/2>::type,gen_seq<N - N/2>::type>::type
///            == concat<Concat<GenSeq<(N/2)/2      >,GenSeq<(N/2)-(N/2)/2          >>,
///                      Concat<GenSeq<((N-(N/2))/2)>,GenSeq<(N-(N/2))-((N-(N/2))/2)>>>
///            == concat<Concat<GenSeq<2>,GenSeq<3>>,
///                      Concat<GenSeq<3>,GenSeq<3>>>
///            == concat<Concat<gen_seq<2>::type,gen_seq<3>::type>,
///                      Concat<gen_seq<3>::type,gen_seq<3>::type>>
///            == concat<concat<gen_seq<2>::type,gen_seq<3>::type>::type,
///                      concat<gen_seq<3>::type,gen_seq<3>::type>::type>
///            == concat<seq<2,3,4,5,6>,seq<2,3,4,5,6,7>>
///            == seq<2,3,4,5,6,7,8,9,10,11,12>

template<> struct gen_seq<0> : seq<>{};
template<> struct gen_seq<1> : seq<2>{};
template<> struct gen_seq<2> : seq<2,3>{};
template<> struct gen_seq<3> : seq<2,3,4>{};
/// END ADECUACIÓN DEL MAKE_INTEGER_SEQUECE<N> PARA EL CASO ACTUAL

using genRadixDig_t = typename NumRepr::memory_handler::genRadixDig_t;

template<std::uint64_t R>
	requires ((R > 1ULL)&&(R < 256ULL))
std::uint64_t hold_radixtype(genRadixDig_t arg) {
	if (std::holds_alternative<NumRepr::dig_t<R>>(arg))
		return R;
	else
		return 0ULL;
}

template<std::uint64_t ... Rs>
constexpr inline
std::uint64_t get_radix_of_actual_type_helper(genRadixDig_t arg) {
	return (hold_radixtype<Rs>(arg)+...);
}

constexpr inline
std::uint64_t get_actual_radix(genRadixDig_t arg) {
	return get_radix_of_actual_type_helper<GenSeq<253>>(genRadixDig_t arg);
}

struct content {
	static constexpr
	std::uint64_t operator()(genRadixDig_t arg) {
		return get_actual_radix(arg);
	}
	using type = NumRepr::dig_t<content::operator(arg)>;
};

auto get_content(genRadixDig_t arg) -> decltype(auto) {
	return std::get<get_actual_radix(arg)>(arg);
}

#endif // GET_HPP_INCLUDED
