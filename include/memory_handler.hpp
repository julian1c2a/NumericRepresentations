#ifndef MEMORY_HANDLER_HPP_INCLUDED
#define MEMORY_HANDLER_HPP_INCLUDED

#include "../include/int_reg_digs_t.hpp"
//#include "../include/variant_types.hpp"
#include <variant>
#include <string>
#include <ostream>
#include <map>
#include <set>

namespace NumRepr {
namespace memory_handler {

// tipos variant por ahora
// genRadixInt32L_t;
// genRadixNat32L_t;
// genRadixDig_t;
template<std::uint64_t B>
using nat_reg_32digs_t = nat_reg_digs_t<B,32U>;

template<std::uint64_t B>
using int_reg_32digs_t = int_reg_digs_t<B,32U>;

class int_var_list;

class nat_var_list;

using false_type = typename std::false_type;
using true_type = typename std::true_type;

using genRadixDig_t =
	std::variant<
		false_type,true_type,dig_t<2>, dig_t<3>, dig_t<4>, dig_t<5>, dig_t<6>, dig_t<7>, dig_t<8>, dig_t<9>,
		dig_t<10>,dig_t<11>,dig_t<12>,dig_t<13>,dig_t<14>,dig_t<15>,dig_t<16>,dig_t<17>,dig_t<18>,dig_t<19>,
		dig_t<20>,dig_t<21>,dig_t<22>,dig_t<23>,dig_t<24>,dig_t<25>,dig_t<26>,dig_t<27>,dig_t<28>,dig_t<29>,
		dig_t<30>,dig_t<31>,dig_t<32>,dig_t<33>,dig_t<34>,dig_t<35>,dig_t<36>,dig_t<37>,dig_t<38>,dig_t<39>,
		dig_t<40>,dig_t<41>,dig_t<42>,dig_t<43>,dig_t<44>,dig_t<45>,dig_t<46>,dig_t<47>,dig_t<48>,dig_t<49>,
		dig_t<50>,dig_t<51>,dig_t<52>,dig_t<53>,dig_t<54>,dig_t<55>,dig_t<56>,dig_t<57>,dig_t<58>,dig_t<59>,
		dig_t<60>,dig_t<61>,dig_t<62>,dig_t<63>,dig_t<64>,dig_t<65>,dig_t<66>,dig_t<67>,dig_t<68>,dig_t<69>,
		dig_t<70>,dig_t<71>,dig_t<72>,dig_t<73>,dig_t<74>,dig_t<75>,dig_t<76>,dig_t<77>,dig_t<78>,dig_t<79>,
		dig_t<80>,dig_t<81>,dig_t<82>,dig_t<83>,dig_t<84>,dig_t<85>,dig_t<86>,dig_t<87>,dig_t<88>,dig_t<89>,
		dig_t<90>,dig_t<91>,dig_t<92>,dig_t<93>,dig_t<94>,dig_t<95>,dig_t<96>,dig_t<97>,dig_t<98>,dig_t<99>,
		dig_t<100>,dig_t<101>,dig_t<102>,dig_t<103>,dig_t<104>,dig_t<105>,dig_t<106>,dig_t<107>,dig_t<108>,dig_t<109>,
		dig_t<110>,dig_t<111>,dig_t<112>,dig_t<113>,dig_t<114>,dig_t<115>,dig_t<116>,dig_t<117>,dig_t<118>,dig_t<119>,
		dig_t<120>,dig_t<121>,dig_t<122>,dig_t<123>,dig_t<124>,dig_t<125>,dig_t<126>,dig_t<127>,dig_t<128>,dig_t<129>,
		dig_t<130>,dig_t<131>,dig_t<132>,dig_t<133>,dig_t<134>,dig_t<135>,dig_t<136>,dig_t<137>,dig_t<138>,dig_t<139>,
		dig_t<140>,dig_t<141>,dig_t<142>,dig_t<143>,dig_t<144>,dig_t<145>,dig_t<146>,dig_t<147>,dig_t<148>,dig_t<149>,
		dig_t<150>,dig_t<151>,dig_t<152>,dig_t<153>,dig_t<154>,dig_t<155>,dig_t<156>,dig_t<157>,dig_t<158>,dig_t<159>,
		dig_t<160>,dig_t<161>,dig_t<162>,dig_t<163>,dig_t<164>,dig_t<165>,dig_t<166>,dig_t<167>,dig_t<168>,dig_t<169>,
		dig_t<170>,dig_t<171>,dig_t<172>,dig_t<173>,dig_t<174>,dig_t<175>,dig_t<176>,dig_t<177>,dig_t<178>,dig_t<179>,
		dig_t<180>,dig_t<181>,dig_t<182>,dig_t<183>,dig_t<184>,dig_t<185>,dig_t<186>,dig_t<187>,dig_t<188>,dig_t<189>,
		dig_t<190>,dig_t<191>,dig_t<192>,dig_t<193>,dig_t<194>,dig_t<195>,dig_t<196>,dig_t<197>,dig_t<198>,dig_t<199>,
		dig_t<200>,dig_t<201>,dig_t<202>,dig_t<203>,dig_t<204>,dig_t<205>,dig_t<206>,dig_t<207>,dig_t<208>,dig_t<209>,
		dig_t<210>,dig_t<211>,dig_t<212>,dig_t<213>,dig_t<214>,dig_t<215>,dig_t<216>,dig_t<217>,dig_t<218>,dig_t<219>,
		dig_t<220>,dig_t<221>,dig_t<222>,dig_t<223>,dig_t<224>,dig_t<225>,dig_t<226>,dig_t<227>,dig_t<228>,dig_t<229>,
		dig_t<230>,dig_t<231>,dig_t<232>,dig_t<233>,dig_t<234>,dig_t<235>,dig_t<236>,dig_t<237>,dig_t<238>,dig_t<239>,
		dig_t<240>,dig_t<241>,dig_t<242>,dig_t<243>,dig_t<244>,dig_t<245>,dig_t<246>,dig_t<247>,dig_t<248>,dig_t<249>,
		dig_t<250>,dig_t<251>,dig_t<252>,dig_t<253>,dig_t<254>,dig_t<255>
	>;


class dig_var_list {

	using key_t = typename std::string;
	using value_t = genRadixDig_t;
	using optvalue_t = typename std::optional<value_t>;
	using node_t = typename std::pair<key_t,value_t>;
	using varlist_t = typename std::map<key_t,value_t>;

	const std::size_t max_size = 128;
	varlist_t lista{};
	inline static const value_t default_value = dig_t<2>::dig_0();

public:
	dig_var_list() = default;
	dig_var_list(const dig_var_list &) = delete;
	dig_var_list(dig_var_list &&) = delete;
	dig_var_list& operator=(const dig_var_list&) = delete;
	dig_var_list& operator=(dig_var_list&&) = delete;

	std::size_t size() const {
		return lista.size();
	}

	bool contains(std::string nombre) const {
		return lista.contains(nombre);
	}

	bool not_fully() const {
		return (lista.size() < max_size);
	}

	bool create_var(std::string nombre,value_t valor=default_value) {
		if (!contains(nombre) && not_fully()) {
			lista.insert({nombre,valor});
			return true;
		}
		return false;
	}

	bool operator()(std::string nombre,value_t valor) {
		if (contains(nombre)) {
			lista[nombre] = valor;
			return true;
		}
		else if (not_fully()) {
			lista.insert({nombre,valor});
			return true;
		}
		else
			return false;
	}

	auto operator()(std::string nombre) const {
		if (contains(nombre)) {
			return (lista.at(nombre));
		}
		else {
			return (default_value);
		}
	}

	bool erase_var(std::string nombre) {
		if (contains(nombre)) {
			lista.erase(nombre);
			return true;
		}
		return false;
	}

};

bool create_var(
	dig_var_list& cont,std::string nombre,
	std::uint64_t radix,std::uint64_t intvalue
);

std::string to_string(
	const dig_var_list& cont,std::string nombre
);

std::ostream& operator<<(
	std::ostream& os,std::pair<const dig_var_list&,std::string> obj
);

template<std::uint64_t base>
using bool_funct_dig = bool (dig_t<base>::*)();
template<std::uint64_t base>
using dig_funct_dig = dig_t<base> (dig_t<base>::*)();
template<std::uint64_t base>
using uint_funct_dig = dig_t<base>::UINT_T (dig_t<base>::*)();

//decltype(auto) func_variant(bool_funct_dig<base> func , genRadixDig_t arg );
//template<std::uint64_t base>
//  requires ((base > 1ULL) && (base < 255ULL))
//decltype(auto) func_variant(dig_funct_dig<base> func , genRadixDig_t arg );
//template<std::uint64_t base>
//  requires ((base > 1ULL) && (base < 255ULL))
//decltype(auto) func_variant(uint_funct_dig<base> func , genRadixDig_t arg );


} // namespace memory_handler
} // namespace NumRepr
#endif // MEMORY_HANDLER_HPP_INCLUDED
