#include "utilities.hpp"
#include "nat_reg_digs_t.hpp"
#include <typeinfo>

template<size_t B,size_t L>
constexpr inline
NumRepr::uint128_t
conversion_to_int(NumRepr::register_of_digits_t<B,L> & arg) noexcept {
	namespace NR = NumRepr;
	namespace us = utilities::special;
	return us::conversion_to_int<B,L,NR::register_of_digits_t<B,L>>(arg);
}

using quabinopndo_t = std::tuple<std::int64_t,std::int64_t,std::int64_t,std::int64_t>;
using tribinopndo_t = std::tuple<std::int64_t,std::int64_t,std::int64_t>;
using bimonoopndo_t = std::tuple<std::int64_t,std::int64_t>;

using result_test_binop_2_results_con_asignacion = std::vector<quabinopndo_t>;
using result_test_binop_con_asignacion = std::vector<tribinopndo_t>;
using result_test_monoop_con_asignacion = std::vector<bimonoopndo_t>;

using retorno_de_binop_2_results_test_t = std::tuple<	bool,
																			result_test_binop_2_results_con_asignacion,
																			result_test_binop_2_results_con_asignacion>;
using retorno_de_binop_test_t = std::tuple<	bool,
																			result_test_binop_con_asignacion,
																			result_test_binop_con_asignacion>;
using retorno_de_mononop_test_t = std::tuple<	bool,
																			result_test_monoop_con_asignacion,
																			result_test_monoop_con_asignacion>;

template<NumRepr::ullint_t Base>
retorno_de_binop_test_t test_dig_suma_dig_con_asignacion() {
	using d_t  = NumRepr::digit_t<Base>;
	namespace us = utilities::special;
	namespace NR = NumRepr;
	bool todo_correcto = true;

	constexpr NR::uint128_t B2L{us::Base_pow_to_Size<Base,1>()};

	std::vector<tribinopndo_t> correctos{};
	correctos.reserve(B2L*B2L);
	std::vector<tribinopndo_t> errores{};
	errores.reserve(B2L*B2L);

	d_t rd_x{0};
	for(std::uint64_t ix{0} ; ix < B2L ; ++ix) {
		d_t rd_y{0};
		for(std::uint64_t iy{0} ; iy < B2L ; ++iy) {
			d_t rd_z{rd_x};
			NR::m_sum_digs_carryin_0(rd_z,rd_y);
			const std::uint64_t iz = rd_z();
			const std::uint64_t iw = (ix+iy)%B2L;
			const bool bien {iz==iw};
			const tribinopndo_t trio{rd_x(),rd_y(),rd_z()};
			if (!bien) {
				d_t rd_w{rd_x};
				NR::m_sum_digs_carryin_0(rd_w,rd_y);
				errores.push_back(trio);
			} else {
				correctos.push_back(trio);
			}
			todo_correcto = todo_correcto && bien;
			++rd_y;
		}
		++rd_x;
	}
	return retorno_de_binop_test_t{todo_correcto,correctos,errores};
}

template<NumRepr::ullint_t Base>
retorno_de_binop_2_results_test_t test_dig_mult_dig_con_asignacion() {
	using d_t  = NumRepr::digit_t<Base>;
	namespace us = utilities::special;
	namespace NR = NumRepr;
	bool todo_correcto = true;

	constexpr NR::uint128_t B2L{us::Base_pow_to_Size<Base,1>()};

	std::vector<quabinopndo_t> correctos{};
	correctos.reserve(B2L*B2L);
	std::vector<quabinopndo_t> errores{};
	errores.reserve(B2L*B2L);

	d_t rd_x{0};
	for(std::uint64_t ix{0} ; ix < Base ; ++ix) {
		d_t rd_y{0};
		for(std::uint64_t iy{0} ; iy < Base ; ++iy) {
			d_t rd_z{rd_x};
			d_t rd_p{NR::m_mult(rd_z,rd_y)};
			const std::uint64_t iz = rd_z();
			const std::uint64_t iw = (ix*iy)%Base;
			const std::uint64_t iq = rd_p();
			const std::uint64_t ip = (ix*iy)/Base;
			const bool bien {(iz==iw)and(ip==iq)};
			const quabinopndo_t trio{rd_x(),rd_y(),rd_p(),rd_z()};
			if (!bien) {
				d_t rd_w{rd_x};
				NR::m_mult(rd_w,rd_y);
				errores.push_back(trio);
			} else {
				correctos.push_back(trio);
			}
			todo_correcto = todo_correcto && bien;
			++rd_y;
		}
		++rd_x;
	}
	return retorno_de_binop_2_results_test_t{todo_correcto,correctos,errores};
}

template<NumRepr::ullint_t Base,std::size_t Long>
std::tuple<bool,uint32_t,uint32_t> test_dig_mult_reg_n_dig_con_asignacion() {
	using rd_t = NumRepr::register_of_digits_t<Base,Long>;
	using d_t  = NumRepr::digit_t<Base>;
	namespace us = utilities::special;
	namespace NR = NumRepr;
	bool todo_correcto = true;

	constexpr NR::uint128_t B2L{us::Base_pow_to_Size<Base,Long>()};
//	constexpr NR::uint128_t B2Lp1{us::Base_pow_to_Size<Base,Long+1>()};

//	std::vector<quabinopndo_t> correctos{};
//	correctos.reserve(B2Lp1);
		uint32_t correctos{0};
//	std::vector<quabinopndo_t> errores{};
//	errores.reserve(B2Lp1);
		uint32_t errores{0};

	rd_t rd_x{0};
	for(std::uint64_t ix{0} ; ix < B2L ; ++ix) {
		d_t rd_y{0};
		for(std::uint64_t iy{0} ; iy < Base ; ++iy) {
			rd_t rd_z{rd_x};
			d_t rd_p{NR::m_mult(rd_z,rd_y)};
			const std::uint64_t iz = conversion_to_int<Base,Long>(rd_z);
			const std::uint64_t iw = (ix*iy)%B2L;
			const std::uint64_t iq = rd_p();
			const std::uint64_t ip = (ix*iy)/B2L;
			const bool bien {(iz==iw)&&(ip==iq)};
//			std::cout << std::boolalpha;
//			std::cout << rd_x << " * "
//								<< rd_y << " == "
//								<< rd_p << " : "
//								<< rd_z << " it is " << bien
//								<< std::endl;
//			std::cout << uint64_t(conversion_to_int<Base,Long>(rd_x)) << " * "
//								<< int(rd_y()) << " == "
//								<< int(rd_p()) << " : "
//								<< uint64_t(conversion_to_int<Base,Long>(rd_z)) << " it is " << bien
//								<< std::endl;
//			std::cout << ix << " * "
//								<< iy << " == "
//								<< ip << " : "
//								<< iw << " it is " << bien
//								<< std::endl;
			if (!bien) {
				rd_t rd_w{rd_x};
				//NR::m_mult(rd_w,rd_y);
				++errores;
			} else {
				++correctos;
			}
			todo_correcto = todo_correcto && bien;
			++rd_y;
		}
		m_incr(rd_x);
	}
	return std::make_tuple(todo_correcto,correctos,errores);
}

template<NumRepr::ullint_t Base,std::size_t Long>
std::tuple<bool,uint32_t,uint32_t> test_reg_mult_reg_con_asignacion() {
	using rd_t = NumRepr::register_of_digits_t<Base,Long>;
	namespace us = utilities::special;
	namespace NR = NumRepr;
	bool todo_correcto = true;

	constexpr NR::uint128_t B2L{us::Base_pow_to_Size<Base,Long>()};
//	constexpr NR::uint128_t B2Lp1{us::Base_pow_to_Size<Base,Long+1>()};

//	std::vector<quabinopndo_t> correctos{};
//	correctos.reserve(B2Lp1);
		uint32_t correctos{0};
//	std::vector<quabinopndo_t> errores{};
//	errores.reserve(B2Lp1);
		uint32_t errores{0};

	rd_t rd_x{0};
	for(std::uint64_t ix{0} ; ix < B2L ; ++ix) {
		rd_t rd_y{0};
		for(std::uint64_t iy{0} ; iy < B2L ; ++iy) {
			rd_t rd_z{rd_x};
			rd_t rd_p{NR::m_mult(rd_z,rd_y)};
			const std::uint64_t iz = conversion_to_int<Base,Long>(rd_z);
			const std::uint64_t iw = (ix*iy)%B2L;
			const std::uint64_t iq = conversion_to_int<Base,Long>(rd_p);
			const std::uint64_t ip = (ix*iy)/B2L;
			const bool bien {(iz==iw)&&(ip==iq)};
//			std::cout << std::boolalpha;
//			std::cout << rd_x << " * "
//								<< rd_y << " == "
//								<< rd_p << " : "
//								<< rd_z << " it is " << bien
//								<< std::endl;
//			std::cout << uint64_t(conversion_to_int<Base,Long>(rd_x)) << " * "
//								<< int(rd_y()) << " == "
//								<< int(rd_p()) << " : "
//								<< uint64_t(conversion_to_int<Base,Long>(rd_z)) << " it is " << bien
//								<< std::endl;
//			std::cout << ix << " * "
//								<< iy << " == "
//								<< ip << " : "
//								<< iw << " it is " << bien
//								<< std::endl;
			if (!bien) {
				rd_t rd_w{rd_x};
				//NR::m_mult(rd_w,rd_y);
				++errores;
			} else {
				++correctos;
			}
			todo_correcto = todo_correcto && bien;
			m_incr(rd_y);
		}
		m_incr(rd_x);
	}
	return std::make_tuple(todo_correcto,correctos,errores);
}

template<NumRepr::ullint_t Base>
retorno_de_binop_test_t test_dig_resta_dig_con_asignacion() {
	using d_t  = NumRepr::digit_t<Base>;
	namespace us = utilities::special;
	namespace NR = NumRepr;
	bool todo_correcto = true;

	constexpr NR::uint128_t B2L{us::Base_pow_to_Size<Base,1>()};

	std::vector<tribinopndo_t> correctos{};
	correctos.reserve(B2L*B2L);
	std::vector<tribinopndo_t> errores{};
	errores.reserve(B2L*B2L);

	d_t rd_x{Base-1};
	for(std::int64_t ix{B2L-1} ; ix > -1 ; --ix) {
		d_t rd_y{ix};
		for(std::int64_t iy{ix} ; iy > -1 ; --iy) {
			d_t rd_z{rd_x};
			NR::m_subtract_digs_borrowin_0(rd_z,rd_y);
			const std::uint64_t iz = rd_z();
			const std::uint64_t iw = ix-iy;
			const bool bien {iz==iw};
			const tribinopndo_t trio{rd_x(),rd_y(),rd_z()};
			if (!bien) {
				d_t rd_w{rd_x};
				NR::m_subtract_digs_borrowin_0(rd_w,rd_y);
				errores.push_back(trio);
			} else {
				correctos.push_back(trio);
			}
			todo_correcto = todo_correcto && bien;
			--rd_y;
		}
		--rd_x;
	}
	return retorno_de_binop_test_t{todo_correcto,correctos,errores};
}

template<NumRepr::ullint_t Base>
retorno_de_binop_test_t test_dig_resta_con_borrow_dig_con_asignacion() {
	using d_t  = NumRepr::digit_t<Base>;
	namespace us = utilities::special;
	namespace NR = NumRepr;
	bool todo_correcto = true;

	constexpr NR::uint128_t B2L{us::Base_pow_to_Size<Base,1>()};

	std::vector<tribinopndo_t> correctos{};
	correctos.reserve(B2L*B2L);
	std::vector<tribinopndo_t> errores{};
	errores.reserve(B2L*B2L);

	d_t rd_x{Base-1};
	for(std::int64_t ix{Base-1} ; ix > -1 ; --ix) {
		d_t rd_y{Base-1};
		for(std::int64_t iy{Base-1} ; iy > -1 ; --iy) {
			d_t rd_z{rd_x};
			NR::m_subtract_digs_borrowin_1(rd_z,rd_y);
			const std::int64_t iz = rd_z();
			const std::int64_t iw = ((ix-iy-1)<0)?(ix-iy-1+Base):(ix-iy-1);
			const bool bien {iz==iw};
			const tribinopndo_t trio{rd_x(),rd_y(),rd_z()};
			if (!bien) {
				d_t rd_w{rd_x};
				NR::m_subtract_digs_borrowin_1(rd_w,rd_y);
				errores.push_back(trio);
			} else {
				correctos.push_back(trio);
			}
			todo_correcto = todo_correcto && bien;
			--rd_y;
		}
		--rd_x;
	}
	return retorno_de_binop_test_t{todo_correcto,correctos,errores};
}

template<NumRepr::ullint_t Base>
void lista_dig_resta_dig_con_asignacion() {
	using d_t  = NumRepr::digit_t<Base>;
	namespace us = utilities::special;
	namespace NR = NumRepr;
	constexpr NR::uint128_t B2L{us::Base_pow_to_Size<Base,1>()};

	std::string filename {"resta_de_digitos_lista.txt"};
	std::fstream fichero {filename, fichero.out | fichero.app};

	bool todo_correcto = true;
	d_t rd_x{Base-1};
	for(std::int64_t ix{B2L-1} ; ix > -1 ; --ix) {
		d_t rd_y{Base-1};
		for(std::int64_t iy{B2L-1} ; iy > -1 ; --iy) {
			d_t rd_z{rd_x};
			d_t borrow = NR::m_subtract_digs_borrowin_0(rd_z,rd_y);
			const std::int64_t iz = rd_z();
			const std::int64_t iw = ((ix-iy)<0) ? (ix-iy+Base) : (ix-iy) ;
			const bool bien {iz==iw};
			const tribinopndo_t trio{rd_x(),rd_y(),rd_z()};
			todo_correcto = todo_correcto && bien;
			fichero << std::boolalpha;
			fichero << "Integers : \t" << ix << "\t - " << iy << "\t = \t" << iw
							<< std::endl;
			fichero << "Digits<\t" << Base << "\t> : " << rd_x << "\t - " << rd_y
							<< "\t = \t" << rd_z << std::endl;
			fichero << "       \t" << Base << "\t    " << "   " << "\t   " << "\t   "
							<< "\t            " << borrow << std::endl;
			fichero << "Correcto : \t" << todo_correcto << std::endl;
			fichero << "--------------------------------------------------"
							<< std::endl;
			--rd_y;
		}
		--rd_x;
	}
	fichero.close();
}

template<NumRepr::ullint_t Base>
retorno_de_binop_test_t test_dig_suma_dig_con_carry_con_asignacion() {
	using d_t  = NumRepr::digit_t<Base>;
	namespace us = utilities::special;
	namespace NR = NumRepr;
	bool todo_correcto = true;

	constexpr NR::uint128_t B2L{us::Base_pow_to_Size<Base,1>()};

	std::vector<tribinopndo_t> correctos{};
	correctos.reserve(B2L*B2L);
	std::vector<tribinopndo_t> errores{};
	errores.reserve(B2L*B2L);

	d_t rd_x{0};
	for(std::uint64_t ix{0} ; ix < B2L ; ++ix) {
		d_t rd_y{0};
		for(std::uint64_t iy{0} ; iy < B2L ; ++iy) {
			d_t rd_z{rd_x};
			NR::m_sum_digs_carryin_1(rd_z,rd_y);
			const std::uint64_t iz = rd_z();
			const std::uint64_t iw = (ix+iy+1)%B2L;
			const bool bien {iz==iw};
			const tribinopndo_t trio{rd_x(),rd_y(),rd_z()};
			if (!bien) {
				d_t rd_w{rd_x};
				NR::m_sum_digs_carryin_1(rd_w,rd_y);
				errores.push_back(trio);
			} else {
				correctos.push_back(trio);
			}
			todo_correcto = todo_correcto && bien;
			++rd_y;
		}
		++rd_x;
	}
	return retorno_de_binop_test_t{todo_correcto,correctos,errores};
}

template<NumRepr::ullint_t Base,NumRepr::ullint_t Longitud>
retorno_de_mononop_test_t test_incremento_con_asignacion() {
	using rd_t = NumRepr::register_of_digits_t<Base,Longitud>;
	using d_t  = NumRepr::digit_t<Base>;
	namespace us = utilities::special;
	namespace NR = NumRepr;
	bool todo_correcto = true;

	constexpr NR::uint128_t B2L{us::Base_pow_to_Size<Base,Longitud>()};

	std::vector<bimonoopndo_t> correctos{};
	correctos.reserve(B2L*B2L);
	std::vector<bimonoopndo_t> errores{};
	errores.reserve(B2L*B2L);

	rd_t rd_x{};
	rd_x.fill(d_t{0});
	for(std::uint64_t ix{0} ; ix < B2L ; ++ix) {
		rd_t rd_z{rd_x};
		NR::m_incr(rd_z);
		const std::uint64_t iz = conversion_to_int<Base,Longitud>(rd_z);
		const std::uint64_t iw = (ix+1)%B2L;
		const bool bien {iz==iw};
		const bimonoopndo_t trio{conversion_to_int<Base,Longitud>(rd_x),iz};
		if (!bien) {
			rd_t rd_w{rd_x};
			NR::m_incr(rd_w);
			errores.push_back(trio);
		} else {
			correctos.push_back(trio);
		}
		todo_correcto = todo_correcto && bien;
		m_incr(rd_x);
	}
	return retorno_de_mononop_test_t{todo_correcto,correctos,errores};
}

template<NumRepr::ullint_t Base,NumRepr::ullint_t Longitud>
retorno_de_mononop_test_t test_decremento_con_asignacion() {
	namespace us = utilities::special;
	namespace NR = NumRepr;

	using rd_t = NR::register_of_digits_t<Base,Longitud>;
	using d_t  = NR::digit_t<Base>;

	bool todo_correcto = true;

	constexpr NR::uint128_t B2L{us::Base_pow_to_Size<Base,Longitud>()};

	std::vector<bimonoopndo_t> correctos{};
	correctos.reserve(B2L);
	std::vector<bimonoopndo_t> errores{};
	errores.reserve(B2L);

	rd_t rd_x{};
	rd_x.fill(d_t{Base-1});
	for(std::int64_t ix{B2L-1} ; ix > 0 ; --ix) {
		rd_t rd_z{rd_x};
		NR::m_decr(rd_z);
		const std::int64_t iz = conversion_to_int<Base,Longitud>(rd_z);
		const std::int64_t iw = ((ix-1)<0)?(ix-1+Base):(ix-1);
		const bool bien {iz==iw};
		const bimonoopndo_t trio{conversion_to_int<Base,Longitud>(rd_x),iz};
		if (!bien) {
			rd_t rd_w{rd_x};
			NR::m_decr(rd_w);
			errores.push_back(trio);
		} else {
			correctos.push_back(trio);
		}
		todo_correcto = todo_correcto && bien;
		m_decr(rd_x);
	}
	return retorno_de_mononop_test_t{todo_correcto,correctos,errores};
}

template<NumRepr::ullint_t Base,NumRepr::ullint_t Longitud>
retorno_de_binop_test_t test_suma_con_asignacion() {
	using rd_t = NumRepr::register_of_digits_t<Base,Longitud>;
	using d_t  = NumRepr::digit_t<Base>;
	namespace us = utilities::special;
	namespace NR = NumRepr;
	bool todo_correcto = true;

	constexpr NR::uint128_t B2L{us::Base_pow_to_Size<Base,Longitud>()};

	std::vector<tribinopndo_t> correctos{};
	correctos.reserve(B2L*B2L);
	std::vector<tribinopndo_t> errores{};
	errores.reserve(B2L*B2L);

	rd_t rd_x{};
	rd_x.fill(d_t{0});
	rd_t rd_y{};
	rd_y.fill(d_t{0});
	for(std::uint64_t ix{0} ; ix < B2L ; ++ix) {
		for(std::uint64_t iy{0} ; iy < B2L ; ++iy) {
			rd_t rd_z{rd_x};
			NR::m_sum(rd_z,rd_y);
			const std::uint64_t iz = conversion_to_int<Base,Longitud>(rd_z);
			const std::uint64_t iw = (ix+iy)%B2L;
			const bool bien {iz==iw};
			const tribinopndo_t trio{ix,iy,iz};
			if (!bien) {
				rd_t rd_w{rd_x};
				NR::m_sum(rd_w,rd_y);
				errores.push_back(trio);
			} else {
				correctos.push_back(trio);
			}
			todo_correcto = todo_correcto && bien;
			m_incr(rd_y);
		}
		m_incr(rd_x);
	}
	return retorno_de_binop_test_t{todo_correcto,correctos,errores};
}

template<NumRepr::ullint_t Base,NumRepr::ullint_t Longitud>
retorno_de_binop_test_t test_resta_con_asignacion() {
	using rd_t = NumRepr::register_of_digits_t<Base,Longitud>;
	using d_t  = NumRepr::digit_t<Base>;
	namespace us = utilities::special;
	namespace NR = NumRepr;
	bool todo_correcto = true;

	constexpr NR::uint128_t B2L{us::Base_pow_to_Size<Base,Longitud>()};

	std::vector<tribinopndo_t> correctos{};
	correctos.reserve(B2L*B2L);
	std::vector<tribinopndo_t> errores{};
	errores.reserve(B2L*B2L);

	rd_t rd_x{};
	rd_x.fill(d_t{Base-1});
	rd_t rd_y{};
	rd_y.fill(d_t{0});
	for(std::int64_t ix{B2L-1} ; ix > -1 ; --ix) {
		for(std::int64_t iy{0} ; iy <= ix ; ++iy) {
			rd_t rd_z{rd_x};
			NR::m_subtract(rd_z,rd_y);
			const std::uint64_t iz = conversion_to_int<Base,Longitud>(rd_z);
			const std::uint64_t iw = ix-iy;
			const bool bien {iz==iw};
			const tribinopndo_t trio{ix,iy,iz};
			if (!bien) {
				rd_t rd_w{rd_x};
				NR::m_subtract(rd_w,rd_y);
				errores.push_back(trio);
			} else {
				correctos.push_back(trio);
			}
			todo_correcto = todo_correcto && bien;
			m_incr(rd_y);
		}
		m_decr(rd_x);
	}
	return retorno_de_binop_test_t{todo_correcto,correctos,errores};
}

template<NumRepr::ullint_t Base,size_t Long>
void show_test_incr_with_assign()
{
	std::cout << std::boolalpha;
	auto resultado{test_incremento_con_asignacion<Base,Long>()};
	auto todo_correcto{std::get<0>(resultado)};
	auto correctos{std::get<1>(resultado)};
	auto errores{std::get<2>(resultado)};
	std::cout << "TEST para el incremento y asignacion sobre el tipo register_of_digits_t<"
						<< int(Base) << "," << int(Long) << ">" << std::endl;
	std::cout << "El vector \"correctos\" tiene " << correctos.size() << " elementos " << std::endl;
	std::cout << "El vector \"errores  \" tiene " << errores.size() << " elementos " << std::endl;
	std::cout << "Todo ha ido bien : " << todo_correcto << std::endl;
}

template<NumRepr::ullint_t Base,size_t Long>
void show_test_decr_with_assign()
{
	std::cout << std::boolalpha;
	auto resultado{test_decremento_con_asignacion<Base,Long>()};
	auto todo_correcto{std::get<0>(resultado)};
	auto correctos{std::get<1>(resultado)};
	auto errores{std::get<2>(resultado)};
	std::cout << "TEST para el decremento y asignacion sobre el tipo register_of_digits_t<"
						<< int(Base) << "," << int(Long) << ">" << std::endl;
	std::cout << "El vector \"correctos\" tiene " << correctos.size() << " elementos " << std::endl;
	std::cout << "El vector \"errores  \" tiene " << errores.size() << " elementos " << std::endl;
	std::cout << "Todo ha ido bien : " << todo_correcto << std::endl;
}

template<NumRepr::ullint_t Base,size_t Long>
void show_test_sum_with_assign()
{
	std::cout << std::boolalpha;
	auto resultado{test_suma_con_asignacion<Base,Long>()};
	auto todo_correcto{std::get<0>(resultado)};
	auto correctos{std::get<1>(resultado)};
	auto errores{std::get<2>(resultado)};
	std::cout << "TEST para la suma y asignacion sobre el tipo register_of_digits_t<"
						<< int(Base) << "," << int(Long) << ">" << std::endl;
	std::cout << "El vector \"correctos\" tiene " << correctos.size() << " elementos " << std::endl;
	std::cout << "El vector \"errores  \" tiene " << errores.size() << " elementos " << std::endl;
	std::cout << "Todo ha ido bien : " << todo_correcto << std::endl;
}

// test_dig_mult_dig_con_asignacion
template<NumRepr::ullint_t Base>
void show_test_mult_2_digits_with_assign()
{
	std::cout << std::boolalpha;
	auto resultado{test_dig_mult_dig_con_asignacion<Base>()};
	auto todo_correcto{std::get<0>(resultado)};
	auto correctos{std::get<1>(resultado)};
	auto errores{std::get<2>(resultado)};
	std::cout << "TEST para la multiplicacion y asignacion sobre 2 objetos tipo digit_t<"
						<< int(Base) << ">" << std::endl;
	std::cout << "El vector \"correctos\" tiene " << correctos.size() << " elementos " << std::endl;
	std::cout << "El vector \"errores  \" tiene " << errores.size() << " elementos " << std::endl;
	std::cout << "Todo ha ido bien : " << todo_correcto << std::endl;
}

template<NumRepr::ullint_t Base,size_t Long>
void show_test_subtract_with_assign()
{
	std::cout << std::boolalpha;
	auto resultado{test_resta_con_asignacion<Base,Long>()};
	auto todo_correcto{std::get<0>(resultado)};
	auto correctos{std::get<1>(resultado)};
	auto errores{std::get<2>(resultado)};
	std::cout << "TEST para la resta y asignacion sobre el tipo register_of_digits_t<"
						<< int(Base) << "," << int(Long) << ">" << std::endl;
	std::cout << "El vector \"correctos\" tiene " << correctos.size() << " elementos " << std::endl;
	std::cout << "El vector \"errores  \" tiene " << errores.size() << " elementos " << std::endl;
	std::cout << "Todo ha ido bien : " << todo_correcto << std::endl;
}

template<NumRepr::ullint_t Base>
void show_test_sum_with_assign_two_digits()
{
	std::cout << std::boolalpha;
	auto resultado{test_dig_suma_dig_con_asignacion<Base>()};
	auto todo_correcto{std::get<0>(resultado)};
	auto correctos{std::get<1>(resultado)};
	auto errores{std::get<2>(resultado)};
	std::cout << "TEST para la suma y asignacion sobre 2 objetos tipo digit_t<"
						<< int(Base) << ">" << std::endl;
	std::cout << "El vector \"correctos\" tiene " << correctos.size() << " elementos " << std::endl;
	std::cout << "El vector \"errores  \" tiene " << errores.size() << " elementos " << std::endl;
	std::cout << "Todo ha ido bien : " << todo_correcto << std::endl;
}

// test_dig_mult_reg_n_dig_con_asignacion
template<NumRepr::ullint_t Base,std::size_t Long>
void show_test_mult_reg_n_dig_with_assign()
{
	std::cout << std::boolalpha;
	auto resultado{test_dig_mult_reg_n_dig_con_asignacion<Base,Long>()};
	auto todo_correcto{std::get<0>(resultado)};
	auto correctos{std::get<1>(resultado)};
	auto errores{std::get<2>(resultado)};
	std::cout << "TEST para la multiplicacion y asignacion sobre objeto izquierdo tipo reg_dig_t<"
						<< int(Base) << " , " << int(Long) << "> y objeto derecho tipo dig_t<"
						<< int(Base) << ">" << std::endl;
	std::cout << "El vector \"correctos\" tiene " << correctos << " elementos " << std::endl;
	std::cout << "El vector \"errores  \" tiene " << errores << " elementos " << std::endl;
	std::cout << "Todo ha ido bien : " << todo_correcto << std::endl;
}

// test_reg_mult_reg_con_asignacion
template<NumRepr::ullint_t Base,std::size_t Long>
void show_test_mult_reg_n_reg_with_assign()
{
	std::cout << std::boolalpha;
	auto resultado{test_reg_mult_reg_con_asignacion<Base,Long>()};
	auto todo_correcto{std::get<0>(resultado)};
	auto correctos{std::get<1>(resultado)};
	auto errores{std::get<2>(resultado)};
	std::cout << "TEST para la multiplicacion y asignacion sobre 2 objetos tipo reg_dig_t<"
						<< int(Base) << " , " << int(Long) << ">" << std::endl;
	std::cout << "El vector \"correctos\" tiene " << correctos << " elementos " << std::endl;
	std::cout << "El vector \"errores  \" tiene " << errores << " elementos " << std::endl;
	std::cout << "Todo ha ido bien : " << todo_correcto << std::endl;
}

template<NumRepr::ullint_t Base>
void show_test_subtract_with_assign_two_digits()
{
	std::cout << std::boolalpha;
	auto resultado{test_dig_resta_dig_con_asignacion<Base>()};
	auto todo_correcto{std::get<0>(resultado)};
	auto correctos{std::get<1>(resultado)};
	auto errores{std::get<2>(resultado)};
	std::cout << "TEST para la resta y asignacion sobre 2 objetos tipo digit_t<"
						<< int(Base) << ">" << std::endl;
	std::cout << "El vector \"correctos\" tiene " << correctos.size() << " elementos " << std::endl;
	std::cout << "El vector \"errores  \" tiene " << errores.size() << " elementos " << std::endl;
	std::cout << "Todo ha ido bien : " << todo_correcto << std::endl;
}


template<NumRepr::ullint_t Base>
void show_test_subtract_with_borrow_with_assign_two_digits()
{
	std::cout << std::boolalpha;
	auto resultado{test_dig_resta_con_borrow_dig_con_asignacion<Base>()};
	auto todo_correcto{std::get<0>(resultado)};
	auto correctos{std::get<1>(resultado)};
	auto errores{std::get<2>(resultado)};
	std::cout << "TEST para la resta con borrow y asignacion sobre 2 objetos tipo digit_t<"
						<< int(Base) << ">" << std::endl;
	std::cout << "El vector \"correctos\" tiene " << correctos.size() << " elementos " << std::endl;
	std::cout << "El vector \"errores  \" tiene " << errores.size() << " elementos " << std::endl;
	std::cout << "Todo ha ido bien : " << todo_correcto << std::endl;
}

template<NumRepr::ullint_t Base>
void show_test_sum_n_carry_with_assign_two_digits()
{
	std::cout << std::boolalpha;
	auto resultado{test_dig_suma_dig_con_carry_con_asignacion<Base>()};
	auto todo_correcto{std::get<0>(resultado)};
	auto correctos{std::get<1>(resultado)};
	auto errores{std::get<2>(resultado)};
	std::cout << "TEST para la suma con carry y asignacion sobre 2 objetos tipo digit_t<"
						<< int(Base) << ">" << std::endl;
	std::cout << "El vector \"correctos\" tiene " << correctos.size() << " elementos " << std::endl;
	std::cout << "El vector \"errores  \" tiene " << errores.size() << " elementos " << std::endl;
	std::cout << "Todo ha ido bien : " << todo_correcto << std::endl;
}

int main() {
	/// digit_t<B>
	/// reg_digs_t<B,L>
	using namespace NumRepr;
//	constexpr ullint_t B{10u};
//	//constexpr ullint_t Bm1{B-1};
//	constexpr size_t L{5};
//	using rd_t = register_of_digits_t<B,L>;
	//using d_t = digit_t<B>;
	/// PRUEBAS SOBRE LA DIVISION
	/// FUNCION AUXILIAR aprox_units_divB
//	rd_t opndo{1,3,5,2,6};
//	std::cout << opndo << std::endl;
//	std::cout << opndo.index_of_MSDig() << std::endl;
//	opndo >>= 1;
//	std::cout << opndo << std::endl;
//	std::cout << opndo.index_of_MSDig() << std::endl;
//	opndo >>= 1;
//	std::cout << opndo << std::endl;
//	std::cout << opndo.index_of_MSDig() << std::endl;
//	opndo >>= 1;
//	std::cout << opndo << std::endl;
//	std::cout << opndo.index_of_MSDig() << std::endl;
//	opndo >>= 1;
//	std::cout << opndo << std::endl;
//	std::cout << opndo.index_of_MSDig() << std::endl;
//	opndo >>= 1;
//	std::cout << opndo << std::endl;
//	std::cout << opndo.index_of_MSDig() << std::endl;
//	opndo = rd_t{6,6,7,9,5};
//	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
//	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
//	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
//	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
//	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
//	rd_t lopndo{9,9,8,2,5};
//	rd_t ropndo{0,0,5,8,7};
//	std::cout << " aprox of " << lopndo  <<  " is " << aprox_units_divB_n<uchint_t,10,5,4>(lopndo) << std::endl;
//	std::cout << " aprox of " << lopndo  <<  " is " << aprox_units_divB_n<uchint_t,10,5,3>(lopndo) << std::endl;
//	std::cout << " aprox of " << lopndo  <<  " is " << aprox_units_divB_n<uchint_t,10,5,2>(lopndo) << std::endl;
//	std::cout << " aprox of " << lopndo  <<  " is " << aprox_units_divB_n<uchint_t,10,5,1>(lopndo) << std::endl;

	constexpr ullint_t B1{10u};
	constexpr size_t L1{3};
	//--------------------------
	constexpr ullint_t B2{2u};
	constexpr size_t L2{10};
	//--------------------------
	constexpr ullint_t B3{19u};
	constexpr size_t L3{3};

	using rd_1_t [[maybe_unused]] = register_of_digits_t<B1,L1>;
	using dig1_t [[maybe_unused]] = digit_t<B1>;
	using rd_2_t [[maybe_unused]] = register_of_digits_t<B2,L2>;
	using dig2_t [[maybe_unused]] = digit_t<B2>;
	using rd_3_t [[maybe_unused]] = register_of_digits_t<B3,L3>;
	using dig3_t [[maybe_unused]] = digit_t<B3>;

//	show_test_incr_with_assign<B1,L1>();
//	show_test_incr_with_assign<B2,L2>();
//	show_test_incr_with_assign<B3,L3>();
//
//	show_test_sum_with_assign<B1,L1>();
//	show_test_sum_with_assign<B2,L2>();
//	show_test_sum_with_assign<B3,L3>();
//
//	show_test_sum_with_assign_two_digits<B1>();
//	show_test_sum_with_assign_two_digits<B2>();
//	show_test_sum_with_assign_two_digits<B3>();
//
//	show_test_sum_n_carry_with_assign_two_digits<B1>();
//	show_test_sum_n_carry_with_assign_two_digits<B2>();
//	show_test_sum_n_carry_with_assign_two_digits<B3>();
//
//	show_test_subtract_with_assign_two_digits<B1>();
//	show_test_subtract_with_assign_two_digits<B2>();
//	show_test_subtract_with_assign_two_digits<B3>();
//
//	show_test_subtract_with_borrow_with_assign_two_digits<B1>();
//	show_test_subtract_with_borrow_with_assign_two_digits<B2>();
//	show_test_subtract_with_borrow_with_assign_two_digits<B3>();
//
//
//	show_test_decr_with_assign<B1,L1>();
//	show_test_decr_with_assign<B2,L2>();
//	show_test_decr_with_assign<B3,L3>();
//
//	show_test_mult_2_digits_with_assign<B1>();
//	show_test_mult_2_digits_with_assign<B2>();
//	show_test_mult_2_digits_with_assign<B3>();

	show_test_mult_reg_n_dig_with_assign<B1,L1>();
	show_test_mult_reg_n_dig_with_assign<B2,L2>();
	show_test_mult_reg_n_dig_with_assign<B3,L3>();

	show_test_mult_reg_n_reg_with_assign<B1,L1>();

	rd_1_t left_1{0,1,3};
	rd_1_t right_1{0,8,9};
	dig1_t dl_1{9};
	auto carry = m_mult(left_1,dl_1);
	std::cout << rd_1_t{0,1,3} << " * " << dl_1 << " = ";
	std::cout << carry << left_1 << std::endl;
	//aprox_coc_rem(left_1,right_1);

	return 0;
}

