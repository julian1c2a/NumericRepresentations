#ifndef basic_num_t__hpp
#define basic_num_t__hpp

#include "basic_types.hpp"
#include "spardigs_t.hpp"

template<unsigned char Radix> using 
nbstr_t = std::basic_string< dig_t< Radix > >;

template<uchint B>
class basic_num_t : class nbstr_t<B> {
public:
typedef nbstr_t<B> nbstr;
typedef typename nbstr::iterator striterator;
typedef typename nbstr::const_iterator cstriterator;
typedef typename nbstr::reverse_iterator rstriterator;
typedef typename nbstr::const_reverse_iterator crstriterator;
public:
inline size_t size() const {
	return this->nbstr::size();
}

inline void resize(size_t arg) {
	this->nbstr::resize(arg);
}

inline dig_t<B> operator[](uint arg) const {
	dig_t<B> ret = (this->nbstr::operator[](arg));
	return ret;
}

inline dig_t<B> & operator[](uint arg) {
	return (this->nbstr::operator[](arg));
}

inline void clear() {
	this->nbstr::clear();
}

inline void push_back(dig_t<B> arg) {
	this->nbstr::push_back(arg);
}

inline void insert(size_t pos,size_t tam,dig_t<B> parg) {
	this->nbstr::insert(pos,tam,parg);
	return;
}

inline basic_num_t substr ( size_t pos , size_t n ) const {
	this->nbstr::substr(pos,n);
	return (*this);
}

inline void push_front(dig_t<B> parg) {
	this->nbstr::insert(0,1,parg);
}

inline striterator begin() {
	return this->nbstr::begin();
}
inline cstriterator end() const {
	return this->nbstr::end();
}
inline rstriterator rbegin() {
	return this->nbstr::rbegin();
}
inline crstriterator rend() const {
	return this->nbstr::rend();
}
inline void erase(size_t pos,size_t tam) {
	this->nbstr::erase(pos,tam);
}

inline const basic_num_t & operator &= (const basic_num_t & arg) {
	this->nbstr::operator +=(arg);
	return (*this);
}

};

template< typename Int_T , const usint Radio >
ullint pot_max_base_B_en_Int_T() {
	const long double max = static_cast<long double>(numeric_limits<Int_T>::max());
	const long double max_unit = static_cast<long double>(numeric_limits<char>::max());
	const long double nb_unit = static_cast<long double>(1+(log(max_unit)/log(2)));
	const long double n_units_Int_T = static_cast<long double>(sizeof(Int_T));
	const long double nb_Int_T = nb_unit * n_units_Int_T;
	const long double log_2_b_B = log(static_cast<long double>(2))/log(static_cast<long double>(Radio));
	long double ld_expB = (floor(nb_Int_T * log_2_b_B));
	//long double ld_potB = (floor(pow(static_cast<long double>(B),ld_expB)));
	ullint ret = ullint(ld_expB);
	return ret;
}

template< typename Int_T , const usint Radio >
ullint num_digs_max_base_B_en_Int_T() {
	const long double max = static_cast<long double>(numeric_limits<Int_T>::max() + 1);
	const long double max_unit = 2*static_cast<long double>(numeric_limits<char>::max() + 1);
	const long double nb_unit = static_cast<long double>((log(max_unit)/log(2)));
	const long double n_units_Int_T = static_cast<long double>(sizeof(Int_T));
	const long double nb_Int_T = nb_unit * n_units_Int_T;
	const long double log_2_b_B = log(static_cast<long double>(2))/log(static_cast<long double>(Radio));
	long double ld_expB = (floor(nb_Int_T * log_2_b_B));
	long double ld_potB = (floor(pow(static_cast<long double>(Radio),ld_expB)));
	//bool B_es_pot_de_2 = false;
	ullint pot_2 = 2;
	for (uint b=1 ; b < max_unit; b++) {
		if (B==pot_2) {
			ld_expB+=static_cast<long double>(1);
			//B_es_pot_de_2 = true;
			break;
		}
		pot_2 *= 2;
	}
	const long double max_pot_B_Int_T = static_cast<long double>(pot_max_base_B_en_Int_T<Int_T,Radio>());
	long double multiplo = 1;
	ullint ind = 0;
	while((multiplo < max) and (ind < Radio)) {
		multiplo = floor(multiplo  +  max_pot_B_Int_T);
		if (multiplo > max) {
			multiplo = floor(multiplo - max_pot_B_Int_T);
			ullint ret = static_cast<ullint>(multiplo-1.0);
			return ret;
		}
		++ind;
	}
	ullint ret = ullint(ld_expB);
	return ret;
}

template< typename Int_T , const usint Radio >
ullint max_base_B_en_Int_T() {
	const long double max = static_cast<long double>(numeric_limits<Int_T>::max());
	const long double n_digs_base_B = static_cast<long double>(num_digs_max_base_B_en_Int_T<Int_T,Radio>());
	const long double dos = static_cast<long double>(2);
	const long double base = static_cast<long double>(Radio);	
	ullint ret = static_cast<ullint>(ceil((n_digs_base_B*log(dos))/log(base)));
	return ret;
}
  /* resumen basic_num :






   */


#endif
