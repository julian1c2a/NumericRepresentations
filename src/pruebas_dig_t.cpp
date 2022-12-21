#include "nat_reg_digs_t.hpp"
#include <typeinfo>

int main() {
	/// digit_t<B>
	/// reg_digs_t<B,L>
	using namespace NumRepr;
	constexpr ullint_t B{10u};
	//constexpr ullint_t Bm1{B-1};
	constexpr size_t L{5};
	using rd_t = register_of_digits_t<B,L>;
	//using d_t = digit_t<B>;
	/// PRUEBAS SOBRE LA DIVISION
	/// FUNCION AUXILIAR aprox_units_divB
	rd_t opndo{1,3,5,2,6};
	std::cout << opndo << std::endl;
	std::cout << opndo.index_of_MSDig() << std::endl;
	opndo >>= 1;
	std::cout << opndo << std::endl;
	std::cout << opndo.index_of_MSDig() << std::endl;
	opndo >>= 1;
	std::cout << opndo << std::endl;
	std::cout << opndo.index_of_MSDig() << std::endl;
	opndo >>= 1;
	std::cout << opndo << std::endl;
	std::cout << opndo.index_of_MSDig() << std::endl;
	opndo >>= 1;
	std::cout << opndo << std::endl;
	std::cout << opndo.index_of_MSDig() << std::endl;
	opndo >>= 1;
	std::cout << opndo << std::endl;
	std::cout << opndo.index_of_MSDig() << std::endl;
	opndo = rd_t{6,6,7,9,5};
	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
	rd_t lopndo{9,9,8,2,5};
	rd_t ropndo{0,0,5,8,7};
	std::cout << " aprox of " << lopndo  <<  " is " << aprox_units_divB_n<uchint_t,10,5,4>(lopndo) << std::endl;
	std::cout << " aprox of " << lopndo  <<  " is " << aprox_units_divB_n<uchint_t,10,5,3>(lopndo) << std::endl;
	std::cout << " aprox of " << lopndo  <<  " is " << aprox_units_divB_n<uchint_t,10,5,2>(lopndo) << std::endl;
	std::cout << " aprox of " << lopndo  <<  " is " << aprox_units_divB_n<uchint_t,10,5,1>(lopndo) << std::endl;
	//auto calc_coc_rem = aprox_coc_rem<uchint_t,10,5>(rd_t,rd_t);
	//rd_t dsor{0,0,0,0,7};
	//rd_t dndo{0,0,0,0,3};
	//auto result = aprox_coc_rem<uchint_t,10,5>(dndo,dsor);
	bool todo_correcto = true;
	rd_t init_zero{0,0,0,0,0};
	for (int64_t ix{0} ; ix < 99999 ; ++ix) {
		std::cout << std::boolalpha;
		constexpr int64_t B1c = B;
		constexpr int64_t B2c = B1c*B1c;
		constexpr int64_t B3c = B2c*B1c;
		constexpr int64_t B4c = B3c*B1c;
		const int64_t conversion=	static_cast<int64_t>(init_zero[4]())*B4c +\
															static_cast<int64_t>(init_zero[3]())*B3c +\
															static_cast<int64_t>(init_zero[2]())*B2c +\
															static_cast<int64_t>(init_zero[1]())*B1c +\
															static_cast<int64_t>(init_zero[0]())     ;
		todo_correcto = todo_correcto && (conversion==ix);
		m_incr(init_zero);
	}
	if (todo_correcto)
		std::cout << "todo_correcto" << std::endl;
	else
		std::cout << "algo ha fallado" << std::endl;

	m_incr(init_zero);
	std::cout << init_zero << std::endl;

	constexpr ullint_t B2{2u};
	//constexpr ullint_t Bm1{B-1};
	constexpr size_t L2{10};
	using rd2_t = register_of_digits_t<B2,L2>;

	todo_correcto = true;
	rd2_t rd2_zero{0,0,0,0,0,0,0,0,0,0};
	std::cout << std::boolalpha;
	std::cout << rd2_zero << std::endl;
	//char michar{'0'};
	for (uint64_t ix{0} ; ix < 1024 ; ++ix) {
		constexpr int64_t B1c = B2;
		constexpr int64_t B2c = B1c*B1c;
		constexpr int64_t B3c = B2c*B1c;
		constexpr int64_t B4c = B3c*B1c;
		constexpr int64_t B5c = B4c*B1c;
		constexpr int64_t B6c = B5c*B1c;
		constexpr int64_t B7c = B6c*B1c;
		constexpr int64_t B8c = B7c*B1c;
		constexpr int64_t B9c = B8c*B1c;
		const uint64_t conversion =
			static_cast<uint64_t>(rd2_zero[9]())*B9c +\
			static_cast<uint64_t>(rd2_zero[8]())*B8c +\
			static_cast<uint64_t>(rd2_zero[7]())*B7c +\
			static_cast<uint64_t>(rd2_zero[6]())*B6c +\
			static_cast<uint64_t>(rd2_zero[5]())*B5c +\
			static_cast<uint64_t>(rd2_zero[4]())*B4c +\
			static_cast<uint64_t>(rd2_zero[3]())*B3c +\
			static_cast<uint64_t>(rd2_zero[2]())*B2c +\
			static_cast<uint64_t>(rd2_zero[1]())*B1c +\
			static_cast<uint64_t>(rd2_zero[0]())     ;
		//std::cin >> michar;
		todo_correcto = todo_correcto && (conversion==ix);
		std::cout << std::boolalpha;
		std::cout << rd2_zero << "todo correcto: " << todo_correcto << std::endl;
		m_incr(rd2_zero);
	}
	std::cout << rd2_zero << std::endl;
	return 0;
}

