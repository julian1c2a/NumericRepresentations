#ifndef NAT_RAT_FIXED_REG_T_HPP_INCLUDED
#define NAT_RAT_FIXED_REG_T_HPP_INCLUDED

#include "int_reg_digs_t.hpp"
#include "utilities.hpp"

namespace NumRepr {

template<type_traits::allowable_base_type_c UINT_T,UINT_T B,std::size_t LE,std::size_t LF>
	requires (type_traits::suitable_base<UINT_T,B>() && (LE>0))
struct nat_rat_fixed_reg_t {
	using dig_t = dig_t<UINT_T,B>;
	template<std::size_t NE,std::size_t NF>
	using base_NEXNF_t = std::array<dig_t<UINT_T,B>,NE+NF>;
	using base_t       = base_NEXNF_t<LE,LF>;
	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	using pfx_rat_reg_NExNF_digs_t		= pfx_rat_reg_digs_t<UINT_T,B,NE,NF>;
	using SIG_UINT_T 		= typename type_traits::sig_UInt_for_UInt_t<UINT_T>;
	using SIG_SINT_T 		= typename type_traits::sig_SInt_for_UInt_t<UINT_T>;
	template<std::size_t NE,std::size_t NF>
	using nat_reg_NExNF_digs_t = nat_reg_digs_t<UINT_T,B,NE+NF>;
	using nat_reg_digs_t = nat_reg_digs_t<UINT_T,B,LE+LF>;
	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	using reg_ints_t		= typename std::array<UINT_T,NE+NF>;
	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	using reg_suints_t	= typename std::array<SIG_UINT_T,NE+NF>;
	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	using reg_ssints_t	= typename std::array<SIG_SINT_T,NE+NF>;
private:
	base_t m_dc;
public :
	static constexpr dig_t 			dig_0()				noexcept	{return dig_t::dig_0();}
	static constexpr dig_t 			dig_1()				noexcept	{return dig_t::dig_1();}
	static constexpr dig_t 			dig_Bm1()			noexcept	{return dig_t::dig_max();}
	static constexpr dig_t 			dig_max()			noexcept	{return dig_t::dig_max();}
	static constexpr dig_t 			dig_Bm2()			noexcept	{return dig_t::dig_submax();}
	static constexpr dig_t 			dig_submax()  noexcept	{return dig_t::dig_submax();}
	static constexpr UINT_T 		ui_0()				noexcept	{return dig_t::ui_0();}
	static constexpr UINT_T 		ui_1() 				noexcept	{return dig_t::ui_1();}
	static constexpr UINT_T 		ui_Bm1() 			noexcept	{return dig_t::ui_Bm1();}
	static constexpr SIG_UINT_T	sui_B() 			noexcept  {return dig_t::sui_B();}
	static constexpr SIG_UINT_T sui_Bp1() 		noexcept	{return dig_t::sui_B()+1;}
	static constexpr UINT_T 		ui_submax()		noexcept	{return dig_t::ui_submax();}
	static constexpr UINT_T 		ui_max() 			noexcept  {return dig_t::ui_max();}

	static constexpr pfx_rat_reg_digs_t 	regd_0() 		noexcept    {
		pfx_rat_reg_digs_t ret{};
		for(auto& dig : ret.m_dc) {
			dig = dig_0();
		}
		return ret;
	}
	static constexpr pfx_rat_reg_digs_t		regd_1() 		noexcept {
		pfx_rat_reg_digs_t ret{regd_0()};
		ret.m_dc[LF] = dig_1();
		return ret;
	}
	static constexpr pfx_rat_reg_digs_t		regd_Bm1() 		noexcept {
		pfx_rat_reg_digs_t ret{regd_0()};
		ret.m_dc[LF] = dig_Bm1();
		return ret;
	}
	static constexpr pfx_rat_reg_digs_t		regd_B() 		noexcept {
		pfx_rat_reg_digs_t ret{regd_0()};
		ret.m_dc[LF+1] = dig_1();
		return ret;
	}

	template<std::int32_t n>
		requires ((n < LE) && (n > -(LF+1)))
	static constexpr pfx_rat_reg_digs_t		regd_pow_n_B()	noexcept {
		pfx_rat_reg_digs_t ret{regd_0()};
		ret.m_dc[LF+n] = dig_1();
		return ret;
	}
	template<std::int32_t n>
		requires ((n < LE) && (n > -(LF+1)))
	static constexpr pfx_rat_reg_digs_t		regd_pow_n_B_m1()	noexcept    {
		pfx_rat_reg_digs_t ret{};
		for(std::size_t ix{-LF} ; ix < n ; ++ix) {
			ret.m_dc[LF+ix] = dig_t(B-1);
		}
		for(std::size_t ix{n} ; ix < LE ; ++ix) {
			ret.m_dc[LF+ix] = dig_t(0);
		}
		return ret;
	}
	/// ARRAYS DE ENTEROS QUE SON DE AYUDA
	static constexpr reg_ints_t<LE+LF> 	regi_0() 				noexcept	{
		reg_ints_t<LE+LF> ret{};
		for(auto& digint : ret) {
			digint = dig_0()();
		}
		return ret;
	}

	static constexpr reg_ints_t<LE+LF>	regi_1() 			noexcept	{
		reg_ints_t<LE+LF> ret{regi_0()};
		ret[LF] = dig_1()();
		return ret;
	}

	static constexpr reg_ints_t<LE+LF>	regi_Bm1() 			noexcept	{
		reg_ints_t<LE+LF> ret{regi_0()};
		ret[LF] = dig_Bm1()();
		return ret;
	}

	static constexpr reg_ints_t<LE+LF>	regi_B() 			noexcept    {
		reg_ints_t<LE+LF> ret{regi_0()};
		ret[LF+1] = dig_1()();
		return ret;
	}

	template<std::int32_t n>
		requires ((n < LE) && (n > -(LF+1)))
	static constexpr reg_ints_t<LE+LF>	regi_pow_n_B()		noexcept	{
		reg_ints_t<LE+LF> ret{regi_0()};
		ret[LF+n] = dig_1()();
		return ret;
	}

	template<std::int32_t n>
		requires ((n < LE) && (n > -(LF+1)))
	static constexpr reg_ints_t<LE+LF>	regi_pow_n_B_m1()	noexcept	{
		reg_ints_t<LE+LF> ret{};
		for(std::int32_t ix{-LF} ; ix < n ; ++ix) {
			ret[LF+ix] = dig_t(B-1)();
		}
		for(std::int32_t ix{n} ; ix < LE ; ++ix) {
			ret[LF+ix] = dig_t(0)();
		}
		return ret;
	}

				/****************************/
				/*													*/
				/*    CONSTRUIR NUMERO			*/
				/*													*/
				/****************************/
public:

	/// CONSTRUCTOR POR DEFECTO
	/// pfx_rat_reg_digs_t<10,3,2>  var();
	/// var == nat#0:0:0:s:0:0#B10
	constexpr inline
	pfx_rat_reg_digs_t()
	noexcept : m_dc{dig_0()} {}
	/// CONSTRUCTOR POR LISTA DE DIGITOS
	/// pfx_rat_reg_digs_t<10,3,2>  var{dig_t(1),dig_t(3),dig_t(2),dig_t(5),dig_t(6)};
	/// var == nat#1:3:2:s:5:6#B10
	constexpr inline
	pfx_rat_reg_digs_t(const std::initializer_list<dig_t> & arg)
	noexcept : m_dc{arg} {}
	/// CONSTRUCTOR POR ARGUMENTOS DIGITOS SIN LIMITE: DEDUCE EL TIPO
	/// pfx_rat_reg_digs_t<10,3,2>  var(dig_t(1),dig_t(3),dig_t(2),dig_t(5),dig_t(6));
	/// var == nat#1:3:2:5:6#B10
	template<typename ... Ts>
		requires (std::is_same_v<Ts,dig_t>&&...)
	constexpr inline
	pfx_rat_reg_digs_t(const Ts &... args)
	noexcept : m_dc{(utility::pack2array<Ts...>{})(args...)} {}
	/// BEGIN : CONSTRUCTOR COPIA/MOVIMIENTO DESDE UN ARRAY DE DIGITOS

	/// FUNCION DELEGADA PARA COPIA DE UN ARRAY DE DISTINTO TAMANO
	/// O TAMANO CUALQUIERA "N"
	/// INTERNO
	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	void copy_arg_N(const base_NEXNF_t<NE,NF> & arg) {
		constexpr int64_t cLE{LE};
		constexpr int64_t cLF{LF};
		constexpr int64_t cNE{NE};
		constexpr int64_t cNF{NF};
		if constexpr (NE<LE) {
			if constexpr (NF<LF) {
				for(std::size_t ix{NE} ; ix < LE ; ++ix)
					m_dc[LF+ix]=dig_0();
				for(std::size_t ix{0} ; ix < LF-NE ; ++ix)
					m_dc[LF+ix]=arg[NF+ix];
			}
			else {
				for(std::size_t ix{NE} ; ix < LE ; ++ix)
					m_dc[LF+ix]=dig_0();
				for(std::size_t ix{0} ; ix < NF-LF ; ++ix)
					m_dc[cLF+ix]=arg[cNF+ix];
			}
		}
		else {
			if constexpr (NF<LF) {
				for(std::size_t ix{LF} ; ix < LE ; ++ix)
					m_dc[NF+ix]=arg[ix];
			}
			else {

			}
		}
	}

	/// FUNCION DELEGADA PARA MOVER DE UN ARRAY DE DISTINTO TAMANO
	/// O TAMANO CUALQUIERA "N"
	/// INTERNO
	template<std::size_t N>
		requires (N>0)
	void move_arg_N(base_N_t<NE,NF>&& arg) {
		if constexpr (N<L) {
			for(std::size_t ix{N} ; ix < L ; ++ix)
				m_dc[ix]=dig_0();
			for(std::size_t ix{0} ; ix < N ; ++ix)
				m_dc[ix]=std::move(arg[ix]);
		}
		else {
			for(std::size_t ix{0} ; ix < L ; ++ix)
				m_dc[ix]=std::move(arg[ix]);
		}
	}
	/// CONSTRUCTOR COPIA REFERENCIA DESDE UN ARRAY DE DIGITOS
	/// INTERNO
	template<std::size_t N>
		requires (N>0)
	constexpr inline
	pfx_rat_reg_digs_t(const base_NExNF_t<NE,NF> & arg)
	noexcept : m_dc{copy_arg_N<N>(arg)} {}
	/// CONSTRUCTOR MOVIMIENTO DESDE UN ARRAY DE DIGITOS
	/// INTERNO
	template<std::size_t N>
		requires (N>0)
	constexpr inline
	pfx_rat_reg_digs_t(const base_NExNF_t<NE,NF> && arg)
	noexcept : m_dc{move_arg_N<N>(arg)} {}
	/// END   : CONSTRUCTOR COPIA/MOVIMIENTO DESDE UN ARRAY DE DIGITOS

	/// FUNCION DE NORMALIZACION A LA BASE B DE UN ARGUMENTOS
	/// EN UN PACK DE ENTEROS CUALQUIERA
	/// INTERNA
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
	/// pfx_rat_reg_digs_t<10,3,2>  var{1,3,2,5,6};
	/// var == nat#1:3:2:s:5:6#B10
	template<type_traits::integral_c ... Ints_type>
	constexpr inline pfx_rat_reg_digs_t(Ints_type ... dig_pow_i) noexcept :
		m_dc{normalize<Ints_type...>(dig_pow_i...)} {}
	/// CONSTRUCTOR COPIA
	/// pfx_rat_reg_digs_t<10,3,2>  var{1,3,2,5,6};
	/// pfx_rat_reg_digs_t<10,3,2>  var2(var);
	template<std::size_t NE, std::size_t NF>
		requires (NE>0)
	constexpr inline pfx_rat_reg_digs_t(const nat_reg_NExNF_digs_t<NE,NF> & arg) noexcept :
		m_dc{copy_arg<NE,NF>(arg.m_dc)} {}
	/// CONSTRUCTOR MOVIMIENTO
	/// pfx_rat_reg_digs_t<10,3,2>  var{1,3,2,5,6};
	/// pfx_rat_reg_digs_t<10,3,2>  var2(std::move(var));
	/// var queda no sabemos su valor
	template<std::size_t NE , std::size_t NF>
		requires (NE>0)
	constexpr inline pfx_rat_reg_digs_t(nat_reg_NExNF_digs_t<NE,NF> && arg) noexcept :
		m_dc{move_arg<NE,NF>(arg.m_dc)} {}

	/// OPERACION ASIGNACION POR COPIA EN LA QUE SE PUEDE COPIAR
	/// reg_N_digs_t == std::array<dig_t,N>;
	/// pfx_rat_reg_digs_t<21,5> var{};
	/// pfx_rat_reg_digs_t       var2{};
	/// var2 = var;
	/// var2 == var
	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline pfx_rat_reg_digs_t & operator = (nat_reg_NExNF_digs_t<NE,NF> & arg) noexcept
	{
		if (this != &arg) {
			copy_arg<NE,NF>(arg.m_dc);
		}
		return (*this);
	}
	/// OPERACION ASIGNACION POR MOVIMIENTO
	/// reg_N_digs_t == std::array<dig_t,N>;
	/// pfx_rat_reg_digs_t<21,5> var{};
	/// pfx_rat_reg_digs_t       var2{};
	/// var2 = std::move(var);
	/// var2 == antigua var; var actual no sabemos su valor;
	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline pfx_rat_reg_digs_t & operator = (nat_reg_NExNF_digs_t<NE,NF> && arg) noexcept
	{
		if (this != &arg) {
			move_arg<NE,NF>(arg.m_dc);
		}
		return (*this);
	}
	/// OPERACION ASIGNACION POR COPIA EN LA QUE  _NO_  SE PUEDE MODIFICAR EL ARGUMENTO
	template<std::size_t NE, std::size_t NF>
		requires (NE>0)
	constexpr inline const pfx_rat_reg_digs_t & operator = (const nat_reg_N_digs_t<NE,NF> & arg)
	noexcept {
		if (this != &arg) {
				copy_arg<NE,NF>(arg.m_dc);
		}
		return (*this);
	}
	/// OPERACION ASIGNACION POR COPIA DESDE BASE_N_T
	template<std::size_t NE, std::size_t NF>
		requires (NE>0)
	constexpr inline pfx_rat_reg_digs_t & operator = (const base_NEXNF_t<NE,NF> & arg) noexcept
	{
		if (&(this->m_dc)!=(&arg))
			copy_arg<NE+NF>(arg);
		return (*this);
	}
	/// OPERACION COPIA DESDE UN DIGITO (CONVERSION)
	/// dig_t<13> a{3};
	/// pfx_rat_reg_digs_t<13,16> A{};
	/// A = a;
	/// A = nat#0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:3#B13
	constexpr inline pfx_rat_reg_digs_t & operator = (const dig_t & arg) noexcept {
		if (&(this->m_dc[LF])!=(&arg)) {
			for (dig_t& dig : m_dc)
				dig = dig_0();
			m_dc[LF] = arg;
		}
		return (*this);
	}
	/// OPERACION COPIA DESDE UN ENTERO (CONVERSION A LA BASE B)
	/// pfx_rat_reg_digs_t<16,4> var{};
	/// var = 1324;
	/// 1324/%16 = 82|12 82/%16 = 5|2 => var == nat#5:2:12#B16
	template<type_traits::integral_c Int_Type>
	constexpr inline pfx_rat_reg_digs_t & operator = (Int_Type arg) noexcept {
		Int_Type creg_g{arg};
		if ((&(this->m_dc()))!=(&arg)) {
			uint128_t BasePowIx{1};
			for(std::size_t k{LF} ; k < LE+LF ; ++k) {
				BasePowIx *= B;
			}
			while (creg_g < 0) {
				creg_g += BasePowIx;
			}
			for(std::size_t k{LF} ; k < LE+LF ; ++k){
				m_dc[k] = dig_t(creg_g);
				creg_g /= B;
			}
			for(std::size_t k{LF-1} ; k >= 0 ; --k)
				m_dc[k]= dig_0();
		}
		return (*this);
	}

	/// FORMACION DE UN REG_M_DIGS_T<M> DESDE EL THIS REG_DIGS_T (L)
	/// Y REG_N_DIGS_T<N> EN SUS DOS FORMAS: (*THIS)SEGUIDO(ARG) Y
	/// (ARG)SEGUIDO(*THIS) : OPERACIONES DE CONCATENACION
	/// A SU VEZ PUEDEN SER POR COPIA Y POR MOVIMIENTO

	/// CONCAT : CONCATENACION
	/// pfx_rat_reg_digs_t<23,7> var1{ 	dig_t(1), dig_t(2), dig_t(3), dig_t(4), dig_t(5),
	///                           	dig_t(6), dig_t(7)                               	}
	/// pfx_rat_reg_digs_t<23,3> var2{ 	dig_t(22), dig_t(21), dig_t(20)										}
	/// var1.concat(var2) == nat#1:2:3:4:5:6:7:22:21:20#B23
	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline
	nat_reg_NExNF_digs_t<LE+NE,LF+NF> concat(const nat_reg_NExNF_digs_t<NE,NF> & arg) const
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		nat_reg_NExNF_digs_t<LE+NE,LF+NF> ret{};
		for(std::size_t ix{0} ; ix < NE+NF ; ++ix) {
			ret[ix] = arg[ix];
		}
		for(std::size_t ix{NE+NF} ; ix < LE+LF+NE+NF ; ++ix) {
			ret[ix] = cthis[ix-NE-NF];
		}
		return ret;
	}

	/// CONCAT : CONCATENACION
	/// pfx_rat_reg_digs_t<23,7> var1{ 	dig_t(1), dig_t(2), dig_t(3), dig_t(4), dig_t(5),
	///                           	dig_t(6), dig_t(7)                               	};
	/// dig_t<23> 					var2{22};
	/// var1.concat(var2) == nat#1:2:3:4:5:6:7:20#B23
	constexpr inline
	reg_N_digs_t<LE+LF+1> concat(const dig_t & arg) const
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		reg_N_digs_t<LE+LF+1> ret{};
		ret[0] = arg;
		for(std::size_t ix{1} ; ix < LE+LF+1 ; ++ix) {
			ret[ix] = cthis[ix-1];
		}
		return ret;
	}

	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline
	nat_reg_NExNF_digs_t<LE+NE,LF+NF> concat_inv(const nat_reg_NExNF_digs_t<NE,NF> & arg) const
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		nat_reg_NExNF_digs_t<LE+NE,LF+NF> ret{};
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix) {
			ret[ix] = cthis[ix];
		}
		for(std::size_t ix{LE+LF} ; ix < NE+NF+LE+LF ; ++ix) {
			ret[ix] = arg[ix-LE-LF];
		}
		return ret;
	}

	constexpr inline
	reg_N_digs_t<LE+LF+1> concat_inv(const dig_t & arg) const
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		reg_N_digs_t<LE+LF+1> ret{};
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix) {
			ret[ix] = cthis[ix];
		}
		ret[LE+LF] = arg;
		return ret;
	}

	template<std::size_t NE, std::size_t NF>
		requires (NE>0)
	constexpr inline
	nat_reg_NExNF_digs_t<LE+NE,LF+NF> concat(nat_reg_NExNF_digs_t<NE,NF> && arg)
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		nat_reg_NExNF_digs_t<LE+NE,LF+NF> ret{};
		for(std::size_t ix{0} ; ix < NE+NF ; ++ix) {
			ret[ix] = std::move(arg[ix]);
		}
		for(std::size_t ix{NE+NF} ; ix < LE+LF+NE+NF ; ++ix) {
			ret[ix] = cthis[ix-NE-NF];
		}
		return ret;
	}

	constexpr inline
	reg_N_digs_t<LE+LF+1> concat(dig_t && arg)
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		reg_N_digs_t<LE+LF+1> ret{};
		ret[0] = std::move(arg);
		for(std::size_t ix{1} ; ix < LE+LF+1 ; ++ix) {
			ret[ix] = cthis[ix-1];
		}
		return ret;
	}
	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline
	nat_reg_NExNF_digs_t<LE+NE,LF+NF> concat_inv(nat_reg_NExNF_digs_t<NE,NF> && arg)
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		nat_reg_NExNF_digs_t<LE+NE,LF+NF> ret{};
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix) {
			ret[ix] = cthis[ix];
		}
		for(std::size_t ix{LE+LF} ; ix < NE+NF+LE+LF ; ++ix) {
			ret[ix] = std::move(arg[ix-LE-LF]);
		}
		return ret;
	}

	constexpr inline
	reg_N_digs_t<LE+LF+1> concat_inv(dig_t && arg)
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		reg_N_digs_t<LE+LF+1> ret{};
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix) {
			ret[ix] = cthis[ix];
		}
		ret[LE+LF] = std::move(arg);
		return ret;
	}

	template<std::size_t ibegin,std::size_t iend>
		requires ((iend-ibegin>0)&&(iend <= LE+LF)&&(ibegin < iend))
	constexpr inline
	reg_N_digs_t<iend-ibegin> subreg_digs() const
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		reg_N_digs_t<iend-ibegin> ret{};
		for(std::size_t ix{ibegin} ; ix < iend ; ++ix) {
			ret[ix-ibegin] = cthis[ix];
		}
		return ret;
	}

	template<std::size_t ibegin,std::size_t iend>
		requires ((iend-ibegin>0)&&(iend <= LE+LF)&&(ibegin < iend))
	constexpr inline
	reg_N_digs_t<iend-ibegin> rev_subreg_digs() const
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		reg_N_digs_t<iend-ibegin> ret{};
		for(std::size_t ix{iend} ; ix > ibegin-1 ; --ix) {
			ret[ix-ibegin] = cthis[LE+LF-1-ix];
		}
		return ret;
	}

	template<std::size_t ibegin,std::size_t iend>
		requires ((iend <= LE+LF)&&(ibegin < iend)&&(ibegin >= LF))
	constexpr inline
	reg_N_digs_t<iend-ibegin> subreg_digs_pe() const
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		reg_N_digs_t<iend-ibegin> ret{};
		for(std::size_t ix{ibegin} ; ix < iend ; ++ix) {
			ret[ix-ibegin] = cthis[ix];
		}
		return ret;
	}

	template<std::size_t ibegin,std::size_t iend>
		requires  ((iend <= LE+LF)&&(ibegin < iend)&&(ibegin >= LF))
	constexpr inline
	reg_N_digs_t<iend-ibegin> rev_subreg_digs_pe() const
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		reg_N_digs_t<iend-ibegin> ret{};
		for(std::size_t ix{iend} ; ix > ibegin-1 ; --ix) {
			ret[ix-ibegin] = cthis[LE+LF-1-ix];
		}
		return ret;
	}

	template<std::size_t ibegin,std::size_t iend>
		requires ((iend < LF)&&(ibegin < iend))
	constexpr inline
	reg_N_digs_t<iend-ibegin> subreg_digs_pf() const
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		reg_N_digs_t<iend-ibegin> ret{};
		for(std::size_t ix{ibegin} ; ix < iend ; ++ix) {
			ret[ix-ibegin] = cthis[ix];
		}
		return ret;
	}

	template<std::size_t ibegin,std::size_t iend>
		requires ((iend < LF)&&(ibegin < iend))
	constexpr inline
	reg_N_digs_t<iend-ibegin> rev_subreg_digs_pf() const
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		reg_N_digs_t<iend-ibegin> ret{};
		for(std::size_t ix{iend} ; ix > ibegin-1 ; --ix) {
			ret[ix-ibegin] = cthis[LF-1-ix];
		}
		return ret;
	}



				/**********************************/
				/*							      						*/
				/*       Algunas Conversiones     */
				/*							      						*/
				/**********************************/

	template<type_traits::integral_c Int_Type>
	constexpr inline Int_Type IntPart() const noexcept {
		std::uint64_t retInt{0};
		std::uint64_t BasePowIx{1};
		for(std::size_t k{LF} ; k < LE+LF ; ++k) {
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

	/// pfx_rat_reg_digs_t<23,12> A;
	/// A = ...
	/// pfx_rat_reg_digs_t<23,10> B;
	/// B = ...
	/// A == B => true or false
	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline
	bool operator == (const nat_reg_NExNF_digs_t<NE,NF>& arg) const
	noexcept {
		if constexpr (NE>LE) {
			for(std::size_t k{LE} ; k < NE ; ++k) {
				if (!(arg[k+NF].is_0())) {
					return false;
				}
			}
		}
		else if constexpr (LE>NE) {
			for(std::size_t k{NE} ; k < LE ; ++k) {
				if (!(m_dc[k+LF].is_0())) {
					return false;
				}
			}
		}
		constexpr auto ZE{std::min(LE,NE)};
		for(std::size_t k{0} ; k < ZE ; ++k) {
				if (m_dc[k+LF]!=arg.m_dc[k+NF])
					return false;
		}
		constexpr auto ZF{std::min(LF,NF)};
		for(std::size_t k{0} ; k < ZF-1 ; ++k) {
				if (m_dc[LF-1-k]!=arg.m_dc[NF-1-k])
					return false;
		}
		if constexpr (NF>LF) {
			for(std::size_t k{LF} ; k < NF ; ++k) {
				if (!(arg[k].is_0())) {
					return false;
				}
			}
		}
		else if constexpr (LF>NF) {
			for(std::size_t k{NF} ; k < LF ; ++k) {
				if (!(m_dc[k].is_0())) {
					return false;
				}
			}
		}
		return true;
	}

	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline
	bool operator == (const pfx_rat_reg_digs_t<NE,NF>& arg) const
	noexcept {
		return ((*this)==arg.m_dc);
	}

	/// pfx_rat_reg_digs_t<23,12> A;
	/// A = ...
	/// pfx_rat_reg_digs_t<23,10> B;
	/// B = ...
	/// A != B => true or false

	template<std::size_t NE , std::size_t NF>
		requires (NE>0)
	constexpr inline
	bool operator != (const nat_reg_NExNF_digs_t<NE,NF>& arg) const
	noexcept {
		if constexpr (LE<NE) {
			for(std::size_t k{LE} ; k < NE ; ++k) {
				if (!(arg[k+NF].is_0())) {
					return true;
				}
			}
		}
		else if constexpr (NE<LE) {
			for(std::size_t k{NE} ; k < LE ; ++k) {
				if (!(m_dc[k+LF].is_0())) {
					return true;
				}
			}
		}

			constexpr auto ZE{std::min(LE,NE)};
			for(std::size_t k{0} ; k < ZE ; ++k) {
				if (m_dc[k+LF]!=arg.m_dc[k+NF]) {
					return true;
				}
			}

			constexpr auto ZF{std::min(LF,NF)};
			for(std::size_t k{0} ; k < ZF ; ++k) {
				if (m_dc[LF-1-k]!=arg.m_dc[NF-1-k]) {
					return true;
				}
			}

		if constexpr (LF<NF) {
			for(std::size_t k{LF-1} ; k < NF ; ++k) {
				if (!(arg[k+NF].is_0())) {
					return true;
				}
			}
		}
		else if constexpr (NF<LF) {
			for(std::size_t k{NF-1} ; k < LF ; ++k) {
				if (!(m_dc[k+LF].is_0())) {
					return true;
				}
			}
		}

		return false;
	}

	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline
	bool operator != (const pfx_rat_reg_digs_t<NE,NF>& arg) const
	noexcept {
		return ((*this)!=arg.m_dc);
	}

	/// pfx_rat_reg_digs_t<23,12> A;
	/// A = ...
	/// pfx_rat_reg_digs_t<23,10> B;
	/// B = ...
	/// A <= B => true or false

	template<std::size_t NE , std::size_t NF>
		requires (NE>0)
	constexpr inline
	bool operator <= (const nat_reg_NExNF_digs_t<NE,NF>& arg) const
	noexcept {
		if constexpr (NE<LE) {
			for(std::size_t k{NE} ; k < LE ; ++k) {
				if (!(arg[k+NF].is_0())) {
					return true;
				}
			}
		}
		else if constexpr (LE<NE) {
			for(std::size_t k{LE} ; k < NE ; ++k) {
				if (!(m_dc[k+LF].is_0())) {
					return false;
				}
			}
		}
		constexpr auto ZE{std::min(LE,NE)};
		for(std::size_t k{0} ; k < ZE ; ++k) {
				if (m_dc[k+NF]<arg.m_dc[k+LF]) {
					return true;
				}
				else if (m_dc[k+NF]>arg.m_dc[k+LF]) {
					return false;
				}
		}
		constexpr auto ZF{std::min(LF,NF)};
		for(std::size_t k{0} ; k < ZF ; ++k) {
				if (m_dc[NF-1-k]<arg.m_dc[LF-1-k]) {
					return true;
				}
				else if (m_dc[NF-1-k]>arg.m_dc[LF-1-k]) {
					return false;
				}
		}
		if constexpr (NF<LF) {
			for(std::size_t k{0} ; k < LF-NF ; ++k) {
				if (!(arg[NF-1-k].is_0())) {
					return true;
				}
			}
		}
		else if constexpr (LF<NF) {
			for(std::size_t k{0} ; k < NF-LF ; ++k) {
				if (!(m_dc[LF-1-k].is_0())) {
					return false;
				}
			}
		}
		return true;
	}

	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline
	bool operator <= (const pfx_rat_reg_digs_t<NE,NF>& arg) const
	noexcept {
		return ((*this)<=arg.m_dc);
	}

	/// pfx_rat_reg_digs_t<23,12> A;
	/// A = ...
	/// pfx_rat_reg_digs_t<23,10> B;
	/// B = ...
	/// A >= B => true or false

	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline
	bool operator >= (const nat_reg_NExNF_digs_t<NE,NF>& arg) const
	noexcept {
		if constexpr (NE>LE) {
			for(std::size_t k{LE} ; k < NE ; ++k) {
				if (!(arg[k+NF].is_0())) {
					return false;
				}
			}
		}
		else if constexpr (LE>NE) {
			for(std::size_t k{NE} ; k < LE ; ++k) {
				if (!(m_dc[k+LF].is_0())) {
					return true;
				}
			}
		}
		constexpr auto ZE{std::min(LE,NE)};
		for(std::int64_t k{ZE-1} ; k > -1 ; --k) {
				if (m_dc[k+LF]>arg.m_dc[k+NF]) {
					return true;
				}
				else if (m_dc[k+LF]<arg.m_dc[k+NF]) {
					return false;
				}
		}
		constexpr auto ZF{std::min(LF,NF)};
		for(std::int64_t k{ZF-1} ; k > -1 ; --k) {
				if (m_dc[LF-1-k]>arg.m_dc[NF-1-k]) {
					return true;
				}
				else if (m_dc[LF-1-k]<arg.m_dc[NF-1-k]) {
					return false;
				}
		}
		if constexpr (LF<NF) {
			for(std::size_t k{0} ; k < NF-LF ; ++k) {
				if (!(arg[NF-1-k].is_0())) {
					return false;
				}
			}
		}
		else if constexpr (NF<LF) {
			for(std::size_t k{0} ; k < LF-NF ; ++k) {
				if (!(m_dc[LF-1-k].is_0())) {
					return true;
				}
			}
		}
		return true;
	}

	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline
	bool operator >= (const pfx_rat_reg_digs_t<NE,NF>& arg) const
	noexcept {
		return ((*this)>=arg.m_dc);
	}

	/// pfx_rat_reg_digs_t<23,12> A;
	/// A = ...
	/// pfx_rat_reg_digs_t<23,10> B;
	/// B = ...
	/// A < B => true or false

	template<std::size_t NE , std::size_t NF>
		requires (NE>0)
	constexpr inline
	bool operator < (const nat_reg_NExNF_digs_t<NE,NF>& arg) const
	noexcept {
		if constexpr (NE<LE) {
			for(std::size_t k{NE} ; k < LE ; ++k) {
				if (!(arg[k+NF].is_0())) {
					return true;
				}
			}
		}
		else if constexpr (LE<NE) {
			for(std::size_t k{LE} ; k < NE ; ++k) {
				if (!(m_dc[k+LF].is_0())) {
					return false;
				}
			}
		}
		constexpr auto ZE{std::min(LE,NE)};
		for(std::size_t k{0} ; k < ZE ; ++k) {
				if (m_dc[k+NF]<arg.m_dc[k+LF]) {
					return true;
				}
				else if (m_dc[k+NF]>arg.m_dc[k+LF]) {
					return false;
				}
		}
		constexpr auto ZF{std::min(LF,NF)};
		for(std::size_t k{0} ; k < ZF ; ++k) {
				if (m_dc[NF-1-k]<arg.m_dc[LF-1-k]) {
					return true;
				}
				else if (m_dc[NF-1-k]>arg.m_dc[LF-1-k]) {
					return false;
				}
		}
		if constexpr (NF<LF) {
			for(std::size_t k{0} ; k < LF-NF ; ++k) {
				if (!(arg[NF-1-k].is_0())) {
					return true;
				}
			}
		}
		else if constexpr (LF<NF) {
			for(std::size_t k{0} ; k < NF-LF ; ++k) {
				if (!(m_dc[LF-1-k].is_0())) {
					return false;
				}
			}
		}
		return false;
	}

	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline
	bool operator < (const pfx_rat_reg_digs_t<NE,NF>& arg) const
	noexcept {
		return ((*this)<arg.m_dc);
	}

	/// pfx_rat_reg_digs_t<23,12> A;
	/// A = ...
	/// pfx_rat_reg_digs_t<23,10> B;
	/// B = ...
	/// A > B => true or false

	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline
	bool operator > (const nat_reg_NExNF_digs_t<NE,NF>& arg) const
	noexcept {
		if constexpr (NE>LE) {
			for(std::size_t k{LE} ; k < NE ; ++k) {
				if (!(arg[k+NF].is_0())) {
					return false;
				}
			}
		}
		else if constexpr (LE>NE) {
			for(std::size_t k{NE} ; k < LE ; ++k) {
				if (!(m_dc[k+LF].is_0())) {
					return true;
				}
			}
		}
		constexpr auto ZE{std::min(LE,NE)};
		for(std::int64_t k{ZE-1} ; k > -1 ; --k) {
				if (m_dc[k+LF]>arg.m_dc[k+NF]) {
					return true;
				}
				else if (m_dc[k+LF]<arg.m_dc[k+NF]) {
					return false;
				}
		}
		constexpr auto ZF{std::min(LF,NF)};
		for(std::int64_t k{ZF-1} ; k > -1 ; --k) {
				if (m_dc[LF-1-k]>arg.m_dc[NF-1-k]) {
					return true;
				}
				else if (m_dc[LF-1-k]<arg.m_dc[NF-1-k]) {
					return false;
				}
		}
		if constexpr (LF<NF) {
			for(std::size_t k{0} ; k < NF-LF ; ++k) {
				if (!(arg[NF-1-k].is_0())) {
					return false;
				}
			}
		}
		else if constexpr (NF<LF) {
			for(std::size_t k{0} ; k < LF-NF ; ++k) {
				if (!(m_dc[LF-1-k].is_0())) {
					return true;
				}
			}
		}
		return false;
	}

	/// CONSTRUCTOR COMPARACION OPERADOR SPACESHIP C++20
	/// Comparaciones con un array estandar de otra longitud
	/// La salida devuelta es greater,less,equivalent
	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline
	std::weak_ordering operator <=> (const nat_reg_NExNF_digs_t<NE,NF>& arg) const
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		if (cthis > arg)
			return std::weak_ordering::greater;
		else if (cthis < arg)
			return std::weak_ordering::less;
		else
			return std::weak_ordering::equivalent;
	}

	template<std::size_t NE,std::size_t NF>
		requires (NE>0)
	constexpr inline
	std::strong_ordering operator <=> (const pfx_rat_reg_digs_t<NE,NF> & arg) const
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		if (cthis > arg)
			return std::strong_ordering::greater;
		else if (cthis < arg)
			return std::strong_ordering::less;
		else
			return std::strong_ordering::equal;
	}

				/************************************/
				/*							  									*/
				/* 		  PRIMER DIGITO DESDE MSB			*/
				/*		  SEGUNDO DIGITO							*/
				/*							   									*/
				/************************************/

	/// pfx_rat_reg_digs_t A{};
	/// I en [LE-1,-LF]
	/// A.get<LE-1>() [devuelve el digito de peso B^(LE-1)]
	/// ..........
	/// A.get<2>() [devuelve el digito de peso B^2]
	/// A.get<1>() [devuelve el digito de peso B^1]
	/// A.get<0>() [devuelve el digito de peso (B^0)==1]
	/// A.get<-1>() [devuelve el digito de peso B^-1]
	/// A.get<-2>() [devuelve el digito de peso B^-2]
	/// ...........
	/// A.get<-LF>() [devuelve el digito de peso B^-LF]
	/// MSB == MSB_E == LE-1  LSB_E == LF  MSB_F == LF-1  LSB_F == 0 == LSB
	template<std::int32_t I>
		requires ((I < LE)&&(std::abs(I) < LF+1))
	inline constexpr const dig_t& get() const noexcept {
		return (m_dc[I+LF]);
	}

	/// pfx_rat_reg_digs_t A{};
	/// A.put<2>(B-1-A.get<2>()) [pone un valor en un digito por su indice]
	template<std::int32_t I>
		requires ((I < LE)&&(std::abs(I) < LF+1))
	inline constexpr void put(const dig_t & arg) noexcept {
		m_dc[I+LF] = arg; return;
	}

	template<std::int32_t I>
		requires ((I < LE)&&(std::abs(I) < LF+1))
	inline constexpr void put(dig_t && arg) noexcept {
		m_dc[I+LF] = std::move(arg); return;
	}

	inline constexpr const dig_t & operator[](std::int32_t idx) const noexcept {
		if ((idx < LE)&&(std::abs(idx) < LF+1))
			return (m_dc[idx+LF]);
		else
			return dig_0();
	}

	inline constexpr dig_t & operator[](std::int32_t idx) noexcept {
		if ((idx < LE)&&(std::abs(idx) < LF+1))
			return (m_dc[idx+LF]);
		else
			return dig_0();
	}

	inline constexpr UINT_T operator()(std::int32_t idx) const noexcept {
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
	const pfx_rat_reg_digs_t & operator ++ ()
	noexcept {
		pfx_rat_reg_digs_t& cthis(*this);
		/// CARRY INICIAL ES 1
		dig_t carry{dig_1()};
		/// BUCLE FOR QUE SUMA CTHIS Y 1 DESDE IDX=0 A IDX=L-1
		for(std::size_t ix{0} ; ix < LE+LF-1 ; ++ix) {
			if ((m_dc[ix]==dig_Bm1())&&(carry == dig_1())) {
				m_dc[ix]=dig_0();
				carry = dig_1();
			}
			else if ((cthis.m_dc[ix]<dig_Bm1())&&(carry == dig_1())){
				if (carry != dig_0()) {
					++m_dc[ix];
					break;
				}
			}
		}
		return cthis;
	}

	constexpr inline
	pfx_rat_reg_digs_t operator ++ (int)
	noexcept {
		pfx_rat_reg_digs_t cpthis(*this);
		++(*this);
		return cpthis;
	}

	constexpr inline
	const pfx_rat_reg_digs_t & operator -- ()
	noexcept {
		pfx_rat_reg_digs_t& cthis(*this);
		/// CARRY INICIAL ES EL COMPLEMENTO A LA BASE DE 1
		dig_t carry{dig_0()};
		/// BUCLE FOR QUE SUMA CTHIS Y C_B(1) DESDE IDX=0 A IDX=LE+LF-1
		for(std::size_t ix{0} ; ix < LE+LF-1 ; ++ix) {
				SIG_UINT_T temp{cthis(ix)+B-1+carry()};
				m_dc[ix]=dig_t(temp);
				carry = dig_t(temp/B);
		}
		return cthis;
	}

	constexpr inline
	pfx_rat_reg_digs_t operator -- (int)
	noexcept {
		pfx_rat_reg_digs_t cpthis(*this);
		--(*this);
		return cpthis;
	}

								/****************************/
								/*													*/
								/* OPERADORES ARITMETICOS		*/
								/*	 C_B()  C_Bm1()  				*/
								/*	mC_B() mC_Bm1()		      */
								/*	operator-() operator!() */
								/*                          */
								/****************************/

	constexpr inline
	const pfx_rat_reg_digs_t & mC_Bm1()
	noexcept {
		pfx_rat_reg_digs_t& cthis(*this);
		for(std::size_t ix{0} ; ix < LE+LF-1 ; ++ix) {
				m_dc[ix] = !m_dc[ix];
		}
		return cthis;
	}

	constexpr inline
	const pfx_rat_reg_digs_t & mC_B()
	noexcept {
		pfx_rat_reg_digs_t& cthis(*this);
		cthis.mC_Bm1();
		dig_t carry{dig_1()};
		/// BUCLE FOR QUE SUMA CTHIS Y 1 DESDE IDX=0 A IDX=L-1
		for(std::size_t ix{0} ; ix < LE+LF-1 ; ++ix) {
			if ((m_dc[ix]==dig_Bm1())&&(carry != dig_1())) {
				m_dc[ix]=dig_0();
				carry = dig_1();
			}
			else if (carry == dig_1()){
				++m_dc[ix];
				break;
			}
		}
		return (cthis);
	}

	constexpr inline
	pfx_rat_reg_digs_t C_Bm1() const
	noexcept
	{
		pfx_rat_reg_digs_t cpthis(*this);
		cpthis.mC_Bm1();
		return cpthis;
	}

	constexpr inline
	pfx_rat_reg_digs_t C_B() const
	noexcept {
		pfx_rat_reg_digs_t cpthis(*this);
		cpthis.mC_B();
		return cpthis;
	}

	constexpr inline
	pfx_rat_reg_digs_t operator ! () const
	noexcept {
		pfx_rat_reg_digs_t cpthis(*this);
		cpthis.mC_Bm1();
		return cpthis;
	}

	constexpr inline
	pfx_rat_reg_digs_t operator - () const
	noexcept {
		pfx_rat_reg_digs_t cpthis(*this);
		cpthis.mC_B();
		return cpthis;
	}

					/***********************************/
					/* OPERADORES ARITMETICOS BASICOS	 */
					/*			pfx_rat_reg_digs_t	@  dig_t			 */
					/*      pfx_rat_reg_digs_t	@= dig_t       */
					/*      pfx_rat_reg_digs_t  @  10B^n       */
					/*      pfx_rat_reg_digs_t  @= 10B^n       */
					/***********************************/

					/************************************/
					/*								   								*/
					/*  ARITMETICOS CON ASIGNACION			*/
					/*			 pfx_rat_reg_digs_t @= dig_t				*/
					/*                                  */
					/************************************/

	constexpr inline
	const pfx_rat_reg_digs_t & operator += (dig_t arg)
	noexcept {
		pfx_rat_reg_digs_t& cthis(*this);
		/// CARRY INICIAL ES 1
		dig_t carry{arg};
		/// CASOS CARRY==0[ULTIMA], CARRY==1[VECES SIGUIENTES], CARRY=ARG [1A VEZ]
		/// SI ARG == 0 ENTONCES SE DEVUELVE SIN MÁS
		/// SI ARG == 1 ENTONCES ++CTHIS
		/// SI ARG >  1 ENTONCES 1a VEZ dig_BmArg
		///                      2a VEZ dig_Bm1   Y SIGUIENTES
		///                             ULTIMA VEZ CARRY ==0
		if (arg.is_0()) {
			return (cthis);
		} else if (arg.is_1()) {
			return (++cthis);
		} else {
			const dig_t dig_BmArg{dig_Bm1()-(arg-dig_1())};
			/// PRIMERA VEZ : ARG > 1 usamos dig_BmArg
			if (m_dc[0]==dig_BmArg) {
				m_dc[0] = dig_0();
				carry    = dig_1();
			}
			/// SEGUNDA VEZ Y SIGUIENTES
			/// BUCLE FOR QUE SUMA CTHIS Y 1 DESDE IDX=0 A IDX=L-1
			for(std::size_t ix{1} ; ix < LE+LF-1 ; ++ix) {
				if (m_dc[ix]==dig_Bm1()&& !(carry.is_0())) {
					m_dc[ix]=dig_0();
					carry = dig_1();
				}
				else if ((m_dc[ix]<dig_Bm1())&&(carry == dig_1())){
					if (carry != dig_0()) {
						++m_dc[ix];
						break;
					}
				}
			}
			return (cthis);
		}
	}

	constexpr inline
	const pfx_rat_reg_digs_t & operator -= (dig_t arg)
	noexcept {
		pfx_rat_reg_digs_t& cthis(*this);
		/// CARRY INICIAL ES 1
		dig_t carry{arg};
		/// CASOS CARRY==0[ULTIMA], CARRY==1[VECES SIGUIENTES], CARRY=ARG [1A VEZ]
		/// SI ARG == 0 ENTONCES SE DEVUELVE SIN MÁS
		/// SI ARG == 1 ENTONCES --CTHIS
		/// SI ARG >  1 ENTONCES 1a VEZ dig_BmArg
		///                      2a VEZ dig_Bm1   Y SIGUIENTES
		///                             ULTIMA VEZ CARRY ==0
		if (arg==dig_0()) {
			return (cthis);
		} else if (arg == dig_1()) {
			return (--cthis);
		} else {
			const dig_t dig_CBArg{arg.C_B()};
			const dig_t dig_sig_Arg{dig_Bm1()};

			/// PRIMERA VEZ : SUMAMOS EL COMPLEMENTO A LA BASE DE ARG
			if (m_dc[0]())+dig_CBArg()>dig_Bm1()()) {
				carry = dig_1();
			} else {
				carry = dig_0();
			}
			m_dc[0] += dig_CBArg;

			/// SEGUNDA VEZ Y SIGUIENTES
			/// BUCLE FOR QUE SUMA CTHIS Y 1 DESDE IDX=0 A IDX=L-1
			for(std::size_t ix{1} ; ix < LE+LF-1 ; ++ix) {
				if (m_dc[ix].is_0() && carry.is_0()) {
					m_dc[ix]=dig_Bm1();
					carry = dig_0();
				}
				else if (m_dc[ix].is_0() && !carry.is_0()) {
					m_dc[ix]=dig_0();
					carry = dig_1();
				}
				else if (m_dc[ix].is_1() && carry.is_0()) {
					m_dc[ix]=dig_0();
					carry = dig_1();
				}
				else {
					m_dc[ix] += dig_Bm1();
					m_dc[ix] += carry;
					carry = dig_1();
				}
			}
			return (cthis);
		}
	}

	/// OPERACIONES '@'(REG_DIGS_T,DIG_T)->STD::ARRAY<REG_DIGS_T,2>
	/// '@' = MULT
	constexpr inline
	std::array<pfx_rat_reg_digs_t,2> mult(dig_t arg) const
	noexcept {
		pfx_rat_reg_digs_t cpthis(*this);
		std::array<pfx_rat_reg_digs_t,2> ret{};
		if (arg.is_0()) {
			for (auto& elem : ret[0].m_dc)
				elem = dig_0();
			for (auto& elem : ret[1].m_dc)
				elem = dig_0();
			return ret;
		}
		else if (arg.is_1()) {
			ret[0] = cpthis;
			for (auto& elem : ret[1].m_dc)
				elem = dig_0();
			return ret;
		}
		else {
			dig_t carry{dig_0()};
			for(std::size_t ix{0} ; ix < LE+LF ; ++ix){
				const auto res = m_dc[ix].mult(arg);
				const auto uds = res[0].add(carry);
				ret[0].m_dc[ix] = m_dc[ix] = uds[0] + carry;
				carry = res[1] + uds[1];
			}
			ret[1].m_dc[0]=carry;
			return ret;
		}
	}
//
//	///< TO DO REVISAR
//	/// '@' = EUCLID_DIV -> (REM,COC)
//	std::array<pfx_rat_reg_digs_t,2> full_euclid_div(dig_t dsor) {
//		const pfx_rat_reg_digs_t & dndo{*this};
//		std::array<pfx_rat_reg_digs_t,2> ret{};
//						if (dsor == dig_0()) {
//				return ret;
//		}
//		else 	if (dsor == dig_1()) {
//			ret[0] = dndo;
//			ret[1] = regd_0();
//			return ret;
//		}
//		else 	if (dndo < regd_B()) {
//			ret[0] = dndo[0] / dsor;
//			ret[1] = dndo[0] % dsor;
//			return ret;
//		}
//		else {
//			pfx_rat_reg_digs_t& coc{ret[0]};
//			pfx_rat_reg_digs_t& rem{ret[1]};
//			for(std::int64_t lx{L-1} ; lx > -1 ; --lx) {
//				if (dndo[lx]>=dsor) {
//					coc << 1;
//					coc[0] = dndo[lx]/dsor;
//					rem[0] = dndo[lx]%dsor;
//					rem << 1;
//					rem[0] = dndo[lx-1];
//				}
//				else {
//					rem << 1;
//					rem[0] = dndo[lx-1];
//					for (UINT_T int_coc{0}; int_coc < B ; ++int_coc) {
//						auto X{dig_t(int_coc).mult(dsor)};
//						reg_N_digs_t<2> prod{X[1],X[0]};
//						if (prod >= rem) {
//							rem -= prod;
//							rem << 1;
//							rem[0] = dndo[lx-2];
//							coc << 1;
//							coc[0] = dig_t(int_coc);
//							break;
//						}
//					}
//				}
//			}
//			return ret;
//		}
//	}

	/// '@' = '+'
	constexpr inline
	std::array<pfx_rat_reg_digs_t,2> add(dig_t arg) const
	noexcept {
		const pfx_rat_reg_digs_t& cthis{*this};
		std::array<pfx_rat_reg_digs_t,2> result{dig_0(),cthis};
		dig_t carry{dig_0()};
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix) {
			auto 	temp_result   =      result[0].m_dc[ix].add(arg);
			auto  temp_result_2 = temp_result[0].m_dc[ix].add(carry);
			result[0].m_dc[ix] = temp_result_2[0];
			result[1].m_dc[ix]  = temp_result_2[1];
			carry = result[1].m_dc[0];
		}
		for(std::size_t ix{1} ; ix < LE+LF ; ++ix) {
			result[1].m_dc[ix] = dig_0();
		}
		return result;
	}

	/// TO DO REPASAR
	/// '@' = '-'
	constexpr inline
	std::array<pfx_rat_reg_digs_t,2> subst(dig_t arg) const
	noexcept {
		const pfx_rat_reg_digs_t& cthis{*this};
		std::array<pfx_rat_reg_digs_t,2> result{dig_0(),cthis};
		pfx_rat_reg_digs_t cb_arg{-arg};
		if (!(arg.is_0())) {
			for(std::size_t ix{1} ; ix < L ; ++ix) {
				cb_arg.m_dc[ix] = dig_Bm1();
			}
		}
		dig_t carry{dig_0()};
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix) {
			auto 	temp_result   =      result[0].m_dc[ix].add(cb_arg[ix]);
			auto  temp_result_2 =      temp_result[0].add(carry);
			result[0].m_dc[ix]  = temp_result_2[0];
			result[1].m_dc[ix]  = (temp_result_2[1].add(temp_result_2[1]))[0];
			carry = result[1].m_dc[ix];
		}
		return result;
	}


				/********************************/
				/*							 								*/
				/*    OPERADORES ARITMETICOS		*/
				/*			 pfx_rat_reg_digs_t @ dig_t	*/
				/* 															*/
				/********************************/

	constexpr inline
	auto operator + (dig_t arg) const
	noexcept {
		pfx_rat_reg_digs_t ret(*this);
		ret += arg;
		return ret;
	}

	constexpr inline
	auto operator - (dig_t arg) const
	noexcept {
		pfx_rat_reg_digs_t ret(*this);
		ret -= arg;
		return ret;
	}

	constexpr inline
	auto operator * (dig_t arg) const
	noexcept {
		pfx_rat_reg_digs_t ret(*this);
		ret *= arg;
		return ret;
	}

//		/// "ARITHMETIC OPERATOR" : COMPLETE EUCLIDEAN DIVISION BY A DIGIT
//		constexpr inline
//		std::array<pfx_rat_reg_digs_t,2> euclid_div (dig_t arg) const
//		noexcept {
//			const pfx_rat_reg_digs_t& dndo{*this};
//			const dig_t&      dsor{arg};
//			const pfx_rat_reg_digs_t<UINT_T,B,2> tmp_dsor{dig_0(),arg};
//						pfx_rat_reg_digs_t<UINT_T,B,2> part_rem{dig_0(),dndo[L-1]};
//						pfx_rat_reg_digs_t rem{regd_0()};
//						pfx_rat_reg_digs_t coc{regd_0()};
//			if (dsor == dig_0()) {
//				std::array<pfx_rat_reg_digs_t,2> rem_coc{regd_0(),regd_0()};
//				return rem_coc;/// ERROR DIVISION BY 0
//			}
//			else if (dsor == dig_1()) {
//				std::array<pfx_rat_reg_digs_t,2> rem_coc{regd_0(),(*this)};
//				return rem_coc;
//			}
//			else if ((dndo == regd_0())||(dndo == regd_1())) {
//				std::array<pfx_rat_reg_digs_t,2> rem_coc{(*this),regd_0()};
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
//				pfx_rat_reg_digs_t<UINT_T,B,2> tmp_dsor{dig_0(),arg};
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
//				std::array<pfx_rat_reg_digs_t,2> rem_coc{std::make_pair(rem,coc)};
//				return rem_coc;
//			}
//		}
//		/// DIVISION BY A DIGIT
//		constexpr inline
//		pfx_rat_reg_digs_t operator / (dig_t arg) const
//		noexcept {
//			return (this->euclid_div(arg))[0];
//		}
//		/// REMAINDER BY A DIGIT
//		constexpr inline
//		pfx_rat_reg_digs_t operator % (dig_t arg) const
//		noexcept {
//			return (this->euclid_div(arg))[1];
//		}
	/// BEGIN : OPERATORS >> >>= << <<=
	/// MULTIPLY BY THE BASE B (10)
	constexpr inline
	pfx_rat_reg_digs_t operator << (std::size_t n) const
	noexcept {
		if (n<LE+LF) {
			pfx_rat_reg_digs_t cpthis{*this};
			for(std::int64_t ix{n-1} ; ix > -1 ; --ix) {
				cpthis.m_dc[ix+n] = cpthis.m_dc[ix];
				cpthis.m_dc[ix] = dig_0();
			}
			return cpthis;
		}
		else
			return (pfx_rat_reg_digs_t{});
	}

	constexpr inline
	const pfx_rat_reg_digs_t & operator <<= (std::size_t n)
	noexcept {
		pfx_rat_reg_digs_t& cthis{*this};
		if (n < LE+LF) {
			for(std::int64_t ix{n-1} ; ix > -1 ; --ix) {
				cthis.m_dc[ix+n] = cthis.m_dc[ix];
				cthis.m_dc[ix] = dig_0();
			}
		}
		else {
			cthis = (pfx_rat_reg_digs_t{});
		}
		return (*this);
	}

	/// DIVIDE BY THE BASE B (/10_B)
	constexpr inline
	pfx_rat_reg_digs_t operator >> (std::size_t n) const
	noexcept {
		if (n<LE+LF) {
			pfx_rat_reg_digs_t cpthis{*this};
			for(std::int64_t ix{0} ; ix < n ; ++ix) {
				cpthis.m_dc[ix] = cpthis.m_dc[ix+n];
				cpthis.m_dc[ix+n] = dig_0();
			}
			return cpthis;
		}
		else
		return (pfx_rat_reg_digs_t{});
	}

	constexpr inline
	const pfx_rat_reg_digs_t & operator >>= (std::size_t n)
	noexcept {
		pfx_rat_reg_digs_t& cthis{*this};
		if (n < LE+LF) {
			for(std::int64_t ix{0} ; ix < n ; ++ix) {
				cthis.m_dc[ix] = cthis.m_dc[ix+n];
				cthis.m_dc[ix+n] = dig_0();
			}
		}
		else
			cthis = (pfx_rat_reg_digs_t{});
		return (*this);
	}

	/// END   : OPERATORS >> >>= << <<=

	/// BEGIN : "OPERATORS" REM_B^n AND M_REM_B^n
	/// REMAINDER BY THE BASE B (%10_B)
	constexpr inline
	pfx_rat_reg_digs_t rem_B(std::size_t n) const
	noexcept {
		pfx_rat_reg_digs_t ret{regd_0()};
		if (n < LE+LF) {
			for(std::size_t ix{0} ; ix < n ; ++ix) {
				ret.m_dc[ix] = m_dc[ix];
			}
		}
		return ret;
	}

	constexpr inline
	const pfx_rat_reg_digs_t & m_rem_B(std::size_t n)
	noexcept {
		if (n < LE+LF) {
			for(std::size_t ix{n} ; ix < LE+LF ; ++ix) {
				m_dc[ix] = dig_0();
			}
		}
		else {
			for(std::size_t ix{0} ; ix < LE+LF ; ++ix) {
				m_dc[ix] = dig_0();
			}
		}
		return (*this);
	}
	/// REMAINDER BY THE BASE B (%10_B)
	/// END   : "OPERATORS" REM_B^n AND M_REM_B^n

	/// BEGIN : OPERATORS | & |= &=
	constexpr inline
	const pfx_rat_reg_digs_t & operator |= (const pfx_rat_reg_digs_t & arg)
	noexcept {
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix) {
			m_dc[ix] |= arg.m_dc[ix];
		}
		return (*this);
	}

	constexpr inline
	pfx_rat_reg_digs_t operator | (const pfx_rat_reg_digs_t & arg)
	noexcept {
		pfx_rat_reg_digs_t ret{*this};
		ret |= arg;
		return ret;
	}

	constexpr inline
	const pfx_rat_reg_digs_t & operator &= (const pfx_rat_reg_digs_t & arg)
	noexcept {
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix) {
			m_dc[ix] &= arg.m_dc[ix];
		}
		return (*this);
	}

	constexpr inline
	pfx_rat_reg_digs_t operator & (const pfx_rat_reg_digs_t & arg)
	noexcept {
		pfx_rat_reg_digs_t ret{*this};
		ret &= arg;
		return ret;
	}

	/// END   : OPERATORS | & |= &=

								/***********************************/
								/*													  		 */
								/* OPERADORES ARITMETICOS		  		 */
								/* pfx_rat_reg_digs_t @ pfx_rat_reg_digs_t */
								/*                            		 */
								/***********************************/

	constexpr inline
	std::pair<dig_t,pfx_rat_reg_digs_t> operator + (const pfx_rat_reg_digs_t & arg) const
	noexcept {
		pfx_rat_reg_digs_t ret(*this);
		/// CARRY INICIAL ES 0
		UINT_T carry{0};
		/// INT_ARRAY TEMPORAL COPIA DE (*THIS) [SUMANDO 0]
		reg_ints_t<LE+LF> retints{};
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix){
			retints[ix] = ret(ix);
		}
		/// INT_ARRAY TEMPORAL COPIA DE ARG  [SUMANDO 1]
		reg_ints_t<LE+LF> argints{};
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix){
			argints[ix] = arg(ix);
		}
		/// BUCLE FOR QUE SUMA RETINTS Y ARGINTS DESDE IDX=0 A IDX=L-1
		for(std::size_t ix{0} ; ix < LE+LF-1 ; ++ix) {
			retints[ix] += (argints[ix]+carry);
			carry = retints[ix]/B;
			ret.m_dc[ix] = dig_t(retints[ix]);
		}
		/// GUARDAMOS EL CARRY FINAL Y RETORNAMOS LA SUMA
		auto retpair = std::make_pair(dig_t(carry),ret);
		return ret;
	}

	constexpr inline
	std::pair<dig_t,pfx_rat_reg_digs_t> operator - (const pfx_rat_reg_digs_t & arg) const
	noexcept {
		pfx_rat_reg_digs_t ret(*this);
		/// INICIALIZAMOS EL CARRY/BORROW A 0
		UINT_T carry_CB{1};
		UINT_T carry_add{0};

		reg_ints_t<LE+LF> retints{};
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix){
			retints[ix] = ret(ix);
		}

		reg_ints_t<LE+LF> argints{};
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix){
			/// GUARDAMOS EL COMPLEMENTO A LA BASE MENOS 1 DEL MINUENDO
			argints[ix] = (B-1)-arg(ix);
		}
		/// COMPLETAMOS EL COMPLEMENTO A LA BASE SUMANDO 1
		/// [carry_CB vale en el inicio 1]
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix){
				argints[ix] = argints[ix]+carry_CB;
				carry_CB = argints[ix]/B;
		}
		/// SE HA COMPLETADO EL COMPLEMENTO A LA BASE

		/// SUMAMOS SUMANDO_0 + C_B(SUMANDO_1)
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix) {
			retints[ix] += (argints[ix]+carry_add);
			carry_add = retints[ix]/B;
			ret.m_dc[ix] = dig_t(retints[ix]);
		}
		auto pairret = std::make_pair(dig_t(carry_add),ret);
		return pairret;
	}

	constexpr inline
	std::array<pfx_rat_reg_digs_t,2> operator* (const pfx_rat_reg_digs_t & arg) const
	noexcept {
		const pfx_rat_reg_digs_t & cthis{*this};
		/// BEGIN : DECLARACIONES E INICIALIZACIONES
		reg_ints_t<LE+LF> actints{};
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix){
			actints[ix] = cthis(ix);
		}
		reg_ints_t<LE+LF> argints{};
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix){
			argints[ix] = arg(ix);
		}
		reg_ints_t<2*(LE+LF)> carryints{};
		for(std::size_t iy{0} ; iy < 2*(LE+LF) ; ++iy) {
			carryints[iy]=0;
		}
		std::array<reg_suints_t<2*(LE+LF)>,LE+LF> retints{};
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix) {
			for(std::size_t iy{0} ; iy < 2*(LE+LF) ; ++iy) {
				retints[ix][iy]   =		0;
			}
		}
		/// END   : DECLARACIONES E INICIALIZACIONES

		/// BEGIN : OBTENEMOS TODOS LOS SUMANDOS MULTIPLICANDO POR UN DIGITO FIJO
		///         COLOCADOS CONVENIENTEMENTE
		for(std::size_t ix{0} ; ix < LE+LF ; ++ix) {
			for(std::size_t iy{0} ; ix+iy < 2*(LE+LF) ; ++iy) {
				retints[ix][ix+iy]   	=		(	static_cast<SIG_UINT_T>(actints[ix])	*
																		static_cast<SIG_UINT_T>(argints[iy])	 )+
																		static_cast<SIG_UINT_T>(carryints[iy]);
				carryints[iy] 				= 	retints[ix][ix+iy]/B;
				retints[ix][ix+iy]   %=		B;
			}
		}
		///         COLOCADOS CONVENIENTEMENTE
		/// END   : OBTENEMOS TODOS LOS SUMANDOS MULTIPLICANDO POR UN DIGITO FIJO

		/// BEGIN : SUMAMOS TODOS LOS SUMANDOS
		std::array<pfx_rat_reg_digs_t,LE+LF> rets{};
		for(std::size_t iz{0} ; iz < LE+LF ; ++iz) {
				rets.m_dc[iz] = pfx_rat_reg_digs_t(retints[iz]);
		}
		for(std::size_t iw{1} ; iw < LE+LF ; ++iw) {
				rets.m_dc[0] += rets.m_dc[iw];
				// no hace falta que la suma sea de tamano L+1
		}
		/// END   : SUMAMOS TODOS LOS SUMANDOS
		/// BEGIN : PREPARAMOS EL PAR DE RETORNO
		std::array<pfx_rat_reg_digs_t,2> retpair{};
		for(std::size_t ix{0} ; ix < 2*LF ; ++ix) {
				retpair[0].m_dc[ix] = rets[0].m_dc[ix];
		}
		for(std::size_t ix{2*LF} ; ix < 2*(LE+LF) ; ++ix) {
				retpair[1].m_dc[ix-2*LF] = rets[0].m_dc[ix];
		}
		/// END   : PREPARAMOS EL PAR DE RETORNO
		return retpair;
	}

	constexpr inline static
	std::size_t cuenta_0s_desde_IZDA(const reg_ints_t<LE+LF>& arg)
	noexcept {
		std::size_t ret{0};
		for(std::int64_t ix{LE+LF-1} ; ix > -1 ; --ix) {
			if (arg[ix]==0) {
				++ret;
			}
			else {
				return ret;
			}
		}
		return LE+LF;
	}

	constexpr inline static
	std::size_t cuenta_0s_desde_DRCHA(const reg_ints_t<LE+LF>& arg)
	noexcept {
		std::size_t ret{0};
		for(std::int64_t ix{0} ; ix < LE+LF ; ++ix) {
			if (arg[ix]==0) {
				++ret;
			}
			else {
				return ret;
			}
		}
		return LE+LF;
	}

//		constexpr inline
//		pfx_rat_reg_digs_t operator / (const pfx_rat_reg_digs_t & arg) const
//		noexcept {
//			const pfx_rat_reg_digs_t& dndo{*this};
//			const pfx_rat_reg_digs_t& dsor{arg};
//			const std::int64_t num_0s_IZDA_dsor{cuenta_0s_desde_IZDA(dsor)};
//			const std::int64_t num_0s_IZDA_dndo{cuenta_0s_desde_IZDA(dndo)};
//			const std::int64_t MSDig_dsor{L-1-num_0s_IZDA_dsor};
//			const std::int64_t MSDig_dndo{L-1-num_0s_IZDA_dndo};
//			pfx_rat_reg_digs_t rem{regd_0()};
//			pfx_rat_reg_digs_t coc{regd_0()};
//			for(std::int64_t num_loops{0} ;
//											num_loops < std::abs(MSDig_dndo-MSDig_dndo)
//																	 ; ++num_loops)
//			{
//				if (MSDig_dsor > MSDig_dndo) {
//					return regd_0();
//				}
//				else if (MSDig_dsor == MSDig_dndo) {
//					for(std::int64_t ix{MSDig_dsor} ; ix > -1 ; --ix) {
//							if (dsor[ix] > dndo[ix]) {
//								return regd_0();// DEVUELVE COCIENTE := 0 Y RESTO := DNDO
//							}
//							else if (dsor[ix] == dndo[ix]) {
//								if (ix == 0)
//									return regd_1();// DEVUELVE COCIENTE := 1 Y RESTO := 0
//								else
//									continue;
//							}
//							else {
//								pfx_rat_reg_digs_t coc{0};
//								pfx_rat_reg_digs_t idndo{dndo};
//								pfx_rat_reg_digs_t idsor{dsor};
//								while (idndo >= idsor) {
//									idndo -= idsor;
//									++coc[0];
//								}
//								return coc; // DEVUELVE COCIENTE := 000...L-1...0D
//														// SIENDO D EL DIGITO 0 (Y EL VALOR DE COCIENTE)
//														// DEVUELVE RESTO    := DNDO - DSOR * D
//							}
//					}
//				}
//				else if (dsor == regd_1()) {
//					return (*this);// DEVUELVE COCIENTE := DNDO Y RESTO := 0
//				}
//				else if (dsor == regd_0()) {
//					return (*this);/// ERROR DIVISION BY 0
//				}
//				else {
//					std::int64_t pl_dndo{MSDig_dsor};
//					std::int64_t ph_dndo{MSDig_dndo};
//
//					// ph_dndo >= ix > pl_dndo
//					for(std::int64_t ix{pl_dndo} ; ix <= ph_dndo ; ++ix) {
//						rem[ix-pl_dndo] = dndo[ix];
//					}
//
//					if (rem == dsor) {
//						return regd_1();// DEVUELVE COCIENTE:=1 Y RESTO:=0
//					}
//					else if (rem > dsor) {
//						dig_t coc_dig{dig_0()};
//						while(rem > dsor) {
//							++coc_dig;
//							rem -= dsor;
//						}
//						coc *= regd_B(); 	// coc = coc * B
//						coc[0] = coc_dig; // coc = coc + D  ; B-1 >= D > 1
//						--pl_dndo;
//						for(std::int64_t ix{ph_dndo} ; ix > pl_dndo ; --ix) {
//							rem[ix-pl_dndo+1] = rem[ix-pl_dndo];
//						}
//						rem[pl_dndo] = dndo[pl_dndo];
//						--ph_dndo;
//					}
//					else {
//						if (pl_dndo != 0) {
//							--pl_dndo;
//							for(std::int64_t ix{ph_dndo} ; ix > pl_dndo ; --ix) {
//								rem[ix-pl_dndo+1] = rem[ix-pl_dndo];
//							}
//							rem[pl_dndo] = dndo[pl_dndo];
//							coc *= regd_B(); // coc = coc * B
//							rem -= dsor;    // coc = coc + 0
//						}
//						else {
//							return coc;// DEVOLVEMOS LO CALCULADO EN COC Y EL RESTO ES REM
//						}
//					}
//				}
//			}
//			return coc;// NO SE DEBERÍA LLEGAR AQUI
//		}
//
//		constexpr inline
//		pfx_rat_reg_digs_t operator % (const pfx_rat_reg_digs_t & arg) const
//		noexcept {
//			pfx_rat_reg_digs_t ret(*this);
//			UINT_T retuds 	= ret.m_dc[0]();
//			UINT_T retdecs 	= ret.m_dc[1]();
//			UINT_T arguds 	= arg.m_dc[0]();
//			UINT_T argdecs 	= arg.m_dc[1]();
//
//			retuds 	+= (B*retdecs);
//			arguds 	+= (B*argdecs);
//			retuds 	%= arguds;
//			retdecs  = retuds;
//			retdecs /= B;
//			retuds 	%= B;
//			ret.m_dc[1] 	= dig_t(retdecs);
//			ret.m_dc[0] 	= dig_t(retuds);
//			return ret;
//		}

				/***********************************/
				/*							   								 */
				/*     OPERADORES ARITMETICOS		 	 */
				/*			pfx_rat_reg_digs_t con base_t	 */
				/* 																 */
				/***********************************/

	constexpr inline
	pfx_rat_reg_digs_t operator + (const base_t & arg) const
	noexcept {
		pfx_rat_reg_digs_t ret(*this);
		pfx_rat_reg_digs_t narg(arg);
		ret += narg;
		return ret;
	}

	constexpr inline
	pfx_rat_reg_digs_t operator - (const base_t & arg) const
	noexcept {
		pfx_rat_reg_digs_t ret(*this);
		pfx_rat_reg_digs_t narg(arg);
		ret -= narg;
		return ret;
	}

	constexpr inline
	pfx_rat_reg_digs_t operator * (const base_t & arg) const
	noexcept {
		pfx_rat_reg_digs_t ret(*this);
		pfx_rat_reg_digs_t narg(arg);
		ret *= narg;
		return ret;
	}

//		constexpr inline
//		pfx_rat_reg_digs_t operator / (const base_t & arg) const
//		noexcept {
//			pfx_rat_reg_digs_t ret(*this);
//			pfx_rat_reg_digs_t narg(arg);
//			ret /= narg;
//			return ret;
//			return ret;
//		}
//
//		constexpr inline
//		pfx_rat_reg_digs_t operator % (const base_t & arg) const
//		noexcept {
//			pfx_rat_reg_digs_t ret(*this);
//			pfx_rat_reg_digs_t narg(arg);
//			ret %= narg;
//			return ret;
//		}

				/************************************/
				/*								    							*/
				/*    ARITMETICOS CON ASIGNACION		*/
				/*			 pfx_rat_reg_digs_t con base_t	*/
				/* 																	*/
				/************************************/

	constexpr inline
	const pfx_rat_reg_digs_t & operator += (const base_t & arg)
	noexcept {
					pfx_rat_reg_digs_t& cthis(*this);
		const pfx_rat_reg_digs_t 	narg(arg);
		cthis += narg;
		return (cthis);
	}

	constexpr inline
	const pfx_rat_reg_digs_t & operator -= (const base_t & arg)
	noexcept {
					pfx_rat_reg_digs_t& cthis(*this);
		const pfx_rat_reg_digs_t 	narg(arg);
		cthis -= narg;
		return (cthis);
	}

	constexpr inline
	const pfx_rat_reg_digs_t & operator *= (const base_t & arg)
	noexcept {
					pfx_rat_reg_digs_t& cthis(*this);
		const pfx_rat_reg_digs_t 	narg(arg);
		cthis *= narg;
		return (cthis);
	}

	constexpr inline
	const pfx_rat_reg_digs_t & operator += (const pfx_rat_reg_digs_t & arg)
	noexcept {
		(*this)+=arg.m_dc;
		return (*this);
	}

	constexpr inline
	const pfx_rat_reg_digs_t & operator -= (const pfx_rat_reg_digs_t & arg)
	noexcept {
		(*this)-=arg.m_dc;
		return (*this);
	}

	constexpr inline
	const pfx_rat_reg_digs_t & operator *= (const pfx_rat_reg_digs_t & arg)
	noexcept {
		(*this)*=arg.m_dc;
		return (*this);
	}

//	constexpr inline
//	const pfx_rat_reg_digs_t & operator /= (const pfx_rat_reg_digs_t & arg)
//	noexcept {
//		pfx_rat_reg_digs_t & ret = (*this);
//		/// TO DO
//		return (*this);
//	}
//
//	constexpr inline
//	const pfx_rat_reg_digs_t & operator %= (const pfx_rat_reg_digs_t & arg)
//	noexcept {
//		pfx_rat_reg_digs_t & cthis{*this};
//		/// TO DO
//		return (*this);
//	}
};


					/****************************/
					/*													*/
					/* 	   ISTREAM Y OSTREAM		*/
					/*													*/
					/****************************/

	template<type_traits::allowable_base_type_c Int_Type,
					Int_Type Base,
					std::size_t Length>
		requires (type_traits::suitable_base<Int_Type,Base>()&&(Length > 0))
	std::istream &
	operator >> (std::istream & is,pfx_rat_reg_digs_t<Int_Type,Base,Length> & arg) {
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
		using pfx_rat_reg_digs_t = pfx_rat_reg_digs_t<Int_Type,Base,Length>;
		/// INDICE QUE RECORRE EL STRING RECOGIDO DE ENTRADA
		std::size_t	indice{0};
		/// VARIABLES PARA ACCIONES EN LOS ESTADOS
		Int_Type 		digito{0};
		std::size_t longitud{0};
		inttype 		numero_base_recogido{0};
		/// VARIABLE DE RETORNO (BINDED TO THE ARG BY REFERENCE)
		pfx_rat_reg_digs_t& numero_ret{arg};
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
							numero_ret = pfx_rat_reg_digs_t::regd_0();
						}
						else  {
							est_act = e0ini;
							digito = 0;
							longitud = 0;
							numero_base_recogido = 0;
							numero_ret = pfx_rat_reg_digs_t::regd_0();
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
							numero_ret = pfx_rat_reg_digs_t::regd_0();
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
							numero_ret.m_dc[Length-1-longitud] = dig_t(digito);
							++longitud;
							digito = c-'0';
						}
						else  {
							est_act = e0ini;
							digito = 0;
							longitud = 0;
							numero_base_recogido = 0;
							indice = 0;
							numero_ret = pfx_rat_reg_digs_t::regd_0();
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
							numero_ret.m_dc[Length-1-longitud] = dig_t(digito);
							digito = 0;
							longitud = 0;
						}
						else  {
							est_act = e0ini;
							indice = 0;
							digito = 0;
							longitud = 0;
							numero_ret = pfx_rat_reg_digs_t::regd_0();
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
							numero_ret = pfx_rat_reg_digs_t::regd_0();
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
	operator << (std::ostream & os,const pfx_rat_reg_digs_t<Int_Type,Base,Long> & arg) {
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

}
#endif // NAT_RAT_FIXED_REG_T_HPP_INCLUDED
