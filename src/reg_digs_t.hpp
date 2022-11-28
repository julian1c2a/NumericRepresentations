#ifndef REG_DIGS_T_HPP_INCLUDED
#define REG_DIGS_T_HPP_INCLUDED

#include "dig_t.hpp"
#include "utilities.hpp"

namespace NumRepr {

using type_traits::allowable_base_type_c;
using type_traits::suitable_base;

template<allowable_base_type_c UINT_T,UINT_T B,size_t L>
  requires ((suitable_base<UINT_T,B>())&&(L > 0))
struct reg_digs_t {
public :
	using dig_t 				= dig_t<UINT_T,B>;

	template<size_t N>
		requires (N>0)
	using base_N_t      = std::array<dig_t,N>;

	using base_t				= base_N_t<L>;

protected :

	base_t m_dc;

public :

	using namespace auxiliary_types;
	using namespace auxiliary_functions;

	using type_traits::sig_UInt_for_UInt_t;
	using type_traits::sig_SInt_for_UInt_t;

	using SIG_UINT_T	= sig_UInt_for_UInt_t<UINT_T>;
	using SIG_SINT_T	= sig_SInt_for_UInt_t<UINT_T>;

	template<binop_e op,size_t N>
	using res_base_N_op_t	=	result_operation_t<base_N_t<N>,op,N>;

	template<binop_e op>
	using res_base_op_t		=	result_operation_t<base_t,op,L>;

	static consteval dig_t		dig_0()			noexcept
	{return dig_t::dig_0();}
	static consteval dig_t		dig_1()			noexcept
	{return dig_t::dig_1();}
	static consteval dig_t		dig_Bm1()		noexcept
	{return dig_t::dig_Bm1();}
	static consteval dig_t 		dig_max()		noexcept
	{return dig_t::dig_max();}
	static consteval dig_t 		dig_Bm2()		noexcept
	{return dig_t::dig_Bm2();}
	static consteval dig_t 		dig_submax()noexcept
	{return dig_t::dig_submax();}
	static consteval UINT_T		ui_0()			noexcept
	{return dig_t::ui_0();}
	static consteval UINT_T		ui_1() 			noexcept
	{return dig_t::ui_1();}
	static consteval UINT_T		ui_Bm1() 		noexcept
	{return B-1;}
	static consteval UINT_T		ui_B() 			noexcept
	{return B;}
	static consteval UINT_T		ui_submax()	noexcept
	{return dig_t::ui_submax();}
	static consteval UINT_T		ui_max() 		noexcept
	{return dig_t::ui_max();}
	static consteval SIG_UINT_T	sui_0()		noexcept
	{return dig_t::sui_0();}
	static consteval SIG_UINT_T	sui_1() 	noexcept
	{return dig_t::sui_1();}
	static consteval SIG_UINT_T sui_Bm1() noexcept
	{return dig_t::sui_B()-1;}
	static consteval SIG_UINT_T	sui_B() 	noexcept
	{return dig_t::sui_B();}
	static consteval SIG_UINT_T sui_Bp1() noexcept
	{return dig_t::sui_B()+1;}
	static consteval SIG_SINT_T	ssi_0()		noexcept
	{return dig_t::ssi_0();}
	static consteval SIG_SINT_T	ssi_1() 	noexcept
	{return dig_t::ssi_1();}
	static consteval SIG_SINT_T ssi_Bm1() noexcept
	{return dig_t::ssi_B()-1;}
	static consteval SIG_SINT_T	ssi_B() 	noexcept
	{return dig_t::ssi_B();}
	static consteval SIG_SINT_T ssi_Bp1() noexcept
	{return dig_t::ssi_B()+1;}

	/// <summary>
	/// PARA EL TIPO-TEMPLATE BASE_N_T OBTENEMOS CONSTANTES INMEDIATAS
	/// TENEMOS CUIDADO DE CREAR UN RVALUE TEMPORAL
	/// </summary>

	template<size_t N>
	static consteval
	base_N_t<N>	regd_base_N_0() noexcept {
		base_N_t<N> ret;
		for(dig_t& dig : ret) {
			dig = dig_0();
		}
		return ret;
	}

	template<size_t N>
	static consteval
	base_N_t<N>	regd_base_N_1() noexcept {
		base_N_t<N> ret{regd_base_N_0<N>()};
		ret[0] = dig_1();
		return ret;
	}

	template<size_t N>
	static consteval
	base_N_t<N>	regd_base_N_Bm1() noexcept {
		base_N_t<N> ret{regd_base_N_0<N>()};
		ret[0] = dig_Bm1();
		return ret;
	}

	template<size_t N>
	static consteval
	base_N_t<N>	regd_base_N_B() noexcept {
		base_N_t<N> ret{regd_base_N_0<N>()};
		ret[1] = dig_1();
		return ret;
	}

	template<size_t N,size_t n>
		requires ((n>=0)&&(n < N))
	static consteval
	base_N_t<N>	regd_base_N_pow_n_B() noexcept {
		base_N_t<N> ret{regd_base_N_0<N>()};
		ret[n] = dig_1();
		return ret;
	}

	template<size_t N,size_t n>
		requires ((n>=0)&&(n < N))
	static consteval
	base_N_t<N>	regd_base_N_pow_n_B_m1() noexcept {
		base_N_t<N> ret{};
		for(size_t ix{0} ; ix < n ; ++ix) {
			ret[ix] = dig_Bm1();
		}
		for(size_t ix{n} ; ix < N ; ++ix) {
			ret[ix] = dig_0();
		}
		return ret;
	}

	/// <summary>
	/// IDEM QUE ANTES PERO CON EL TIPO BASE_T ESPECIALIZANDO AL TIPO BASE_N_T<L>
	/// DONDE BASE_T == BASE_N_T<L>
	/// TENEMOS CUIDADO DE CREAR UN RVALUE TEMPORAL
	/// </summary>

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

	/// <summary>
	/// IDEM QUE ANTES PERO CON LA CLASE DERIVADA, LA ACTUAL
	/// TENEMOS CUIDADO DE CREAR UN RVALUE TEMPORAL
	/// </summary>

	static consteval
	reg_digs_t regd_0() noexcept {
		return reg_digs_t{regd_base_N_0<L>()};
	}

	static consteval
	reg_digs_t	regd_1() noexcept {
		return reg_digs_t{regd_base_N_1<L>()};
	}

	static consteval
	reg_digs_t	regd_Bm1() noexcept {
		return reg_digs_t{regd_base_N_Bm1<L>()};
	}

	static consteval
	reg_digs_t	regd_B() noexcept {
		return reg_digs_t{regd_base_N_B<L>()};
	}

	static consteval
	reg_digs_t	regd_pow_n_B()	noexcept {
		return reg_digs_t{regd_base_N_pow_n_B<L>()};
	}

	static consteval
	reg_digs_t	regd_pow_n_B_m1() noexcept	{
		return reg_digs_t{regd_base_N_pow_n_B_m1<L>()};
	}

public :
	/// <summary>
	/// En este bloque hacemos esta clase wrapper como si fuese una clase derivada de base_t
	/// Para esto replicamos y sobrecargamos cada una de las funciones por defecto de std::array
	/// </summary>
	constexpr decltype(auto)begin()					noexcept
	{ return const_ref_data().begin(); }
	constexpr decltype(auto)cbegin()	const	noexcept
	{ return const_ref_data().cbegin(); }
	constexpr decltype(auto)end()						noexcept
	{ return const_ref_data().end(); }
	constexpr decltype(auto)cend()		const	noexcept
	{ return const_ref_data().cend(); }
	constexpr decltype(auto)rbegin()				noexcept
	{ return const_ref_data().rbegin(); }
	constexpr decltype(auto)crbegin()	const	noexcept
	{ return const_ref_data().crbegin(); }
	constexpr decltype(auto)rend()					noexcept
	{ return const_ref_data().rend(); }
	constexpr decltype(auto)crend()		const	noexcept
	{ return const_ref_data().crend(); }

	constexpr size_type		size()			const	noexcept
	{ return const_ref_data().size(); }
	constexpr size_type		max_size()	const	noexcept
	{ return const_ref_data().max_size(); }
	constexpr bool				empty()			const	noexcept
	{ return const_ref_data().empty(); }

	constexpr dig_t					front()					noexcept
	{ return (ref_data().front()); }
	constexpr dig_t const&	front()		const	noexcept
	{ return (const_ref_data().front()); }
	constexpr dig_t					back()					noexcept
	{ return (ref_data().back()); }
	constexpr dig_t const&	back()		const	noexcept
	{ return (const_ref_data().back()); }

	constexpr void	fill(const dig_t& value)	noexcept
	{ ref_data().fill(value); }
	constexpr void	swap(base_t& other)				noexcept
	{ ref_data().swap(*other.data()); }

	/// <summary>
	///
	///
	///
	///    Constructores de reg_digs_t
	///
	///
	///
	/// </summary>

public:

	/// <summary>
	/// Constructor por defecto (rellena de dig_t(0) todo el array)
	/// </summary>
	consteval inline
	reg_digs_t()
	noexcept : (ref_data())(regd_base_0()) {}

public :
	/// <summary>
	/// Funcion miembro para generar un objeto tipo base_t y devolverlo desde un std::initializer_list<dig_t>
	/// </summary>
	/// <function name="make_base_t"></function>
	/// <param name="const std::initializer_list<dig_t>& larg"></param>
	/// <returns="rarg : base_t"></returns>
	static constexpr base_t make_base_t(const std::initializer_list<dig_t>& larg) {
		base_t rarg;
		for (size_t ix{ 0 }; ix < L; ++ix) {
			rarg[ix] = larg[ix];
		}
		return std::move(rarg);
	}

public:
	/// <summary>
	/// Constructor por lista de digitos utilizando la función make_base_t
	/// </summary>
	constexpr inline
	reg_digs_t(const std::initializer_list<dig_t> & arg)
	noexcept : m_dc(make_base_t(arg)) {}

	/// <summary>
	/// Constructor por argumentos tipo dig_t: deduce el tipo
	/// </summary>
	template<typename ... Ts>
		requires (std::is_same_v<Ts,dig_t>&&...)
	constexpr inline
	reg_digs_t(const Ts &... args)
	noexcept : m_dc{(utilities::pack2array<Ts...>{})(args...)} {}

	/// CONSTRUCTOR COPIA DESDE EL TIPO BASE
	constexpr inline
	reg_digs_t(const base_t & rarg) noexcept : m_dc{rarg} {}
	/// CONSTRUCTOR MOVIMIENTO DESDE EL TIPO BASE
	constexpr inline
	reg_digs_t(base_t && rarg) noexcept : m_dc{std::move(rarg)} {}

	/// <summary>
	/// Constructor por Copia/Movimiento desde una sucesión variádica de dígitos dig_t
	/// </summary>
private:

	/// <summary>
	/// Función miembro (delegada) para copiar un objeto tipo base_t desde una referencia constante a un array cualquiera de dig_t
	/// </summary>
	/// <function name="copy_arg_N"></function>
	/// <param name="const base_N_t<N> & arg"></param>
	/// <returns="void"></returns>
	template<size_t N>
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
			m_dc=*arg.data();
		}
	}

	/// <summary>
	/// Función miembro (delegada) para mover un objeto tipo base_t desde una referencia derecha a un array cualquiera de dig_t
	/// </summary>
	/// <function name="copy_arg_N"></function>
	/// <param name="const base_N_t<N> & arg"></param>
	/// <returns="void"></returns>
	template<size_t N>
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
			m_dc=std::move(*arg.data());
		}
	}

public:

	/// <summary>
	/// Constructor copia desde un array cualquiera de dígitos dig_t (usando copy_arg_N<N>)
	/// </summary>
	template<size_t N>
	constexpr inline
	reg_digs_t(const base_N_t<N> & arg)
	noexcept : (ref_data()){copy_arg_N<N>(arg)} {}

	/// <summary>
	/// Constructor por movimiento desde un array cualquiera de dígitos dig_t (usando move_arg_N<N>)
	/// </summary>
	template<size_t N>
	constexpr inline
	reg_digs_t(const base_N_t<N> && arg)
	noexcept : m_dc{move_arg_N<N>(std::move(arg))} {}

public :

	/// <summary="Función de normalización a dig_t (dígitos base B) que construye un objeto de tipo ">
	/// </summary>
	/// <summary="base_t desde una sucesión variádica de enteros cualquiera">
	/// </summary>
	/// <function name="normalize"></function>
	/// <param name="Ints_type ... digits_pow_i"></param>
	/// <returns="base_t"></returns>
	template<type_traits::integral_c ... Ints_type,size_t N>
		requires (((sizeof...(Ints_type)) <= L)&&(N>0))
	static constexpr inline
	base_N_t<N> normalize(Ints_type ... digits_pow_i)
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
					unsigned_integral_c<unique_type>,
					typename std::conditional_t<
						is_unsigned_sz_gt_v<UINT_T,unique_type>,
							sig_UInt_for_UInt_t<UINT_T>,
							sig_UInt_for_UInt_t<unique_type>
					 >,
					typename std::conditional_t<
						is_unsigned_sz_gt_v<UINT_T,sig_UInt_for_SInt_t<unique_type>>,
							sig_UInt_for_UInt_t<UINT_T>,
							sig_UInt_for_SInt_t<unique_type>
					>
			>;
		std::array<SUInt_type,pack_sz> ret_array{digits_pow_i...};
		base_N_t<pack_sz> ret;
		if constexpr (N <= pack_size) {
			for (size_t ix{ 0 }; ix < pack_sz; ++ix) {
				ret[ix] = dig_t(ret_array[ix]);
			}
		}
		else {
			for (size_t ix{ 0 }; ix < pack_sz; ++ix) {
				ret[ix] = dig_t(ret_array[ix]);
			}
			for (size_t ix{ pack_sz }; ix < L; ++ix) {
				ret[ix] = dig_t(0);
			}
		}
		return std::move(ret);
	}

public:

	/// <summary="Constructor copia desde una sucesión de objetos enteros variádica, normalizándolos">
	/// </summary>


	template<type_traits::integral_c ... Ints_type>
	constexpr inline base_t(Ints_type ... dig_pow_i) noexcept :
		(ref_data()){normalize<Ints_type...>(dig_pow_i...)} {}

	///	<summary>
	/// Sobrecarga del operador copia
	/// </summary>

	/// OPERACION ASIGNACION POR COPIA REFERENCIA CONST _NO_ COPIABLE DESDE BASE_N_T EN LA IZQUIERDA
	template<size_t N>
	constexpr inline
	const reg_digs_t & operator = (const reg_N_digs_t<N> & arg) noexcept
	{
		if (this->data()!=(arg.data()))
			copy_arg_N<N>(arg);
		return (*this);
	}

	/// OPERACION ASIGNACION POR COPIA REFERENCIA DESDE BASE_N_T EN LA IZQUIERDA
	template<size_t N>
	constexpr inline
	reg_dgis_t & operator = (reg_N_digs_t<N> & arg) noexcept
	{
		if (this!=(&arg))
			copy_arg_N<N>(arg);
		return (*this);
	}

	/// OPERACION ASIGNACION POR MOVIMIENTO DESDE BASE_N_T EN LA QUE NO SE PUEDE COPIAR
	template<size_t N>
	constexpr inline
	const base_t & operator = (reg_N_digs_t<N>&& arg) noexcept
	{
		if (this!=(&arg))
			move_arg_N<N>(std::move(arg));
		return (*this);
	}

	/// OPERACION COPIA DESDE UN DIGITO (CONVERSION)
	constexpr inline
	reg_digs_t & operator = (const dig_t & arg)
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
	const reg_digs_t& = (Int_Type arg) noexcept {
		using type_traits::maxbase();
		constexpr int128_t B_128t_v{static_cast<int128_t>(B)};
		constexpr bool puede_multiplicarse{
				(maxbase<int128_t>()/B_128t_v) > 0
		};
		if ((&(this->m_dc)) != (&arg)) {
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
				m_dc[k] = dig_t(creg_g%B_128t_v);
				creg_g /= B_128t_v;
			}
		}
		return (*this);
	}

				/****************************************/
				/*							      	    */
				/*       Algunas Conversiones    		*/
				/*							      		*/
				/****************************************/

	template<type_traits::integral_c Int_Type> /// SE PODRÍA HACER PARA UINT128_T
	constexpr inline operator Int_Type() const noexcept {
		using type_traits::maxbase();
		uint64_t retInt{0};
		uint64_t BasePowIx{1};
		for(size_t k{0} ; k < L ; ++k) {
			retInt += m_dc[k]*BasePowIx;
			BasePowIx *= B;
			if(	(k+1 < L)
						&&
					( maxbase<Int_Type>() < (retInt+((data()[k+1])*BasePowIx)) )	)
			{	return retInt; }
		}
		return retInt;
	}

private :
	/// <summary=" sobrecarga de las funciones miembro : ">
	/// constexpr dig_t* data() noexcept;
	/// </summary>
	/// <returns name="dig_t*"></returns>
	constexpr dig_t* data() noexcept {
		return (m_dc.data());
	}
public :
	/// <summary=" sobrecarga de las funciones miembro : ">
	/// constexpr const dig_t* data() const noexcept;
	/// </summary>
	/// <returns name="const dig_t*"></returns>
	constexpr const dig_t* data() const noexcept {
		return (static_cast<const dig_t*>(m_dc.data()));
	}
private:
	inline constexpr
	base_t& ref_data() const {
		return (this->m_dc);
	}
public:
	inline constexpr
	const base_t & const_ref_data() const {
		return (this->m_dc);
	}
	inline constexpr
	base_t cpy_data() const {
		return (this->m_dc);
	}


	///	<summary="Sobrecarga del const dig_t & operator[](size_t) const"></summary>
	const dig_t& operator[](size_t ix) const {
		return (m_dc[ix]);
	}
	/// <summary="Sobrecarga del dig_t & operator[](size_t)"></summary>
	dig_t& operator[](size_t ix) {
		return (m_dc[ix]);
	}


	/// <summary>
	/// Funciones que ponen a constantes (constexpr) los objetos base_t
	/// </summary>
	/// <typeparam name="size_t"></typeparam>
	/// <nontypeparam name="N"></nontypeparam>
	/// <param name="this"></param>
	/// <returns name="void"></returns>

	constexpr inline
	void set_0() noexcept
	{	m_dc.fill(dig_0());	}

	constexpr inline
	void set_1() noexcept
	{	m_dc.fill(dig_0());
		m_dc[0].set_1();	}

	constexpr inline
	void set_Bm1() noexcept
	{	m_dc.fill(dig_0());
		m_dc[0].set_Bm1();	}

	constexpr inline
	void set_dig(dig_t d) noexcept
	{	m_dc.fill(d);
		m_dc[0] = d;	}

	constexpr inline
	void set_fill_dig(dig_t d) noexcept
	{	m_dc.fill(d);	}

	constexpr inline
	void set_fill_1() noexcept
	{	m_dc.fill(dig_1());	}


	constexpr inline
	void set_fill_Bm1() noexcept
	{	m_dc.fill(dig_Bm1());	}


	/// <summary="Funciones que ponen a constantes(constexpr) los objetos un subintervalo o subrango de base_t cualquiera">
	/// </summary>
	/// <typeparam name="size_t"></typeparam>
	/// <nontypeparam name="N_i"></nontypeparam>
	/// <nontypeparam name="N_pf"></nontypeparam>
	/// <param name="this"></param>
	/// <returns name="void"></returns>

	/// OPERACION DE PONER A VALOR DIG_0 DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_N_T<N>
	template<size_t N_i,size_t N_pf> 	// i  es inicio
										// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	static constexpr inline
	void set_interval_0() noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			m_dc[ix].set_0();
	}

	/// OPERACION DE PONER A VALOR DIG_Bm1 DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_N_T<N>
	template<size_t N,size_t N_i,size_t N_pf> 	// i  es inicio
												// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	static constexpr inline
	void set_interval_Bm1() noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			m_dc[ix].set_Bm1();
	}

	/// OPERACION DE PONER A VALOR DIG DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_T
	template<size_t N_i,size_t N_pf>	// i  es inicio
										// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	static constexpr inline
	void set_interval_dig(dig_t dig) noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			m_dc[ix] = dig;
	}

	/// OPERACION DE PONER A VALOR DIG_0 DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_T
	template<size_t N_i,size_t N_pf> 	// i  es inicio
										// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	constexpr inline
	void set_interval_0() noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			m_dc[ix] = dig_0();
	}


	///<summary="Funciones comparativas básicas con constantes tipo constexpr"></summary>
	///<param name="this"></param>
	///<returns="bool"></returns>



	inline constexpr
	bool is_0() const noexcept
	{
		for(elem : m_dc) {
			if(elem.is_not_0())
				return false;
		}
		return true;
	}

	inline constexpr
	bool is_1() const noexcept
	{
		if (m_dc[0].is_not_1())
			return false;
		for(size_t ix{1} ; ix<L ; ++ix) {
			if(m_dc[ix].is_not_0())
				return false;
		}
		return true;
	}

	inline constexpr
	bool is_Bm1() const noexcept
	{
		if (m_dc[0].is_not_Bm1())
			return false;
		for(size_t ix{1} ; ix<L ; ++ix) {
			if(m_dc[ix].is_not_0())
				return false;
		}
		return true;
	}

	inline constexpr
	bool is_B() const noexcept
	{
		if constexpr (L == 1) return false;
		else {
			if (m_dc[0].is_not_0())
				return false;
			if (m_dc[1].is_not_1())
				return false;
			for (size_t ix{ 2 }; ix < L; ++ix) {
				if (m_dc[ix].is_not_0())
					return false;
			}
			return true;
		}
	}

	inline constexpr
	bool is_Bp1() const noexcept
	{
		if constexpr (L == 1) return false;
		else {
			if (m_dc[0].is_not_1())
				return false;
			if (m_dc[1].is_not_1())
				return false;
			for (size_t ix{ 2 }; ix < L; ++ix) {
				if (m_dc[ix].is_not_0())
					return false;
			}
			return true;
		}
	}

	template<size_t n>
		requires (n<L)
	inline constexpr
	bool is_B_pow_m1() const noexcept
	{
		if constexpr (n == 0) {
			return m_dc.is_0();
		}
		else if constexpr (n == 1) {
			return m_dc.is_Bm1();
		}
		else if constexpr (n == 2) {
			if (m_dc[1].is_not_Bm1() || m_dc[0].is_not_Bm1())
				return false;
			for(size_t ix{2} ; ix < L ; ++ix)
				if (m_dc[ix].is_not_0())
					return false;
			return true;
		}
		else {
			for(size_t ix{0} ; ix < n ; ++ix)
				if (m_dc[ix].is_not_Bm1())
					return false;
			for(size_t ix{n} ; ix < L ; ++ix)
				if (m_dc[ix].is_not_0())
					return false;
			return true;
		}
	}

	template<size_t n>
		requires (n<L-1)
	inline constexpr
	bool is_B_pow() const noexcept
	{
		if constexpr (n == 0) {
			if (m_dc[0].is_not_1())
				return false;
			for (size_t ix{1} ; ix < L ; ++ix)
				if (m_dc[ix].is_not_0())
					return false;
			return true;
		}
		else if constexpr (n == 1) {
			if (m_dc[0].is_not_0())
				return false;
			if (m_dc[1].is_not_1())
				return false;
			for (size_t ix{2} ; ix < L ; ++ix)
				if (m_dc[ix].is_not_0())
					return false;
			return true;
		}
		else if constexpr (n == 2) {
			if (m_dc[0].is_not_0() || m_dc[1].is_not_0())
				return false;
			if (m_dc[2].is_not_1())
				return false;
			for (size_t ix{3} ; ix < L ; ++ix)
				if (m_dc[ix].is_not_0())
					return false;
			return true;
		}
		else {
			for (size_t ix{0} ; ix < n ; ++ix)
				if (m_dc[ix].is_not_0())
					return false;
			if (m_dc[n].is_not_1())
				return false;
			for (size_t ix{n+1} ; ix < L ; ++ix)
				if (m_dc[ix].is_not_0())
					return false;
			return true;
		}
	}

	inline constexpr
	bool is_any_B_pow() const noexcept
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

	inline constexpr
	bool is_filled_of_1() const noexcept {
		for (size_t ix{0} ; ix < L ; ++ix)
			if (m_dc[ix].is_not_1())
				return false;
		return true;
	}

	inline constexpr
	bool is_filled_of_Bm1() const noexcept {
		for (size_t ix{0} ; ix < L ; ++ix)
			if (m_dc[ix].is_not_Bm1())
				return false;
		return true;
	}

	inline constexpr
	bool is_filled_of(dig_t d) const {
		for (size_t ix{0} ; ix < L ; ++ix)
			if (arg[ix] != d)
				return false;
		return true;
	}

	inline constexpr
	int32_t index_of_MSDig() const noexcept {
		for(int32_t ix{L-1} ; ix > -1 ; --ix) {
			if (m_dc[ix].is_not_0())
				return ix;
		}
		return (-1);
	}

	///
	///
	/// SOBRECARGA DE LOS OPERADORES DE COMPARACION Y ORDEN
	///
	///

	/// COMPARACIONES ENTRE BASE_T Y DIG_T EN FORMA BASE_T @ DIG_T
	static constexpr inline
	bool operator == (const dig_t& rarg) const noexcept {
		if (m_dc[0] != rarg)
			return false;
		for(size_t ix{1} ; ix < L ; ++ix)
			if (m_dc[ix].is_not_0())
				return false;
		return true;
	}

	constexpr inline
	bool operator != (const dig_t& rarg) const noexcept {
		for(size_t ix{1} ; ix < L ; ++ix)
			if (m_dc[ix].is_not_0())
				return true;
		if (m_dc[0] != rarg)
			return true;
		return false;

	}

	constexpr inline
	bool operator > (const dig_t& rarg) const noexcept {
		for(size_t ix{1} ; ix < L ; ++ix)
			if (m_dc[ix].is_not_0())
				return true;
		if (m_dc[0] > rarg)
			return true;
		return false;
	}

	constexpr inline
	bool operator < (const dig_t& rarg) const noexcept {
		for(size_t ix{1} ; ix < L ; ++ix)
			if (m_dc[ix].is_not_0())
				return false;
		if (m_dc[0] >= rarg)
			return false;
		return true;
	}

	constexpr inline
	bool operator >= (const dig_t& rarg) const noexcept {
		for(size_t ix{1} ; ix < L ; ++ix)
			if (m_dc[ix].is_not_0())
				return true;
		if (m_dc[0] >= rarg)
			return true;
		return false;
	}

	constexpr inline
	bool operator <= (const dig_t& rarg) const noexcept {
		for(size_t ix{1} ; ix < N ; ++ix)
			if (m_dc[ix].is_not_0())
				return false;
		if (m_dc[0] > rarg)
			return false;
		else
			return true;
	}

	/// COMPARACIONES ENTRE BASE_T Y BASE_N_T HETEROGENEOS EN GENERAL
	///	EN FORMA BASE_T<L> @ BASE_N_T<M>
	template<size_t M>
	constexpr inline
	bool operator == (const base_N_t<M>& rarg) const noexcept {
		constexpr size_t P{std::min(L,M)};
		constexpr size_t Q{std::max(L,M)};
		constexpr bool L_gt_M{L>M};

		if constexpr (L!=M) {
			for (size_t ix{P} ix < Q ; ++ix) {
				if constexpr (L_gt_M) {
					if (m_dc[ix].is_not_0())
						return false;
				}
				else {
					if (rarg[ix].is_not_0())
						return false;
				}
			}
		}
		for(size_t ix{0} ; ix < P ; ++ix)
			if (m_dc[ix] != rarg[ix])
				return false;
		return true;
	}

	template<size_t M>
	constexpr inline
	bool operator != (const base_N_t<M>& rarg) const noexcept {
		return (!(*m_dc.data() == rarg.const_ref_data()));	}

	template<size_t M>
	constexpr inline
	bool operator > (const base_N_t<M>& rarg) const noexcept {
		constexpr size_t P{std::min(L,M)};
		constexpr size_t Q{std::max(L,M)};
		constexpr bool L_gt_M{L>M};

		if constexpr (L != M) {
			for(size_t ix{P} ; ix < Q ; ++ix) {
				if constexpr (L>M) {
					if (m_dc[ix].is_not_0())
						return true;
				}
				else {
					if (rarg[ix].is_not_0())
						return false;
				}
			}
		}

		for(int32_t ix{L} ; ix > -1 ; --ix)
			if (m_dc[ix] > rarg[ix])
				return true;
		return false;
	}

	template<size_t M>
	constexpr inline
	bool operator < (const base_N_t<M>& rarg) const noexcept {
		constexpr size_t P{std::min(L,M)};
		constexpr size_t Q{std::max(L,M)};
		constexpr bool L_gt_M{L>M};

		if constexpr (L != M) {
			for(size_t ix{P} ; ix < Q ; ++ix) {
				if constexpr (L_gt_M) {
					if (m_dc[ix].is_not_0())
						return false;
				}
				else {
					if (rarg[ix].is_not_0())
						return true;
				}
			}
		}

		for(int32_t ix{L} ; ix > -1 ; --ix)
			if (m_dc[ix] < rarg[ix])
				return true;
		return false;
	}

	template<size_t M>
	constexpr inline
	bool operator >= (const base_N_t<M>& rarg) const noexcept {
		return (!(const_ref_data() < rarg.const_ref_data()));	}

	template<size_t M>
	constexpr inline
	bool operator <= (const base_N_t<M>& rarg) const noexcept {
		return (!(const_ref_data() > rarg.const_ref_data()));	}

	constexpr bool operator == (const base_t& arg) const noexcept {
		return (const_ref_data() == arg.const_ref_data());	}

	constexpr bool operator != (const base_t& arg) const noexcept {
		return (const_ref_data() != arg.const_ref_data());	}

	constexpr bool operator < (const base_t& arg) const noexcept {
		return (const_ref_data() < arg.const_ref_data());	}

	constexpr bool operator > (const base_t& arg) const noexcept {
		return (const_ref_data() > arg.const_ref_data());	}

	constexpr bool operator <= (const base_t& arg) const noexcept {
		return (const_ref_data() < arg.const_ref_data());	}

	constexpr bool operator >= (const base_t& arg) const noexcept {
		return (const_ref_data() > arg.const_ref_data());	}

	/// OPERADOR COMPARACION SPACESHIP C++20

	template<size_t M>
	constexpr inline
	std::strong_ordering operator <=> (const base_N_t<M>& arg) const noexcept
	{
		if (const_ref_data() == arg.const_ref_data())
			return std::strong_ordering::equal;
		else if (const_ref_data() < arg.const_ref_data())
			return std::strong_ordering::less;
		else
			return std::strong_ordering::greater;
	}

	/// OPERADOR COMPARACION SPACESHIP C++20
	constexpr inline
	std::weak_ordering operator <=> (const dig_t & arg) const noexcept
	{
		if (const_ref_data() > arg)
			return std::weak_ordering::greater;
		else if (const_ref_data() < arg)
			return std::weak_ordering::less;
		else
			return std::weak_ordering::equivalent;
	}

	/// STATIC BASE_N_T<N>		CONCAT(BASE_N_T<N>)
	/// STATIC BASE_N_T<N+M>	CONCAT(BASE_N_T<N>,BASE_N_T<M>)
	/// STATIC BASE_N_T<N+1>	CONCAT(BASE_N_T<N>,DIG_T)
	/// STATIC BASE_N_T<1+M>	CONCAT(DIG_T,BASE_N_T<M>)
	/// STATIC BASE_N_T<1>		CONCAT(DIG_T)
	/// STATIC BASE_N_T<1+1>	CONCAT(DIG_T,DIG_T)
	/// STATIC BASE_N_T<SIZEOF...(DIG_PACK)> CONCAT(DIG_T ... DIG_PACK) VARIADIC PACK

	/// STATIC BASE_T CONCAT()
	static constexpr inline
	base_t concat(const base_t & arg) noexcept
	{	base_t ret{arg}; return std::move(ret);	}

	/// BASE_N_T<L+M> CONCAT(BASE_N_T<M>)
	template<size_t M>
	static constexpr inline
	base_N_t<L+M> concat(const base_t& larg,const base_N_t<M>& rarg) noexcept {
		base_N_t<L+M> ret;
		for(size_t ix{0} ; ix < L ; ++ix)
			ret[ix] = larg[ix];
		for(size_t ix{L} ; ix < M ; ++ix)
			ret[ix] = rarg[ix];
		return std::move(ret);
	}

	/// BASE_T<L+1> CONCAT(DIG_T)
	static constexpr inline
	base_N_t<L+1> concat(const base_t & larg,dig_t rarg) noexcept
	{
		base_N_t<L+1> ret;
		for(size_t ix{0} ; ix < L ; ++ix)
			ret[ix] = larg[ix];
		ret[L] = rarg;
		return std::move(ret);
	}

	/// BASE_N_T<1+L> CONCAT(DIG_T)
	static constexpr inline
	base_N_t<1+L> concat(dig_t larg,const base_t & rarg) noexcept
	{
		base_N_t<1+L> ret;
		ret[0] = larg;
		for(size_t ix{1} ; ix < L+1 ; ++ix)
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

	/// reg_digs_t				CAT(reg_digs_t)
	/// reg_N_digs_t<L+M>	CAT(reg_N_digs_t<M>)
	/// reg_N_digs_t<N+1>	CAT(dig_t)
	/// reg_N_digs_t<SIZEOF...(DIG_PACK)> CAT(DIG_T ... DIG_PACK) VARIADIC PACK

	/// STATIC BASE_T CONCAT()
	static constexpr inline
	base_t concat(const base_t & arg) noexcept
	{	base_t ret{arg}; return std::move(ret);	}

	/// BASE_N_T<L+M> CONCAT(BASE_N_T<M>)
	template<size_t M>
	static constexpr inline
	base_N_t<L+M> concat(const base_t& larg,const base_N_t<M>& rarg) noexcept {
		base_N_t<L+M> ret;
		for(size_t ix{0} ; ix < L ; ++ix)
			ret[ix] = larg[ix];
		for(size_t ix{L} ; ix < M ; ++ix)
			ret[ix] = rarg[ix];
		return std::move(ret);
	}

	/// BASE_T<L+1> CONCAT(DIG_T)
	static constexpr inline
	base_N_t<L+1> concat(const base_t & larg,dig_t rarg) noexcept
	{
		base_N_t<L+1> ret;
		for(size_t ix{0} ; ix < L ; ++ix)
			ret[ix] = larg[ix];
		ret[L] = rarg;
		return std::move(ret);
	}

	/// BASE_N_T<1+L> CONCAT(DIG_T)
	static constexpr inline
	base_N_t<1+L> concat(dig_t larg,const base_t & rarg) noexcept
	{
		base_N_t<1+L> ret;
		ret[0] = larg;
		for(size_t ix{1} ; ix < L+1 ; ++ix)
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
	template<size_t ibegin,size_t iend>
		requires ((iend <= L)&&(ibegin < L)&&(ibegin != iend))
	static constexpr inline
	base_N_t<std::abs<size_t>(iend-ibegin)> subregister() const noexcept
	{
		if constexpr (ibegin < iend) {
			base_N_t<iend-ibegin> ret;
			for(size_t ix{ibegin} ; ix < iend ; ++ix) {
				ret[ix-ibegin] = m_dc[ix];
			}
			return std::move(ret);
		}
		else {
			nat_reg_N_digs_t<iend-ibegin> ret;
			for(int32_t ix{iend} ; ix > ibegin-1 ; --ix) {
				ret[ix-ibegin] = m_dc[L-1-ix];
			}
			return std::move(ret);
		}
	}
								/****************************/
								/*													*/
								/* OPERADORES ARITMETICOS		*/
								/*	 C_B()  C_Bm1()  				*/
								/*	mC_B() mC_Bm1()		    	*/
								/*	operator!() operator-() */
								/*                          */
								/****************************/

	constexpr inline
	const base_t & mC_Bm1() noexcept
	{
		for(size_t ix{0} ; ix < L ; ++ix) {
				m_dc[ix].mC_Bm1();
		}
		return (*this);
	}

	constexpr inline
	const base_t & mC_B(base_t & arg) noexcept
	{
		mC_Bm1(m_dc);
		for(size_t ix{0} ; ix < L ; ++ix) {
			if (arg[ix].is_not_Bm1()) {
				++arg[ix];
				return (*this);
			}
			else {
				arg[ix].set_0();
			}
		}
		return (*this);
	}

	constexpr inline
	base_t C_Bm1() const noexcept
	{	return std::move(base_t{m_dc}.mC_Bm1()); }

	constexpr inline
	base_t C_B() const noexcept
	{
		return std::move(base_t{m_dc}.mC_B());
	}

	constexpr inline
	base_t operator !() const noexcept
	{ return C_Bm1(); }

	constexpr inline
	base_t operator -() const noexcept
	{ return C_B();	}


	/// BEGIN : OPERATORS >> >>= << <<= REM_B^n M_REM_B^n MER_B_N M_MER_B_N

	/// MULTIPLY BY THE BASE B (10) << <<=
	/// DIVIDE BY THE BASE B (10)	  >> >>=
	/// REMAINDER BY THE BASE B (10) REM_B_N M_REM_B_N
	/// MULTIPLICATIVE CARRY BY THE BASE B (10) MER_B_N M_MER_B_N

private :

	constexpr inline
	base_t operator << (size_t n) const noexcept
	{
		base_t cparg{m_dc};
		for(std::int32_t ix{L-1-n} ; ix > -1 ; --ix) {
			cparg[ix+n]	= m_dc[ix];
		}
		for(std::int32_t ix{0} ; ix < n ; ++ix) {
			cparg[ix]		= dig_0();
		}
		return std::move(cparg);
	}

	static constexpr inline
	const base_t & operator <<= (size_t n) noexcept
	{
		for(std::int32_t ix{L-1-n} ; ix > -1 ; --ix) {
			m_dc[ix+n]	= m_dc[ix];
		}
		for(std::int32_t ix{0} ; ix < n ; ++ix) {
			m_dc[ix]	= dig_0();
		}
		return (*this);
	}

	constexpr inline
	const base_t & operator >>= (size_t n) noexcept
	{
		for(std::int32_t ix{0} ; ix < L-n ; ++ix) {
			m_dc[ix] 		= m_dc[ix+n];
		}
		for(std::int32_t ix{L-n} ; ix < L ; ++ix) {
			m_dc[ix]		=	dig_0();
		}
		return (*this);
	}

	constexpr inline
	base_t operator >> (size_t n) const noexcept
	{
		return std::move(base_t{m_dc}.ref_data() >>= n);
	}

	constexpr inline
	base_t rem_B(size_t n) const noexcept
	{
		base_t ret{m_dc};
		ret <<= L-n;
		return std::move(ret);
	}

	constexpr inline
	const base_t & m_rem_B(size_t n) noexcept
	{
		m_dc <<= L-n;
		return (larg);
	}


	constexpr inline
	base_t mer_B(size_t n) const noexcept
	{
		base_t ret{m_dc};
		ret >>= L-n;
		return std::move(ret);
	}

	constexpr inline
	const base_t & m_mer_B(size_t n) noexcept
	{
		m_dc >>= L-n;
		return (*this);
	}

	constexpr inline
	const base_t & operator |= (const base_t & rarg) const noexcept
	{
		for(size_t ix{0} ; ix < L ; ++ix) {
			m_dc[ix] |= rarg[ix];
		}
		return (*this);
	}

	constexpr inline
	base_t operator | (const base_t & rarg) const noexcept
	{
		base_t ret{m_dc};
		ret |= rarg;
		return std::move(ret);
	}

	constexpr inline
	const base_t & operator &= (const base_t & rarg) noexcept
	{
		for(size_t ix{0} ; ix < L ; ++ix) {
			m_dc[ix] &= rarg[ix];
		}
		return (*this);
	}

	constexpr inline
	base_t operator & (const base_t & rarg) noexcept
	{
		base_t ret{m_dc};
		ret &= rarg;
		return std::move(ret);
	}

  };
}

#endif // REG_DIGS_T_HPP_INCLUDED
