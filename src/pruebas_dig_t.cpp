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

using tribinopndo_t = std::tuple<std::int64_t,std::int64_t,std::int64_t>;
using bimonoopndo_t = std::tuple<std::int64_t,std::int64_t>;

using result_test_binop_con_asignacion = std::vector<tribinopndo_t>;
using result_test_monoop_con_asignacion = std::vector<bimonoopndo_t>;

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
	using rd_t = NumRepr::register_of_digits_t<Base,Longitud>;
	using d_t  = NumRepr::digit_t<Base>;
	namespace us = utilities::special;
	namespace NR = NumRepr;
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
		const std::uint64_t iz = conversion_to_int<Base,Longitud>(rd_z);
		const std::uint64_t iw = (ix-1)%B2L;
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
		m_incr(rd_x);
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

	show_test_incr_with_assign<B1,L1>();
	show_test_incr_with_assign<B2,L2>();
	show_test_incr_with_assign<B3,L3>();
	//show_test_sum_with_assign<B1,L1>();
	//show_test_sum_with_assign<B2,L2>();
	//show_test_sum_with_assign<B3,L3>();

	show_test_sum_with_assign_two_digits<B1>();
	show_test_sum_with_assign_two_digits<B2>();
	show_test_sum_with_assign_two_digits<B3>();

	show_test_sum_n_carry_with_assign_two_digits<B1>();
	show_test_sum_n_carry_with_assign_two_digits<B2>();
	show_test_sum_n_carry_with_assign_two_digits<B3>();

	//lista_dig_resta_dig_con_asignacion<B1>();
	//lista_dig_resta_dig_con_asignacion<B2>();
	//lista_dig_resta_dig_con_asignacion<B3>();

	show_test_subtract_with_assign_two_digits<B1>();
	show_test_subtract_with_assign_two_digits<B2>();
	show_test_subtract_with_assign_two_digits<B3>();

	show_test_subtract_with_borrow_with_assign_two_digits<B1>();
	show_test_subtract_with_borrow_with_assign_two_digits<B2>();
	show_test_subtract_with_borrow_with_assign_two_digits<B3>();

	show_test_decr_with_assign<B1,L1>();
	//show_test_decr_with_assign<B2,L2>();
	//show_test_decr_with_assign<B3,L3>();

	return 0;
}

