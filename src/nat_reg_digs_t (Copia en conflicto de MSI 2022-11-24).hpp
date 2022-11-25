#ifndef  NAT_REG_DIGS_T_HPP_INCLUDED
#define NAT_REG_DIGS_T_HPP_INCLUDED

#include "dig_t.hpp"
#include "utilities.hpp"

namespace NumRepr {

using type_traits::allowable_base_type_c;
using type_traits::suitable_base;

template<allowable_base_type_c UINT_T,UINT_T B,size_t L>
	requires (suitable_base<UINT_T,B>() && (L>0))
struct nat_reg_digs_t {

	using SIG_UINT_T 			= typename type_traits::sig_UInt_for_UInt_t<UINT_T>;
	using SIG_SINT_T 			= typename type_traits::sig_SInt_for_UInt_t<UINT_T>;

	using dig_t 					= dig_t<UINT_T,B>;

	template<size_t N>
		requires (N>0)
	using base_N_t      	= std::array<dig_t,N>;
	using base_t					= base_N_t<L>;

	template<binop_e op,size_t N>
	using res_base_N_op_t	=
				typename auxiliary_types::result_operation_t<base_N_t<N>,op,N>;
	template<binop_e op>
	using res_base_op_t		=
				typename auxiliary_types::result_operation_t<base_t,op,L>;

	template<size_t N>
		requires (N>0)
	using nat_reg_N_digs_t= nat_reg_digs_t<UINT_T,B,N>;

	template<binop_e op,size_t N>
	using res_N_op_t 			=
				typename auxiliary_types::result_operation_t<nat_reg_N_digs_t<N>,op,N>;
	template<binop_e op>
	using res_op_t 				=
				typename auxiliary_types::result_operation_t<nat_reg_digs_t,op,L>;

	template<size_t N>
		requires (N>0)
	using reg_ints_t			= typename std::array<UINT_T,N>;
	template<size_t N>
		requires (N>0)
	using reg_suints_t		= typename std::array<SIG_UINT_T,N>;
	template<size_t N>
		requires (N>0)
	using reg_ssints_t		= typename std::array<SIG_SINT_T,N>;

private:
	base_t m_dc;

public :

	static consteval dig_t 				dig_0()			noexcept
	{return dig_t::dig_0();}
	static consteval dig_t 				dig_1()			noexcept
	{return dig_t::dig_1();}
	static consteval dig_t 				dig_Bm1()		noexcept
	{return dig_t::dig_Bm1();}
	static consteval dig_t 				dig_max()		noexcept
	{return dig_t::dig_max();}
	static consteval dig_t 				dig_Bm2()		noexcept
	{return dig_t::dig_Bm2();}
	static consteval dig_t 				dig_submax()noexcept
	{return dig_t::dig_submax();}
	static consteval UINT_T 			ui_0()			noexcept
	{return dig_t::ui_0();}
	static consteval UINT_T 			ui_1() 			noexcept
	{return dig_t::ui_1();}
	static consteval UINT_T 			ui_Bm1() 		noexcept
	{return B-1;}
	static consteval UINT_T 			ui_B() 		  noexcept
	{return B;}
	static consteval UINT_T 			ui_submax()	noexcept
	{return dig_t::ui_submax();}
	static consteval UINT_T 			ui_max() 		noexcept
	{return dig_t::ui_max();}
	static consteval SIG_UINT_T		sui_0()			noexcept
	{return dig_t::sui_0();}
	static consteval SIG_UINT_T		sui_1() 		noexcept
	{return dig_t::sui_1();}
	static consteval SIG_UINT_T 	sui_Bm1() 	noexcept
	{return dig_t::sui_B()-1;}
	static consteval SIG_UINT_T		sui_B() 		noexcept
	{return dig_t::sui_B();}
	static consteval SIG_UINT_T 	sui_Bp1() 	noexcept
	{return dig_t::sui_B()+1;}

	/// PARA EL TIPO-TEMPLATE BASE_N_T OBTENEMOS CONSTANTES INMEDIATAS
	/// TENEMOS CUIDADO DE CREAR UN RVALUE TEMPORAL
	template<size_t N>
		requires (N>=0)
	static consteval
	base_N_t<N> 	regd_base_N_0()    noexcept {
		base_N_t<N> ret{};
		for(auto& dig : ret) {
			dig = dig_0();
		}
		return ret;
	}
	template<size_t N>
		requires (N>=0)
	static consteval
	base_N_t<N>		regd_base_N_1()    noexcept {
		base_N_t<N> ret{regd_base_N_0<N>()};
		ret[0] = dig_1();
		return ret;
	}
	template<size_t N>
		requires (N>=0)
	static consteval
	base_N_t<N>		regd_base_N_Bm1()  noexcept {
		base_N_t<N> ret{regd_base_N_0<N>()};
		ret[0] = dig_Bm1();
		return ret;
	}
	template<size_t N>
		requires (N>=0)
	static consteval
	base_N_t<N>		regd_base_N_B() 	noexcept {
		base_N_t<N> ret{regd_base_N_0<N>()};
		ret[1] = dig_1();
		return ret;
	}
	template<size_t N,size_t n>
		requires ((n>=0)&&(n < N))
	static consteval
	base_N_t<N>	regd_base_N_pow_n_B()	noexcept {
		base_N_t<N> ret{regd_base_N_0<N>()};
		ret[n] = dig_1();
		return ret;
	}
	template<size_t N,size_t n>
		requires ((n>=0)&&(n < N))
	static consteval
	base_N_t<N>	regd_base_N_pow_n_B_m1() noexcept	{
		base_N_t<N> ret{};
		for(size_t ix{0} ; ix < n ; ++ix) {
			ret[ix] = dig_Bm1();
		}
		for(size_t ix{n} ; ix < N ; ++ix) {
			ret[ix] = dig_0();
		}
		return ret;
	}
	/// IDEM QUE ANTES PERO CON EL TIPO BASE_T ESPECIALIZANDO AL TIPO BASE_N_T<L>
	/// DONDE BASE_T == BASE_N_T<L>
	/// TENEMOS CUIDADO DE CREAR UN RVALUE TEMPORAL
	static consteval
	base_t regd_base_0() noexcept {
		return base_t{regd_base_N_0<L>()};
	}
	static consteval
	base_t	regd_base_1() noexcept {
		return base_t{regd_base_N_1<L>()};
	}
	static consteval
	base_t	regd_base_Bm1() noexcept {
		return base_t{regd_base_N_Bm1<L>()};
	}
	static consteval
	base_t	regd_base_B() noexcept {
		return base_t{regd_base_N_B<L>()};
	}
	static consteval
	base_t	regd_base_pow_n_B()	noexcept {
		return base_t{regd_base_N_pow_n_B<L>()};
	}
	static consteval
	base_t	regd_base_pow_n_B_m1() noexcept	{
		return base_t{regd_base_N_pow_n_B_m1<L>()};
	}
	/// FUNCIONES INMEDIATAS QUE NOS DAN CONSTANTES DEL TIPO DE LA ACTUAL CLASE
	/// SE HACE CREANDO UNA VARIABLE RVALUE TEMPORAL CON LA FUNCION HOMOLOGA PARA
	/// BASE_T
	static consteval
	nat_reg_digs_t 	regd_0()    noexcept {
		return nat_reg_digs_t{regd_base_0()};
	}
	static consteval
	nat_reg_digs_t		regd_1()    noexcept {
		return nat_reg_digs_t{regd_base_1()};
	}
	static consteval
	nat_reg_digs_t		regd_Bm1()  noexcept {
		return nat_reg_digs_t{regd_base_Bm1()};
	}
	static consteval
	nat_reg_digs_t		regd_B() 	noexcept {
		return nat_reg_digs_t{regd_base_B()};
	}
	template<size_t n>
		requires ((n>=0)&&(n < L))
	static consteval
	nat_reg_digs_t		regd_pow_n_B()	noexcept {
		return nat_reg_digs_t{regd_base_pow_n_B()};
	}
	template<size_t n>
		requires ((n>=0)&&(n < L))
	static consteval
	nat_reg_digs_t		regd_pow_n_B_m1() noexcept	{
		return nat_reg_digs_t{regd_base_pow_n_B_m1()};
	}
	/// ARRAYS DE ENTEROS (CONSTANTES EN TIEMPO DE COMPILACION INMEDIATAS)
	static consteval
	reg_ints_t<L> 	regi_0() 					noexcept	{
		reg_ints_t<L> ret{};
		for(auto& digint : ret) {
			digint = dig_0()();
		}
		return ret;
	}

	static consteval
	reg_ints_t<L>		regi_1() 				noexcept	{
		reg_ints_t<L> ret{regi_0()};
		ret[0] = dig_1()();
		return ret;
	}

	static consteval
	reg_ints_t<L>		regi_Bm1() 				noexcept	{
		reg_ints_t<L> ret{regi_0()};
		ret[0] = dig_Bm1()();
		return ret;
	}

	static consteval
	reg_ints_t<L>		regi_B() 				noexcept  {
		reg_ints_t<L> ret{regi_0()};
		ret[1] = dig_1()();
		return ret;
	}

	template<size_t n>
		requires ((n>=0)&&(n < L))
	static consteval
	reg_ints_t<L>		regi_pow_n_B()		noexcept	{
		reg_ints_t<L> ret{regi_0()};
		ret[n] = dig_1()();
		return ret;
	}

	template<size_t n>
		requires ((n>=0)&&(n < L))
	static consteval
	reg_ints_t<L>	regi_pow_n_B_m1()	noexcept	{
		reg_ints_t<L> ret{};
		for(size_t ix{0} ; ix < n ; ++ix) {
			ret[ix] = dig_t(B-1)();
		}
		for(size_t ix{n} ; ix < L ; ++ix) {
			ret[ix] = dig_t(0)();
		}
		return ret;
	}

				/************************************/
				/*																	*/
				/*    CONSTRUIR NUMERO	  					*/
				/*																	*/
				/************************************/

public:

	/// CONSTRUCTOR POR DEFECTO
	consteval inline
	nat_reg_digs_t()
	noexcept : m_dc{dig_0()} {}
	/// CONSTRUCTOR POR LISTA DE DIGITOS
	constexpr inline
	nat_reg_digs_t(const std::initializer_list<dig_t> & arg)
	noexcept : m_dc{arg} {}
	/// CONSTRUCTOR POR ARGUMENTOS DIGITOS SIN LIMITE: DEDUCE EL TIPO
	template<typename ... Ts>
		requires (std::is_same_v<Ts,dig_t>&&...)
	constexpr inline
	nat_reg_digs_t(const Ts &... args)
	noexcept : m_dc{(utility::pack2array<Ts...>{})(args...)} {}

private:

	/// BEGIN : CONSTRUCTOR COPIA/MOVIMIENTO DESDE UN ARRAY DE DIGITOS
	/// FUNCION DELEGADA PARA COPIA DE UN ARRAY DEL MISMO TAMANO
	/// O UN TAMANO CUALQUIERA "N"
	template<size_t N>
		requires (N>0)
	constexpr inline
	void copy_arg_N(const base_N_t<N> & arg) noexcept {
		///< Z < W or Z == W
		constexpr auto Z{std::min(N,L)};
		constexpr auto W{std::max(N,L)};
		if constexpr (Z==L) {
			for(size_t ix{0} ; ix < Z ; ++ix)
				m_dc[ix]=arg[ix];
		}
		else if constexpr (W==L) {
			for(size_t ix{0} ; ix < Z ; ++ix)
				m_dc[ix]=arg[ix];
			for(size_t ix{Z} ; ix < W ; ++ix)
				m_dc[ix]=dig_0();
		}
		else {
			m_dc=arg;
		}
	}

	/// FUNCION DELEGADA PARA MOVER DE UN ARRAY DEL MISMO TAMANO
	/// O UN TAMANO CUALQUIERA "N"
	template<size_t N>
		requires (N>0)
	constexpr inline
	void move_arg_N(base_N_t<N>&& arg) noexcept {
		///< Z < W or Z == W
		constexpr auto Z{std::min(N,L)};
		constexpr auto W{std::max(N,L)};
		if constexpr (Z==L) {
			for(size_t ix{0} ; ix < Z ; ++ix)
				m_dc[ix]=std::move(arg[ix]);
		}
		else if constexpr (W==L) {
			for(size_t ix{0} ; ix < Z ; ++ix)
				m_dc[ix]=std::move(arg[ix]);
			for(size_t ix{Z} ; ix < W ; ++ix)
				m_dc[ix]=std::move(dig_0());
		}
		else {
      m_dc=std::move(arg);
		}
	}

	/// FUNCION DELEGADA PARA COPIA DE UN NAT_REG_N_DIGS_T DEL MISMO TAMANO
	/// O UN TAMANO CUALQUIERA "N"
	template<size_t N>
		requires (N>0)
	constexpr inline
	void copy_arg_N(const nat_reg_n_digs_t<N> & arg) noexcept {
		m_dc = arg.const_ref_data();
	}

	/// FUNCION DELEGADA PARA MOVER DE UN NAT_REG_N_DIGS_T DEL MISMO TAMANO
	/// O UN TAMANO CUALQUIERA "N"
	template<size_t N>
		requires (N>0)
	constexpr inline
	void move_arg_N(nat_reg_n_digs_t<N>&& arg) noexcept {
		m_dc = std::move(arg.const_ref_data());
	}

public:

	/// CONSTRUCTOR COPIA DESDE UN ARRAY DE DIGITOS
	template<size_t N>
		requires (N>0)
	constexpr inline
	nat_reg_digs_t(const base_N_t<N> & arg)
	noexcept : m_dc{copy_arg_N<N>(arg)} {}

	/// CONSTRUCTOR MOVIMIENTO DESDE UN ARRAY DE DIGITOS
	template<size_t N>
		requires (N>0)
	constexpr inline
	nat_reg_digs_t(const base_N_t<N> && arg)
	noexcept : m_dc{move_arg_N<N>(std::move(arg))} {}
	/// END   : CONSTRUCTOR COPIA/MOVIMIENTO DESDE UN ARRAY DE DIGITOS

private :

	/// FUNCION DE NORMALIZACION A LA BASE B DE UN ARGUMENTOS
	/// EN UN PACK DE ENTEROS CUALQUIERA
	template<type_traits::integral_c ... Ints_type>
		requires ((sizeof...(Ints_type)) <= L)
	static constexpr inline
	base_t normalize(Ints_type ... digits_pow_i)
	noexcept {
		///< CREA UN STD_ARRAY DEL TIPO INT PASADO POR ARGUMENTOS
		///< DE TAMANO EL PACK DE ARGUMENTOS PASADO (MENOR O IGUAL QUE L)
		using pack_type 	= typename utility::pack2array<Ints_type...>;
		///< DEVUELVE EL TIPO INTERNO DE ELEMENTO DEL ARRAY ANTERIOR
		///< [UN TIPO ENTERO]
		using unique_type = typename pack_type::elem_type;
		///< DEVUELVE EL TAMANO DEL ARRAY ANTERIOR (TAMAÑO <= L)
		consteval size_t pack_sz{pack_type::pack_size()};
		///< ELIGE ENTRE CUATRO TIPOS DE ENTEROS SEGUN TENGAN SIGNO O NO Y SU TAMANO
		///< SEA MAYOR O MENOR QUE EL PROPIO DE LA BASE UINT_T
		///< 		TIPO PROPIO ES : 									UINT_T
		///< 		TIPO PASADO COMO ARGUMENTO ES :  	UNIQUE_TYPE
		///< 		LOS TIPOS PASADOS EN LOS ARGUMENTOS HAN DE SER IGUALES ENTRE SI
		///< PARA EL INTERROGANTE CONDICIONAL UTILIZAMOS
		///< 		UNSIGNED_INTEGRAL_C<S>		PRIMERA PREGUNTA O MAS EXTERIOR
		///< 		IS_UNISGNED_SZ_GT_V<T,S>	PREGUNTAS SEGUNDAS O MAS INTERIORES
		///< PARA ELEGIR EL TIPO APROPIADO EN CADA CASO USAMOS
		///<		SIG_UINT_FOR_UINT_T<UINT_T>
		///<		SIG_UINT_FOR_UINT_T<UNIQUE_TYPE>
		///<		SIG_UINT_FOR_UINT_T<UINT_T>
		///<		SIG_UINT_FOR_SINT_T<UNIQUE_TYPE>
		using NumRepr::type_traits;
		using SUInt_type =
			typename std::conditional_t
			<
					unsigned_integral_c<unique_type>
					,typename std::conditional_t<
						is_unsigned_sz_gt_v<UINT_T,unique_type>,
							sig_UInt_for_UInt_t<UINT_T>,
							sig_UInt_for_UInt_t<unique_type>
					 >
					,typename std::conditional_t<
						is_unsigned_sz_gt_v<UINT_T,sig_UInt_for_SInt_t<unique_type>>,
							sig_UInt_for_UInt_t<UINT_T>,
							sig_UInt_for_SInt_t<unique_type>
					>
			>;
		std::array<SUInt_type,L> ret_array{digits_pow_i...};
		base_t ret;
		for(size_t ix{0} ; ix < pack_sz ; ++ix) {
			ret[ix] = dig_t(ret_array[ix]);
		}
		for(size_t ix{pack_sz} ; ix < L ; ++ix) {
			ret[ix] = dig_t(0);
		}
		return ret;
	}

public:

	/// CONSTRUCTOR COPIA DESDE ARGUMENTOS ENTEROS SIN LIMITE : DEDUCE EL TIPO
	template<type_traits::integral_c ... Ints_type>
	constexpr inline nat_reg_digs_t(Ints_type ... dig_pow_i) noexcept :
		m_dc{normalize<Ints_type...>(dig_pow_i...)} {}

	/// CONSTRUCTOR COPIA POR REFERENCIA CONSTANTE
	template<size_t N>
		requires (N>0)
	constexpr inline nat_reg_digs_t(const nat_reg_N_digs_t<N> & arg) noexcept :
		m_dc{copy_arg_N<N>(arg.const_ref_data())} {}

	/// CONSTRUCTOR POR MOVIMIENTO
	template<size_t N>
		requires (N>0)
	constexpr inline nat_reg_digs_t(nat_reg_N_digs_t<N> && arg) noexcept :
		m_dc{move_arg_N(std::move(*(arg.data())))} {}

	/// OPERACION ASIGNACION POR COPIA REFERENCIA CONST _NO_ COPIABLE DESDE BASE_N_T
	template<size_t N>
		requires (N>0)
	constexpr inline
	const nat_reg_digs_t & operator = (const base_N_t<N> & arg) noexcept
	{
		if (&(this->m_dc)!=(&arg))
			copy_arg_N<N>(arg);
		return (*this);
	}

	/// OPERACION ASIGNACION POR COPIA REFERENCIA DESDE BASE_N_T
	template<size_t N>
		requires (N>0)
	constexpr inline
	nat_reg_digs_t & operator = (base_N_t<N> & arg) noexcept
	{
		if (&(this->m_dc)!=(&arg))
			copy_arg_N<N>(arg);
		return (*this);
	}

	/// OPERACION ASIGNACION POR COPIA MOVIMIENTO DESDE BASE_N_T
	template<size_t N>
		requires (N>0)
	constexpr inline
	const nat_reg_digs_t & operator = (base_N_t<N>&& arg) noexcept
	{
		if (&(this->m_dc)!=(&arg))
			move_arg_N<N>(std::move(arg));
		return (*this);
	}

	/// OPERACION ASIGNACION POR COPIA REFERENCIA EN LA QUE SE PUEDE COPIAR
	template<size_t N>
		requires (N>0)
	constexpr inline
	nat_reg_digs_t & operator = (const nat_reg_N_digs_t<N> & arg) noexcept
	{
		if (this != &arg)
			(*this) = arg.const_ref_data();
		return (*this);
	}

	/// OPERACION ASIGNACION POR MOVIMIENTO
	template<size_t N>
		requires (N>0)
	constexpr inline
	nat_reg_digs_t & operator = (nat_reg_N_digs_t<N> && arg) noexcept
	{
		if (this != &arg)
			(*this) = std::move(*(arg.data()));
		return (*this);
	}

	/// OPERACION ASIGNACION POR COPIA EN LA QUE  _NO_  SE PUEDE COPIAR
	template<size_t N>
		requires (N>0)
	constexpr inline
	const nat_reg_digs_t & operator = (const nat_reg_N_digs_t<N> & arg) noexcept
	{
		if (this != &arg)
			(*this) = arg.const_ref_data();
		return (*this);
	}
private:
	template<size_t N>
		requires (N>0)
	static constexpr inline
	void set_0(base_N_t& arg) noexcept
	{
		for (dig_t& dig : arg)
			dig = dig_0();
	}

	template<size_t N>
		requires (N>0)
	static constexpr inline
	void set_1(base_N_t& arg) noexcept
	{
		arg[0].set_1();
		for (size_t ix{1} ; ix < N ; ++ix )
			arg[ix] = dig_0();
	}

	template<size_t N>
		requires (N>0)
	static constexpr inline
	void set_Bm1(base_N_t& arg) noexcept
	{
		arg[0].set_Bm1();
		for (size_t ix{1} ; ix < N ; ++ix )
			arg[ix] = dig_0();
	}

	template<size_t N>
		requires (N>0)
	static constexpr inline
	void set_dig(base_N_t& larg,dig_t d) noexcept
	{
		larg[0] = d;
		for (size_t ix{1} ; ix < N ; ++ix )
			larg[ix] = dig_0();
	}

	template<size_t N>
		requires (N>0)
	static constexpr inline
	void set_fill_dig(base_N_t& larg,dig_t d) noexcept
	{
		for (auto & elem : larg)
			elem = d;
	}

	template<size_t N>
		requires (N>0)
	static constexpr inline
	void set_fill_1(base_N_t& larg) noexcept
	{
		for (auto & elem : larg)
			elem.set_1();
	}

	template<size_t N>
		requires (N>0)
	static constexpr inline
	void set_fill_Bm1(base_N_t& larg) noexcept
	{
		for (auto & elem : larg)
			elem.set_Bm1();
	}

	/// OPERACION DE PONER A VALOR DIG_0 DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_N_T<N>
	template<size_t N,size_t N_i,size_t N_pf> 	// i  es inicio
																							// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= N)&&(N>0))
	static constexpr inline
	void set_interval_0(base_N_t<N>& larg) noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			larg[ix] = dig_0();
	}

	/// OPERACION DE PONER A VALOR DIG_Bm1 DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_N_T<N>
	template<size_t N,size_t N_i,size_t N_pf> 	// i  es inicio
																							// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= N)&&(N>0))
	static constexpr inline
	void set_interval_Bm1(base_N_t<N>& larg) noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			larg[ix] = dig_Bm1();
	}

	/// OPERACION DE PONER A VALOR DIG DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_N_T<N>
	template<size_t N,size_t N_i,size_t N_pf> 		// i  es inicio
																								// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= N)&&(N>0))
	static constexpr inline
	void set_interval_dig(base_N_t<N>& larg,dig_t dig) noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			m_dc[ix] = dig;
	}

	/// OPERACION DE PONER A VALOR DIG_0 DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_T
	/// ESPECIALIZACION PARA N==L
	template<size_t N_i,size_t N_pf> 	// i  es inicio
																		// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	static constexpr inline
	void set_interval_0(base_t& larg) noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			larg[ix] = dig_0();
	}

	/// OPERACION DE PONER A VALOR DIG_Bm1 DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_T
	/// ESPECIALIZACION PARA N==L
	template<size_t N_i,size_t N_pf> 	// i  es inicio
																		// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	static constexpr inline
	void set_interval_Bm1(base_t& larg) noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			larg[ix] = dig_Bm1();
	}

	/// OPERACION DE PONER A VALOR DIG DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_T
	/// ESPECIALIZACION PARA N==L
	template<size_t N_i,size_t N_pf> 	// i  es inicio
																		// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	static constexpr inline
	void set_interval_dig(base_t& larg,dig_t dig) noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			m_dc[ix] = dig;
	}

public:
	/// OPERACION DE LIMPIEZA A CERO DEL NAT_REG_DIGS_T
	constexpr inline
	void set_0() noexcept {
		set_0(m_dc);
	}

	/// OPERACION DE LIMPIEZA A B-1 DEL NAT_REG_DIGS_T
	constexpr inline
	void set_Bm1() noexcept {
		set_Bm1(m_dc);
	}

	/// OPERACION DE LIMPIEZA A VALOR DIG_T DEL NAT_REG_DIGS_T
	constexpr inline
	void set_dig(dig_t arg) noexcept {
		set_dig(m_dc,arg);
	}

	/// OPERACION DE PONER A VALOR DIG_0 EN [N_0 , N_1) DEL NAT_REG_DIGS_T
	template<size_t N_i,size_t N_pf> 	// i es inicio
																		// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	constexpr inline
	void set_interval_0() noexcept {
		set_interval_0<N_i,N_pf>(m_dc);
	}
	/// OPERACION DE PONER A VALOR DIG_Bm1 EN [N_0 , N_1) DEL NAT_REG_DIGS_T
	template<size_t N_i,size_t N_pf> 	// i es inicio
																		// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	constexpr inline
	void set_interval_Bm1() noexcept {
		set_interval_Bm1<N_i,N_pf>(m_dc);
	}
	/// OPERACION DE PONER A VALOR DIG EN [N_0 , N_1) DEL NAT_REG_DIGS_T
	template<size_t N_i,size_t N_pf> 	// i es inicio
																		// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	constexpr inline
	void set_interval_dig(dig_t dig) noexcept {
		set_interval_0<N_i,N_pf>(m_dc,dig);
	}

	/// OPERACION COPIA DESDE UN DIGITO (CONVERSION)
	constexpr inline
	nat_reg_digs_t & operator = (const dig_t & arg)
	noexcept {
		if ((&(this->m_dc[0]))!=(&arg)) {
			set_0();
			m_dc[0] = arg;
		}
		return (*this);
	}

	/// OPERACION COPIA DESDE UN ENTERO (CONVERSION A LA BASE B) A UN BASE_T
	template<type_traits::integral_c Int_Type>
	static constexpr inline
	const base_t& assign(base_t& larg,Int_Type arg) noexcept {
		using type_traits::maxbase();
		constexpr int128_t B_128t_v{static_cast<int128_t>(B)};
		constexpr bool puede_multiplicarse{
				(maxbase<int128_t>()/B_128t_v) > 0
		};
		if ((&larg)!=(&arg)) {
			int128_t creg_g{static_cast<int128_t>(arg)};
			int128_t BasePowIx{B_128t_v};
			for(size_t k{1u} ; k < L ; ++k) {
				if constexpr (puede_multiplicarse)
					BasePowIx *= B_128t_v;
				else
					break;
			}
			while (creg_g < 0) {
				creg_g += BasePowIx;
			}
			for(size_t k{0u} ; k < L ; ++k){
				larg[k] = dig_t(creg_g%B_128t_v);
				creg_g /= B_128t_v;
			}
		}
		return (*this);
	}

	/// OPERACION COPIA DESDE UN ENTERO (CONVERSION A LA BASE B)
	template<type_traits::integral_c Int_Type>
	constexpr inline nat_reg_digs_t & operator = (Int_Type arg) noexcept {
		assign(m_dc,arg);
		return (*this);
	}

private:
	/// STATIC BASE_N_T<N> CONCAT(BASE_N_T<N>)
	/// STATIC BASE_N_T<N+M> CONCAT(BASE_N_T<N>,BASE_N_T<M>)
	/// STATIC BASE_N_T<N+1> CONCAT(BASE_N_T<N>,DIG_T)
	/// STATIC BASE_N_T<1+M> CONCAT(DIG_T,BASE_N_T<M>)
	/// STATIC BASE_N_T<1> CONCAT(DIG_T)
	/// STATIC BASE_N_T<1+1> CONCAT(DIG_T,DIG_T)
	/// STATIC BASE_N_T<SIZEOF...(DIG_PACK)> CONCAT(DIG_T ... DIG_PACK) VARIADIC PACK

	/// STATIC BASE_N_T<N> CONCAT(BASE_N_T<N>)
	template<size_t N>
		requires (N>0)
	static constexpr inline
	base_N_t<N> concat(const base_N_t<N>& larg) noexcept
	{
		return std::move(base_N_t<N>{larg});
	}

	/// STATIC BASE_N_T<N+M> CONCAT(BASE_N_T<N>,BASE_N_T<M>)
	template<size_t N,size_t M>
		requires ((N>0)&&(M>0))
	static constexpr inline
	base_N_t<N+M> concat(const base_N_t<N>& larg,const base_N_t<M>& rarg) noexcept
	{
		base_N_t<N+M> ret;
		for(size_t ix{0} ; ix < N ; ++ix)
			ret[ix] = larg[ix];
		for(size_t ix{N} ; ix < M ; ++ix)
			ret[ix] = rarg[ix];
		return std::move(ret);
	}

	/// STATIC BASE_N_T<N+1> CONCAT(BASE_N_T<N>,DIG_T)
	template<size_t N>
		requires (N>0)
	static constexpr inline
	base_N_t<N+1> concat(const base_N_t<N>& larg,dig_t rarg) noexcept
	{
		base_N_t<N+1> ret;
		for(size_t ix{0} ; ix < N ; ++ix)
			ret[ix] = larg[ix];
		ret[N] = rarg;
		return std::move(ret);
	}

	/// STATIC BASE_N_T<1+M> CONCAT(DIG_T,BASE_N_T<M>)
	template<size_t M>
		requires (M>0)
	static constexpr inline
	base_N_t<1+M> concat(dig_t larg, const base_N_t<M>& rarg) noexcept
	{
		base_N_t<1+M> ret;
		ret[0] = larg;
		for(size_t ix{1} ; ix < N+1 ; ++ix)
			ret[ix] = rarg[ix-1];
		return std::move(ret);
	}

	/// STATIC BASE_N_T<1> CONCAT(DIG_T)
	static constexpr inline
	base_N_t<1> concat(dig_t larg) noexcept
	{
		return std::move(base_N_t<1>{larg});
	}

	/// STATIC BASE_N_T<1+1> CONCAT(DIG_T,DIG_T)
	static constexpr inline
	base_N_t<2> concat(dig_t larg,dig_t rarg) noexcept
	{
		base_N_t<2> ret;
		ret[0] = larg;
		ret[1] = rarg;
		return std::move(ret);
	}

	/// STATIC BASE_N_T<SIZEOF...(DIG_PACK)> CONCAT(DIG_T,DIG_T ... DIG_PACK) VARIADIC
	template<typename T0,typename ... Ts>
		requires (((std::is_same_v<Ts,dig_t>)&&...)&&(std::is_same_v<T,dig_t>))
	static constexpr inline
	base_N_t<1+(sizeof ... (Ts))> concat(T0 dig0,Ts ... dig_pack) noexcept {
		return concat(dig_0,dig_pack...);
	}

	/// STATIC BASE_N_T<N+1+(SIZEOF...(DIG_PACK))> CONCAT(BASE_N_T<N>,DIG_T,DIG_T ... DIG_PACK) VARIADIC
	template<size_t N,typename T,typename ... Ts>
		requires (((std::is_same_v<Ts,dig_t>)&&...)&&(std::is_same_v<T,dig_t>)&&(N>0))
	static constexpr inline
	base_N_t<N+1+(sizeof ... (Ts))> concat(base_N_t<N> larg,T dig,Ts ... dig_pack) noexcept {
		return concat(larg,concat(dig,dig_pack...));
	}

	/// STATIC BASE_N_T<M+1+(SIZEOF...(DIG_PACK))> CONCAT(DIG_T,DIG_T ... DIG_PACK,BASE_N_T<M>) VARIADIC
	template<size_t M,typename T,typename ... Ts>
		requires (((std::is_same_v<Ts,dig_t>)&&...)&&(std::is_same_v<T,dig_t>)&&(M>0))
	static constexpr inline
	base_N_t<M+1+(sizeof ... (Ts))> concat(T dig,Ts ... dig_pack,base_N_t<M> rarg) noexcept {
		return concat(concat(dig,dig_pack...),rarg);
	}

	/// STATIC BASE_N_T<SIZE_T N,SIZE_T ... N_PACK> CONCAT(BASE_N_T<N> LARG,BASE_N_T<N_PACK> ... RARG_PACK) VARIADIC
	template<size_t N,size_t ... N_pack>
		requires ((N>0)&&((N_pack>0)&&...))
	static constexpr inline
	base_N_t<N+(...+(N_pack))> concat(base_N_t<N> larg,base_N_t<N_pack...> ... rarg_pack) noexcept
	{
		return concat(larg,rarg_pack...);
	}

	/// TAKE A SUBREGISTER OF A REGISTER OF DIGITS
	template<size_t N,size_t ibegin,size_t iend>
		requires ((N>0)&&(iend <= N)&&(ibegin < N)&&(ibegin != iend))
	static constexpr inline
	base_N_t<std::abs<size_t>(iend-ibegin)> subregister(const base_N_t<N> & arg) noexcept
	{
		if constexpr (ibegin < iend) {
			base_N_t<iend-ibegin> ret;
			for(size_t ix{ibegin} ; ix < iend ; ++ix) {
				ret[ix-ibegin] = arg[ix];
			}
			return std::move(ret);
		}
		else {
			nat_reg_N_digs_t<iend-ibegin> ret;
			for(int32_t ix{iend} ; ix > ibegin-1 ; --ix) {
				ret[ix-ibegin] = arg[L-1-ix];
			}
			return std::move(ret);
		}
	}


public:

	/// FORMACION DE UN REG_M_DIGS_T<M> DESDE EL THIS REG_DIGS_T (L)
	/// Y REG_N_DIGS_T<N> EN SUS DOS FORMAS: (*THIS)SEGUIDO(ARG) Y
	/// (ARG)SEGUIDO(*THIS) : OPERACIONES DE CONCATENACION

	/// FORMACION DE UN REG_M_DIGS_T<M> DESDE EL THIS REG_DIGS_T (L)
	/// Y REG_N_DIGS_T<N> EN SUS DOS FORMAS: (*THIS)SEGUIDO(ARG) Y
	/// (ARG)SEGUIDO(*THIS) : OPERACIONES DE CONCATENACION

	/// NAT_REG_N_T<L+M> NAT_REG_T::CAT(NAT_REG_N_T<M>)
	/// NAT_REG_N_T<L+M> NAT_REG_T::CAT_INV(NAT_REG_N_T<M>)
	/// NAT_REG_N_T<L+1> NAT_REG_T::CAT(DIG_T)
	/// NAT_REG_N_T<L+1> NAT_REG_T::CAT_INV(DIG_T)

	/// SUBREPR => SUB REPRESENTACION

	template<size_t N>
		requires (N>0)
	constexpr inline
	nat_reg_N_digs_t<N+L> cat(const nat_reg_N_digs_t<N> & arg) const noexcept
	{
		return (concat<L,N>(m_dc,arg));
	}

	constexpr inline
	nat_reg_N_digs_t<L+1> cat(dig_t arg) const
	noexcept {
		return (concat<L>(m_dc,arg));
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	nat_reg_N_digs_t<N+L> cat_inv(const nat_reg_N_digs_t<N> & arg) const noexcept
	{
		return (concat<N,L>(arg,m_dc));
	}

	constexpr inline
	nat_reg_N_digs_t<L+1> cat_inv(dig_t arg) const noexcept
	{
		return (concat<L>(arg,m_dc));
	}

	template<size_t ibegin,size_t iend>
		requires ((iend <= L)&&(ibegin < iend))
	constexpr inline
	nat_reg_N_digs_t<iend-ibegin> subrepr() const noexcept
	{
		return subregister<L,ibegin,iend>(m_dc);
	}

				/****************************************/
				/*							      	    						*/
				/*       Algunas Conversiones    				*/
				/*							      									*/
				/****************************************/

	template<type_traits::integral_c Int_Type>
	constexpr inline operator Int_Type() const noexcept {
		using type_traits::maxbase();
		uint64_t retInt{0};
		uint64_t BasePowIx{1};
		for(size_t k{0} ; k < L ; ++k) {
			retInt += m_dc[k]*BasePowIx;
			BasePowIx *= B;
			if(	(k+1 < L)
						&&
					( maxbase<Int_Type>() < (retInt+(m_dc[k+1]*BasePowIx)) )	)
			{	return retInt; }
		}
		return retInt;
	}

				/****************************************************/
				/*							    																*/
				/* FUNCIONES COMPARATIVAS BASICAS										*/
				/*							    																*/
				/****************************************************/

private:

	template<size_t N>
		requires (N>0)
	static inline constexpr
	bool is_0(const base_N_t<N> & arg) noexcept
	{
		for(elem : arg) {
			if(elem.is_not_0())
				return false;
		}
		return true;
	}

	template<size_t N>
		requires (N>0)
	static inline constexpr
	bool is_1(const base_N_t<N> & arg) noexcept
	{
		if (arg[0].is_not_1())
			return false;
		for(size_t ix{1} ; ix<N ; ++ix) {
			if(arg[ix].is_not_0())
				return false;
		}
		return true;
	}

	template<size_t N>
		requires (N>0)
	static inline constexpr
	bool is_Bm1(const base_N_t<N> & arg) noexcept
	{
		if (arg[0].is_not_Bm1())
			return false;
		for(size_t ix{1} ; ix<N ; ++ix) {
			if(arg[ix].is_not_0())
				return false;
		}
		return true;
	}

	template<size_t N>
		requires (N>0)
	static inline constexpr
	bool is_B(const base_N_t<N> & arg) noexcept
	{
		if (arg[0].is_not_0())
			return false;
		if (arg[1].is_not_1())
			return false;
		for(size_t ix{2} ; ix<N ; ++ix) {
			if(arg[ix].is_not_0())
				return false;
		}
		return true;
	}

	template<size_t N>
		requires (N>0)
	static inline constexpr
	bool is_Bp1(const base_N_t<N> & arg) noexcept
	{
		if (arg[0].is_not_1())
			return false;
		if (arg[1].is_not_1())
			return false;
		for(size_t ix{2} ; ix<N ; ++ix) {
			if(arg[ix].is_not_0())
				return false;
		}
		return true;
	}

	template<size_t N,size_t n>
		requires ((n<N) && (N>0))
	static inline constexpr
	bool is_B_pow_m1(const base_N_t<N> & arg) noexcept
	{
		if constexpr (n == 0) {
			return is_0(arg);
		}
		else if constexpr (n == 1) {
			return is_Bm1(arg);
		}
		else if constexpr (n == 2) {
			if (arg[1].is_not_Bm1() || arg[0].is_not_Bm1())
				return false;
			for(size_t ix{2} ; ix < N ; ++ix)
				if (arg[ix].is_not_0())
					return false;
			return true;
		}
		else {
			for(size_t ix{0} ; ix < n ; ++ix)
				if (arg[ix].is_not_Bm1())
					return false;
			for(size_t ix{n} ; ix < N ; ++ix)
				if (arg[ix].is_not_0())
					return false;
			return true;
		}
	}

	template<size_t N,size_t n>
		requires ((n<N) && (N>0))
	static inline constexpr
	bool is_B_pow(const base_N_t<N> & arg) noexcept
	{
		if constexpr (n == 0) {
			if (arg[0].is_not_1())
				return false;
			for (size_t ix{1} ; ix < N ; ++ix)
				if (arg[ix].is_not_0())
					return false;
			return true;
		}
		else if constexpr (n == 1) {
			if (arg[0].is_not_0())
				return false;
			if (arg[1].is_not_1())
				return false;
			for (size_t ix{2} ; ix < N ; ++ix)
				if (arg[ix].is_not_0())
					return false;
			return true;
		}
		else if constexpr (n == 2) {
			if (arg[0].is_not_0() || arg[1].is_not_0())
				return false;
			if (arg[2].is_not_1())
				return false;
			for (size_t ix{3} ; ix < N ; ++ix)
				if (arg[ix].is_not_0())
					return false;
			return true;
		}
		else {
			for (size_t ix{0} ; ix < n ; ++ix)
				if (arg[ix].is_not_0())
					return false;
			if (arg[n].is_not_1())
				return false;
			for (size_t ix{n+1} ; ix < N ; ++ix)
				if (arg[ix].is_not_0())
					return false;
			return true;
		}
	}

	template<size_t N>
		requires (N>0)
	static inline constexpr
	bool is_filled_of_1(const base_N_t<N> & arg) {
		for (size_t ix{0} ; ix < N ; ++ix)
			if (arg[ix].is_not_1())
				return false;
		return true;
	}

	template<size_t N>
		requires (N>0)
	static inline constexpr
	bool is_filled_of_Bm1(const base_N_t<N> & arg) {
		for (size_t ix{0} ; ix < N ; ++ix)
			if (arg[ix].is_not_Bm1())
				return false;
		return true;
	}

	template<size_t N,size_t n,dig_t d>
		requires ((n>0) && (n<L) && (N>0))
	static inline constexpr
	bool is_filled_of(const base_N_t<N> & arg) {
		for (size_t ix{0} ; ix < N ; ++ix)
			if (arg[ix] != d)
				return false;
		return true;
	}

public:

	inline constexpr
	bool is_0() const {
		return is_0(m_dc);
	}

	inline constexpr
	bool is_1() const {
		return is_1(m_dc);
	}

	inline constexpr
	bool is_Bm1() const {
		return is_Bm1(m_dc);
	}

	inline constexpr
	bool is_B() const {
		return is_B(m_dc);
	}

	inline constexpr
	bool is_Bp1() const {
		return is_Bp1(m_dc);
	}

	template<size_t n>
		requires ((n>0) && (n<L))
	inline constexpr
	bool is_B_pow_m1() const {
		return is_B_pow_m1<L,n>(m_dc);
	}

	template<size_t n>
		requires ((n>0) && (n<L))
	inline constexpr
	bool is_B_pow() const {
		return is_B_pow<L,n>(m_dc);
	}

	inline constexpr
	bool is_filled_of_1() const {
		return is_filled_of_1<L>(m_dc);
	}

	inline constexpr
	bool is_filled_of_Bm1() const {
		return is_filled_of_Bm1<L>(m_dc);
	}

	template<size_t n,dig_t d>
		requires ((n>0) && (n<L))
	inline constexpr
	bool is_filled_of() const {
		return is_filled_of<L,n,d>(m_dc);
	}


				/****************************************************/
				/*							    																*/
				/* OPERADORES COMPARATIVOS	 												*/
				/*							    																*/
				/****************************************************/

	/// COMPARACIONES ENTRE BASE_N_T Y DIG_T EN FORMA BASE_N_T<N> @ DIG_T
	/// STATIC
	template<size_t N>
		requires (N>0)
	static constexpr inline
	bool operator == (const base_N_t<N>& larg, const dig_t& rarg) {
		if (larg[0] != rarg)
			return false;
		for(size_t ix{1} ; ix < N ; ++ix)
			if (m_dc[ix].is_not_0())
				return false;
		return true;
	}

	template<size_t N>
		requires (N>0)
	static constexpr inline
	bool operator != (const base_N_t<N>& larg, const dig_t& rarg) {
		for(size_t ix{1} ; ix < N ; ++ix)
			if (m_dc[ix].is_not_0())
				return true;
		if (larg[0] != rarg)
			return true;
		return false;

	}

	template<size_t N>
		requires (N>0)
	static constexpr inline
	bool operator > (const base_N_t<N>& larg, const dig_t& rarg) {
		for(size_t ix{1} ; ix < N ; ++ix)
			if (m_dc[ix].is_not_0())
				return true;
		if (larg[0] > rarg)
			return true;
		return false;
	}

	template<size_t N>
		requires (N>0)
	static constexpr inline
	bool operator < (const base_N_t<N>& larg, const dig_t& rarg)  {
		for(size_t ix{1} ; ix < N ; ++ix)
			if (m_dc[ix].is_not_0())
				return false;
		if (larg[0] >= rarg)
			return false;
		return true;
	}

	template<size_t N>
		requires (N>0)
	static constexpr inline
	bool operator >= (const base_N_t<N>& larg, const dig_t& rarg)  {
		for(size_t ix{1} ; ix < N ; ++ix)
			if (m_dc[ix].is_not_0())
				return true;
		if (larg[0] >= rarg)
			return true;
		return false;
	}

	template<size_t N>
		requires (N>0)
	static constexpr inline
	bool operator <= (const base_N_t<N>& larg, const dig_t& rarg)   {
		for(size_t ix{1} ; ix < N ; ++ix)
			if (m_dc[ix].is_not_0())
				return false;
		if (larg[0] > rarg)
			return false;
		else
			return true;
	}

	/// COMPARACIONES ENTRE BASE_N_T Y BASE_N_T HETEROGENEOS EN GENERAL
	///	EN FORMA BASE_N_T<N> @ BASE_N_T<M>
	/// STATIC
	template<size_t N,size_t M>
		requires ((N>0)&&(M>0))
	static constexpr inline
	bool operator == (const base_N_t<N>& larg, const base_N_t<M>& rarg) noexcept
	{
		constexpr size_t P{std::min(N,M)};
		constexpr size_t Q{std::max(N,M)};
		constexpr bool N_gt_M{N>M};

		if constexpr (N!=M) {
			for (size_t ix{P} ix < Q ; ++ix) {
				if constexpr (N_gt_M) {
					if (larg[ix].is_not_0())
						return false;
				}
				else {
					if (rarg[ix].is_not_0())
						return false;
				}
			}
		}
		for(size_t ix{0} ; ix < P ; ++ix)
			if (larg[ix] != rarg[ix])
				return false;
		return true;
	}

	template<size_t N,size_t M>
		requires ((N>0)&&(M>0))
	static constexpr inline
	bool operator != (const base_N_t<N>& larg, const base_N_t<M>& rarg) {
		return (!(larg == rarg));
	}

	template<size_t N,size_t M>
		requires ((N>0)&&(M>0))
	static constexpr inline
	bool operator > (const base_N_t<N>& larg, const base_N_t<M>& rarg) noexcept
	{
		constexpr size_t P{std::min(N,M)};
		constexpr size_t Q{std::max(N,M)};
		constexpr bool N_gt_M{N>M};

		if constexpr (N != M) {
			for(size_t ix{P} ; ix < Q ; ++ix) {
				if constexpr (N>M) {
					if (larg[ix].is_not_0())
						return true;
				}
				else {
					if (rarg[ix].is_not_0())
						return false;
				}
			}
		}

		for(int32_t ix{N} ; ix > -1 ; --ix)
			if (larg[ix] > rarg[ix])
				return true;
		return false;
	}

	template<size_t N,size_t M>
		requires ((N>0)&&(M>0))
	static constexpr inline
	bool operator < (const base_N_t<N>& larg, const base_N_t<M>& rarg) noexcept
	{
		constexpr size_t P{std::min(N,M)};
		constexpr size_t Q{std::max(N,M)};
		constexpr bool N_gt_M{N>M};

		if constexpr (N != M) {
			for(size_t ix{P} ; ix < Q ; ++ix) {
				if constexpr (N>M) {
					if (larg[ix].is_not_0())
						return false;
				}
				else {
					if (rarg[ix].is_not_0())
						return true;
				}
			}
		}

		for(int32_t ix{N} ; ix > -1 ; --ix)
			if (larg[ix] < rarg[ix])
				return true;
		return false;
	}

	template<size_t N,size_t M>
		requires ((N>0)&&(M>0))
	static constexpr inline
	bool operator >= (const base_N_t<N>& larg, const base_N_t<M>& rarg) noexcept
	{
		return (!(larg < rarg));
	}

	template<size_t N,size_t M>
		requires ((N>0)&&(M>0))
	static constexpr inline
	bool operator <= (const base_N_t<N>& larg, const base_N_t<M>& rarg) noexcept
	{
		return (!(larg > rarg));
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	bool operator == (const base_N_t<N>& arg) const noexcept
	{
		return (m_dc == arg);
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	bool operator == (const nat_reg_N_digs_t<N>& arg) const noexcept
	{
		return (m_dc == arg.const_ref_data());
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	bool operator != (const base_N_t<N>& arg) const noexcept
	{
		return (m_dc != arg);
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	bool operator != (const nat_reg_N_digs_t<N>& arg) const noexcept
	{
		return (m_dc != arg.const_ref_data());
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	bool operator <= (const base_N_t<N>& arg) const noexcept
	{
		return (m_dc <= arg);
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	bool operator <= (const nat_reg_N_digs_t<N>& arg) const noexcept
	{
		return (m_dc <= arg.const_ref_data());
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	bool operator >= (const base_N_t<N>& arg) const noexcept
	{
		return (m_dc >= arg);
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	bool operator >= (const nat_reg_N_digs_t<N>& arg) const noexcept
	{
		return (m_dc >= arg.const_ref_data());
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	bool operator < (const base_N_t<N>& arg) const noexcept
	{
		return (m_dc < arg);
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	bool operator < (const nat_reg_N_digs_t<N>& arg) const noexcept
	{
		return (m_dc < arg.const_ref_data());
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	bool operator > (const base_N_t<N>& arg) const noexcept
	{
		return (m_dc > arg);
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	bool operator > (const nat_reg_N_digs_t<N> & arg) const noexcept
	{
		return (m_dc > arg.const_ref_data());
	}

	/// OPERADOR COMPARACION SPACESHIP C++20
	template<size_t N>
		requires (N>0)
	constexpr inline
	std::strong_ordering operator <=> (const nat_reg_N_digs_t<N>& arg) const noexcept
	{
		if (m_dc == arg.const_ref_data())
			return std::strong_ordering::equal;
		else if (m_dc < arg.const_ref_data())
			return std::strong_ordering::less;
		else
			return std::strong_ordering::greater;
	}

	/// OPERADOR COMPARACION SPACESHIP C++20
	template<size_t N>
		requires (N>0)
	constexpr inline
	std::weak_ordering operator <=> (const base_N_t<N>& arg) const noexcept
	{
		if (m_dc == arg)
			return std::weak_ordering::equivalent;
		else if (m_dc < arg)
			return std::weak_ordering::less;
		else
			return std::weak_ordering::greater;
	}

	/// OPERADOR COMPARACION SPACESHIP C++20
	constexpr inline
	std::weak_ordering operator <=> (const dig_t & arg) const noexcept
	{
		if (m_dc > arg)
			return std::weak_ordering::greater;
		else if (m_dc < arg)
			return std::weak_ordering::less;
		else
			return std::weak_ordering::equivalent;
	}

				/********************************/
				/*							  							*/
				/* 		  PRIMER DIGITO	 	   			*/
				/*		  SEGUNDO DIGITO					*/
				/*							   							*/
				/********************************/

	template<size_t I>
		requires ((I<L)&&(I>=0))
	inline constexpr
	dig_t get() const noexcept
	{
		return (m_dc[I]);
	}

	template<size_t I>
		requires ((I<L)&&(I>=0))
	inline constexpr
	dig_t put(dig_t arg) noexcept
	{
		m_dc[I] = arg;
		return (m_dc[I]);
	}

	inline constexpr
	dig_t operator[](size_t idx) const noexcept
	{
		return (m_dc[idx]);
	}

	inline constexpr
	dig_t& operator[](size_t idx) noexcept
	{
		return (m_dc[idx]);
	}

	template<type_traits::integral_c Int_Type=UINT_T>
	inline constexpr Int_Type operator()(size_t idx) const noexcept
	{
		return static_cast<Int_Type>(m_dc[idx]());
	}

private:
	inline constexpr
	base_t& ref_data() const {
		return (this->m_dc);
	}
	inline constexpr
	base_t* data() const {
		return (&(this->m_dc));
	}
public:
	inline constexpr
	const base_t & const_ref_data() const {
		return (this->m_dc);
	}
	inline constexpr
	base_t cpy_data() const {
		return this->m_dc;
	}

								/****************************/
								/*													*/
								/* OPERADORES ARITMETICOS		*/
								/*	POSTINCREMENTO ++(int)  */
								/*	PREINCREMENTO ++()			*/
								/*	POSTDECREMENTO --(int)  */
								/*	PREDECREMENTO ++()			*/
								/*                          */
								/****************************/
///<! TODO : ME HE QUEDADO REPASANDO POR AQUI	31/23/18/11/2022
private:
	///< PREINCREMENT(OBJ) == ++OBJ SOLO QUE DEVUELVE CARRY TAMBIEN
	///< PREINCREMENT(OBJ) -> CONDICIONALMENTE
	///< 			BIEN RES_BASE_OP_T 	(con CARRY),
	///<			BIEN BASE_T 				(sin CARRY)

	///<			result_content_low
	///<			result_content_high
	///<			carry
	///<			borrow
	///<			result_content_quotient
	///<			result_content_remainder
	///<			good_result

	template<bool with_result_type>
	static constexpr inline
	auto	preincrement (base_t& arg)  ->
			std::conditional_t<
					with_result_type,
							res_base_op_t<binop_e::add>,
							const base_t &
			>																		noexcept
	{
		if constexpr (with_result_type) { /// true == tipo resultado
			/// CREAMOS EL RETORNO RET DE TIPO RESULTADO
			res_base_op_t<binop_e::add> ret{
				.result_content_low = static_cast<base_t>(arg),
				.carry							=	dig_0(),
				.good_result				=	true
			};
			/// NOMBRE CORTO PARA RET.CARRY
			dig_t& carry{ret.carry};
			/// NOMBRE CORTO PARA RET.RESULT_CONTENT_LOW
			auto&  result{ret.result_content_low};
			/// NOMBRE CORTO PARA RET.GOOD_RESULT
			bool&  good{ret.good_result};
			/// INCREMENTO DEL PRIMER DIGITO
			if (arg[0].is_Bm1()) {
				result[0] = dig_0();
				carry 		= dig_1();
			}
			else {
				++result[0];
				carry 	= dig_0();
				return std::move(ret);
			}
			/// BUCLE FOR QUE SUMA ARG Y 1 DESDE IDX=1 A IDX=L-1
			if (carry.is_not_0()) {
				for(size_t ix{1} ; ix < L ; ++ix) {
					if (carry.is_not_0()) {
						if (arg[ix] == dig_Bm1()) {
							result[ix] = dig_0();
							carry = dig_1();
							continue;
						}
						else {
							++result[ix];
							carry = dig_0();
							return std::move(ret);
						}
					}
				}
			}
			if (carry.is_not_0()) {
				good = false;
			}
			return std::move(ret);
		}
		else {
			/// CARRY INICIAL POR DEFECTO
			dig_t carry{dig_0()};
			/// INCREMENTO DEL PRIMER DIGITO
			if (arg[0].is_Bm1()) {
				arg[0] = dig_0();
				carry = dig_1();
			}
			else {
				++arg[ix];
				return (arg);
			}
			/// BUCLE FOR QUE SUMA ARG Y 1 DESDE IDX=1 A IDX=L-1
			for(size_t ix{1} ; ix < L ; ++ix) {
				if (carry.is_1()) {
					if (arg[ix].is_Bm1()) {
						arg[ix] 	= dig_0();
						carry 		= dig_1();
						continue;
					}
					else {
						++arg[ix];
						return (arg);
					}
				}
			}
			return (arg);
		}
	}

public :

	constexpr inline
	const nat_reg_digs_t & operator ++ () noexcept
	{
		preincrement<false>(m_dc);
		return (*this);
	}

private:

	template<bool with_result_type>
	static constexpr inline
	auto postincrement (base_t& arg) ->
			std::conditional<
					with_result_type,
							res_base_op_t<binop_e::add>,
							const base_t &
			>																		noexcept
	{
		base_t cparg{static_cast<base_t>(arg)};
		if constexpr (with_result_type) {
			auto ret{preincrement<true>(arg)};
			ret.result_content_low = cparg;
			return std::move(ret);
		}
		else {
			preincrement<false>(arg);
			return (cparg);
		}
	}

public :

	constexpr inline
	const nat_reg_digs_t& operator ++ (int) noexcept
	{
		postincrement<false>(m_dc);
		return (*this);
	}

private :

	template<bool with_result_type>
	constexpr inline
	auto predecrement (base_t& arg) ->
		std::conditional<
				with_result_type,
						res_base_op_t<binop_e::sub>,
						const base_t&
				>                               noexcept
	{
		if constexpr (!with_result_type) {
			/// BORROW INICIAL POR DEFECTO
			dig_t borrow{dig_0()};
			/// RESTA 1 A ARG EN IDX == 0
			if (arg[0].is_not_0()) {
				--arg[0];
				return (arg);
			} else {
				arg[0] = dig_Bm1();
				borrow = dig_1();
			}
			/// BUCLE FOR QUE RESTA A ARG UN 1 DESDE IDX=1 A IDX=L-1
			for(size_t ix{1} ; ix < L ; ++ix) {
				if (borrow.is_not_0()) {
					if (arg[ix].is_not_0()) {
						--arg[ix];
						return (arg);
					}
					else if (arg[ix].is_0()) {
						arg[ix] = dig_Bm1();
						borrow = dig_1();
					}
				}
			}
			return (arg);
		}
		else {
			/// CREAMOS EL RETORNO RET
			res_base_op_t<binop_e::sub> ret{
				.result_content_low	=	arg,
				.borrow							=	dig_0(),
				.good_result				=	true
			};
			/// NOMBRE CORTO PARA RET.RESULT_CONTENT_LOW
			auto& result{ret.result_content_low};
			/// NOMBRE CORTO PARA RET.BORROW
			dig_t& borrow{ret.borrow};
			/// NOMBRE CORTO PARA RET.GOOD_RESULT
			bool& good{ret.good_result};
			/// RESTA 1 A ARG EN IDX == 0
			if (arg[0].is_not_0()) {
				--result[0];
				borrow 		= dig_0();
				return std::move(ret);
			} else {
				result[0] = dig_Bm1();
				borrow 		= dig_1();
			}
			/// BUCLE FOR QUE RESTA BORROW A ARG
			/// [DESDE 1 EN IDX=0] DESDE IDX=1 A IDX=L-1
			for(size_t ix{1} ; ix < L ; ++ix) {
				if (borrow.is_not_0()) {
					if (arg[ix].is_not_0()) {
						--result[ix];
						borrow = dig_0();
						return std::move(ret);
					}
					else {
						result[ix] = dig_Bm1();
						borrow = dig_1();
						continue;
					}
				}
			}
			if (borrow.is_not_0()) {
				good = false;
			}
			return std::move(ret);
		}
	}

public :

	constexpr inline
	const nat_reg_digs_t & operator -- () noexcept
	{
		predecrement<false>(m_dc);
		return (*this);
	}

private :

	template<bool with_result_type>
	constexpr inline
	auto postdecrement(base_t& arg) ->
		std::conditional<
				with_result_type,
						res_base_op_t<binop_e::sub>,
						const base_t&
				>                               noexcept
	{
		base_t cparg{static_cast<base_t>(arg)};
		if constexpr (with_result_type) {
			res_base_op_t<binop_e::sub> ret{predecrement<true>(arg)};
			ret.result_content_low = std::move(cparg);
			return std::move(ret);
		}
		else {
			predecrement<false>(arg);
			return (cparg);
		}
	}

public :

	constexpr inline
	const nat_reg_digs_t & operator -- (int) noexcept
	{
		postdecrement<false>(m_dc);
		return (*this);
	}

								/****************************/
								/*													*/
								/* OPERADORES ARITMETICOS		*/
								/*	 C_B()  C_Bm1()  				*/
								/*	mC_B() mC_Bm1()		    	*/
								/*	operator!() operator-() */
								/*                          */
								/****************************/

private :

	static constexpr inline
	const base_t & mC_Bm1(base_t & arg) noexcept
	{
		for(size_t ix{0} ; ix < L ; ++ix) {
				arg[ix].mC_Bm1();
		}
		return (*this);
	}

	static constexpr inline
	const base_t & mC_B(base_t & arg) noexcept
	{
		mC_Bm1(m_dc);
		++(*this);
		return (*this);
	}

	static constexpr inline
	base_t C_Bm1(const base_t & arg) noexcept
	{
		return (arg.mC_Bm1());
	}

	static constexpr inline
	base_t C_B(const base_t & arg) noexcept
	{
		return (arg.mC_B());
	}

public :

	constexpr inline
	const nat_reg_digs_t & mC_B() noexcept
	{
		mC_B(m_dc);
		return (*this);
	}

	constexpr inline
	const nat_reg_digs_t & mC_Bm1() noexcept
	{
		mC_Bm1(m_dc);
		return (*this);
	}

	constexpr inline
	nat_reg_digs_t C_Bm1() const noexcept
	{
		return nat_reg_digs_t{C_Bm1(m_dc)};
	}

	constexpr inline
	nat_reg_digs_t C_B() const noexcept
	{
		return nat_reg_digs_t{C_B(m_dc)};
	}

	constexpr inline
	nat_reg_digs_t operator !() const noexcept
	{
		return C_Bm1();
	}

	constexpr inline
	nat_reg_digs_t operator -() const noexcept
	{
		return C_B();
	}


	/// BEGIN : OPERATORS >> >>= << <<= REM_B^n M_REM_B^n MER_B_N M_MER_B_N

	/// MULTIPLY BY THE BASE B (10) << <<=
	/// DIVIDE BY THE BASE B (10)	  >> >>=
	/// REMAINDER BY THE BASE B (10) REM_B_N M_REM_B_N
	/// MULTIPLICATIVE CARRY BY THE BASE B (10) MER_B_N M_MER_B_N

private :

	static constexpr inline
	base_t operator << (const base_t& larg, size_t n) noexcept
	{
		base_t cparg{larg};
		for(std::int32_t ix{L-1-n} ; ix > -1 ; --ix) {
			cparg[ix+n]	= larg[ix];
		}
		for(std::int32_t ix{0} ; ix < n ; ++ix) {
			cparg[ix]		= dig_0();
		}
		return std::move(cparg);
	}

	static constexpr inline
	const base_t & operator <<= (base_t& larg, size_t n) noexcept
	{
		for(std::int32_t ix{L-1-n} ; ix > -1 ; --ix) {
			larg[ix+n]	= larg[ix];
		}
		for(std::int32_t ix{0} ; ix < n ; ++ix) {
			larg[ix]	= dig_0();
		}
		return (larg);
	}

	static constexpr inline
	const base_t & operator >>= (base_t& larg, size_t n) noexcept
	{
		for(std::int32_t ix{0} ; ix < L-n ; ++ix) {
			larg[ix] 		= larg[ix+n];
		}
		for(std::int32_t ix{L-n} ; ix < L ; ++ix) {
			larg[ix]		=	dig_0();
		}
		return (larg);
	}

	static constexpr inline
	base_t operator >> (const base_t & larg, size_t n) noexcept
	{
		return std::move(base_t{larg}.ref_data() >>= n);
	}

	static constexpr inline
	base_t rem_B(const base_t & larg,size_t n) noexcept
	{
		base_t ret{larg};
		ret <<= L-n;
		return std::move(ret);
	}

	static constexpr inline
	const base_t & m_rem_B(base_t& larg,size_t n) noexcept
	{
		larg <<= L-n;
		return (larg);
	}


	static constexpr inline
	base_t mer_B(const base_t & larg,size_t n) noexcept
	{
		base_t ret{larg};
		ret >>= L-n;
		return std::move(ret);
	}

	static constexpr inline
	const base_t & m_mer_B(base_t& larg,size_t n) noexcept
	{
		larg >>= L-n;
		return (larg);
	}


public :

	constexpr inline
	nat_reg_digs_t operator << (size_t n) const noexcept
	{
		nat_reg_digs_t cpthis{*this};
		cpthis.ref_data() <<= n;
		return std::move(cpthis);
	}

	constexpr inline
	const nat_reg_digs_t & operator <<= (size_t n) noexcept
	{
		m_dc <<= n;
		return (*this);
	}

	constexpr inline
	nat_reg_digs_t operator >> (size_t n) const noexcept
	{
		return std::move(nat_reg_digs_t{*this}.ref_data() >>= n);
	}

	constexpr inline
	const nat_reg_digs_t & operator >>= (size_t n) noexcept
	{
		m_dc >>= n;
		return (*this);
	}

	constexpr inline
	nat_reg_digs_t rem_B(size_t n) const noexcept
	{
		nat_reg_digs_t ret{rem_B(m_dc,n)};
		return std::move(ret);
	}

	constexpr inline
	const nat_reg_digs_t & m_rem_B(size_t n) noexcept
	{
		m_rem_B(m_dc,n);
		return (*this);
	}

	constexpr inline
	nat_reg_digs_t mer_B(size_t n) const noexcept
	{
		nat_reg_digs_t ret{mer_B(m_dc,n)};
		return std::move(ret);
	}

	constexpr inline
	const nat_reg_digs_t & m_mer_B(size_t n) noexcept
	{
		m_mer_B(m_dc,n);
		return (*this);
	}

	/// END   : OPERATORS >> >>= << <<= REM_B^n M_REM_B^n MER_B_N M_MER_B_N

	/// BEGIN : OPERATORS | & |= &=

private :

	static constexpr inline
	const base_t & operator |= (base_t & larg,const base_t & rarg) noexcept
	{
		for(size_t ix{0} ; ix < L ; ++ix) {
			larg[ix] |= rarg[ix];
		}
		return (larg);
	}

	static constexpr inline
	base_t operator | (const base_t & larg,const base_t & rarg) noexcept
	{
		nat_reg_digs_t ret{larg};
		ret |= rarg;
		return std::move(ret);
	}

	static constexpr inline
	const base_t & operator &= (base_t & larg,const base_t & rarg) noexcept
	{
		for(size_t ix{0} ; ix < L ; ++ix) {
			larg[ix] &= rarg[ix];
		}
		return (larg);
	}

	static constexpr inline
	base_t operator & (base_t & larg,const base_t & rarg) noexcept
	{
		base_t ret{larg};
		ret &= rarg;
		return std::move(ret);
	}

public :

	constexpr inline
	const nat_reg_digs_t & operator |= (const nat_reg_digs_t & arg) noexcept
	{
		m_dc |= arg.const_ref_data();
		return (*this);
	}

	constexpr inline
	nat_reg_digs_t operator | (const nat_reg_digs_t & arg) noexcept
	{
		nat_reg_digs_t ret{*this};
		ret |= arg;
		return std::move(ret);
	}

	constexpr inline
	const nat_reg_digs_t & operator &= (const nat_reg_digs_t & arg) noexcept
	{
		m_dc &= arg.const_ref_data();
		return (*this);
	}

	constexpr inline
	nat_reg_digs_t operator & (const nat_reg_digs_t & arg) noexcept
	{
		nat_reg_digs_t ret{*this};
		ret &= arg;
		return std::move(ret);
	}

	/// END   : OPERATORS | & |= &=


					/************************************/
					/* OPERADORES ARITMETICOS BASICOS		*/
					/*			nat_reg_digs_t	@  dig_t		*/
					/*      nat_reg_digs_t	@= dig_t    */
					/*      nat_reg_digs_t  @  10B^n    */
					/*      nat_reg_digs_t  @= 10B^n    */
					/************************************/

					/************************************/
					/*								   								*/
					/*  ARITMETICOS CON ASIGNACION			*/
					/*		nat_reg_digs_t @= dig_t				*/
					/*                                  */
					/************************************/

	/// OPERACIONES BINARIAS CON/SIN TIPO RESULTADO
	/// OPERACIONES BINARIAS
	///										BASE_T @ DIG_T
	/// OPERATOR BASE_T += DIG_T CON NOMBRE M_ADDITION
	template<bool with_result_type>
	static constexpr inline
	auto m_add (base_t & larg,const dig_t & rarg) ->
		typename std::conditional_t<
			with_result_type,
				res_base_op_t<binop_e::add>,
				base_t const&
		>                                           noexcept
	{
		constexpr auto UINT_T middle_max{std::numeric_limits<UINT_T>::max()/2};
		using uint_type = std::conditional_t<B<=middle_max,UINT_T,SIG_UINT_T>;
		using dig_t = dig_t<uint_type,B>;
		if constexpr (! with_result_type) {
			/// CARRY INICIAL POR DEFECTO
			dig_t carry{dig_0()};
			/// SUMA DEL PRIMER DIGITO DE LARG[0] Y RARG
			if (larg[0] <= dig_Bm1()-rarg) {
				larg[0] += rarg;
				return (larg);
			}
			else {
				larg[0] -= (dig_Bm1()-rarg+1);
				carry = dig_1();
			}
			/// BUCLE FOR QUE SUMA ARG Y 1 DESDE IDX=1 A IDX=L-1
			for(size_t ix{1} ; ix < L ; ++ix) {
				if (carry.is_1()) {
					if (larg[ix].is_Bm1()) {
						larg[ix] = dig_0();
						carry = dig_1();
					}
					else {
						++larg[ix];
						return (larg);
					}
				}
			}
			return (larg);
		}
		else {
			/// INICIALIZACION
			res_base_op_t<binop_e::add> ret{
				.result_content_low		=		larg,
				.carry								=		dig_0(),
				.good_result					=		true
			};
			/// NOMBRE CORTO PARA RET.RESULT_CONTENT_LOW
			auto&		result{ret.result_content_low};
			/// NOMBRE CORTO PARA RET.CARRY
			dig_t&	carry{ret.carry};
			/// NOMBRE CORTO PARA RET.GOOD_RESULT
			bool&		good{ret.good_result};
			/// SUMA DEL PRIMER DIGITO DE LARG[0] Y RARG
			if (larg[0] <= dig_Bm1()-rarg) {
				result[0]       +=	rarg;
				carry						 =	dig_0();
				return std::move(ret);
			}
			else {
				ret.result_content[0]   -= (dig_B()-rarg);
				carry                    = dig_1();
			}
			/// BUCLE FOR QUE SUMA ARG Y 1 DESDE IDX=1 A IDX=L-1
			for(size_t ix{1} ; ix < L ; ++ix) {
				if (carry.is_not_0()) {
					if (result[ix].is_Bm1()) {
						result[ix]  = dig_0();
						carry       = dig_1();
					}
					else {
						++result[ix];
						carry = dig_0();
					}
				}
			}
			if (carry.is_not_0())
				good = false;
			return std::move(ret);
		}
	}

	/// OPERATOR BASE_T -= DIG_T CON NOMBRE M_SUB
	static constexpr inline
	const base_t & m_sub(base_t & larg,const dig_t & rarg) noexcept
	{
		/// COPIA DE RARG
		dig_t cprarg{rarg};
		/// CARRY INICIAL POR DEFECTO: NULO
		dig_t borrow{dig_0()};
		/// SUMA DEL PRIMER DIGITO DE LARG[0] Y RARG
		if (larg[0] >= rarg) {
			larg[0] -= rarg;
			borrow = dig_0();
			return (larg);
		}
		else {
			cprarg -= larg[0];
			larg[0] = cprarg.C_B();
			borrow 	= dig_1();
		}
		/// BUCLE FOR QUE RESTA RARG A LARG DESDE IDX=1 A IDX=L-1
		for(size_t ix{1} ; ix < L ; ++ix) {
			if (borrow.is_1()) {
				if (arg[ix].is_0()) {
					arg[ix] = dig_Bm1();
					borrow  = dig_1();
					continue;
				}
				else {
					--arg[ix];
					borrow = dig_0();
					return (arg);
				}
			}
		}
		return (arg);
	}

	static constexpr inline
	base_t add (const base_t & larg,const dig_t & rarg) noexcept
	{
		return m_add<false>(larg,rarg);
	}

	static constexpr inline
	base_t sub (const base_t & larg,const dig_t & rarg) noexcept
	{
		return m_sub<false>(larg,rarg);
	}

public :

	constexpr inline
	const nat_reg_digs_t & operator += (const dig_t& rarg) noexcept
	{
		m_add<false>(m_dc,rarg);
		return (*this);
	}

	constexpr inline
	const nat_reg_digs_t & operator -= (const dig_t& rarg) noexcept
	{
		m_sub<false>(m_dc,rarg);
		return (*this);
	}

	constexpr inline
	nat_reg_digs_t operator + (const dig_t& rarg) noexcept
	{
		return nat_reg_digs_t{add(m_dc,rarg)};
	}

	constexpr inline
	nat_reg_digs_t operator - (const dig_t& rarg) noexcept
	{
		return nat_reg_digs_t{sub(m_dc,rarg)};
	}

private :

	/// OPERACIONES '@'(REG_DIGS_T,DIG_T)->RESULT_TYPE<'@'>
	/// '@' = MULT
	template<bool with_result_type>
	constexpr inline
	auto mult(dig_t arg) const ->
		std::conditional_t<
			with_result_type,
				res_base_op_t<binop_e::mult>,
				const base_t &
		>                                noexcept
	{
		nat_reg_digs_t cpthis(*this);
		if constexpr (with_result_type) {
			res_base_op_t<binop_e::mult> ret{
				.result_content_low 	= m_dc,
				.result_content_high 	= regd_0(),
				.good_result 					= true
			};
			base_t & res_low {ret.result_content_low };
			base_t & res_high{ret.result_content_high};
			bool   & good{ret.good_result};
			if (arg.is_0()) {
				res_low 	= regd_0();
				return std::move(ret);
			}
			else if (is_0()) {
				return std::move(ret);
			}
			else if (arg.is_1()) {
				return std::move(ret);
			}
			else if (is_1()) {
				res_low.set_0();
				res_low[0] = arg;
				return std::move(ret);
			}
			else {
				constexpr UINT_T sqrt_max{type_traits::sqrt_max()};
				using uint_type = std::conditional_t<
					B <= sqrt_max ,
						UINT_T,
						SIG_UINT_T
				>;
				constexpr uint_type Bc{B};
				uint_type carry{0};
				uint_type cparg{arg()};
				for(size_t ix{0} ; ix < L ; ++ix){
					uint_type digint{m_dc(ix)};
					digint *= cparg;
					uint_type unds{digint % Bc};
					uint_type decs{digint / Bc};
					if (unds < (Bc-1)-carry) {
						unds += carry;
						carry = 0;
					}
					else {
						const uint_type raw_sum{unds+carry};
						decs += raw_sum/Bc;
						unds 	= raw_sum%Bc;
						carry = decs;
					}
					res_low[ix] = unds;
				}
				if (carry != 0) {
					res_high[0] = dig_t(carry);
					good = false;
				}
				return std::move(ret);
			}
		}
		else {
			base_t ret{static_cast<base_t>(m_dc)};
			if (arg.is_0()) {
				return std::move(regd_0());
			}
			else if (is_0()) {
				return std::move(regd_0());
			}
			else if (arg.is_1()) {
				return std::move(ret);
			}
			else if (is_1()) {
				ret.set_0();
				ret[0] = arg;
				return std::move(ret);
			}
			else {
				constexpr UINT_T sqrt_max{type_traits::sqrt_max()};
				using uint_type = std::conditional_t<
					B <= sqrt_max ,
						UINT_T,
						SIG_UINT_T
				>;
				constexpr uint_type Bc{B};
				uint_type carry{0};
				uint_type cparg{arg()};
				for(size_t ix{0} ; ix < L ; ++ix){
					uint_type digint{m_dc(ix)};
					digint *= cparg;
					uint_type unds{digint % B};
					uint_type decs{digint / B};
					if (unds < (Bc-1)-carry) {
						unds += carry;
					}
					else {
						decs += (unds+carry)/Bc;
						unds 	= (unds+carry)%Bc;
						carry = decs;
					}
					ret[ix] = unds;
				}
				return std::move(ret);
			}
		}
	}

	/// '@' = FULL_EUCLID_DIV(BASE_T,DIG_T) -> (REM,COC,GOOD)
	static constexpr inline
	auto fediv(const base_t& larg,const dig_t& rarg) ->
		res_base_op_t<binop_e::fediv>
	noexcept {
			res_base_op_t<binop_e::fediv> ret{
				.result_content_quotient 	= larg,
				.result_content_remainder = regd_0(),
				.good_result = true
			}
			base_t& coc{ret.result_content_quotient};
			base_N_t<2> rem{dig_0(),dig_0()};
			bool& good{ret.good_result};
			base_t dndo{larg};
			dig_t dsor{rarg};
			if (dsor == dig_0()) {
				good = false;
				return std::move(ret);
			}
			else 	if (dsor == dig_1()) {
				return std::move(ret);
			}
			else 	if (dndo < regd_B()) {
				coc = dig_0();
				coc[0] = dndo[0] / dsor;
				rem[0] = dndo[0] % dsor;
				return std::move(ret);
			}
			else {
				///  7    tipo UINT_T entero
				/// [7]   tipo dig_t  wrapper de un entero
				/// [[7]] tipo base_t array
				/// [[2][3][4][5][6]] / [7]
				/// INICIALIZACION
				dndo = larg; //[[2][3][4][5][6]];
				dsor = rarg; // [7]             ;
				rem  = {dig_0(),dig_0()}        ;
				coc  = regd_0();
				/// BUCLE PRINCIPAL DE DIVISION
				for ( int32_t ix=L ; ix > 0 ; --ix ) {
					coc  <<= 1;
					if ( rem < dsor ) {
						rem  <<= 1;
					}
					else {
						const SIG_UINT_T dndo_uint  = rem[1]()*B+rem[0]();
							// Como maximo (B-1)*B+B-1=B^2-1
						const SIG_UINT_T coc_uint   = dndo_uint / dsor_uint;
						const SIG_UINT_T rem_uint   = dndo_uint % dsor_uint;
						coc[0] = dig_t{coc_uint};
						rem[1] = dig_t{rem_uint};
					}
					rem[0] = dndo[ix-1];
				}
				/// ULTIMA ITERACION
				coc  <<= 1;
				if ( rem >= dsor ) {
					const SIG_UINT_T dndo_uint  =  rem[1]()*B+rem[0]();
						// Como maximo (B-1)*B+B-1=B^2-1
					const SIG_UINT_T coc_uint   = dndo_uint / dsor_uint;
					const SIG_UINT_T rem_uint   = dndo_uint % dsor_uint;
					coc[0] = dig_t{coc_uint};
					rem[1] = dig_0();
					rem[0] = dig_t{rem_uint};
				}
				ret.result_content_remainder[0] = rem[0];
				ret.result_content_remainder[1] = rem[1];
				return std::move(ret);
			}
		}
	}

//  /// TO DO REPASAR
//	/// '@' = '+'
//	constexpr inline
//	std::array<nat_reg_digs_t,2> add(dig_t arg) const
//	noexcept {
//		const nat_reg_digs_t& cthis{*this};
//		std::array<nat_reg_digs_t,2> result{dig_0(),cthis};
//		dig_t carry{dig_0()};
//		for(size_t ix{0} ; ix < L ; ++ix) {
//			auto 	temp_result   =      result[0][ix].add(arg);
//			auto  temp_result_2 = temp_result[0][ix].add(carry);
//			result[0][ix] = temp_result_2[0];
//			result[1][0]  = temp_result_2[1];
//			carry = result[1][0];
//		}
//		for(size_t ix{1} ; ix < L ; ++ix) {
//			result[1][ix] = dig_0();
//		}
//		return result;
//	}
//
//	/// TO DO REPASAR
//	/// '@' = '-'
//	constexpr inline
//	std::array<nat_reg_digs_t,2> sub(dig_t arg) const
//	noexcept {
//		const nat_reg_digs_t& cthis{*this};
//		std::array<nat_reg_digs_t,2> result{dig_0(),cthis};
//		nat_reg_digs_t cb_arg{-arg};
//		if (!(arg.is_0())) {
//			for(size_t ix{1} ; ix < L ; ++ix) {
//				cb_arg[ix] = dig_Bm1();
//			}
//		}
//		dig_t carry{dig_0()};
//		for(size_t ix{0} ; ix < L ; ++ix) {
//			auto 	temp_result   =      result[0][ix].add(cb_arg[ix]);
//			auto  temp_result_2 =     temp_result[0].add(carry);
//			result[0][ix]  = temp_result_2[0];
//			result[1][ix]  = (temp_result_2[1].add(temp_result_2[1]))[0];
//			carry = result[1][ix];
//		}
//		return result;
//	}


					/********************************/
					/*							 								*/
					/*    OPERADORES ARITMETICOS		*/
					/*		nat_reg_digs_t @ dig_t		*/
					/* 															*/
					/********************************/

public :

		constexpr inline
		auto operator + (dig_t arg) const noexcept
		{
			nat_reg_digs_t ret(*this);
			ret += arg;
			return ret;
		}

		constexpr inline
		auto operator - (dig_t arg) const noexcept
		{
			nat_reg_digs_t ret(*this);
			ret -= arg;
			return ret;
		}

		constexpr inline
		auto operator * (dig_t arg) const noexcept
		{
			nat_reg_digs_t ret(*this);
			ret *= arg;
			return ret;
		}

		///< TO DO TODAY 20:28-10-11-2022
		///< ARITHMETIC OPERATION : COMPLETE EUCLIDEAN DIVISION BY A BASE_N_T<1>
		static constexpr inline
		auto fediv (const base_t& larg,const base_N_t<1>& rarg)
		 -> res_base_op_t<binop_e::fediv>
		noexcept {
			res_base_op_t ret{
				.result_content_quotient 		= larg,
				.result_content_remainder   = regd_base_0(),
				.good_result = true
			}
			using base_rem_t 	= base_N_t<2>;
			static constexpr base_rem_t cero_rem{regd_base_N_0<2>()};
			using base_dsor_t = base_N_t<1>;
			static constexpr base_dsor_t cero_dsor{dig_0()};
			static constexpr base_dsor_t uno_dsor{dig_1()};
			base_t& 	coc{ret.result_content_quotient};
			base_rem_t	rem = cero_rem;
			bool& good{ret.good_result};
			const base_t&		dndo{larg};
			const base_dsor_t& 	dsor{rarg};
			if (dsor == cero_dsor) {
				good = false;
				return std::move(ret);
			}
			else if (dsor == uno_dsor) {
				return std::move(ret);
			}
			else if (dndo < regd_base_B()) {
				coc = dig_0();
				coc[0] = dndo[0] / dsor[0];
				rem[0] = dndo[0] % dsor[0];
				return std::move(ret);
			}
			else {
				///  7    tipo UINT_T entero
				/// [7]   tipo dig_t  wrapper de un entero
				/// [[7]] tipo base_t array
				/// [[2][3][4][5][6]] / [7]
				/// INICIALIZACION
				dndo = larg; //[[2][3][4][5][6]];
				dsor = rarg; // [7]             ;
				rem  = cero_rem        					;
				coc  = regd_0();
				/// BUCLE PRINCIPAL DE DIVISION
				for ( int32_t ix=L ; ix > 0 ; --ix ) {
					coc  <<= 1;
					if ( rem < dsor ) {
						rem  <<= 1;
					}
					else {
						const SIG_UINT_T dndo_uint  = rem[1]()*B+rem[0]();
							// Como maximo (B-1)*B+B-1=B^2-1
						const SIG_UINT_T coc_uint   = dndo_uint / dsor_uint;
						const SIG_UINT_T rem_uint   = dndo_uint % dsor_uint;
						coc[0] = dig_t{coc_uint};
						rem[1] = dig_t{rem_uint};
					}
					rem[0] = dndo[ix-1];
				}
				/// ULTIMA ITERACION
				coc  <<= 1;
				if ( rem >= dsor ) {
					const SIG_UINT_T dndo_uint  = rem[1]()*B+rem[0]();
						// Como maximo (B-1)*B+B-1=B^2-1
					const SIG_UINT_T coc_uint   = dndo_uint / dsor_uint;
					const SIG_UINT_T rem_uint   = dndo_uint % dsor_uint;
					coc[0] = dig_t{coc_uint};
					rem[1] = dig_0();
					rem[0] = dig_t{rem_uint};
				}
				ret.result_content_remainder[0] = rem[0];
				ret.result_content_remainder[1] = rem[1];
				return std::move(ret);
			}
		}

		static constexpr inline
		base_N_t<3> aprox_divB(const base_N_t<3>& arg) noexcept
		{
			/// 999
			/// 99,9
			/// 100
			base_N_t<3> cparg{arg};
			if (cparg[2].is_not_0()) {
				if (cparg[0] <= dig_t{B/2}) {
					cparg[0] = cparg[1];
					cparg[1] = cparg[2];
					cparg[2] = dig_0();
				}
				else {
					if (cparg[1].is_Bm1()) {
						if (cparg[2].is_Bm1()) {
							cparg[0] = dig_0();
							cparg[1] = dig_0();
							cparg[2] = dig_1();
						}
						else {
							++cparg[2];
							cparg[1] = dig_0();
							cparg[0] = cparg[1];
							cparg[1] = cparg[2];
							cparg[2] = dig_0();
						}
					}
					else {
						++cparg[1];
						cparg[0] = cparg[1];
						cparg[1] = cparg[2];
						cparg[2] = dig_0();
					}
				}
			}
			return cparg;
		}

		static constexpr inline
		base_N_t<2> aprox_divB_not0(const base_N_t<2>& arg) noexcept
		{
			base_N_t<2> cparg{arg};
			if (cparg[1].is_not_1()) {
				if (cparg[0] <= dig_t{B/2}) {
					cparg[0] = cparg[1];
					cparg[1] = dig_0();
				}
				else {
					if (cparg[1].is_Bm1()) {
						cparg[1]=dig_1();
						cparg[0]=dig_0();
					}
					else {
						++cparg[1];
						cparg[0] = cparg[1];
						cparg[1] = dig_0();
					}
				}
			}
			else {
				if (cparg[0] <= dig_t{B-1}) {
					cparg[1] = dig_0();
					cparg[0] = dig_1();
				}
				else {
					cparg[1] = dig_0();
					cparg[0] = dig_t{2};
				}
			}
			return cparg;
		}

		///< TODO 15-11-2022
    ///< HECHO DESPUES DE LA HORA 20:00-14-11-2022 PERO EL MISMO DIA
    ///< FUNCION DE RECURSION PARA LA DIVISION
    static constexpr inline
    std::array<SIG_UINT_T,2> aprox_coc(
				const base_t& dndo, const base_t& dsor,
				const base_N_t<3>& rem, const base_N_t<2>& coc,
				SIG_UINT_T rem_calculado , SIG_UINT_T coc_calculado
			)                                                    noexcept
		{
				base_N_t<3> rem_aprox {dsor*dig_t(coc_calculado)+dig_t(rem_calculado)};
						/// RESULTADO BASE_N_T<3> desde RESULTADO BASE_N_T<2>
				rem_aprox[2] = dig_0();
				const SIG_UINT_T dsor_uint{dsor[1]()*B+dsor[0]()};/// ALGUN CAST DE UINT_T A SIG_UINT_T ?
        if (rem_aprox == rem) {
            return std::array<SIG_UINT_T,2>{coc_calculado,rem_calculado};
            /// ES COC_CALULADO = TEMP[1] O COC_CALULADO = TEMP[0] ?
            /// ES REM_CALULADO = TEMP[0] O REM_CALULADO = TEMP[1] ?
        }
        else if (rem_aprox > rem) {
            /// PROBAR CON --coc_uint
            /// rem_2_uint HABRIA QUE INCREMETAR EL REM EN DSOR
            --coc_calculado;
            rem_calculado += dsor_uint;
            SIG_UINT_T rem_aprox{coc_calculado*dsor_uint+rem_calculado};
            if (base_t(coc_calculado)*dig_t{dsor_uint}+dig_t{rem_aprox} == rem) {
							return std::array<SIG_UINT_T,2>{coc_calculado,rem_calculado};
            }
            else {
							return aprox_decr_coc(dndo,dsor,rem,coc,rem_calculado,coc_calculado);
            }
        }
        else {
            /// PROBAR CON ++coc_uint
            /// rem_2_uint HABRIA QUE DECREMETAR EL REM EN DSOR
            ++coc_calculado;
            rem_calculado -= dsor_uint;
            SIG_UINT_T rem_aprox{coc_calculado*dsor_uint+rem_calculado};
            if (base_t(coc_calculado)*dig_t{dsor_uint}+dig_t{rem_aprox} == rem) {
							return std::array<SIG_UINT_T,2>{coc_calculado,rem_calculado};
            }
            else {
							return aprox_incr_coc(dndo,dsor,rem,coc,rem_calculado,coc_calculado);
            }
        }
    }

		static constexpr inline
    std::array<SIG_UINT_T,2> aprox_decr_coc (
				const base_t& dndo, const base_t& dsor,
				const base_N_t<3>& rem, const base_N_t<2>& coc,
				SIG_UINT_T rem_calculado , SIG_UINT_T coc_calculado
			)                                                     noexcept
		{
			const SIG_UINT_T dsor_uint{dsor[1]()*B+dsor[0]()};

			--coc_calculado;
      rem_calculado += dsor_uint;

      if (base_t(coc_calculado)*dig_t{dsor_uint}+dig_t{rem_calculado} == rem) {
				return std::array<SIG_UINT_T,2>{coc_calculado,rem_calculado};
      }
      else {
				return aprox_decr_coc(dndo,dsor,rem,coc,rem_calculado,coc_calculado);
      }
		}

		static constexpr inline
    std::array<SIG_UINT_T,2> aprox_incr_coc (
				const base_t& dndo, const base_t& dsor,
				const base_N_t<3>& rem, const base_N_t<2>& coc,
				SIG_UINT_T rem_calculado , SIG_UINT_T coc_calculado
			)                                                    noexcept
		{
			const SIG_UINT_T dsor_uint{dsor[1]()*B+dsor[0]()};

			++coc_calculado;
      rem_calculado -= dsor_uint;

      if (base_t(coc_calculado)*dig_t{dsor_uint}+dig_t{rem_calculado} == rem) {
				return std::array<SIG_UINT_T,2>{coc_calculado,rem_calculado};
      }
      else {
				return aprox_incr_coc(dndo,dsor,rem,coc,rem_calculado,coc_calculado);
      }
		}

		///< TODO 20:00-14-11-2022
		static constexpr inline
		auto fediv (const base_t& larg,const base_N_t<2>& rarg)
		    -> res_base_op_t<binop_e::fediv>									noexcept
		{
			res_base_op_t ret{
				.result_content_quotient 		= larg,
				.result_content_remainder   = regd_base_0(),
				.good_result                = true
			}
			using base_rem_t 	= base_N_t<3>;
			static constexpr base_rem_t cero_rem{regd_base_N_0<3>()};
			static constexpr base_rem_t uno_rem{regd_base_N_1<3>()};
			using base_dsor_t = base_N_t<2>;
			static constexpr base_dsor_t cero_dsor{regd_base_N_0<2>()};
			static constexpr base_dsor_t uno_dsor{regd_base_N_1<2>()};
			base_t& 		coc{ret.result_content_quotient}; /// COC
			base_rem_t	rem{cero_rem};										/// REM resto disminuido a 3
			bool& good{ret.good_result};                  /// GOOD
			const base_t&				dndo{larg};               /// DNDO
			const base_dsor_t& 	dsor{rarg};               /// DSOR dismiuido a tamano 2
			if (dsor == cero_dsor) {
				good = false;
				return std::move(ret);
			}
			else 	if (dsor == uno_dsor) {
				return std::move(ret);
			}
			else if (dsor[1].is_0()) {
				return std::move(fdiv(dndo,dsor[0]));
			}
			else if (dsor.is_B()) {
				rem[2] = rem[1]  = dig_0();
				rem[0] = dndo[0];
				coc = dndo >> 1;
			}
			else 	if (dndo < dsor) {
				coc = regd_base_0();
				for( size_t ix{0} ; ix < 3 ; ++ix )
					ret.result_content_remainder[ix] = dndo[ix];
				return std::move(ret);
			}
			else if (dndo == dsor) {
				coc = regd_base_1();
				ret.result_content_remainder = std::move(uno_rem);
				return std::move(ret);
			}
			else {
				/// dsor > B-1
				/// dsor[1] >= dig_1()
				/// dndo > dsor
				/// dosr != B

				/// INICIALIZACION
				rem  = regd_base_N_0<3>() ;
				coc  = regd_base_0()			;
				/// BUCLE PRINCIPAL DE DIVISION
				for ( int32_t ix=L ; ix > 0 ; --ix ) {
					coc  <<= 1;
					if ( rem < dsor ) {
						rem  <<= 1;
					}
					else {
						auto rem_red{aprox_divB(rem)};
						auto dsor_red{aprox_divB_not0(dsor)};
						/// DOS CASOS: REM[2]==0 O REM[2]==1
						/// DOS CASOS: DSOR[1]==0 O DSOR[1]==1
						const SIG_UINT_T dndo_uint  = rem_red[1]()*B+rem[0]();
						const SIG_UINT_T dsor_uint  = dsor_red[0]();

						const SIG_UINT_T coc_uint   = dndo_uint / dsor_uint;
						const SIG_UINT_T rem_uint   = dndo_uint % dsor_uint;
						/// COMPROBACION :
						/// DSOR*[COC_UINT]+[REM_UINT] == REM
						/// HACER LA BUSQUEDA DEL COCIENTE RECURSIVA
						/// HASTA DAR CON EL COCIENTE CORRECTO

						if(rem[2].is_0() && dsor[1].is_0()) {
							/// 751 -> 075
							///  47 ->  05
							if (dsor*dig_t(coc_uint)+dig_t(rem_uint) == rem) {
								coc[0] = dig_t{coc_uint};
								rem[1] = dig_t{rem_uint};
							}
							else {
								auto result{aprox_coc()};
								coc[0] = dig_t{result[0]};
								rem[1] = dig_t{result[1]};
							}
							/// Caso estandar
						}
						else if (rem[2].is_0() && dsor[1].is_not_0()) {
							/// 751 -> 075
							///  99 ->  10
							rem >>= 1;
							coc <<= 1;
							/// Caso de division por BASE
						}
						///		else if (rem[2].is_not_0() && dsor[1].is_0()) {
						///			/// 999 -> 100 D*B^2
						///			///  27 ->  03 E
						///			/// D*B^2 / E > B
						///			///< ESTE CASO NO SE PUEDE DAR
						///			/// Se ha de reducir el rem practico a los 2 primeros
						///		}
						else {
							/// 999 -> 100
							///  99 ->  10
							rem = cero_rem;
							coc <<= 1;
						}
					}
					rem[0] = dndo[ix-1];
				}
				/// TODO 11-28-17-11-2022
				/// ULTIMA ITERACION
				coc  <<= 1;
				if ( rem >= dsor ) {
					auto rem_red{aprox_divB(rem)};
					auto dsor_red{aprox_divB_not0(dsor)};

					const SIG_UINT_T dndo_uint  = rem_red[1]()*B+rem_red[0]();
					const SIG_UINT_T dsor_uint  = dsor_red[0]();

					/// DOS CASOS: REM[2]==0 O REM[2]==1
					/// DOS CASOS: DSOR[1]==0 O DSOR[1]==1
					const SIG_UINT_T coc_uint   = dndo_uint / dsor_uint;
					const SIG_UINT_T rem_uint   = dndo_uint % dsor_uint;
					/// COMPROBACION :
					/// DSOR*[COC_UINT]+[REM_UINT] == REM
					/// HACER LA BUSQUEDA DEL COCIENTE RECURSIVA
					/// HASTA DAR CON EL COCIENTE CORRECTO

					if(rem[2].is_0() && dsor[1].is_0()) {
						/// 751 -> 075
						///  47 ->  05
						if (dsor*dig_t(coc_uint)+dig_t(rem_uint) == rem) {
							coc[0] = dig_t{coc_uint};
							rem[1] = dig_t{rem_uint};
						}
						else if (dsor*dig_t(coc_uint)+dig_t(rem_uint) > rem) {
							/// PROBAR CON --coc_uint
							/// rem_2_uint HABRIA QUE INCREMETAR EL REM EN DSOR
							--coc_uint;
							auto temp = rem - dsor * dig_t(coc_uint);
							const SIG_UINT_T rem_2_uint{rem_uint+dsor[1]()*B+dsor[0]()};
							coc[0] = dig_t{coc_uint};
							rem[1] = dig_t{rem_2_uint};
						}
						else {
							/// PROBAR CON ++coc_uint
							/// rem_2_uint HABRIA QUE DECREMETAR EL REM EN DSOR
							++coc_uint;
							auto temp = rem - dsor * dig_t(coc_uint);
							const SIG_UINT_T rem_3_uint{rem_uint-dsor[1]()*B-dsor[0]()};
							coc[0] = dig_t{coc_uint};
							rem[1] = dig_t{rem_3_uint};
						}
						/// Caso estandar
					}
					else if (rem[2].is_0() && dsor[1].is_not_0()) {
						/// 751 -> 075
						///  99 ->  10
						rem >>= 1;
						coc <<= 1;
						/// Caso de division por BASE
					}
					///		else if (rem[2].is_not_0() && dsor[1].is_0()) {
					///			/// 999 -> 100 D*B^2
					///			///  27 ->  03 E
					///			/// D*B^2 / E > B
					///			///< ESTE CASO NO SE PUEDE DAR
					///			/// Se ha de reducir el rem practico a los 2 primeros
					///		}
					else {
						/// 999 -> 100
						///  99 ->  10
						rem = cero_rem;
						coc <<= 1;
					}
					coc[0] = dig_t{coc_uint};
					rem[1] = dig_0();
					rem[0] = dig_t{rem_uint};
				}
				ret.result_content_remainder[0] = rem[0];
				ret.result_content_remainder[1] = rem[1];
				ret.result_content_remainder[2] = rem[2];
				return std::move(ret);
			}
		}

//		noexcept {
//			const nat_reg_digs_t& dndo{*this};
//			const dig_t&      dsor{arg};
//			const nat_reg_digs_t<UINT_T,B,2> tmp_dsor{dig_0(),arg};
//						nat_reg_digs_t<UINT_T,B,2> part_rem{dig_0(),dndo[L-1]};
//						nat_reg_digs_t rem{regd_0()};
//						nat_reg_digs_t coc{regd_0()};
//			if (dsor == dig_0()) {
//				std::array<nat_reg_digs_t,2> rem_coc{regd_0(),regd_0()};
//				return rem_coc;/// ERROR DIVISION BY 0
//			}
//			else if (dsor == dig_1()) {
//				std::array<nat_reg_digs_t,2> rem_coc{regd_0(),(*this)};
//				return rem_coc;
//			}
//			else if ((dndo == regd_0())||(dndo == regd_1())) {
//				std::array<nat_reg_digs_t,2> rem_coc{(*this),regd_0()};
//				return rem_coc;
//			}
//			else if (dndo < regd_B()) {
//					dig_t retcoc{dndo[1]/dsor};
//					dig_t retrem{dndo[1]%dsor};
//					coc[0]=retcoc;
//					rem[0]=retrem;
//					return std::make_pair(rem,coc);
//			}
//			else {
//				nat_reg_digs_t<UINT_T,B,2> tmp_dsor{dig_0(),arg};
//				std::int64_t ph_dndo{L-1};
//				std::int64_t pl_dndo{L-1};
//				// ph_dndo >= ix >= pl_dndo
//				while((ph_dndo>-1)&&(pl_dndo>-1)) {
//					if (pl_dndo == L-1) {
//						part_rem[1] = dig_0();
//						part_rem[0] = dndo[L-1];
//					}
//					else if ((pl_dndo == 0)&&(ph_dndo == 1)) {
//						part_rem[1] = dndo[1];
//						part_rem[0] = dndo[0];
//					}
//					else if ((pl_dndo == 0)&&(ph_dndo == 0)) {
//						part_rem[1] = dig_0();
//						part_rem[0] = dndo[0];
//					}
//					else if (ph_dndo > pl_dndo) {
//						part_rem[1] = dndo[ph_dndo];
//						part_rem[0] = dndo[pl_dndo];
//					}
//					else {
//						part_rem[1] = dig_0();
//						part_rem[0] = dndo[pl_dndo];
//					}
//
//					coc << 1;
//					if (part_rem>=tmp_dsor) {
//						dig_t cocdig{dig_0()};
//						while(part_rem>=tmp_dsor) {
//							++cocdig;
//							part_rem -= tmp_dsor;
//						}
//						coc |= cocdig;
//						if (ph_dndo > pl_dndo) {
//							--ph_dndo;
//							--pl_dndo;
//						}
//						else {
//							--pl_dndo;
//						}
//					}
//					else {
//						if (ph_dndo > pl_dndo) {
//							--ph_dndo;
//							--pl_dndo;
//						}
//						else {
//							--pl_dndo;
//						}
//					}
//				}
//				rem[1]=part_rem[1];
//				rem[0]=part_rem[0];
//				std::array<nat_reg_digs_t,2> rem_coc{std::make_pair(rem,coc)};
//				return rem_coc;
//			}
//		}

		/// DIVISION BY A DIGIT
		constexpr inline
		nat_reg_digs_t operator / (dig_t arg) const noexcept
		{
			return ((this->fediv(arg)).result_content_quotient);
		}

		/// REMAINDER BY A DIGIT
		constexpr inline
		nat_reg_digs_t operator % (dig_t arg) const noexcept
		{
			return ((this->fediv(arg)).result_content_remainder);
		}

								/****************************************/
								/*									    								*/
								/* OPERADORES ARITMETICOS		  					*/
								/* nat_reg_digs_t @ nat_reg_digs_t			*/
								/*                            					*/
								/****************************************/

	template<size_t N>
		requires (N>0)
	constexpr inline
	const nat_reg_digs_t & operator += (const base_N_t<N> & arg) noexcept
	{
		nat_reg_digs_t & cthis = (*this);
		dig_t  				carry{0};
		if constexpr (N < L) {
			for (size_t ix{0} ; ix < N ; ++ix) {
				dig_t& 				cthis{cthis.m_dc[ix]};
				const dig_t  	cpthis{cthis.m_dc[ix]};
				const dig_t  	cparg{arg[ix]};
				cthis += cparg;
				cthis += carry;
				if ((cthis < cpthis) || (cparg < cpthis))
					carry = dig_1();
			}
			for (size_t ix{N} ; ix < L ; ++ix) {
				dig_t& 				cthis{cthis.m_dc[ix]};
				const dig_t  	cpthis{cthis.m_dc[ix]};
				cthis += carry;
				if (cthis < cpthis)
					carry = dig_1();
			}
		}
		else {
			for (size_t ix{0} ; ix < L ; ++ix) {
				dig_t& 				cthis{cthis.m_dc[ix]};
				const dig_t  	cpthis{cthis.m_dc[ix]};
				const dig_t  	cparg{arg[ix]};
				cthis += cparg;
				cthis += carry;
				if ((cthis < cpthis) || (cparg < cpthis))
					carry = dig_1();
			}
		}
		return (cthis);
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	const nat_reg_digs_t & operator += (const nat_reg_N_digs_t<N> & arg) noexcept
	{
		(*this)+= arg.m_dc;
		return (*this);
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	const nat_reg_digs_t & operator -= (const base_N_t<N> & arg) noexcept
	{
		nat_reg_digs_t & cthis{*this};
		base_N_t<N> cparg{arg};
		///< cparg pasa a ser el complemento a la base menos 1 de cparg
			// begin
			for(auto & elem_dig : cparg) {
				elem_dig = dig_t(B-1)-elem_dig;
			}
			dig_t  			carry{0};
			for (size_t ix{0} ; ix < N ; ++ix) {
				dig_t& 				cthis{cthis.m_dc[ix]};
				const dig_t  	cpthis{cthis.m_dc[ix]};
				cthis += carry;
				if (cthis < cpthis)
					carry = dig_1();
			}
			// end
		cthis += cparg;
		return (cthis);
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	const nat_reg_digs_t & operator -= (const nat_reg_N_digs_t<N> & arg) noexcept
	{
		(*this)-= arg.m_dc;
		return (*this);
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	const nat_reg_digs_t & operator *= (const base_N_t<N> & arg) noexcept
	{
		nat_reg_digs_t cpthis{*this};
		nat_reg_digs_t& cthis{0};
		for(size_t ix{0} ; ix < N ; ++ix) {
			cthis += (cpthis*arg[ix]);
			cpthis <<= 1;
		}
		return (cthis);
	}

	template<size_t N>
		requires (N>0)
	constexpr inline
	const nat_reg_digs_t & operator *= (const nat_reg_N_digs_t<N> & arg) noexcept
	{
		(*this)*= arg.m_dc;
		return (*this);
	}

/// TO DO
//	constexpr inline
//	const nat_reg_digs_t & operator /= (const nat_reg_digs_t & arg)
//	noexcept {
//		nat_reg_digs_t & ret = (*this);
//		/// TO DO
//		return (*this);
//	}
/// TO DO
//	constexpr inline
//	const nat_reg_digs_t & operator %= (const nat_reg_digs_t & arg)
//	noexcept {
//		nat_reg_digs_t & cthis{*this};
//		/// TO DO
//		return (*this);
//	}

		template<size_t N>
		constexpr inline
		nat_reg_digs_t operator + (const base_N_t<N> & arg) const noexcept
		{
			nat_reg_digs_t ret(*this);
			ret += arg;
			return std::move(ret);
		}

		template<size_t N>
		constexpr inline
		nat_reg_digs_t operator - (const base_N_t<N> & arg) const noexcept
		{
			nat_reg_digs_t ret(*this);
			ret -= arg;
			return ret;
		}

		template<size_t N>
		constexpr inline
		nat_reg_digs_t operator * (const base_N_t<N> & arg) const noexcept
		{
			nat_reg_digs_t ret(*this);
			ret *= arg;
			return ret;
		}

		template<size_t N>
		constexpr inline
		nat_reg_digs_t operator + (const nat_reg_N_digs_t<N> & arg) const noexcept
		{
			nat_reg_digs_t ret(*this);
			ret += arg;
			return ret;
		}

		template<size_t N>
		constexpr inline
		nat_reg_digs_t operator - (const nat_reg_N_digs_t<N> & arg) const noexcept
		{
			nat_reg_digs_t ret(*this);
			ret -= arg;
			return ret;
		}

		template<size_t N>
		constexpr inline
		nat_reg_digs_t operator * (const nat_reg_N_digs_t<N> & arg) const noexcept
		{
			nat_reg_digs_t ret(*this);
			ret *= arg;
			return ret;
		}


		constexpr inline static
		size_t cuenta_0s_desde_IZDA(const reg_ints_t<L>& arg) noexcept
		{
			size_t ret{0};
			for(std::int64_t ix{L-1} ; ix > -1 ; --ix) {
				if (arg[ix]==0) {
					++ret;
				}
				else {
					return ret;
				}
			}
			return L;
		}

		constexpr inline static
		size_t cuenta_0s_desde_DRCHA(const reg_ints_t<L>& arg) noexcept
		{
			size_t ret{0};
			for(std::int64_t ix{0} ; ix < L ; ++ix) {
				if (arg[ix]==0) {
					++ret;
				}
				else {
					return ret;
				}
			}
			return L;
		}

		constexpr inline
		nat_reg_digs_t operator / (const nat_reg_digs_t & arg) const noexcept
		{
			const nat_reg_digs_t& dndo{*this};
			const nat_reg_digs_t& dsor{arg};
			const int32_t num_0s_IZDA_dsor{cuenta_0s_desde_IZDA(dsor)};
			const int32_t num_0s_IZDA_dndo{cuenta_0s_desde_IZDA(dndo)};
			const int32_t MSDig_dsor{L-1-num_0s_IZDA_dsor};
				/// MOST SIGNIFICANT DIGIT DEL DIVISOR [DEL NUMERO NO DEL TIPO]
			const int32_t MSDig_dndo{L-1-num_0s_IZDA_dndo};
				/// MOST SIGNIFICANT DIGIT DEL DIVIDENDO [DEL NUMERO NO DEL TIPO]
			const size_t  dist_dndo_dsor{std::abs(MSDig_dndo-MSDig_dndo)};
			nat_reg_digs_t rem{regd_0()};
			nat_reg_digs_t coc{regd_0()};
			for(size_t num_loops{0} ; num_loops < dist_dndo_dsor ; ++num_loops)
			{
				if (MSDig_dsor > MSDig_dndo) {
					coc.set_0();
					return coc;// DEVUELVE COCIENTE := 0 Y RESTO := DNDO
				}
				else if (MSDig_dsor == MSDig_dndo) {
					for(int32_t ix{MSDig_dsor} ; ix > -1 ; --ix) {
							if (dsor[ix] > dndo[ix]) {
								return regd_0();// DEVUELVE COCIENTE := 0 Y RESTO := DNDO
							}
							else if (dsor[ix] == dndo[ix]) {
								if (ix == 0) {
									coc.set_1();
									return coc;// DEVUELVE COCIENTE := 1 Y RESTO := 0
								}
							}
							else {
								nat_reg_digs_t coc{0};
								nat_reg_digs_t idndo{dndo};
								nat_reg_digs_t idsor{dsor};
								while (idndo >= idsor) {
									idndo -= idsor;
									++coc[0];
								}
								return coc; // DEVUELVE COCIENTE := 000...L-1...0D
														// SIENDO D EL DIGITO 0 (Y EL VALOR DE COCIENTE)
														// DEVUELVE RESTO    := DNDO - DSOR * D
							}
					}
				}
				else if (dsor == regd_1()) {
					return coc;// DEVUELVE COCIENTE := DNDO Y RESTO := 0
				}
				else if (dsor == regd_0()) {
					coc.set_0();
					return coc;/// ERROR DIVISION BY 0
										 // DEVUELVE COCIENTE := 0 Y RESTO := 0
				}
				else {
					int32_t pl_dndo{MSDig_dsor};
					int32_t ph_dndo{MSDig_dndo};

					// ph_dndo >= ix > pl_dndo
					for(int32_t ix{pl_dndo} ; ix <= ph_dndo ; ++ix) {
						rem[ix-pl_dndo] = dndo[ix];
					}

					if (rem == dsor) {
						coc.set_1();
						return regd_1();// DEVUELVE COCIENTE:=1 Y RESTO:=0
					}
					else if (rem > dsor) {
						dig_t coc_dig{dig_0()};
						while(rem > dsor) {
							++coc_dig;
							rem -= dsor;
						}
						coc *= regd_B(); 	// coc = coc * B
						coc[0] = coc_dig; // coc = coc + D  ; B-1 >= D > 1
						--pl_dndo;
						for(int32_t ix{ph_dndo} ; ix > pl_dndo ; --ix) {
							rem[ix-pl_dndo+1] = rem[ix-pl_dndo];
						}
						rem[pl_dndo] = dndo[pl_dndo];
						--ph_dndo;
					}
					else {
						if (pl_dndo != 0) {
							--pl_dndo;
							for(int32_t ix{ph_dndo} ; ix > pl_dndo ; --ix) {
								rem[ix-pl_dndo+1] = rem[ix-pl_dndo];
							}
							rem[pl_dndo] = dndo[pl_dndo];
							coc *= regd_B(); // coc = coc * B
							rem -= dsor;    // coc = coc + 0
						}
						else {
							return coc;// DEVOLVEMOS LO CALCULADO EN COC Y EL RESTO ES REM
						}
					}
				}
			}
			return coc;// NO SE DEBERÍA LLEGAR AQUI
		}

		constexpr inline
		nat_reg_digs_t operator % (const nat_reg_digs_t & arg) const noexcept
		{
			nat_reg_digs_t ret(*this);
			UINT_T retuds 	= ret(0);
			UINT_T retdecs 	= ret(1);
			UINT_T arguds 	= arg(0);
			UINT_T argdecs 	= arg(1);

			retuds 	+= (B*retdecs);
			arguds 	+= (B*argdecs);
			retuds 	%= arguds;
			retdecs  = retuds;
			retdecs /= B;
			retuds 	%= B;
			ret.m_dc[1] 	= dig_t(retdecs);
			ret.m_dc[0] 	= dig_t(retuds);
			return ret;
		}

};


					/****************************/
					/*													*/
					/* 	   ISTREAM Y OSTREAM		*/
					/*													*/
					/****************************/

	///	TODO
	/// ESTA VERSION +
	/// VERSION CON TRATAMIENTO DE ERRORES EN RUNTIME
	template<type_traits::allowable_base_type_c Int_Type,
					Int_Type Base,
					size_t Length>
		requires (type_traits::suitable_base<Int_Type,Base>()&&(Length > 0))
	std::istream &
	operator >> (std::istream & is,nat_reg_digs_t<Int_Type,Base,Length> & arg) {
		enum estado_e {
			e0ini	, e1r		, e1e		, e1g			, e1sep		,
			e1d		, e1i		, e2g		, e2start	, e2dig		,
			e2dp	, e2end	, e2B		, e3dig		, e0fin
		};
		/// STRING RECOGIDO DESDE LA ENTRADA ESTANDAR CIN
		std::string sds;
		/// TIPOS A SER UTILIZADOS EN LA FUNCIÓN: NOMBRE DE TIPOS CORTOS
		using inttype = typename type_traits::sig_UInt_for_UInt_t<Int_Type>;
		using dig_t = dig_t<Int_Type,Base>;
		using nat_reg_digs_t = nat_reg_digs_t<Int_Type,Base,Length>;
		/// INDICE QUE RECORRE EL STRING RECOGIDO DE ENTRADA
		size_t	indice{0};
		/// VARIABLES PARA ACCIONES EN LOS ESTADOS
		Int_Type 		digito{0};
		size_t longitud{0};
		inttype 		numero_base_recogido{0};
		/// VARIABLE DE RETORNO (BINDED TO THE ARG BY REFERENCE)
		nat_reg_digs_t& numero_ret{arg};
		/// ESTADO ACTUAL
		estado_e est_act = e0ini;
		/// CARACTER QUE GUARDARA EL INDICADO POR EL INDICE DEL STRING RECOGIDO DESDE CIN
		char c{'\0'};
		/// RECOGEMOS DESDE LA ENTRADA EL STRING CON LA INFORMACION CODIFICADA
		is >> sds;
		/// MAQUINA DE ESTADOS FINITOS QUE HACE EL PARSE() DE LA ENTRADA
		do {
			c = sds[indice];
			switch(est_act) {
				case e0ini :
					{
						if (c=='r') {
							est_act = e1r;
						} else {
							est_act = e0ini;
						}
					}
					break;
				case e1r :
					{
						{
							if (c=='e') {
								est_act = e1e;
							}
							else {
								est_act = e0ini;
							}
						}
					}
					break;
				case e1e :
					{
						if (c=='g') {
							est_act = e1g;
						}
						else  {
							est_act = e0ini;
						}
					}
					break;
				case e1g :
					{
						if (c=='_') {
							est_act = e1sep;
						}
						else  {
							est_act = e0ini;
						}
					}
					break;
				case e1sep :
					{
						if (c=='d') {
							est_act = e1d;
						}
						else  {
							est_act = e0ini;
						}
					}
					break;
				case e1d :
					{
						if (c=='i') {
							est_act = e1i;
						}
						else  {
							est_act = e0ini;
						}
					}
					break;
				case e1i :
					{
						if (c=='g') {
							est_act = e2g;
						}
						else  {
							est_act = e0ini;
						}
					}
					break;
				case e2g :
					{
						if (c=='#') {
							est_act = e2start;
						}
						else  {
							est_act = e0ini;
						}
					}
					break;
				case e2start :
					{
						if (((c>='0')&&(c<='9'))&&(std::abs(c-'0')<Base)) {
							est_act = e2dig;
							digito = (c-'0');
							longitud = 0;
							numero_base_recogido = 0;
							numero_ret = nat_reg_digs_t::regd_0();
						}
						else  {
							est_act = e0ini;
							digito = 0;
							longitud = 0;
							numero_base_recogido = 0;
							numero_ret = nat_reg_digs_t::regd_0();
						}
					}
					break;
				case e2dig :
					{
						const bool dig_c {(c >= '0') && (c <= '9')};
						const bool dig_lt_Base{digito<Base};
						const bool c_es_dig_B {dig_c && dig_lt_Base};
						const bool dig_B_cdl {c_es_dig_B && (longitud < Length-1)};
						const bool tt_dig_B_cdl {(c==':')&&dig_lt_Base&&(longitud < Length-1)};
						const bool tf_dig_B_cdl {(c=='#')&&dig_lt_Base&&(longitud == Length-1)};
						if (dig_B_cdl) {
							digito *= 10;
							digito += (c-'0');
							est_act = e2dig;
						}
						else if (tt_dig_B_cdl) {
							est_act = e2dp;
						}
						else if (tf_dig_B_cdl) {
							est_act = e2end;
						}
						else  {
							est_act = e0ini;
							digito = 0;
							longitud = 0;
							numero_base_recogido = 0;
							numero_ret = nat_reg_digs_t::regd_0();
						}
					}
					break;
				case e2dp :
					{
						const bool dig_c {(c >= '0') && (c <= '9')};
						const bool c_es_dig_B {(std::abs(c-'0')<Base) && (digito<Base)};
						const bool dig_B_cdl {dig_c && c_es_dig_B && (longitud < Length-1)};
						const bool rdig_B_cdl {dig_c && c_es_dig_B && dig_B_cdl};
						if (rdig_B_cdl) {
							est_act = e2dig;
							numero_ret[Length-1-longitud] = dig_t(digito);
							++longitud;
							digito = c-'0';
						}
						else  {
							est_act = e0ini;
							digito = 0;
							longitud = 0;
							numero_base_recogido = 0;
							indice = 0;
							numero_ret = nat_reg_digs_t::regd_0();
						}
					}
					break;
				case e2end :
					{
						const bool c_es_sepfin {c == 'B'};
						const bool d_es_digB {digito < Base};
						const bool l_coincide {longitud == Length-1};// llega al cero ?
						const bool rdigB_cdl {c_es_sepfin && d_es_digB && l_coincide};
						if (rdigB_cdl) {
							est_act = e2B;
							numero_ret[Length-1-longitud] = dig_t(digito);
							digito = 0;
							longitud = 0;
						}
						else  {
							est_act = e0ini;
							indice = 0;
							digito = 0;
							longitud = 0;
							numero_ret = nat_reg_digs_t::regd_0();
						}
					}
					break;
				case e2B :
					{
						if ((c >= '0')&&(c <= '9')) {
							est_act = e3dig;
							numero_base_recogido = c-'0';
							digito = 0;
						}
						else  {
							est_act = e0ini;
							digito = 0;
							longitud = 0;
							numero_base_recogido = 0;
							numero_ret = nat_reg_digs_t::regd_0();
						}
					}
					break;
				case e3dig :
					{
						const bool espacio_c {c < 16};
						const bool digito_c {(c>='0') && (c<='9')};
						const bool num_base_lt_Base {numero_base_recogido < Base};
						const bool num_base_eq_Base {numero_base_recogido == Base};
						if (digito_c && num_base_lt_Base) {
							est_act = e3dig;
							numero_base_recogido *= 10;
							numero_base_recogido += (c-'0');
						}
						else if (espacio_c && num_base_eq_Base) {
							numero_base_recogido *= 10;
							numero_base_recogido += (c-'0');
								est_act = e0fin;
								numero_base_recogido = 0;
						}
						else  {
							est_act = e0ini;
							numero_base_recogido = 0;
						}
					}
					break;
				case e0fin :
					{
						est_act = e0fin;
					}
			}
			++indice;
		} while (est_act!=e0fin);

		return (is);
	}

	template<type_traits::allowable_base_type_c Int_Type,Int_Type Base,size_t Long>
		requires (type_traits::suitable_base<Int_Type,Base>())
	std::ostream &
	operator << (std::ostream & os,const nat_reg_digs_t<Int_Type,Base,Long> & arg) {
		using inttype = typename type_traits::sig_UInt_for_UInt_t<Int_Type>;
		os << "reg_dig#";
		for(int32_t ix{Long-1} ; ix > 0 ; --ix) {
				os << static_cast<inttype>(arg(ix));
				os << ':';
		}
		os << static_cast<inttype>(arg(0));
		os << "#B";
		os << static_cast<inttype>(Base);
		return (os);
	}

}
#endif // NAT_REG_DIGS_T_HPP_INCLUDED