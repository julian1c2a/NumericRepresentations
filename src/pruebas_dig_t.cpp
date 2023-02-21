
#include "testunit.hpp"

int main() {
	/// digit_t<B>
	/// reg_digs_t<B,L>
	using namespace NumRepr;
	// constexpr ullint_t B{10u};
	// constexpr ullint_t Bm1{B-1};
	// constexpr size_t L{5};
	// using rd_t = register_of_digits_t<B, L>;
	// using d_t = digit_t<B>;
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
	constexpr size_t L1{4};
	//--------------------------
	constexpr ullint_t B2{2u};
	constexpr size_t L2{13};
	//--------------------------
	constexpr ullint_t B3{23u};
	constexpr size_t L3{3};
	//--------------------------
	constexpr ullint_t B4{5u};
	constexpr size_t L4{7};
	//--------------------------
	constexpr ullint_t B5{3u};
	constexpr size_t L5{10};
	//--------------------------
	constexpr ullint_t B6{12u};
	constexpr size_t L6{4};
	//--------------------------
	constexpr ullint_t B7{8u};
	constexpr size_t L7{6};
	//--------------------------
	constexpr ullint_t B8{16u};
	constexpr size_t L8{4};

	using rd_1_t [[maybe_unused]] = register_of_digits_t<B1,L1>;
	using dig1_t [[maybe_unused]] = digit_t<B1>;
	using rd_2_t [[maybe_unused]] = register_of_digits_t<B2,L2>;
	using dig2_t [[maybe_unused]] = digit_t<B2>;
	using rd_3_t [[maybe_unused]] = register_of_digits_t<B3,L3>;
	using dig3_t [[maybe_unused]] = digit_t<B3>;
	using rd_4_t [[maybe_unused]] = register_of_digits_t<B4,L4>;
	using dig4_t [[maybe_unused]] = digit_t<B4>;
	using rd_5_t [[maybe_unused]] = register_of_digits_t<B5,L5>;
	using dig5_t [[maybe_unused]] = digit_t<B5>;
	using rd_6_t [[maybe_unused]] = register_of_digits_t<B6,L6>;
	using dig6_t [[maybe_unused]] = digit_t<B6>;
	using rd_7_t [[maybe_unused]] = register_of_digits_t<B7,L7>;
	using dig7_t [[maybe_unused]] = digit_t<B7>;
	using rd_8_t [[maybe_unused]] = register_of_digits_t<B8,L8>;
	using dig8_t [[maybe_unused]] = digit_t<B8>;

	[[maybe_unused]] constexpr auto B2L_1{Base_pow_to_Size<B1,L1>()};
	[[maybe_unused]] constexpr auto B2L_2{Base_pow_to_Size<B2,L2>()};
	[[maybe_unused]] constexpr auto B2L_3{Base_pow_to_Size<B3,L3>()};
	[[maybe_unused]] constexpr auto B2L_4{Base_pow_to_Size<B4,L4>()};
	[[maybe_unused]] constexpr auto B2L_5{Base_pow_to_Size<B5,L5>()};
	[[maybe_unused]] constexpr auto B2L_6{Base_pow_to_Size<B6,L6>()};
	[[maybe_unused]] constexpr auto B2L_7{Base_pow_to_Size<B7,L7>()};
	[[maybe_unused]] constexpr auto B2L_8{Base_pow_to_Size<B8,L8>()};

//	show_test_convert_to_int<B1,L1>();
//	show_test_convert_to_int<B2,L2>();
//	show_test_convert_to_int<B3,L3>();
//
//	show_test_conversion_to_int<B1,L1>();
//	show_test_conversion_to_int<B2,L2>();
//	show_test_conversion_to_int<B3,L3>();

//	show_test_incr_with_assign<B1,L1>();
//	show_test_incr_with_assign<B2,L2>();
//	show_test_incr_with_assign<B3,L3>();

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

//	show_test_subtract_with_assign<B1,L1>();
//	show_test_subtract_with_assign<B2,L2>();
//	show_test_subtract_with_assign<B3,L3>();
//
//	show_test_decr_with_assign<B1,L1>();
//	show_test_decr_with_assign<B2,L2>();
//	show_test_decr_with_assign<B3,L3>();

//	show_test_mult_2_digits_with_assign<B1>();
//	show_test_mult_2_digits_with_assign<B2>();
//	show_test_mult_2_digits_with_assign<B3>();

//	show_test_mult_reg_n_dig_with_assign<B1,L1>();
//	show_test_mult_reg_n_dig_with_assign<B2,L2>();
//	show_test_mult_reg_n_dig_with_assign<B3,L3>();
//
//	show_test_mult_reg_n_reg_with_assign<B1,L1>();
//	show_test_mult_reg_n_reg_with_assign<B2,L2>();
//	show_test_mult_reg_n_reg_with_assign<B3,L3>();

//	show_test_comp_notequal_than_reg_reg<B1,L1>();
//	show_test_comp_equal_than_reg_reg<B1,L1>();
//	show_test_comp_less_than_reg_reg<B1,L1>();
//	show_test_comp_less_or_equal_than_reg_reg<B1,L1>();
//	show_test_comp_greater_than_reg_reg<B1,L1>();
//	show_test_comp_greater_or_equal_than_reg_reg<B1,L1>();
//
//
//	show_test_comp_notequal_than_reg_reg<B2,L2>();
//	show_test_comp_equal_than_reg_reg<B2,L2>();
//	show_test_comp_less_than_reg_reg<B2,L2>();
//	show_test_comp_less_or_equal_than_reg_reg<B2,L2>();
//	show_test_comp_greater_than_reg_reg<B2,L2>();
//	show_test_comp_greater_or_equal_than_reg_reg<B2,L2>();
//
//
//	show_test_comp_notequal_than_reg_reg<B3,L3>();
//	show_test_comp_equal_than_reg_reg<B3,L3>();
//	show_test_comp_less_than_reg_reg<B3,L3>();
//	show_test_comp_less_or_equal_than_reg_reg<B3,L3>();
//	show_test_comp_greater_than_reg_reg<B3,L3>();
//	show_test_comp_greater_or_equal_than_reg_reg<B3,L3>();

//	show_test_calc_coc_dig_rem_div_dsor_for_fediv<B1,L1>();
//	show_test_calc_coc_dig_rem_div_dsor_for_fediv<B2,L2>();
//	show_test_calc_coc_dig_rem_div_dsor_for_fediv<B3,L3>();


	NumRepr::show_test_div_fediv_two_reg_digs<B1,L1>();
//	NumRepr::show_test_div_fediv_two_reg_digs<B2,L2>();
//	NumRepr::show_test_div_fediv_two_reg_digs<B3,L3>();
//	NumRepr::show_test_div_fediv_two_reg_digs<B4,L4>();
//	NumRepr::show_test_div_fediv_two_reg_digs<B5,L5>();
//	NumRepr::show_test_div_fediv_two_reg_digs<B6,L6>();
//	NumRepr::show_test_div_fediv_two_reg_digs<B7,L7>();
//	NumRepr::show_test_div_fediv_two_reg_digs<B8,L8>();


	/*
	C:\Users\julia\Dropbox\GitHub\NumericRepresentations\bin\Release>NumericRepresentations.exe
	TEST para la division (con resto) sobre 2 objetos tipo reg_digs_t<8,6>
	Tiempo transcurrido: 5.87144e+06 ms
	El numero de pruebas "correctas" son 68719214592 pruebas exitosas
	El numero de pruebas "erroneas"  son 0 pruebas fallidas
	Todo ha ido bien : true
	TEST para la division (con resto) sobre 2 objetos tipo reg_digs_t<16,4>
	Tiempo transcurrido: 265941 ms
	El numero de pruebas "correctas" son 4294901760 pruebas exitosas
	El numero de pruebas "erroneas"  son 0 pruebas fallidas
	Todo ha ido bien : true
	TEST para la division (con resto) sobre 2 objetos tipo reg_digs_t<10,4>
	Tiempo transcurrido: 7451.24 ms
	El numero de pruebas "correctas" son 99990000 pruebas exitosas
	El numero de pruebas "erroneas"  son 0 pruebas fallidas
	Todo ha ido bien : true
	TEST para la division (con resto) sobre 2 objetos tipo reg_digs_t<2,13>
	Tiempo transcurrido: 17472.4 ms
	El numero de pruebas "correctas" son 67100672 pruebas exitosas
	El numero de pruebas "erroneas"  son 0 pruebas fallidas
	Todo ha ido bien : true
	TEST para la division (con resto) sobre 2 objetos tipo reg_digs_t<23,3>
	Tiempo transcurrido: 8707.7 ms
	El numero de pruebas "correctas" son 148023722 pruebas exitosas
	El numero de pruebas "erroneas"  son 0 pruebas fallidas
	Todo ha ido bien : true
	TEST para la division (con resto) sobre 2 objetos tipo reg_digs_t<5,6>
	Tiempo transcurrido: 26157.4 ms
	El numero de pruebas "correctas" son 244125000 pruebas exitosas
	El numero de pruebas "erroneas"  son 0 pruebas fallidas
	Todo ha ido bien : true
	TEST para la division (con resto) sobre 2 objetos tipo reg_digs_t<3,10>
	Tiempo transcurrido: 721789 ms
	El numero de pruebas "correctas" son 3486725352 pruebas exitosas
	El numero de pruebas "erroneas"  son 0 pruebas fallidas
	Todo ha ido bien : true
	TEST para la division (con resto) sobre 2 objetos tipo reg_digs_t<12,4>
	Tiempo transcurrido: 31565.9 ms
	El numero de pruebas "correctas" son 429960960 pruebas exitosas
	El numero de pruebas "erroneas"  son 0 pruebas fallidas
	Todo ha ido bien : true

	C:\Users\julia\Dropbox\GitHub\NumericRepresentations\bin\Release>
	*/

	return 0;
}

