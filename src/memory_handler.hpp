#ifndef MEMORY_HANDLER_HPP_INCLUDED
#define MEMORY_HANDLER_HPP_INCLUDED

#include "nat_reg_digs_t.hpp"
#include <variant>
#include <string>
#include <map>
#include <set>

namespace NumRepr {
namespace memory_handler {

namespace details {



} // namespace details



template<std::size_t Radix>
class dig_var_list {
	using dig_t = dig_t<Radix>;
	using optdig_t = typename std::optional<dig_t>;
	using key = typename std::string;
	using value = dig_t; // Base,Valor
	using varlist_t = typename std::map<key,value>;


	const std::size_t max_size = 2048;
	varlist_t lista{};

public:
	dig_var_list() = default;

	bool disp_nomb_var(std::string nombre) const {
		return (!lista.contains(nombre));
	}

	std::size_t size() const {
		return lista.size();
	}

	bool contains(std::string nombre) const {
		return lista.contains(nombre);
	}

	bool espacio_nueva_var() const {
		return (lista.size() < max_size);
	}

	bool crea_var(std::string nombre,dig_t valor=dig_t::dig_0()) {
		if (disp_nomb_var(nombre) && espacio_nueva_var()) {
			lista.insert({nombre,valor()});
			return true;
		}
		return false;
	}

	bool operator()(std::string nombre,dig_t valor) {
		if (espacio_nueva_var()) {
		    if (disp_nomb_var(nombre)) {
		    	lista[nombre] = valor;
		    	return true;
		    }
		    else {
		    	lista.insert({nombre,valor});
		    	return true;
		    }
		}
		else
			return false;
	}

	optdig_t operator()(std::string nombre) const {
		if (contains(nombre)) {
			return (optdig_t(lista.at(nombre)));
		}
		else {
			return (dig_t::dig_0());
		}
	}

	bool destruye_var(std::string nombre) {
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
