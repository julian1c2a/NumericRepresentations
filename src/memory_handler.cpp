
#include "../include/memory_handler.hpp"
#include <variant>
#include <utility>
#include <ostream>
#include <string>

namespace NumRepr {
namespace memory_handler {

//using genRadixDig_t = typename NumRepr::memory_handler::genRadixDig_t;
std::string to_string(const dig_var_list& cont,std::string nombre) {
	if (!cont.contains(nombre) && cont.not_fully()) {
		switch(cont(nombre).index()) {
			case 0 : return std::string("dig_t<0>??? It is nonsense try represent a number in base 0");
			case 1 : return std::string("dig_t<1>??? We haven't implemented representation in base 1");
            case 2 : return std::get<2>(cont(nombre)).to_string();
            case 3 : return std::get<3>(cont(nombre)).to_string();
            case 4 : return std::get<4>(cont(nombre)).to_string();
            case 5 : return std::get<5>(cont(nombre)).to_string();
            case 6 : return std::get<6>(cont(nombre)).to_string();
            case 7 : return std::get<7>(cont(nombre)).to_string();
            case 8 : return std::get<8>(cont(nombre)).to_string();
            case 9 : return std::get<9>(cont(nombre)).to_string();
            case 10 : return std::get<10>(cont(nombre)).to_string();
            case 11 : return std::get<11>(cont(nombre)).to_string();
            case 12 : return std::get<12>(cont(nombre)).to_string();
            case 13 : return std::get<13>(cont(nombre)).to_string();
            case 14 : return std::get<14>(cont(nombre)).to_string();
            case 15 : return std::get<15>(cont(nombre)).to_string();
            case 16 : return std::get<16>(cont(nombre)).to_string();
            case 17 : return std::get<17>(cont(nombre)).to_string();
            case 18 : return std::get<18>(cont(nombre)).to_string();
            case 19 : return std::get<19>(cont(nombre)).to_string();
            case 20 : return std::get<20>(cont(nombre)).to_string();
            case 21 : return std::get<21>(cont(nombre)).to_string();
            case 22 : return std::get<22>(cont(nombre)).to_string();
            case 23 : return std::get<23>(cont(nombre)).to_string();
            case 24 : return std::get<24>(cont(nombre)).to_string();
            case 25 : return std::get<25>(cont(nombre)).to_string();
            case 26 : return std::get<26>(cont(nombre)).to_string();
            case 27 : return std::get<27>(cont(nombre)).to_string();
            case 28 : return std::get<28>(cont(nombre)).to_string();
            case 29 : return std::get<29>(cont(nombre)).to_string();
            case 30 : return std::get<30>(cont(nombre)).to_string();
            case 31 : return std::get<31>(cont(nombre)).to_string();
            case 32 : return std::get<32>(cont(nombre)).to_string();
            case 33 : return std::get<33>(cont(nombre)).to_string();
            case 34 : return std::get<34>(cont(nombre)).to_string();
            case 35 : return std::get<35>(cont(nombre)).to_string();
            case 36 : return std::get<36>(cont(nombre)).to_string();
            case 37 : return std::get<37>(cont(nombre)).to_string();
            case 38 : return std::get<38>(cont(nombre)).to_string();
            case 39 : return std::get<39>(cont(nombre)).to_string();
            case 40 : return std::get<40>(cont(nombre)).to_string();
            case 41 : return std::get<41>(cont(nombre)).to_string();
            case 42 : return std::get<42>(cont(nombre)).to_string();
            case 43 : return std::get<43>(cont(nombre)).to_string();
            case 44 : return std::get<44>(cont(nombre)).to_string();
            case 45 : return std::get<45>(cont(nombre)).to_string();
            case 46 : return std::get<46>(cont(nombre)).to_string();
            case 47 : return std::get<47>(cont(nombre)).to_string();
            case 48 : return std::get<48>(cont(nombre)).to_string();
            case 49 : return std::get<49>(cont(nombre)).to_string();
            case 50 : return std::get<50>(cont(nombre)).to_string();
            case 51 : return std::get<51>(cont(nombre)).to_string();
            case 52 : return std::get<52>(cont(nombre)).to_string();
            case 53 : return std::get<53>(cont(nombre)).to_string();
            case 54 : return std::get<54>(cont(nombre)).to_string();
            case 55 : return std::get<55>(cont(nombre)).to_string();
            case 56 : return std::get<56>(cont(nombre)).to_string();
            case 57 : return std::get<57>(cont(nombre)).to_string();
            case 58 : return std::get<58>(cont(nombre)).to_string();
            case 59 : return std::get<59>(cont(nombre)).to_string();
            case 60 : return std::get<60>(cont(nombre)).to_string();
            case 61 : return std::get<61>(cont(nombre)).to_string();
            case 62 : return std::get<62>(cont(nombre)).to_string();
            case 63 : return std::get<63>(cont(nombre)).to_string();
            default  : return std::string("default is unknown case");
		}
	}
	else {
		return std::string("Name of variable is used (busy) or the number of variables is too high");
	}
}

bool create_var(
	dig_var_list& cont,std::string nombre,
	std::uint64_t radix,std::uint64_t intvalue
	) {
	if (!cont.contains(nombre) && cont.not_fully()) {
		switch(radix) {
			case   0 :
				return false;
			case   1 :
				return false;
			case   2 :
				cont.create_var(nombre,dig_t<  2>(intvalue));
				return true;
			case   3 :
				cont.create_var(nombre,dig_t<  3>(intvalue));
				return true;
			case   4 :
				cont.create_var(nombre,dig_t<  4>(intvalue));
				return true;
			case   5 :
				cont.create_var(nombre,dig_t<  5>(intvalue));
				return true;
			case   6 :
				cont.create_var(nombre,dig_t<  6>(intvalue));
				return true;
			case   7 :
				cont.create_var(nombre,dig_t<  7>(intvalue));
				return true;
			case   8 :
				cont.create_var(nombre,dig_t<  8>(intvalue));
				return true;
			case   9 :
				cont.create_var(nombre,dig_t<  9>(intvalue));
				return true;
			case  10 :
				cont.create_var(nombre,dig_t< 10>(intvalue));
				return true;
			case  11 :
				cont.create_var(nombre,dig_t< 11>(intvalue));
				return true;
			case  12 :
				cont.create_var(nombre,dig_t< 12>(intvalue));
				return true;
			case  13 :
				cont.create_var(nombre,dig_t< 13>(intvalue));
				return true;
			case  14 :
				cont.create_var(nombre,dig_t< 14>(intvalue));
				return true;
			case  15 :
				cont.create_var(nombre,dig_t< 15>(intvalue));
				return true;
			case  16 :
				cont.create_var(nombre,dig_t< 16>(intvalue));
				return true;
			case  17 :
				cont.create_var(nombre,dig_t< 17>(intvalue));
				return true;
			case  18 :
				cont.create_var(nombre,dig_t< 18>(intvalue));
				return true;
			case  19 :
				cont.create_var(nombre,dig_t< 19>(intvalue));
				return true;
			case  20 :
				cont.create_var(nombre,dig_t< 20>(intvalue));
				return true;
			case  21 :
				cont.create_var(nombre,dig_t< 21>(intvalue));
				return true;
			case  22 :
				cont.create_var(nombre,dig_t< 22>(intvalue));
				return true;
			case  23 :
				cont.create_var(nombre,dig_t< 23>(intvalue));
				return true;
			case  24 :
				cont.create_var(nombre,dig_t< 24>(intvalue));
				return true;
			case  25 :
				cont.create_var(nombre,dig_t< 25>(intvalue));
				return true;
			case  26 :
				cont.create_var(nombre,dig_t< 26>(intvalue));
				return true;
			case  27 :
				cont.create_var(nombre,dig_t< 27>(intvalue));
				return true;
			case  28 :
				cont.create_var(nombre,dig_t< 28>(intvalue));
				return true;
			case  29 :
				cont.create_var(nombre,dig_t< 29>(intvalue));
				return true;
			case  30 :
				cont.create_var(nombre,dig_t< 30>(intvalue));
				return true;
			case  31 :
				cont.create_var(nombre,dig_t< 31>(intvalue));
				return true;
			case  32 :
				cont.create_var(nombre,dig_t< 32>(intvalue));
				return true;
			case  33 :
				cont.create_var(nombre,dig_t< 33>(intvalue));
				return true;
			case  34 :
				cont.create_var(nombre,dig_t< 34>(intvalue));
				return true;
			case  35 :
				cont.create_var(nombre,dig_t< 35>(intvalue));
				return true;
			case  36 :
				cont.create_var(nombre,dig_t< 36>(intvalue));
				return true;
			case  37 :
				cont.create_var(nombre,dig_t< 37>(intvalue));
				return true;
			case  38 :
				cont.create_var(nombre,dig_t< 38>(intvalue));
				return true;
			case  39 :
				cont.create_var(nombre,dig_t< 39>(intvalue));
				return true;
			case  40 :
				cont.create_var(nombre,dig_t< 40>(intvalue));
				return true;
			case  41 :
				cont.create_var(nombre,dig_t< 41>(intvalue));
				return true;
			case  42 :
				cont.create_var(nombre,dig_t< 42>(intvalue));
				return true;
			case  43 :
				cont.create_var(nombre,dig_t< 43>(intvalue));
				return true;
			case  44 :
				cont.create_var(nombre,dig_t< 44>(intvalue));
				return true;
			case  45 :
				cont.create_var(nombre,dig_t< 45>(intvalue));
				return true;
			case  46 :
				cont.create_var(nombre,dig_t< 46>(intvalue));
				return true;
			case  47 :
				cont.create_var(nombre,dig_t< 47>(intvalue));
				return true;
			case  48 :
				cont.create_var(nombre,dig_t< 48>(intvalue));
				return true;
			case  49 :
				cont.create_var(nombre,dig_t< 49>(intvalue));
				return true;
			case  50 :
				cont.create_var(nombre,dig_t< 50>(intvalue));
				return true;
			case  51 :
				cont.create_var(nombre,dig_t< 51>(intvalue));
				return true;
			case  52 :
				cont.create_var(nombre,dig_t< 52>(intvalue));
				return true;
			case  53 :
				cont.create_var(nombre,dig_t< 53>(intvalue));
				return true;
			case  54 :
				cont.create_var(nombre,dig_t< 54>(intvalue));
				return true;
			case  55 :
				cont.create_var(nombre,dig_t< 55>(intvalue));
				return true;
			case  56 :
				cont.create_var(nombre,dig_t< 56>(intvalue));
				return true;
			case  57 :
				cont.create_var(nombre,dig_t< 57>(intvalue));
				return true;
			case  58 :
				cont.create_var(nombre,dig_t< 58>(intvalue));
				return true;
			case  59 :
				cont.create_var(nombre,dig_t< 59>(intvalue));
				return true;
			case  60 :
				cont.create_var(nombre,dig_t< 60>(intvalue));
				return true;
			case  61 :
				cont.create_var(nombre,dig_t< 61>(intvalue));
				return true;
			case  62 :
				cont.create_var(nombre,dig_t< 62>(intvalue));
				return true;
			case  63 :
				cont.create_var(nombre,dig_t< 63>(intvalue));
				return true;
			default  :
				return false;
		}
	} else {
		return false;
	}
} /// END OF FUNCTIONS

} /// END OF NAMESPACE MEMORY_HANDLER
} /// END OF NAMESPACE NUMREPR
