#ifndef LEXER_PARSER_HPP_INCLUDED
#define LEXER_PARSER_HPP_INCLUDED

#include "basic_types.hpp"

namespace lex {
	/// std::istream operator >> int_reg_digs_t
			/// pasamos error a std::cerr
	/// get_reg_digs_t(std::istream,
			///						 std::ostream,
			///						 int_reg_digs_t)
	///
	/// estados regulares
	///		st_00 st_01 st_02 st_03 st_04 st_05 st_06 st_07 st_08
	///		st_09 st_10 st_11 st_12 st_13
	/// estados error sintactico
	///		st_err_00 st_err_01 st_err_02 st_err_03 st_err_04
	///		st_err_05 st_err_06 st_err_07 st_err_08 st_err_09
	///		st_err_10 st_err_11 st_err_12 st_err_13
	/// estados error semantico
	///		st_sem_00 st_sem_01 st_sem_02 st_sem_03 st_sem_04
	///		st_sem_05 st_sem_06 st_sem_07 st_sem_08 st_sem_09
	///		st_sem_10 st_sem_11 st_sem_12 st_sem_13
	namespace lex{
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
		enum class lexst_e :
			reglexst_e,sintaxerrlexst_e,semerrlexst_e {
			reg_00 = reglexst_e::st_00,
			reg_01 = reglexst_e::st_01,
			reg_02 = reglexst_e::st_02,
			reg_03 = reglexst_e::st_03,
			reg_04 = reglexst_e::st_04,
			reg_05 = reglexst_e::st_05,
			reg_06 = reglexst_e::st_06,
			reg_07 = reglexst_e::st_07,
			reg_08 = reglexst_e::st_08,
			reg_09 = reglexst_e::st_09,
			reg_10 = reglexst_e::st_10,
			reg_11 = reglexst_e::st_11,
			reg_12 = reglexst_e::st_12,
			reg_13 = reglexst_e::st_13,
			err_00 = sintaxerrlexst_e::st_err_00,
			err_01 = sintaxerrlexst_e::st_err_01,
			err_02 = sintaxerrlexst_e::st_err_02,
			err_03 = sintaxerrlexst_e::st_err_03,
			err_04 = sintaxerrlexst_e::st_err_04,
			err_05 = sintaxerrlexst_e::st_err_05,
			err_06 = sintaxerrlexst_e::st_err_06,
			err_07 = sintaxerrlexst_e::st_err_07,
			err_08 = sintaxerrlexst_e::st_err_08,
			err_09 = sintaxerrlexst_e::st_err_09,
			err_10 = sintaxerrlexst_e::st_err_10,
			err_11 = sintaxerrlexst_e::st_err_11,
			err_12 = sintaxerrlexst_e::st_err_12,
			err_13 = sintaxerrlexst_e::st_err_13,
			sem_00 = semerrlexst_e::st_sem_00,
			sem_01 = semerrlexst_e::st_sem_01,
			sem_02 = semerrlexst_e::st_sem_02,
			sem_03 = semerrlexst_e::st_sem_03,
			sem_04 = semerrlexst_e::st_sem_04,
			sem_05 = semerrlexst_e::st_sem_05,
			sem_06 = semerrlexst_e::st_sem_06,
			sem_07 = semerrlexst_e::st_sem_07,
			sem_08 = semerrlexst_e::st_sem_08,
			sem_09 = semerrlexst_e::st_sem_09,
			sem_10 = semerrlexst_e::st_sem_10,
			sem_11 = semerrlexst_e::st_sem_11,
			sem_12 = semerrlexst_e::st_sem_12,
			sem_13 = semerrlexst_e::st_sem_13
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
		bool is_end_of_digit(char in) {
			return (in == '_');
		}
		bool is_whitespace(char in) {
			return ((in == ' ')||(in == '\t'));
		}
		bool is_desc_end(char in) {
			return (in == '\n')||(in == std::char_traits<char>::eof());
		}
		bool is_desc_radix(char in) {
			return ((in == 'b')||(in == 'B'));
		}
		bool is_sign(char in) {
			return ((in == '+')||(in == '-'));
		}
		sign_e sign_value(char in) {
			if (in == '+')
				return sign_e::vplus;
			else
				return sign_e::vminus;
		}
	
}

		/// DECLARACION GENERICA : FUNCION OBTENCION DEL TIPO
		template<
			template T,typename UIn_t,UIn_t B,size_t LE,size_t LF
		>
		bool is_type_id(std::string in);
		/// DECLARACION GENERICA : FUNCION OBTENCION DEL STRING IDENTIFICADOR DEL TIPO
		template<
			template T,typename UIn_t,UIn_t B,size_t LE,size_t LF
		> std::string to_string<T>();
		/// DECLARACION GENERICA : FUNCION OBTENCION DEL STRING IDENTIFICADOR DEL TIPO
		template<template T,typename UIn_t,UIn_t B,size_t LE,size_t LF>
		size_t size_of_string_idT<T>();
		/// ESPECIALIZACIONES PARA DIG_T
		template<typename UIn_t,UIn_t B>
		bool is_type_id<dig_t,UInt_t,B,0,0>(std::string in) {
			return	(
						(in == "dig")||
						(in == "di")||
						(in == "d")
					);
		}
		template<typename UInt_t,UInt_t B>
		std::string to_string<dig_t,UInt_t,B,0,0>()
		{	return std::string{"dig"};	}
		template<typename UInt_t,UInt_t B>
		size_t size_of_string_idT<dig_t,UInt_t,B,0,0>()
		{	return (to_string<dig_t,UInt_t,B,0,0>()).size();    }
		/// ESPECIALIZACIONES PARA REG_DIGS
		template<typename UInt_t,UInt_t B,size_t LE>
		bool is_type_id<reg_digs_t,UInt_t,B,LE,0>(std::string in) {
			return	(
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
		template<typename UInt_t,UInt_t B,size_t LE>
		std::string to_string<reg_digs_t,UInt_t,B,LE,0>()
		{	return std::string{"reg_digs"};	}
		template<typename UIn_t,UIn_t B>
		size_t size_of_string_idT<reg_digs_t,UInt_t,B,LE,0>()
		{	return (to_string<reg_digs_t,UInt_t,B,LE,0>()),size();	}
		/// ESPECIALIZACIONES PARA NAT_REG_DIGS
		template<typename UInt_t,UInt_t B,size_t LE>
		bool is_type_id<nat_reg_digs_t,UInt_t,B,LE,0>(std::string in)
		{   return(
					(in == "nat_reg_digs")||
					(in == "nat_reg_dig")||
					(in == "nat_reg_di")||
					(in == "nat_reg_d")||
					(in == "nat_reg_")||
					(in == "nat_reg")||
					(in == "nat_re")||
					(in == "nat_r")||
					(in == "nat_")||
					(in == "nat")||
					(in == "na")||
					(in == "n")
				);
		}
		template<typename UIn_t,UIn_t B,size_t LE>
		std::string to_string<nat_reg_digs_t,UInt_t,B,LE,0>()
		{   return std::string{"nat_reg_digs"};		}
		template<typename UInt_t,UInt_t B>
		size_t size_of_string_idT<nat_reg_digs_t,UInt_t,B,LE,0>()
		{	return (to_string<nat_reg_digs_t,UInt_t,B,LE,0>()).size();	}
		/// ESPECIALIZACIONES PARA INT_REG_DIGS_T
		template<typename UInt_t,UInt_t B,size_t LE>
		bool is_type_id<int_reg_digs_t,UInt_t,B,LE,0>(std::string in)
		{	return	(
						(in == "int_reg_digs")||
						(in == "int_reg_dig")||
						(in == "int_reg_di")||
						(in == "int_reg_d")||
						(in == "int_reg_")||
						(in == "int_reg")||
						(in == "int_re")||
						(in == "int_r")||
						(in == "int_")||
						(in == "int")||
						(in == "in")||
						(in == "i")
					);
		}
		template<typename UInt_t,UInt_t B,size_t LE>
		std::string to_string<int_reg_digs_t,UInt_t,B,LE,0>()
		{	return std::string{"int_reg_digs"}; 	}
		template<typename UInt_t,UInt_t B>
		size_t size_of_string_idT<int_reg_digs_t,UInt_t,B,LE,0>()
		{   return (to_string<int_reg_digs_t,UInt_t,B,LE,0>()).size();	}
		/// ESPECIALIZACIONES PARA NAT_RAT_FIXED_REG_T
		template<typename UInt_t,UInt_t B,size_t LE,size_t LF>
		bool is_type_id<nat_rat_fixed_reg_t,UInt_t,B,LE,LF>(std::string in)
		{   return	(
						(in == "nat_rat_fixed_reg")||
						(in == "nat_rat_fixed_re")||
						(in == "nat_rat_fixed_r")||
						(in == "nat_rat_fixed_")||
						(in == "nat_rat_fixed")||
						(in == "nat_rat_fixe")||
						(in == "nat_rat_fix")||
						(in == "nat_rat_fi")||
						(in == "nat_rat_f")||
						(in == "nat_rat_")||
						(in == "nat_rat")||
						(in == "nat_ra")||
						(in == "nat_r")||
						(in == "nat_")||
						(in == "nat")||
						(in == "na")||
						(in == "n")
					);
		}
		template<typename UInt_t,UInt_t B,size_t LE,size_t LF>
		std::string to_string<nat_rat_fixed_reg_t,UInt_t,B,LE,LF>()
		{   return std::string{"nat_rat_fixed_reg"};	}
		template<typename UInt_t,UInt_t B,size_t LE,size_t LF>
		size_t size_of_string_idT<nat_rat_fixed_reg_t,UInt_t,B,LE,LF>()
		{   return (to_string<nat_rat_fixed_reg_t,UInt_t,B,LE,LF>()).size();	}
		/// ESPECIALIZACIONES PARA NAT_RAT_FIXED_REG_T
		template<typename UInt_t,UInt_t B,size_t LE,size_t LF>
		bool is_type_id<rat_fixed_reg_t,UInt_t,B,LE,LF>(std::string in)
		{   return	(
						(in == "rat_fixed_reg")||
						(in == "rat_fixed_re")||
						(in == "rat_fixed_r")||
						(in == "rat_fixed_")||
						(in == "rat_fixed")||
						(in == "rat_fixe")||
						(in == "rat_fix")||
						(in == "rat_fi")||
						(in == "rat_f")||
						(in == "rat_")||
						(in == "rat")||
						(in == "ra")||
						(in == "r")
					);
		}
		template<typename UInt_t,UInt_t B,size_t LE,size_t LF>
		std::string to_string<rat_fixed_reg_t,UInt_t,B,LE,LF>()
		{	return std::string{"rat_fixed_reg"};	}
		template<typename UInt_t,UInt_t B,size_t LE,size_t LF>
		size_t size_of_string_idT<rat_fixed_reg_t,UInt_t,B,LE,LF>()
		{	return (to_string<rat_fixed_reg_t,UInt_t,B,LE,LF>()).size();		}
		/// ESPECIALIZACIONES PARA BASE_NUM_T
		template<typename UInt_t,UInt_t B>
		bool is_type_id<base_num_t,UInt_t,B,0,0>(std::string in)
		{	return	(
						(in == "base_num")||
						(in == "base_nu")||
						(in == "base_n")||
						(in == "base_")||
						(in == "base")||
						(in == "bas")||
						(in == "ba")||
						(in == "b")
					);
		}
		template<typename UInt_t,UInt_t B>
		std::string
		to_string<base_num_t,UInt_t,B,0,0>()
		{	return std::string{"base_num"};	}
		template<typename UInt_t,UInt_t B>
		size_t	size_of_string_idT<base_num_t,UInt_t,B,0,0>()
		{	return (to_string<base_num_t,UInt_t,B,0,0>()).size();	}
		/// ESPECIALIZACIONES PARA NAT_NUM_T
		template<typename UInt_t,UInt_t B>
		bool is_type_id<nat_num_t,UInt_t,B,0,0>(std::string in)
		{	return	(
						(in == "nat_num")||
						(in == "nat_nu")||
						(in == "nat_n")||
						(in == "nat_")||
						(in == "nat")||
						(in == "na")||
						(in == "n")
					);
		}
		template<typename UInt_t,UInt_t B>
		std::string	to_string<nat_num_t,UInt_t,B,0,0>()
		{	return std::string{"nat_num"};	}
		template<typename UInt_t,UInt_t B>
		size_t	size_of_string_idT<nat_num_t,UInt_t,B,0,0>()
		{	return (to_string<nat_num_t,UInt_t,B,0,0>()).size();	}
		/// ESPECIALIZACIONES PARA NAT_NUM_T
		template<typename UInt_t,UInt_t B>
		bool is_type_id<int_num_t,UInt_t,B,0,0>(std::string in)
		{	return	(
						(in == "int_num")||
						(in == "int_nu")||
						(in == "int_n")||
						(in == "int_")||
						(in == "int")||
						(in == "in")||
						(in == "i")
					);
		}
		template<typename UInt_t,UInt_t B>
		std::string	to_string<int_num_t,UInt_t,B,0,0>()
		{	return std::string{"int_num"};	}
		template<typename UInt_t,UInt_t B>
		size_t size_of_string_idT<int_num_t,UInt_t,B,0,0>()
		{	return (to_string<int_num_t,UInt_t,B,0,0>()).size();	}
		/// ESPECIALIZACIONES PARA NAT_RAT_NUM_T
		template<typename UInt_t,UInt_t B>
		bool is_type_id<nat_rat_num_t,UInt_t,B,0,0>(std::string in)
		{	return	(
						(in == "nat_rat_num")||
						(in == "nat_rat_nu")||
						(in == "nat_rat_n")||
						(in == "nat_rat_")||
						(in == "nat_rat")||
						(in == "nat_ra")||
						(in == "nat_r")||
						(in == "nat_")||
						(in == "nat")||
						(in == "na")||
						(in == "n")
					);
		}
		template<typename UInt_t,UInt_t B>
		std::string to_string<nat_rat_num_t,UInt_t,B,0,0>()
		{	return std::string{"nat_rat_num"};	}
		template<typename UInt_t,UInt_t B>
		size_t size_of_string_idT<nat_rat_num_t,UInt_t,B,0,0>()
		{	return (to_string<nat_rat_num_t,UInt_t,B,0,0>()).size();	}
		/// ESPECIALIZACIONES PARA RAT_NUM_T
		template<typename UInt_t,UInt_t B>
		bool is_type_id<rat_num_t,UInt_t,B,0,0>(std::string in)
		{	return	(
						(in == "rat_num")||
						(in == "rat_nu")||
						(in == "rat_n")||
						(in == "rat_")||
						(in == "rat")||
						(in == "ra")||
						(in == "r")
					);
		}
		template<typename UInt_t,UInt_t B>
		std::string	to_string<rat_num_t,UInt_t,B,0,0>()
		{	return std::string{"rat_num"};		}
		template<typename UInt_t,UInt_t B>
		size_t	size_of_string_idT<rat_num_t,UInt_t,B,0,0>()
		{	return (to_string<rat_num_t,UInt_t,B,0,0>()).size();   }
		/// FUNCION QUE CONSIGUE EL TOKEN TYPE PARA LA
		/// OBTENCION DEL OBJETO CORRESPONDIENTE POR TECLADO
		template<template T,typename UIn_t,UIn_t B,size_t LE=0,size_t LF=0>
		void get_type_token(std::istream& is,std::ostream& errs,type& value)
		{
			std::string old_input_string{""};
			std::string new_input_string{""};
			while(true) {
				is >> input_char;
				new_input_string += input_char;
				if (
					is_type_id<T,UInt_t,B,LE,LF>(new_input_string)
				) {
					old_input_string = new_input_string;
					continue;
				}
				else {
					errs << "Has cometido un error, ten?as que\
					 escribir \
					\" " << to_string<T,UInt_t,B,LE,LF>()
					<< " \"  y has escrito "
					<< input_string << std::endl;
					errs << "Considera que has escrito "
					<< old_input_string
					<< " y continua escribiendo a partir de ah?";
					new_input_string = old_input_string;
				}
			}
			if (new_input_string.length()
					==
				to_string<T,UInt_t,B,LE,LF>())
				return true;
			else
				return false;
		}

		/// FUNCION QUE CONSIGUE EL TOKEN PUNTO FIJO
		template<typename UInt_t,UInt_t B>
		void get_type_token(std::istream& is,std::ostream& errs,bool& value)
		{
			std::string old_input_string{""};
			std::string new_input_string{""};
			size_t index{0};
			char input_char = nullchar<char>;
			while(true) {
				is >> input_char;
				if ((index==0)&&(is_separator(input_char))) {
					new_input_string += input_char;
					old_input_string = new_imput_string;
					++index;
				}
				else if (
					(index == 0)&&(! is_separator(input_char))
				) {
					errs << "Has cometido un error, ten?as que\
					 escribir \
					\" " << '#'
					<< " \"  y has escrito "
					<< new_input_string << std::endl;
					errs << "Considera que has escrito "
					<< old_input_string
					<< " y continua escribiendo a partir de ah?";
					new_input_string = old_input_string;
				}
				else if (index==1)&&(input_char == '.') {
					new_input_string += input_char;
					old_input_string = new_imput_string;
					value = true;
					return;
				}
				else{
					errs << "Has cometido un error, tenias que \
					 escribir \
					\" " << "#."
					<< " \"  y has escrito "
					<< new_input_string << std::endl;
					errs << "Considera que has escrito "
					<< old_input_string
					<< " y continua escribiendo a partir de ahi";
					new_input_string = old_input_string;
				}
			}
			if (new_input_string=="#.")
				return true;
			else
				return false;
		}
		/// FUNCION QUE CONSIGUE EL TOKEN PUNTO FIJO
		template<typename UInt_t,UInt_t B>
		void get_explicit_sign_token(std::istream& is,std::ostream& errs,bool& value, sign_e& signo)
		{
			std::string old_input_string{""};
			std::string new_input_string{""};
			size_t index{0};
			char input_char = nullchar<char>;
			while(true) {
				is >> input_char;
				if ((index==0)&&(is_separator(input_char))) {
					new_input_string += input_char;
					old_input_string = new_imput_string;
					++index;
				}
				else if (
					(index == 0)&&(! is_separator(input_char))
				) {
					errs << "Has cometido un error, ten?as que\
					 escribir \
					\" " << '#'
					<< " \"  y has escrito "
					<< new_input_string << std::endl;
					errs << "Considera que has escrito "
					<< old_input_string
					<< " y continua escribiendo a partir de ah?";
					new_input_string = old_input_string;
				}
				else if(
					(index==1)&&
					(
						(input_char == '+')||
						(input_char == '-')
					)
				){
					new_input_string += input_char;
					old_input_string = new_imput_string;
					value = true;
					signo = sign_value(input_char);
					return;
				}
				else{
					errs << "Has cometido un error, tenias que \
					 escribir \
					\" " << "#+ o #-"
					<< " \"  y has escrito "
					<< new_input_string << std::endl;
					errs << "Considera que has escrito "
					<< old_input_string
					<< " y continua escribiendo a partir de ahi";
					new_input_string = old_input_string;
				}
			}
			if( (new_input_string=="#+")||
				(new_input_string=="#-")    )
				return true;
			else
				return false;
		}
		/// FUNCION QUE CONSIGUE EL TOKEN DIGITO
		template<typename UInt_t,UInt_t B>
		void get_explicit_sign_token(std::istream& is,std::ostream& errs,bool& value,UInt_t& uint_value)
		{
			std::string old_input_string{""};
			std::string new_input_string{""};
			size_t index{0};
			char input_char = nullchar<char>;
			uint_value = 0;
			value = false;
			while(true) {
				is >> input_char;
				if ((index==0)&&(is_separator(input_char))) {
					new_input_string += input_char;
					old_input_string = new_imput_string;
					++index;
				}
				else if (
					(index == 0)&&(! is_separator(input_char))
				) {
					errs << "Has cometido un error, tenias que \
					 escribir \
					\" " << '#'
					<< " \"  y has escrito "
					<< new_input_string << std::endl;
					errs << "Considera que has escrito "
					<< old_input_string
					<< " y continua escribiendo a partir de ahi";
					new_input_string = old_input_string;
				}
				else if(
					(index==1)&&
					(	(input_char >= '0')&&
						(input_char <= '9')	    )
				){
					if (digit_value(input_char) < B) {
						new_input_string += input_char;
						uint_value *= B;
						uint_value += sign_value(input_char);
						if (uint_value < B) {
							value = true;
							old_input_string = new_input_string;
						}
						else {
							old_input_string = "#";
								value = false;
							errs << "Has cometido un error, tenias que \
							poner un valor menor que la base y has \
							 puesto \
							\" " << uint_value
							<< " \"  y has escrito "
							<< new_input_string << std::endl;
							errs << "Considera que has escrito "
							<< old_input_string
							<< " y continua escribiendo a partir de ahi";
							index = 1;
						}
					}
				}
				else if(
					(index>1)&&
					(input_char == '_')
				){
					value = true;
					return;
				}
				else{
					errs << "Has cometido un error, tenias que \
					 escribir \
					\" " << "#digdigdig..."
					<< " \"  y has escrito "
					<< new_input_string << std::endl;
					errs << "Considera que has escrito "
					<< old_input_string
					<< " y continua escribiendo a partir de ahi";
					new_input_string = old_input_string;
				}
			}
			if(input_char=='_')
				return true;
			else
				return false;
		}
		/// FUNCION QUE CONSIGUE EL TOKEN BASE
		template<typename UInt_t,UInt_t B>
		void get_explicit_radix_token(std::istream& is,std::ostream& errs,bool& value,UInt_t& uint_radix);
}
#endif // LEXER_PARSER_HPP_INCLUDED
