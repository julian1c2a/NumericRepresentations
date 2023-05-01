#ifndef GET_HPP_INCLUDED
#define GET_HPP_INCLUDED

#include "memory_handler.hpp"

using genRadixDig_t = typename NumRepr::memory_handler::genRadixDig_t;

template<std::uint64_t R>
	requires ((R > 1ULL)&&(R < 256ULL))
std::uint64_t hold_radixtype(genRadixDig_t arg) {
	if (std::holds_alternative<NumRepr::dig_t<R>>(arg))
		return R;
	else
		return 0ULL;
}

template<std::uint64_t ...Rs>
std::uint64_t get_radix_of_type_helper(	genRadixDig_t arg ) {
	return (hold_radixtype<Rs>(arg)+...);
}

std::uint64_t get_radix_of_type( genRadixDig_t arg );

#endif // GET_HPP_INCLUDED
