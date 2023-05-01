#ifndef MEMORY_HANDLER_HPP_INCLUDED
#define MEMORY_HANDLER_HPP_INCLUDED

#include "../include/int_reg_digs_t.hpp"
#include "../include/variant_types.hpp"
#include <variant>
#include <string>
#include <map>
#include <set>

namespace NumRepr {
namespace memory_handler {

template<typename VariantType>
class var_list {

	using key_t = typename std::string;
	using value_t = VariantType; // Base,Valor
	using optvalue_t = typename std::optional<value_t>;
	using node_t = typename std::pair<key_t,value_t>;
	using varlist_t = typename std::map<key_t,value_t>;

	const std::size_t max_size = 2048;
	varlist_t lista{};
	inline static const value_t default_value = dig_t<10>::dig_0();

public:
	var_list() = default;

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

using intvar_list = var_list<genRadixInt32L_t>;
using natvar_list = var_list<genRadixNat32L_t>;
using digvar_list = var_list<genRadixDig_t>;

} // namespace memory_handler
} // namespace NumRepr
#endif // MEMORY_HANDLER_HPP_INCLUDED
