#ifndef INT_REG_DIGS_T_HPP
#define INT_REG_DIGS_T_HPP

#include "nat_reg_digs_t.hpp"

namespace NumRepr {

using type_traits::allowable_base_type_c;
using type_traits::suitable_base;

template<allowable_base_type_c UINT_T,UINT_T B,size_t L>
	requires (type_traits::suitable_base<UINT_T,B>() && (L>0))
struct int_reg_digs_t : protected nat_reg_digs_t<UINT_T,B,L> {
/// NECESITAMOS:
///			B = BASE EN LA QUE TRABAJAMOS
///					=> TIPO BASE 	UINT_T
///					=> TIPO 			SIG_UINT_T  ALGO MAYOR (EL DOBLE) QUE UINT_T
///					=> TIPO				SIG_SINT_T  TIPO CON SIGNO DONDE CABE UN UINT_T
///			L = LONGITUD DEL MODULO DEL NUMERO EN DIGITOS
///			DIGITO EXTRA PARA EL SIGNO
	using SIG_UINT_T 		= typename type_traits::sig_UInt_for_UInt_t<UINT_T>;
	using SIG_SINT_T 		= typename type_traits::sig_SInt_for_UInt_t<UINT_T>;
	using dig_t 				= dig_t<UINT_T,B>;
	template<std::size_t N>
		requires (N>0)
	using base_2_N_t      = std::array<dig_t,N>;
	using base_2_t				= base_2_N_t<L>;
	template<std::size_t N>
		requires (N>0)
	using base_N_t			= nat_reg_digs_t<UINT_T,B,N>;
	using base_t      	= base_N_t<L>;
	template<std::size_t N>
		requires (N>0)
	using int_reg_N_digs_t	= int_reg_digs_t<UINT_T,B,N>;

	template<std::size_t N>
		requires (N>0)
	using reg_N_ints_t		        = typename std::array<UINT_T,N>;
	template<std::size_t N>
		requires (N>0)
	using reg_N_ints_t_suints_t	= typename std::array<SIG_UINT_T,N>;
	template<std::size_t N>
		requires (N>0)
	using reg_N_ssints_t			= typename std::array<SIG_SINT_T,N>;

	constexpr auto minus           = sign_e::vminus;
	constexpr auto plus              = sign_e::vplus;

private:
	sign_e signo{};
	base_t magnitud{};

public :

	static constexpr dig_t 				dig_0()				noexcept	{return dig_t::dig_0();}
	static constexpr dig_t 				dig_1()				noexcept	{return dig_t::dig_1();}
	static constexpr dig_t 				dig_Bm1()		noexcept	{return dig_t::dig_max();}
	static constexpr dig_t 				dig_max()			noexcept	{return dig_t::dig_max();}
	static constexpr dig_t 				dig_Bm2()		noexcept	{return dig_t::dig_submax();}
	static constexpr dig_t 				dig_submax()	noexcept	{return dig_t::dig_submax();}
	static constexpr UINT_T 			ui_0()				noexcept	{return dig_t::ui_0();}
	static constexpr UINT_T 			ui_1() 				noexcept	{return dig_t::ui_1();}
	static constexpr UINT_T 			ui_Bm1() 			noexcept	{return B-1;}
	static constexpr UINT_T 			ui_B() 		    	noexcept	{return B;}
	static constexpr UINT_T 			ui_submax()		noexcept	{return dig_t::ui_submax();}
	static constexpr UINT_T 			ui_max() 			noexcept  {return dig_t::ui_max();}
	static constexpr SIG_UINT_T	sui_0()				noexcept	{return dig_t::sui_0();}
	static constexpr SIG_UINT_T	sui_1() 		    	noexcept	{return dig_t::sui_1();}
	static constexpr SIG_UINT_T 	sui_Bm1() 		noexcept	{return dig_t::sui_B()-1;}
	static constexpr SIG_UINT_T	sui_B() 			noexcept  {return dig_t::sui_B();}
	static constexpr SIG_UINT_T 	sui_Bp1() 		noexcept	{return dig_t::sui_B()+1;}

	///< FUNCIONES DE AYUDA QUE DEVUELVEN UNA CONSTANTE (POR MOVIMIENTO)
	///< CONSTANTES DE TIPO base_2_N_t<N>
	///< base_2_N_t : ES EL TIPO DEL STD::ARRAY<DIG_T<B>,N> QUE ES EL TIPO BASE DE
	///< 							nat_reg_digs_t<B,N>
	///< base_2_t 	: ES EL TIPO DEL STD::ARRAY<DIG_T<B>,L> QUE ES EL TIPO BASE DE
	///< 							nat_reg_digs_t<B,L> QUE ES EL TIPO DEL MODULO
	///< base_N_t		: ES EL TIPO BASE DEL MODULO DEL ENTERO QUE ESTAMOS
	///<							CONSTRUYENDO PERO DE LONGITUD N CUALQUIERA
	///< base_t			: ES EL TIPO BASE DEL MODULO DEL ENTERO QUE ESTAMOS
	///<							CONSTRUYENDO (LONGITUD L)

	template<std::size_t N>
		requires (N>0)
	static constexpr base_2_N_t<N>&& 	regd_b2_0()
	noexcept {
		return std::move(base_2_N_t<N>{dig_0()});
	}

	template<std::size_t N>
		requires (N>0)
	static constexpr base_2_N_t<N>&&	regd_b2_1()
	noexcept {
		base_2_N_t<N> ret{dig_0()};
		ret[0] = dig_1();
		return std::move(ret);
	}

	template<std::size_t N>
		requires (N>0)
	static constexpr base_2_N_t<N>&&	regd_b2_Bm1()
	noexcept {
		base_2_N_t<N> ret{regd_b2_0<N>()};
		ret[0] = dig_Bm1();
		return std::move(ret);
	}

	template<std::size_t N>
		requires (N>0)
	static constexpr base_2_N_t<N>&&	regd_b2_B()
	noexcept {
		base_2_N_t<N> ret{regd_b2_0<N>()};
		ret[1] = dig_1();
		return std::move(ret);
	}

	template<std::size_t N,std::size_t n>
		requires ((N > 0)&&(n >= 0)&&(n < N))
	static constexpr base_2_N_t<N>&&	regd_b2_pow_n_B()
	noexcept {
		base_2_N_t<N> ret{regd_b2_0<N>()};
		ret[n] = dig_1();
		return std::move(ret);
	}

	template<std::size_t N,std::size_t n>
		requires ((N > 0)&&(n >= 0)&&(n < L))
	static constexpr base_2_N_t<N>&&	regd_b2_pow_n_B_m1()
	noexcept	{
		base_2_N_t<N> ret{dig_Bm1()};
		for(std::size_t ix{n} ; ix < N ; ++ix) {
			ret[ix] = dig_0();
		}
		return std::move(ret);
	}

	///< 	CONSTANTES DE TIPO base_N_t<N>

	template<std::size_t N>
		requires (N>0)
	static constexpr base_N_t<N>&& 	regd_N_0()
	noexcept {
		base_N_t ret{std::move(regd_b2_0<N>())};
		return std::move(ret);
	}

	template<std::size_t N>
		requires (N>0)
	static constexpr base_N_t<N>&&	regd_N_1()
	noexcept {
		base_N_t<N> ret{std::move(regd_b2_0<N>())};
		ret[0] = dig_1();
		return std::move(ret);
	}

	template<std::size_t N>
		requires (N>0)
	static constexpr base_N_t<N>&&	regd_N_Bm1()
	noexcept {
		base_N_t<N> ret{std::move(regd_b2_0<N>())};
		ret[0] = dig_Bm1();
		return std::move(ret);
	}

	template<std::size_t N>
		requires (N>0)
	static constexpr base_N_t<N>&&	regd_N_B()
	noexcept {
		base_N_t<N> ret{std::move(regd_b2_0<N>())};
		ret[1] = dig_1();
		return std::move(ret);
	}

	template<std::size_t N,std::size_t n>
		requires ((N > 0)&&(n >= 0)&&(n < N))
	static constexpr base_N_t<N>&&	regd_N_pow_n_B()
	noexcept {
		base_N_t<N> ret{std::move(regd_b2_0<N>())};
		ret[n] = dig_1();
		return std::move(ret);
	}

	template<std::size_t N,std::size_t n>
		requires ((N > 0)&&(n >= 0)&&(n < L))
	static constexpr base_N_t<N>&&	regd_N_pow_n_B_m1()
	noexcept	{
		base_N_t<N> ret{std::move(regd_b2_Bm1<N>())};
		for(std::size_t ix{n} ; ix < N ; ++ix) {
			ret[ix] = dig_0();
		}
		return std::move(ret);
	}
	///<  TODO LO HECHO PARA base_N_t<N> HECHO PARA base_t
	static constexpr base_t&& 	regd_0()
	noexcept {
		return std::move(regd_N_0<L>());
	}

	static constexpr base_t&&	regd_1()
	noexcept {
		return std::move(regd_N_1<L>());
	}

	static constexpr base_t&&	regd_Bm1()
	noexcept {
		return std::move(regd_N_Bm1<L>());
	}

	static constexpr base_t&&	regd_B()
	noexcept {
		return std::move(regd_N_B<L>());
	}

	template<std::size_t n>
		requires ((n >= 0)&&(n < L))
	static constexpr base_t&&	regd_pow_n_B()
	noexcept {
		return std::move(regd_N_pow_n_B<L,n>());
	}

	template<std::size_t n>
		requires ((n >= 0)&&(n < L))
	static constexpr base_t&&	regd_pow_n_B_m1()
	noexcept	{
		return std::move(regd_N_pow_n_B_m1<L,n>());
	}

	///< 	CONSTANTES DE TIPO int_reg_N_digs_t<N>
	///<  ALTERNA VALOR POSITIVO CON NEGATIVO

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	static constexpr int_reg_N_digs_t<N>&& 	sregd_N_0()
	noexcept {
		return std::move(int_reg_N_digs_t<N>{signo{vplus},magnitud{regd_0<N>()}});
	}

	constexpr inline
	static constexpr int_reg_digs_t&& 	sregd_0()
	noexcept {
		return std::move(sregd_N_0<L>());
	}

	template<std::size_t N>
		requires (N>0)
	static constexpr int_reg_N_digs_t<N>&&	sregd_N_1()
	noexcept {
		return std::move(int_reg_N_digs_t<N>{signo{vplus},magnitud{regd_1()<N>()}});
	}

	constexpr inline
	static constexpr int_reg_digs_t&& 	sregd_1()
	noexcept {
		return std::move(sregd_N_1()<L>());
	}

	template<std::size_t N>
		requires (N>0)
	static constexpr int_reg_N_digs_t<N>&&	sregd_N_m1()
	noexcept {
		return std::move(int_reg_N_digs_t<N>{signo{vminus},magnitud{dig_Bm1()}});
	}

	static constexpr int_reg_digs_t&&	sregd_m1()
	noexcept {
		return std::move(sregd_N_m1<L>);
	}

	template<std::size_t N>
		requires (N>0)
	static constexpr int_reg_N_digs_t<N>&&	sregd_N_Bm1()
	noexcept {
		return std::move(int_reg_N_digs_t<N>{signo{vplus},magnitud{regd_N_Bm1<N>()}});
	}

	static constexpr int_reg_digs_t&&	sregd_Bm1()
	noexcept {
		return std::move(sregd_N_Bm1<L>());
	}
	///< B = 16 ; L =3 ;
	///< mBp1 -16+1=-15=-FF1
	///< TODO TODO TODO
	template<std::size_t N>
		requires (N>0)
	static constexpr int_reg_N_digs_t<N>&&	sregd_N_mBp1()
	noexcept {
		return std::move(int_reg_N_digs_t<N>{
			signo{vminus},
			magnitud{
				std::move(
					concatenate_homogeneus_containers<dig_t,N-1,1>()
					nat_reg_digs_t<UINT_T,B,N-1>{dig_Bm1()}.concat(nat_reg_digs_t<UINT_T,B,1>{dig_1()})
				)
			}
		}
		);
	}

	static constexpr int_reg_digs_t&&	sregd_mBp1()
	noexcept {
		return std::move(sregd_N_mBp1<L>());
	}

	template<std::size_t N>
		requires (N>0)
	static constexpr int_reg_N_digs_t<N>&& sregd_N_B()
	noexcept {
		return std::move(int_reg_N_digs_t<N>{
			signo{vplus},
			magnitud{std::move((regd_0<N-1>().concat(regd_1<1>())).concat(regd_0<1>())})
		});
	}

	static constexpr int_reg_digs_t&& sregd_B()
	noexcept {
		return std::move(sregd_N_B<L>());
	}

	///< B = 16 ; L =3 ;
	///< mB -16=-(FFF-010+001)=-(FEF+001)=-(FF0)

	template<std::size_t N>
		requires (N>0)
	static constexpr int_reg_N_digs_t<N>&& sregd_N_mB()
	noexcept {
		return std::move(int_reg_N_digs_t<N>{
			signo{vminus},
			magnitud{std::move(
				std::array<dig_t,N-1>(dig_Bm1()).concat(std::array<dig_t,1>(dig_0()))
			)}
		});
	}

	static constexpr int_reg_digs_t&& sregd_mB()
	noexcept {
		return std::move(sregd_N_mB<L>());
	}

	///< TODO : 21m:18h:03d:11m:2022

	template<std::size_t N,std::size_t n>
		requires ((N > 0)&&(n >= 0)&&(n < N))
	static constexpr int_reg_N_digs_t<N>&& sregd_pow_n_B()
	noexcept {
		int_reg_N_digs_t<N> ret{};
		ret.signo = sign_e::vplus;
		ret.magnitud = regd_0();
		ret.magnitud[n] = dig_1();
		return std::move(ret);
	}

	template<std::size_t n>
		requires ((n >= 0)&&(n < L))
	static constexpr int_reg_digs_t&& sregd_pow_n_B()noexcept {
		int_reg_digs_t ret{};
		ret.signo = sign_e::vplus;
		ret.magnitud = regd_0<L>();
		ret.magnitud[n] = dig_1();
		return std::move(ret);
	}

	template<std::size_t N,std::size_t n>
		requires ((N > 0)&&(n >= 0)&&(n < N))
	static constexpr int_reg_N_digs_t<N>&& sregd_m_pow_n_B()noexcept {
		int_reg_N_digs_t<N> ret{};
		ret.signo = sign_e::vminus;
		ret.magnitud = regd_Bm1();
		for(std::size_t ix{0} ; ix < n-1 ; ++ix)
			ret.magnitud[ix] = dig_0();
		return std::move(ret);
	}

	template<std::size_t n>
		requires ((n >= 0)&&(n < L))
	static constexpr int_reg_digs_t&& sregd_m_pow_n_B()noexcept {
		int_reg_digs_t ret{};
		ret.signo = sign_e::vminus;
		ret.magnitud = regd_Bm1<L>();
		for(std::size_t ix{0} ; ix < n-1 ; ++ix)
			ret.magnitud[ix] = dig_0();
		return std::move(ret);
	}

	template<std::size_t N,std::size_t n>
		requires ((N > 0) && (n >= 0) && (n < N))
	static constexpr int_reg_N_digs_t<N>&&sregd_pow_n_B_m1()noexcept	{
		int_reg_N_digs_t<N> ret{};
		ret.signo = sign_e::vplus;
		for(std::size_t ix{0} ; ix < n ; ++ix) {
			ret.magnitud[ix] = dig_0();
		}
		for(std::size_t ix{n} ; ix < N ; ++ix) {
			ret.magnitud[ix] = dig_Bm1();
		}
		return std::move(ret);
	}

	template<std::size_t n>
		requires ((n >= 0) && (n < L))
	static constexpr int_reg_digs_t&&sregd_pow_n_B_m1()noexcept	{
		int_reg_digs_t ret{};
		ret.signo = sign_e::vplus;
		for(std::size_t ix{0} ; ix < n ; ++ix) {
			ret.magnitud[ix] = dig_0();
		}
		for(std::size_t ix{n} ; ix < L ; ++ix) {
			ret.magnitud[ix] = dig_Bm1();
		}
		return std::move(ret);
	}

	template<std::size_t N,std::size_t n>
		requires ((N > 0) && (n >= 0) && (n < N))
	static constexpr int_reg_N_digs_t<N>&&sregd_m_pow_n_B_m1()noexcept	{
		int_reg_N_digs_t<N> ret{};
		ret.signo = sign_e::vminus;
		ret.magnitud = regd_0();
		ret.magnitud[n] = dig_1();
		return std::move(ret);
	}

	template<std::size_t n>
		requires ((n >= 0) && (n < L))
	static constexpr int_reg_digs_t&& sregd_m_pow_n_B_m1()noexcept	{
		int_reg_digs_t ret{};
		ret.signo = sign_e::vminus;
		ret.magnitud = regd_0<L>();
		ret.magnitud[n] = dig_1();
		return std::move(ret);
	}

	///< FUNCIONES QUE DEVUELVEN ARRAYS CONSTANTES DE ENTEROS QUE SON DE AYUDA
	template<std::size_t N>
		requires (N>0)
	static constexpr reg_ints_t<N>&& 	regi_0() 						noexcept	{
		reg_ints_t<N> ret{};
		for(auto& digint : ret) {
			digint = dig_0()();
		}
		return std::move(ret);
	}

	template<std::size_t N>
		requires (N>0)
	static constexpr reg_ints_t<N>&& regi_1() 					noexcept	{
		reg_ints_t<N> ret{regi_0()};
		ret[0] = dig_1()();
		return std::move(ret);
	}

	template<std::size_t N>
		requires (N>0)
	static constexpr reg_ints_t<N>&&	regi_Bm1() 				noexcept	{
		reg_ints_t<N> ret{regi_0()};
		ret[0] = dig_Bm1()();
		return std::move(ret);
	}

	template<std::size_t N>
		requires (N>0)
	static constexpr reg_ints_t<N>&&	regi_B() 					noexcept  {
		reg_ints_t<N> ret{regi_0()};
		ret[1] = dig_1()();
		return std::move(ret);
	}

	template<std::size_t N,std::size_t n>
		requires ((N > 0)&&(n >= 0)&&(n < N))
	static constexpr reg_ints_t<N>&&	regi_pow_n_B()		noexcept	{
		reg_ints_t<N> ret{regi_0()};
		ret[n] = dig_1()();
		return std::move(ret);
	}

	template<std::size_t N,std::size_t n>
		requires ((N > 0)&&(n >= 0)&&(n < N))
	static constexpr reg_ints_t<L>&&	regi_pow_n_B_m1()	noexcept	{
		reg_ints_t<N> ret{};
		for(std::size_t ix{0} ; ix < n ; ++ix) {
			ret[ix] = dig_t(B-1)();
		}
		for(std::size_t ix{n} ; ix < N ; ++ix) {
			ret[ix] = dig_t(0)();
		}
		return std::move(ret);
	}

				/****************************/
				/*													*/
				/*    CONSTRUIR NUMERO			*/
				/*													*/
				/****************************/
public:

	/// CONSTRUCTOR POR DEFECTO
	consteval inline
	int_reg_digs_t()
	noexcept : signo{sign_e::vplus}, magnitud{std::move(sregd_0<L>())} {}
	/// CONSTRUCTOR POR LISTA DE DIGITOS
	constexpr inline
	int_reg_digs_t(sign_e arg_sign,const std::initializer_list<dig_t> & arg)
	noexcept : signo{arg_sign},magnitud{arg} {}
	/// CONSTRUCTOR POR ARGUMENTOS DIGITOS SIN LIMITE: DEDUCE EL TIPO
	template<typename ... Ts>
		requires (std::is_same_v<Ts,dig_t>&&...)
	constexpr inline
	int_reg_digs_t(sign_e arg_sign,const Ts &... args)
	noexcept : signo{arg_sign}, magnitud{(utility::pack2array<Ts...>{})(args...)} {}
	/// BEGIN : CONSTRUCTOR COPIA/MOVIMIENTO DESDE UN ARRAY DE DIGITOS

	/// FUNCION DELEGADA PARA COPIA DE UN ARRAY DEL MISMO TAMANO
	/// O UN TAMANO CUALQUIERA "N"
	template<std::size_t N>
		requires (N>0)
	void copy_arg_N(const base_N_t<N> & arg) {
		if constexpr (N<L) {
			for(std::size_t ix{N} ; ix < L ; ++ix)
				magnitud[ix]=dig_0();
			for(std::size_t ix{0} ; ix < N ; ++ix)
				magnitud[ix]=arg[ix];
		}
		else {
			for(std::size_t ix{0} ; ix < L ; ++ix)
				magnitud[ix]=arg[ix];
		}
	}

	/// FUNCION DELEGADA PARA MOVER DE UN ARRAY DEL MISMO TAMANO
	/// O UN TAMANO CUALQUIERA "N"
	template<std::size_t N>
		requires (N>0)
	void move_arg_N(base_N_t<N>&& arg) {
		if constexpr (N<L) {
			for(std::size_t ix{N} ; ix < L ; ++ix)
				magnitud[ix]=std::move(dig_0());
			for(std::size_t ix{0} ; ix < N ; ++ix)
				magnitud[ix]=std::move(arg[ix]);
		}
		else if constexpr (N > L) {
			for(std::size_t ix{0} ; ix < L ; ++ix)
				magnitud[ix]=std::move(arg[ix]);
		}
		else {
			magnitud=std::move(arg);
		}
	}
	/// CONSTRUCTOR COPIA DESDE UN ARRAY DE DIGITOS
	template<std::size_t N>
		requires (N>0)
	constexpr inline
	int_reg_digs_t(sign_e argsign,const base_N_t<N> & arg)
	noexcept : signo{argsign},magnitud{copy_arg_N<N>(arg)} {}
	/// CONSTRUCTOR MOVIMIENTO DESDE UN ARRAY DE DIGITOS
	template<std::size_t N>
		requires (N>0)
	constexpr inline
	int_reg_digs_t(sign_e argsign,const base_N_t<N> && arg)
	noexcept : signo{argsign}, magnitud{move_arg_N<N>(arg)} {}
	/// END   : CONSTRUCTOR COPIA/MOVIMIENTO DESDE UN ARRAY DE DIGITOS
	/// FUNCION DE NORMALIZACION A LA BASE B DE UN ARGUMENTOS
	/// EN UN PACK DE ENTEROS CUALQUIERA
	template<type_traits::integral_c ... Ints_type>
		requires ((sizeof...(Ints_type))<=L)
	static constexpr inline
	base_t normalize(Ints_type ... digits_pow_i)
	noexcept {
		using pack_type 	= typename utility::pack2array<Ints_type...>;
		using unique_type = typename pack_type::elem_type;
		constexpr std::size_t pack_sz{pack_type::pack_size()};
		if constexpr ( type_traits::unsigned_integral_c<unique_type> ) {
			if constexpr (type_traits::is_unsigned_sz_gt_v<UINT_T,unique_type>) {
					using SUInt_type = type_traits::sig_UInt_for_UInt_t<UINT_T>;
					std::array<SUInt_type,L> ret_array{digits_pow_i...};
					base_t ret{};
					for(std::size_t ix{0} ; ix < pack_sz ; ++ix) {
						ret[ix] = dig_t(ret_array[ix]);
					}
					for(std::size_t ix{pack_sz} ; ix < L ; ++ix) {
						ret[ix] = dig_t(0);
					}
					return ret;
			}
			else {
					using SUInt_type = type_traits::sig_UInt_for_UInt_t<unique_type>;
					std::array<SUInt_type,L> ret_array{digits_pow_i...};
					base_t ret{};
					for(std::size_t ix{0} ; ix < pack_sz ; ++ix) {
						ret[ix] = dig_t(ret_array[ix]);
					}
					for(std::size_t ix{pack_sz} ; ix < L ; ++ix) {
						ret[ix] = dig_t(0);
					}
					return ret;
			}
		}
		else {
			using temp_SUInt_type = type_traits::sig_UInt_for_SInt_t<unique_type>;
			if constexpr (type_traits::is_unsigned_sz_gt_v<UINT_T,temp_SUInt_type>)
			{
					using SUInt_type = type_traits::sig_UInt_for_UInt_t<UINT_T>;
					std::array<SUInt_type,L> ret_array{digits_pow_i...};
					base_t ret{};
					for(std::size_t ix{0} ; ix < pack_sz ; ++ix) {
						if (ret_array[ix] < 0)
							ret[ix] = dig_t((((ret_array[ix]/(-B))+1)*B)+ret_array[ix]);
						else
							ret[ix] = dig_t(ret_array[ix]);
					}
					for(std::size_t ix{pack_sz} ; ix < L ; ++ix) {
						ret[ix] = dig_0();
					}
					return ret;
			}
			else {
					using SUInt_type = temp_SUInt_type;
					std::array<SUInt_type,L> ret_array{digits_pow_i...};
					base_t ret{};
					for(std::size_t ix{0} ; ix < pack_sz ; ++ix) {
						if (ret_array[ix] < 0)
							ret[ix] = dig_t((((ret_array[ix]/(-B))+1)*B)+ret_array[ix]);
						else
							ret[ix] = dig_t(ret_array[ix]);
					}
					for(std::size_t ix{pack_sz} ; ix < L ; ++ix) {
						ret[ix] = dig_0();
					}
					return ret;
			}
		}
	}
	/// CONSTRUCTOR COPIA DESDE ARGUMENTOS ENTEROS SIN LIMITE : DEDUCE EL TIPO
	template<type_traits::integral_c ... Ints_type>
	constexpr inline int_reg_digs_t(sign_e argsign, Ints_type ... dig_pow_i) noexcept :
		signo{sign_e::argsign},magnitud{normalize<Ints_type...>(dig_pow_i...)} {}
	/// CONSTRUCTOR COPIA POR REFERENCIA CONSTANTE
	template<std::size_t N>
		requires (N>0)
	constexpr inline int_reg_digs_t(const int_reg_N_digs_t<N> & arg) noexcept :
		signo{arg.signo},magnitud{copy_arg_N<N>(arg.magnitud)} {}
	/// CONSTRUCTOR POR MOVIMIENTO
	template<std::size_t N>
		requires (N>0)
	constexpr inline int_reg_digs_t(int_reg_N_digs_t<N> && arg) noexcept :
		signo{std::move(arg.signo)},magnituditud{move_arg_N(arg.magnitud)} {}

	/// OPERACION ASIGNACION POR COPIA REFERENCIA EN LA QUE SE PUEDE COPIAR
	template<std::size_t N>
		requires (N>0)
	constexpr inline int_reg_digs_t & operator = (int_reg_N_digs_t<N> & arg) noexcept
	{
		if (this != &arg) {
			copy_arg_N<N>(arg.m_dc);
		}
		return (*this);
	}
	/// OPERACION ASIGNACION POR MOVIMIENTO
	template<std::size_t N>
		requires (N>0)
	constexpr inline int_reg_digs_t & operator = (int_reg_N_digs_t<N> && arg) noexcept
	{
		if (this != &arg) {
			move_arg_N<N>(arg.m_dc);
		}
		return (*this);
	}
	/// OPERACION ASIGNACION POR COPIA EN LA QUE  _NO_  SE PUEDE COPIAR
	template<std::size_t N>
		requires (N>0)
	constexpr inline const int_reg_digs_t & operator = (const int_reg_N_digs_t<N> & arg)
	noexcept {
		if (this != arg) {
				copy_arg_N<N>(arg.m_dc);
		}
		return (*this);
	}
	/// OPERACION ASIGNACION POR COPIA DESDE BASE_N_T
	template<std::size_t N>
		requires (N>0)
	constexpr inline int_reg_digs_t & operator = (const base_N_t<N> & arg) noexcept
	{
		if (&(this->m_dc)!=(&arg))
			copy_arg_N<N>(arg);
		return (*this);
	}
	/// OPERACION COPIA DESDE UN DIGITO (CONVERSION)
	constexpr inline int_reg_digs_t & operator = (const dig_t & arg) noexcept {
		if (&(this->m_dc[0])!=(&arg)) {
			for (dig_t& dig : m_dc)
				dig = dig_0();
			m_dc[0] = arg;
		}
		return (*this);
	}
	/// OPERACION COPIA DESDE UN ENTERO (CONVERSION A LA BASE B)
	template<type_traits::integral_c Int_Type>
	constexpr inline int_reg_digs_t & operator = (Int_Type&& arg) noexcept {
		Int_Type creg_g{std::forward(arg)};
		if ((&(this->m_dc()))!=(&arg)) {
			uint128_t BasePowIx{1};
			for(std::size_t k{0u} ; k < L ; ++k) {
				BasePowIx *= B;
			}
			while (creg_g < 0) {
				creg_g += BasePowIx;
			}
			for(std::size_t k{0u} ; k < L ; ++k){
				m_dc[k] = dig_t(creg_g);
				creg_g /= B;
			}
		}
		return (*this);
	}

	/// FORMACION DE UN REG_M_DIGS_T<M> DESDE EL THIS REG_DIGS_T (L)
	/// Y REG_N_DIGS_T<N> EN SUS DOS FORMAS: (*THIS)SEGUIDO(ARG) Y
	/// (ARG)SEGUIDO(*THIS) : OPERACIONES DE CONCATENACION
	/// A SU VEZ PUEDEN SER POR COPIA Y POR MOVIMIENTO

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	int_reg_N_digs_t<N+L> concat(const int_reg_N_digs_t<N> & arg) const
	noexcept {
		const int_reg_digs_t & cthis{*this};
		int_reg_N_digs_t<N+L> ret{};
		for(std::size_t ix{0} ; ix < N ; ++ix) {
			ret[ix] = arg[ix];
		}
		for(std::size_t ix{N} ; ix < L+N ; ++ix) {
			ret[ix] = cthis[ix-N];
		}
		return ret;
	}
	constexpr inline
	int_reg_N_digs_t<L+1> concat(const dig_t & arg) const
	noexcept {
		const int_reg_digs_t & cthis{*this};
		int_reg_N_digs_t<L+1> ret{};
		ret[0] = arg;
		for(std::size_t ix{1} ; ix < L+1 ; ++ix) {
			ret[ix] = cthis[ix-1];
		}
		return ret;
	}
	template<std::size_t N>
		requires (N>0)
	constexpr inline
	int_reg_N_digs_t<N+L> concat_inv(const int_reg_N_digs_t<N> & arg) const
	noexcept {
		const int_reg_digs_t & cthis{*this};
		int_reg_N_digs_t<N+L> ret{};
		for(std::size_t ix{0} ; ix < L ; ++ix) {
			ret[ix] = cthis[ix];
		}
		for(std::size_t ix{L} ; ix < N+L ; ++ix) {
			ret[ix] = arg[ix-L];
		}
		return ret;
	}
	constexpr inline
	int_reg_N_digs_t<L+1> concat_inv(const dig_t & arg) const
	noexcept {
		const int_reg_digs_t & cthis{*this};
		int_reg_N_digs_t<L+1> ret{};
		for(std::size_t ix{0} ; ix < L ; ++ix) {
			ret[ix] = cthis[ix];
		}
		ret[L] = arg;
		return ret;
	}


	template<std::size_t N>
		requires (N>0)
	constexpr inline
	int_reg_N_digs_t<N+L> concat(int_reg_N_digs_t<N> && arg)
	noexcept {
		const int_reg_digs_t & cthis{*this};
		int_reg_N_digs_t<N+L> ret{};
		for(std::size_t ix{0} ; ix < N ; ++ix) {
			ret[ix] = std::move(arg[ix]);
		}
		for(std::size_t ix{N} ; ix < L+N ; ++ix) {
			ret[ix] = cthis[ix-N];
		}
		return ret;
	}
	constexpr inline
	int_reg_N_digs_t<L+1> concat(dig_t && arg)
	noexcept {
		const int_reg_digs_t & cthis{*this};
		int_reg_N_digs_t<L+1> ret{};
		ret[0] = std::move(arg);
		for(std::size_t ix{1} ; ix < L+1 ; ++ix) {
			ret[ix] = cthis[ix-1];
		}
		return ret;
	}

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	int_reg_N_digs_t<N+L> concat_inv(int_reg_N_digs_t<N> && arg)
	noexcept {
		const int_reg_digs_t & cthis{*this};
		int_reg_N_digs_t<N+L> ret{};
		for(std::size_t ix{0} ; ix < L ; ++ix) {
			ret[ix] = cthis[ix];
		}
		for(std::size_t ix{L} ; ix < N+L ; ++ix) {
			ret[ix] = std::move(arg[ix-L]);
		}
		return ret;
	}
	constexpr inline
	int_reg_N_digs_t<L+1> concat_inv(dig_t && arg)
	noexcept {
		const int_reg_digs_t & cthis{*this};
		int_reg_N_digs_t<L+1> ret{};
		for(std::size_t ix{0} ; ix < L ; ++ix) {
			ret[ix] = cthis[ix];
		}
		ret[L] = std::move(arg);
		return ret;
	}

	template<std::size_t ibegin,std::size_t iend>
		requires ((iend <= L)&&(ibegin < iend))
	constexpr inline
	int_reg_N_digs_t<iend-ibegin> subreg_digs() const
	noexcept {
		const int_reg_digs_t & cthis{*this};
		int_reg_N_digs_t<iend-ibegin> ret{};
		for(std::size_t ix{ibegin} ; ix < iend ; ++ix) {
			ret[ix-ibegin] = cthis[ix];
		}
		return ret;
	}
	template<std::size_t ibegin,std::size_t iend>
		requires ((iend-ibegin>0)&&(iend <= L)&&(ibegin < iend))
	constexpr inline
	int_reg_N_digs_t<iend-ibegin> rev_subreg_digs() const
	noexcept {
		const int_reg_digs_t & cthis{*this};
		int_reg_N_digs_t<iend-ibegin> ret{};
		for(std::int64_t ix{iend} ; ix > ibegin-1 ; --ix) {
			ret[ix-ibegin] = cthis[L-1-ix];
		}
		return ret;
	}

				/**********************************/
				/*							      						*/
				/*       Algunas Conversiones     */
				/*							      						*/
				/**********************************/

	template<type_traits::integral_c Int_Type>
	constexpr inline operator Int_Type() const noexcept {
		std::uint64_t retInt{0};
		std::uint64_t BasePowIx{1};
		for(std::size_t k{0} ; k < L ; ++k) {
			retInt += m_dc[k]*BasePowIx;
			BasePowIx *= B;
		}
		return (retInt);
	}

				/********************************/
				/*							    						*/
				/* OPERADORES COMPARATIVOS	 		*/
				/*							    						*/
				/********************************/

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	bool operator == (const int_reg_N_digs_t<N>& arg) const
	noexcept {
	  /// *this == nat#1:2:3:4#B7     L==4
	  /// arg   == nat#2:1:2:3:4#B7   N==5
		if constexpr (N>L) {
			for(std::size_t k{L} ; k < N ; ++k) {
				if (!(arg[k].is_0())) {
					return false;
				}
			}
		}
		/// *this == nat#1:2:3:4#B7     L==4
	  /// arg   == nat#2:3:4#B7       N==3
		else if constexpr (L>N) {
			for(std::size_t k{N} ; k < L ; ++k) {
				if (!(m_dc[k].is_0())) {
					return false;
				}
			}
		}
		constexpr auto Z{std::min(L,N)};
		for(std::size_t k{0} ; k < Z ; ++k) {
				if (m_dc[k]!=arg.m_dc[k])
					return false;
		}
		return true;
	}

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	bool operator != (const int_reg_N_digs_t<N>& arg) const
	noexcept {
		if constexpr (N>L) {
			for(std::size_t k{L} ; k < N ; ++k) {
				if (!(arg[k].is_0())) {
					return true;
				}
			}
		}
		else if constexpr (L>N) {
			for(std::size_t k{N} ; k < L ; ++k) {
				if (!(m_dc[k].is_0())) {
					return true;
				}
			}
		}
		constexpr auto Z{std::min(L,N)};
		for(std::size_t k{0} ; k < Z ; ++k) {
				const bool condition{m_dc[k]!=arg.m_dc[k]};
				if (condition) {
					return true;
				}
		}
		return false;
	}

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	bool operator <= (const int_reg_N_digs_t<N>& arg) const
	noexcept {
		if constexpr (N>L) {
			for(std::size_t k{L} ; k < N ; ++k) {
				if (!(arg[k].is_0())) {
					return true;
				}
			}
		}
		else if constexpr (L>N) {
			for(std::size_t k{N} ; k < L ; ++k) {
				if (!(m_dc[k].is_0())) {
					return false;
				}
			}
		}
		constexpr auto Z{std::min(L,N)};
		for(std::size_t k{0} ; k < Z ; ++k) {
				if (m_dc[k]<arg.m_dc[k]) {
					return true;
				}
				else if (m_dc[k]>arg.m_dc[k]) {
					return false;
				}
		}
		return true;
	}

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	bool operator >= (const int_reg_N_digs_t<N>& arg) const
	noexcept {
		if constexpr (N>L) {
			for(std::size_t k{L} ; k < N ; ++k) {
				if (!(arg[k].is_0())) {
					return false;
				}
			}
		}
		else if constexpr (L>N) {
			for(std::size_t k{N} ; k < L ; ++k) {
				if (!(m_dc[k].is_0())) {
					return true;
				}
			}
		}
		constexpr auto Z{std::min(L,N)};
		for(std::int64_t k{Z-1} ; k > -1 ; --k) {
				if (m_dc[k]>arg.m_dc[k]) {
					return false;
				}
				else if (m_dc[k]<arg.m_dc[k]) {
					return true;
				}
		}
		return true;
	}

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	bool operator <  (const int_reg_N_digs_t<N>& arg) const
	noexcept {
		if constexpr (N>L) {
			for(std::size_t k{L} ; k < N ; ++k) {
				if (!(arg[k].is_0())) {
					return true;
				}
			}
		}
		else if constexpr (L>N) {
			for(std::size_t k{N} ; k < L ; ++k) {
				if (!(m_dc[k].is_0())) {
					return false;
				}
			}
		}
		constexpr auto Z{std::min(L,N)};
		for(std::int64_t k{Z-1} ; k > -1 ; --k) {
				if (m_dc[k]<arg.m_dc[k]) {
					return true;
				}
				else if (m_dc[k]>arg.m_dc[k]) {
					return false;
				}
		}
		return false;
	}

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	bool operator > (const int_reg_N_digs_t<N> & arg) const
	noexcept {
		if constexpr (N>L) {
			for(std::size_t k{L} ; k < N ; ++k) {
				if (!(arg[k].is_0())) {
					return false;
				}
			}
		}
		else if constexpr (L>N) {
			for(std::size_t k{N} ; k < L ; ++k) {
				if (!(m_dc[k].is_0())) {
					return true;
				}
			}
		}
		constexpr auto Z{std::min(L,N)};
		for(std::int64_t k{Z-1} ; k > -1 ; --k) {
				if (m_dc[k]>arg[k]) {
					return true;
				}
				else if (m_dc[k]<arg[k]) {
					return false;
				}
		}
		return false;
	}
	/// CONSTRUCTOR COMPARACION OPERADOR SPACESHIP C++20

	template<std::size_t N>
		requires ((N>0)&&(N<L))
	constexpr inline
	std::strong_ordering operator <=> (const int_reg_N_digs_t<N>& arg) const
	noexcept {
		const int_reg_digs_t & cthis{*this};
		for(std::size_t ix{N} ; ix < L ; ++ix) {
			if (!(cthis[ix].is_0()))
				return std::strong_ordering::greater;
		}
		int_reg_N_digs_t<N> cpthis{};
		for(std::size_t ix{0} ; ix < N ;++ix)
			cpthis[ix] = cthis[ix];
		if (cpthis == arg)
			return std::strong_ordering::equal;
		else if (cpthis < arg)
			return std::strong_ordering::less;
		else
			return std::strong_ordering::greater;
	}

	template<std::size_t N>
		requires ((N>0)&&(N>L))
	constexpr inline
	std::strong_ordering operator <=> (const int_reg_N_digs_t<N>& arg) const
	noexcept {
		const int_reg_digs_t & cthis{*this};
		for(std::size_t ix{L} ; ix < N ; ++ix) {
			if (!(arg[ix].is_0()))
				return std::strong_ordering::greater;
		}
		int_reg_N_digs_t<L> cparg{};
		for(std::size_t ix{0} ; ix < L ;++ix)
			cparg[ix] = arg[ix];
		if (cthis == cparg)
			return std::strong_ordering::equal;
		else if (cthis < cparg)
			return std::strong_ordering::less;
		else
			return std::strong_ordering::greater;
	}

				/********************************/
				/*							  							*/
				/* 		  PRIMER DIGITO	 	   			*/
				/*		  SEGUNDO DIGITO					*/
				/*							   							*/
				/********************************/

	template<std::size_t I>
		requires ((I<L)&&(I>=0))
	inline constexpr const dig_t& get() const noexcept {
		return (m_dc[I]);
	}

	template<std::size_t I>
		requires ((I<L)&&(I>=0))
	inline constexpr void put(const dig_t & arg) noexcept {
		m_dc[I] = arg; return;
	}

	template<std::size_t I>
		requires ((I<L)&&(I>=0))
	inline constexpr void put(dig_t && arg) noexcept {
		m_dc[I] = std::move(arg); return;
	}

	inline constexpr const dig_t & operator[](std::size_t idx) const noexcept {
		return (m_dc[idx]);
	}

	inline constexpr dig_t & operator[](std::size_t idx) noexcept {
		return (m_dc[idx]);
	}

	inline constexpr UINT_T operator()(std::size_t idx) const noexcept {
		return (m_dc[idx]());
	}

								/****************************/
								/*													*/
								/* OPERADORES ARITMETICOS		*/
								/*	POSTINCREMENTO ++(int)  */
								/*	PREINCREMENTO ++()		  */
								/*	POSTDECREMENTO --(int)  */
								/*	PREDECREMENTO ++()		  */
								/*                          */
								/****************************/

	constexpr inline
	const int_reg_digs_t & operator ++ ()
	noexcept {
		int_reg_digs_t& cthis(*this);
		/// CARRY INICIAL ES 1
		dig_t carry{dig_1()};
		/// BUCLE FOR QUE SUMA CTHIS Y 1 DESDE IDX=0 A IDX=L-1
		for(std::size_t ix{0} ; ix < L-1 ; ++ix) {
			if ((cthis[ix]==dig_Bm1())&&(carry == dig_1())) {
				cthis[ix]=dig_0();
				carry = dig_1();
			}
			else if ((cthis[ix]<dig_Bm1())&&(carry == dig_1())){
				if (carry != dig_0()) {
					++cthis[ix];
					// carry = dig_0();
					break;
				}
			}
		}
		return cthis;
	}

	constexpr inline
	int_reg_digs_t operator ++ (int)
	noexcept {
		int_reg_digs_t cpthis(*this);
		++(*this);
		return cpthis;
	}

	constexpr inline
	const int_reg_digs_t & operator -- ()
	noexcept {
		int_reg_digs_t& cthis(*this);
		/// CARRY INICIAL ES EL COMPLEMENTO A LA BASE DE 1
		dig_t carry{dig_0()};
		/// BUCLE FOR QUE SUMA CTHIS Y C_B(1) DESDE IDX=0 A IDX=L-1
		for(std::size_t ix{0} ; ix < L-1 ; ++ix) {
				SIG_UINT_T temp{cthis(ix)+B-1+carry()};
				cthis[ix]=dig_t(temp);
				carry = dig_t(temp/B);
		}
		return cthis;
	}

	constexpr inline
	int_reg_digs_t operator -- (int)
	noexcept {
		int_reg_digs_t cpthis(*this);
		--(*this);
		return cpthis;
	}

								/****************************/
								/*													*/
								/* OPERADORES ARITMETICOS		*/
								/*	 C_B()  C_Bm1()  				*/
								/*	mC_B() mC_Bm1()		      */
								/*	operator!() operator-() */
								/*                          */
								/****************************/

	constexpr inline
	const int_reg_digs_t & mC_Bm1()
	noexcept {
		int_reg_digs_t& cthis(*this);
		for(std::size_t ix{0} ; ix < L ; ++ix) {
				cthis[ix] = !cthis[ix];
		}
		return cthis;
	}

	constexpr inline
	const int_reg_digs_t & mC_B()
	noexcept {
		int_reg_digs_t& cthis(*this);
		cthis.mC_Bm1();
		dig_t carry{dig_1()};
		/// BUCLE FOR QUE SUMA CTHIS Y 1 DESDE IDX=0 A IDX=L-1
		for(std::size_t ix{0} ; ix < L ; ++ix) {
			if ((cthis[ix]==dig_Bm1())&&(carry != dig_1())) {
				cthis[ix]=dig_0();
				carry = dig_1();
			}
			else if (carry == dig_1()){
				++cthis[ix];
				break;
			}
		}
		return (cthis);
	}

	constexpr inline
	int_reg_digs_t C_Bm1() const
	noexcept
	{
		int_reg_digs_t cpthis(*this);
		cpthis.mC_Bm1();
		return cpthis;
	}

	constexpr inline
	int_reg_digs_t C_B() const
	noexcept {
		int_reg_digs_t cpthis(*this);
		cpthis.mC_B();
		return cpthis;
	}

	constexpr inline
	int_reg_digs_t operator ! () const
	noexcept {
		int_reg_digs_t cpthis(*this);
		cpthis.mC_Bm1();
		return cpthis;
	}

	constexpr inline
	int_reg_digs_t operator - () const
	noexcept {
		int_reg_digs_t cpthis(*this);
		cpthis.mC_B();
		return cpthis;
	}

					/************************************/
					/* OPERADORES ARITMETICOS BASICOS	 	*/
					/*			int_reg_digs_t	@  dig_t		*/
					/*      int_reg_digs_t	@= dig_t    */
					/*      int_reg_digs_t  @  10B^n    */
					/*      int_reg_digs_t  @= 10B^n    */
					/************************************/

					/************************************/
					/*								   								*/
					/*  ARITMETICOS CON ASIGNACION			*/
					/*			 int_reg_digs_t @= dig_t		*/
					/*                                  */
					/************************************/

	constexpr inline
	const int_reg_digs_t & operator += (dig_t arg)
	noexcept {
		int_reg_digs_t& cthis(*this);
		/// CARRY INICIAL ES 1
		dig_t carry{arg};
		/// CASOS CARRY==0[ULTIMA], CARRY==1[VECES SIGUIENTES], CARRY=ARG [1A VEZ]
		/// SI ARG == 0 ENTONCES SE DEVUELVE SIN MÁS
		/// SI ARG == 1 ENTONCES ++CTHIS
		/// SI ARG >  1 ENTONCES 1a VEZ dig_BmArg
		///                      2a VEZ dig_Bm1   Y SIGUIENTES
		///                             ULTIMA VEZ CARRY ==0
		if (arg==dig_0()) {
			return (cthis);
		} else if (arg == dig_1()) {
			return (++cthis);
		} else {
			const dig_t dig_BmArg{dig_Bm1()-(arg-dig_1())};
			/// PRIMERA VEZ : ARG > 1 usamos dig_BmArg
			if (cthis[0]==dig_BmArg) {
				cthis[0] = dig_0();
				carry    = dig_1();
			}
			/// SEGUNDA VEZ Y SIGUIENTES
			/// BUCLE FOR QUE SUMA CTHIS Y 1 DESDE IDX=0 A IDX=L-1
			for(std::size_t ix{1} ; ix < L-1 ; ++ix) {
				if (cthis[ix]==dig_Bm1()&& !(carry.is_0())) {
					cthis[ix]=dig_0();
					carry = dig_1();
				}
				else if ((cthis[ix]<dig_Bm1())&&(carry == dig_1())){
					if (carry != dig_0()) {
						++cthis[ix];
						break;
					}
				}
			}
			return cthis;
		}
	}

	constexpr inline
	const int_reg_digs_t & operator -= (dig_t arg)
	noexcept {
		int_reg_digs_t& cthis(*this);
		/// CARRY INICIAL ES 1
		dig_t carry{arg};
		/// CASOS CARRY==0[ULTIMA], CARRY==1[VECES SIGUIENTES], CARRY=ARG [1A VEZ]
		/// SI ARG == 0 ENTONCES SE DEVUELVE SIN MÁS
		/// SI ARG == 1 ENTONCES ++CTHIS
		/// SI ARG >  1 ENTONCES 1a VEZ dig_BmArg
		///                      2a VEZ dig_Bm1   Y SIGUIENTES
		///                             ULTIMA VEZ CARRY == 0
		if (arg==dig_0()) {
			return (cthis);
		} else if (arg == dig_1()) {
			return (--cthis);
		} else {
			const dig_t dig_CBArg{arg.C_B()};
			const dig_t dig_sig_Arg{dig_Bm1()};

			/// PRIMERA VEZ : SUMAMOS EL COMPLEMENTO A LA BASE DE ARG
			if (cthis(0)+dig_CBArg()>dig_Bm1()()) {
				carry = dig_1();
			} else {
				carry = dig_0();
			}
			cthis[0] += dig_CBArg;

			/// SEGUNDA VEZ Y SIGUIENTES
			/// BUCLE FOR QUE SUMA CTHIS Y 1 DESDE IDX=0 A IDX=L-1
			for(std::size_t ix{1} ; ix < L-1 ; ++ix) {
				if (cthis[ix].is_0() && carry.is_0()) {
					cthis[ix]=dig_Bm1();
					carry = dig_0();
				}
				else if (cthis[ix].is_0() && !carry.is_0()) {
					cthis[ix]=dig_0();
					carry = dig_1();
				}
				else if (cthis[ix].is_1() && carry.is_0()) {
					cthis[ix]=dig_0();
					carry = dig_1();
				}
				else {
					cthis[ix] += dig_Bm1();
					cthis[ix] += carry;
					carry = dig_1();
				}
			}
			return cthis;
		}
	}

	/// OPERACIONES '@'(REG_DIGS_T,DIG_T)->STD::ARRAY<REG_DIGS_T,2>
	/// '@' = MULT
	constexpr inline
	std::array<int_reg_digs_t,2> mult(dig_t arg) const
	noexcept {
		int_reg_digs_t cpthis(*this);
		std::array<int_reg_digs_t,2> ret{};
		if (arg.is_0()) {
			cpthis = ret[0];
			return ret;
		}
		else if (arg.is_1()) {
			ret[0] = cpthis;
			return ret;
		}
		else {
			dig_t carry{dig_0()};
			for(std::size_t ix{0} ; ix < L ; ++ix){
				const auto res = cpthis[ix].mult(arg);
				const auto uds = res[0].add(carry);
				ret[0][ix] = cpthis[ix] = uds[0] + carry;
				carry = res[1] + uds[1];
			}
			ret[1][0]=carry;
			return ret;
		}
	}

	///< TO DO REVISAR
	/// '@' = EUCLID_DIV -> (REM,COC)
	std::array<int_reg_digs_t,2> full_euclid_div(dig_t dsor) {
		const int_reg_digs_t & dndo{*this};
		std::array<int_reg_digs_t,2> ret{};
						if (dsor == dig_0()) {
				return ret;
		}
		else 	if (dsor == dig_1()) {
			ret[0] = dndo;
			ret[1] = regd_0();
			return ret;
		}
		else 	if (dndo < regd_B()) {
			ret[0] = dndo[0] / dsor;
			ret[1] = dndo[0] % dsor;
			return ret;
		}
		else {
			int_reg_digs_t& coc{ret[0]};
			int_reg_digs_t& rem{ret[1]};
			for(std::int64_t lx{L-1} ; lx > -1 ; --lx) {
				if (dndo[lx]>=dsor) {
					coc << 1;
					coc[0] = dndo[lx]/dsor;
					rem[0] = dndo[lx]%dsor;
					rem << 1;
					rem[0] = dndo[lx-1];
				}
				else {
					rem << 1;
					rem[0] = dndo[lx-1];
					for (UINT_T int_coc{0}; int_coc < B ; ++int_coc) {
						auto X{dig_t(int_coc).mult(dsor)};
						int_reg_N_digs_t<2> prod{X[1],X[0]};
						if (prod >= rem) {
							rem -= prod;
							rem << 1;
							rem[0] = dndo[lx-2];
							coc << 1;
							coc[0] = dig_t(int_coc);
							break;
						}
					}
				}
			}
			return ret;
		}
	}

	/// '@' = '+'
	constexpr inline
	std::array<int_reg_digs_t,2> add(dig_t arg) const
	noexcept {
		const int_reg_digs_t& cthis{*this};
		std::array<int_reg_digs_t,2> result{dig_0(),cthis};
		dig_t carry{dig_0()};
		for(std::size_t ix{0} ; ix < L ; ++ix) {
			auto 	temp_result   =      result[0][ix].add(arg);
			auto  temp_result_2 = temp_result[0][ix].add(carry);
			result[0][ix] = temp_result_2[0];
			result[1][0]  = temp_result_2[1];
			carry = result[1][0];
		}
		for(std::size_t ix{1} ; ix < L ; ++ix) {
			result[1][ix] = dig_0();
		}
		return result;
	}

	/// TO DO REPASAR
	/// '@' = '-'
	constexpr inline
	std::array<int_reg_digs_t,2> subst(dig_t arg) const
	noexcept {
		const int_reg_digs_t& cthis{*this};
		std::array<int_reg_digs_t,2> result{dig_0(),cthis};
		int_reg_digs_t cb_arg{-arg};
		if (!(arg.is_0())) {
			for(std::size_t ix{1} ; ix < L ; ++ix) {
				cb_arg[ix] = dig_Bm1();
			}
		}
		dig_t carry{dig_0()};
		for(std::size_t ix{0} ; ix < L ; ++ix) {
			auto 	temp_result   =      result[0][ix].add(cb_arg[ix]);
			auto  temp_result_2 =     temp_result[0].add(carry);
			result[0][ix]  = temp_result_2[0];
			result[1][ix]  = (temp_result_2[1].add(temp_result_2[1]))[0];
			carry = result[1][ix];
		}
		return result;
	}


					/********************************/
					/*							 								*/
					/*    OPERADORES ARITMETICOS		*/
					/*			 int_reg_digs_t @ dig_t	*/
					/* 															*/
					/********************************/

		constexpr inline
		auto operator + (dig_t arg) const
		noexcept {
			int_reg_digs_t ret(*this);
			ret += arg;
			return ret;
		}

		constexpr inline
		auto operator - (dig_t arg) const
		noexcept {
			int_reg_digs_t ret(*this);
			ret -= arg;
			return ret;
		}

		constexpr inline
		auto operator * (dig_t arg) const
		noexcept {
			int_reg_digs_t ret(*this);
			ret *= arg;
			return ret;
		}

		/// "ARITHMETIC OPERATOR" : COMPLETE EUCLIDEAN DIVISION BY A DIGIT
		constexpr inline
		std::array<int_reg_digs_t,2> euclid_div (dig_t arg) const
		noexcept {
			const int_reg_digs_t& dndo{*this};
			const dig_t&      dsor{arg};
			const int_reg_digs_t<UINT_T,B,2> tmp_dsor{dig_0(),arg};
						int_reg_digs_t<UINT_T,B,2> part_rem{dig_0(),dndo[L-1]};
						int_reg_digs_t rem{regd_0()};
						int_reg_digs_t coc{regd_0()};
			if (dsor == dig_0()) {
				std::array<int_reg_digs_t,2> rem_coc{regd_0(),regd_0()};
				return rem_coc;/// ERROR DIVISION BY 0
			}
			else if (dsor == dig_1()) {
				std::array<int_reg_digs_t,2> rem_coc{regd_0(),(*this)};
				return rem_coc;
			}
			else if ((dndo == regd_0())||(dndo == regd_1())) {
				std::array<int_reg_digs_t,2> rem_coc{(*this),regd_0()};
				return rem_coc;
			}
			else if (dndo < regd_B()) {
					dig_t retcoc{dndo[1]/dsor};
					dig_t retrem{dndo[1]%dsor};
					coc[0]=retcoc;
					rem[0]=retrem;
					return std::make_pair(rem,coc);
			}
			else {
				int_reg_digs_t<UINT_T,B,2> tmp_dsor{dig_0(),arg};
				std::int64_t ph_dndo{L-1};
				std::int64_t pl_dndo{L-1};
				// ph_dndo >= ix >= pl_dndo
				while((ph_dndo>-1)&&(pl_dndo>-1)) {
					if (pl_dndo == L-1) {
						part_rem[1] = dig_0();
						part_rem[0] = dndo[L-1];
					}
					else if ((pl_dndo == 0)&&(ph_dndo == 1)) {
						part_rem[1] = dndo[1];
						part_rem[0] = dndo[0];
					}
					else if ((pl_dndo == 0)&&(ph_dndo == 0)) {
						part_rem[1] = dig_0();
						part_rem[0] = dndo[0];
					}
					else if (ph_dndo > pl_dndo) {
						part_rem[1] = dndo[ph_dndo];
						part_rem[0] = dndo[pl_dndo];
					}
					else {
						part_rem[1] = dig_0();
						part_rem[0] = dndo[pl_dndo];
					}

					coc << 1;
					if (part_rem>=tmp_dsor) {
						dig_t cocdig{dig_0()};
						while(part_rem>=tmp_dsor) {
							++cocdig;
							part_rem -= tmp_dsor;
						}
						coc |= cocdig;
						if (ph_dndo > pl_dndo) {
							--ph_dndo;
							--pl_dndo;
						}
						else {
							--pl_dndo;
						}
					}
					else {
						if (ph_dndo > pl_dndo) {
							--ph_dndo;
							--pl_dndo;
						}
						else {
							--pl_dndo;
						}
					}
				}
				rem[1]=part_rem[1];
				rem[0]=part_rem[0];
				std::array<int_reg_digs_t,2> rem_coc{std::make_pair(rem,coc)};
				return rem_coc;
			}
		}
		/// DIVISION BY A DIGIT
		constexpr inline
		int_reg_digs_t operator / (dig_t arg) const
		noexcept {
			return (this->euclid_div(arg))[0];
		}
		/// REMAINDER BY A DIGIT
		constexpr inline
		int_reg_digs_t operator % (dig_t arg) const
		noexcept {
			return (this->euclid_div(arg))[1];
		}
		/// BEGIN : OPERATORS >> >>= << <<=
		/// MULTIPLY BY THE BASE B (10)
		constexpr inline
		int_reg_digs_t operator << (std::size_t n) const
		noexcept {
			int_reg_digs_t cpthis{*this};
			for(std::int64_t ix{n-1} ; ix > -1 ; --ix) {
				cpthis[ix+n] = cpthis[ix];
				cpthis[ix] = dig_0();
			}
			return cpthis;
		}

		constexpr inline
		const int_reg_digs_t & operator <<= (std::size_t n)
		noexcept {
			int_reg_digs_t& cthis{*this};
			for(std::int64_t ix{n-1} ; ix > -1 ; --ix) {
				cthis[ix+n] = cthis[ix];
				cthis[ix] = dig_0();
			}
			return (*this);
		}
		/// DIVIDE BY THE BASE B (10)
		constexpr inline
		int_reg_digs_t operator >> (std::size_t n) const
		noexcept {
			int_reg_digs_t cpthis{*this};
			for(std::int64_t ix{0} ; ix < n ; ++ix) {
				cpthis[ix] = cpthis[ix+n];
				cpthis[ix+n] = dig_0();
			}
			return cpthis;
		}
		constexpr inline
		const int_reg_digs_t & operator >>= (std::size_t n)
		noexcept {
			int_reg_digs_t& cthis{*this};
			for(std::int64_t ix{0} ; ix < n ; ++ix) {
				cthis[ix] = cthis[ix+n];
				cthis[ix+n] = dig_0();
			}
			return (*this);
		}
		/// END   : OPERATORS >> >>= << <<=
		/// BEGIN : "OPERATORS" REM_B^n AND M_REM_B^n
		/// REMAINDER BY THE BASE B (10)
		constexpr inline
		int_reg_digs_t rem_B(std::size_t n) const
		noexcept {
			int_reg_digs_t ret{regd_0()};
			for(std::size_t ix{0} ; ix < n ; ++ix) {
				ret[ix] = m_dc[ix];
			}
			return ret;
		}

		constexpr inline
		const int_reg_digs_t & m_rem_B(std::size_t n)
		noexcept {
			for(std::size_t ix{n} ; ix < L ; ++ix) {
				m_dc[ix] = dig_0();
			}
			return (*this);
		}
		/// REMAINDER BY THE BASE B (10)
		/// END   : "OPERATORS" REM_B^n AND M_REM_B^n

		/// BEGIN : OPERATORS | & |= &=
		constexpr inline
		const int_reg_digs_t & operator |= (const int_reg_digs_t & arg)
		noexcept {
			for(std::size_t ix{0} ; ix < L ; ++ix) {
				m_dc[ix] |= arg[ix];
			}
			return (*this);
		}

		constexpr inline
		int_reg_digs_t operator | (const int_reg_digs_t & arg)
		noexcept {
			int_reg_digs_t ret{*this};
			ret |= arg;
			return ret;
		}

		constexpr inline
		const int_reg_digs_t & operator &= (const int_reg_digs_t & arg)
		noexcept {
			for(std::size_t ix{0} ; ix < L ; ++ix) {
				m_dc[ix] &= arg[ix];
			}
			return (*this);
		}

		constexpr inline
		int_reg_digs_t operator & (const int_reg_digs_t & arg)
		noexcept {
			int_reg_digs_t ret{*this};
			ret &= arg;
			return ret;
		}

	/// END   : OPERATORS | & |= &=

								/**************************************/
								/*													  				*/
								/* OPERADORES ARITMETICOS		  				*/
								/* int_reg_digs_t @ int_reg_digs_t		*/
								/*                            				*/
								/**************************************/

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	const int_reg_digs_t & operator += (const base_N_t<N> & arg)
	noexcept {
		int_reg_digs_t & cthis = (*this);
		dig_t  				carry{0};
		if constexpr (N < L) {
			for (std::size_t ix{0} ; ix < N ; ++ix) {
				dig_t& 				cthis{cthis.m_dc[ix]};
				const dig_t  	cpthis{cthis.m_dc[ix]};
				const dig_t  	cparg{arg[ix]};
				cthis += cparg;
				cthis += carry;
				if ((cthis < cpthis) || (cparg < cpthis))
					carry = dig_1();
			}
			for (std::size_t ix{N} ; ix < L ; ++ix) {
				dig_t& 				cthis{cthis.m_dc[ix]};
				const dig_t  	cpthis{cthis.m_dc[ix]};
				cthis += carry;
				if (cthis < cpthis)
					carry = dig_1();
			}
		}
		else {
			for (std::size_t ix{0} ; ix < L ; ++ix) {
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

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	const int_reg_digs_t & operator += (const int_reg_N_digs_t<N> & arg)
	noexcept {
		(*this)+= arg.m_dc;
		return (*this);
	}

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	const int_reg_digs_t & operator -= (const base_N_t<N> & arg)
	noexcept {
		int_reg_digs_t & cthis{*this};
		base_N_t<N> cparg{arg};
		///< cparg pasa a ser el complemento a la base menos 1 de cparg
			// begin
			for(auto & elem_dig : cparg) {
				elem_dig = dig_t(B-1)-elem_dig;
			}
			dig_t  			carry{0};
			for (std::size_t ix{0} ; ix < N ; ++ix) {
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

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	const int_reg_digs_t & operator -= (const int_reg_N_digs_t<N> & arg)
	noexcept {
		(*this)-= arg.m_dc;
		return (*this);
	}

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	const int_reg_digs_t & operator *= (const base_N_t<N> & arg)
	noexcept {
		int_reg_digs_t cpthis{*this};
		int_reg_digs_t& cthis{0};
		for(std::size_t ix{0} ; ix < N ; ++ix) {
			cthis += (cpthis*arg[ix]);
			cpthis <<= 1;
		}
		return (cthis);
	}

	template<std::size_t N>
		requires (N>0)
	constexpr inline
	const int_reg_digs_t & operator *= (const int_reg_N_digs_t<N> & arg)
	noexcept {
		(*this)*= arg.m_dc;
		return (*this);
	}

/// TO DO
//	constexpr inline
//	const int_reg_digs_t & operator /= (const int_reg_digs_t & arg)
//	noexcept {
//		int_reg_digs_t & ret = (*this);
//		/// TO DO
//		return (*this);
//	}
/// TO DO
//	constexpr inline
//	const int_reg_digs_t & operator %= (const int_reg_digs_t & arg)
//	noexcept {
//		int_reg_digs_t & cthis{*this};
//		/// TO DO
//		return (*this);
//	}

		template<std::size_t N>
		constexpr inline
		int_reg_digs_t operator + (const base_N_t<N> & arg) const
		noexcept {
			int_reg_digs_t ret(*this);
			ret += arg;
			return ret;
		}

		template<std::size_t N>
		constexpr inline
		int_reg_digs_t operator - (const base_N_t<N> & arg) const
		noexcept {
			int_reg_digs_t ret(*this);
			ret -= arg;
			return ret;
		}

		template<std::size_t N>
		constexpr inline
		int_reg_digs_t operator * (const base_N_t<N> & arg) const
		noexcept {
			int_reg_digs_t ret(*this);
			ret *= arg;
			return ret;
		}

		template<std::size_t N>
		constexpr inline
		int_reg_digs_t operator + (const int_reg_N_digs_t<N> & arg) const
		noexcept {
			int_reg_digs_t ret(*this);
			ret += arg;
			return ret;
		}

		template<std::size_t N>
		constexpr inline
		int_reg_digs_t operator - (const int_reg_N_digs_t<N> & arg) const
		noexcept {
			int_reg_digs_t ret(*this);
			ret -= arg;
			return ret;
		}

		template<std::size_t N>
		constexpr inline
		int_reg_digs_t operator * (const int_reg_N_digs_t<N> & arg) const
		noexcept {
			int_reg_digs_t ret(*this);
			ret *= arg;
			return ret;
		}


		constexpr inline static
		std::size_t cuenta_0s_desde_IZDA(const reg_ints_t<L>& arg)
		noexcept {
			std::size_t ret{0};
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
		std::size_t cuenta_0s_desde_DRCHA(const reg_ints_t<L>& arg)
		noexcept {
			std::size_t ret{0};
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
		int_reg_digs_t operator / (const int_reg_digs_t & arg) const
		noexcept {
			const int_reg_digs_t& dndo{*this};
			const int_reg_digs_t& dsor{arg};
			const std::int64_t num_0s_IZDA_dsor{cuenta_0s_desde_IZDA(dsor)};
			const std::int64_t num_0s_IZDA_dndo{cuenta_0s_desde_IZDA(dndo)};
			const std::int64_t MSDig_dsor{L-1-num_0s_IZDA_dsor};
			const std::int64_t MSDig_dndo{L-1-num_0s_IZDA_dndo};
			int_reg_digs_t rem{regd_0()};
			int_reg_digs_t coc{regd_0()};
			for(std::int64_t num_loops{0} ;
											num_loops < std::abs(MSDig_dndo-MSDig_dndo)
																	 ; ++num_loops)
			{
				if (MSDig_dsor > MSDig_dndo) {
					return regd_0();
				}
				else if (MSDig_dsor == MSDig_dndo) {
					for(std::int64_t ix{MSDig_dsor} ; ix > -1 ; --ix) {
							if (dsor[ix] > dndo[ix]) {
								return regd_0();// DEVUELVE COCIENTE := 0 Y RESTO := DNDO
							}
							else if (dsor[ix] == dndo[ix]) {
								if (ix == 0)
									return regd_1();// DEVUELVE COCIENTE := 1 Y RESTO := 0
								else
									continue;
							}
							else {
								int_reg_digs_t coc{0};
								int_reg_digs_t idndo{dndo};
								int_reg_digs_t idsor{dsor};
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
					return (*this);// DEVUELVE COCIENTE := DNDO Y RESTO := 0
				}
				else if (dsor == regd_0()) {
					return (*this);/// ERROR DIVISION BY 0
				}
				else {
					std::int64_t pl_dndo{MSDig_dsor};
					std::int64_t ph_dndo{MSDig_dndo};

					// ph_dndo >= ix > pl_dndo
					for(std::int64_t ix{pl_dndo} ; ix <= ph_dndo ; ++ix) {
						rem[ix-pl_dndo] = dndo[ix];
					}

					if (rem == dsor) {
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
						for(std::int64_t ix{ph_dndo} ; ix > pl_dndo ; --ix) {
							rem[ix-pl_dndo+1] = rem[ix-pl_dndo];
						}
						rem[pl_dndo] = dndo[pl_dndo];
						--ph_dndo;
					}
					else {
						if (pl_dndo != 0) {
							--pl_dndo;
							for(std::int64_t ix{ph_dndo} ; ix > pl_dndo ; --ix) {
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
		int_reg_digs_t operator % (const int_reg_digs_t & arg) const
		noexcept {
			int_reg_digs_t ret(*this);
			UINT_T retuds 	= ret.m_dc[0]();
			UINT_T retdecs 	= ret.m_dc[1]();
			UINT_T arguds 	= arg.m_dc[0]();
			UINT_T argdecs 	= arg.m_dc[1]();

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

    ///  dig_t   DISTINTAS REPRESENTACIONES
    /// "dig_t,dig_t,..,dig_t" L digitos int_reg_digs_t
    /// "dig_t,dig_t,...,dig_t,sep,dig_t,dig_t,...,dig_t" LE SEP LF pf_int_reg_digs_t  C_B
    /// "dig_t,dig_t,...,dig_t,sep,dig_t,dig_t,...,dig_t" LE SEP LF pf_int_reg_digs_t  MS     ***
    /// "dig_t,dig_t,...,dig_t,sep,dig_t,dig_t,...,dig_t" LE SEP LF pf_int_reg_digs_t  EXC_N  ***
    /// "signo,dig_t,dig_t,..,dig_t" L digitos int_reg_digs_t  C_B
    /// "signo,dig_t,dig_t,..,dig_t" L digitos int_reg_digs_t  MS     ***
    /// "signo,dig_t,dig_t,..,dig_t" L digitos int_reg_digs_t  EXC_N  ***
    /// "signo,dig_t,dig_t,...,dig_t,sep,dig_t,dig_t,...,dig_t" LE SEP LF pf_int_reg_digs_t  C_B
    /// "signo,dig_t,dig_t,...,dig_t,sep,dig_t,dig_t,...,dig_t" LE SEP LF pf_int_reg_digs_t  MS    ***
    /// "signo,dig_t,dig_t,...,dig_t,sep,dig_t,dig_t,...,dig_t" LE SEP LF pf_int_reg_digs_t  EXC_N ***
    /// "dig_t,dig_t,...dig_t" numero variable de digitos nat_num_t
    /// "signo,dig_t,dig_t,...dig_t" numero variable de digitos int_num_t C_B
    /// "dig_t,dig_t,...dig_t/dig_t,dig_t,...dig_t" numero variable de digitos en denominador y numerador ***
    /// "signo,dig_t,dig_t,...dig_t" numero variable de digitos int_num_t C_B
    /// "signo,dig_t,dig_t,...dig_t" numero variable de digitos int_num_t C_B
    ///                                             numero variable de digitos en denominador y numerador ***
    /// EXTENSIONES P-ADICAS              ***
    /// EXTENSIONES FRACCIONES CONTINUAS  ***

};


					/****************************/
					/*													*/
					/* 	   ISTREAM Y OSTREAM		*/
					/*													*/
					/****************************/

	/// std::istream operator >> int_reg_digs_t /// pasamos error a std::cerr
	/// get_reg_digs_t(std::istream,std::ostream,int_reg_digs_t)
	///
	/// estados regulares st_00 st_01 st_02 st_03 st_04 st_05 st_06 st_07 st_08
	///										st_09 st_10 st_11 st_12
	/// estados error sintáctico
	///										st_err_00 st_err_01 st_err_02 st_err_03 st_err_04
	///										st_err_05 st_err_06 st_err_07 st_err_08 st_err_09
	///										st_err_10 st_err_11
	/// estados error semántico
	///										st_sem_00 st_sem_01 st_sem_02 st_sem_03 st_sem_04
	///										st_sem_05 st_sem_06 st_sem_07 st_sem_08 st_sem_09
	///										st_sem_10 st_sem_11 st_sem_12
	namespace lex{
	enum class reglexst_e : uint16_t {
		st_00 = 0,st_01 = 1,st_02 = 2,st_03 = 3 ,st_04 = 4 ,st_05 = 5 ,
		st_06 = 6,st_07 = 7,st_08 = 8,st_09 = 9 ,st_10 = 10,st_11 = 11,
		st_12 = 12
	};
	enum class sintaxerrlexst_e : uint16_t {
		st_err_00 = 256,st_err_01 = 257,st_err_02 = 258,
		st_err_03 = 259,st_err_04 = 260,st_err_05 = 261,
		st_err_06 = 262,st_err_07 = 263,st_err_08 = 264,
		st_err_09 = 265,st_err_10 = 266,st_err_11 = 267
	};
	enum class semerrlexst_e : uint16_t {
		st_sem_00 = 4096,st_sem_01 = 4097,st_sem_02 = 4098,st_sem_03 = 4099,
		st_sem_04 = 4100,st_sem_05 = 4101,st_sem_06 = 4102,st_sem_07 = 4103,
		st_sem_08 = 4104,st_sem_09 = 4105,st_sem_10 = 4106,st_sem_11 = 4107,
		st_sem_12 = 4108
	};
	enum class lexst_e : reglexst_e,sintaxerrlexst_e,semerrlexst_e {
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
		sem_12 = semerrlexst_e::st_sem_12
	};
	enum class type_token_e {
		nothing,type,separator,whitespace,digit,desc_radix,desc_end,sign
	};
	enum class action_e {
		nothing,report_error,go_to_another_st,get_number_digit,get_radix,get_sign
	};
	bool is_digit(char in) {
		return ((in >= '0')||(in <= '8'));
	}
	bool is_valid_char(char in) {
		return (in>='a' && in <='z')||(in>='A' && in<='Z');
	}
	bool is_separator(char in) {
		return (in == '#');
	}
	bool is_space(char in) {
		return ((in == ' ')||(in == '\t'));
	}
	bool is_desc_end(char in) {
		return (in == '\n');/// PODRIA SER TAMBIEN EOL
	}
	bool is_desc_radix(char in) {
		return ((in == 'b')||(in == 'B'));
	}
	bool is_sign(char in) {
		return ((in == '+')||(in == '-'));
	}
	bool is_type_id(string in) {
		return
			(
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
	}//END NAMESPACE LEX
	template<type_traits::allowable_base_type_c Int_Type,
					Int_Type Base,
					size_t Length>
		requires (type_traits::suitable_base<Int_Type,Base>()&&(Length > 0))
	get_int_reg_digs_t(	std::istream& is,
											std::ostream& errs,
											int_reg_digs_t<Int_Type,Base,Length>& value
	) {

		using lexst 	= typename lex::lexst_e;
		using lextk 	= typename lex::type_token_e;
		using lexact 	= typename lex::action_e;

		lexst actual_st 	= lexst::reg_00;
		lextk actual_tk 	= lextk::nothing;
		lexact actual_act = lexact::nothing;

		bool get_new_char_in = true;
		std::string buffer_in;
		char input_char = nullchar();
		size_t index = 0;

		while (input_char != std::ios::eof()) {
			switch(actual_st) {
				case lexst::reg_00 : {
					if (is_space(input_char)) {
							actual_st  = lexst::reg_00;
							actual_tk  = lextk::nothing;
							actual_act = lexact::nothing;
							get_new_char_in = true;
					}
					else if (is_valid_char(input_char)) {
						local_buffer_in += input_char;
						if (is_type_id(local_buffer_in)) {
							actual_st  = lexst::reg_01;
							actual_tk  = lextk::type;
							actual_act = lexact::nothing;
							get_new_char_in = true;
						}
						else {
							actual_st  = lexst::reg_00;
							actual_tk  = lextk::nothing;
							actual_act = lexact::report_error;
							get_new_char_in = false;
						}
					}
					else {
						actual_st  = lexst::reg_00;
						actual_tk  = lextk::nothing;
						actual_act = lexact::report_error;
						get_new_char_in = false;
					}
				}
				break;
				case lexst::reg_01 :
					break;
				case lexst::reg_02 :
					break;
				case lexst::reg_03 :
					break;
				case lexst::reg_04 :
					break;
				case lexst::reg_05 :
					break;
				case lexst::reg_06 :
					break;
				case lexst::reg_07 :
					break;
				case lexst::reg_08 :
					break;
				case lexst::reg_09 :
					break;
				case lexst::reg_10 :
					break;
				case lexst::reg_11 :
					break;
				case lexst::reg_12 :
					break;
				case lexst::err_00 :
					break;
				case lexst::err_01 :
					break;
				case lexst::err_02 :
					break;
				case lexst::err_03 :
					break;
				case lexst::err_04 :
					break;
				case lexst::err_05 :
					break;
				case lexst::err_06 :
					break;
				case lexst::err_07 :
					break;
				case lexst::err_08 :
					break;
				case lexst::err_09 :
					break;
				case lexst::err_10 :
					break;
				case lexst::err_11 :
					break;
				case lexst::sem_00 :
					break;
				case lexst::sem_01 :
					break;
				case lexst::sem_02 :
					break;
				case lexst::sem_03 :
					break;
				case lexst::sem_04 :
					break;
				case lexst::sem_05 :
					break;
				case lexst::sem_06 :
					break;
				case lexst::sem_07 :
					break;
				case lexst::sem_08 :
					break;
				case lexst::sem_09 :
					break;
				case lexst::sem_10 :
					break;
				case lexst::sem_11 :
					break;
				case lexst::sem_12 :
					break;
				default :
			}
			if (get_new_char_in) {
				input_char = buffer_iner_in[index];
				++index;
			}
		}
	}

	template<type_traits::allowable_base_type_c Int_Type,
					Int_Type Base,
					size_t Length>
		requires (type_traits::suitable_base<Int_Type,Base>()&&(Length > 0))
	std::istream &
	operator >> (std::istream & is,int_reg_digs_t<Int_Type,Base,Length> & arg) {
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
		using int_reg_digs_t = int_reg_digs_t<Int_Type,Base,Length>;
		/// INDICE QUE RECORRE EL STRING RECOGIDO DE ENTRADA
		std::size_t	indice{0};
		/// VARIABLES PARA ACCIONES EN LOS ESTADOS
		Int_Type 		digito{0};
		std::size_t longitud{0};
		inttype 		numero_base_recogido{0};
		/// VARIABLE DE RETORNO (BINDED TO THE ARG BY REFERENCE)
		int_reg_digs_t& numero_ret{arg};
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
							numero_ret = int_reg_digs_t::regd_0();
						}
						else  {
							est_act = e0ini;
							digito = 0;
							longitud = 0;
							numero_base_recogido = 0;
							numero_ret = int_reg_digs_t::regd_0();
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
							numero_ret = int_reg_digs_t::regd_0();
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
							numero_ret = int_reg_digs_t::regd_0();
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
							numero_ret = int_reg_digs_t::regd_0();
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
							numero_ret = int_reg_digs_t::regd_0();
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

	template<type_traits::allowable_base_type_c Int_Type,Int_Type Base,std::size_t Long>
		requires (type_traits::suitable_base<Int_Type,Base>())
	std::ostream &
	operator << (std::ostream & os,const int_reg_digs_t<Int_Type,Base,Long> & arg) {
		using inttype = typename type_traits::sig_UInt_for_UInt_t<Int_Type>;
		os << "reg_dig#";
		for(std::int64_t ix{Long-1} ; ix > 0 ; --ix) {
				os << static_cast<inttype>(arg(ix));
				os << ':';
		}
		os << static_cast<inttype>(arg(0));
		os << "#B";
		os << static_cast<inttype>(Base);
		return (os);
	}


#endif
