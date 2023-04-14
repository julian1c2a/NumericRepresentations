#ifndef AUXILIARY_TYPES_HPP_INCLUDED
#define AUXILIARY_TYPES_HPP_INCLUDED

#include "basic_types.hpp"

namespace NumRepr {

/****************************/
//
//	SIGNO
//
/****************************/

enum class sign_e : bool { vminus = true, vplus = false }; /// INTRODUCIDO
enum class sign_funct_e : char { vzero = 0, vminus = -1, vplus = +1 };
enum class dig_format_e : unsigned char {
  BINnat = 0,
  BCDnat = 1,
  BCDexc3 = 2,
  BCDaitk = 3,
  johnson_n = 4,
  biquinario = 5
}; /// A INTRODUCIR
enum class num_type_e : unsigned char {
  natural = 0,
  entero = 1,
  racional = 2,
  real = 3
}; /// YA INTRODUCIDO, PERO NO EXPLICITAMENTE NI COMPLETAMENTE
enum class nat_num_format_e : bool {
  natural = false,
  exc_n = true
}; /// SOLO NATURAL
enum class int_num_format_e : unsigned char {
  int_CB = 0,
  int_CBm1 = 1,
  int_MS = 2,
  int_EXC_n = 3
}; /// EN C_B YA QUEDA EN MS
enum class rat_num_format_e : unsigned char {
  pair_num_den = 0,
  fxd_pt = 1,
  flt_pt = 2
};

enum class binop_e { add, sub, mult, div, rem, fediv, other };

namespace auxiliary_types {
/// auxiliary types for digit type and its operations
template <typename T, binop_e oper> struct resbinop_t;

template <typename T> struct resbinop_t<T, binop_e::add> {
  T content;
  T carry;
};

template <typename T> struct resbinop_t<T, binop_e::sub> {
  T content;
  T borrow;
};

template <typename T> struct resbinop_t<T, binop_e::mult> {
  T low_content;
  T high_content;
};

template <typename T> struct resbinop_t<T, binop_e::fediv> {
  T quotient;
  T remainder;
  bool no_div_by_0;
};

template <typename T> struct resbinop_t<T, binop_e::div> {
  T quotient;
  bool no_div_by_0;
};

template <typename T> struct resbinop_t<T, binop_e::rem> {
  T remainder;
  bool no_div_by_0;
};

template <typename T, binop_e oper, size_t N>
  requires(N > 0)
struct result_operation_t;

template <typename T, size_t N>
  requires(N > 0)
struct result_operation_t<T, binop_e::add, N> {
  std::array<T, N> result_content_low;
  T carry;
  bool good_result;
};

template <typename T, size_t N>
  requires(N > 0)
struct result_operation_t<T, binop_e::sub, N> {
  std::array<T, N> result_content_low;
  T borrow;
  bool good_result;
};

template <typename T, size_t N>
  requires(N > 0)
struct result_operation_t<T, binop_e::mult, N> {
  std::array<T, N> result_content_low;
  std::array<T, N> result_content_high;
  bool good_result;
};

template <typename T, size_t N>
  requires(N > 0)
struct result_operation_t<T, binop_e::fediv, N> {
  std::array<T, N> result_content_quotient;
  std::array<T, N> result_content_remainder;
  bool good_result;
};

template <typename T, size_t N>
  requires(N > 0)
struct result_operation_t<T, binop_e::div, N> {
  std::array<T, N> result_content_quotient;
  bool good_result;
};

template <typename T, size_t N>
  requires(N > 0)
struct result_operation_t<T, binop_e::rem, N> {
  std::array<T, N> result_content_remainder;
  bool good_result;
};
} // namespace auxiliary_types
} // namespace NumRepr

#endif // AUXILIARY_TYPES_HPP_INCLUDED
