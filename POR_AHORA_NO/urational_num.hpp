#ifndef POSITIVE_RATIONALS_NUM_HPP
#define POSITIVE_RATIONALS_NUM_HPP

#include "uint_num_t.hpp" // Base class: basic_num_t

typedef long double longdouble;

template<unsigned char B>
class positive_rational_num : public std::pair<uint_num_t<B>,uint_num_t<B>>
{	
	
	typedef uint_num_t<B> uint_num;
	typedef std::pair<uint_num,uint_num> fraction_t;
	typedef dig_t<B> dig;
	typedef pardigs_t<B> pardigs;
	typedef std::pair<pardigs,pardigs> parpardigs;
	typedef std::pair<ullint,ullint> parullint;
	
	
	typedef basic_num_t<B>										basic_num;
	typedef typename std::basic_string<dig>					nbstr;
	typedef typename nbstr::iterator							striterator;
	typedef typename nbstr::reverse_iterator					rstriterator;
	typedef typename nbstr::const_iterator						cstriterator;
	typedef typename nbstr::const_reverse_iterator			crstriterator;
	typedef typename basic_num::iterator						b_iterator;
	typedef typename basic_num::reverse_iterator				b_riterator;
	typedef typename basic_num::const_iterator				b_citerator;
	typedef typename basic_num::const_reverse_iterator		b_criterator;
	typedef typename uint_num::iterator						iterator;
	typedef typename uint_num::reverse_iterator				riterator;
	typedef typename uint_num::const_iterator					citerator;
	typedef typename uint_num::const_reverse_iterator		criterator;
	typedef n2digs_t<B>											n2digs;
	typedef spardigs_t<B>										spardigs;

	
	static const uint_num basic_0;
	static const uint_num basic_1;
	static const uint_num basic_Bm1;
	static const uint_num basic_B;	
	
private :
//	fraction_t m_num;
public:
//		CONSTRUTORES
	positive_rational_num()
		: fraction_t(basic_0,basic_0)	{}
	positive_rational_num(const basic_num_t<B> & E,const basic_num_t<B> & F) 
		: fraction_t(E,F) 	{}
	positive_rational_num(dig E,dig F)
		: fraction_t(uint_num(E),uint_num(F))	{}
	positive_rational_num(pardigs E,pardigs F)
		: fraction_t(uint_num(E),uint_num(F))	{}
	positive_rational_num(const uint_num & E,const uint_num & F)
		: fraction_t(uint_num(E),uint_num(F)) {}
	positive_rational_num(ullint E,ullint F)
		: fraction_t(uint_num(E),uint_num(F))	{}
	positive_rational_num(const positive_rational_num & alter)
		: fraction_t(alter)	{}
//		OPERADORES DE ASIGNACION
	const positive_rational_num & operator = (const fraction_t & E) {
		this->first = E.first;
		this->second = E.second;
		return (*this);
	}
	
	positive_rational_num & operator = (fraction_t & E) {
		this->first = E.first;
		this->second = E.second;
		return (*this);
	}
	
	const positive_rational_num & operator = (const pardigs & E) {
		this->first.clear();
		this->first.push_back(E.first);
		this->second.clear();
		this->second.push_back(E.second);
		return (*this);
	}
	
	positive_rational_num & operator = (pardigs & E) {
		this->first.clear();
		this->first.push_back(E.first);
		this->second.clear();
		this->second.push_back(E.second);
		return (*this);
	}
	
	const positive_rational_num & operator = (const parpardigs & E) {
		this->first.clear();
		this->first.push_back(E.first.first);
		this->first.push_front(E.first.second);
		this->second.clear();
		this->second.push_back(E.second.first);
		this->second.push_front(E.second.second);
		return (*this);
	}
	
	positive_rational_num & operator = (parpardigs & E) {
		this->first.clear();
		this->first.push_back(E.first.first);
		this->first.push_front(E.first.second);
		this->second.clear();
		this->second.push_back(E.second.first);
		this->second.push_front(E.second.second);
		return (*this);
	}
	
	const positive_rational_num & operator = (const parullint & E) {
		this->first.clear();
		this->first.push_back(dig(ullint(E.first)));
		this->second.clear();
		this->second.push_back(dig(ullint(E.second)));
		return (*this);
	}
	
	positive_rational_num & operator = (parullint & E)  {
		this->first.clear();
		this->first.push_back(dig(ullint(E.first)));
		this->second.clear();
		this->second.push_back(dig(ullint(E.second)));
		return (*this);
	}
	
	const positive_rational_num & operator = (const positive_rational_num & alter) {
		this->first = alter.first; 
		this->second = alter.second;
		return (*this);
	}
	
	positive_rational_num & operator = (positive_rational_num & alter)  {
		this->first = alter.first; 
		this->second = alter.second;
		return (*this);
	}

// OPERADORES DE CAST
	inline operator long double() const {
		long double ret = 0;
		criterator I = this->second.rend();
		criterator J = this->second.rbegin();
		riterator  k = (--I);
		ret += (ullint(*k)*ullint(B));
		--k;
		for(;k >= J; --k) {
			ret += ullint(*k);
			ret *= ullint(B);
		}
		criterator L = this->first.rend();
		criterator M = this->second.rbegin();
		k = (--L);
		
		longdouble temp = (longdouble(k->ullint()));
		temp /= (longdouble(B));
		ret += temp;
		--k;
		for(;k >= M; --k) {
			ret += ullint(*k);
			ret /= longdouble(ullint(B));
		}
		return ret;
	}

// OPERACIONES GET Y SET
	
	const uint_num & get_IntPart() const {
		return this->second;
	}
	
	const uint_num & get_FractPart() const {
		return this->first;
	}
	
	void set_IntPart(const uint_num & arg) {
		this->second = arg;
	}
	
	void set_FractPart(const uint_num & arg) {
		this->first = arg;
	}

// COMPARACIONES

	bool operator ==(const positive_rational_num & arg) const {
		return ((this->first==arg.first)&&(this->second==arg.second));
	}
	bool operator !=(const positive_rational_num & arg) const {
		return ((this->first!=arg.first)||(this->second!=arg.second));
	}
	bool operator <=(const positive_rational_num & arg) const {
		return ( (this->first<=arg.first) ||
				  (
					(this->first==arg.first) &&
				    (this->second<=arg.second)
				  )
				);
	}
	bool operator <(const positive_rational_num & arg) const {
		return ( (this->first<arg.first) ||
				  (
					(this->first==arg.first) &&
				    (this->second<arg.second)
				  )
				);
	}
	bool operator >=(const positive_rational_num & arg) const {
		return ( (this->first>=arg.first) ||
				  (
					(this->first==arg.first) &&
				    (this->second>=arg.second)
				  )
				);
	}
	bool operator >(const positive_rational_num & arg) const {
		return ( (this->first>arg.first) ||
				  (
					(this->first==arg.first) &&
				    (this->second>arg.second)
				  )
				);
	}
	
	bool is_0() const {
		return ((this->first.is_0())&&(this->second.is_0()));
	}
	
	bool is_1() const {
		return ((this->first.is_0())&&(this->second.is_1()));
	}

// OPERACIONES DE COMPLEMENTO
	positive_rational_num C_B() const {
		positive_rational_num ret(*this);
		ret.first.mC_Bm1();
		ret.second.mC_Bm1();
		
		citerator C = ret.first.begin();
		citerator F1 = ret.first.end();
		citerator C1 = ret.second.begin();
		citerator F = ret.second.end();
		iterator I = C;
		
		pardigs temp(0,*I);
		pardigs carry; 
		++temp;
		(*I)= temp.first;
		++I;
		
		while((I < F1)&&(temp.second != dig(0))) {
			carry = temp.second;
			temp = pardigs(0,*I);  
			temp += carry;
			(*I)= temp.first;
			++I;
		}
		
		I = C1;
		carry = temp.second;
		temp(0,*I);
		temp += carry;
		(*I)= temp.first;
		++I;
		
		while((I < F)&&(temp.second != dig(0))) {
			carry = temp.second;
			temp = pardigs(0,*I);  
			temp += carry;
			(*I)= temp.first;
			++I;
		}
		
		return ret;
	}
	
	//mC_B()
	//C_Bm1()
	//mC_Bm1()
};



/* resumen POSITIV_RATIONAL_NUM:






   */

#endif // POSITIVE_RATIONALS_NUM_HPP
