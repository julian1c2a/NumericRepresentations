#ifndef FIXED_SIZED_UNSIGNED_INT_TYPE__HPP
#define FIXED_SIZED_UNSIGNED_INT_TYPE__HPP

#include <array>
#include "dig_t.hpp"


template<const uchint B,const ullint ND>
class fs_uint_t : public std::array<dig_t<B>,ND> {
	
};




#endif //FIXED_SIZED_UNSIGNED_INT_TYPE__HPP