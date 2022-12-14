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

#include <cinttypes>

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
//#include <fmt/format.h>

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

namespace NumRepr {
/// NUEVOS NOMBRES PARA LOS ENTEROS O PARECIDOS
using 	chint_t 		= char;
using 	schint_t 		= signed char;
using 	ssint_t 		= signed short int;
using 	sint_t      = signed int;
using 	slint_t     = signed long int;
using 	sllint_t 		= signed long long int;
using 	uchint_t 		= unsigned char;
using 	usint_t 		= unsigned short int;
using 	uint_t 		  = unsigned int;
using 	ulint_t 		= unsigned long int;
using 	ullint_t 		= unsigned long long int;
using 	uint128_t 	= __uint128_t;
using 	sint128_t 	= __int128_t;
using		size_t 			= std::size_t;
using		sint8_t 		= std::int8_t;
using		sint16_t		= std::int16_t;
using		sint32_t		= std::int32_t;
using		sint64_t		= std::int64_t;
using		int8_t 			= std::int8_t;
using		int16_t			= std::int16_t;
using		int32_t			= std::int32_t;
using		int64_t			= std::int64_t;
using   fast8_t 		= std::int_fast8_t;
using   fast16_t 		= std::int_fast16_t;
using   fast32_t 		= std::int_fast32_t;
using   fast64_t 		= std::int_fast64_t;
using   least8_t 		= std::int_least8_t;
using   least16_t 	= std::int_least16_t;
using   least32_t 	= std::int_least32_t;
using   least64_t 	= std::int_least64_t;
//using		ssize_t 	= std::ssize_t;
using		uint8_t 		= std::uint8_t;
using		uint16_t 		= std::uint16_t;
using		uint32_t 		= std::uint32_t;
using		uint64_t 		= std::uint64_t;
using   ufast8_t 		= std::uint_fast8_t;
using   ufast16_t 	= std::uint_fast16_t;
using   ufast32_t 	= std::uint_fast32_t;
using   ufast64_t 	= std::uint_fast64_t;
using   uleast8_t 	= std::uint_least8_t;
using   uleast16_t 	= std::uint_least16_t;
using   uleast32_t 	= std::uint_least32_t;
using   uleast64_t 	= std::uint_least64_t;
//using		uchint8		= std::char8_t;
//using		uchint16	= std::char16_t;
//using		uchint32	= std::char32_t;
using		intmax_t		= std::intmax_t;
using		uintmax_t		= std::uintmax_t;

namespace type_traits {
/// TYPE_TRAITS AND CONCEPTS
template<typename IntT>
concept arith_integral_c = 	std::is_arithmetic_v<IntT>	&&
                            std::is_integral_v<IntT>;

template<typename NatIntT>
concept arith_natural_c =   std::is_arithmetic_v<NatIntT>   &&
														std::is_unsigned_v<NatIntT>     &&
														std::is_integral_v<NatIntT>;

template<typename CharT>
concept char_type_c = std::is_same_v<CharT,char> 						||
											std::is_same_v<CharT,signed char> 		||
											std::is_same_v<CharT,unsigned char> 	||
											std::is_same_v<CharT,wchar_t>;

template<char_type_c CharT>
constexpr inline
CharT  nullchar {CharT('\0')};

char* clear_ccad(char *,usint_t);

template< template<uchint_t B> class T  , uchint_t B >
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

///            "CLASS"              TYPE                   TYPE DEFINITION
/// template<typename              int_type,int_type base> class digito<int_type,base> {};
///            CONCEPT              TYPE                   TYPE DEFINITION
/// template<allowable_base_type_c int_type,int_type base> class digito<int_type,base> {};

	/// METAOPERADOR QUE NOS DA LA ADECUACION DE UN TIPO PARA SER BASE DE UN SISTEMA DE NUMERACION
	/// VALE CUALQUIER TIPO UNSIGNED INTEGRAL QUE NO SEA EL MAYOR CONSIDERADO
	/// AQUI EL MAYOR CONSIDERADO ES UINT128_T
	template<typename UINT_T>	// variable on compile time for concept on UINT_T for BASE
	constexpr bool is_uint_type_for_radix_v = std::is_unsigned_v<UINT_T> && (! std::is_same_v<UINT_T,uint128_t>);
		/// CONCEPT FOR UNSIGNED INTEGRAL TYPES VALID FOR THE RADIX
	template<typename UINT_T>
	concept uint_type_for_radix_c = is_uint_type_for_radix_v<UINT_T>;

	/// METAOPERADOR QUE NOS DA SI UN TIPO INTEGRAL ES UNSIGNED
	/// VALEN LOS QUE VALEN PARA RADIX MAS LOS TIPO MAS GRANDES
	/// POR LO TANTO UINT128_T SE CONSIDERA UN UNSIGNED INTEGRAL TYPE
  template<typename UINT_T> // variable on compile time for concept on UINT_T
	constexpr bool is_unsigned_type_v =
			is_uint_type_for_radix_v<UINT_T>	|| std::is_same_v<UINT_T,uint128_t>;
		/// CONCEPT FOR UNSIGNED INTEGRAL TYPES
	template<typename UINT_T>
	concept unsigned_integral_c = is_unsigned_type_v<UINT_T>;

	/// METAOPERADOR QUE NOS DA SI UN TIPO INTEGRAL ES SIGNED
	template<typename SINT_T> // concept on SINT_T
	constexpr bool is_signed_type_v = std::is_signed_v<SINT_T>;
		/// CONCEPT FOR SIGNED INTEGRAL TYPES
	template<typename SINT_T>
	concept signed_integral_c = is_signed_type_v<SINT_T>;

	/// METAOPERADOR QUE NOS DA SI UN TIPO ES INTEGRAL
	template<typename INT_TYPE>
	inline constexpr bool is_integral_type_v = std::is_integral_v<INT_TYPE>;

	template<typename INT_T>
	concept integral_c = is_integral_type_v<INT_T>;

	/// METAOPERADORES DE COMPARACION DE CAPACIDAD DE INTEGERS
	template<typename T,typename S>
	constexpr bool eq_sz_v = (sizeof(T) == sizeof(S));
	template<typename T,typename S>
	constexpr bool gt_sz_v = (sizeof(T) > sizeof(S));
	template<typename T,typename S>
	constexpr bool lt_sz_v = (sizeof(T) < sizeof(S));
	template<typename T,typename S>
	constexpr bool ge_sz_v = gt_sz_v<T,S>||eq_sz_v<T,S>;
	template<typename T,typename S>
	constexpr bool le_sz_v = lt_sz_v<T,S>||eq_sz_v<T,S>;

	///<  METAFUNCION : DA EL SIGUIENTE TIPO NATURAL PARA EL ACTUAL TIPO NATURAL
	///<  POR ESPECIALIZACION EXPLICITA
	namespace ugly_details_UInt_for_UInt {
		template<unsigned_integral_c UInt_t>
		struct __sig_UInt_for_UInt_t {using type = void;};

		template<>
		struct __sig_UInt_for_UInt_t<ullint_t>
		{	using type = uint128_t;};

		template<>
		struct __sig_UInt_for_UInt_t<ulint_t>
		{
			template<unsigned_integral_c uint_type>
			static inline constexpr bool uint_type_gt_this_type_v = gt_sz_v<uint_type,ulint_t>;

			using type =
				typename
				std::conditional_t<
					uint_type_gt_this_type_v<ullint_t>,
						ullint_t,
						typename __sig_UInt_for_UInt_t<ullint_t>::type
				>;
		};

		template<>
		struct __sig_UInt_for_UInt_t<uint_t>
		{
			template<unsigned_integral_c uint_type>
			static inline constexpr bool uint_type_gt_this_type_v = gt_sz_v<uint_type,uint_t>;

			using type =
				std::conditional_t<
					uint_type_gt_this_type_v<ulint_t>,
						ulint_t,
						typename __sig_UInt_for_UInt_t<ulint_t>::type
				>;
		};

		template<>
		struct __sig_UInt_for_UInt_t<usint_t>
		{
			template<unsigned_integral_c uint_type>
			static inline constexpr bool uint_type_gt_this_type_v = gt_sz_v<uint_type,usint_t>;

			using type =
				std::conditional_t<
					uint_type_gt_this_type_v<uint_t>,
						uint_t,
						typename __sig_UInt_for_UInt_t<uint_t>::type
				>;
		};

		template<>
		struct __sig_UInt_for_UInt_t<uchint_t>
		{
			template<unsigned_integral_c uint_type>
			static inline constexpr bool uint_type_gt_this_type_v = gt_sz_v<uint_type,uchint_t>;

			using type =
				std::conditional_t<
					uint_type_gt_this_type_v<usint_t>,
						usint_t,
						typename __sig_UInt_for_UInt_t<usint_t>::type
				>;
		};


	}


	template<typename UInt_t>
	using sig_UInt_for_UInt_t =
	typename ugly_details_UInt_for_UInt::__sig_UInt_for_UInt_t<UInt_t>::type;

	///<  METAFUNCION : DA EL SIGUIENTE TIPO ENTERO PARA EL ACTUAL TIPO NATURAL
	///<  POR ESPECIALIZACION EXPLICITA
	namespace ugly_details_sig_SInt_for_UInt {
		template<typename UInt>
		struct __sig_SInt_for_UInt_t
		{using type = void;};

		template<>
		struct __sig_SInt_for_UInt_t<ullint_t>
		{	using type = sint128_t;};

		template<>
		struct __sig_SInt_for_UInt_t<ulint_t>
		{
			template<typename int_type>
			static inline constexpr bool int_type_gt_this_type_v = gt_sz_v<int_type,ulint_t>;

			using type =
				std::conditional_t<
					int_type_gt_this_type_v<sllint_t>,
						sllint_t,
						typename __sig_SInt_for_UInt_t<ullint_t>::type
				>;
		};

		template<>
		struct __sig_SInt_for_UInt_t<uint_t>
		{
			template<typename int_type>
			static inline constexpr bool int_type_gt_this_type_v = gt_sz_v<int_type,uint_t>;

			using type =
				std::conditional_t<
					int_type_gt_this_type_v<slint_t>,
						slint_t,
						typename __sig_SInt_for_UInt_t<ulint_t>::type
				>;
		};

		template<>
		struct __sig_SInt_for_UInt_t<usint_t>
		{
			template<typename int_type>
			static inline constexpr bool int_type_gt_this_type_v = gt_sz_v<int_type,usint_t>;

			using type =
				std::conditional_t<
					int_type_gt_this_type_v<sint_t>,
						sint_t,
						typename __sig_SInt_for_UInt_t<uint_t>::type
				>;
		};

		template<>
		struct __sig_SInt_for_UInt_t<uchint_t>
		{
			template<typename int_type>
			static inline constexpr bool int_type_gt_this_type_v = gt_sz_v<int_type,uchint_t>;

			using type =
				std::conditional_t<
					int_type_gt_this_type_v<ssint_t>,
						ssint_t,
						typename __sig_SInt_for_UInt_t<usint_t>::type
				>;
		};



	}

	template<typename UInt_t>
	using sig_SInt_for_UInt_t =
	typename ugly_details_sig_SInt_for_UInt::__sig_SInt_for_UInt_t<UInt_t>::type;

	///<  METAFUNCION : DA EL SIGUIENTE TIPO NATURAL PARA EL ACTUAL TIPO ENTERO
	///<  POR ESPECIALIZACION EXPLICITA
	namespace ugly_details_UInt_for_SInt	{
		template<typename SInt>
		struct __sig_UInt_for_SInt_t
		{using type = void;};

		template<>
		struct __sig_UInt_for_SInt_t<sint128_t>
		{using type = uint128_t;};

		template<>
		struct __sig_UInt_for_SInt_t<schint_t>
		{using type = uchint_t;};

		template<>
		struct __sig_UInt_for_SInt_t<ssint_t>
		{using type = usint_t;};

		template<>
		struct __sig_UInt_for_SInt_t<sint_t>
		{using type = uint_t;};

		template<>
		struct __sig_UInt_for_SInt_t<slint_t>
		{using type = ulint_t;};

		template<>
		struct __sig_UInt_for_SInt_t<sllint_t>
		{using type = ullint_t;};


	}

	template<typename Int_t>
	using sig_UInt_for_SInt_t =
	typename ugly_details_UInt_for_SInt::__sig_UInt_for_SInt_t<Int_t>::type;

	///<  METAFUNCION : DA EL SIGUIENTE TIPO ENTERO PARA EL ACTUAL TIPO ENTERO
	///<  POR ESPECIALIZACION EXPLICITA
	namespace ugly_details_SInt_for_SInt {

		template<typename SInt>
		struct __sig_SInt_for_SInt_t
		{using type = void;};

		template<>
		struct __sig_SInt_for_SInt_t<sllint_t>
		{	using type = sint128_t;};

		template<>
		struct __sig_SInt_for_SInt_t<slint_t> {
			template<signed_integral_c SINT_T>
			static inline constexpr bool signed_gt_signed_v = gt_sz_v<SINT_T,slint_t>;

			using type =
				std::conditional_t<
					signed_gt_signed_v<sllint_t>,
						sllint_t,
						typename __sig_SInt_for_SInt_t<sllint_t>::type
				>;
		};

		template<>
		struct __sig_SInt_for_SInt_t<sint_t> {
			template<typename SINT_T>
			static inline constexpr bool signed_gt_signed_v = gt_sz_v<SINT_T,sint_t>;

			using type =
				std::conditional_t<
					signed_gt_signed_v<slint_t>,
						slint_t,
						typename __sig_SInt_for_SInt_t<slint_t>::type
				>;
		};

		template<>
		struct __sig_SInt_for_SInt_t<ssint_t> {
			template<typename SINT_T>
			static inline constexpr bool signed_gt_signed_v = gt_sz_v<SINT_T,ssint_t>;

			using type =
				std::conditional_t<
					signed_gt_signed_v<sint_t>,
						sint_t,
						typename __sig_SInt_for_SInt_t<sint_t>::type
				>;
		};

		template<>
		struct __sig_SInt_for_SInt_t<schint_t> {
			template<typename SINT_T>
			static inline constexpr bool signed_gt_signed_v = gt_sz_v<SINT_T,schint_t>;

			using type =
				std::conditional_t<
					signed_gt_signed_v<ssint_t>,
						ssint_t,
						typename __sig_SInt_for_SInt_t<ssint_t>::type
				>;
		};


	}

	template<typename SInt_t>
	using sig_SInt_for_SInt_t =
	typename ugly_details_SInt_for_SInt::__sig_SInt_for_SInt_t<SInt_t>::type;

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
		constexpr
			long double raiz_real{
				std::sqrt(
					static_cast<long double>(
						static_cast<SIG_UINT_T>(base)
					)
				)
			};
		return	static_cast<UINT_T>(std::floor(raiz_real));
	}

	///< QUEREMOS FABRICAR LA METAFUNCION TypeFromIntNumber_t<numero_sin_signo>
	///< QUE DEVUELVA EL TIPO ENTERO SIN SIGNO MAS PEQUENO PARA EL NUMERO numero_sin_signo
	namespace ugly_details_for_suitable_type_deduction {
		template<typename T, T Radix>
		struct UIntTypeForRadix;
		///< DEFINICION PARA ESPECIALIZACION TYPE_TRAITS::UINT_TYPE_FOR_RADIX
		///< FOR RADIX VALID
		template<integral_c T, T Radix>
			requires (Radix > 1)
		struct UIntTypeForRadix<T, Radix> {
			static constexpr 	ullint_t		uint_value_0_max    = static_cast<ullint_t>(maxbase<uchint_t>());
			static constexpr 	ullint_t		uint_value_1_max    = static_cast<ullint_t>(maxbase<usint_t>());
			static constexpr 	ullint_t		uint_value_2_max    = static_cast<ullint_t>(maxbase<uint_t>());
			static constexpr 	ullint_t		uint_value_3_max    = static_cast<ullint_t>(maxbase<ulint_t>());
			static constexpr 	ullint_t		uint_value_4_max    = static_cast<ullint_t>(maxbase<ullint_t>());
			static constexpr 	ullint_t		uint_value 					= static_cast<ullint_t>(Radix);
			using UIntType =
				std::conditional_t<
					uint_value <= uint_value_0_max,
						uchint_t,
						std::conditional_t<
							uint_value <= uint_value_1_max,
								usint_t,
								std::conditional_t<
									uint_value <= uint_value_2_max,
										uint_t,
										std::conditional_t<
											uint_value <= uint_value_3_max,
												ulint_t,
												std::conditional_t<
													uint_value <= uint_value_4_max,
														ullint_t,
														uint128_t
												>
										>
								>
						>
				>;
		};
	}

	///< DEFINICION PARA LLAMAR A TYPE_TRAITS::UINT_TYPE_FOR_RADIX
	///< CON SOLO RADIX
	///< DEVUELVE EL TIPO MAS PEQUENO PARA EL NUMERO SIN SIGNO ENTERO QUE LE
	///< PASAMOS EN TIEMPO DE COMPILACION
	using namespace ugly_details_for_suitable_type_deduction;
	template<ullint_t Radix>
	using TypeFromIntNumber_t =
			typename UIntTypeForRadix<decltype(Radix),Radix>::UIntType;


	///< QUEREMOS FABRICAR LA METAFUNCION TypeFromIntNumberLTSqrtMaxOfType_t<numero>
	///< QUE DEVUELVA EL TIPO ENTERO SIN SIGNO MAS PEQUENO PARA EL NUMERO numero
	///< TAL QUE SQRT(TYPE::MAX())>=B-1
	namespace ugly_details_for_greater_suitable_type_deduction {
		template<typename T, T Radix>
		struct UIntTypeForRadixContainsMultResult;
		///< DEFINICION PARA ESPECIALIZACION TYPE_TRAITS::UINT_TYPE_FOR_RADIX_WITH_CONTAINS_MULT_RESULT
		///< FOR RADIX VALID
		template<integral_c T, T Radix>
			requires (Radix > 1)
		struct UIntTypeForRadixContainsMultResult<T, Radix> {
			static constexpr 	ullint_t		uint_value_0_max    = static_cast<ullint_t>(sqrt_max<uchint_t>());
			static constexpr 	ullint_t		uint_value_1_max    = static_cast<ullint_t>(sqrt_max<usint_t>());
			static constexpr 	ullint_t		uint_value_2_max    = static_cast<ullint_t>(sqrt_max<uint_t>());
			static constexpr 	ullint_t		uint_value_3_max    = static_cast<ullint_t>(sqrt_max<ulint_t>());
			static constexpr 	ullint_t		uint_value_4_max    = static_cast<ullint_t>(sqrt_max<ullint_t>());
			static constexpr 	ullint_t		uint_value 					= static_cast<ullint_t>(Radix);
			using UIntType =
				std::conditional_t<
					uint_value <= uint_value_0_max,
						uchint_t,
						std::conditional_t<
							uint_value <= uint_value_1_max,
								usint_t,
								std::conditional_t<
									uint_value <= uint_value_2_max,
										uint_t,
										std::conditional_t<
											uint_value <= uint_value_3_max,
												ulint_t,
												std::conditional_t<
													uint_value <= uint_value_4_max,
														ullint_t,
														uint128_t
												>
										>
								>
						>
				>;
		};
	}
	///< DEFINICION PARA LLAMAR A TYPE_TRAITS::UINT_TYPE_FOR_RADIX_WITH_HOLD_OPS_t
	///< CON SOLO RADIX
	///< DEVUELVE EL TIPO MAS PEQUENO PARA EL NUMERO SIN SIGNO ENTERO QUE LE
	///< PASAMOS EN TIEMPO DE COMPILACION
	using namespace ugly_details_for_greater_suitable_type_deduction;
	template<integral_c IntType, IntType Radix>
	using GreaterTypeFromIntNumber_t =
	typename UIntTypeForRadixContainsMultResult<decltype(Radix),Radix>::UIntType;
}// END NAMESPACE TYPE_TRAITS
}// END NAMESPACE NUMREPR

#endif // BASIC_TYPES_HPP_INCLUDED
