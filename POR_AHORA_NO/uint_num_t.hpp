#ifndef uint_num__hpp
#define uint_num__hpp

#include "basic_num_t.hpp"
#include <string>

using namespace std;

template<const uchint B>
class uint_num_t : public basic_num_t<B> {
private:
typedef dig_t<B>												dig;
typedef basic_num_t<B>										basic_num;
typedef typename std::basic_string<dig>						nbstr;
typedef typename nbstr::iterator								striterator;
typedef typename nbstr::reverse_iterator					rstriterator;
typedef typename nbstr::const_iterator						cstriterator;
typedef typename nbstr::const_reverse_iterator				crstriterator;
typedef typename basic_num::iterator						b_iterator;
typedef typename basic_num::reverse_iterator				b_riterator;
typedef typename basic_num::const_iterator					b_citerator;
typedef typename basic_num::const_reverse_iterator			b_criterator;
typedef typename uint_num_t::iterator						iterator;
typedef typename uint_num_t::reverse_iterator				riterator;
typedef typename uint_num_t::const_iterator				citerator;
typedef typename uint_num_t::const_reverse_iterator		criterator;
typedef n2digs_t<B>											n2digs;
typedef pardigs_t<B>											pardigs;
typedef spardigs_t<B>											spardigs;
typedef uint_num_t<B>											uint_num;

private:

pardigs		aux;

			/****************************/
			/*							*/
			/*		CONSTRUCTORES		*/
			/*							*/
			/****************************/

public:

inline size_t size() const {
	const basic_num & cthis = (*this);
	return cthis.basic_num::size();
}

private:

inline void resize(size_t arg) {
	basic_num & cthis = (*this);
	cthis.basic_num::resize(arg);
	return;
}

public:

inline void push_front(dig_t<B> parg) {
	basic_num & cthis = (*this);
	cthis.basic_num::push_front(parg);
	return;
}

private:

inline uint_num& insert ( size_t pos1, const dig_t<B> chardig ){
	basic_num & cthis = (*this);
	cthis.basic_num::insert(pos1,1,chardig);
	return (*this);
}
inline uint_num& insert ( size_t pos1, size_t n, dig_t<B> c ){
	basic_num & cthis = (*this);
	cthis.basic_num::insert(pos1,n,c);
	return (*this);
}

inline const uint_num_t& operator &= (const uint_num_t& arg) {
	basic_num & cthis = (*this);
	cthis.basic_num::operator +=(arg);
	return (*this);
}

// string& erase ( size_t pos = 0, size_t n = npos );

inline uint_num& erase ( size_t pos, size_t npos ){
	uint_num_t& cthis = (*this);
	size_t npos_2= npos;
	const size_t sz = size();
	if ((sz == npos) and (pos == 0)) {
		npos_2--;
		operator[](sz-1) = dig_t<B>(0);
	}
	cthis.basic_num::erase(pos,npos_2);
	return (*this);
}

inline iterator erase ( iterator first, iterator last ){
	size_t npos= last-first;
	const size_t sz = size();
	if (sz == npos) {
		last--;
		operator[](sz-1) = d_0<B>();
	}
	return basic_num::erase(first,last);
}
public:
inline dig_t<B> operator[](uint arg) const {
	const uint_num_t& cthis = (*this);
	return cthis.basic_num::operator[](arg);
}
inline dig_t<B> & operator[](uint arg) {
	basic_num & cthis = (*this);
	return cthis.basic_num::operator[](arg);
}

inline void clear() {
	basic_num & cthis = (*this);
	cthis.basic_num::clear();
}

inline void push_back(dig_t<B> arg) {
	basic_num & cthis = (*this);
	cthis.basic_num::push_back(arg);
}

inline striterator begin() {
	basic_num & cthis = (*this);
	return cthis.basic_num::begin();
}

inline cstriterator end() const {
	const basic_num & cthis = (*this);
	return cthis.basic_num::end();
}

public:
uint_num_t() {
	uint_num_t & cthis = (*this);
	aux=pardigs();
	cthis.resize(1);
	cthis[0] = dig(0);
}

const uint_num_t & operator = (const uint_num_t & a) {
	uint_num_t& cthis = (*this);
	cthis.clear();
	aux=a.aux;
	const int sz = a.size();
	cthis.resize(sz);
	for (int k=0; k < sz ; ++k){
		cthis[k]=a[k];
	}
	cthis.reduce();
	return cthis;
}

uint_num_t& operator = (uint_num_t& a) {
	uint_num_t& cthis = (*this);
	aux=a.aux;
	const int sz = a.size(); 
	cthis.clear();
	cthis.resize(sz);
	for (int k=0; k < sz ; ++k) {
		cthis[k]=a[k];
	}
	cthis.reduce();
	return cthis;
}

uint_num_t(const uint_num_t& a) {
	uint_num_t& cthis = (*this);
	aux=a.aux;
	cthis.clear();
	cthis.resize(a.size());
	for (usint k=0; k < a.size() ; ++k)
		cthis[k]=a[k];
	cthis.reduce();
}

uint_num_t(const string & a ) {
	uint_num_t& cthis = (*this);
	cthis.clear();
	basic_stringstream<char> in;
	in.clear();
	in << a;
	in >> (*this);
	return;
}

const uint_num_t& operator = (const string & a ) {
	uint_num_t& cthis = (*this);
	cthis.clear();
	basic_stringstream<char> in;
	in.clear();
	in << a;
	in >> cthis;
	return cthis;
}

operator string () const {
	
	const uint_num_t& cthis = (*this);
	string ret;
	basic_stringstream<char> sal_aux;
	sal_aux << cthis;
	sal_aux >> ret;
	return ret;
}

uint_num_t(dig a0) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	cthis.resize(1);
	cthis[0]=a0;
}

const uint_num_t& operator = (const dig & a0) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	cthis.resize(1);
	cthis[0]=a0;
	return cthis;
}

uint_num_t(const dig & a1,const dig & a0 ) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	cthis.resize(2);
	cthis[1]=a0;
	cthis[0]=a1;
	cthis.reduce();
}

uint_num_t(const dig & a2,const dig & a1,const dig & a0) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	cthis.resize(3);
	cthis[2]=a0;
	cthis[1]=a1;
	cthis[0]=a2;
	cthis.reduce();
}

uint_num_t(const vector<dig> & arg) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	for ( int ix=0; ix < arg.size() ; ++ix )
		cthis.push_back(arg[ix]);
	cthis.reduce();
}

const uint_num_t& operator = (const vector<dig> & arg) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	for ( int ix=0; ix < arg.size() ; ++ix )
		cthis.push_back(arg[ix]);
	cthis.reduce();
	return cthis;
}

operator vector<dig> () const {
	const uint_num_t& cthis = (*this);
	const usint sz = (cthis.reduce()).size();
	const usint pos_max = sz-1;
	vector<dig> ret(sz);
	for ( int ix=0; ix < sz ; ++ix )
		ret[pos_max-ix] = cthis[ix];
	return ret;
}

uint_num_t(const pardigs & a) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	cthis.resize(2);
	cthis[0] = a.g_first();
	cthis[1] = a.g_second();
	cthis.reduce();
}

const uint_num_t& operator = (const pardigs & a) {
	const uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	cthis.resize(2);
	cthis[0] = a.g_first();
	cthis[1] = a.g_second();
	cthis.reduce();
	return cthis;
}

uint_num_t(const n2digs & a) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	cthis.resize(2);
	cthis[0] = a.first();
	cthis[1] = a.second();
	cthis.reduce();
}

const uint_num_t& operator = (const n2digs & a) {
	const uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	cthis.resize(2);
	cthis[0] = a.first();
	cthis[1] = a.second();
	cthis.reduce();
	return cthis;
}

uint_num_t(char ch) {
	uint_num_t& cthis = (*this);
	cthis.clear();
	aux=pardigs();
	cthis.resize(1);
	cthis[0] = dig_t<B>(static_cast<uchint>(ch-'0'));
}

const uint_num_t& operator = (char ch) {
	uint_num_t& cthis = (*this);
	cthis.clear();
	aux=pardigs();
	cthis.resize(1);
	cthis[0] = dig_t<B>(static_cast<uchint>(ch-'0'));
	return cthis;
}

uint_num_t(uchint a) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	cthis.resize(1);
	cthis[0]=dig_t<B>(a);
}

const uint_num_t& operator = (uchint a) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	cthis.resize(1);
	cthis[0]=dig_t<B>(a);
	return cthis;
}

uint_num_t(usint a) {
	uint_num_t& cthis = (*this);
	basic_num_t<B> temp;
	cthis.clear();
	//cthis.resize(pot_max_base_B_en_Int_T<usint,B>().first);
	aux=pardigs();
	usint rem=0,coc=a;
	while (coc >= B) {
		rem = coc%B;
		cthis.push_front(dig_t<B>(rem));
		coc = coc/B;
	}
	rem = coc%B;
	cthis.push_front(dig_t<B>(rem));
}

const uint_num_t& operator = (usint a) {
	uint_num_t& cthis = (*this);
	basic_num_t<B> temp;
	cthis.clear();
	aux=pardigs();
	usint rem=0,coc=a;
	while (coc >= B) {
		rem = coc%B;
		cthis.push_front(dig_t<B>(rem));
		coc = coc/B;
	}
	rem = coc%B;
	cthis.push_front(dig_t<B>(rem));
	return cthis;
}

uint_num_t(uint a) {
	uint_num_t& cthis = (*this);
	cthis.clear();
	aux=pardigs();
	uint rem=0,coc=a;
	while (coc >= B) {
		rem = coc%B;
		cthis.push_front(dig_t<B>(rem));
		coc = coc/B;
	}
	rem = coc%B;
	cthis.push_front(dig_t<B>(rem));
}

const uint_num_t& operator = (uint a) {
	uint_num_t& cthis = (*this);
	cthis.clear();
	aux=pardigs();
	uint rem=0,coc=a;
	while (coc >= B) {
		rem = coc%B;
		cthis.push_front(dig_t<B>(rem));
		coc = coc/B;
	}
	rem = coc%B;
	cthis.push_front(dig_t<B>(rem));
	return cthis;
}

uint_num_t(ulint a) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	ulint rem=0,coc=a;
	while (coc >= B) {
		rem = coc%B;
		cthis.push_front(dig_t<B>(rem));
		coc = coc/B;
	}
	rem = coc%B;
	cthis.push_front(dig_t<B>(rem));
}

const uint_num_t& operator = (ulint a) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	ulint rem=0,coc=a;
	while (coc >= B) {
		rem = coc%B;
		cthis.push_front(dig_t<B>(rem));
		coc = coc/B;
	}
	rem = coc%B;
	cthis.push_front(dig_t<B>(rem));
	return cthis;
}

uint_num_t(ullint a) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	ullint rem=0,coc=a;
	while (coc >= B) {
		rem = coc%B;
		cthis.push_front(dig_t<B>(rem));
		coc = coc/B;
	}
	rem = coc%B;
	cthis.push_front(dig_t<B>(rem));
}

const uint_num_t& operator = (ullint a) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	ullint rem=0,coc=a;
	while (coc >= B) {
		rem = coc%B;
		cthis.push_front(dig_t<B>(rem));
		coc = coc/B;
	}
	rem = coc%B;
	cthis.push_front(dig_t<B>(rem));
	return cthis;
}

operator uint () const {
	const uint_num_t& cthis = (*this);
	const uint sz = (cthis.reduce()).size();
	const uint pos_max = sz-1;
	const uint nds = num_digs_max_base_B_en_Int_T<uint,B>();
	uchint ret = 0;
	for(uint il = 0; (il < sz)and(il < nds) ;++il) {
		ret *= B;
		ret += cthis[sz-nds+il].ullint();
	}
	return ret;
}

operator usint () const {
	const uint_num_t& cthis = (*this);
	const uint sz = (cthis.reduce()).size();
	const uint pos_max = sz-1;
	const uint nds = num_digs_max_base_B_en_Int_T<usint,B>();
	uchint ret = 0;
	for(uint il = 0; (il < sz)and(il < nds) ;++il) {
		ret *= ullint(B);
		ret += cthis[sz-nds+il].ullint();
	}
	return ret;
}

operator uchint () const {
	const uint_num_t& cthis = (*this);
	const uint sz = (cthis.reduce()).size();
	const uint pos_max = sz-1;
	const uint nds = num_digs_max_base_B_en_Int_T<uchint,B>();
	uchint ret = 0;
	for(uint il = 0; (il < sz)and(il < nds) ;++il) {
		ret *= B;
		ret += cthis[sz-nds+il].Dig2UInt();
	}
	return ret;
}

operator ulint () const {
	const uint_num_t& cthis = (*this);
	const uint sz = (cthis.reduce()).size();
	const uint pos_max = sz-1;
	const uint nds = num_digs_max_base_B_en_Int_T<ulint,B>();
	uchint ret = 0;
	for(uint il = 0; (il < sz)and(il < nds) ;++il) {
		ret *= B;
		ret += cthis[sz-nds+il].Dig2UInt();
	}
	return ret;
}

operator ullint () const {
	const uint_num_t& cthis = (*this);
	const uint sz = (cthis.reduce()).size();
	const uint pos_max = sz-1;
	const uint nds = num_digs_max_base_B_en_Int_T<ullint,B>();
	uchint ret = 0;
	for(uint il = 0; (il < sz)and(il < nds) ;++il) {
		ret *= B;
		ret += cthis[sz-nds+il].Dig2UInt();
	}
	return ret;
}

uint_num_t& operator = (dig a0) {
	uint_num_t& cthis = (*this);
	aux=pardigs();
	cthis.clear();
	cthis.resize(1);
	cthis[0]=a0;
	return cthis;
}

		/****************************************/
		/*										*/
		/*		DIGITOS NO SIGNIFICATIVOS		*/
		/*										*/
		/****************************************/

usint ceros_a_la_izqda () const {
	const uint_num_t& cthis = (*this);
	//digitos no significativos para n??meros positivos
	bool Exit = false;
	int sz=0;
	const size_t fin= cthis.size();
	for ( uint i=0 ; (i < fin) and (!Exit) ; ++i) {
		if (cthis[i]==0) ++sz;
		else Exit=true;
	}
	return sz;
}

//digitos no significativos para n??meros positivos
size_t ceros_a_la_drcha () const {
	const uint_num_t& cthis = (*this);
	bool Exit = false;
	size_t sz=0;
	const size_t fin=cthis.size();
	const size_t finl = fin-1;
	if (cthis[finl]==0) {
		for ( int i=finl ; (i >=0) and (!Exit) ; --i) {
			if (cthis[i]==0) ++sz;
			else Exit=true;
		}
	}
	return sz;
}

usint digs_no_significativos () const {
	const uint_num_t& cthis = (*this);
	//digitos no significativos
	return ceros_a_la_izqda();
}
usint digs_fracc_no_significativos () const {
	const uint_num_t& cthis = (*this);
	//digitos no significativos
	return ceros_a_la_drcha();
}

		/************************************/
		/*									*/
		/*	OPERACIONES COMPARATIVAS		*/
		/*									*/
		/************************************/

bool operator == (const uint_num_t& arg) const {
	const uint_num_t& cthis = (*this);
	const usint thisnsz = ceros_a_la_izqda();
	const usint thisvsz = cthis.size()-thisnsz;
	const usint argnsz = arg.ceros_a_la_izqda();
	const usint argvsz = arg.size()-argnsz;
	if ((thisvsz > argvsz)||(thisvsz < argvsz))
		return false;
	else {
		for (slint k=(thisvsz-1);k>=0;--k)
			if (arg[k]!=cthis[k]) return false;
		return true;
	}
}

bool operator != (const uint_num_t& arg) const {
	const uint_num_t& cthis = (*this);
	const usint thisnsz = ceros_a_la_izqda();
	const usint thisvsz = (cthis.size())-thisnsz;
	const usint argnsz = arg.ceros_a_la_izqda();
	const usint argvsz = arg.size()-argnsz;
	if ((thisvsz > argvsz)||(thisvsz < argvsz))
		return true;
	else {
		for (slint k=(thisvsz-1);k>=0;--k)
			if (arg[k]!=cthis[k])
				return true;
		return false;
	}
}

bool operator >= (const uint_num_t& arg) const {
	const uint_num_t& cthis = (*this);
	const usint thisnsz = ceros_a_la_izqda();
	const usint thisvsz = (cthis.size())-thisnsz;
	const usint argnsz = arg.ceros_a_la_izqda();
	const usint argvsz = arg.size()-argnsz;

	if (thisvsz > argvsz) return true;
	else if (thisvsz < argvsz) return false;

	for (usint k=0;k<thisvsz;++k) {
		if ((cthis[k] > arg[k])) return true;
		else if ((cthis[k] < arg[k])) return false;
	}
	return false;
}

bool operator <= (const uint_num_t& arg) const {
	const uint_num_t& cthis = (*this);
	const usint thisnsz = ceros_a_la_izqda();
	const usint thisvsz = (cthis.size())-thisnsz;
	const usint argnsz = arg.ceros_a_la_izqda();
	const usint argvsz = arg.size()-argnsz;
	if (thisvsz < argvsz) return true;
	else if (thisvsz > argvsz) return false;
	for (usint k=0;k<thisvsz;++k) {
		if ((cthis[k] < arg[k])) return true;
		else if ((cthis[k] > arg[k])) return false;
	}
	return false;
}

bool operator >  (const uint_num_t& arg ) const {
	const uint_num_t& cthis = (*this);
	const usint thisnsz = ceros_a_la_izqda();
	const usint thisvsz = (cthis.size())-thisnsz;
	const usint argnsz = arg.ceros_a_la_izqda();
	const usint argvsz = arg.size()-argnsz;
	if (thisvsz > argvsz) return true;
	else if (thisvsz < argvsz) return false;

	for (usint k=0;k<thisvsz;++k) {
		if ((cthis[k] > arg[k])) return true;
		else if ((cthis[k] < arg[k])) return false;
	}
	return false;
}

bool operator <  (const uint_num_t& arg) const {
	const uint_num_t& cthis = (*this);
	const usint thisnsz = ceros_a_la_izqda();
	const usint thisvsz = (cthis.size())-thisnsz;
	const usint argnsz = arg.ceros_a_la_izqda();
	const usint argvsz = arg.size()-argnsz;

	if (thisvsz < argvsz) return true;
	else if (thisvsz > argvsz) return false;
	for (usint k=0;k<thisvsz;++k) {
		if ((cthis[k] < arg[k])) return true;
		else if ((cthis[k] > arg[k])) return false;
	}
	return false;
}

		/************************************/
		/*									*/
		/*		OPERACIONES ARITMETICAS		*/
		/*									*/
		/************************************/

uint_num_t operator + (const uint_num_t& arg) const {

	const uint_num_t& cthis = (*this);
	pardigs_t<B> tempt ;
	const bool cthis_is_max = (cthis>=arg);
	uint_num_t<B> cpyarg(arg);
	uint_num_t<B> cpythis(cthis);
	cpythis.reduce();
	cpyarg.reduce();
	uint_num_t<B> * pmax = ((cthis_is_max)?(&cpythis):(&cpyarg));
	uint_num_t<B> & max = (*pmax);
	uint_num_t<B> * pmin = ((cthis_is_max)?(&cpyarg):(&cpythis));
	uint_num_t<B> & min = (*pmin);

	dig carry(0);

	int M = (max.size())-1;
	int m = (min.size())-1;
	for ( ; !(m<0) ; --M,--m) {
		tempt.p_uds(max[M]);
		tempt.p_decs(dig_t<B>(0));
		tempt += min[m];
		tempt += carry;
		carry =tempt.g_decs();
		max[M]=tempt.g_uds();
	}
	for ( ; !(M<0) ; --M) {
		tempt.p_uds(max[M]);
		tempt.p_decs(dig_t<B>(0));
		tempt += carry;
		carry =tempt.g_decs();
		max[M]=tempt.g_uds();
	}

	if (carry!=dig(0)) {
		max.push_front(carry);
	}

	max.aux =  pardigs();
	return max;
}

uint_num_t operator - (const uint_num_t& arg) const {
	uint_num_t ret(*this);
	ret.reduce();
	const size_t szret = ret.size();
	uint_num_t cpy(arg.minus(ret.size()));
	ret += cpy;
	if (ret.size() > szret) {
		ret.erase(0,1);
	}
	ret.reduce();
	return ret;	
}

// Utilizamos una funcion uint_num_t* dig_t
uint_num_t operator * (const uint_num_t& arg) const {
	const uint_num_t& cthis = (*this);
	cthis.reduce();
	uint_num_t multtemp;
	uint_num_t sumatemp;
	uint_num_t cadena_de_ceros;
	const int argsz = arg.size();
	const int argmsb = argsz-2;

	multtemp = cthis*arg[argsz-1];
	sumatemp += multtemp;

	for (int j = argmsb ; j >= 0 ; --j) {
		multtemp = cthis*arg[j];
		multtemp &= cadena_de_ceros;
		sumatemp += multtemp;
		cadena_de_ceros.push_back(dig(0));
	}	

	return sumatemp;
}

uint_num_t operator / (const uint_num_t& arg) const {
	const uint_num_t & cthis = (*this);
	uint_num_t dvndo_int(cthis); //Siempre ser?? positivo
	dvndo_int.reduce();
	uint_num_t rem(dvndo_int);
	rem.reduce();
	uint_num_t dvsor_int(arg);//Siempre ser?? positivo
	dvsor_int.reduce();

	const usint cssor = dvsor_int.ceros_a_la_drcha(); // ceros que tienen valor y por los que dividir 
	// divisor y dividendo
	uint_num_t dvndo_fra(dvndo_int);
	
	if (dvndo_int.size()>=dvsor_int.size()) {
		dvndo_fra.erase(0,dvndo_int.size()-cssor);
		if (dvndo_int != uint_num_t(dig(0))) {
			dvndo_int.erase(dvndo_int.size()-cssor,cssor);// division por una potencia de B, /B^cssor
		}
		dvndo_int.reduce();
		if (dvsor_int != uint_num_t(dig(0))) {
			dvsor_int.erase(dvsor_int.size()-cssor,cssor);// division por una potencia de B  /B^cssor
		}
		uint_num_t dvsor_fra(dvsor_int);
		dvsor_fra.erase(0,dvsor_int.size()-cssor);
		dvsor_int.reduce();
	}
	else {
		dvndo_int = uint_num_t(dig(0));
		return dvndo_int;
	}
	//dvndo_fra.reduce();//dvndo_fra.reduce_fra() HAY QUE HACERLO
	const int szndo		= dvndo_int.size();
	const int lsb_ndo   = szndo-1;
	const int msb_ndo	= 0;
	const int szsor     = dvsor_int.size();
	const int lsb_sor   = szsor-1;
	const int msb_sor   = 0;

	// hemos dividido por los ceros del divisor (por una potencia de B)
	// tanto divisor como dividendo, obteniendo dvndo_int y dvsor_int como
	// cocientes enteros.
	div_uno(rem,dvndo_int,dvsor_int,szndo,szsor);
	// ahora hacemos lo mismo con el cociente de las potencias de B del
	// dividendo obteniendo dvndo_fra

	/* *
		RemReal = RemObtenido*(B^cssor) + Dvndo_fra

		rem = rem.insert(rem.size()-1,cssor,0);
		rem += dvndo_fra;
	* */
	//////////if (sgn_ndo!=sgn_sor) dvndo_int.mC_B();
	// rehacer el resto tomando en cuenta los ceros quitados
	// acomodar el formato al signo de la operacion
	// determinar el signo de la operacion
	return dvndo_int;
}

uint_num_t operator % (const uint_num_t& arg) const {
	const uint_num_t & cthis = (*this);
	uint_num_t dvndo_int(cthis); //Siempre ser?? positivo
	dvndo_int.reduce();
	uint_num_t rem(dvndo_int);
	rem.reduce();
	uint_num_t dvsor_int(arg);//Siempre ser?? positivo
	dvsor_int.reduce();
	dvndo_int/=dvsor_int;
	dvndo_int*=dvsor_int;
	rem -= dvndo_int;
	return rem;
}

uint_num_t operator * (pardigs a) const {
	const uint_num_t & cthis = (*this);
	pardigs 		temp;
	dig  			carry=0;
	uint_num_t		ret(*this);
	for ( ssint k=(cthis.size()-1) ; k >= 0  ; --k ) {
		temp = (pardigs(cthis[k]))*(pardigs(a.g_first()));
		temp += carry;
		ret[k]= temp.g_first();
		carry=temp.g_second();
	}
	if (carry != 0)
		ret.insert(0,carry);
	ret.reduce();
	carry = 0;
	uint_num_t ret2(ret);
	for ( ssint k=((cthis.size())-1) ; k >= 0  ; --k ) {
		temp = pardigs(cthis[k])*pardigs(a.g_second());
		temp += carry;
		ret2.erase(0,k-1);
		ret2 += temp.g_first();//???
		carry = temp.g_second();
	}
	ret += ret2;
	if (carry != 0)
		ret.insert(0,carry);
	ret.reduce();

	return ret;
}

//	uint_num_toperator / (pardigs) const;
//	uint_num_toperator % (pardigs) const;

uint_num_t operator + (dig arg) const {
	uint_num_t ret(*this);
	ret.reduce();
	pardigs tempt;
	const usint szt = ret.size();
	ssint k = szt-1;
	dig carry;
	
	tempt.p_uds(ret[k]);
	tempt += arg;
	ret[k] = tempt.g_uds();
	carry = tempt.g_decs();
	tempt.p_decs(dig(0));
	
	if (szt>=1) {
		for ( k=szt-2 ; k>=0 ; --k) {
			tempt.p_uds(ret[k]);
			tempt += carry;
			ret[k]=tempt.g_uds();
			carry =tempt.g_decs();
			tempt.p_decs(dig(0));
		}
	}

	ret.push_front(carry) ;
	ret.aux = pardigs();
	ret.reduce();
	return ret;
}

uint_num_t operator - (dig arg) const {
	uint_num_t ret(*this);
	ret.reduce();
	if (arg == dig(0)) return ret;
	uint_num_t cpy(uint_num_t(arg).minus(ret.size()));
	pardigs tempt;
	pardigs tempa;
	sint szt = ret.size();
	sint k = szt-1;
	tempt.p_uds(ret[k]);
	tempt.p_decs(dig(0));
	tempa.p_uds(cpy[k]);
	tempa.p_decs(dig(0));
	tempt += tempa;
	ret[k] =tempt.g_uds();
	dig carry(tempt.g_decs());
	--k;
	for ( ; k >= 0 ; --k) {
		tempt.p_uds(ret[k]);
		tempt += cpy[k];
		tempt += carry;
		carry =tempt.g_decs();
		ret[k] =tempt.g_uds();
	}

	ret.reduce();
	ret.aux =  pardigs();
	return ret;
}

uint_num_t operator * (dig a) const {
	const uint_num_t & cthis = (*this);
	pardigs 	temp;
	dig  		carry=0;
	const int	sz = cthis.size();
	const int	lsb = sz - 1; 
	uint_num_t ret(*this);
	for ( int k=lsb ; k >= 0 ; --k ) {
		temp = pardigs(dig(0),cthis[k])*a;
		temp += carry;
		ret[k]= temp.g_uds();
		carry=temp.g_decs();
	}
	if (carry != 0) {
		ret.push_front(carry);
	}
	ret.reduce();
	return ret;
}

		/************************************/
		/*									*/
		/*		OPERACIONES ARITMETICAS		*/
		/*		CON ASIGNACION				*/
		/*									*/
		/************************************/

const uint_num_t & operator += (const uint_num_t&arg) {
	uint_num_t & cthis = (*this);
	cthis.reduce();
	pardigs_t<B> tempt ;
	const bool cthis_is_max = (cthis>=arg);
	uint_num_t<B> cpyarg(arg);
	cpyarg.reduce();
	uint_num_t<B> * pmax = ((cthis_is_max)?(&cthis):(&cpyarg));
	uint_num_t<B> & max = (*pmax);
	uint_num_t<B> * pmin = ((cthis_is_max)?(&cpyarg):(&cthis));
	uint_num_t<B> & min = (*pmin);
	
	dig carry(0);
	
	int M = (max.size())-1;
	int m = (min.size())-1;
	cthis.aux = pardigs();
	for ( ; !(m<0) ; --M,--m) {
		tempt.p_uds(max[M]);
		tempt.p_decs(dig_t<B>(0));
		tempt += min[m];
		tempt += carry;
		carry =tempt.g_decs();
		max[M]=tempt.g_uds();
	}
	for ( ; !(M<0) ; --M) {
		tempt.p_uds(max[M]);
		tempt.p_decs(dig_t<B>(0));
		tempt += carry;
		carry =tempt.g_decs();
		max[M]=tempt.g_uds();
	}

	if (carry!=dig(0)) {
		max.push_front(carry);
	}

	if ((&cthis)!=(&max)) {
		cthis = (max.reduce());
	}
	else {
		cthis.reduce();
	}
	cthis.aux =  pardigs();
	return cthis;
}

const uint_num_t & operator -= (const uint_num_t& arg) {
	uint_num_t & ret = (*this);
	ret.reduce();
	const size_t szret = ret.size();
	uint_num_t cpy(arg.minus(ret.size()));
	//cpy.reduce();
 	ret += cpy;
	if (ret.size() > szret) {
		ret.erase(0,1);
	} 
	ret.reduce();
	return ret;
}

const uint_num_t& operator *= (const uint_num_t& arg) {
	uint_num_t & cthis = (*this);
	cthis.reduce();
	uint_num_t multtemp;
	uint_num_t sumatemp;
	uint_num_t cadena_de_ceros;
	const int argsz = arg.size();
	const int argmsb = argsz-2;


	multtemp = cthis*arg[argsz-1];
	sumatemp += multtemp;

	for (int j = argmsb ; j >= 0 ; --j) {
		multtemp = cthis*arg[j];
		multtemp &= cadena_de_ceros;
		sumatemp += multtemp;
		cadena_de_ceros.push_back(dig(0));
	}	
	cthis = sumatemp;	
	return cthis;
}

inline uint_num_t substr ( size_t pos , size_t n ) const {
	const basic_num & cthis = (*this);
	cthis.nbstr::substr(pos,n);
	return (*this);
}

const uint_num_t & operator /= (const uint_num_t& arg) {
	uint_num_t & cthis = (*this);
	uint_num_t dvndo_int(*this); //Siempre ser?? positivo
	dvndo_int.reduce();
	uint_num_t rem(dvndo_int);
	rem.reduce();
	uint_num_t dvsor_int(arg);//Siempre ser?? positivo
	dvsor_int.reduce();

	const usint cssor = dvsor_int.ceros_a_la_drcha(); // ceros que tienen valor y por los que dividir 
	// divisor y dividendo
	uint_num_t dvndo_fra(dvndo_int);
	
	if (dvndo_int.size()>=dvsor_int.size()) {
		dvndo_fra.erase(0,dvndo_int.size()-cssor);
		if (dvndo_int != uint_num_t(dig(0))) {
			dvndo_int.erase(dvndo_int.size()-cssor,cssor);// division por una potencia de B, /B^cssor
		}
		dvndo_int.reduce();
		if (dvsor_int != uint_num_t(dig(0))) {
			dvsor_int.erase(dvsor_int.size()-cssor,cssor);// division por una potencia de B  /B^cssor
		}
		uint_num_t dvsor_fra(dvsor_int);
		dvsor_fra.erase(0,dvsor_int.size()-cssor);
		dvsor_int.reduce();
	}
	else {
		dvndo_int = uint_num_t(dig(0));
		cthis = dvndo_int;
		return cthis;
	}
	//dvndo_fra.reduce();//dvndo_fra.reduce_fra() HAY QUE HACERLO
	const int szndo		= dvndo_int.size();
	const int lsb_ndo   = szndo-1;
	const int msb_ndo	= 0;
	const int szsor     = dvsor_int.size();
	const int lsb_sor   = szsor-1;
	const int msb_sor   = 0;

	// hemos dividido por los ceros del divisor (por una potencia de B)
	// tanto divisor como dividendo, obteniendo dvndo_int y dvsor_int como
	// cocientes enteros.
	div_uno(rem,dvndo_int,dvsor_int,szndo,szsor);
	// ahora hacemos lo mismo con el cociente de las potencias de B del
	// dividendo obteniendo dvndo_fra

	/* *
		RemReal = RemObtenido*(B^cssor) + Dvndo_fra

		rem = rem.insert(rem.size()-1,cssor,0);
		rem += dvndo_fra;
	* */
	//////////if (sgn_ndo!=sgn_sor) dvndo_int.mC_B();
	// rehacer el resto tomando en cuenta los ceros quitados
	// acomodar el formato al signo de la operacion
	// determinar el signo de la operacion
	cthis=dvndo_int;
	return cthis;
}

const uint_num_t& operator %= (const uint_num_t& arg) {
	uint_num_t & cthis = (*this);
	uint_num_t dvndo_int(cthis); //Siempre ser?? positivo
	dvndo_int.reduce();
	uint_num_t rem(dvndo_int);
	rem.reduce();
	uint_num_t dvsor_int(arg);//Siempre ser?? positivo
	dvsor_int.reduce();
	dvndo_int/=dvsor_int;
	dvndo_int*=dvsor_int;
	rem -= dvndo_int;
	cthis = rem;
	return cthis;
}

const uint_num_t & operator *= (pardigs a) {
	uint_num_t	    	cthis = (*this);
	uint_num_t & 		ret = (*this);
	ret *= a.g_uds();
	cthis.push_back(dig(0));
	ret += cthis * a.g_decs();
	ret.reduce();
	return ret;
}

const uint_num_t & operator += (dig arg) {
	uint_num_t & cthis = (*this);
	cthis.reduce();
	dig		carry(0);
	pardigs tempt;
	
	int k =  cthis.size() ;
	tempt.p_uds(cthis[k-1]);
	tempt += arg;
	cthis[k-1]=tempt.g_uds();
	carry = tempt.g_decs();
	--k;
	for (; k > 0 ; --k) {
		tempt = pardigs();
		tempt += carry;
		tempt += cthis[k-1];
		cthis[k-1]=tempt.g_uds();
		carry = tempt.g_decs();
	}
	
	if (carry != dig(0)) cthis.push_front(carry);
	cthis.reduce();
	return cthis;
}

const uint_num_t & operator -= (dig arg) {
	uint_num_t & cthis = (*this);
	cthis.reduce();
	if (arg == dig(0)) return cthis;
	uint_num_t cpy(uint_num_t(arg).minus(cthis.size()));
	pardigs tempt;
	pardigs tempa;
	sint szt = cthis.size();
	sint k = szt-1;
	tempt.p_uds(cthis[k]);
	tempt.p_decs(dig(0));
	tempa.p_uds(cpy[k]);
	tempa.p_decs(dig(0));
	tempt += tempa;
	cthis[k] =tempt.g_uds();
	dig carry(tempt.g_decs());
	--k;
	for ( ; k >= 0 ; --k) {
		tempt.p_uds(cthis[k]);
		tempt += cpy[k];
		tempt += carry;
		carry =tempt.g_decs();
		cthis[k] =tempt.g_uds();
	}

	cthis.reduce();
	cthis.aux =  pardigs();
	return cthis;
}

const uint_num_t & operator *= (dig arg) {
	uint_num_t & cthis = (*this);
	pardigs temp;
	dig  	carry=0;
	cthis.reduce();
	for ( ssint k=((cthis.size())-1) ; k >= 0 ; --k ) {
		temp.p_uds(cthis[k]);
		temp *= arg;
		temp += carry;
		cthis[k]= temp.g_uds();
		carry=temp.g_decs();
		temp.p_decs(dig(0));
	}
	if (carry != 0)	push_front(carry);
	cthis.reduce();
	return cthis;
}

		/****************************/
		/*							*/
		/*	COMPLEMENTO A BASE Y	*/
		/*		BASE MENOS 1		*/
		/*							*/
		/****************************/

uint_num_t operator - () const {
	uint_num_t cpy(*this);
	cpy.reduce();
	crstriterator start = cpy.rend();
	rstriterator  it    = cpy.rbegin();
	for ( ; it != start ; ++it ) {
		(*it) = (!(*it));
	}
	cpy.reduce();
	it = cpy.rbegin();
	cpy.aux.p_uds(*it);
	cpy.aux.p_decs(dig());
	cpy.aux += pd_1<B>();
	(*it) = cpy.aux.g_uds();
	++it;
	if ((cpy.aux.g_decs())!= dig(0)) {
		for ( ; it != start ; ++it ) {
			cpy.aux.p_uds(cpy.aux.g_decs());
			cpy.aux.p_decs(0);
			
			if (cpy.aux == pardigs()) break;
			cpy.aux += pardigs(*it);
			(*it) = cpy.aux.g_uds();
		}
		cpy.push_front(cpy.aux.g_uds());
		cpy.push_front(cpy.aux.g_decs());
	}

	cpy.aux = pardigs();
	cpy.reduce();
	return cpy;
}


uint_num_t minus (size_t sz) const {
	uint_num_t cpy(*this);
	cpy.reduce();
	if (cpy.size() < sz) {
		const int tm = sz - cpy.size();
		for(int i=0; i<tm ; ++i) {
			cpy.push_front(dig(0));
		}
	}
	else if (cpy.size() > sz) {
		cpy.erase(0,1);
	}
	crstriterator start = cpy.rend();
	rstriterator  it    = cpy.rbegin();
	for ( ; it != start ; ++it ) {
		(*it) = (!(*it));
	}
	it = cpy.rbegin();
	cpy.aux.p_uds(*it);
	cpy.aux.p_decs(dig(0));
	cpy.aux += pd_1<B>();
	(*it) = cpy.aux.g_uds();
	++it;
	if ((cpy.aux.g_decs())!= dig(0)) {
		for ( ; it != start ; ++it ) {
			cpy.aux.p_uds(cpy.aux.g_decs());
			cpy.aux.p_decs(0);
			
			if (cpy.aux == pardigs()) break;
			cpy.aux += pardigs(*it);
			(*it) = cpy.aux.g_uds();
		}
		cpy.push_front(cpy.aux.g_uds());
		cpy.push_front(cpy.aux.g_decs());
	}

	cpy.aux = pardigs();
	if (cpy.size() < sz) {
		const int tm = sz - cpy.size();
		for(int i=0; i<tm ; ++i) {
			cpy.push_front(dig(B-1));
		}
	}
	else if (cpy.size() > sz) {
		cpy.erase(0,1);
	}
	//cpy.reduce();
	return cpy;
}


uint_num_t operator ! () const {
	uint_num_t cpy(*this);
	const striterator fin = cpy.end();
	striterator  it = cpy.begin();
	for ( ; it != fin ; ++it )
		(*it) = (!(*it));
	cpy.aux = pardigs();
	cpy.reduce();
	return cpy;
}

		/****************************/
		/*							*/
		/*		 MODIFICADOR		*/
		/*	COMPLEMENTO A BASE Y	*/
		/*		BASE MENOS 1		*/
		/*							*/
		/****************************/

const uint_num_t & mC_B () {
	uint_num_t & cpy = (*this);
	cpy.reduce();
	crstriterator start = cpy.rend();
	rstriterator  it    = cpy.rbegin();
	for ( ; it != start ; ++it ) {
		(*it) = (!(*it));
	}
	cpy.reduce();
	it = cpy.rbegin();
	cpy.aux.p_uds(*it);
	cpy.aux.p_decs(dig());
	cpy.aux += pd_1<B>();
	(*it) = cpy.aux.g_uds();
	++it;
	if ((cpy.aux.g_decs())!= dig(0)) {
		for ( ; it != start ; ++it ) {
			cpy.aux.p_uds(cpy.aux.g_decs());
			cpy.aux.p_decs(0);
			
			if (cpy.aux == pardigs()) break;
			cpy.aux += pardigs(*it);
			(*it) = cpy.aux.g_uds();
		}
		cpy.push_front(cpy.aux.g_uds());
		cpy.push_front(cpy.aux.g_decs());
	}

	cpy.aux = pardigs();
	cpy.reduce();
	return cpy;
}

const uint_num_t & mC_Bm1 () {
	uint_num_t & cpy = (*this);
	const striterator fin = cpy.end();
	striterator  it = cpy.begin();
	for ( ; it != fin ; ++it )
		(*it) = (!(*it));
	cpy.aux = pardigs();
	cpy.reduce();
	return cpy;
}

					/****************************/
					/*							*/
					/*  	   ABSOLUTO			*/
					/*							*/
					/****************************/

inline uint_num_t abs () const {
	return (*this);
}

inline const uint_num_t & m_abs () {
	uint_num_t & cthis = (*this);
	return cthis;
}

							/****************************/
							/*							*/
							/*	DIVIDIR ENTRE BASE o 2	*/
							/*							*/
							/****************************/

uint_num_t divB () const {
	uint_num_t cpy(*this);
	cpy.reduce();
	cpy.m_abs();
	cpy.cthis.erase(0,1);
	cpy.reduce();
	return cpy;
}

dig remB () const {
	uint_num_t cpy(*this);
	cpy.reduce();
	return cpy[0];
}

const uint_num_t & m_divB() {
	uint_num_t & cpy = (*this);
	cpy.reduce();
	cpy.cthis.erase(0,1);
	cpy.reduce();
	return cpy;
}

dig m_remB() {
	uint_num_t& cpy = (*this);
	cpy.reduce();
	return cpy[0];
}

uint_num_t div2 () const {
	uint_num_t & cthis = (*this);
	uint_num_t dvndo_int(cthis.abs());
	dvndo_int.reduce();
	uint_num_t rem(dvndo_int);
	const dig dos = 2;

	uint_num_t dvsor_int(dos);

	const usint cssor = ((B==2)?(1):(0));

	uint_num_t dvndo_fra(dvndo_int.substr(0,cssor));
	if (B==2) dvsor_int[0]=1;// division por una potencia de B

	dvndo_int.reduce();
	dvndo_fra.reduce();

	const usint longtndo  = dvndo_int.size();
	const usint longtndo2 = dvndo_fra.size();
	const usint longtsor  = 1;
	const usint longsor   = 0;

	// hemos dividido por los ceros del divisor (por una potencia de B)
	// tanto divisor como dividendo, obteniendo dvndo_int y dvsor_int como
	// cocientes enteros.
	div_uno(rem,dvndo_int,dvsor_int,longtndo,longsor);
	// ahora hacemos lo mismo con el cociente de las potencias de B del
	// dividendo obteniendo dvndo_fra

	/* *
		RemReal = RemObtenido*B^cssor + Dvndo_fra

		rem = rem.cthis.insert(0,cssor,0);
		rem += dvndo_fra;
	* */
	/////////////////if (sgn==vminus) dvndo_int.mC_B();
	// rehacer el resto tomando en cuenta los ceros quitados
	// acomodar el formato al signo de la operacion
	// determinar el signo de la operacion
	return dvndo_int;
}

dig rem2 () const {
	uint_num_t & cthis = (*this);
	uint_num_t cpy = cthis.reduce();
	cpy.reduce();
	if ((B%2)==1) {
		if (cpy.size()==1)
			return dig::Rem2(cpy[0]);
		else {
			usint paridad = 0;
			for ( usint k=0 ; k < cpy.size() ; ++k )
				paridad += dig::Dig2UInt(dig::Rem2(cpy[k]));
			paridad %= 2;
			return dig(paridad);
		}
	}
	else {
		return dig::Rem2<B>(cpy[0]);
	}
}

const uint_num_t & m_div2() {
	uint_num_t & cthis = (*this);
	cthis.reduce();
	uint_num_t & dvndo_int = (*this);
	uint_num_t rem(dvndo_int);
	const dig dos = 2;

	uint_num_t dvsor_int(dos);

	const usint cssor = ((B==2)?(1):(0));

	uint_num_t dvndo_fra(dvndo_int.substr(0,cssor));
	if (B==2) dvsor_int[0]=1;// division por una potencia de B

	dvndo_int.reduce();
	dvndo_fra.reduce();

	const usint longtndo  = dvndo_int.size();
	const usint longtndo2 = dvndo_fra.size();
	const usint longtsor  = 1;
	const usint longsor   = 0;

	// hemos dividido por los ceros del divisor (por una potencia de B)
	// tanto divisor como dividendo, obteniendo dvndo_int y dvsor_int como
	// cocientes enteros.
	div_uno(rem,dvndo_int,dvsor_int,longtndo,longsor);
	// ahora hacemos lo mismo con el cociente de las potencias de B del
	// dividendo obteniendo dvndo_fra

	/* *
		RemReal = RemObtenido*B^cssor + Dvndo_fra

		rem = rem.insert(0,cssor,0);
		rem += dvndo_fra;
	* */
	/////////////////if (sgn==vminus) dvndo_int.mC_B();
	// rehacer el resto tomando en cuenta los ceros quitados
	// acomodar el formato al signo de la operacion
	// determinar el signo de la operacion
	return dvndo_int;
}

dig m_rem2() {
	uint_num_t & cthis = (*this);
	cthis.reduce();
	uint_num_t & cpy = (*this);
	if (B%2==1) {
		if (cpy.size()==1)
			return dig::Rem2(cpy[0]);
		else {
			usint paridad = 0;
			for ( usint k=0 ; k < cpy.size() ; ++k )
				paridad += dig::Dig2UInt(dig::Rem2(cpy[k]));
			paridad %= 2;
			return dig(paridad);
		}
	}
	else {
		return dig::Rem2<B>(cpy[0]);
	}
}

dig	remBm1() const {
	uint_num_t cthis(*this),suma;
	cthis.abs();
	cthis.reduce();
	suma.reduce();
	suma.insert(0,1,0);
	suma.erase(0,(cthis.size())-1);
	do {
		for ( usint i = 0 ; i < cthis.size() ; ++i ) {
			suma += cthis[i];
			suma.reduce();
		}
	} while (suma.size()>1);

	if ((suma[0]==0)||(suma[0]==(B-1))) return 0;
	else return suma[0];
}

// dig	 			remBm1p()		;
// uint_num	 		divBm1() 	const;
// const uint_num	& 	divBm1p()		;

private:

//		inline void	div3_step(pair< n2digs_t , usint > & S) const;
//		inline void div3p_step(pair< n2digs_t , usint > & S);
//		inline void	div7_step(pair< n2digs_t , usint > & S) const;
//		inline void div7p_step(pair< n2digs_t , usint > & S);
public:
	inline pardigs	g_aux() const {
		basic_num & cthis = (*this);
		return cthis.aux;
	}
	inline void	p_aux(pardigs arg) {
		aux=arg;
		return;
	}

private:

		/****************************/
		/*							*/
		/*		Division Generica	*/
		/*							*/
		/****************************/


inline void	div_gen_step(	const uint_num_t & dvsor,
							uint_num_t & rem,
							uint_num_t & coc,
							usint & ndig) const {
	const uint_num_t & cthis = (*this);
	const int szsor = dvsor.size();
	const int maxpossor = szsor-1;
	const int szndo = cthis.size();
	const int maxposndo = szndo-1;
	const uint_num_t & dvndo = cthis;
	const uint szrem = rem.size();
	if (ndig==0) ndig = szrem;
	if (rem < dvsor) {
		coc.push_back(dig(0));
		coc.reduce();
	}
	else if (rem == dvsor) {
		coc.push_back(dig(1));
		coc.reduce();
		rem.erase(0,rem.size()-1);
		rem[0]=dig(0);
	}
	else {
			pardigs dighrem;
			if ( szrem > szsor ) dighrem = pardigs(rem[0],rem[1]) ;
			else dighrem = pardigs(dig(0),rem[0]) ;
			pardigs dighsor        = pardigs(dig(0),dvsor[0]) ;
			pardigs & digcocprueba = dighrem ;
			digcocprueba /= dighsor ;
			if (digcocprueba > pd_Bm1<B>()) { 
				digcocprueba = pd_Bm1<B>();
			}
			uint_num_t remprueba(dvsor) ;
			remprueba *= digcocprueba;
			for ( pardigs ix(0,0)  ; ix < pardigs(1,0) ; ix += pardigs(0,1) ) {
				if ( remprueba > rem ) {
					--digcocprueba;
					remprueba -= dvsor;
				}
				else {
					rem -= remprueba;
					coc.push_back(digcocprueba.g_uds());
					coc.reduce();
					break;
				}
			}
	}
	if(dvndo.size()> ndig) { 
		rem.push_back(dvndo[ndig]);
	}
	rem.reduce();
	++ndig;
	return;
}

		/************************************/
		/*									*/
		/*		Un Paso de Division Simple	*/
		/*									*/
		/************************************/

public:

inline bool es_cero() const {
	bool escero = (size()==0);
	if (escero) return true;
	escero = (size()==1)and(operator[](0)==dig_t<B>(0));
	if (escero) return true;
	return false;
}

inline bool no_es_cero() const {
	bool noescero = (size()>1);
	if (noescero) return true;
	noescero = (size()==1)and(operator[](0)!=dig_t<B>(0));
	if (noescero) return true;
	return false;
}

private:

inline void div_uno(uint_num_t& rem ,
					uint_num_t& dvndo,
					uint_num_t& dvsor,
					const usint szndo,
					const usint szsor) const {
	const uint_num_t& cthis = (*this);
	rem = dvndo;
	if (dvsor.es_cero()) { // caso de division por 0
		return;
	}
	else if ((dvndo.es_cero())or(szndo < szsor)) { // caso de 0 dividido por !=0 ?? caso de cociente 0
		rem = dvndo;
		dvndo.erase(0,(cthis.size())-2);
		dvndo[0] = dig(0);
		return;
		// rem=dvndo; hecho por defecto
	}
	else if (dvndo==dvsor) { // caso de dividir por si mismo
		dvndo.clear();
		rem.clear();
		dvndo.push_front(dig(1));
		rem.push_front(dig(0));			
		return;
	}
	else if ((szsor==1)&&(dvsor[0]==1)) { // caso de dividir por potencias de B (1)
		//dvndo;
		if (rem.size() > 1){
			rem.erase(0,rem.size()-2);
		}
		rem[0]=dig(0);
		return;
	}
	else if ((szndo == szsor) && (dvndo < dvsor)) {
		rem = dvndo;
		dvndo.clear();
		dvndo.push_front(dig(0));
		return;
	}
	else { 
		// ((long_dvndo > long_dvsor) or (dvndo > dvsor))
		// algoritmo de resta general
		// implementar div_step pasamos (resto,cociente,i,dividendo,divisor) devuelve (resto,cociente,i,dividendo,divisor)
		// se puede hacer con una tupla
		// dvndo;
		rem   = dvndo;
		rem.reduce();
		rem.erase(szsor,szndo-szsor);
		uint_num_t coc(dig(0));
		usint ndig = 0;
		do {
			div_gen_step(dvsor,rem,coc,ndig);
		} while ( ndig <= szndo );
		dvndo = coc;
		return;
	}
}
//END PRIVATE


		/****************************/
		/*							*/
		/*		Division Euclidea	*/
		/*							*/
		/****************************/

public:

pair< uint_num_t, uint_num_t> EuclidDiv (const uint_num_t & arg) const {
	const uint_num_t & cthis = (*this);
	/////////////////const sign_e sgn_ndo = signo;
	/////////////////const sign_e sgn_sor = arg.signo;
	uint_num_t dvndo_int = cthis;
	dvndo_int.reduce();
	uint_num_t dvsor_int = arg.abs();
	dvsor_int.reduce();

	uint_num_t rem(dvndo_int);

	const usint cssor = dvsor_int.ceros_a_la_drcha(); //???

	uint_num_t dvndo_fra(dvndo_int.substr(0,cssor));
	dvsor_int.erase(0,cssor);// division por una potencia de B

	dvsor_int.reduce();
	dvndo_fra.reduce_fracc();// reduce 0s a la derecha

	const usint longtndo  = dvndo_int.size();
	const usint longtndo2 = dvndo_fra.size();
	const usint longtsor  = dvsor_int.size();
	const usint longsor   = longtsor;

	// hemos dividido por los ceros del divisor (por una potencia de B)
	// tanto divisor como dividendo, obteniendo dvndo_int y dvsor_int como
	// cocientes enteros.
	div_uno(rem,dvndo_int,dvsor_int,longtndo,longsor);
	// ahora hacemos lo mismo con el cociente de las potencias de B del
	// dividendo obteniendo dvndo_fra

	/* *
		RemReal = RemObtenido*B^cssor + Dvndo_fra
	 * */
	rem = rem.insert(0,cssor,0);
	rem += dvndo_fra;

	//////////////////if (sgn_ndo != sgn_sor) dvndo_int.mC_B();
	// rehacer el resto tomando en cuenta los ceros quitados
	// acomodar el formato al signo de la operacion
	// determinar el signo de la operacion
	return make_pair(rem,dvndo_int);
}

pair< uint_num_t, const uint_num_t & > m_EuclidDiv (const uint_num_t & arg) {
	const uint_num_t & cthis = (*this);
	//////////////onst sign_e sgn_ndo = signo;
	//////////////const sign_e sgn_sor = arg.signo;
	cthis.absp();
	cthis.reduce();
	uint_num_t & dvndo_int = cthis;
	uint_num_t dvsor_int = arg.abs();
	dvsor_int.reduce();

	uint_num_t rem(dvndo_int);

	const usint cssor = dvsor_int.ceros_a_la_drcha(); //???

	uint_num_t dvndo_fra(dvndo_int.substr(0,cssor));
	dvsor_int.erase(0,cssor);// division por una potencia de B

	dvsor_int.reduce();
	dvndo_int.reduce();

	dvndo_fra.reduce_fracc();

	const usint longtndo  = dvndo_int.size();
	const usint longtndo2 = dvndo_fra.size();
	const usint longtsor  = dvsor_int.size();
	const usint longsor   = longtsor;

	// hemos dividido por los ceros del divisor (por una potencia de B)
	// tanto divisor como dividendo, obteniendo dvndo_int y dvsor_int como
	// cocientes enteros.
	div_uno(rem,dvndo_int,dvsor_int,longtndo,longsor);
	// ahora hacemos lo mismo con el cociente de las potencias de B del
	// dividendo obteniendo dvndo_fra

	/* *
		RemReal = RemObtenido*B^cssor + Dvndo_fra
	 * */
	rem = rem.insert(0,cssor,0);
	rem += dvndo_fra;

	/////////////////if (sgn_ndo != sgn_sor) dvndo_int.mC_B();
	// rehacer el resto tomando en cuenta los ceros quitados
	// acomodar el formato al signo de la operacion
	// determinar el signo de la operacion
	return make_pair(rem,dvndo_int);
}

		/************************************/
		/*									*/
		/*			PRE Y POST				*/
		/*									*/
		/************************************/

public:

const uint_num_t & operator ++ () {
	uint_num_t & cthis = (*this);
	cthis += dig(1);
	return cthis;
}

uint_num_t operator ++ (int) {
	uint_num_t cpThis(*this);
	uint_num_t & cthis = (*this);
	cpThis += dig(1);
	cthis = cpThis;
	return cpThis;
}

const uint_num_t & operator -- () {
	uint_num_t & cthis = (*this);
	cthis -= dig(1);
	return cthis;
}

uint_num_t operator -- (int) {
	uint_num_t cpThis(*this);
	uint_num_t & cthis = (*this);
	cpThis -= dig(1);
	cthis = cpThis;
	return cpThis;
}

		/****************************/
		/*							*/
		/*			REDUCE			*/
		/*							*/
		/****************************/

inline const uint_num_t & reduce() {
	uint_num_t & cthis = (*this);
	if (cthis.size()==0) {
		cthis = uint_num_t(dig(0));
		return cthis;
	}
	else if (cthis.size()==1) return cthis;
	else {
		const usint nsz = digs_no_significativos();
		if (nsz==0) return cthis;
		else {
			const usint pos = 0;
			if (nsz>0) cthis.erase(pos,nsz);
			return cthis;
		}
	}
}

inline uint_num_t reduce() const {
	const uint_num_t & cthis = (*this);
	uint_num_t cpyreducida(cthis);
		if (cpyreducida.size()==0) {
		cpyreducida = uint_num_t(dig(0));
		return cpyreducida;
	}
	else if (cpyreducida.size()==1) return cpyreducida;
	else {
		const usint nsz = cpyreducida.digs_no_significativos();
		if (nsz==0) return cpyreducida;
		else {
			const usint pos = 0;
			if (nsz>0) cpyreducida.erase(pos,nsz);
			return cpyreducida;
		}
	}
}

inline const uint_num_t & reduce_fracc() {
	uint_num_t & cthis = (*this);
	if (cthis.size()==0) {
		cthis = uint_num_t(dig(0));
		return cthis;
	}
	else if (cthis.size()==1) return cthis;
	else {
		const usint nsz = digs_fracc_no_significativos();
		if (nsz==0) return cthis;
		else {
			const usint pos = 0;
			cthis.erase(pos,nsz);
			return cthis;
		}
	}
}

inline uint_num_t reduce_fracc() const {
	const uint_num_t& cthis = (*this);
	uint_num_t cpyreducida(cthis);
		if (cpyreducida.size()==0) {
		cpyreducida = uint_num_t(dig(0));
		return cpyreducida;
	}
	else if (cpyreducida.size()==1) return cpyreducida;
	else {
		const usint nsz = cpyreducida.digs_fracc_no_significativos();
		if (nsz==0) return cpyreducida;
		else {
			const usint pos = 0;
			cpyreducida.erase(pos,nsz);
			return cpyreducida;
		}
	}
}

};

		/****************************/
		/*							*/
		/*		ISTREAM Y OSTREAM	*/
		/*							*/
		/****************************/

//uint#:dig:dig:#B
template<const uchint Base>
istream & operator >> (istream & is,uint_num_t<Base> & arg) {
	enum estado_e {e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13};
	vector<string> num(255);
	string sds;
	string num_digint;
	string num_base;
	usint numero_base_recogido 	= 0;
	usint ind_sds 				= 0;
	usint digint 				= 0;
	usint ind_num    			= 0;
	estado_e est_act 			= e0;
	char c;
	is >> sds;
	do {
		c = sds[ind_sds];
		switch (est_act) {
		case e0 :
			{
				num_digint.clear();
				num_base.clear();
				numero_base_recogido = 0;
				digint = 0;
				ind_num = 0;
			}
			if (c=='u') est_act = e1;
			break;

		case e1 :
			if (c=='i') est_act = e2;
			else est_act = e0;
			break;

		case e2 :
			if (c=='n') est_act = e3;
			else est_act = e0;
			break;

		case e3 :
			if (c=='t') est_act = e4;
			else est_act = e0;
			break;

		case e4 :
			if (c=='#') est_act = e5;
			else est_act = e0;
			break;

		case e5 :
			if ((c>='1')and(c<='9')) {
				num[ind_num].push_back(c-'0');
				est_act = e6;
			}
			else est_act=e0;
			break;
		case e6 :
			if ((c>='0')and(c<='9')) {
				num[ind_num].push_back(c-'0');
			}
			else if (c==':') {
				est_act=e7;
				++ind_num;
			}
			else if (c=='#') {
				est_act=e8;
				++ind_num;
			}
			else est_act=e0;
			break;
		case e7 :
			if ((c>='0')and(c<='9')) {
				est_act = e6;
				num[ind_num].push_back(c-'0');
			}
			else est_act = e0;
			break;
		case e8 :
			if (c=='B') {
				est_act = e9;
			}
			else est_act = e0;
			break;
		case e9 :
			if ((c<='9')and(c>='2')){
				est_act = e10;
				num_base.push_back(c-'0');
			}
			else if (c=='1') {
				est_act = e11;
				num_base.push_back(1);
			}
			else if (c==' ' || c=='\0')
				est_act = e12;
			else est_act=e0;
			break;
		case e10 :
			if ((c<='9')and(c>='0'))
				num_base.push_back(c-'0');
			else if(c==' ' || c=='\0')
				est_act = e12;
			else est_act = e0;
			break;
		case e11 :
			if ((c<='9')and(c>='0')) {
				est_act=e9;
				num_base.push_back(c-'0');
			}
			else if(c==' ' || c=='\0')
				est_act = e12;
			else est_act = e0;
			break;
		case e12 :
			for (uint k=0 ; k < num_base.size() ; ++k ) {
				numero_base_recogido *= 10;
				numero_base_recogido += num_base[k];
			}
			if (numero_base_recogido!=Base) est_act = e0;
			else est_act = e13;
		case e13 : break;
		default  : est_act=e0;
		}
		++ind_sds;
	} while ((est_act!=e13)and(c!='\0'));

	arg.clear();
	uchint numero;
	for (uchint j=0 ; j < ind_num ; ++j) {
		numero=0;
		for (uint k=0 ; k < num[j].size() ; ++k ) {
			numero *= 10;
			numero += num[j][k];
		}
		arg.push_back(dig_t<Base>(numero));
	}
	arg.p_aux(pardigs_t<Base>());
	return is;
}

template<const uchint Base>
ostream & operator << (ostream & os,const uint_num_t<Base> & arg) {
	usint sz = arg.size();
	os  << "uint#";
	for (int k=0 ; k<sz ; ++k) {
		if (k==0)
			os 	<< arg[k].Dig2Int();
		else
			os 	<< ":" << arg[k].Dig2Int();
	}
	os 	<<"#B"
		<< static_cast<int>(Base) ;
	return os;
}

/* resumen UINT_NUM_T:






   */

#endif
