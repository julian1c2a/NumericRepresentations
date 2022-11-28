#ifndef NAT_REG_DIGS_T__HPP__INCLUDED
#define NAT_REG_DIGS_T__HPP__INCLUDED

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
	using reg_ints_t		= typename std::array<UINT_T,N>;
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
		base_N_t<N> ret;
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
	bool is_any_B_pow(const base_N_t<N> & arg) noexcept
	{
		const auto pred_not_0 = [](dig_t d){return (d.is_not_0());};
		const auto it{std::find_if(arg.begin(),arg.end(),pred_not_0)};
		if (it != arg.end()) {
			const size_t card{std::count_if(arg.begin(),arg.end(),pred_not_0)};
			if (card != 1)
				return false;
			else
				return (is_0(*it));
		}
	}

	template<size_t N>
		requires (N>0)
	static inline constexpr
	int32_t index_of_MSDig(const base_N_t<N> & arg) noexcept
	{
		for(int32_t ix{N-1} ; ix > -1 ; --ix) {
			if (arg[ix].is_not_0())
				return ix;
		}
		return (-1);
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
	///< PREINCREMENT(OBJ) == ++OBJ SOLO QUE DEVUELVE CARRY TAMBIÉN
	///< PREINCREMENT(OBJ) -> CONDICIONALMENTE
	///< 			BIEN RES_BASE_OP_T 	(con CARRY),
	///<			BIEN BASE_T 		(sin CARRY)

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
			>		noexcept
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

	/// FUNCIONES DE IMPLEMENTACION DE LA DIVISION ENTRE DOS REGISTROS DE DIGITOS
	/// BEGIN
		template<size_t N>
			requires (N>1)
		static constexpr inline
		base_N_t<N> aprox_units_divB(const base_N_t<N>& arg) noexcept
			///< PRECONDITIONS : ARG != 0 AND ARG != 1 >\\\
		{
			/// CASO EN QUE LA LONGITUD PERMANECE
			///  999 		; 998 	; 997 	; 996
			///  099,9 	; 099,8 ; 099,7 ; 099,6
			///  100		; 100		;	100		;	100
			base_N_t<N> cparg{arg};
			if ((cparg[0]<= dig_t{B/2})||(is_any_B_pow(cparg))) {
				cparg >>= 1;
				return std::move(cparg);
			}
			else if (cparg[N-1].is_not_Bm1()) {
				cparg >>= 1;
				preincrement<false>(cparg);
				return std::move(cparg);
			}
			else {
				if (subregister<N,1,N>(arg).is_fill_of_Bm1()){
					/// CPARG == Bm1 Bm1 Bm1 ... Bm1 Bm1 Bm1 d0<B/2
					cparg.set_0();
					cparg[N-1].set_1();
					return std::move(cparg);
				}
				else {
					/// CPARG == Bm1 dnm2 dnm3 ... d3 d2 d1 d0
					cparg >>= 1;
					preincrement<false>(cparg);
					return std::move(cparg);
				}
			}
		} ///< POSTCONDICION RET[N-1] == (DIG_1() | DIG_0())									>\\\
			///< POSTCONDICION RET[N-1] == DIG_1() => RET[N-2,0] == REGD_N_0()	>\\\

		///< HAY QUE VER SI ES POTENCIA DE B : is_any_B_pow
		template<size_t N,size_t n>
			requires ((n > 0) && (n < N) && (N > 1)) /// N == SIZE_FROM n == SIZE_TO
		static constexpr inline
		base_N_t<N> aprox_units_divB_n(const base_N_t<N>& arg) noexcept
		{
			if constexpr (n == N-1){
				return std::move(aprox_units_divB<N>(arg));
			}
			else {
				base_N_t<N> cparg{arg}; // n = N-x => x = N-n
				for(size_t ix{0} ; ix < N-n ; ++ix) {
					cparg = std::move(aprox_units_divB<N>(cparg));
				}
				return std::move(cparg);
			}
		}

		///< FUNCION DE RECURSION PARA LA DIVISION
    template<size_t N>
			requires (N > 0)
    static constexpr inline
    /// std::array<SIG_UINT_T,2>{}[0] == COC
    /// std::array<SIG_UINT_T,2>{}[1] == REM
    /// PRECONDICION DSOR != 0 Y DSOR != 1
    std::array<SIG_UINT_T,2> aprox_coc_rem(
				const base_N_t<N>& rem	  , const base_N_t<N>& dsor	) noexcept
		{
			std::array<SIG_UINT_T,2> ret;
			const size_t dsor_msb{static_cast<size_t>(index_of_MSDig(dsor))};
			if (dsor_msb==0) {
				/// SIZE(DIVISOR) == 1 DIGITO !=0 !=1
				const SIG_UINT_T rem_uint {SIG_UINT_T(rem)};
				const SIG_UINT_T dsor_uint {dsor[0]()};
				SIG_UINT_T coc_calculado = rem_uint / dsor_uint;
				SIG_UINT_T rem_calculado = rem_uint % dsor_uint;
				const SIG_UINT_T rem_aprox {SIG_UINT_T(dsor)*coc_calculado+rem_calculado};

				ret[1] = rem_calculado;
				ret[0] = coc_calculado;
				return std::move(ret);
			}
			else {
				/// SIZE(DIVISOR) >= 2
				/// 2545/278 o mayores
				base_N_t<N> dsor_red{dsor};
				int32_t ix{0};
				for( ; ix < N ; ++ix) {
					dsor_red = aprox_units_divB<N>(dsor_red);
					if (index_of_MSDig<N>(dsor_red) == 1)
						break;
				}
				base_N_t<N> rem_red{rem};
				for( ; ix > -1 ; --ix) {
					rem_red = aprox_units_divB<N>(rem_red);
				}

				const SIG_UINT_T dsor_uint {SIG_UINT_T(dsor_red)};
				const SIG_UINT_T rem_uint {SIG_UINT_T(rem_red)};
				const base_N_t<N> rem_aprox {dsor*dig_t{coc_calculado}+dig_t{rem_calculado}};

				if ((rem_aprox <= rem)&&(rem_aprox + dsor > rem)) {
					/// CORRECTO EN COC
					ret[1] = rem_calculado;
					ret[0] = coc_calculado;
					return std::move(ret);
				}
				else if (rem_aprox > rem) {
					/// NOS HEMOS PASADO EN EL COC
					--coc_calculado;
					rem_calculado += dsor_uint;
					return aprox_coc_rem(rem,dsor,coc_calculado,rem_calculado);
				}
				else {
					/// NOS HEMOS QUEDADO CORTOS EN EL COC rem_aprox + dsor_uint <= rem
					++coc_calculado;
					rem_calculado -= dsor_uint;
					return aprox_coc_rem(rem,dsor,coc_calculado,rem_calculado);
				}
			}
    }

		///< FUNCION DE RECURSION PARA LA DIVISION
		///< SOBRECARGA DE LA ANTERIOR PARA LA RECURSION QUE NO SEA EL PRIMER CASO
    template<size_t N>
			requires (N > 0)
    static constexpr inline
    /// std::array<SIG_UINT_T,2>{}[0] == COC
    /// std::array<SIG_UINT_T,2>{}[1] == REM
    /// PRECONDICION DSOR != 0 Y DSOR != 1
    std::array<SIG_UINT_T,2> aprox_coc_rem(
				const base_N_t<N>& rem	  , const base_N_t<N>& dsor	,
				SIG_UINT_T coc_calculado 	, SIG_UINT_T rem_calculado
			) noexcept
		{ /// SUPONEMOS QUE REM TIENE TAMANO 1 o 2
			/// DSOR YA REDUCIDO TIENE TAMANO 1
			std::array<SIG_UINT_T,2> ret;
			const size_t dsor_msb{static_cast<size_t>(index_of_MSDig(dsor))};
			if (dsor_msb==0) {
				/// SIZE(DIVISOR) == 1 DIGITO !=0 !=1
				const SIG_UINT_T rem_aprox {SIG_UINT_T(dsor)*coc_calculado+rem_calculado};
				const SIG_UINT_T rem_uint {SIG_UINT_T(rem)};
				const SIG_UINT_T dsor_uint {dsor[0]()};
				if ((rem_aprox <= rem_uint)&&(rem_aprox + dsor_uint > rem_uint)) {
					/// CORRECTO EN COC
					ret[1] = rem_calculado;
					ret[0] = coc_calculado;
					return std::move(ret);
				}
				else if (rem_aprox > rem) {
					/// NOS HEMOS PASADO EN EL COC
					--coc_calculado;
					rem_calculado += dsor_uint;
					return aprox_coc_rem(rem,dsor,coc_calculado,rem_calculado);
				}
				else {
					/// NOS HEMOS QUEDADO CORTOS EN EL COC rem_aprox + dsor_uint <= rem
					++coc_calculado;
					rem_calculado -= dsor_uint;
					return aprox_coc_rem(rem,dsor,coc_calculado,rem_calculado);
				}
				/// 24/7
			}
			else {
				/// SIZE(DIVISOR) >= 2
				/// 2545/278 o mayores
				base_N_t<N> dsor_red{dsor};
				int32_t ix{0};
				for( ; ix < N ; ++ix) {
					dsor_red = aprox_units_divB<N>(dsor_red);
					if (index_of_MSDig<N>(dsor_red) == 1)
						break;
				}
				base_N_t<N> rem_red{rem};
				for( ; ix > -1 ; --ix) {
					rem_red = aprox_units_divB<N>(rem_red);
				}

				const SIG_UINT_T dsor_uint {SIG_UINT_T(dsor_red)};
				const SIG_UINT_T rem_uint {SIG_UINT_T(rem_red)};
				const base_N_t<N> rem_aprox {dsor*dig_t{coc_calculado}+dig_t{rem_calculado}};

				if ((rem_aprox <= rem)&&(rem_aprox + dsor > rem)) {
					/// CORRECTO EN COC
					ret[1] = rem_calculado;
					ret[0] = coc_calculado;
					return std::move(ret);
				}
				else if (rem_aprox > rem) {
					/// NOS HEMOS PASADO EN EL COC
					--coc_calculado;
					rem_calculado += dsor_uint;
					return aprox_coc_rem(rem,dsor,coc_calculado,rem_calculado);
				}
				else {
					/// NOS HEMOS QUEDADO CORTOS EN EL COC rem_aprox + dsor_uint <= rem
					++coc_calculado;
					rem_calculado -= dsor_uint;
					return aprox_coc_rem(rem,dsor,coc_calculado,rem_calculado);
				}
			}
    }
	/// END
	/// FUNCIONES DE IMPLEMENTACION DE LA DIVISION ENTRE DOS REGISTROS DE DIGITOS

	///	TODO TO	DO 36 : 20 : 25 : 11 : 2022
	/// TODO TO	DO	repasar que el tipo de vuelta cambie y sea :
	/// 	std::array<base_N_t<N>,2> -> res_base_N_op_t<N,binop_e::fediv>
	/// '@' = FULL_EUCLID_DIV(BASE_T,DIG_T) -> (REM,COC,GOOD)
	template<size_t N>
		requires (N > 0)
	static constexpr inline
	std::array<base_N_t<N>,2> fediv(const base_N_t<N> & larg,const base_N_t<N> & rarg)
	noexcept {

		using ret_type = std::array<base_N_t<N>,2>;
		using ret_aprox_type = std::array<SIG_UINT_T,2>;

		base_N_t<N> dndo{larg};
		base_N_t<N> dsor{rarg};

		const int32_t dsor_MSDig{index_of_MSDig(larg)};
			/// MOST SIGNIFICANT DIGIT DEL DIVISOR [DEL NUMERO NO DEL TIPO]
		const int32_t dndo_MSDig{index_of_MSDig(rarg)};
			/// MOST SIGNIFICANT DIGIT DEL DIVIDENDO [DEL NUMERO NO DEL TIPO]
		const size_t  dist_dndo_dsor{std::abs(dndo_MSDig-dndo_MSDig)};

		base_N_t<N> rem{regd_N_0<N>()};
		base_N_t<N> coc{regd_N_0<N>()};

		if (is_0(dvsor)) {
			ret_type ret;
			ret[0] = std::move(coc);
			ret[1] = std::move(rem);
			return std::move(ret);
		}
		else if (is_1(dvsor)) {
			ret_type ret;
			ret[0] = dndo;
			set_0<N>(ret[1]);
			return std::move(ret);
		}
		else if (dndo < dsor) {
			ret_type ret;
			set_0<N>(ret[0]);
			ret[1] = dndo;
			return std::move(ret);
		}
		else if (dndo == dsor) {
			ret_type ret;
			set_1<N>(ret[0]);
			set_0<N>(ret[1]);
			return std::move(ret);
		}
		else {
			int32_t pl_dndo{dndo_MSDig-dsor_MSDig+1};
			for(int32_t ix{dsor_MSDig},iy{dndo_MSDig} ; ix > -1 ; --ix,--iy) {
				rem[ix] = dndo[iy];
			}

			for(size_t num_loops{0} ; num_loops < dist_dndo_dsor ; ++num_loops)
			{
				if (rem == dsor) {
					coc <<= 1;
					coc[0] = dig_1();
					rem = regd_base_N_0<N>();
					--pl_dndo;
					rem[0] = dndo[pl_dndo];
				}
				else if (rem < dsor) {
					coc <<= 1;
					coc[0] = dig_0();
					rem <= 1;
					--pl_dndo;
					rem[0] = dndo[pl_dndo];
				}
				///	else if (rem >= dsor*dig_B()) {
				///		este caso no se deberia de dar nunca
				///	}
				else {
					auto ret{aprox_coc_rem<N>(rem,dsor)};
					SIG_UINT_T coc_dig{ret[0]};
					SIG_UINT_T rem_dig{ret[1]};

					coc <<= 1; 	// coc = coc * B
					coc[0] = dig_t(coc_dig); // coc = coc + D  ; B-1 >= D > 1
					--pl_dndo;
					rem <<= 1;
					rem[0] = dndo[pl_dndo];
				}
			}
			ret[0] = coc;
			ret[1] = rem;
			return std::move(ret);
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

		template<size_t N>
		static constexpr inline
		auto fediv<N,1>(const base_N_t<N>& larg,const base_N_t<1>& rarg)
		 -> res_base_N_op_t<binop_e::fediv>
		noexcept {
			const dig_t & arg{rarg[0]};
			return fediv<N>(larg,arg);
		}

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
#endif //NAT_REG_DIGS_T__HPP__INCLUDED
