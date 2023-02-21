#ifndef NAT_REG_DIGS_T__HPP__INCLUDED
#define NAT_REG_DIGS_T__HPP__INCLUDED

#include "reg_digs_t.hpp"
#include "utilities.hpp"

namespace NumRepr {

using type_traits::uint_type_for_radix_c;
using type_traits::suitable_base;

template<uint_type_for_radix_c UINT_T,UINT_T B,size_t L>
	requires (suitable_base<UINT_T,B>() && (L>0))
struct nat_reg_digs_t : public reg_digs_t<UINT_T,B,L> {

	using SIG_UINT_T = typename type_traits::sig_UInt_for_UInt_t<UINT_T>;
	using SIG_SINT_T = typename type_traits::sig_SInt_for_UInt_t<UINT_T>;

	using dig_t 	 = dig_t<UINT_T,B>;

	template<size_t N>
		requires ( N > 0 )
	using base_N_t   = reg_digs_t<UINT_T,B,N>;
	using base_t	 = base_N_t<L>;

	template<binop_e op,size_t N>
	using res_base_N_op_t	=
				typename auxiliary_types::result_operation_t<base_N_t<N>,op,N>;
	template<binop_e op>
	using res_base_op_t		=
				typename auxiliary_types::result_operation_t<base_t,op,L>;

	template<size_t N>
		requires ( N > 0 )
	using nat_reg_N_digs_t = nat_reg_digs_t<UINT_T,B,N>;

	template<binop_e op,size_t N>
	using res_N_op_t 			=
		typename auxiliary_types::result_operation_t<nat_reg_N_digs_t<N>,op,N>;
	template<binop_e op>
	using res_op_t 				=
		typename auxiliary_types::result_operation_t<nat_reg_digs_t,op,L>;

public :

	/// FUNCIÓNES INMEDIATAS QUE NOS DAN CONSTANTES DEL TIPO DE LA ACTUAL CLASE
	/// SE HACE CREANDO UNA VARIABLE RVALUE TEMPORAL CON LA FUNCIÓN HOMOLOGA PARA
	/// BASE_T
	static consteval
	nat_reg_digs_t 	regd_0()    noexcept {
		return nat_reg_digs_t{base_t::regd_0()};
	}

	static consteval
	nat_reg_digs_t	regd_1()    noexcept {
		return nat_reg_digs_t{base_t::regd_1()};
	}

	static consteval
	nat_reg_digs_t	regd_Bm1()  noexcept {
		return nat_reg_digs_t{base_t::regd_Bm1()};
	}

	static consteval
	nat_reg_digs_t	regd_B() 	noexcept {
		return nat_reg_digs_t{base_t::regd_B()};
	}

	template<size_t n>
		requires ((n>=0)&&(n < L))
	static consteval
	nat_reg_digs_t	regd_pow_n_B()	noexcept {
		return nat_reg_digs_t{base_t::regd_pow_n_B()};
	}

	template<size_t n>
		requires ((n>=0)&&(n < L))
	static consteval
	nat_reg_digs_t	regd_pow_n_B_m1() noexcept	{
		return nat_reg_digs_t{base_t::regd_pow_n_B_m1()};
	}


				/************************************/
				/*	    							*/
				/*    CONSTRUIR NUMERO				*/
				/*					    			*/
				/************************************/

public:

	/// CONSTRUCTOR POR DEFECTO
	consteval inline
	nat_reg_digs_t()
	noexcept : base_t{dig_t::dig_0()} {}
	/// CONSTRUCTOR POR LISTA DE DIGITOS
	constexpr inline
	nat_reg_digs_t(const std::initializer_list<dig_t> & arg)
	noexcept : base_t{arg} {}
	/// CONSTRUCTOR POR ARGUMENTOS DIGITOS SIN LIMITE: DEDUCE EL TIPO
	template<typename ... Ts>
		requires (std::is_same_v<Ts,dig_t>&&...)
	constexpr inline
	nat_reg_digs_t(const Ts &... args)
	noexcept : base_t(args...) {}

public:
	inline constexpr const base_t* const const_base_this() const noexcept
	{ return static_cast<const base_t* const>(this); }
	inline constexpr base_t base_cpy_cthis() const noexcept
	{ return base_t(*const_base_this()); }
	inline constexpr const base_t& base_const_ref_cthis() const noexcept
	{ return (*const_base_this()); }
	inline constexpr const dig_t& const_by_index(size_t ix) const noexcept
	{ return (base_const_ref_cthis()[ix]); }
	inline constexpr dig_t cpy_by_index(size_t ix) const noexcept
	{ return dig_t(base_const_ref_cthis()[ix]); }
private:
	inline constexpr base_t* const base_this() noexcept
	{ return static_cast<base_t* const>(this); }
	inline constexpr base_t& base_ref_cthis() noexcept
	{ return (*base_this); }
	inline constexpr const dig_t& by_index(size_t ix) noexcept
	{ return (base_ref_cthis()[ix]); }
public:


	/// BEGIN : CONSTRUCTOR COPIA/MOVIMIENTO DESDE UN ARRAY DE DIGITOS
	/// FUNCIÓN DELEGADA PARA COPIA DE UN ARRAY DEL MISMO TAMAÑO
	/// O UN TAMAÑO CUALQUIERA "N"
	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	void copy_arg_N(const base_N_t<N> & arg) noexcept {
		///< Z < W or Z == W

		constexpr auto Z{std::min(N,L)};
		constexpr auto W{std::max(N,L)};
		if constexpr (Z==L) {
			for(size_t ix{0} ; ix < Z ; ++ix)
				by_index(ix)=arg[ix];
		}
		else if constexpr (W==L) {
			for(size_t ix{0} ; ix < Z ; ++ix)
				by_index(ix)=arg[ix];
			for(size_t ix{Z} ; ix < W ; ++ix)
				by_index(ix)=dig_t::dig_0();
		}
		else {
			base_ref_cthis() = arg;
		}
	}

	/// FUNCIÓN DELEGADA PARA MOVER DE UN ARRAY DEL MISMO TAMAÑO
	/// O UN TAMAÑO CUALQUIERA "N"
	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	void move_arg_N(base_N_t<N>&& arg) noexcept {
		///< Z < W or Z == W
		constexpr auto Z{std::min(N,L)};
		constexpr auto W{std::max(N,L)};
		if constexpr (Z==L) {
			for(size_t ix{0} ; ix < Z ; ++ix)
				by_index(ix)=std::move(arg[ix]);
		}
		else if constexpr (W==L) {
			for(size_t ix{0} ; ix < Z ; ++ix)
				by_index(ix)=std::move(arg[ix]);
			for(size_t ix{Z} ; ix < W ; ++ix)
				by_index(ix)=std::move(dig_t::dig_0());
		}
		else {
      base_ref_cthis()=std::move(arg);
		}
	}

	/// FUNCIÓN DELEGADA PARA COPIA DE UN NAT_REG_N_DIGS_T DEL MISMO TAMAÑO
	/// O UN TAMAÑO CUALQUIERA "N"
	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	void copy_arg_N(const nat_reg_N_digs_t<N> & arg) noexcept {
		base_ref_cthis() = arg.base_const_ref_cthis();
	}

	/// FUNCIÓN DELEGADA PARA MOVER DE UN NAT_REG_N_DIGS_T DEL MISMO TAMAÑO
	/// O UN TAMAÑO CUALQUIERA "N"
	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	void move_arg_N(nat_reg_N_digs_t<N>&& arg) noexcept {
		base_ref_cthis() = std::move(arg.base_const_ref_cthis());
	}

public:

	/// CONSTRUCTOR COPIA DESDE UN ARRAY DE DIGITOS
	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	nat_reg_digs_t(const base_N_t<N> & arg)
	noexcept : base_t{copy_arg_N<N>(arg)} {}

	/// CONSTRUCTOR MOVIMIENTO DESDE UN ARRAY DE DIGITOS
	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	nat_reg_digs_t(const base_N_t<N> && arg)
	noexcept : base_t{move_arg_N<N>(std::move(arg))} {}
	/// END   : CONSTRUCTOR COPIA/MOVIMIENTO DESDE UN ARRAY DE DIGITOS

public:

	/// CONSTRUCTOR COPIA DESDE ARGUMENTOS ENTEROS SIN LIMITE : DEDUCE EL TIPO
	template<type_traits::integral_c ... Ints_type>
	constexpr inline nat_reg_digs_t(Ints_type ... dig_pow_i) noexcept :
		base_t{normalize<Ints_type...>(dig_pow_i...)} {}

	/// CONSTRUCTOR COPIA POR REFERENCIA CONSTANTE
	template<size_t N>
		requires ( N > 0 )
	constexpr inline nat_reg_digs_t(const nat_reg_N_digs_t<N> & arg) noexcept :
		base_t{copy_arg_N<N>(arg.base_const_ref_cthis())} {}

	/// CONSTRUCTOR POR MOVIMIENTO
	template<size_t N>
		requires ( N > 0 )
	constexpr inline nat_reg_digs_t(nat_reg_N_digs_t<N> && arg) noexcept :
		base_t{move_arg_N(std::move(*(arg.base_this())))} {}

	/// OPERACIÓN ASIGNACIÓN POR COPIA REFERENCIA CONST _NO_ COPIABLE DESDE BASE_N_T
	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	const nat_reg_digs_t & operator = (const base_N_t<N> & arg) noexcept
	{
		if (base_this() != &arg)
			copy_arg_N<N>(arg);
		return (*this);
	}

	/// OPERACIÓN ASIGNACIÓN POR COPIA REFERENCIA DESDE BASE_N_T
	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	nat_reg_digs_t & operator = (base_N_t<N> & arg) noexcept
	{
		if (const_base_this() != &arg)
			copy_arg_N<N>(arg);
		return (*this);
	}

	/// OPERACIÓN ASIGNACIÓN POR COPIA MOVIMIENTO DESDE BASE_N_T
	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	const nat_reg_digs_t & operator = (base_N_t<N>&& arg) noexcept
	{
		if (const_base_this() != &arg)
			move_arg_N<N>(std::move(arg));
		return (*this);
	}

	/// OPERACIÓN ASIGNACIÓN POR COPIA REFERENCIA EN LA QUE SE PUEDE COPIAR
	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	nat_reg_digs_t & operator = (const nat_reg_N_digs_t<N> & arg) noexcept
	{
		if (this != &arg)
			(*base_this()) = arg.base_const_ref_cthis();
		return (*this);
	}

	/// OPERACIÓN ASIGNACIÓN POR MOVIMIENTO
	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	nat_reg_digs_t & operator = (nat_reg_N_digs_t<N> && arg) noexcept
	{
		if (this != &arg)
			(*base_this()) = std::move(*(arg.base_this()));
		return (*this);
	}

	/// OPERACIÓN ASIGNACIÓN POR COPIA EN LA QUE  _NO_  SE PUEDE COPIAR
	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	const nat_reg_digs_t & operator = (const nat_reg_N_digs_t<N> & arg) noexcept
	{
		if (this != &arg)
			(*base_this()) = arg.base_const_ref_cthis();
		return (*this);
	}
private:
	template<size_t N>
		requires ( N > 0 )
	static constexpr inline
	void set_0(base_N_t<N>& arg) noexcept
	{
		for (dig_t& dig : arg)
			dig = dig_t::dig_0();
	}

	template<size_t N>
		requires ( N > 0 )
	static constexpr inline
	void set_1(base_N_t<N>& arg) noexcept
	{
		arg[0].set_1();
		for (size_t ix{1} ; ix < N ; ++ix )
			arg[ix] = dig_t::dig_0();
	}

	template<size_t N>
		requires ( N > 0 )
	static constexpr inline
	void set_Bm1(base_N_t<N>& arg) noexcept
	{
		arg[0].set_Bm1();
		for (size_t ix{1} ; ix < N ; ++ix )
			arg[ix] = dig_t::dig_0();
	}

	template<size_t N>
		requires ( N > 0 )
	static constexpr inline
	void set_dig(base_N_t<N>& larg,dig_t d) noexcept
	{
		larg[0] = d;
		for (size_t ix{1} ; ix < N ; ++ix )
			larg[ix] = dig_t::dig_0();
	}

	template<size_t N>
		requires ( N > 0 )
	static constexpr inline
	void set_fill_dig(base_N_t<N>& larg,dig_t d) noexcept
	{
		for (auto & elem : larg)
			elem = d;
	}

	template<size_t N>
		requires ( N > 0 )
	static constexpr inline
	void set_fill_1(base_N_t<N>& larg) noexcept
	{
		for (auto & elem : larg)
			elem.set_1();
	}

	template<size_t N>
		requires ( N > 0 )
	static constexpr inline
	void set_fill_Bm1(base_N_t<N>& larg) noexcept
	{
		for (auto & elem : larg)
			elem.set_Bm1();
	}

	/// OPERACIÓN DE PONER A VALOR DIG_0 DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_N_T<N>
	template<size_t N,size_t N_i,size_t N_pf> 	// i es inicio
												// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= N)&&( N > 0 ))
	static constexpr inline
	void set_interval_0(base_N_t<N>& larg) noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			larg[ix] = dig_t::dig_0();
	}

	/// OPERACIÓN DE PONER A VALOR DIG_Bm1 DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_N_T<N>
	template<size_t N,size_t N_i,size_t N_pf> 	// i es inicio
												// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= N)&&( N > 0 ))
	static constexpr inline
	void set_interval_Bm1(base_N_t<N>& larg) noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			larg[ix] = dig_t::dig_Bm1();
	}

	/// OPERACIÓN DE PONER A VALOR DIG DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_N_T<N>
	template<size_t N,size_t N_i,size_t N_pf>   // i es inicio
												// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= N)&&( N > 0 ))
	static constexpr inline
	void set_interval_dig(base_N_t<N>& larg,dig_t dig) noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			larg[ix] = dig;
	}

	/// OPERACIÓN DE PONER A VALOR DIG_0 DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_T
	/// ESPECIALIZACIÓN PARA N==L
	template<size_t N_i,size_t N_pf> 	// i es inicio
										// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	static constexpr inline
	void set_interval_0(base_t& larg) noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			larg[ix] = dig_t::dig_0();
	}

	/// OPERACIÓN DE PONER A VALOR DIG_Bm1 DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_T
	/// ESPECIALIZACIÓN PARA N==L
	template<size_t N_i,size_t N_pf> 	// i es inicio
										// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	static constexpr inline
	void set_interval_Bm1(base_t& larg) noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			larg[ix] = dig_t::dig_Bm1();
	}

	/// OPERACIÓN DE PONER A VALOR DIG DEL ARRAY
	///	DESDE [N_0 , N_1) EN BASE_T
	/// ESPECIALIZACIÓN PARA N==L
	template<size_t N_i,size_t N_pf> 	// i es inicio
										// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	static constexpr inline
	void set_interval_dig(base_t& larg,dig_t dig) noexcept {
		for (size_t ix{N_i} ; ix < N_pf ; ++ix)
			larg[ix] = dig;
	}

public:
	/// OPERACIÓN DE LIMPIEZA A CERO DEL NAT_REG_DIGS_T
	constexpr inline
	void set_0() noexcept {
		set_0(base_ref_cthis());
	}

	/// OPERACIÓN DE LIMPIEZA A B-1 DEL NAT_REG_DIGS_T
	constexpr inline
	void set_Bm1() noexcept {
		set_Bm1(base_ref_cthis());
	}

	/// OPERACIÓN DE LIMPIEZA A VALOR DIG_T DEL NAT_REG_DIGS_T
	constexpr inline
	void set_dig(dig_t arg) noexcept {
		set_dig(base_ref_cthis(),arg);
	}

	/// OPERACIÓN DE PONER A VALOR DIG_0 EN [N_0 , N_1) DEL NAT_REG_DIGS_T
	template<size_t N_i,size_t N_pf> 	// i es inicio
																		// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	constexpr inline
	void set_interval_0() noexcept {
		set_interval_0<N_i,N_pf>(base_ref_cthis());
	}
	/// OPERACIÓN DE PONER A VALOR DIG_Bm1 EN [N_0 , N_1) DEL NAT_REG_DIGS_T
	template<size_t N_i,size_t N_pf> 	// i es inicio
																		// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	constexpr inline
	void set_interval_Bm1() noexcept {
		set_interval_Bm1<N_i,N_pf>(base_ref_cthis());
	}
	/// OPERACIÓN DE PONER A VALOR DIG EN [N_0 , N_1) DEL NAT_REG_DIGS_T
	template<size_t N_i,size_t N_pf> 	// i es inicio
																		// pf es pasado el final
		requires ((N_i < N_pf)&&(N_pf <= L))
	constexpr inline
	void set_interval_dig(dig_t dig) noexcept {
		set_interval_0<N_i,N_pf>(base_ref_cthis(),dig);
	}

	/// OPERACIÓN COPIA DESDE UN DIGITO (CONVERSIÓN)
	constexpr inline
	nat_reg_digs_t & operator = (const dig_t & arg)
	noexcept {
		if (&const_by_index(0) != &arg) {
			set_0();
			by_index(0) = arg;
		}
		return (*this);
	}

	/// OPERACIÓN COPIA DESDE UN ENTERO (CONVERSIÓN A LA BASE B) A UN BASE_T
	template<type_traits::integral_c Int_Type>
	static constexpr inline
	const base_t& assign(base_t& larg,Int_Type arg) noexcept {
		using type_traits::maxbase;
		constexpr sint128_t B_128t_v{static_cast<sint128_t>(B)};
		constexpr bool puede_multiplicarse{
				(maxbase<sint128_t>()/B_128t_v) > 0
		};
		if ((&larg)!=(&arg)) {
			sint128_t creg_g{static_cast<sint128_t>(arg)};
			sint128_t BasePowIx{B_128t_v};
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
		return (larg);
	}

	/// OPERACIÓN COPIA DESDE UN ENTERO
	/// CONVERSIÓN A LA BASE B DEL OBJETO ARG DE TIPO INT_TYPE
	template<type_traits::integral_c Int_Type>
	constexpr inline nat_reg_digs_t & operator = (Int_Type arg) noexcept {
		using UInt_Type = std::conditional_t<
												std::is_signed_v<Int_Type>,
													std::conditional_t<
														type_traits::ge_sz_v<
																UINT_T,
																type_traits::sig_UInt_for_SInt_t<Int_Type>
														>,
															UINT_T,
															type_traits::sig_UInt_for_SInt_t<Int_Type>
													>,
													std::conditional_t<
														type_traits::ge_sz_v<
																UINT_T,
																Int_Type
														>,
															UINT_T,
															Int_Type
													>
											>;
		UInt_Type argc = static_cast<UInt_Type>((arg<0)?-arg:arg);
		constexpr UInt_Type Bc = static_cast<UInt_Type>(B);

		size_t ix{0};
		UInt_Type quotient = argc / Bc;
		UInt_Type remainder = argc % Bc;
		do {
			by_index(ix) = remainder;

			argc = quotient;
			quotient = argc / Bc;
			remainder = argc % Bc;

			++ix;
		} while( argc != 0 );

		if (ix < L-1)
			for( ; ix < L ; ++ix)
				by_index(ix) = dig_t::dig_0();

		return (*this);
	}

public:

	/// NAT_REG_N_T<L+M> NAT_REG_T::CAT(NAT_REG_N_T<M>)
	/// NAT_REG_N_T<L+M> NAT_REG_T::CAT_INV(NAT_REG_N_T<M>)
	/// NAT_REG_N_T<L+1> NAT_REG_T::CAT(DIG_T)
	/// NAT_REG_N_T<L+1> NAT_REG_T::CAT_INV(DIG_T)

	/// SUBREPR => SUB REPRESENTACION

	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	nat_reg_N_digs_t<N+L> cat(const nat_reg_N_digs_t<N> & arg) const noexcept
	{	return (concat<L,N>(base_cpy_cthis(),arg));	}

	constexpr inline
	nat_reg_N_digs_t<L+1> cat(dig_t arg) const
	noexcept {	return (concat<L>(base_cpy_cthis(),arg));	}

	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	nat_reg_N_digs_t<N+L> cat_inv(const nat_reg_N_digs_t<N> & arg) const noexcept
	{	return (concat<N,L>(arg,base_cpy_cthis()));	}

	constexpr inline
	nat_reg_N_digs_t<L+1> cat_inv(dig_t arg) const noexcept
	{	return (concat<L>(arg,base_cpy_cthis()));	}

	template<size_t ibegin,size_t iend>
		requires ((iend <= L)&&(ibegin < iend))
	constexpr inline
	nat_reg_N_digs_t<iend-ibegin> subrepr() const noexcept
	{	return subregister<L,ibegin,iend>(base_cpy_cthis());	}

				/****************************************/
				/*							      	    */
				/*       Algunas Conversiones    		*/
				/*							      		*/
				/****************************************/

	template<type_traits::integral_c Int_Type>
	constexpr inline operator Int_Type() const noexcept {
		using type_traits::maxbase;
		uint64_t retInt{0};
		uint64_t BasePowIx{1};
		for(size_t k{0} ; k < L ; ++k) {
			retInt += const_by_index(k)*BasePowIx;
			BasePowIx *= B;
			if(	(k+1 < L)
						&&
					( maxbase<Int_Type>() < (retInt+(const_by_index(k+1)*BasePowIx)) )	)
			{	return retInt; }
		}
		return retInt;
	}

public:

				/****************************************************/
				/*							    					*/
				/* OPERADORES COMPARATIVOS	 						*/
				/*							    					*/
				/****************************************************/

	/// OPERADOR COMPARACIÓN SPACESHIP C++20
	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	std::strong_ordering operator <=> (const nat_reg_N_digs_t<N>& arg)
	const noexcept {
		return (base_const_ref_cthis() <=> arg.base_const_ref_cthis());
	}

	/// OPERADOR COMPARACIÓN SPACESHIP C++20
	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	std::weak_ordering operator <=> (const base_N_t<N>& arg) const
	noexcept {
		return (base_const_ref_cthis() <=> arg);
	}

	/// OPERADOR COMPARACIÓN SPACESHIP C++20
	constexpr inline
	std::weak_ordering operator <=> (const dig_t & arg) const noexcept
	{	return (base_const_ref_cthis() <=> arg); }

				/********************************/
				/*							  	*/
				/* 		  PRIMER DIGITO	 	   	*/
				/*		  SEGUNDO DIGITO		*/
				/*							   	*/
				/********************************/

	inline constexpr
	dig_t operator[](size_t idx) const noexcept
	{
		return (cpy_by_index(idx));
	}

	inline constexpr
	dig_t& operator[](size_t idx) noexcept
	{
		return (by_index(idx));
	}

	template<type_traits::integral_c Int_Type=UINT_T>
	inline constexpr Int_Type operator()(size_t idx) const noexcept
	{
		return static_cast<Int_Type>(cpy_by_index(idx)());
	}

								/****************************/
								/*							*/
								/* OPERADORES ARITMÉTICOS	*/
								/*	POSTINCREMENTO ++(int)  */
								/*	PREINCREMENTO ++()		*/
								/*	POSTDECREMENTO --(int)  */
								/*	PREDECREMENTO ++()		*/
								/*                          */
								/****************************/
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
	auto	preincrement (base_t& arg)  noexcept ->
			std::conditional_t<
					with_result_type,
						res_base_op_t<binop_e::add>,
						const base_t &
			>
	{
		if constexpr (with_result_type) { /// true == tipo resultado
			/// CREAMOS EL RETORNO RET DE TIPO RESULTADO
			res_base_op_t<binop_e::add> ret{
				.result_content_low = static_cast<base_t>(arg),
				.carry							=	dig_t::dig_0(),
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
				result[0] = dig_t::dig_0();
				carry 		= dig_t::dig_1();
			}
			else {
				++result[0];
				carry 	= dig_t::dig_0();
				return ret;
			}
			/// BUCLE FOR QUE SUMA ARG Y 1 DESDE IDX=1 A IDX=L-1
			if (carry.is_not_0()) {
				for(size_t ix{1} ; ix < L ; ++ix) {
					if (carry.is_not_0()) {
						if (arg[ix] == dig_t::dig_Bm1()) {
							result[ix] = dig_t::dig_0();
							carry = dig_t::dig_1();
							continue;
						}
						else {
							++result[ix];
							carry = dig_t::dig_0();
							return ret;
						}
					}
				}
			}
			if (carry.is_not_0()) {
				good = false;
			}
			return ret;
		}
		else {
			/// CARRY INICIAL POR DEFECTO
			dig_t carry{dig_t::dig_0()};
			/// INCREMENTO DEL PRIMER DIGITO
			if (arg[0].is_Bm1()) {
				arg[0] = dig_t::dig_0();
				carry = dig_t::dig_1();
			}
			else {
				++arg[0];
				return (arg);
			}
			/// BUCLE FOR QUE SUMA ARG Y 1 DESDE IDX=1 A IDX=L-1
			for(size_t ix{1} ; ix < L ; ++ix) {
				if (carry.is_1()) {
					if (arg[ix].is_Bm1()) {
						arg[ix] 	= dig_t::dig_0();
						carry 		= dig_t::dig_1();
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
		preincrement<false>(base_ref_cthis());
		return (*this);
	}

private:

	template<bool with_result_type>
	static constexpr inline
	auto postincrement (base_t& arg) noexcept ->
			std::conditional<
					with_result_type,
							res_base_op_t<binop_e::add>,
							const base_t &
			>
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
		postincrement<false>(base_ref_cthis);
		return (*this);
	}

private :

	template<bool with_result_type>
	constexpr inline
	auto predecrement (base_t& arg) noexcept ->
		std::conditional<
				with_result_type,
						res_base_op_t<binop_e::sub>,
						const base_t&
				>
	{
		if constexpr (!with_result_type) {
			/// BORROW INICIAL POR DEFECTO
			dig_t borrow{dig_t::dig_0()};
			/// RESTA 1 A ARG EN IDX == 0
			if (arg[0].is_not_0()) {
				--arg[0];
				return (arg);
			} else {
				arg[0] = dig_t::dig_Bm1();
				borrow = dig_t::dig_1();
			}
			/// BUCLE FOR QUE RESTA A ARG UN 1 DESDE IDX=1 A IDX=L-1
			for(size_t ix{1} ; ix < L ; ++ix) {
				if (borrow.is_not_0()) {
					if (arg[ix].is_not_0()) {
						--arg[ix];
						return (arg);
					}
					else if (arg[ix].is_0()) {
						arg[ix] = dig_t::dig_Bm1();
						borrow = dig_t::dig_1();
					}
				}
			}
			return (arg);
		}
		else {
			/// CREAMOS EL RETORNO RET
			res_base_op_t<binop_e::sub> ret{
				.result_content_low	=	arg,
				.borrow							=	dig_t::dig_0(),
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
				borrow 		= dig_t::dig_0();
				return std::move(ret);
			} else {
				result[0] = dig_t::dig_Bm1();
				borrow 		= dig_t::dig_1();
			}
			/// BUCLE FOR QUE RESTA BORROW A ARG
			/// [DESDE 1 EN IDX=0] DESDE IDX=1 A IDX=L-1
			for(size_t ix{1} ; ix < L ; ++ix) {
				if (borrow.is_not_0()) {
					if (arg[ix].is_not_0()) {
						--result[ix];
						borrow = dig_t::dig_0();
						return std::move(ret);
					}
					else {
						result[ix] = dig_t::dig_Bm1();
						borrow = dig_t::dig_1();
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
		predecrement<false>(base_ref_cthis);
		return (*this);
	}

private :

	template<bool with_result_type>
	constexpr inline
	auto postdecrement(base_t& arg) noexcept ->
		std::conditional<
				with_result_type,
						res_base_op_t<binop_e::sub>,
						const base_t&
				>
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
		postdecrement<false>(base_ref_cthis);
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

//
//public :
//
//	constexpr inline
//	const nat_reg_digs_t & mC_B() noexcept
//	{
//		mC_B(base_ref_cthis);
//		return (*this);
//	}
//
//	constexpr inline
//	const nat_reg_digs_t & mC_Bm1() noexcept
//	{
//		mC_Bm1(base_ref_cthis);
//		return (*this);
//	}
//
//	constexpr inline
//	nat_reg_digs_t C_Bm1() const noexcept
//	{
//		return nat_reg_digs_t{C_Bm1(base_ref_cthis())};
//	}
//
//	constexpr inline
//	nat_reg_digs_t C_B() const noexcept
//	{
//		return nat_reg_digs_t{C_B(base_const_ref_cthis())};
//	}
//
//	constexpr inline
//	nat_reg_digs_t operator !() const noexcept
//	{
//		return C_Bm1();
//	}
//
//	constexpr inline
//	nat_reg_digs_t operator -() const noexcept
//	{
//		return C_B();
//	}


	/// BEGIN : OPERATORS >> >>= << <<= REM_B^n M_REM_B^n MER_B_N M_MER_B_N

	/// MULTIPLY BY THE BASE B (10) << <<=
	/// DIVIDE BY THE BASE B (10)	  >> >>=
	/// REMAINDER BY THE BASE B (10) REM_B_N M_REM_B_N
	/// MULTIPLICATIVE CARRY BY THE BASE B (10) MER_B_N M_MER_B_N

private :

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
		base_ref_cthis() <<= n;
		return (*this);
	}

	constexpr inline
	nat_reg_digs_t operator >> (size_t n) const noexcept
	{
		return (nat_reg_digs_t{*this}.ref_data() >>= n);
	}

	constexpr inline
	const nat_reg_digs_t & operator >>= (size_t n) noexcept
	{
		base_ref_cthis >>= n;
		return (*this);
	}

	constexpr inline
	nat_reg_digs_t rem_B(size_t n) const noexcept
	{
		nat_reg_digs_t ret{rem_B(base_ref_cthis,n)};
		return ret;
	}

	constexpr inline
	const nat_reg_digs_t & m_rem_B(size_t n) noexcept
	{
		m_rem_B(base_ref_cthis(),n);
		return (*this);
	}

	constexpr inline
	nat_reg_digs_t mer_B(size_t n) const noexcept
	{
		nat_reg_digs_t ret{mer_B(base_ref_cthis(),n)};
		return std::move(ret);
	}

	constexpr inline
	const nat_reg_digs_t & m_mer_B(size_t n) noexcept
	{
		m_mer_B(base_ref_cthis(),n);
		return (*this);
	}

	/// END   : OPERATORS >> >>= << <<= REM_B^n M_REM_B^n MER_B_N M_MER_B_N

	/// BEGIN : OPERATORS | & |= &=

public :

	constexpr inline
	const nat_reg_digs_t & operator |= (const nat_reg_digs_t & arg) noexcept
	{
		base_ref_cthis() |= arg.base_const_ref_cthis();
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
		base_ref_cthis() &= arg.base_const_ref_cthis();
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
					/*  ARITMETICOS CON ASIGNACIÓN			*/
					/*		nat_reg_digs_t @= dig_t				*/
					/*                                  */
					/************************************/

	/// OPERACIÓNES BINARIAS CON/SIN TIPO RESULTADO
	/// OPERACIÓNES BINARIAS
	///										BASE_T @ DIG_T
	/// OPERATOR BASE_T += DIG_T CON NOMBRE M_ADDITION
	template<bool with_result_type>
	static constexpr inline
	auto m_add (base_t & larg,const dig_t & rarg) noexcept ->
		typename std::conditional_t<
			with_result_type,
				res_base_op_t<binop_e::add>,
				base_t
		>
	{
		using namespace type_traits;
		constexpr UINT_T middle_max{std::numeric_limits<UINT_T>::max()/2};
		using SIG_UINT_T = sig_UInt_for_UInt_t<UINT_T>;
		using uint_type = std::conditional_t<B<=middle_max,UINT_T,SIG_UINT_T>;
		using dig_t = typename NumRepr::dig_t<uint_type,B>::dig_t;
		if constexpr (! with_result_type) {
			/// CARRY INICIAL POR DEFECTO
			dig_t carry{dig_t::dig_0()};
			/// SUMA DEL PRIMER DIGITO DE LARG[0] Y RARG
			if (larg[0] <= dig_t::dig_Bm1()-rarg) {
				larg[0] += rarg;
				return (larg);
			}
			else {
				larg[0] -= (dig_t::dig_Bm1()-rarg+1);
				carry = dig_t::dig_1();
			}
			/// BUCLE FOR QUE SUMA ARG Y 1 DESDE IDX=1 A IDX=L-1
			for(size_t ix{1} ; ix < L ; ++ix) {
				if (carry.is_1()) {
					if (larg[ix].is_Bm1()) {
						larg[ix] = dig_t::dig_0();
						carry = dig_t::dig_1();
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
				.carry								=		dig_t::dig_0(),
				.good_result					=		true
			};
			/// NOMBRE CORTO PARA RET.RESULT_CONTENT_LOW
			auto&		result{ret.result_content_low};
			/// NOMBRE CORTO PARA RET.CARRY
			dig_t&	carry{ret.carry};
			/// NOMBRE CORTO PARA RET.GOOD_RESULT
			bool&		good{ret.good_result};
			/// SUMA DEL PRIMER DIGITO DE LARG[0] Y RARG
			if (larg[0] <= dig_t::dig_Bm1()-rarg) {
				result[0]       +=	rarg;
				carry						 =	dig_t::dig_0();
				return std::move(ret);
			}
			else {
				ret.result_content[0]   -= (dig_t::dig_Bm1()+dig_t::dig_1()-rarg);
				carry                    = dig_t::dig_1();
			}
			/// BUCLE FOR QUE SUMA ARG Y 1 DESDE IDX=1 A IDX=L-1
			for(size_t ix{1} ; ix < L ; ++ix) {
				if (carry.is_not_0()) {
					if (result[ix].is_Bm1()) {
						result[ix]  = dig_t::dig_0();
						carry       = dig_t::dig_1();
					}
					else {
						++result[ix];
						carry = dig_t::dig_0();
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
		dig_t borrow{dig_t::dig_0()};
		/// SUMA DEL PRIMER DIGITO DE LARG[0] Y RARG
		if (larg[0] >= rarg) {
			larg[0] -= rarg;
			borrow = dig_t::dig_0();
			return (larg);
		}
		else {
			cprarg -= larg[0];
			larg[0] = cprarg.C_B();
			borrow 	= dig_t::dig_1();
		}
		/// BUCLE FOR QUE RESTA RARG A LARG DESDE IDX=1 A IDX=L-1
		for(size_t ix{1} ; ix < L ; ++ix) {
			if (borrow.is_1()) {
				if (larg[ix].is_0()) {
					larg[ix] = dig_t::dig_Bm1();
					borrow  = dig_t::dig_1();
					continue;
				}
				else {
					--larg[ix];
					borrow = dig_t::dig_0();
					return (larg);
				}
			}
		}
		return (larg);
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
		m_add<false>(base_ref_cthis(),rarg);
		return (*this);
	}

	constexpr inline
	const nat_reg_digs_t & operator -= (const dig_t& rarg) noexcept
	{
		m_sub<false>(base_ref_cthis(),rarg);
		return (*this);
	}

	constexpr inline
	nat_reg_digs_t operator + (const dig_t& rarg) noexcept
	{
		return nat_reg_digs_t{add(base_const_ref_cthis(),rarg)};
	}

	constexpr inline
	nat_reg_digs_t operator - (const dig_t& rarg) noexcept
	{
		return nat_reg_digs_t{sub(base_const_ref_cthis(),rarg)};
	}

private :

	/// OPERACIÓNES '@'(REG_DIGS_T,DIG_T)->RESULT_TYPE<'@'>
	/// '@' = MULT
	template<bool with_result_type>
	constexpr inline
	auto mult(dig_t arg) const noexcept ->
		std::conditional_t<
			with_result_type,
				res_base_op_t<binop_e::mult>,
				const base_t &
		>
	{
		nat_reg_digs_t cpthis(*this);
		if constexpr (with_result_type) {
			res_base_op_t<binop_e::mult> ret{
				.result_content_low 	= base_const_ref_cthis(),
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
			else if (nat_reg_digs_t::is_0()) {
				return std::move(ret);
			}
			else if (arg.is_1()) {
				return std::move(ret);
			}
			else if (nat_reg_digs_t::is_1()) {
				res_low.set_0();
				res_low[0] = arg;
				return std::move(ret);
			}
			else {
				constexpr UINT_T sqrt_max{type_traits::sqrt_max<UINT_T>()};
				using uint_type = std::conditional_t<
					B <= sqrt_max ,
						UINT_T,
						SIG_UINT_T
				>;
				constexpr uint_type Bc{B};
				uint_type carry{0};
				uint_type cparg{arg()};
				for(size_t ix{0} ; ix < L ; ++ix){
					uint_type digint{const_by_index(ix)};
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
			base_t ret{base_const_ref_cthis()};
			if (arg.is_0()) {                   // ????
				return std::move(regd_0());
			}
			else if (nat_reg_digs_t::is_0()) {  // ????
				return std::move(regd_0());
			}
			else if (arg.is_1()) {
				return std::move(ret);
			}
			else if (nat_reg_digs_t::is_1()) { //?????
				ret.set_0();
				ret[0] = arg;
				return std::move(ret);
			}
			else {
				constexpr UINT_T sqrt_max{type_traits::sqrt_max<UINT_T>()};
				using uint_type = std::conditional_t<
					B <= sqrt_max ,
						UINT_T,
						SIG_UINT_T
				>;
				constexpr uint_type Bc{B};
				uint_type carry{0};
				uint_type cparg{arg()};
				for(size_t ix{0} ; ix < L ; ++ix){
					uint_type digint{const_by_index(ix)};
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

//  /// TO DO REPASAR
//	/// '@' = '+'
//	constexpr inline
//	std::array<nat_reg_digs_t,2> add(dig_t arg) const
//	noexcept {
//		const nat_reg_digs_t& cthis{*this};
//		std::array<nat_reg_digs_t,2> result{dig_t::dig_0(),cthis};
//		dig_t carry{dig_t::dig_0()};
//		for(size_t ix{0} ; ix < L ; ++ix) {
//			auto 	temp_result   =      result[0][ix].add(arg);
//			auto  temp_result_2 = temp_result[0][ix].add(carry);
//			result[0][ix] = temp_result_2[0];
//			result[1][0]  = temp_result_2[1];
//			carry = result[1][0];
//		}
//		for(size_t ix{1} ; ix < L ; ++ix) {
//			result[1][ix] = dig_t::dig_0();
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
//		std::array<nat_reg_digs_t,2> result{dig_t::dig_0(),cthis};
//		nat_reg_digs_t cb_arg{-arg};
//		if (!(arg.is_0())) {
//			for(size_t ix{1} ; ix < L ; ++ix) {
//				cb_arg[ix] = dig_t::dig_Bm1();
//			}
//		}
//		dig_t carry{dig_t::dig_0()};
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

//		template<size_t N>
//		static constexpr inline
//		auto fediv<N,1>(const base_N_t<N>& larg,const base_N_t<1>& rarg)
//		noexcept -> res_base_N_op_t<binop_e::fediv,N> {
//			const dig_t & arg{rarg[0]};
//			return fediv<N>(larg,arg);
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
		requires ( N > 0 )
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
					carry = dig_t::dig_1();
			}
			for (size_t ix{N} ; ix < L ; ++ix) {
				dig_t& 				cthis{cthis.m_dc[ix]};
				const dig_t  	cpthis{cthis.m_dc[ix]};
				cthis += carry;
				if (cthis < cpthis)
					carry = dig_t::dig_1();
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
					carry = dig_t::dig_1();
			}
		}
		return (cthis);
	}

	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	const nat_reg_digs_t & operator += (const nat_reg_N_digs_t<N> & arg) noexcept
	{
		(*this)+= arg.m_dc;
		return (*this);
	}

	template<size_t N>
		requires ( N > 0 )
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
					carry = dig_t::dig_1();
			}
			// end
		cthis += cparg;
		return (cthis);
	}

	template<size_t N>
		requires ( N > 0 )
	constexpr inline
	const nat_reg_digs_t & operator -= (const nat_reg_N_digs_t<N> & arg) noexcept
	{
		(*this)-= arg.m_dc;
		return (*this);
	}

	template<size_t N>
		requires ( N > 0 )
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
		requires ( N > 0 )
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
//	const nat_reg_digs_t & operator %= ( const nat_reg_digs_t & arg )
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

	/// ESPECIALIZACIONES PARA NAT_REG_DIGS
  template<typename UInt_t,UInt_t B,size_t LE>
  bool is_nat_reg_digs_type_id(std::string in)
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

  template<typename UInt_t,UInt_t B,size_t LE>
  std::string to_nat_reg_digs_type_string()
  {   return std::string{"nat_reg_digs"};		}

  template<typename UInt_t,UInt_t B,size_t LE>
  size_t size_of_nat_reg_digs_type_string_idT()
  {	return (to_nat_reg_digs_type_string<UInt_t,B,LE>()).size();	}

	///	TODO
	/// ESTA VERSION +
	/// VERSION CON TRATAMIENTO DE ERRORES EN RUNTIME
	template<type_traits::uint_type_for_radix_c Int_Type,
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

	template<type_traits::uint_type_for_radix_c Int_Type,Int_Type Base,size_t Long>
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
