#ifndef DIGIT_VARIANT_T_HPP_INCLUDED
#define DIGIT_VARIANT_T_HPP_INCLUDED

#include <cassert>
#include <cctype>
#include <charconv>
#include <concepts>
#include <cstdint>
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

#include <digit_variant.hpp>

namespace NumRepr {
using std::abs;
using std::integral;
using std::isspace;
using std::string;
using std::uint32_t;
using std::size_t;
using std::unsigned_integral;

enum class radixformat { bin, dec };

constexpr static std::size_t size_of_variant=64ull;

class digit_variant;

template <template <std::size_t I> class TC, class>
struct TC_variant;

template <template <std::size_t I> class TC, std::size_t... Is>
struct TC_variant<TC, std::index_sequence<Is...>> {
  using type = std::variant<TC<Is>...>;
};

template <template <std::size_t I> class TC, class TSeq>
using TC_variant_t = typename TC_variant<TC, TSeq>::type;

using digit_variant_t = TC_variant_t<digit_variant , std::make_index_sequence<size_of_variant>>;

/// TIPOS
/// DIGIT_VARIANT
/// REG_DIG_VARIANT
/// NAT_REG_VARIANT
/// INT_REG_VARIANT
/// NAT_VARIANT
/// INT_VARIANT

struct digit_variant : public digit_variant_t {
  using UINT_T = digit_variant<255ull>::UINT_T;
  using SIG_UINT_T = digit_variant<255ull>::SIG_UINT_T;

  inline static constexpr size_t digits = std::numeric_limits<std::uint64_t>::digits;

  inline constexpr explicit operator UINT_T() const noexcept;

  inline constexpr UINT_T get() const noexcept;

  inline constexpr explicit operator SIG_UINT_T() const noexcept;

  inline constexpr explicit operator SIG_SINT_T() const noexcept;

  /// digit_variant<10> a{3};
  /// a()->3 (como uint)
  inline constexpr UINT_T operator()() const noexcept;
  /// digit_variant<10> digito{4};
  /// digito() devuelve un 4 de tipo uchint

  constexpr void set_0() noexcept;
  constexpr void set_1() noexcept;
  constexpr void set_Bm1() noexcept;
  constexpr void set_Bm2() noexcept;
  constexpr void set_dig(digit_variant d) noexcept;
  constexpr void set_dig(UINT_T di) noexcept;

  ////////////////////////////////////////////////////////////////////////////
  inline static consteval bool is_prime() noexcept;
  ////////////////////////////////////////////////////////////////////////////
  inline static consteval digit_variant dig_max() noexcept;
  inline static consteval digit_variant dig_submax() noexcept;
  inline static consteval digit_variant dig_Bm1() noexcept;
  inline static consteval digit_variant dig_Bm2() noexcept;
  inline static consteval digit_variant dig_0() noexcept;
  inline static consteval digit_variant dig_1() noexcept;
  ////////////////////////////////////////////////////////////////////////////
  inline static consteval UINT_T ui_max() noexcept;
  inline static consteval UINT_T ui_submax() noexcept;
  inline static consteval UINT_T ui_Bm1() noexcept;
  inline static consteval UINT_T ui_Bm2() noexcept;
  inline static consteval UINT_T ui_0() noexcept;
  inline static consteval UINT_T ui_1() noexcept;
  ////////////////////////////////////////////////////////////////////////////
  inline static consteval SIG_UINT_T sui_B() noexcept;

  inline static consteval SIG_UINT_T sui_max() noexcept;

  inline static consteval SIG_UINT_T sui_submax() noexcept;

  inline static consteval SIG_UINT_T sui_0() noexcept;

  inline static consteval SIG_UINT_T sui_1() noexcept;

  ////////////////////////////////////////////////////////////////////////////
  inline static consteval SIG_SINT_T ssi_B() noexcept;

  inline static consteval SIG_SINT_T ssi_max() noexcept;

  inline static consteval SIG_UINT_T ssi_submax() noexcept;

  inline static consteval SIG_UINT_T ssi_0() noexcept;

  inline static consteval SIG_UINT_T ssi_1() noexcept;

  ////////////////////////////////////////////////////////////////////////////

  /************************************/
  /*								  */
  /*	CONSTRUIR DIGITO			  */
  /*								  */
  /************************************/

  ///< CONSTRUCTORES
  ///< CONSTRUCTOR POR DEFECTO
  consteval inline digit_variant() noexcept;

    /// CONSTRUCTOR A PARTIR DE UN ENTERO ARG
  /// ARG EQUIV ARG+Z*B DONDE Z ES UN ENTERO
  /// EN m_d SOLO QUEREMOS QUE HAYA UN NUMERO ENTRE 0 Y B-1 INCLUSIVES
  template <type_traits::integral_c Int_t>
  constexpr inline digit_variant(Int_t arg) noexcept;

  /// CONSTRUCTOR COPIA POR REFERENCIA
  constexpr inline digit_variant(const digit_variant &) noexcept = default;
  /// CONSTRUCTOR POR MOVIMIENTO
  constexpr inline digit_variant(digit_variant &&) noexcept = default;

  /// PODEMOS PASAR ARGUMENTOS POR COPIA, REFERENCIA (PUNTEROS) Y MOVIMIENTO
  /// COPIA 		: COPIA EL ARGUMENTO LITERALMENTE PARA PASARLO: EL ORIGINAL
  /// INTACTO REFERENCIA: COPIA LA DIRECCION DEL ARGUMENTO
  ///             (SI ES CONST EL COMPILADOR NO TE DEJA COMPILAR SI LO CAMBIAS)
  /// MOVIMIENTO: SI EL ARGUMETO NO SE VA A UTILIZAR MAS SE LE PASA LA PROPIEDAD
  /// A LA FUNCION

  /************************************/
  /*								  */
  /*	OPERADORES DE ASIGNACION	  */
  /*								  */
  /************************************/

  /// SOBRECARGA DEL OPERATOR=() MEDIANTE REFERENCIA CTE DESDE UN INT_T
  template <type_traits::integral_c Int_t>
  constexpr inline const digit_variant &operator=(const Int_t &a) noexcept;

  /// SOBRECARGA DEL OPERATOR=() MEDIANTE REFERENCIA CTE DESDE UN DIG_T
  constexpr inline digit_variant &operator=(const digit_variant &) noexcept = default;

  /// SOBRECARGA DEL OPERATOR=() MEDIANTE MOVIMIENTO DESDE UN DIG_T
  constexpr inline digit_variant &operator=(digit_variant &&) noexcept = default;
  /// a y b son digitos;
  /// a = std::move(b);
  /// a es identico a b; en b puede no queda nada;

  ///*************************************///
  ///< SENTIDO DE LA DIVISION DE DIGITOS >///
  ///*************************************///

  constexpr inline bool is_unit() const noexcept;

  constexpr inline bool is_0_divisor() const noexcept;

  constexpr inline digit_variant mult_inv() const noexcept;

  /**************************************/
  /*									*/
  /*	FUNCIONES PARA CONOCER EL CARRY	*/
  /*									*/
  /**************************************/

  inline constexpr static digit_variant sum_carry(digit_variant arg_1, digit_variant arg_2) noexcept;

  /************************************/
  /*								  */
  /*	OPERADORES & &= | |=    	  */
  /*  FUNCIONAN COMO MAX Y MIN		  */
  /*								  */
  /************************************/

  /// DEVOLVER EL MENOR: ANDBITWISE
  /// NO TIENE POSIBILIDAD DE ERROR
  constexpr inline digit_variant operator&(const digit_variant &arg) const noexcept;

  /// DEVOLVER EL MENOR HABIENDOLO ASIGNADO ANDBITWISE AND ASSIGN
  /// NO TIENE POSIBILIDAD DE ERROR
  constexpr inline const digit_variant &operator&=(digit_variant arg) noexcept;

  /// DEVOLVER EL MAYOR ORBITWISE
  /// NO TIENE POSIBILIDAD DE ERROR
  constexpr inline digit_variant operator|(const digit_variant &arg) const noexcept;

  /// DEVOLVER EL MAYOR HABIENDOLO ASIGNADO ORBITWISE AND ASSIGN
  /// NO TIENE POSIBILIDAD DE ERROR
  constexpr inline const digit_variant &operator|=(digit_variant arg) noexcept;

  /******************************************************/
  /*													*/
  /*	OPERADORES *^n *^=n                             */
  /*  FUNCIONAN COMO Power(*,n) y n = Power(*,n)		*/
  /*	DONDE n ES NATURAL                              */
  /*													*/
  /******************************************************/

  template <type_traits::unsigned_integral_c UIntType>
  constexpr inline const digit_variant& operator^=(UIntType exp) noexcept;

  template <type_traits::unsigned_integral_c UIntType>
  constexpr inline digit_variant operator^(UIntType exp) const noexcept;

  /****************************************/
  /*				               		  */
  /* OPERADORES COMPARACION				  */
  /*				                	  */
  /****************************************/

  constexpr inline bool operator==(digit_variant a) const noexcept;

  constexpr inline bool operator!=(digit_variant a) const noexcept;

  constexpr inline bool operator>=(digit_variant a) const noexcept;

  constexpr inline bool operator>(digit_variant a) const noexcept;

  constexpr inline bool operator<=(digit_variant a) const noexcept;

  constexpr inline bool operator<(digit_variant a) const noexcept;

  /// SI COMPARAMOS O HACEMOS UNA OPERACION CON UN INT_T SIEMPRE SERA
  /// DIG_T @ INT_T -> DIG_T Y NUNCA INT_T @ DIG_T -> ANY_TYPE
  /// METODO PROPIO DE C++20
  constexpr inline std::strong_ordering operator<=>(digit_variant rhs) const noexcept;

  template <type_traits::integral_c Int_t>
  constexpr inline bool operator==(Int_t rhs) noexcept;

  /// METODO PROPIO DE C++20
  /// ESTABLECEMOS UN ORDEN PARCIAL SOBRE LOS ENTEROS SI a b EN Z
  /// ESTANDO EN ESTE AMBITO DE BASE B SI a mod B = b mod B
  template <type_traits::integral_c Int_t>
  constexpr inline std::weak_ordering operator<=>(Int_t rhs) const noexcept;

  /********************************************/
  /*				    					  */
  /*   ARITMETICOS CON ASIGNACION     		  */
  /*				    					  */
  /********************************************/

  constexpr inline
  const digit_variant& operator+=(digit_variant arg) noexcept;

  template <type_traits::integral_c Int_t>
  constexpr inline
  const digit_variant &operator+=(Int_t arg) noexcept;

  constexpr inline
  const digit_variant& operator-=(digit_variant arg) noexcept;

  template <type_traits::integral_c Int_t>
  constexpr inline
  const digit_variant &operator-=(Int_t arg) noexcept;

  constexpr inline
  const digit_variant& operator*=(digit_variant arg) noexcept;

  template <type_traits::integral_c Int_t>
  constexpr inline
  const digit_variant& operator*=(Int_t arg) noexcept;

  constexpr inline
  const digit_variant& operator/=(digit_variant arg) noexcept;

  template <type_traits::integral_c Int_t>
  constexpr inline
  const digit_variant& operator/=(Int_t arg) noexcept;

  constexpr inline
  const digit_variant& operator%=(digit_variant arg) noexcept;

  template <type_traits::integral_c Int_t>
  constexpr inline const digit_variant&
  operator%=(Int_t arg) noexcept;

  /// Tengo serias dudas que la division y el resto euclideo tengan cabida
  /// entre los operadores aritmeticos de un tipo digit_variant
  /// DUDA SATISFECHA: TIENEN CABIDA PORQUE EL INVERSO MULTIPLICATIVO ETC.
  /// SOLO NOS SIRVE SI ESTUVIERAMOS CONSTRUYENDO NUMEROS DE UN ANILLO FINITO

  /********************************/
  /*			     			  */
  /* 		  PRE Y POST 		  */
  /*			CIRCULARES		  */
  /*							  */
  /********************************/

  constexpr inline
  const digit_variant& operator++() noexcept;

  constexpr inline digit_variant operator++(int) noexcept;

  constexpr inline const digit_variant &operator--() noexcept;

  constexpr inline digit_variant operator--(int) noexcept;

  /****************************************/
  /*									  */
  /*    OPERADORES ARITMETICOS   		  */
  /*									  */
  /****************************************/

  constexpr inline digit_variant operator+(digit_variant arg) const noexcept;

  constexpr inline digit_variant operator-(digit_variant arg) const noexcept;

  constexpr inline digit_variant operator*(digit_variant arg) const noexcept;

  constexpr inline digit_variant operator/(digit_variant arg) const noexcept;

  constexpr inline digit_variant operator%(digit_variant arg) const noexcept;

  template <type_traits::integral_c Int_type>
  constexpr inline digit_variant operator+(Int_type arg) const noexcept;

  template <type_traits::integral_c Int_type>
  constexpr inline digit_variant operator-(Int_type arg) const noexcept;

  template <type_traits::integral_c Int_type>
  constexpr inline digit_variant operator*(Int_type arg) const noexcept;

  template <type_traits::integral_c Int_type>
  constexpr inline digit_variant operator/(Int_type arg) const noexcept;

  template <type_traits::integral_c Int_type>
  constexpr inline digit_variant operator%(Int_type arg) const noexcept;

  /****************************************/
  /*									  */
  /*	     COMPLEMENTO BASE 			  */
  /*	      Y BASE MENOS 1			  */
  /*									  */
  /****************************************/

  /// EN BASE B, B-1-m_d ES EL COMPL_Bm1(m_d)
  constexpr inline
  digit_variant operator!() const noexcept;

  /// EN BASE B, B-m_d ES EL COMPL_B(m_d)
  constexpr inline
  digit_variant operator-() const noexcept;

  constexpr inline /// "C_Bm1" es identico a "operator!()"
  digit_variant C_Bm1() const noexcept;

  constexpr inline /// "C_B" es identico a "operator-()"
  digit_variant C_B() const noexcept;

  /****************************************************/
  /*				    							  */
  /*    MODIFICADORES COMPLEMENTO	    			  */
  /*				    							  */
  /****************************************************/

  constexpr inline const digit_variant &mC_Bm1() noexcept;

  constexpr inline const digit_variant &mC_B() noexcept;

  /**********************************/
  /*                            	*/
  /*   	NULO Y MAXIMO         	  	*/
  /*                            	*/
  /**********************************/

  constexpr inline
  bool is_0() const noexcept;

  constexpr inline
  bool is_1() const noexcept;

  constexpr inline
  bool is_0or1() const noexcept;

  constexpr inline bool
  is_not_1() const noexcept;

  constexpr inline bool
  is_not_0() const noexcept;

  constexpr inline
  bool is_not_0or1() const noexcept;

  constexpr inline
  bool is_Bm1() const noexcept;

  constexpr inline
  bool is_not_Bm1() const noexcept;

  constexpr inline
  bool is_Bm1orBm2() const noexcept;

  constexpr inline
  bool is_not_Bm1orBm2() const noexcept;

  constexpr inline
  bool is_Bm2() const noexcept;

  constexpr inline
  bool is_not_Bm2() const noexcept;

  constexpr inline
  bool is_not_maxormin() const noexcept;

  constexpr inline
  bool is_maxormin() const noexcept;

  constexpr inline
  bool is_far_maxormin() const noexcept;

  constexpr inline
  bool is_near_maxormin() const noexcept;

  /********************************/
  /*							  */
  /* 	     VARIOS CASTS		  */
  /*							  */
  /********************************/
  constexpr inline
  std::uint64_t radix() const;

  constexpr inline
  std::string to_string() const noexcept;
}; /// END OF CLASS DIGIT_VARIANT

/************************************/
/*                                  */
/*         ISTREAM Y OSTREAM        */
/*                                  */
/************************************/

template <std::uint64_t Base>
  requires(Base > 1)
std::istream &operator>>(std::istream &is, digit_variant<Base> &arg);

template <std::uint64_t Base>
  requires(Base > 1)
std::ostream &operator<<(std::ostream &os, digit_variant<Base> arg);

digit_variant make_digit_variant(std::uint32_t,std::uint32_t);

} // END OF NAMESPACE NUMREPR IN THIS TRANSLATION UNIT

#endif // DIGIT_VARIANT_T_HPP_INCLUDED
