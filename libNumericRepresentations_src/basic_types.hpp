#ifndef TIPOS_BASICOS__HPP
#define TIPOS_BASICOS__HPP

#include <istream>
#include <ostream>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>

#include <vector>
#include <list>
#include <map>

#include <climits>
#include <numeric>
#include <limits>
#include <cmath>

#include <iterator>
#include <functional>

typedef		void*					pdig_t;
typedef		pdig_t*					ppdig_t;
typedef		char					chint;
typedef		chint*					p_chint;
typedef		unsigned char			uchint;
typedef		uchint*					p_uchint;
typedef		signed char				schint;
typedef		schint*					p_schint;
typedef		int*					p_int;
typedef		signed short int		ssint;
typedef		ssint*					p_ssint;
typedef		signed int				sint;
typedef		sint*					p_sint;
typedef		signed long int			slint;
typedef		slint*					p_slint;
typedef		signed long long int	sllint;
typedef		sllint*					p_sllint;
typedef		unsigned char			uchint;
typedef		uchint*					p_uchint;
typedef		unsigned short int		usint;
typedef		usint*					p_usint;
typedef		unsigned int			uint;
typedef		uint*					p_uint;
typedef		unsigned long int		ulint;
typedef		ulint*					p_ulint;
typedef		unsigned long long int	ullint;
typedef		ullint*					p_ullint;


					/****************************/
					//							//
					//	SIGNO					//
					//							//
					/****************************/ 


enum sign_e {vminus,vplus};

template<unsigned char B> class D_t;
template<unsigned char B> class spDs_t;
template<const unsigned char B> class sign_class {
private:
	template<class T>	T operator = (T);
	template<class T>	T& operator = (T);
	template<class T>	const T& operator = (T);
	template<class T>	void operator = (T);
	template<class T>	T operator = (T&);
	template<class T>	T& operator = (T&);
	template<class T>	const T& operator = (T&);
	template<class T>	void operator = (T&);
	template<class T>	T operator = (const T&);
	template<class T>	T& operator = (const T&);
	template<class T>	const T& operator = (const T&);
	template<class T>	void operator = (const T&);
friend class D_t<B>;
friend class spDs_t<B>;
public:
	static const unsigned char vminus = B - 1;
	static const unsigned char vplus = 0;
	unsigned char signo;
	sign_class(unsigned char arg=0) : signo((arg == 0) ? (0) : (B - 1)) {}
	void toggle() {
		signo = (signo==vminus?vplus:vminus);
	}
	unsigned int get() const {
		return signo;
	}
	void put(unsigned int arg) {
		if (arg != 0)
			signo = B-1;
		else
			signo = 0;
	}
	void put_vplus() {
		signo = 0;
	}
	void put_vminus() {
		signo = B-1;
	}
};

inline sign_e Char2Sign(char ch) {
	if (ch <= ',') return vplus;
	else return vminus;
}

inline sign_e Int2Sign (int nu) {
	if (nu <= 0) return vminus;
	else return vplus;
}

inline sign_e Nat2Sign (uchint nu) {
	if (nu==0) return vminus;
	else return vplus;
}

const char nullchar = '\0';

char * clear_ccad(char * cad_c,usint long_de_cad_c) {
	for( usint I=0 ; I < long_de_cad_c ; ++I )
		cad_c[I]=nullchar;
	return cad_c;
}

template< template<const uchint B> class T , const uchint B >
const char* devCadenaC(T<B> arg,usint long_ccad = 64) {
	static char* c_cad = new char[long_ccad];
	c_cad = clear_ccad(c_cad,long_ccad);
	std::stringstream pre_cad;
	pre_cad << arg;
	std::string cad(pre_cad.str());
	const uint longitud = cad.length();
	for(uint i=0;i<longitud;++i) {
		c_cad[i] = cad[i];
	}
	for(uint i=longitud;i<long_ccad;++i) {
		c_cad[i] = '\0';
	}
	return c_cad;
}

/* resumen TIPOS BASICOS :






   */

#endif
