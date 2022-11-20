#ifndef REG_DIGS_T_HPP_INCLUDED
#define REG_DIGS_T_HPP_INCLUDED

#include "dig_t.hpp"
#include "utilities.hpp"

namespace NumRepr {
  using type_traits::allowable_base_type_c;
  template<uint128_t B,size_t L>
    requires ((B > 1)&&(L > 0))
  using reg_digs_t = typename std::array<digit_t<B>,L>;
}

#endif // REG_DIGS_T_HPP_INCLUDED
