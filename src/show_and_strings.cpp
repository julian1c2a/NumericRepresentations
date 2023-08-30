#include <string>
#include <ostream>
#include "../include/variant_types.hpp"

namespace NumRepr::memory_handler {

std::string varRadixDig_t::to_string() const noexcept {
	const std::size_t indice{this->index()};
	if (indice==0) {
		return std::string("dig_t<0>??? It is nonsense try represent a number in base 0.");
	} else if (indice == 1) {
		return std::string("dig_t<1>??? It has not implemented represents a number in radix 1.");
	} else if (indice >= 64) {
		return std::string("dig_t<(B>63)> is not included in this variant.");
	} else {
		switch(indice) {
			case 2 : return (std::get<2>(*this)).to_string();
			case 3 : return (std::get<3>(*this)).to_string();
			case 4 : return (std::get<4>(*this)).to_string();
			case 5 : return (std::get<5>(*this)).to_string();
			case 6 : return (std::get<6>(*this)).to_string();
			case 7 : return (std::get<7>(*this)).to_string();
			case 8 : return (std::get<8>(*this)).to_string();
			case 9 : return (std::get<9>(*this)).to_string();
			case 10 : return (std::get<10>(*this)).to_string();
			case 11 : return (std::get<11>(*this)).to_string();
			case 12 : return (std::get<12>(*this)).to_string();
			case 13 : return (std::get<13>(*this)).to_string();
			case 14 : return (std::get<14>(*this)).to_string();
			case 15 : return (std::get<15>(*this)).to_string();
			case 16 : return (std::get<16>(*this)).to_string();
			case 17 : return (std::get<17>(*this)).to_string();
			case 18 : return (std::get<18>(*this)).to_string();
			case 19 : return (std::get<19>(*this)).to_string();
			case 20 : return (std::get<20>(*this)).to_string();
			case 21 : return (std::get<21>(*this)).to_string();
			case 22 : return (std::get<22>(*this)).to_string();
			case 23 : return (std::get<23>(*this)).to_string();
			case 24 : return (std::get<24>(*this)).to_string();
			case 25 : return (std::get<25>(*this)).to_string();
			case 26 : return (std::get<26>(*this)).to_string();
			case 27 : return (std::get<27>(*this)).to_string();
			case 28 : return (std::get<28>(*this)).to_string();
			case 29 : return (std::get<29>(*this)).to_string();
			case 30 : return (std::get<30>(*this)).to_string();
			case 31 : return (std::get<31>(*this)).to_string();
			case 32 : return (std::get<32>(*this)).to_string();
			case 33 : return (std::get<33>(*this)).to_string();
			case 34 : return (std::get<34>(*this)).to_string();
			case 35 : return (std::get<35>(*this)).to_string();
			case 36 : return (std::get<36>(*this)).to_string();
			case 37 : return (std::get<37>(*this)).to_string();
			case 38 : return (std::get<38>(*this)).to_string();
			case 39 : return (std::get<39>(*this)).to_string();
			case 40 : return (std::get<40>(*this)).to_string();
			case 41 : return (std::get<41>(*this)).to_string();
			case 42 : return (std::get<42>(*this)).to_string();
			case 43 : return (std::get<43>(*this)).to_string();
			case 44 : return (std::get<44>(*this)).to_string();
			case 45 : return (std::get<45>(*this)).to_string();
			case 46 : return (std::get<46>(*this)).to_string();
			case 47 : return (std::get<47>(*this)).to_string();
			case 48 : return (std::get<48>(*this)).to_string();
			case 49 : return (std::get<49>(*this)).to_string();
			case 50 : return (std::get<50>(*this)).to_string();
			case 51 : return (std::get<51>(*this)).to_string();
			case 52 : return (std::get<52>(*this)).to_string();
			case 53 : return (std::get<53>(*this)).to_string();
			case 54 : return (std::get<54>(*this)).to_string();
			case 55 : return (std::get<55>(*this)).to_string();
			case 56 : return (std::get<56>(*this)).to_string();
			case 57 : return (std::get<57>(*this)).to_string();
			case 58 : return (std::get<58>(*this)).to_string();
			case 59 : return (std::get<59>(*this)).to_string();
			case 60 : return (std::get<60>(*this)).to_string();
			case 61 : return (std::get<61>(*this)).to_string();
			case 62 : return (std::get<62>(*this)).to_string();
			default : return (std::get<63>(*this)).to_string();
		}
	}
}


std::ostream& operator<<(std::ostream& os,const varRadixDig_t& obj) {
	os << obj.to_string();
	return os;
}





}/// END NAMESPACE NUMREPR::MEMORY_HANDLER