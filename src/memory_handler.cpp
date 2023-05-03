
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
            case 64 : return std::get<64>(cont(nombre)).to_string();
            case 65 : return std::get<65>(cont(nombre)).to_string();
            case 66 : return std::get<66>(cont(nombre)).to_string();
            case 67 : return std::get<67>(cont(nombre)).to_string();
            case 68 : return std::get<68>(cont(nombre)).to_string();
            case 69 : return std::get<69>(cont(nombre)).to_string();
            case 70 : return std::get<70>(cont(nombre)).to_string();
            case 71 : return std::get<71>(cont(nombre)).to_string();
            case 72 : return std::get<72>(cont(nombre)).to_string();
            case 73 : return std::get<73>(cont(nombre)).to_string();
            case 74 : return std::get<74>(cont(nombre)).to_string();
            case 75 : return std::get<75>(cont(nombre)).to_string();
            case 76 : return std::get<76>(cont(nombre)).to_string();
            case 77 : return std::get<77>(cont(nombre)).to_string();
            case 78 : return std::get<78>(cont(nombre)).to_string();
            case 79 : return std::get<79>(cont(nombre)).to_string();
            case 80 : return std::get<80>(cont(nombre)).to_string();
            case 81 : return std::get<81>(cont(nombre)).to_string();
            case 82 : return std::get<82>(cont(nombre)).to_string();
            case 83 : return std::get<83>(cont(nombre)).to_string();
            case 84 : return std::get<84>(cont(nombre)).to_string();
            case 85 : return std::get<85>(cont(nombre)).to_string();
            case 86 : return std::get<86>(cont(nombre)).to_string();
            case 87 : return std::get<87>(cont(nombre)).to_string();
            case 88 : return std::get<88>(cont(nombre)).to_string();
            case 89 : return std::get<89>(cont(nombre)).to_string();
            case 90 : return std::get<90>(cont(nombre)).to_string();
            case 91 : return std::get<91>(cont(nombre)).to_string();
            case 92 : return std::get<92>(cont(nombre)).to_string();
            case 93 : return std::get<93>(cont(nombre)).to_string();
            case 94 : return std::get<94>(cont(nombre)).to_string();
            case 95 : return std::get<95>(cont(nombre)).to_string();
            case 96 : return std::get<96>(cont(nombre)).to_string();
            case 97 : return std::get<97>(cont(nombre)).to_string();
            case 98 : return std::get<98>(cont(nombre)).to_string();
            case 99 : return std::get<99>(cont(nombre)).to_string();
            case 100 : return std::get<100>(cont(nombre)).to_string();
            case 101 : return std::get<101>(cont(nombre)).to_string();
            case 102 : return std::get<102>(cont(nombre)).to_string();
            case 103 : return std::get<103>(cont(nombre)).to_string();
            case 104 : return std::get<104>(cont(nombre)).to_string();
            case 105 : return std::get<105>(cont(nombre)).to_string();
            case 106 : return std::get<106>(cont(nombre)).to_string();
            case 107 : return std::get<107>(cont(nombre)).to_string();
            case 108 : return std::get<108>(cont(nombre)).to_string();
            case 109 : return std::get<109>(cont(nombre)).to_string();
            case 110 : return std::get<110>(cont(nombre)).to_string();
            case 111 : return std::get<111>(cont(nombre)).to_string();
            case 112 : return std::get<112>(cont(nombre)).to_string();
            case 113 : return std::get<113>(cont(nombre)).to_string();
            case 114 : return std::get<114>(cont(nombre)).to_string();
            case 115 : return std::get<115>(cont(nombre)).to_string();
            case 116 : return std::get<116>(cont(nombre)).to_string();
            case 117 : return std::get<117>(cont(nombre)).to_string();
            case 118 : return std::get<118>(cont(nombre)).to_string();
            case 119 : return std::get<119>(cont(nombre)).to_string();
            case 120 : return std::get<120>(cont(nombre)).to_string();
            case 121 : return std::get<121>(cont(nombre)).to_string();
            case 122 : return std::get<122>(cont(nombre)).to_string();
            case 123 : return std::get<123>(cont(nombre)).to_string();
            case 124 : return std::get<124>(cont(nombre)).to_string();
            case 125 : return std::get<125>(cont(nombre)).to_string();
            case 126 : return std::get<126>(cont(nombre)).to_string();
            case 127 : return std::get<127>(cont(nombre)).to_string();
            case 128 : return std::get<128>(cont(nombre)).to_string();
            case 129 : return std::get<129>(cont(nombre)).to_string();
            case 130 : return std::get<130>(cont(nombre)).to_string();
            case 131 : return std::get<131>(cont(nombre)).to_string();
            case 132 : return std::get<132>(cont(nombre)).to_string();
            case 133 : return std::get<133>(cont(nombre)).to_string();
            case 134 : return std::get<134>(cont(nombre)).to_string();
            case 135 : return std::get<135>(cont(nombre)).to_string();
            case 136 : return std::get<136>(cont(nombre)).to_string();
            case 137 : return std::get<137>(cont(nombre)).to_string();
            case 138 : return std::get<138>(cont(nombre)).to_string();
            case 139 : return std::get<139>(cont(nombre)).to_string();
            case 140 : return std::get<140>(cont(nombre)).to_string();
            case 141 : return std::get<141>(cont(nombre)).to_string();
            case 142 : return std::get<142>(cont(nombre)).to_string();
            case 143 : return std::get<143>(cont(nombre)).to_string();
            case 144 : return std::get<144>(cont(nombre)).to_string();
            case 145 : return std::get<145>(cont(nombre)).to_string();
            case 146 : return std::get<146>(cont(nombre)).to_string();
            case 147 : return std::get<147>(cont(nombre)).to_string();
            case 148 : return std::get<148>(cont(nombre)).to_string();
            case 149 : return std::get<149>(cont(nombre)).to_string();
            case 150 : return std::get<150>(cont(nombre)).to_string();
            case 151 : return std::get<151>(cont(nombre)).to_string();
            case 152 : return std::get<152>(cont(nombre)).to_string();
            case 153 : return std::get<153>(cont(nombre)).to_string();
            case 154 : return std::get<154>(cont(nombre)).to_string();
            case 155 : return std::get<155>(cont(nombre)).to_string();
            case 156 : return std::get<156>(cont(nombre)).to_string();
            case 157 : return std::get<157>(cont(nombre)).to_string();
            case 158 : return std::get<158>(cont(nombre)).to_string();
            case 159 : return std::get<159>(cont(nombre)).to_string();
            case 160 : return std::get<160>(cont(nombre)).to_string();
            case 161 : return std::get<161>(cont(nombre)).to_string();
            case 162 : return std::get<162>(cont(nombre)).to_string();
            case 163 : return std::get<163>(cont(nombre)).to_string();
            case 164 : return std::get<164>(cont(nombre)).to_string();
            case 165 : return std::get<165>(cont(nombre)).to_string();
            case 166 : return std::get<166>(cont(nombre)).to_string();
            case 167 : return std::get<167>(cont(nombre)).to_string();
            case 168 : return std::get<168>(cont(nombre)).to_string();
            case 169 : return std::get<169>(cont(nombre)).to_string();
            case 170 : return std::get<170>(cont(nombre)).to_string();
            case 171 : return std::get<171>(cont(nombre)).to_string();
            case 172 : return std::get<172>(cont(nombre)).to_string();
            case 173 : return std::get<173>(cont(nombre)).to_string();
            case 174 : return std::get<174>(cont(nombre)).to_string();
            case 175 : return std::get<175>(cont(nombre)).to_string();
            case 176 : return std::get<176>(cont(nombre)).to_string();
            case 177 : return std::get<177>(cont(nombre)).to_string();
            case 178 : return std::get<178>(cont(nombre)).to_string();
            case 179 : return std::get<179>(cont(nombre)).to_string();
            case 180 : return std::get<180>(cont(nombre)).to_string();
            case 181 : return std::get<181>(cont(nombre)).to_string();
            case 182 : return std::get<182>(cont(nombre)).to_string();
            case 183 : return std::get<183>(cont(nombre)).to_string();
            case 184 : return std::get<184>(cont(nombre)).to_string();
            case 185 : return std::get<185>(cont(nombre)).to_string();
            case 186 : return std::get<186>(cont(nombre)).to_string();
            case 187 : return std::get<187>(cont(nombre)).to_string();
            case 188 : return std::get<188>(cont(nombre)).to_string();
            case 189 : return std::get<189>(cont(nombre)).to_string();
            case 190 : return std::get<190>(cont(nombre)).to_string();
            case 191 : return std::get<191>(cont(nombre)).to_string();
            case 192 : return std::get<192>(cont(nombre)).to_string();
            case 193 : return std::get<193>(cont(nombre)).to_string();
            case 194 : return std::get<194>(cont(nombre)).to_string();
            case 195 : return std::get<195>(cont(nombre)).to_string();
            case 196 : return std::get<196>(cont(nombre)).to_string();
            case 197 : return std::get<197>(cont(nombre)).to_string();
            case 198 : return std::get<198>(cont(nombre)).to_string();
            case 199 : return std::get<199>(cont(nombre)).to_string();
            case 200 : return std::get<200>(cont(nombre)).to_string();
            case 201 : return std::get<201>(cont(nombre)).to_string();
            case 202 : return std::get<202>(cont(nombre)).to_string();
            case 203 : return std::get<203>(cont(nombre)).to_string();
            case 204 : return std::get<204>(cont(nombre)).to_string();
            case 205 : return std::get<205>(cont(nombre)).to_string();
            case 206 : return std::get<206>(cont(nombre)).to_string();
            case 207 : return std::get<207>(cont(nombre)).to_string();
            case 208 : return std::get<208>(cont(nombre)).to_string();
            case 209 : return std::get<209>(cont(nombre)).to_string();
            case 210 : return std::get<210>(cont(nombre)).to_string();
            case 211 : return std::get<211>(cont(nombre)).to_string();
            case 212 : return std::get<212>(cont(nombre)).to_string();
            case 213 : return std::get<213>(cont(nombre)).to_string();
            case 214 : return std::get<214>(cont(nombre)).to_string();
            case 215 : return std::get<215>(cont(nombre)).to_string();
            case 216 : return std::get<216>(cont(nombre)).to_string();
            case 217 : return std::get<217>(cont(nombre)).to_string();
            case 218 : return std::get<218>(cont(nombre)).to_string();
            case 219 : return std::get<219>(cont(nombre)).to_string();
            case 220 : return std::get<220>(cont(nombre)).to_string();
            case 221 : return std::get<221>(cont(nombre)).to_string();
            case 222 : return std::get<222>(cont(nombre)).to_string();
            case 223 : return std::get<223>(cont(nombre)).to_string();
            case 224 : return std::get<224>(cont(nombre)).to_string();
            case 225 : return std::get<225>(cont(nombre)).to_string();
            case 226 : return std::get<226>(cont(nombre)).to_string();
            case 227 : return std::get<227>(cont(nombre)).to_string();
            case 228 : return std::get<228>(cont(nombre)).to_string();
            case 229 : return std::get<229>(cont(nombre)).to_string();
            case 230 : return std::get<230>(cont(nombre)).to_string();
            case 231 : return std::get<231>(cont(nombre)).to_string();
            case 232 : return std::get<232>(cont(nombre)).to_string();
            case 233 : return std::get<233>(cont(nombre)).to_string();
            case 234 : return std::get<234>(cont(nombre)).to_string();
            case 235 : return std::get<235>(cont(nombre)).to_string();
            case 236 : return std::get<236>(cont(nombre)).to_string();
            case 237 : return std::get<237>(cont(nombre)).to_string();
            case 238 : return std::get<238>(cont(nombre)).to_string();
            case 239 : return std::get<239>(cont(nombre)).to_string();
            case 240 : return std::get<240>(cont(nombre)).to_string();
            case 241 : return std::get<241>(cont(nombre)).to_string();
            case 242 : return std::get<242>(cont(nombre)).to_string();
            case 243 : return std::get<243>(cont(nombre)).to_string();
            case 244 : return std::get<244>(cont(nombre)).to_string();
            case 245 : return std::get<245>(cont(nombre)).to_string();
            case 246 : return std::get<246>(cont(nombre)).to_string();
            case 247 : return std::get<247>(cont(nombre)).to_string();
            case 248 : return std::get<248>(cont(nombre)).to_string();
            case 249 : return std::get<249>(cont(nombre)).to_string();
            case 250 : return std::get<250>(cont(nombre)).to_string();
            case 251 : return std::get<251>(cont(nombre)).to_string();
            case 252 : return std::get<252>(cont(nombre)).to_string();
            case 253 : return std::get<253>(cont(nombre)).to_string();
            case 254 : return std::get<254>(cont(nombre)).to_string();
            case 255 : return std::get<255>(cont(nombre)).to_string();
            default  : return std::string("default is unknown case");
		}
	}
	else {
		return std::string("Name of variable is used (busy) or the number of variables is too high");
	}
}

std::ostream& operator<<(
	std::ostream& os,std::pair<const dig_var_list&,std::string> obj
  ) {
	const auto& the_varlist_of_digits{std::get<0>(obj)};
	const auto& the_name_of_the_variable{std::get<1>(obj)};
	os << to_string(the_varlist_of_digits,the_name_of_the_variable);
	return os;
}

bool create_var(
	dig_var_list& cont,std::string nombre,
	std::uint64_t radix,std::uint64_t intvalue
)
{
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
			case  64 :
				cont.create_var(nombre,dig_t< 64>(intvalue));
				return true;
			case  65 :
				cont.create_var(nombre,dig_t< 65>(intvalue));
				return true;
			case  66 :
				cont.create_var(nombre,dig_t< 66>(intvalue));
				return true;
			case  67 :
				cont.create_var(nombre,dig_t< 67>(intvalue));
				return true;
			case  68 :
				cont.create_var(nombre,dig_t< 68>(intvalue));
				return true;
			case  69 :
				cont.create_var(nombre,dig_t< 69>(intvalue));
				return true;
			case  70 :
				cont.create_var(nombre,dig_t< 70>(intvalue));
				return true;
			case  71 :
				cont.create_var(nombre,dig_t< 71>(intvalue));
				return true;
			case  72 :
				cont.create_var(nombre,dig_t< 72>(intvalue));
				return true;
			case  73 :
				cont.create_var(nombre,dig_t< 73>(intvalue));
				return true;
			case  74 :
				cont.create_var(nombre,dig_t< 74>(intvalue));
				return true;
			case  75 :
				cont.create_var(nombre,dig_t< 75>(intvalue));
				return true;
			case  76 :
				cont.create_var(nombre,dig_t< 76>(intvalue));
				return true;
			case  77 :
				cont.create_var(nombre,dig_t< 77>(intvalue));
				return true;
			case  78 :
				cont.create_var(nombre,dig_t< 78>(intvalue));
				return true;
			case  79 :
				cont.create_var(nombre,dig_t< 79>(intvalue));
				return true;
			case  80 :
				cont.create_var(nombre,dig_t< 80>(intvalue));
				return true;
			case  81 :
				cont.create_var(nombre,dig_t< 81>(intvalue));
				return true;
			case  82 :
				cont.create_var(nombre,dig_t< 82>(intvalue));
				return true;
			case  83 :
				cont.create_var(nombre,dig_t< 83>(intvalue));
				return true;
			case  84 :
				cont.create_var(nombre,dig_t< 84>(intvalue));
				return true;
			case  85 :
				cont.create_var(nombre,dig_t< 85>(intvalue));
				return true;
			case  86 :
				cont.create_var(nombre,dig_t< 86>(intvalue));
				return true;
			case  87 :
				cont.create_var(nombre,dig_t< 87>(intvalue));
				return true;
			case  88 :
				cont.create_var(nombre,dig_t< 88>(intvalue));
				return true;
			case  89 :
				cont.create_var(nombre,dig_t< 89>(intvalue));
				return true;
			case  90 :
				cont.create_var(nombre,dig_t< 90>(intvalue));
				return true;
			case  91 :
				cont.create_var(nombre,dig_t< 91>(intvalue));
				return true;
			case  92 :
				cont.create_var(nombre,dig_t< 92>(intvalue));
				return true;
			case  93 :
				cont.create_var(nombre,dig_t< 93>(intvalue));
				return true;
			case  94 :
				cont.create_var(nombre,dig_t< 94>(intvalue));
				return true;
			case  95 :
				cont.create_var(nombre,dig_t< 95>(intvalue));
				return true;
			case  96 :
				cont.create_var(nombre,dig_t< 96>(intvalue));
				return true;
			case  97 :
				cont.create_var(nombre,dig_t< 97>(intvalue));
				return true;
			case  98 :
				cont.create_var(nombre,dig_t< 98>(intvalue));
				return true;
			case  99 :
				cont.create_var(nombre,dig_t< 99>(intvalue));
				return true;
			case 100 :
				cont.create_var(nombre,dig_t<100>(intvalue));
				return true;
			case 101 :
				cont.create_var(nombre,dig_t<101>(intvalue));
				return true;
			case 102 :
				cont.create_var(nombre,dig_t<102>(intvalue));
				return true;
			case 103 :
				cont.create_var(nombre,dig_t<103>(intvalue));
				return true;
			case 104 :
				cont.create_var(nombre,dig_t<104>(intvalue));
				return true;
			case 105 :
				cont.create_var(nombre,dig_t<105>(intvalue));
				return true;
			case 106 :
				cont.create_var(nombre,dig_t<106>(intvalue));
				return true;
			case 107 :
				cont.create_var(nombre,dig_t<107>(intvalue));
				return true;
			case 108 :
				cont.create_var(nombre,dig_t<108>(intvalue));
				return true;
			case 109 :
				cont.create_var(nombre,dig_t<109>(intvalue));
				return true;
			case 110 :
				cont.create_var(nombre,dig_t<110>(intvalue));
				return true;
			case 111 :
				cont.create_var(nombre,dig_t<111>(intvalue));
				return true;
			case 112 :
				cont.create_var(nombre,dig_t<112>(intvalue));
				return true;
			case 113 :
				cont.create_var(nombre,dig_t<113>(intvalue));
				return true;
			case 114 :
				cont.create_var(nombre,dig_t<114>(intvalue));
				return true;
			case 115 :
				cont.create_var(nombre,dig_t<115>(intvalue));
				return true;
			case 116 :
				cont.create_var(nombre,dig_t<116>(intvalue));
				return true;
			case 117 :
				cont.create_var(nombre,dig_t<117>(intvalue));
				return true;
			case 118 :
				cont.create_var(nombre,dig_t<118>(intvalue));
				return true;
			case 119 :
				cont.create_var(nombre,dig_t<119>(intvalue));
				return true;
			case 120 :
				cont.create_var(nombre,dig_t<120>(intvalue));
				return true;
			case 121 :
				cont.create_var(nombre,dig_t<121>(intvalue));
				return true;
			case 122 :
				cont.create_var(nombre,dig_t<122>(intvalue));
				return true;
			case 123 :
				cont.create_var(nombre,dig_t<123>(intvalue));
				return true;
			case 124 :
				cont.create_var(nombre,dig_t<124>(intvalue));
				return true;
			case 125 :
				cont.create_var(nombre,dig_t<125>(intvalue));
				return true;
			case 126 :
				cont.create_var(nombre,dig_t<126>(intvalue));
				return true;
			case 127 :
				cont.create_var(nombre,dig_t<127>(intvalue));
				return true;
			case 128 :
				cont.create_var(nombre,dig_t<128>(intvalue));
				return true;
			case 129 :
				cont.create_var(nombre,dig_t<129>(intvalue));
				return true;
			case 130 :
				cont.create_var(nombre,dig_t<130>(intvalue));
				return true;
			case 131 :
				cont.create_var(nombre,dig_t<131>(intvalue));
				return true;
			case 132 :
				cont.create_var(nombre,dig_t<132>(intvalue));
				return true;
			case 133 :
				cont.create_var(nombre,dig_t<133>(intvalue));
				return true;
			case 134 :
				cont.create_var(nombre,dig_t<134>(intvalue));
				return true;
			case 135 :
				cont.create_var(nombre,dig_t<135>(intvalue));
				return true;
			case 136 :
				cont.create_var(nombre,dig_t<136>(intvalue));
				return true;
			case 137 :
				cont.create_var(nombre,dig_t<137>(intvalue));
				return true;
			case 138 :
				cont.create_var(nombre,dig_t<138>(intvalue));
				return true;
			case 139 :
				cont.create_var(nombre,dig_t<139>(intvalue));
				return true;
			case 140 :
				cont.create_var(nombre,dig_t<140>(intvalue));
				return true;
			case 141 :
				cont.create_var(nombre,dig_t<141>(intvalue));
				return true;
			case 142 :
				cont.create_var(nombre,dig_t<142>(intvalue));
				return true;
			case 143 :
				cont.create_var(nombre,dig_t<143>(intvalue));
				return true;
			case 144 :
				cont.create_var(nombre,dig_t<144>(intvalue));
				return true;
			case 145 :
				cont.create_var(nombre,dig_t<145>(intvalue));
				return true;
			case 146 :
				cont.create_var(nombre,dig_t<146>(intvalue));
				return true;
			case 147 :
				cont.create_var(nombre,dig_t<147>(intvalue));
				return true;
			case 148 :
				cont.create_var(nombre,dig_t<148>(intvalue));
				return true;
			case 149 :
				cont.create_var(nombre,dig_t<149>(intvalue));
				return true;
			case 150 :
				cont.create_var(nombre,dig_t<150>(intvalue));
				return true;
			case 151 :
				cont.create_var(nombre,dig_t<151>(intvalue));
				return true;
			case 152 :
				cont.create_var(nombre,dig_t<152>(intvalue));
				return true;
			case 153 :
				cont.create_var(nombre,dig_t<153>(intvalue));
				return true;
			case 154 :
				cont.create_var(nombre,dig_t<154>(intvalue));
				return true;
			case 155 :
				cont.create_var(nombre,dig_t<155>(intvalue));
				return true;
			case 156 :
				cont.create_var(nombre,dig_t<156>(intvalue));
				return true;
			case 157 :
				cont.create_var(nombre,dig_t<157>(intvalue));
				return true;
			case 158 :
				cont.create_var(nombre,dig_t<158>(intvalue));
				return true;
			case 159 :
				cont.create_var(nombre,dig_t<159>(intvalue));
				return true;
			case 160 :
				cont.create_var(nombre,dig_t<160>(intvalue));
				return true;
			case 161 :
				cont.create_var(nombre,dig_t<161>(intvalue));
				return true;
			case 162 :
				cont.create_var(nombre,dig_t<162>(intvalue));
				return true;
			case 163 :
				cont.create_var(nombre,dig_t<163>(intvalue));
				return true;
			case 164 :
				cont.create_var(nombre,dig_t<164>(intvalue));
				return true;
			case 165 :
				cont.create_var(nombre,dig_t<165>(intvalue));
				return true;
			case 166 :
				cont.create_var(nombre,dig_t<166>(intvalue));
				return true;
			case 167 :
				cont.create_var(nombre,dig_t<167>(intvalue));
				return true;
			case 168 :
				cont.create_var(nombre,dig_t<168>(intvalue));
				return true;
			case 169 :
				cont.create_var(nombre,dig_t<169>(intvalue));
				return true;
			case 170 :
				cont.create_var(nombre,dig_t<170>(intvalue));
				return true;
			case 171 :
				cont.create_var(nombre,dig_t<171>(intvalue));
				return true;
			case 172 :
				cont.create_var(nombre,dig_t<172>(intvalue));
				return true;
			case 173 :
				cont.create_var(nombre,dig_t<173>(intvalue));
				return true;
			case 174 :
				cont.create_var(nombre,dig_t<174>(intvalue));
				return true;
			case 175 :
				cont.create_var(nombre,dig_t<175>(intvalue));
				return true;
			case 176 :
				cont.create_var(nombre,dig_t<176>(intvalue));
				return true;
			case 177 :
				cont.create_var(nombre,dig_t<177>(intvalue));
				return true;
			case 178 :
				cont.create_var(nombre,dig_t<178>(intvalue));
				return true;
			case 179 :
				cont.create_var(nombre,dig_t<179>(intvalue));
				return true;
			case 180 :
				cont.create_var(nombre,dig_t<180>(intvalue));
				return true;
			case 181 :
				cont.create_var(nombre,dig_t<181>(intvalue));
				return true;
			case 182 :
				cont.create_var(nombre,dig_t<182>(intvalue));
				return true;
			case 183 :
				cont.create_var(nombre,dig_t<183>(intvalue));
				return true;
			case 184 :
				cont.create_var(nombre,dig_t<184>(intvalue));
				return true;
			case 185 :
				cont.create_var(nombre,dig_t<185>(intvalue));
				return true;
			case 186 :
				cont.create_var(nombre,dig_t<186>(intvalue));
				return true;
			case 187 :
				cont.create_var(nombre,dig_t<187>(intvalue));
				return true;
			case 188 :
				cont.create_var(nombre,dig_t<188>(intvalue));
				return true;
			case 189 :
				cont.create_var(nombre,dig_t<189>(intvalue));
				return true;
			case 190 :
				cont.create_var(nombre,dig_t<190>(intvalue));
				return true;
			case 191 :
				cont.create_var(nombre,dig_t<191>(intvalue));
				return true;
			case 192 :
				cont.create_var(nombre,dig_t<192>(intvalue));
				return true;
			case 193 :
				cont.create_var(nombre,dig_t<193>(intvalue));
				return true;
			case 194 :
				cont.create_var(nombre,dig_t<194>(intvalue));
				return true;
			case 195 :
				cont.create_var(nombre,dig_t<195>(intvalue));
				return true;
			case 196 :
				cont.create_var(nombre,dig_t<196>(intvalue));
				return true;
			case 197 :
				cont.create_var(nombre,dig_t<197>(intvalue));
				return true;
			case 198 :
				cont.create_var(nombre,dig_t<198>(intvalue));
				return true;
			case 199 :
				cont.create_var(nombre,dig_t<199>(intvalue));
				return true;
			case 200 :
				cont.create_var(nombre,dig_t<200>(intvalue));
				return true;
			case 201 :
				cont.create_var(nombre,dig_t<201>(intvalue));
				return true;
			case 202 :
				cont.create_var(nombre,dig_t<202>(intvalue));
				return true;
			case 203 :
				cont.create_var(nombre,dig_t<203>(intvalue));
				return true;
			case 204 :
				cont.create_var(nombre,dig_t<204>(intvalue));
				return true;
			case 205 :
				cont.create_var(nombre,dig_t<205>(intvalue));
				return true;
			case 206 :
				cont.create_var(nombre,dig_t<206>(intvalue));
				return true;
			case 207 :
				cont.create_var(nombre,dig_t<207>(intvalue));
				return true;
			case 208 :
				cont.create_var(nombre,dig_t<208>(intvalue));
				return true;
			case 209 :
				cont.create_var(nombre,dig_t<209>(intvalue));
				return true;
			case 210 :
				cont.create_var(nombre,dig_t<210>(intvalue));
				return true;
			case 211 :
				cont.create_var(nombre,dig_t<211>(intvalue));
				return true;
			case 212 :
				cont.create_var(nombre,dig_t<212>(intvalue));
				return true;
			case 213 :
				cont.create_var(nombre,dig_t<213>(intvalue));
				return true;
			case 214 :
				cont.create_var(nombre,dig_t<214>(intvalue));
				return true;
			case 215 :
				cont.create_var(nombre,dig_t<215>(intvalue));
				return true;
			case 216 :
				cont.create_var(nombre,dig_t<216>(intvalue));
				return true;
			case 217 :
				cont.create_var(nombre,dig_t<217>(intvalue));
				return true;
			case 218 :
				cont.create_var(nombre,dig_t<218>(intvalue));
				return true;
			case 219 :
				cont.create_var(nombre,dig_t<219>(intvalue));
				return true;
			case 220 :
				cont.create_var(nombre,dig_t<220>(intvalue));
				return true;
			case 221 :
				cont.create_var(nombre,dig_t<221>(intvalue));
				return true;
			case 222 :
				cont.create_var(nombre,dig_t<222>(intvalue));
				return true;
			case 223 :
				cont.create_var(nombre,dig_t<223>(intvalue));
				return true;
			case 224 :
				cont.create_var(nombre,dig_t<224>(intvalue));
				return true;
			case 225 :
				cont.create_var(nombre,dig_t<225>(intvalue));
				return true;
			case 226 :
				cont.create_var(nombre,dig_t<226>(intvalue));
				return true;
			case 227 :
				cont.create_var(nombre,dig_t<227>(intvalue));
				return true;
			case 228 :
				cont.create_var(nombre,dig_t<228>(intvalue));
				return true;
			case 229 :
				cont.create_var(nombre,dig_t<229>(intvalue));
				return true;
			case 230 :
				cont.create_var(nombre,dig_t<230>(intvalue));
				return true;
			case 231 :
				cont.create_var(nombre,dig_t<231>(intvalue));
				return true;
			case 232 :
				cont.create_var(nombre,dig_t<232>(intvalue));
				return true;
			case 233 :
				cont.create_var(nombre,dig_t<233>(intvalue));
				return true;
			case 234 :
				cont.create_var(nombre,dig_t<234>(intvalue));
				return true;
			case 235 :
				cont.create_var(nombre,dig_t<235>(intvalue));
				return true;
			case 236 :
				cont.create_var(nombre,dig_t<236>(intvalue));
				return true;
			case 237 :
				cont.create_var(nombre,dig_t<237>(intvalue));
				return true;
			case 238 :
				cont.create_var(nombre,dig_t<238>(intvalue));
				return true;
			case 239 :
				cont.create_var(nombre,dig_t<239>(intvalue));
				return true;
			case 240 :
				cont.create_var(nombre,dig_t<240>(intvalue));
				return true;
			case 241 :
				cont.create_var(nombre,dig_t<241>(intvalue));
				return true;
			case 242 :
				cont.create_var(nombre,dig_t<242>(intvalue));
				return true;
			case 243 :
				cont.create_var(nombre,dig_t<243>(intvalue));
				return true;
			case 244 :
				cont.create_var(nombre,dig_t<244>(intvalue));
				return true;
			case 245 :
				cont.create_var(nombre,dig_t<245>(intvalue));
				return true;
			case 246 :
				cont.create_var(nombre,dig_t<246>(intvalue));
				return true;
			case 247 :
				cont.create_var(nombre,dig_t<247>(intvalue));
				return true;
			case 248 :
				cont.create_var(nombre,dig_t<248>(intvalue));
				return true;
			case 249 :
				cont.create_var(nombre,dig_t<249>(intvalue));
				return true;
			case 250 :
				cont.create_var(nombre,dig_t<250>(intvalue));
				return true;
			case 251 :
				cont.create_var(nombre,dig_t<251>(intvalue));
				return true;
			case 252 :
				cont.create_var(nombre,dig_t<252>(intvalue));
				return true;
			case 253 :
				cont.create_var(nombre,dig_t<253>(intvalue));
				return true;
			case 254 :
				cont.create_var(nombre,dig_t<254>(intvalue));
				return true;
			case 255 :
				cont.create_var(nombre,dig_t<255>(intvalue));
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
