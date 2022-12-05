// *** ADDED BY HEADER FIXUP ***
#include "istream"
// *** END ***

/*
  A list of valid replacements is as follows:

  Use:					                    Instead of:
  <sstream>, basic_stringbuf	   	        <strstream>, strstreambuf
  <sstream>, basic_istringstream	        <strstream>, istrstream
  <sstream>, basic_ostringstream	        <strstream>, ostrstream
  <sstream>, basic_stringstream		        <strstream>, strstream
  <unordered_set>, unordered_set     	    <ext/hash_set>, hash_set
  <unordered_set>, unordered_multiset	    <ext/hash_set>, hash_multiset
  <unordered_map>, unordered_map	        <ext/hash_map>, hash_map
  <unordered_map>, unordered_multimap	    <ext/hash_map>, hash_multimap
  <functional>, bind			            <functional>, binder1st
  <functional>, bind			            <functional>, binder2nd
  <functional>, bind			            <functional>, bind1st
  <functional>, bind			            <functional>, bind2nd
  <memory>, unique_ptr       		        <memory>, auto_ptr
*/

#ifndef BASIC_TYPES_HPP_INDLUDED
#define BASIC_TYPES_HPP_INDLUDED

#include <cstdint>

#include <type_traits>
#include <optional>
#include <compare>
#include <concepts>

//#include <istream>
//#include <ostream>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
//#include <fmt>

#include <array>
#include <vector>
#include <list>
#include <map>

#include <climits>
#include <numeric>
#include <limits>
#include <cmath>

#include <iterator>
#include <functional>
/// NUEVOS NOMBRES PARA LOS ENTEROS O PARECIDOS
using 		chint 		= char;
using 		schint 		= signed char;
using 		ssint 		= signed short int;
using 		sint 		= signed int;
using 		slint 		= signed long int;
using 		sllint 		= signed long long int;
using 		uchint 		= unsigned char;
using 		usint 		= unsigned short int;
using 		uint 		= unsigned int;
using 		ulint 		= unsigned long int;
using 		ullint 		= unsigned long long int;
using 		uint128_t 	= __uint128_t;
using 		sint128_t 	= __int128_t;
using		size_t 		= std::size_t;
using		sint8_t 	= std::int8_t;
using		sint16_t	= std::int16_t;
using		sint32_t	= std::int32_t;
using		sint64_t	= std::int64_t;
using		int8_t 	= std::int8_t;
using		int16_t	= std::int16_t;
using		int32_t	= std::int32_t;
using		int64_t	= std::int64_t;
//using		ssize_t 	= std::ssize_t;
using		uint8_t 	= std::uint8_t;
using		uint16_t 	= std::uint16_t;
using		uint32_t 	= std::uint32_t;
using		uint64_t 	= std::uint64_t;
//using		uchint8		= std::char8_t;
//using		uchint16	= std::char16_t;
//using		uchint32	= std::char32_t;

namespace NumRepr {

/// TYPE_TRAITS AND CONCEPTS
template<typename IntT>
concept arith_integral_c = 	std::is_arithmetic_v<IntT>	&&
                            std::is_integral_v<IntT>;

template<typename NatIntT>
concept arith_natural_c =   std::is_arithmetic_v<NatIntT>   &&
						    std::is_unsigned_v<NatIntT>     &&
							std::is_integral_v<NatIntT>;

template<typename CharT>
concept char_type = std::is_same_v<CharT,char> 						||
										std::is_same_v<CharT,signed char> 		||
										std::is_same_v<CharT,unsigned char> 	||
										std::is_same_v<CharT,wchar_t>;

template<typename CharT>
constexpr inline
CharT  nullchar {CharT('\0')};

char* clear_ccad(char *,usint);

template< template<uchint B> class T  , uchint B >
inline constexpr
const char* devCadenaC(T<B> arg,std::size_t long_ccad = 64) noexcept {
	char* c_cad = new char[long_ccad];
	c_cad = clear_ccad(c_cad,long_ccad);
	std::stringstream pre_cad;
	pre_cad << arg;
	std::string cad(pre_cad.str());
	const size_t longitud = cad.length();
	for(size_t i=0;i<longitud;++i) {
		c_cad[i] = cad[i];
	}
	for(size_t i=longitud;i<long_ccad;++i) {
		c_cad[i] = nullchar<char>;
	}
	return c_cad;
}

inline constexpr
char* clear_ccad(char * cad_c,std::size_t long_de_cad_c) noexcept {
	for( size_t I=0 ; I < long_de_cad_c ; ++I )
		cad_c[I]=nullchar<char>;
	return cad_c;
}

inline constexpr
unsigned long long atoull(char* text) noexcept {
		int i=0;
		while(*text)
		{
			i=(i<<3) + (i<<1) + (*text - '0');
			++text;
		}
		return(i);
}

namespace type_traits {
///            "CLASS"              TYPE                   TYPE DEFINITION
/// template<typename              int_type,int_type base> class digito<int_type,base> {};
///            CONCEPT              TYPE                   TYPE DEFINITION
/// template<allowable_base_type_c int_type,int_type base> class digito<int_type,base> {};

	template<typename UINT_T>
	concept allowable_base_type_c =         // concept on UINT_T for BASE
			std::is_same_v<UINT_T,uint8_t>	||
			std::is_same_v<UINT_T,uint16_t>	||
			std::is_same_v<UINT_T,uint32_t>	||
			std::is_same_v<UINT_T,uint64_t>;

  template<typename UINT_T>
	concept allowable_unsigned_type_c =         // concept on UINT_T
			std::is_same_v<UINT_T,uint8_t>	||
			std::is_same_v<UINT_T,uint16_t>	||
			std::is_same_v<UINT_T,uint32_t>	||
			std::is_same_v<UINT_T,uint64_t> ||
			std::is_same_v<UINT_T,uint128_t>;

	template<typename UINT_T>
	concept unsigned_integral_c = allowable_unsigned_type_c<UINT_T>;

	template<typename SINT_T>
	concept allowable_signed_type_c =       // concept on SINT_T
			std::is_same_v<SINT_T,sint8_t>      ||
			std::is_same_v<SINT_T,sint16_t>	    ||
			std::is_same_v<SINT_T,sint32_t>	    ||
			std::is_same_v<SINT_T,sint64_t>	    ||
			std::is_same_v<SINT_T,schint>		||
			std::is_same_v<SINT_T,chint>		||
			std::is_same_v<SINT_T,ssint>		||
			std::is_same_v<SINT_T,sint>			||
			std::is_same_v<SINT_T,slint>		||
			std::is_same_v<SINT_T,sllint>		||
			std::is_same_v<SINT_T,sint128_t>	;

	template<typename SINT_T>
	concept signed_integral_c = allowable_signed_type_c<SINT_T>;

	template<typename INT_T>
	concept integral_c = signed_integral_c<INT_T> || unsigned_integral_c<INT_T>;

	template<typename T,typename S>
	constexpr bool has_the_same_size = (sizeof(T)==sizeof(S));

	template<unsigned_integral_c T,unsigned_integral_c S>
	struct is_unsigned_sz_gt {
		static inline constexpr bool value = ((sizeof(T) > sizeof(S))?true:false);
	};

	template<unsigned_integral_c T,unsigned_integral_c S>
	constexpr bool is_unsigned_sz_gt_v = is_unsigned_sz_gt<T,S>::value;

	template<unsigned_integral_c T,unsigned_integral_c S>
	constexpr bool is_unsigned_sz_geqt_v	=	(is_unsigned_sz_gt_v<T,S> || std::is_same_v<T,S>);

	template<signed_integral_c T,unsigned_integral_c S>
	struct is_signed_sz_gt {
		static inline constexpr bool value = ((sizeof(T)>sizeof(S)+1)?true:false);
	};

	template<signed_integral_c T,signed_integral_c S>
	constexpr bool is_signed_sz_gt_v = is_signed_sz_gt<T,S>::value;

	template<signed_integral_c T,unsigned_integral_c S>
	constexpr bool is_signed_sz_geqt_v	=	is_signed_sz_gt_v<T,S>
											||
											std::is_same_v<T,S>;

	template<integral_c T,unsigned_integral_c S>
	constexpr bool is_int_unsig_sz_gt_v		=   is_signed_sz_gt_v<T,S>
										||
										is_unsigned_sz_gt_v<T,S>;
	template<integral_c T,unsigned_integral_c S>
	constexpr bool is_int_unsig_sz_geqt_v	    =	is_signed_sz_geqt_v<T,S>
										||
										is_unsigned_sz_geqt_v<T,S>;

	template<unsigned_integral_c T,integral_c S>
	constexpr bool is_unsig_int_sz_gt_v		=   is_signed_sz_gt_v<T,S>
										||
										is_unsigned_sz_gt_v<T,S>;
	template<unsigned_integral_c T,integral_c S>
	constexpr bool is_unsig_int_sz_geqt_v	    =	is_signed_sz_geqt_v<T,S>
										||
										is_unsigned_sz_geqt_v<T,S>;

	///<  METAFUNCION : DA EL SIGUIENTE TIPO NATURAL PARA EL ACTUAL TIPO NATURAL
	///<  POR ESPECIALIZACION EXPLICITA
	namespace detail {
		template<unsigned_integral_c UInt_t>
		struct __sig_UInt_for_UInt_t {using type = void;};

		template<>
		struct __sig_UInt_for_UInt_t<uint8_t>
		{using type = uint16_t;};

		template<>
		struct __sig_UInt_for_UInt_t<uint16_t>
		{using type = uint32_t;};

		template<>
		struct __sig_UInt_for_UInt_t<uint32_t>
		{using type = uint64_t;};

		template<>
		struct __sig_UInt_for_UInt_t<uint64_t>
		{using type = uint128_t;};
	}
	template<unsigned_integral_c UInt_t>
	using sig_UInt_for_UInt_t = typename detail::__sig_UInt_for_UInt_t<UInt_t>::type;
	/// sig_UInt_for_UInt_t<unsigned char> devuelve el tipo unsigned short;
	/// sig_UInt_for_UInt_t<unsigned short> devuelve el tipo unsigned long;
	/// sig_UInt_for_UInt_t<unsigned long> devuelve el tipo unsigned long long;
	/// sig_UInt_for_UInt_t<unsigned long long> devuelve el tipo uint128_t;
	/// sig_UInt_for_UInt_t<uint128_t> devuelve el tipo void;

	///<  METAFUNCION : DA EL SIGUIENTE TIPO ENTERO PARA EL ACTUAL TIPO NATURAL
	///<  POR ESPECIALIZACION EXPLICITA
	namespace detail {
		template<unsigned_integral_c UInt>
		struct __sig_SInt_for_UInt_t
		{using type = void;};

		template<>
		struct __sig_SInt_for_UInt_t<uint8_t>
		{using type = int16_t;};

		template<>
		struct __sig_SInt_for_UInt_t<uint16_t>
		{using type = int32_t;};

		template<>
		struct __sig_SInt_for_UInt_t<uint32_t>
		{using type = int64_t;};

		template<>
		struct __sig_SInt_for_UInt_t<uint64_t>
		{using type = sint128_t;};
	}

	template<unsigned_integral_c UInt_t>
	using sig_SInt_for_UInt_t = typename detail::__sig_SInt_for_UInt_t<UInt_t>::type;
	/// sig_SInt_for_UInt_t<unsigned char> devuelve el tipo short;
	/// sig_SInt_for_UInt_t<unsigned short> devuelve el tipo long;
	/// sig_SInt_for_UInt_t<unsigned long> devuelve el tipo long long;
	/// sig_SInt_for_UInt_t<unsigned long long> devuelve el tipo int128_t;
	/// sig_SInt_for_UInt_t<uint128_t> devuelve el tipo void;

	///<  METAFUNCION : DA EL SIGUIENTE TIPO NATURAL PARA EL ACTUAL TIPO ENTERO
	///<  POR ESPCEIALIZACION EXPLICITA
	namespace detail{
		template<integral_c SInt>
		struct __sig_UInt_for_SInt_t
		{using type = void;};

		template<>
		struct __sig_UInt_for_SInt_t<int8_t>
		{using type = uint8_t;};

		template<>
		struct __sig_UInt_for_SInt_t<int16_t>
		{using type = uint16_t;};

		template<>
		struct __sig_UInt_for_SInt_t<int32_t>
		{using type = uint32_t;};

		template<>
		struct __sig_UInt_for_SInt_t<int64_t>
		{using type = uint64_t;};

		template<>
		struct __sig_UInt_for_SInt_t<sint128_t>
		{using type = uint128_t;};

		template<>
		struct __sig_UInt_for_SInt_t<uint8_t>
		{using type = uint8_t;};

		template<>
		struct __sig_UInt_for_SInt_t<uint16_t>
		{using type = uint16_t;};

		template<>
		struct __sig_UInt_for_SInt_t<uint32_t>
		{using type = uint32_t;};

		template<>
		struct __sig_UInt_for_SInt_t<uint64_t>
		{using type = uint64_t;};

		template<>
		struct __sig_UInt_for_SInt_t<uint128_t>
		{using type = uint128_t;};
	}

	template<integral_c SInt_t>
	using sig_UInt_for_SInt_t = typename detail::__sig_UInt_for_SInt_t<SInt_t>::type;

	///<  METAFUNCION : DA EL SIGUIENTE TIPO ENTERO PARA EL ACTUAL TIPO ENTERO
	///<  POR ESPCECIALIZACION EXPLICITA
	namespace detail {
		template<signed_integral_c SInt>
		struct __sig_SInt_for_SInt_t
		{using type = void;};

		template<>
		struct __sig_SInt_for_SInt_t<int8_t>
		{using type = int16_t;};

		template<>
		struct __sig_SInt_for_SInt_t<int16_t>
		{using type = int32_t;};

		template<>
		struct __sig_SInt_for_SInt_t<int32_t>
		{using type = int64_t;};

		template<>
		struct __sig_SInt_for_SInt_t<int64_t>
		{using type = sint128_t;};
	}

	template<signed_integral_c SInt_t>
	using sig_SInt_for_SInt_t = typename detail::__sig_SInt_for_SInt_t<SInt_t>::type;

	///< METAFUNCIONES PARA DAR CON LOS MAXIMOS NUMEROS QUE CABEN EN UN TIPO
	///< Y SIMILARES
	template<typename UINT_T>
	consteval UINT_T maxbase() {
		return (static_cast<UINT_T>(std::numeric_limits<UINT_T>::max()));
	}

	template<typename UINT_T>
	consteval UINT_T submaxbase() {
		return static_cast<UINT_T>(maxbase<UINT_T>()-1);
	}

	template<typename UINT_T>
	consteval UINT_T minbase() {
		return static_cast<UINT_T>(2);
	}

	template<typename UINT_T>
	consteval UINT_T subminbase() {
		return static_cast<UINT_T>(3);
	}

	template<typename UINT_T>
	consteval UINT_T monobase() {
		return static_cast<UINT_T>(1);
	}

	template<typename UINT_T>
	consteval UINT_T nobase() {
		return static_cast<UINT_T>(0);
	}

	template<typename UINT_T>
	consteval UINT_T maxdigit() {
		return static_cast<UINT_T>(submaxbase<UINT_T>());
	}

	template<typename UINT_T>
	consteval UINT_T submaxdigit() {
		return static_cast<UINT_T>(submaxbase<UINT_T>()-1);
	}

	template<typename UINT_T>
	consteval UINT_T digit_0() {
		return static_cast<UINT_T>(0u);
	}

	template<typename UINT_T>
	consteval UINT_T digit_1() {
		return static_cast<UINT_T>(1u);
	}

	template<typename UINT_T>
	consteval UINT_T base_2() {
		return static_cast<UINT_T>(2u);
	}

  template<typename UINT_T,UINT_T B>
	consteval bool base_geqt_2() {
		return (B >= base_2<UINT_T>());
	}

	template<typename UINT_T,UINT_T B>
	consteval bool base_leqt_max() {
		return (B <= maxbase<UINT_T>());
	}

	template<typename UINT_T,UINT_T B>
	consteval bool suitable_base() { // requires on B
		return (base_geqt_2<UINT_T,B>() && base_leqt_max<UINT_T,B>());
	}

	template<typename UINT_T>
	consteval UINT_T middle_max() {
		using SIG_UINT_T = sig_UInt_for_UInt_t<UINT_T>;
		constexpr SIG_UINT_T maximo = maxbase<UINT_T>();
		constexpr SIG_UINT_T uno{1};
		constexpr SIG_UINT_T dos{2};
		return	static_cast<UINT_T>((maximo+uno)/dos);
	}

	template<typename UINT_T>
	consteval UINT_T sqrt_max() {
		using SIG_UINT_T = sig_UInt_for_UInt_t<UINT_T>;
		constexpr SIG_UINT_T maximo{maxbase<UINT_T>()};
		constexpr SIG_UINT_T uno{1};
		constexpr SIG_UINT_T base{maximo+uno};
		constexpr long double raiz_real{std::sqrt(base)};
		return	static_cast<UINT_T>(std::floor(raiz_real));
	}

	///< QUEREMOS FABRICAR LA METAFUNCION TypeFromIntNumber_t<numero_sin_signo>
	///< QUE DEVUELVA EL TIPO ENTERO SIN SIGNO MAS PEQUENO PARA EL NUMERO numero_sin_signo

		///< DECLARACION DE UN TYPE_TRAITS PARA LITERALES INTEGRALES NOVALIDOS
		struct empty_type{};
		///< DECLARACION DE UN TYPE_TRAITS PARA LITERALES INTEGRALES SIN DEFINCION
		template<typename Type,Type Radix>
		struct UIntTypeForRadix{
			static constexpr 	uint128_t		uint_value_max 	    = maxbase<uint128_t>();
			static constexpr 	uint128_t		uint_value 			= static_cast<uint128_t>(Radix);
			static constexpr 	bool			bool_value 			=   (Radix <= uint_value_max) &&
																	    (Radix > 1) 			  &&
																		std::is_integral_v<Type>   ;
			using  				actUIntType			                =   std::conditional_t<
																			bool_value,
																				uint128_t,
																				empty_type
																		>;
			static constexpr 	actUIntType     act_uint_value 	    = ( bool_value ? uint_value : 0 );
			using 				UIntType 							=
																	std::conditional_t<
																		bool_value,
																	    typename
																			UIntTypeForRadix<
																				uint128_t,
																				uint_value
																			>::UIntType,
																		   empty_type
                                  >;
		};
		///< FUNCION TYPE_TRAITS DE AYUDA PARA TYPE_TRAITS::UINTTYPEFORRADIX
		template<integral_c Type,Type Radix>
			requires (Radix > 1)
		using UIntTypeForRadix_t = typename UIntTypeForRadix<Type,Radix>::UIntType;
		///< DEFINICION PARA ESPECIALIZACION TYPE_TRAITS::UINTTYPEFORRADIX UNSIGNED
		///< POSIBLY RADIX NON VALID
		template<uint128_t Radix>
			requires (Radix > 1)
		struct UIntTypeForRadix<uint128_t, Radix> {
			static constexpr 	uint128_t				uint_value_max 	    = maxbase<uint64_t>();
			static constexpr 	uint128_t				uint_value 			= static_cast<uint64_t>(Radix);
			static constexpr 	uint64_t			uint_value_sig		= static_cast<uint64_t>(Radix);
			static constexpr 	bool					bool_value 			= (Radix <= uint_value_max);
			using  				actUIntType 			                    = std::conditional_t<
																			    bool_value,
																				    uint64_t ,
																					empty_type
																			>;
			static constexpr 	actUIntType 			act_uint_value 		= ( bool_value ? uint_value_sig : 0 );
			using 				UIntType 				                    = std::conditional_t<
                                                                                    bool_value,
																					    UIntTypeForRadix_t<
                                                                                            uint64_t,
																							uint_value
																						>,
																						empty_type
                                                                              >;
		};
		///< DEFINICION PARA ESPECIALIZACION TYPE_TRAITS::UINTTYPEFORRADIX SIGNED
		///< POSIBLY RADIX NON VALID
		template<sint128_t Radix>
			requires (Radix > 1)
		struct UIntTypeForRadix<uint128_t, Radix> {
			static constexpr 	uint128_t				uint_value_max 	    = maxbase<int64_t>();
			static constexpr 	uint128_t				uint_value 			= static_cast<uint64_t>(Radix);
			static constexpr 	uint64_t			uint_value_sig		= static_cast<uint64_t>(Radix);
			static constexpr 	bool					bool_value 			= (Radix <= uint_value_max);
			using  				actUIntType 			                    = std::conditional_t<
																			        bool_value,
																					    uint64_t,
																						empty_type
																			>;
			static constexpr 	actUIntType 			act_uint_value 		= ( bool_value ? uint_value_sig : 0 );
			using 				UIntType				                    = std::conditional_t<
																				  bool_value,
																					UIntTypeForRadix_t<
																					    uint64_t,
																						uint_value
                                                                                    >,
																					empty_type
																			>;
		};
		///< DEFINICION PARA ESPECIALIZACION TYPE_TRAITS::UINTTYPEFORRADIX UNSIGNED
		///< RADIX VALID
		template<uint64_t Radix>
			requires (Radix > 1)
		struct UIntTypeForRadix<uint64_t, Radix> {
			static constexpr 	uint64_t		uint_value_max 	    = maxbase<uint32_t>();
			static constexpr 	uint64_t		uint_value 			= static_cast<uint64_t>(Radix);
			static constexpr 	uint32_t		uint_value_sig		= static_cast<uint32_t>(Radix);
			static constexpr 	bool			bool_value 			= (Radix <= uint_value_max);
			using  				actUIntType 		                = std::conditional_t<
																		bool_value,
												    					    uint32_t,
																			uint64_t
																	>;
			static constexpr 	actUIntType 	act_uint_value 		= ( bool_value ? uint_value_sig : uint_value );
			using 				UIntType 			                = std::conditional_t<
																		bool_value,
																	    	UIntTypeForRadix_t<
																				uint32_t,
																				uint_value
																			>,
																			uint64_t
																	>;
		};
		///< DEFINICION PARA ESPECIALIZACION TYPE_TRAITS::UINTTYPEFORRADIX SIGNED
		///< RADIX VALID
		template<std::int64_t Radix>
			requires (Radix > 1)
		struct UIntTypeForRadix<int64_t, Radix> {
			static constexpr 	uint64_t		uint_value_max 	    = maxbase<uint32_t>();
			static constexpr 	uint64_t		uint_value 			= static_cast<uint64_t>(Radix);
			static constexpr 	uint32_t		uint_value_sig		= static_cast<uint32_t>(Radix);
			static constexpr 	bool			bool_value 			= (Radix <= uint_value_max);
			using  				actUIntType 			            = std::conditional_t<
																		bool_value,
																			uint32_t,
																			uint64_t
																	>;
			static constexpr 	actUIntType 	act_uint_value 		= ( bool_value ? uint_value_sig : uint_value );
			using 				UIntType 				            = std::conditional_t<
																		bool_value,
																	    	UIntTypeForRadix_t<
																				uint32_t,
																				uint_value
																			>,
																			uint64_t
																	>;
		};
		///< DEFINICION PARA ESPECIALIZACION TYPE_TRAITS::UINTTYPEFORRADIX UNSIGNED
		///< RADIX VALID
		template<uint32_t Radix>
			requires (Radix > 1)
		struct UIntTypeForRadix<uint32_t, Radix> {
			static constexpr 	uint32_t		uint_value_max  	= maxbase<uint16_t>();
			static constexpr 	uint32_t		uint_value 			= static_cast<uint16_t>(Radix);
			static constexpr 	std::uint16_t	uint_value_sig		= static_cast<uint16_t>(Radix);
			static constexpr 	bool			bool_value 			= (Radix <= uint_value_max);
			using  				actUIntType 			            = std::conditional_t	<
																			bool_value,
																				uint16_t,
																				uint32_t
																	>;
			static constexpr 	actUIntType 	act_uint_value 		= ( bool_value ? uint_value_sig : uint_value );
			using 				UIntType 							= std::conditional_t<
																			bool_value,
																				UIntTypeForRadix_t<
																					uint16_t,
																					uint_value
																				>,
																			uint32_t
                                                                       >;
		};
		///< DEFINICION PARA ESPECIALIZACION TYPE_TRAITS::UINTTYPEFORRADIX SIGNED
		///< RADIX VALID
		template<sint32_t Radix>
			requires (Radix > 1)
		struct UIntTypeForRadix<sint32_t, Radix> {
			static constexpr 	uint32_t		uint_value_max 	    = maxbase<uint16_t>();
			static constexpr 	uint32_t		uint_value 			= static_cast<uint16_t>(Radix);
			static constexpr 	uint16_t		uint_value_sig		= static_cast<uint16_t>(Radix);
			static constexpr 	bool			bool_value 			= (Radix <= uint_value_max);
			using  				actUIntType 			            = std::conditional_t	<
																			bool_value,
																				uint16_t,
																				uint32_t
																	>;
			static constexpr 	actUIntType 	act_uint_value 		= ( bool_value ? uint_value_sig : uint_value );
			using 				UIntType 				            = std::conditional_t<
																		bool_value,
																			UIntTypeForRadix_t<
																				uint16_t,
																				uint_value
																			>,
																			uint32_t
																	>;
		};
		///< DEFINICION PARA ESPECIALIZACION TYPE_TRAITS::UINTTYPEFORRADIX UNSIGNED
		///< RADIX VALID
		template<uint16_t Radix>
			requires (Radix > 1)
		struct UIntTypeForRadix<uint16_t, Radix> {
			static constexpr 	uint16_t		uint_value_max 	    = maxbase<uint8_t>();
			static constexpr 	uint16_t		uint_value 			= static_cast<uint8_t>(Radix);
			static constexpr 	uint8_t		    uint_value_sig		= static_cast<uint8_t>(Radix);
			static constexpr 	bool			bool_value 			= (Radix <= uint_value_max);
			using  				actUIntType 			            = std::conditional_t	<
																			bool_value,
																				uint8_t,
																				uint16_t
																	>;
			static constexpr 	actUIntType 	act_uint_value 		= ( bool_value ? uint_value_sig : uint_value );
			using 				UIntType 				            = std::conditional_t<
																	    	bool_value,
																				UIntTypeForRadix_t<
																					uint8_t,
																					uint_value
																		    	>,
																			uint16_t
																		>;
		};
		///< DEFINICION PARA ESPECIALIZACION TYPE_TRAITS::UINTTYPEFORRADIX SIGNED
		///< RADIX VALID
		template<sint16_t Radix>
			requires (Radix > 1)
		struct UIntTypeForRadix<sint16_t, Radix> {
			static constexpr 	uint16_t		uint_value_max 	    = maxbase<uint8_t>();
			static constexpr 	uint16_t		uint_value 			= static_cast<uint8_t>(Radix);
			static constexpr 	uint8_t		    uint_value_sig		= static_cast<uint8_t>(Radix);
			static constexpr 	bool			bool_value 			= (Radix <= uint_value_max);
			using  				actUIntType 			            = std::conditional_t<
                                                                            bool_value,
																			    uint8_t,
																				uint16_t
																	>;
			static constexpr 	actUIntType 	act_uint_value 		= ( bool_value ? uint_value_sig : uint_value );
			using 				UIntType 		= std::conditional_t<
														bool_value,
														    UIntTypeForRadix_t<
																uint8_t,
																uint_value
															>,
															uint16_t
													>;
		};
		///< DEFINICION PARA ESPECIALIZACION TYPE_TRAITS::UINTTYPEFORRADIX UNSIGNED
		///< RADIX VALID FINAL
		template<uint8_t Radix>
			requires (Radix > 1)
		struct UIntTypeForRadix<uint8_t, Radix> {
			static constexpr 	uint8_t		uint_value_max 	    = maxbase<uint8_t>();
			static constexpr 	uint8_t		uint_value 			= static_cast<uint8_t>(Radix);
			static constexpr 	bool		bool_value 			= true;
			using 				UIntType 				        = uint8_t;
		};
		///< DEFINICION PARA ESPECIALIZACION TYPE_TRAITS::UINTTYPEFORRADIX SIGNED
		///< RADIX VALID FINAL
		template<sint8_t Radix>
			requires (Radix > 1)
		struct UIntTypeForRadix<sint8_t, Radix> {
			static constexpr 	uint8_t		uint_value_max 	    = maxbase<uint8_t>();
			static constexpr 	uint8_t		uint_value 			= static_cast<uint8_t>(Radix);
			static constexpr 	bool		bool_value 			= true;
			using 				UIntType 				        = uint8_t;
		};
	///< DEFINICION PARA LLAMAR A TYPE_TRAITS::UINTTYPEFORRADIX
	///< CON SOLO RADIX
	///< DEVUELVE EL TIPO MAS PEQUENO PARA EL NUMERO SIN SIGNO ENTERO QUE LE
	///< PASAMOS EN TIEMPO DE COMPILACION
	template<uint128_t Radix>
	using TypeFromIntNumber_t = UIntTypeForRadix_t<decltype(Radix),Radix>;
}

///< CONCATENACION DE ARRAYS HOMOGENEOS
///< DEFINICION GENERAL PARA 3+* ARRAYS DE LONGITUDES n_head Y n_tail_head Y ... n_tail_tail
template<
		typename T_head		,  typename T_tail_head		,   typename ... T_tail_tail  ,
		std::size_t n_head		,  std::size_t n_tail_head		,	std::size_t ... n_tail_tail
>
	requires (
		((n_head > 0) && (n_tail_head > 0) && ( ... && (n_tail_tail > 0)))
		&&
		(std::is_same_v<T_head,T_tail_head> && ( ... && (std::is_same_v<T_tail_head,T_tail_tail>)))
	)
static inline constexpr
std::array<T_head,n_head+n_tail_head+(...+(n_tail_tail))>&&
concatenate_arrays(
	std::array<T_head       ,n_head      	>&& arg_head,
	std::array<T_tail_head	,n_tail_head	>&& arg_tail_head,
	std::array<T_tail_tail  ,n_tail_tail  >&&  ...   arg_tail_tail
) noexcept {
	return std::move(
			concatenate_arrays< T_head ,T_tail_tail ... , n_head+n_tail_head , n_tail_tail ... >(
				concatenate_arrays< T_head , T_tail_head , n_head , n_tail_head >( arg_head , arg_tail_head ),
				arg_tail_tail ...
		)
	);
}

///< CONCATENACION DE ARRAYS HOMOGENEOS
///< DEFINICION PARA 2 ARRAYS DE LONGITUDES T_1 Y T_0
template< typename T_1 , typename T_0 , std::size_t n_1 , std::size_t n_0 >
	requires ((n_1 > 0)&&(n_0 > 0)&&(std::is_same_v<T_1,T_0>))
static inline constexpr
std::array<T_0,n_1+n_0>&&
concatenate_arrays(std::array<T_1,n_1>&& arg_l,std::array<T_0,n_0>&& arg_r)
noexcept {
	std::array<T_0,n_1+n_0> ret;
	for(std::size_t idx{0} ; idx < n_0 ; ++idx)
		ret[idx] = std::move(arg_r[idx]);
	for(std::size_t idx{n_0} ; idx < n_1+n_0 ; ++idx)
		ret[idx] = std::move(arg_l[idx-n_0]);
	return std::move(ret);
}

}
#endif // BASIC_TYPES_HPP_INCLUDED
