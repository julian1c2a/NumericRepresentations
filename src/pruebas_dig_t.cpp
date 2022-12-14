#include "reg_digs_t.hpp"
#include <typeinfo>

int main() {
	//template<uchint B,std::size_t L>
	//using reg_digs_t = typename NumRepr::reg_digs_t<uchint,B,L>;
/*
	uchint a='a';
	std::cout << "sizeof(a=" << a << ")=" << sizeof(a) << "\n";
	usint b='b';
	std::cout << "sizeof(b=" << b << ")=" << sizeof(b) << "\n";
	ulint c='c';
	std::cout << "sizeof(c=" << c << ")=" << sizeof(c) << "\n";
	ullint d='d';
	std::cout << "sizeof(d=" << d << ")=" << sizeof(d) << "\n";
*/
/*
	constexpr char fdl{'\n'};
	dig_t v0{dig_t::dig_0()};
	dig_t v1{dig_t::dig_1()};
	dig_t vBm1{dig_t::dig_max()};
	dig_t vBm2{dig_t::dig_submax()};
	std::cout << "v0    =  " << v0.to_string() 		<< fdl
						<< "v1    =  " << v1.to_string() 		<< fdl
						<< "vBm1  =  " << vBm1.to_string() 	<< fdl
						<< "vBm2  =  " << vBm2.to_string() 	<< fdl;
	std::cout << "Size of type dig_t = " << sizeof(dig_t) << fdl;
	for(std::size_t ix{0} ; ix < 23 ; ++ix) {
		std::cout << "TABLAS DE MULTIPLICAR PARA BASE " << dig_t::radix_str() << fdl;
		std::cout << "TABLAS DEL : " << ix << fdl;
		for(std::size_t iy{ix} ; iy < 23 ; ++iy) {
			dig_t dx{ix};
			dig_t dy{iy};
			std::cout << dx << " * " << dy << " = " << dx.multcarry(dy)
								<< ' ' << dx.multresult(dy) << fdl;
		}
	}
	dig_t a{22};
	dig_t b{22};
	dig_t c = a*b;
	dig_t d = a.multresult(b);
	std::cout << c << fdl;
	std::cout << d << fdl;
*/
	using namespace NumRepr;
	constexpr ullint_t B{25u};
	constexpr ullint_t Bm1{B-1};
	constexpr size_t L{5};
	using register_digs_t = typename NumRepr::register_digs_t<B,L>;
	using digit_t = typename NumRepr::digit_t<B>;

	constexpr digit_t A{Bm1};
	const std::type_info& type_of_A = typeid(decltype(A()));
	std::cout << type_of_A.name() << " " << digit_t{A()} << " < ";
	using tipo_de_A = decltype(A());
	using limites_de_A = std::numeric_limits<tipo_de_A>;
	std::cout << limites_de_A::max() << std::endl;

	register_digs_t mi_valor(10u,5u,2u,23u,11u);// escrito alreves
	std::cout << mi_valor << std::endl;
	for(int i{0} ; i<5 ; ++i) {
		std::cout << mi_valor[i] << " ";
	}
	std::cout << std::endl;
	std::cin >> mi_valor;
	for(int i{0} ; i<5 ; ++i) {
		std::cout << mi_valor[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Adios" << std::endl;
	return 0;
}

