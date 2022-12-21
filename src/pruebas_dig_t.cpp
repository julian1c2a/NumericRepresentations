#include "nat_reg_digs_t.hpp"
#include <typeinfo>

int main() {
	/// digit_t<B>
	/// reg_digs_t<B,L>
	using namespace NumRepr;
	constexpr ullint_t B{10u};
	constexpr ullint_t Bm1{B-1};
	constexpr size_t L{5};
	using rd_t = register_of_digits_t<B,L>;
	using d_t = digit_t<B>;
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


	return 0;
}

