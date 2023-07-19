#ifndef MEMORY_HANDLER_HPP_INCLUDED
#define MEMORY_HANDLER_HPP_INCLUDED

#include "digit_variant_t.hpp"
#include <variant>
#include <string>
#include <ostream>
#include <map>
#include <set>

namespace NumRepr {
namespace MemHand {

template<class Variant_t>
class TC_varlist_t {

	using key_t = typename std::string;
	using value_t = Variant_t;
	using node_t = typename std::pair<key_t,value_t>;
	using varlist_t = typename std::map<key_t,value_t>;

protected :

	const std::size_t max_size = 64ull;
	varlist_t lista{};
	static constexpr value_t default_value = Variant_t();

public:

	TC_varlist_t() = default;
	TC_varlist_t(const TC_varlist_t &) = delete;
	TC_varlist_t(TC_varlist_t &&) = delete;
	TC_varlist_t& operator=(const TC_varlist_t&) = delete;
	TC_varlist_t& operator=(TC_varlist_t&&) = delete;

	const varlist_t& getLista() const {
		return (lista);
	}

	std::size_t size() const {
		return lista.size();
	}

	bool contains(std::string nombre) const {
		return lista.contains(nombre);
	}

	bool not_fully() const {
		return (lista.size() < max_size);
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

} // namespace memory_handler
} // namespace NumRepr
#endif // MEMORY_HANDLER_HPP_INCLUDED
