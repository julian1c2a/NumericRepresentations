#ifndef AUXILIARY_FUNCTIONS_HPP_INCLUDED
#define AUXILIARY_FUNCTIONS_HPP_INCLUDED

#include "auxiliary_types.hpp"

namespace NumRepr {

constexpr inline
sign_e Char2Sign(char ch) noexcept
{
	if (ch <= ',')
		return sign_e::vplus;
	else
		return sign_e::vminus;
}

template<arith_integral_c IntT>
constexpr inline
sign_e Int2Sign (IntT nu) noexcept
{
	if (nu < 0)
		return sign_e::vminus;
	else
		return sign_e::vplus;
}

template<arith_integral_c IntT>
constexpr inline
sign_funct_e Int2SignFunct (IntT nu) noexcept
{
	if (nu < 0)
		return sign_funct_e::vminus;
	else if (nu > 0)
		return sign_funct_e::vplus;
	else
		return sign_funct_e::vzero;
}

template<arith_natural_c NatIntT>
constexpr inline
sign_funct_e Nat2SignFunct (NatIntT nu) noexcept
{
	if (nu==0)
		return sign_funct_e::vzero;
	else
		return sign_funct_e::vplus;
}

namespace detail {
// precondition: low*low <= n, high*high > n.
constexpr inline
size_t ceilsqrt(size_t n,size_t low,size_t high) noexcept
{
  const auto mid{std::midpoint(low, high)};
  const auto sqmid{mid*mid};
  return
	(
		(low + 1 >= high)	?
			high			:
			(sqmid == n)		?
				mid      		:
				(sqmid <  n)		?
					ceilsqrt(n, mid, high)	:
					ceilsqrt(n, low, mid)
	);
}

// returns ceiling(sqrt(n))
constexpr inline
size_t ceilsqrt(size_t n) noexcept
{
  const auto num_max_dig{std::numeric_limits<std::size_t>::digits};
  return
	(
		(n < 3)	?
			n	:
			ceilsqrt(
				n,
				1,
				std::size_t(1) << (num_max_dig / 2)
			)
	);
}

// returns true if n divisible by an odd integer in
// [2 * low + 1, 2 * high + 1).
constexpr inline
bool find_factor(size_t n,size_t low,size_t high) noexcept
{
  const auto mid{std::midpoint(low, high)};
  return
	(
		(low + 1 >= high)				?
			(n % (2 * low + 1)) == 0	:
			(
				find_factor(n, low, mid)
				||
				find_factor(n, mid, high)
			)
	);
}
}
namespace auxiliary_functions {
	constexpr inline
	bool is_prime(size_t n) noexcept
	{
		if (n < 2)
			return false;
		else if ((n==2)||(n==3))
			return true;
		else
			return (!detail::find_factor(n, 1, (detail::ceilsqrt(n) + 1) / 2));
	}
	constexpr inline
	bool is_power_of_2(uint128_t num) noexcept
	{
		if((num % 2) != 0)
			return false;
		else
			return is_power_of_2(num / 2);
	}
}
}
#endif // AUXILIARY_FUNCTIONS_HPP_INCLUDED
