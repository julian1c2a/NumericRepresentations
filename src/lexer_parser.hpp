#ifndef LEXER_PARSER_HPP_INCLUDED
#define LEXER_PARSER_HPP_INCLUDED

#include "auxiliary_types.hpp"

namespace NumRepr {
namespace lex {
  enum class reglexst_e : uint16_t {
    st_00= 0,st_01= 1,st_02=2,st_03=3,st_04= 4,st_05= 5,
    st_06= 6,st_07= 7,st_08=8,st_09=9,st_10=10,st_11=11,
    st_12=12,st_13=13
  };
  enum class sintaxerrlexst_e : uint16_t {
    st_err_00 = 256,st_err_01 = 257,st_err_02 = 258,
    st_err_03 = 259,st_err_04 = 260,st_err_05 = 261,
    st_err_06 = 262,st_err_07 = 263,st_err_08 = 264,
    st_err_09 = 265,st_err_10 = 266,st_err_11 = 267,
    st_err_12 = 268,st_err_13 = 269
  };
  enum class semerrlexst_e : uint16_t {
    st_sem_00 = 4096,st_sem_01 = 4097,st_sem_02 = 4098,
    st_sem_03 = 4099,st_sem_04 = 4100,st_sem_05 = 4101,
    st_sem_06 = 4102,st_sem_07 = 4103,st_sem_08 = 4104,
    st_sem_09 = 4105,st_sem_10 = 4106,st_sem_11 = 4107,
    st_sem_12 = 4108,st_sem_13 = 4109
  };
  enum class lexst_e : uint16_t {
    reg_00 =  0,
    reg_01 =  1,
    reg_02 =  2,
    reg_03 =  3,
    reg_04 =  4,
    reg_05 =  5,
    reg_06 =  6,
    reg_07 =  7,
    reg_08 =  8,
    reg_09 =  9,
    reg_10 = 10,
    reg_11 = 11,
    reg_12 = 12,
    reg_13 = 13,
    err_00 = 256,
    err_01 = 257,
    err_02 = 258,
    err_03 = 259,
    err_04 = 260,
    err_05 = 261,
    err_06 = 262,
    err_07 = 263,
    err_08 = 264,
    err_09 = 265,
    err_10 = 266,
    err_11 = 267,
    err_12 = 268,
    err_13 = 269,
    sem_00 = 4096,
    sem_01 = 4097,
    sem_02 = 4098,
    sem_03 = 4099,
    sem_04 = 4100,
    sem_05 = 4101,
    sem_06 = 4102,
    sem_07 = 4103,
    sem_08 = 4104,
    sem_09 = 4105,
    sem_10 = 4106,
    sem_11 = 4107,
    sem_12 = 4108,
    sem_13 = 4109
  };

  bool is_digit(char in) {
    return ((in >= '0')&&(in <= '9'));
  }

  size_t digit_value(char in) {
    return static_cast<size_t>(in-'0');
  }

  bool is_valid_char(char in) {
    return (in>='a' && in <='z')||(in>='A' && in<='Z');
  }

  bool char_value(char in) {
    if ((in>='a')&&(in <='z')){
      return in;
    }
    else{
      return (in-('A'-'a'));
    }
  }

  bool is_separator(char in) {
    return (in == '#');
  }

  bool is_end_of_number(char in) {
    return (in == '_');
  }

  bool is_whitespace(char in) {
    return ((in == ' ')||(in == '\t'));
  }

  bool is_end_descriptor(char in) {
    return (in == '\n')||(in == std::char_traits<char>::eof());
  }

  bool is_radix_descriptor(char in) {
    return ((in == 'b')||(in == 'B'));
  }

  bool is_sign(char in) {
    return ((in == '+')||(in == '-'));
  }

  NumRepr::sign_e sign_value(char in) {
    if (in == '+')
      return NumRepr::sign_e::vplus;
    else
      return NumRepr::sign_e::vminus;
  }
}
}
#endif // LEXER_PARSER_HPP_INCLUDED
