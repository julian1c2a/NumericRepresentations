#ifndef BASE_NUM_T_HPP_INCLUDED
#define BASE_NUM_T_HPP_INCLUDED

#include "int_reg_digs_t.hpp"

namespace NumRepr{

template<type_traits::allowable_base_type_c UINT_T,UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
struct base_num_t {
public:
	basic_string<dig_t<UINT_T,B>> m_dstr;
public:
	using 						dig_t = dig_t<UINT_T,B>;
	using 						nbstr = basic_string<dig_t>;
	using 						striterator 	= typename nbstr::iterator;
	using 						cstriterator 	= typename nbstr::const_iterator;
	using 						rstriterator 	= typename nbstr::reverse_iterator rstriterator;
	using 						crstriterator	= typename nbstr::const_reverse_iterator crstriterator;
public:
	inline constexpr size_t size() const noexcept {
		return m_dstr.size();
	}

	inline constexpr void resize(size_t arg) noexcept {
		m_dstr.resize(arg); return;
	}

	inline constexpr dig_t operator[](ullint arg) const noexcept {
		dig_t ret = m_dstr[arg];
		return m_dstr[arg];
	}

	inline constexpr dig_t & operator[](ullint arg) noexcept {
		dig_t ret = m_dstr[arg];
		return (m_dstr[arg]);
	}

	inline constexpr void clear() noexcept {
		m_dstr.clear();
		return;
	}

	inline constexpr void push_back(dig_t arg) noexcept {
		m_dstr.push_back(arg);
		return;
	}

	inline constexpr void insert(size_t pos,size_t tam,dig_t parg) noexcept {
		m_dstr.insert(pos,tam,parg);
		return;
	}

	inline constexpr num_basic_t substr ( size_t pos , size_t n ) const noexcept {
		m_dstr.substr(pos,n);
		return (*this);
	}

	inline constexpr void push_front(dig_t parg) noexcept {
		m_dstr.insert(0,1,parg);
		return;
	}

	inline constexpr striterator begin() noexcept {
		return m_dstr.begin();
	}
	inline constexpr cstriterator end() const noexcept {
		return m_dstr.end();
	}
	inline constexpr rstriterator rbegin() noexcept {
		return m_dstr.rbegin();
	}
	inline constexpr crstriterator rend() const noexcept {
		return m_dstr.rend();
	}
	inline constexpr void erase(size_t pos,size_t tam) noexcept {
		m_dstr.erase(pos,tam);
		return;
	}

	inline constexpr const num_basic_t & operator &= (const num_basic_t & arg) noexcept {
		m_dstr += arg.m_dstr;
		return (*this);
	}
};

template< typename Int_T , usint B >
inline constexpr
ullint pot_max_base_B_en_Int_T() noexcept {
	constexpr long double max = static_cast<long double>(type_traits::maxbase<Int_T>());
	constexpr long double max_unit = static_cast<long double>(numeric_limits<char>::max());
	constexpr long double nb_unit = static_cast<long double>(1+(log(max_unit)/log(2)));
	constexpr long double n_units_Int_T = static_cast<long double>(sizeof(Int_T));
	constexpr long double nb_Int_T = nb_unit * n_units_Int_T;
	constexpr long double log_2_b_B = std::log(static_cast<long double>(2))/std::log(static_cast<long double>(B));
	constexpr long double ld_expB = (std::floor(nb_Int_T * log_2_b_B));
	//long double ld_potB = (floor(pow(static_cast<long double>(B),ld_expB)));
	constexpr ullint ret = static_cast<ullint>(ld_expB);
	return ret;
}

template< typename Int_T , ullint B >
inline constexpr ullint num_digs_max_base_B_en_Int_T() noexcept {
	constexpr long double max = static_cast<long double>(numeric_limits<Int_T>::max() + 1);
	constexpr long double max_unit = 2*static_cast<long double>(numeric_limits<char>::max() + 1);
	constexpr long double nb_unit = static_cast<long double>((log(max_unit)/log(2)));
	constexpr long double n_units_Int_T = static_cast<long double>(sizeof(Int_T));
	constexpr long double nb_Int_T = nb_unit * n_units_Int_T;
	constexpr long double log_2_b_B = log(static_cast<long double>(2))/log(static_cast<long double>(B));
	long double ld_expB = (floor(nb_Int_T * log_2_b_B));
	long double ld_potB = (floor(pow(static_cast<long double>(B),ld_expB)));
	//bool B_es_pot_de_2 = false;
	ullint pot_2 = 2;
	for (ullint b=1 ; b < max_unit; b++) {
		if (B==pot_2) {
			ld_expB+=static_cast<long double>(1);
			//B_es_pot_de_2 = true;
			break;
		}
		pot_2 *= 2;
	}
	constexpr long double max_pot_B_Int_T = static_cast<long double>(pot_max_base_B_en_Int_T<Int_T,B>());
	long double multiplo = 1;
	ullint ind = 0;
	while((multiplo < max) and (ind < B)) {
		multiplo = floor(multiplo  +  max_pot_B_Int_T);
		if (multiplo > max) {
			multiplo = floor(multiplo - max_pot_B_Int_T);
			ullint ret = static_cast<ullint>(multiplo-1.0);
			return ret;
		}
		++ind;
	}
	constexpr ullint ret = ullint(ld_expB);
	return ret;
}

template< typename Int_T , ullint B >
inline constexpr ullint max_base_B_en_Int_T() noexcept {
	constexpr long double max = static_cast<long double>(numeric_limits<Int_T>::max());
	constexpr long double n_digs_base_B = static_cast<long double>(num_digs_max_base_B_en_Int_T<Int_T,B>());
	constexpr long double dos = static_cast<long double>(2);
	constexpr long double base = static_cast<long double>(B);
	constexpr ullint ret = static_cast<ullint>(ceil((n_digs_base_B*log(dos))/log(base)));
	return ret;
}
}
#endif //  BASE_NUM_T__HPP__INCLUDED
