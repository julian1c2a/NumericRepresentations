#ifndef DIG_T_HPP_INCLUDED
#define DIG_T_HPP_INCLUDED

#include "auxiliary_functions.hpp"
#include "auxiliary_types.hpp"

namespace NumRepr {
using type_traits::sqrt_max;
using type_traits::maxbase;
using type_traits::sig_SInt_for_UInt_t;
using type_traits::sig_UInt_for_UInt_t;
using type_traits::suitable_base;
using type_traits::uint_type_for_radix_c;
///< WRAPPER PARA UN TIPO UINT_T QUE UNSIGNED_INTEGRAL_T<UINT_T>
///< SE SOBRECARGAN LOS OPERADORES ARITMETICOS PARA ARITMETICA MODULAR
///< DIG_T = SUMA Y MULTIPLICACION CIRCULAR (MODULAR CON MOD B)
template <std::uint64_t B>
requires (B > 1)
struct dig_t {
/// GENERACIÓN DEL TIPO QUE CONTENDRÁ EL DÍGITO CON ENTERO SIN SIGNO
using UINT_T = typename type_traits::TypeFromIntNumber_t<static_cast<uint64_t>(B)>;
private:
  UINT_T m_d;

public:

  // SIG_UINT_T(uchint) -> usint
  using SIG_UINT_T = sig_UInt_for_UInt_t<UINT_T>;
  // SIG_SINT_T(uchint) -> ssint
  using SIG_SINT_T = sig_SInt_for_UInt_t<UINT_T>;

  using uintspair = std::array<UINT_T, 2>;
  using digspair = std::array<dig_t, 2>;
  using uintspairlist = std::array<uintspair, B>;
  using uintspairtbl = std::array<uintspairlist, B>;

  ///< BEGIN : CONSTRUCCION DE LAS TABLAS DE MULTIPLICAR
  ///<         ESTATICAS PARA TODA LA CLASE
  /// ¡¡¡¡ no usado aún !!!!
  template <UINT_T n, UINT_T m>
    requires((n < B) && (m < B))
  static consteval inline uintspair mult() noexcept {
    if constexpr (B > type_traits::sqrt_max<UINT_T>()) {
      constexpr SIG_UINT_T sup_n{n};
      constexpr SIG_UINT_T sup_m{m};
      constexpr SIG_UINT_T result{sup_n * sup_m};
      constexpr UINT_T ret_1{result / B}; // "DECENAS"
      constexpr UINT_T ret_0{result % B}; // "UNIDADES"
      constexpr uintspair ret{ret_1, ret_0};
      return ret;
    } else {
      constexpr UINT_T result{n * m};
      constexpr UINT_T ret_1{result / B}; // "DECENAS"
      constexpr UINT_T ret_0{result % B}; // "UNIDADES"
      constexpr uintspair ret{ret_1, ret_0};
      return ret;
    }
  }
  /// PARA B=3 2*2									  1  COMIENZAN POR 2
  /// B-2
  /// PARA B=4 2*2 2*3 3*4							  3  COMIENZAN POR 2 B-2, 3
  /// B-3
  /// PARA B=5 2*2 2*3 2*4 3*3 3*4 4*4				  6  COMIENZAN POR 2 B-2, 3 B-3, 4
  /// B-4 PARA B=6 2*2 2*3 2*4 2*5 3*3 3*4 3*5 4*4 4*5 5*5 10  COMIENZAN POR 2
  /// B-2, 3 B-3, 4 B-4, 5 B-5
  /// PARA B=r 2*2 2*(2+1) ... 2*(r-1)		     r-1  r  COMIENZAN POR 2 B-2, 3
  /// B-3, 4 B-4, 5 B-1, ... , r-1 B-r+1
  ///			 3*3		 ... 3*(r-1) r-2
  ///						 ...
  ///			(r-1)*(r-1) r-(r-1)
  ///													_______
  ///							(r-2)r-(r-1)*r/2 + 1
  ///= 							[2(r-2)-((r-2)+1)]r/2 + 1 =
  ///							((r-3)r + 2)/2
  ///= 							(r^2 - 3r + 2) / 2 													a r^2 + b r + c
  ///							   						------------------
  ///													1 = a  9 + b 3 +
  ///c 													3 = a 16 + b 4 + c 													6 = a 25 + b 5 + c
  ///													------------------
  ///													1 = a  9 + b 3 +
  ///c 													2 = a  7 + b 1 													5 = a 16 + b 2
  ///													------------------
  ///													1 = a  9 + b 3 +
  ///c 													2 = a  7 + b 													1 = a  2
  ///													------------------
  ///													c =
  ///2/2 													b = -3/2 													a =  1/2
  ///													------------------
  ///													SIZE = (B^2 - 3B +
  ///2)/2 							2+3+4+...+B-1 = 1+2+3+4+...+B-1 - 1           =
  ///                         = (B-1)B/2 - 2(B-1)/2   = (B^2 - B - 2B +2)/2 =
  ///                                                 =(B^2-3B+2)/2
  ///
  /// FALTARIA HACERLAS SOLO PARA BASES MAYORES QUE 2
  /// CODE NEW USING TYPES :
  /// using pair_map = std::pair<uintspair,uintspair>;
  /// CODE MULTTABLE:
  ///		static consteval std::array<pair_map,(B^2 - 3B + 2)/2>
  ///multtable{make_multtables()};
  /// CODE FOR MAKE_MULTTABLES():
  ///		static consteval
  ///		std::array<pair_map,(B^2 - 3B + 2)/2> make_multtables() noexcept
  ///{ 			std::array<pair_map,(B^2 - 3B + 2)/2>	ret;
  ///			/// ESTO QUE SIGUE HABRIA QUE HACERLO POR UNROOLING LOOP EN
  ///COMPILE TIME
  ///			/// YA QUE IDX E IDY NO SON CONSTANTES EN TIEMPO DE
  ///COMPILACION
  ///			///	LO MEJOR ES HACERLO EN UNA CLASE TEMPLATE POR
  ///RECURSION 			for(size_t idx{2} ; idx < B ; ++idx) { 				for(size_t idy{idx} ; idy
  ///< B ; ++idy) { 					make_pair(make_array(idx,idy),mult<idx,idy>());
  ///				}
  ///			}
  ///		}

public:
  inline constexpr explicit operator UINT_T() const noexcept { return m_d; }

  inline constexpr UINT_T get() const noexcept { return (m_d); }

  inline constexpr explicit operator SIG_UINT_T() const noexcept {
    return static_cast<SIG_UINT_T>(m_d);
  }

  inline constexpr explicit operator SIG_SINT_T() const noexcept {
    return static_cast<SIG_SINT_T>(m_d);
  }
  /// dig_t<10> a{3};
  /// a()->3 (como uint)
  inline constexpr UINT_T operator()() const noexcept { return (m_d); }
  /// dig_t<10> digito{4};
  /// digito() devuelve un 4 de tipo uchint

  constexpr void set_0() noexcept { m_d = 0; }
  constexpr void set_1() noexcept { m_d = 1; }
  constexpr void set_Bm1() noexcept { m_d = B - 1; }
  constexpr void set_Bm2() noexcept { m_d = B - 2; }
  constexpr void set_dig(dig_t d) noexcept { m_d = d; }
  constexpr void set_dig(UINT_T di) noexcept { m_d = di%B; }

public:
  ////////////////////////////////////////////////////////////////////////////
  inline static consteval bool is_prime() noexcept {
    return auxiliary_functions::is_prime(static_cast<std::size_t>(B));
  }
  ////////////////////////////////////////////////////////////////////////////
  inline static consteval dig_t dig_max() noexcept { return dig_t(B - 1u); };
  inline static consteval dig_t dig_submax() noexcept { return dig_t(B - 2u); }
  inline static consteval dig_t dig_Bm1() noexcept { return dig_t(B - 1u); }
  inline static consteval dig_t dig_Bm2() noexcept { return dig_t(B - 2u); }
  inline static consteval dig_t dig_0() noexcept { return dig_t(); }
  inline static consteval dig_t dig_1() noexcept { return dig_t(1u); }
  ////////////////////////////////////////////////////////////////////////////
  inline static consteval UINT_T ui_max() noexcept { return UINT_T(B - 1u); }
  inline static consteval UINT_T ui_submax() noexcept { return UINT_T(B - 2u); }
  inline static consteval UINT_T ui_Bm1() noexcept { return UINT_T(B - 1u); }
  inline static consteval UINT_T ui_Bm2() noexcept { return UINT_T(B - 2u); }
  inline static consteval UINT_T ui_0() noexcept { return UINT_T(0u); }
  inline static consteval UINT_T ui_1() noexcept { return UINT_T(1u); }
  ////////////////////////////////////////////////////////////////////////////
  inline static consteval SIG_UINT_T sui_B() noexcept {
    return static_cast<SIG_UINT_T>(B);
  }
  inline static consteval SIG_UINT_T sui_max() noexcept {
    return static_cast<SIG_UINT_T>(B - 1u);
  }
  inline static consteval SIG_UINT_T sui_submax() noexcept {
    return static_cast<SIG_UINT_T>(B - 2u);
  }
  inline static consteval SIG_UINT_T sui_0() noexcept {
    return static_cast<SIG_UINT_T>(0u);
  }
  inline static consteval SIG_UINT_T sui_1() noexcept {
    return static_cast<SIG_UINT_T>(1u);
  }
  ////////////////////////////////////////////////////////////////////////////
  inline static consteval SIG_SINT_T ssi_B() noexcept {
    return static_cast<SIG_SINT_T>(B);
  }
  inline static consteval SIG_SINT_T ssi_max() noexcept {
    return static_cast<SIG_SINT_T>(B - 1u);
  }
  inline static consteval SIG_UINT_T ssi_submax() noexcept {
    return static_cast<SIG_SINT_T>(B - 2u);
  }
  inline static consteval SIG_UINT_T ssi_0() noexcept {
    return static_cast<SIG_SINT_T>(0u);
  }
  inline static consteval SIG_UINT_T ssi_1() noexcept {
    return static_cast<SIG_SINT_T>(1u);
  }
  ////////////////////////////////////////////////////////////////////////////

public:
  /************************************/
  /*								  */
  /*	CONSTRUIR DIGITO			  */
  /*								  */
  /************************************/

  ///< CONSTRUCTORES
  ///< CONSTRUCTOR POR DEFECTO
  consteval inline dig_t() noexcept : m_d(0u) {}

private:
  ///< NORMALIZA ES UNA FUNCION QUE BASICAMENTE SI ENTRA 1524 DEVUELVE 1524%B
  ///< TENIENDO EN CUENTA TIPOS Y SIGNOS
  template <type_traits::integral_c Int_t>
  constexpr static inline UINT_T normaliza(Int_t arg) noexcept {
    if constexpr (std::is_same_v<Int_t, UINT_T>) {
      return (arg % B);
    } else if constexpr (std::is_signed_v<Int_t>) {
      if constexpr (type_traits::maxbase<Int_t>() >=
                    type_traits::maxbase<SIG_SINT_T>()) {
        constexpr Int_t sint_0{0}; // ssi_0()
        constexpr Int_t sint_B{B}; // ssi_B()
        Int_t cparg{arg};
        if (arg < sint_0) {
          Int_t coc{(-arg) / sint_B};
          coc *= sint_B;
          cparg += coc;
          if (cparg < 0)
            cparg += sint_B;
          if (cparg >= sint_B)
            cparg -= sint_B;
        } else {
          cparg %= sint_B;
        }
        return static_cast<UINT_T>(cparg);
      } else {
        constexpr SIG_SINT_T sint_0{0};
        constexpr SIG_SINT_T sint_B{B};
        SIG_SINT_T cparg{arg};
        if (arg < sint_0) {
          SIG_SINT_T coc{(-arg) / sint_B};
          coc *= sint_B;
          cparg += coc;
          if (cparg < 0)
            cparg += sint_B;
          if (cparg >= sint_B)
            cparg -= sint_B;
        } else {
          cparg %= sint_B;
        }
        return static_cast<UINT_T>(cparg);
      }
    } else {
      if constexpr (maxbase<Int_t>() < maxbase<UINT_T>()) {
        constexpr SIG_UINT_T uint_B{B};
        SIG_UINT_T cparg{arg};
        if (arg >= uint_B) {
          cparg %= uint_B;
        }
        return static_cast<UINT_T>(cparg);
      } else {
        constexpr Int_t uint_B{B};
        Int_t cparg{arg};
        if (arg >= uint_B) {
          cparg %= uint_B;
        }
        return static_cast<UINT_T>(cparg);
      }
    }
  }

public:
  /// CONSTRUCTOR A PARTIR DE UN ENTERO ARG
  /// ARG EQUIV ARG+Z*B DONDE Z ES UN ENTERO
  /// EN m_d SOLO QUEREMOS QUE HAYA UN NUMERO ENTRE 0 Y B-1 INCLUSIVES
  template <type_traits::integral_c Int_t>
  constexpr inline dig_t(Int_t arg) noexcept : m_d(normaliza<Int_t>(arg)) {}

  /// CONSTRUCTOR COPIA POR REFERENCIA
  constexpr inline dig_t(const dig_t &) noexcept = default;
  /// CONSTRUCTOR POR MOVIMIENTO
  constexpr inline dig_t(dig_t &&) noexcept = default;

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
  constexpr inline const dig_t &operator=(const Int_t &a) noexcept {
    if constexpr (std::is_same_v<Int_t, UINT_T>) {
      if (&a != &m_d) {
        m_d = normaliza<Int_t>(a);
      }
    } else {
      m_d = normaliza<Int_t>(a);
    }
    return (*this);
  }
  /// SOBRECARGA DEL OPERATOR=() MEDIANTE REFERENCIA CTE DESDE UN DIG_T
  constexpr inline dig_t &operator=(const dig_t &) noexcept = default;
  /// SOBRECARGA DEL OPERATOR=() MEDIANTE MOVIMIENTO DESDE UN DIG_T
  constexpr inline dig_t &operator=(dig_t &&) noexcept = default;
  /// a y b son digitos;
  /// a = std::move(b);
  /// a es identico a b; en b puede no queda nada;

  ///*************************************///
  ///< SENTIDO DE LA DIVISION DE DIGITOS >///
  ///*************************************///

  constexpr inline bool is_unit() const noexcept { // FROM FINITE RINGS
    ///******************************************///
    ///< Es B COPRIMO con m_d ?                 >///
    ///< Es max_comun_divisor(B,m_d)==1 ? 		>///
    ///******************************************///
    dig_t &cthis{*this};
    if constexpr (is_prime()) {
      if (!is_0()) {
        return true;
      } else {
        return false;
      }
    } else {
      if (is_1())
        return true;
      else if (std::gcd(B, m_d) != ui_1())
        return false;
      else
        return true;
    }
  }

  constexpr inline bool is_0_divisor() const noexcept { // FROM FINITE RINGS
    ///******************************************///
    ///< Es B NO ES COPRIMO con m_d ?			>///
    ///< Es max_comun_divisor(B,m_d)!=1 ?       >///
    ///******************************************///
    if constexpr (is_prime()) {
      if (is_0()) {
        return true;
      } else {
        return false;
      }
    } else {
      if (is_0())
        return true;
      else if (std::gcd(B, m_d) != ui_1())
        return true;
      else
        return false;
    }
  }

  constexpr inline dig_t mult_inv() const noexcept { // FROM FINITE RINGS
    if (is_unit()) {
      dig_t &cthis{*this};
      if (is_1()) {
        return dig_1();
      } else if (is_Bm1())
        return dig_max();
      else {
        for (dig_t index(2); !is_Bm1(); ++index) {
          if (index.is_unit()) {
            if ((cthis * index).is_1()) {
              return index;
            }
          }
        }
      }
    } else {
      return dig_0();
    }
  }

  /**************************************/
  /*									*/
  /*	FUNCIONES PARA CONOCER EL CARRY	*/
  /*									*/
  /**************************************/

  inline constexpr static dig_t sum_carry(dig_t arg_1, dig_t arg_2) noexcept {
    if constexpr (B <= type_traits::middle_max<UINT_T>()) {
      if constexpr ((B % 2) == 0) {
        constexpr UINT_T Bdiv2{B / 2};
        if ((arg_1() < Bdiv2) && (arg_2() < Bdiv2)) {
          return dig_0();
        } else if ((arg_1() >= Bdiv2) && (arg_2() >= Bdiv2)) {
          return dig_1();
        } else if (arg_1() >= B - arg_2()) {
          return dig_1();
        } else {
          return dig_0();
        }
      } else {
        constexpr UINT_T Bdiv2_1{B / 2};
        constexpr UINT_T Bdiv2_2{(B / 2) + 1};
        if (((arg_1() < Bdiv2_1) && (arg_2() < Bdiv2_2)) ||
            ((arg_1() < Bdiv2_2) && (arg_2() < Bdiv2_1))) {
          return dig_0();
        } else if (((arg_1() >= Bdiv2_1) && (arg_2() >= Bdiv2_2)) ||
                   ((arg_1() >= Bdiv2_2) && (arg_2() >= Bdiv2_1))) {
          return dig_1();
        } else if (arg_1() >= B - arg_2()) {
          return dig_1();
        } else {
          return dig_0();
        }
      }
    } else {
      if constexpr ((B % 2) == 0) {
        constexpr SIG_UINT_T Bdiv2{B / 2};
        if ((arg_1() < Bdiv2) && (arg_2() < Bdiv2)) {
          return dig_0();
        } else if ((arg_1() >= Bdiv2) && (arg_2() >= Bdiv2)) {
          return dig_1();
        } else if (arg_1() >= B - arg_2()) {
          return dig_1();
        } else {
          return dig_0();
        }
      } else {
        constexpr SIG_UINT_T Bdiv2_1{B / 2};
        constexpr SIG_UINT_T Bdiv2_2{(B / 2) + 1};
        if (((arg_1() < Bdiv2_1) && (arg_2() < Bdiv2_2)) ||
            ((arg_1() < Bdiv2_2) && (arg_2() < Bdiv2_1))) {
          return dig_0();
        } else if (((arg_1() >= Bdiv2_1) && (arg_2() >= Bdiv2_2)) ||
                   ((arg_1() >= Bdiv2_2) && (arg_2() >= Bdiv2_1))) {
          return dig_1();
        } else if (arg_1() >= B - arg_2()) {
          return dig_1();
        } else {
          return dig_0();
        }
      }
    }
  }

  /************************************/
  /*								  */
  /*	OPERADORES & &= | |=    	  */
  /*  FUNCIONAN COMO MAX Y MIN		  */
  /*								  */
  /************************************/

  /// DEVOLVER EL MENOR: ANDBITWISE
  /// NO TIENE POSIBILIDAD DE ERROR
  constexpr inline dig_t operator&(const dig_t &arg) const noexcept {
    return (((*this) <= arg) ? (*this) : arg);
  }

  /// DEVOLVER EL MENOR HABIENDOLO ASIGNADO ANDBITWISE AND ASSIGN
  /// NO TIENE POSIBILIDAD DE ERROR
  constexpr inline const dig_t &operator&=(dig_t arg) noexcept {
    if (arg < (*this))
      (*this) = arg;
    return (*this);
  }

  /// DEVOLVER EL MAYOR ORBITWISE
  /// NO TIENE POSIBILIDAD DE ERROR
  constexpr inline dig_t operator|(const dig_t &arg) const noexcept {
    return (((*this) >= arg) ? (*this) : arg);
  }

  /// DEVOLVER EL MAYOR HABIENDOLO ASIGNADO ORBITWISE AND ASSIGN
  /// NO TIENE POSIBILIDAD DE ERROR
  constexpr inline const dig_t &operator|=(dig_t arg) noexcept {
    if (arg > (*this))
      (*this) = arg;
    return (*this);
  }

  /******************************************************/
  /*													*/
  /*	OPERADORES *^n *^=n                             */
  /*  FUNCIONAN COMO Power(*,n) y n = Power(*,n)		*/
  /*	DONDE n ES NATURAL                              */
  /*													*/
  /******************************************************/

  template <type_traits::unsigned_integral_c UIntType>
  constexpr inline const dig_t& operator^=(UIntType exp) noexcept {
    dig_t &cthis{*this};
    if (exp == 0) {
      cthis = dig_1();
      return (cthis);
    } else if (exp == 1) {
      return (cthis);
    } else if (exp == 2) {
      cthis *= cthis;
      return (cthis);
    } else {
      const dig_t vthis{*this};
      cthis *= vthis;
      for (UIntType ix{2}; ix < exp; ++ix) {
        cthis *= vthis;
      }
      return (cthis);
    }
  }

  template <type_traits::unsigned_integral_c UIntType>
  constexpr inline dig_t operator^(UIntType exp) const noexcept {
    dig_t cpthis{*this};
    cpthis ^= exp;
    return cpthis;
  }

  /****************************************/
  /*				               		  */
  /* OPERADORES COMPARACION				  */
  /*				                	  */
  /****************************************/

  constexpr inline bool operator==(dig_t a) const noexcept {
    return ((a.m_d == m_d) ? true : false);
  }
  constexpr inline bool operator!=(dig_t a) const noexcept {
    return ((a.m_d != m_d) ? true : false);
  }
  constexpr inline bool operator>=(dig_t a) const noexcept {
    return ((a.m_d <= m_d) ? true : false);
  }
  constexpr inline bool operator>(dig_t a) const noexcept {
    return ((a.m_d < m_d) ? true : false);
  }
  constexpr inline bool operator<=(dig_t a) const noexcept {
    return ((a.m_d >= m_d) ? true : false);
  }
  constexpr inline bool operator<(dig_t a) const noexcept {
    return ((a.m_d > m_d) ? true : false);
  }
  /// SI COMPARAMOS O HACEMOS UNA OPERACION CON UN INT_T SIEMPRE SERA
  /// DIG_T @ INT_T -> DIG_T Y NUNCA INT_T @ DIG_T -> ANY_TYPE
  /// METODO PROPIO DE C++20
  constexpr inline std::strong_ordering operator<=>(dig_t rhs) const noexcept {
    const auto lhs_d{m_d};
    const auto rhs_d{rhs.m_d};
    return ((lhs_d < rhs_d) ? std::strong_ordering::less
                            : ((lhs_d > rhs_d) ? std::strong_ordering::greater
                                               : std::strong_ordering::equal));
  }

  template <type_traits::integral_c Int_t>
  constexpr inline bool operator==(Int_t rhs) noexcept {
    const dig_t &lhs{*this};
    return ((lhs.m_d == normaliza<Int_t>(rhs)) ? true : false);
  }
  /// METODO PROPIO DE C++20
  /// ESTABLECEMOS UN ORDEN PARCIAL SOBRE LOS ENTEROS SI a b EN Z
  /// ESTANDO EN ESTE AMBITO DE BASE B SI a mod B = b mod B
  template <type_traits::integral_c Int_t>
  constexpr inline std::weak_ordering operator<=>(Int_t rhs) const noexcept {
    const dig_t &lhs{*this};
    const UINT_T rhs_B{normaliza<Int_t>(rhs)};
    return ((lhs() < rhs_B)   ? std::weak_ordering::less
            : (lhs() > rhs_B) ? std::weak_ordering::greater
                              : std::weak_ordering::equivalent);
  }

  /********************************************/
  /*				    					  */
  /*   ARITMETICOS CON ASIGNACION     		  */
  /*				    					  */
  /********************************************/

  constexpr inline
  const dig_t& operator+=(dig_t arg) noexcept {
    dig_t &cthis{*this};
    if constexpr (B < type_traits::middle_max<UINT_T>()) {
      m_d += arg.m_d;
      if (m_d >= B)
        m_d -= B;
      return (cthis);
    } else {
      SIG_UINT_T tmp{m_d};
      tmp += (arg.m_d);
      if (tmp >= B)
        tmp -= B;
      m_d = static_cast<UINT_T>(tmp);
      return (cthis);
    }
  }

  template <type_traits::integral_c Int_t>
  constexpr inline
  const dig_t &operator+=(Int_t arg) noexcept {
    if constexpr (B >= type_traits::middle_max<UINT_T>()) {
      const SIG_UINT_T arg1{normaliza<Int_t>(arg)};
      SIG_UINT_T arg2{m_d};
      arg2 += arg1;
      if (arg2 >= static_cast<Int_t>(B))
        arg2 -= static_cast<Int_t>(B);
      m_d = static_cast<UINT_T>(arg2);
      return (*this);
    } else {
      const UINT_T arg1{normaliza<Int_t>(arg)};
      UINT_T arg2{m_d};
      arg2 += arg1;
      if (arg2 >= static_cast<Int_t>(B))
        arg2 -= static_cast<Int_t>(B);
      m_d = static_cast<UINT_T>(arg2);
      return (*this);
    }
  }

  constexpr inline
  const dig_t& operator-=(dig_t arg) noexcept {
    SIG_SINT_T cp_dm{m_d};
    cp_dm -= arg.m_d;
    if (cp_dm < 0)
      cp_dm += ssi_B();
    m_d = cp_dm;
    return (*this);
  }

  template <type_traits::integral_c Int_t>
  constexpr inline
  const dig_t &operator-=(Int_t arg) noexcept {
    SIG_SINT_T tmp{normaliza<Int_t>(arg)};
    SIG_SINT_T este{m_d};
    este -= tmp;
    if (este < static_cast<SIG_SINT_T>(0))
      este += ssi_B();
    m_d = este;
    return (*this);
  }

  constexpr inline
  const dig_t& operator*=(dig_t arg) noexcept {
    if constexpr (B < type_traits::sqrt_max<UINT_T>()) {
      m_d *= arg.m_d;
      m_d %= B;
      return (*this);
    } else {
      SIG_UINT_T tmp{m_d};
      tmp *= arg.m_d;
      tmp %= static_cast<SIG_UINT_T>(B);
      m_d = static_cast<UINT_T>(tmp);
      return (*this);
    }
  }

  template <type_traits::integral_c Int_t>
  constexpr inline
  const dig_t& operator*=(Int_t arg) noexcept {
    const Int_t tmp{normaliza<Int_t>(arg)};
    if constexpr (std::is_signed_v<Int_t>) {
      if constexpr (sizeof(Int_t) > sizeof(UINT_T)) {
        using SIG2_SINT_T = type_traits::sig_SInt_for_SInt_t<Int_t>;
        const SIG2_SINT_T norm_arg{tmp};
        SIG2_SINT_T este{m_d};
        este *= norm_arg;
        este %= static_cast<SIG2_SINT_T>(B);
        m_d = static_cast<UINT_T>(este);
        return (*this);
      } else {
        const SIG_SINT_T norm_arg{tmp};
        SIG_SINT_T este{m_d};
        este *= norm_arg;
        este %= static_cast<SIG_SINT_T>(B);
        m_d = static_cast<UINT_T>(este);
        return (*this);
      }
    } else {
      if constexpr (sizeof(Int_t) > sizeof(UINT_T)) {
        using SIG2_UINT_T = type_traits::sig_UInt_for_UInt_t<Int_t>;
        const SIG2_UINT_T norm_arg{tmp};
        SIG2_UINT_T este{m_d};
        este *= norm_arg;
        este %= static_cast<SIG2_UINT_T>(B);
        m_d = static_cast<UINT_T>(este);
        return (*this);
      } else {
        const SIG_UINT_T norm_arg{tmp};
        SIG_UINT_T este{m_d};
        este *= norm_arg;
        este %= static_cast<SIG_UINT_T>(B);
        m_d = static_cast<UINT_T>(este);
        return (*this);
      }
    }
  }

  constexpr inline
  const dig_t& operator/=(dig_t arg) noexcept {
    if (arg.m_d != ui_0())
      m_d /= arg.m_d;
    return (*this);
  }

  template <type_traits::integral_c Int_t>
  constexpr inline
  const dig_t& operator/=(Int_t arg) noexcept {
    UINT_T cparg{normaliza<Int_t>(arg)};
    dig_t tmp{cparg};
    if (tmp != dig_0())
      (*this) /= tmp;
    return (*this);
  }

  constexpr inline
  const dig_t& operator%=(dig_t arg) noexcept {
    if (arg.m_d != ui_0())
      m_d %= arg.m_d;
    return (*this);
  }

  template <type_traits::integral_c Int_t>
  constexpr inline const dig_t&
  operator%=(Int_t arg) noexcept {
    dig_t cparg{normaliza<Int_t>(arg)};
    if (cparg != dig_0())
      (*this) %= cparg;
    return (*this);
  }
  /// Tengo serias dudas que la division y el resto euclideo tengan cabida
  /// entre los operadores aritmeticos de un tipo dig_t
  /// DUDA SATISFECHA: TIENEN CABIDA PORQUE EL INVERSO MULTIPLICATIVO ETC.
  /// SOLO NOS SIRVE SI ESTUVIERAMOS CONSTRUYENDO NUMEROS DE UN ANILLO FINITO

  /********************************/
  /*			     			  */
  /* 		  PRE Y POST 		  */
  /*			CIRCULARES		  */
  /*							  */
  /********************************/

  constexpr inline
  const dig_t& operator++() noexcept {
    (m_d < ui_max()) ? (++m_d) : (m_d = ui_0());
    return (*this);
  }

  constexpr inline dig_t operator++(int) noexcept {
    dig_t ret(*this);
    ++(*this);
    return ret;
  }

  constexpr inline const dig_t &operator--() noexcept {
    m_d = (m_d > ui_0()) ? (--m_d) : (ui_max());
    return (*this);
  }

  constexpr inline dig_t operator--(int) noexcept {
    dig_t ret(*this);
    --(*this);
    return ret;
  }

  /****************************************/
  /*									  */
  /*    OPERADORES ARITMETICOS   		  */
  /*									  */
  /****************************************/

  constexpr inline dig_t operator+(dig_t arg) const noexcept {
    dig_t ret(*this);
    ret += arg;
    return ret;
  }

  constexpr inline dig_t operator-(dig_t arg) const noexcept {
    dig_t ret(*this);
    ret -= arg;
    return ret;
  }

  constexpr inline dig_t operator*(dig_t arg) const noexcept {
    dig_t ret(*this);
    ret *= arg;
    return ret;
  }

  constexpr inline dig_t operator/(dig_t arg) const noexcept {
    dig_t ret(*this);
    ret /= arg;
    return ret;
  }

  constexpr inline dig_t operator%(dig_t arg) const noexcept {
    dig_t ret(*this);
    ret %= arg;
    return ret;
  }

  template <type_traits::integral_c Int_type>
  constexpr inline dig_t operator+(Int_type arg) const noexcept {
    dig_t ret(*this);
    ret += normaliza<Int_type>(arg);
    return ret;
  }

  template <type_traits::integral_c Int_type>
  constexpr inline dig_t operator-(Int_type arg) const noexcept {
    dig_t ret(*this);
    const dig_t tmp(normaliza<Int_type>(arg));
    ret -= tmp;
    return ret;
  }

  template <type_traits::integral_c Int_type>
  constexpr inline dig_t operator*(Int_type arg) const noexcept {
    dig_t ret(*this);
    const dig_t tmp(normaliza<Int_type>(arg));
    ret *= tmp;
    return ret;
  }

  template <type_traits::integral_c Int_type>
  constexpr inline dig_t operator/(Int_type arg) const noexcept {
    dig_t ret(*this);
    const dig_t cparg(normaliza<Int_type>(arg));
    if (cparg != dig_0())
      ret /= cparg;
    return ret;
  }

  template <type_traits::integral_c Int_type>
  constexpr inline dig_t operator%(Int_type arg) const noexcept {
    dig_t ret(*this);
    const dig_t cparg(normaliza<Int_type>(arg));
    if (cparg != dig_0())
      ret %= cparg;
    return ret;
  }

  /****************************************/
  /*									  */
  /*	     COMPLEMENTO BASE 			  */
  /*	      Y BASE MENOS 1			  */
  /*									  */
  /****************************************/

  /// EN BASE B, B-1-m_d ES EL COMPL_Bm1(m_d)
  constexpr inline
  dig_t operator!() const noexcept {
    return dig_t(ui_max() - m_d);
  }

  /// EN BASE B, B-m_d ES EL COMPL_B(m_d)
  constexpr inline
  dig_t operator-() const noexcept {
    return dig_t((m_d == 0) ? 0 : (B - m_d));
  }

  constexpr inline /// "C_Bm1" es identico a "operator!()"
  dig_t C_Bm1() const noexcept {
    return dig_t(ui_max() - m_d);
  }

  constexpr inline /// "C_B" es identico a "operator-()"
  dig_t C_B() const noexcept {
    return dig_t((m_d == 0) ? 0 : (B - m_d));
  }

  /****************************************************/
  /*				    							  */
  /*    MODIFICADORES COMPLEMENTO	    			  */
  /*				    							  */
  /****************************************************/

  constexpr inline const dig_t &mC_Bm1() noexcept {
    m_d = (ui_max() - m_d);
    return (*this);
  }

  constexpr inline const dig_t &mC_B() noexcept {
    (m_d == 0) ? (m_d) : (m_d = (B - m_d));
    return (*this);
  }

  /// dig_t<uchint,7> a,b,c;
  /// a = 5;
  /// b = 2;
  /// c = 0;
  /// !a == 1 is TRUE  a.C_Bm1() == 1 is TRUE
  /// !b == 4 is TRUE  b.C_Bm1() == 4 is TRUE
  /// !c == 6 is TRUE  c.C_Bm1() == 6 is TRUE
  /// -a == 2 is TRUE  a.C_B() == 2 is TRUE
  /// -b == 5 is TRUE  b.C_B() == 5 is TRUE
  /// -c == 0 is TRUE  c.C_B() == 0 is TRUE
  ///  a.mC_Bm1() == 1 is TRUE  a == 1 is TRUE
  ///  b.mC_Bm1() == 4 is TRUE  b == 4 is TRUE
  ///  c.mC_Bm1() == 6 is TRUE  c == 6 is TRUE
  ///  a.mC_B() 	== 2 is TRUE  a	== 2 is TRUE
  ///  b.mC_B() 	== 5 is TRUE  b	== 5 is TRUE
  ///  c.mC_B() 	== 0 is TRUE  c	== 0 is TRUE

  /**********************************/
  /*                            	*/
  /*   	NULO Y MAXIMO         	  	*/
  /*                            	*/
  /**********************************/

  constexpr inline
  bool is_0() const noexcept { return (m_d == ui_0()); }

  constexpr inline
  bool is_1() const noexcept { return (m_d == ui_1()); }

  constexpr inline
  bool is_0or1() const noexcept {
    return ((m_d == ui_0()) || (m_d == ui_1()));
  }

  constexpr inline bool
  is_not_1() const noexcept { return (m_d != ui_1()); }

  constexpr inline bool
  is_not_0() const noexcept { return (m_d != ui_0()); }

  constexpr inline
  bool is_not_0or1() const noexcept { return (!is_0or1()); }

  constexpr inline
  bool is_Bm1() const noexcept { return (m_d == ui_Bm1()); }

  constexpr inline
  bool is_not_Bm1() const noexcept {
    return (m_d != ui_Bm1());
  }

  constexpr inline
  bool is_Bm1orBm2() const noexcept {
    return (is_Bm1() || is_Bm2());
  }

  constexpr inline
  bool is_not_Bm1orBm2() const noexcept {
    return (is_not_Bm1() && is_not_Bm2());
  }

  constexpr inline
  bool is_Bm2() const noexcept { return (m_d == ui_Bm2()); }

  constexpr inline
  bool is_not_Bm2() const noexcept {
    return (m_d != ui_Bm2());
  }

  constexpr inline
  bool is_not_maxormin() const noexcept {
    return (is_not_0() && is_not_Bm1());
  }

  constexpr inline
  bool is_maxormin() const noexcept {
    return (is_0() || is_Bm1());
  }

  constexpr inline
  bool is_far_maxormin() const noexcept {
    if constexpr (B == 2u) {
      return false;
    } else {
      return (is_not_0() && is_not_Bm1() && is_not_1() && is_not_Bm2());
    }
  }

  constexpr inline
  bool is_near_maxormin() const noexcept {
    if constexpr (B == 2u) {
      return true;
    } else {
      return (is_0() || is_Bm1() || is_1() || is_Bm2());
    }
  }

  /********************************/
  /*							  */
  /* 	     VARIOS CASTS		  */
  /*							  */
  /********************************/

  /// TIENE QUE DEVOLVER STD::STRING
private:
  constexpr inline std::string num_to_string() const noexcept {
    const std::int64_t data_member = static_cast<std::int64_t>(this->m_d);
    std::ostringstream fmtr_obj;
    fmtr_obj << data_member;
    const std::string ret{fmtr_obj.str()};
    return ret;
  }

  static constexpr inline std::string radix_str() noexcept {
    constexpr std::int64_t radix = static_cast<std::int64_t>(B);
    std::ostringstream fmtr_obj;
    fmtr_obj << radix;
    const std::string ret{"B" + fmtr_obj.str()};
    return ret;
  }

public:
  constexpr inline std::string to_string() const noexcept {
    const std::string num{this->num_to_string()};
    const std::string ret{"dig#" + num + "#" + radix_str()};
    return ret;
  }
};

/************************************/
/*                                  */
/*         ISTREAM Y OSTREAM        */
/*                                  */
/************************************/

template <std::uint64_t Base>
  requires(Base > 1)
std::istream &operator>>(std::istream &is, dig_t<Base> &arg) {
  using dig_t = dig_t<Base>;
  using UINT_T = dig_t::UINT_T;
  using SIG_UINT_T = dig_t::SIG_UINT_T;
  enum estado_e { e0, e1, e2, e3, e4, e5, e6, e7, e8 };

  std::string sds;
  std::string num_dig;
  std::string num_base;

  estado_e est_act = e0;
  SIG_UINT_T indice = 0;
  SIG_UINT_T numero_base_recogido = 0;
  UINT_T numero = 0;

  char c;
  is >> sds;
  do {
    c = sds[indice];
    switch (est_act) {
    case e0:
      if (c == 'd') {
        est_act = e1;
      }
      break;
    case e1:
      if (c == '#') {
        est_act = e2;
      } else {
        est_act = e0;
      }
      break;
    case e2:
      if ((c <= '9') and (c >= '0')) {
        est_act = e3;
        num_dig.push_back(c - '0');
      } else {
        est_act = e0;
        num_dig.clear();
      }
      break;
    case e3:
      if ((c <= '9') and (c >= '0'))
        num_dig.push_back(c - '0');
      else if (c == '#')
        est_act = e4;
      else {
        est_act = e0;
        num_dig.clear();
      }
      break;
    case e4:
      if (c == 'B')
        est_act = e5;
      else {
        est_act = e0;
        num_dig.clear();
      }
      break;
    case e5:
      if ((c <= '9') and (c >= '0')) {
        est_act = e6;
        num_base.push_back(c - '0');
      } else {
        est_act = e0;
        num_dig.clear();
        num_base.clear();
      }
      break;
    case e6:
      if ((c <= '9') and (c >= '0'))
        num_base.push_back(c - '0');
      else if ((c == ' ') || (c == '\0'))
        est_act = e7;
      break;
    case e7:
      if ((c != ' ') || (c != '\0')) {
        est_act = e0;
        num_dig.clear();
        num_base.clear();
      }
      break;
    case e8:
    default:
      break;
    }
    ++indice;
    if (est_act == e7) {
      for (SIG_UINT_T k = 0; k < num_base.size(); ++k) {
        numero_base_recogido *= 10;
        numero_base_recogido += num_base[k];
      }
      if (numero_base_recogido != Base) {
        est_act = e0;
        num_dig.clear();
        num_base.clear();
      } else
        est_act = e8;
    }
  } while (est_act != e8);

  for (SIG_UINT_T k = 0; k < num_dig.size(); ++k) {
    numero *= 10;
    numero += num_dig[k];
  }
  numero %= Base;
  arg = dig_t(numero);
  return is;
}

template <std::uint64_t Base>
  requires(Base > 1)
std::ostream &operator<<(std::ostream &os, dig_t<Base> arg) {
  os << "d#" << static_cast<std::int64_t>(arg()) << "#B"
     << static_cast<std::int64_t>(Base);
  return os;
}

} // namespace NumRepr
#endif // DIG_T__HPP___INCLUDED
