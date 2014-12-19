#ifndef dig_t__hpp
#define dig_t__hpp

#include "basic_types.hpp"

template< const uchint B > class dig_t
{
private:

	typedef dig_t<B>                    dig;
	uchint m_d;

public:

    static const uchint NDigs = 1;
    static const bool   with_sign = false;


public:

		/****************************/
		/*							*/
		/*		CONSTRUIR NUMERO	*/
		/*							*/
		/****************************/

    inline dig_t() : m_d(0) {}
	inline dig_t(const ullint & a) : m_d(a%B) {}
	inline dig_t(const dig & a) : m_d(a.m_d) {}
	inline const dig & operator = (const ullint& a) {
		(this->m_d)=(a%B);
		return (*this);
	}
	inline dig & operator = (ullint& a) {
		(this->m_d)=(a%B);
		return (*this);
	}
	inline const dig& operator = (const dig& a) {
		(this->m_d)=(a.m_d);
		return (*this);
	}
	inline dig& operator = (dig& a) {
		(this->m_d)=(a.m_d);
		return (*this);
	}

		/********************************/
		/*								*/
		/*	OPERADORES	COMPARACIÓN		*/
		/*								*/
		/********************************/

	inline bool operator == (ullint a) const {
		return ((a%B)==m_d)? true : false;
	}

	inline bool operator == (dig a) const {
		return  ((a.m_d) == m_d)? true : false;
	}

	inline bool operator != (ullint a) const {
		return ((a%B)!=m_d)? true : false;
	}

	inline bool operator != (dig a) const {
		return ((a.m_d)!=m_d)? true : false;
	}

	inline bool operator >= (ullint a) const {
		return ((a%B)<=m_d)? true : false;
	}

	inline bool operator >= (dig a) const {
		return ((a.m_d)<=m_d)? true : false;
	}

	inline bool operator >  (ullint a) const {
		return  ((a%B) < m_d)? true : false;
	}

	inline bool operator >  (dig a) const {
		return  ((a.m_d) < m_d )? true : false;
	}

	inline bool operator <= (ullint a) const {
		return  ((a%B) >= m_d)? true : false;
	}

	inline bool operator <= (dig a) const {
		return  ( (a.m_d) >= m_d )? true : false;
	}

	inline bool operator <  (ullint a) const {
		return  ((a%B) > m_d)? true : false;
	}

	inline bool operator <  (dig a) const {
		return  ((a.m_d) >  m_d )? true : false;
	}

		/************************************/
		/*									*/
		/*	ARITMETICOS CON ASIGNACION		*/
		/*									*/
		/************************************/

	inline dig& operator +=(dig& arg) {
	    usint M_D = m_d;
		M_D += arg.m_d;
		m_d = M_D % B;
		return (*this);
	}

	inline const dig& operator +=(const dig& arg) {
	    usint M_D = m_d;
		M_D += arg.m_d;
		m_d = M_D % B;
		return (*this);
	}

	inline dig& operator +=(ullint& arg) {
        usint M_D = m_d;
        M_D += arg;
		m_d = M_D % B;
		return (*this);
	}

    inline const dig& operator +=(const ullint& arg) {
        usint M_D = m_d;
        M_D += arg;
		m_d = M_D % B;
		return (*this);
	}

	inline dig& operator -=(dig& arg) {
		ssint t=m_d;
		t-=static_cast<ssint>(arg.m_d);
		if (t < 0) t += B;
		m_d=(t%B);
		return (*this);
	}

    inline const dig& operator -=(const dig& arg) {
		ssint t=m_d;
		t-=static_cast<ssint>(arg.m_d);
		if (t < 0) t += B;
		m_d=(t%B);
		return (*this);
	}

	inline dig & operator -=(ullint & arg) {
		ssint t=m_d;
		t-=static_cast<ssint>(arg%B);
		if (t < 0) t += B;
		m_d=(t%B);
		return (*this);
	}


	inline const dig & operator -=(const ullint & arg) {
		ssint t=m_d;
		t-=static_cast<ssint>(arg%B);
		if (t < 0) t += B;
		m_d=(t%B);
		return (*this);
	}


	inline dig& operator *=(dig& arg) {
	    usint M_D = m_d;
		M_D *= arg.m_d;
		m_d = M_D % B;
		return (*this);
	}

    inline const dig & operator *=(const dig& arg) {
	    usint M_D = m_d;
		M_D *= arg.m_d;
		m_d = M_D % B;
		return (*this);
	}

	inline dig& operator *=(ullint& arg) {
	    usint M_D = m_d;
		M_D *= (arg%B);
		m_d = M_D % B;
		return (*this);
	}

    inline const dig& operator *=(const ullint& arg) {
	    usint M_D = m_d;
		M_D *= (arg%B);
		m_d = M_D % B;
		return (*this);
	}

	inline const dig & operator /=(const dig & arg) {
		m_d /= arg.m_d;
		return (*this);
	}

    inline dig& operator /=(dig & arg) {
		m_d /= arg.m_d;
		return (*this);
	}

	inline dig& operator /=(ullint& arg) {
		m_d /= (arg%B);
		return (*this);
	}

    inline const dig& operator /=(const ullint& arg) {
		m_d /= (arg%B);
		return (*this);
	}


	inline dig& operator %=(dig& arg) {
		m_d %= arg.m_d;
		return (*this);
	}

	inline const dig& operator %=(const dig& arg) {
		m_d %= arg.m_d;
		return (*this);
	}

	inline dig& operator %=(ullint & arg) {
		m_d %= (arg%B);
		return (*this);
	}


	inline const dig& operator %=(const ullint & arg) {
		m_d %= (arg%B);
		return (*this);
	}


		/********************************/
		/*								*/
		/*			PRE Y POST			*/
		/*								*/
		/********************************/

	inline dig& operator ++ () {
		(m_d < (B-1))?(m_d+=1):(m_d=0);
		return(*this);
	}

	inline dig operator ++ (int) {
		dig t(*this);
		m_d = ((m_d < (B-1))?(m_d+1):(0));
		return t;
	}

	inline dig& operator -- () {
		(m_d > 0)?(m_d-=1):(m_d=(B-1));
		return(*this);
	}

	inline dig operator -- (int) {
		dig t(*this);
		m_d = ((m_d > 0)?(m_d-1):(B-1));
		return t;
	}

		/********************************/
		/*								*/
		/*		OPERADORES ARITMETICOS	*/
		/*								*/
		/********************************/

	inline dig operator + (dig arg) const {
		dig ret(*this);
		usint M_D = ret.m_d;
		M_D += arg.m_d;
		ret.m_d = M_D % B;
		return ret;
	}

	inline dig operator - (dig arg) const {
		dig ret(*this);
		ssint M_D = ret.m_d;
		M_D += B;
		M_D -= arg.m_d;
		ret.m_d = M_D % B;
		return ret;
	}

	inline dig operator * (dig arg) const {
		dig ret(*this);
		usint M_D = ret.m_d;
		M_D*= arg.m_d;
		ret.m_d = M_D % B;
		return ret;
	}

	inline dig operator / (dig arg) const {
		dig ret(*this);
		(ret.m_d)/=(arg.m_d);
		return ret;
	}

	inline dig operator % (dig arg) const {
		dig ret(*this);
		(ret.m_d)%=(arg.m_d);
		return ret;
	}

	inline dig operator + (ullint arg) const {
		dig ret(*this);
		usint M_D = ret.m_d;
		M_D += (arg%B);
		ret.m_d = M_D % B;
		return ret;
	}

	inline dig operator - (ullint arg) const {
		dig ret(*this);
		ssint M_D = ret.m_d;
		M_D +=  B;
		M_D -= (arg%B);
		ret.m_d = M_D % B;
		return ret;
	}

	inline dig operator * (ullint arg) const {
		dig ret(*this);
		usint M_D = ret.m_d;
		M_D *= (arg%B);
		ret.m_d = M_D % B;
		return ret;
	}

	inline dig operator / (ullint arg) const {
		dig ret(*this);
		(ret.m_d)/=(arg%B);
		return ret;
	}

	inline dig operator % (ullint arg) const {
		dig RET(*this);
		(RET.m_d) %= (arg%B);
		return RET;
	}

				/********************************/
				/*								*/
				/*		COMPLEMENTO BASE		*/
				/*			Y BASE MENOS 1		*/
				/*								*/
				/********************************/

	inline dig operator ! () const {
		return dig((B-1)-m_d);
	}

	inline dig operator - () const {
		return dig((m_d==0)?0:(B-m_d));
	}

				/************************************/
				/*									*/
				/*		MODIFICADORES COMPLEMENTO	*/
				/*									*/
				/************************************/

	inline dig& mC_Bm1 () { //modificador a Complemento a la Base menos 1
	    m_d=((B-1)-m_d);
		return (*this);
	}

	inline dig& mC_B () {  //modificador a Complemento a la Base
	    if (m_d!=0) m_d=(B-m_d);
		return (*this);
	}

		/********************************/
		/*								*/
		/*		NULO Y MAXIMO			*/
		/*								*/
		/********************************/

	inline bool is_0 () const {
		return (m_d==0);
	}

	inline bool is_1 () const {
		return (m_d==1);
	}

	inline bool is_max () const {
		return (m_d==(B-1));
	}

	inline bool is_submax() const {
		return (m_d==(B-2));
	}


	inline bool is_m1() const {
		return false;
	}

	inline bool is_min() const {
		return (is_0());
	}

	inline bool is_submin() const {
		return (is_1());
	}

	inline bool is_negative() const {
		return false;
	}

	inline bool is_positive() const {
		return true;
	}

	inline dig_t abs() const {
		return (*this);
	}

	inline const dig_t& m_abs() {
		return (*this);
	}

		/********************************/
		/*								*/
		/*		VARIOS CASTS			*/
		/*								*/
		/********************************/

	template<const uchint R>
	inline operator dig_t<R> () {
		return dig_t<R>(this->m_d);
	}

    inline explicit operator sllint() const {
        return static_cast<sllint>(this->m_d);
    }

    inline explicit operator ullint() const {
        return static_cast<ullint>(this->m_d);
    }

	inline ullint operator()() const {
		return static_cast<ullint>(this->m_d);
	}

	inline sign_e g_sign() const {
		return vplus;
	}

	inline dig_t g_uds() const {
		return (*this);
	}

	inline dig_t g_decs() const {
		return dig_t(0);
	}
	
	inline void p_uds(sllint a) {
		if (a < 0) {
			this->m_d = (((-a/sllint(B))+1)*(-a))+a;
		}
		else {
			this->m_d = a%sllint(B);
		}
	}
	
	inline void p_decs(sllint a) const {}

};


template<const uchint B>
const dig_t<B> d_0() {
	static const dig_t<B> d = dig_t<B>(0);
	return d;
}

template<const uchint B>
const dig_t<B> d_1() {
	static const dig_t<B> d = dig_t<B>(1);
	return d;
}

template<const uchint B>
const dig_t<B> d_max() {
	static const dig_t<B> d = dig_t<B>(B-1);
	return d;
}

template<const uchint B>
const dig_t<B> d_submax() {
	static const dig_t<B> d = dig_t<B>(B-2);
	return d;
}

			/********************************/
			/*								*/
			/*		ISTREAM Y OSTREAM		*/
			/*								*/
			/********************************/

template<const uchint Base>
std::istream & operator >> (std::istream & is,dig_t<Base> & arg)
{
	enum estado_e {e0,e1,e2,e3,e4,e5,e6,e7,e8};
	std::string sds;
	std::string num_dig;
	std::string num_base;
	estado_e est_act = e0;
	usint indice = 0;
	usint numero_base_recogido=0;
	uchint numero = 0;
	char c;
	is >> sds;
	do {
		c = sds[indice];
		switch(est_act) {
			case e0 : if (c=='d'){
					est_act = e1;
				}
				break;
			case e1 : if (c=='#') {
					est_act = e2;
				}
				else {
					est_act = e0;
				}
				break;
			case e2 : if ((c<='9')and(c>='0')) {
					est_act = e3;
					num_dig.push_back(c-'0');
				}
				else {
					est_act = e0;
					num_dig.clear();
				}
				break;
			case e3 : if ((c<='9')and(c>='0')) num_dig.push_back(c-'0');
					  else if (c == '#') est_act = e4;
					  else {
						est_act=e0;
						num_dig.clear();
					  }
					  break;
			case e4 : if (c == 'B') est_act = e5;
					  else {
						est_act = e0;
						num_dig.clear();
					  }
					  break;
			case e5 : if ((c<='9')and(c>='0')) {
						est_act = e6;
						num_base.push_back(c-'0');
					  }
					  else {
						est_act = e0;
						num_dig.clear();
						num_base.clear();
					  }
					  break;
			case e6 : if ((c<='9')and(c>='0')) num_base.push_back(c-'0');
					  else if ((c==' ')||(c=='\0')) est_act = e7;
					  break;
			case e7 : if ((c!=' ')||(c!='\0')){
						est_act = e0;
						num_dig.clear();
						num_base.clear();
					}
		}

		++indice;

		if (est_act==e7) {
			for (usint k=0 ; k < num_base.size() ; ++k ) {
				numero_base_recogido *= 10;
				numero_base_recogido += num_base[k];
			}
			if (numero_base_recogido!=Base) {
				est_act = e0;
				num_dig.clear();
				num_base.clear();
			}
			else est_act = e8;
		}
	} while (est_act!=e8);

	for (int k=0 ; k < num_dig.size() ; ++k ) {
		numero *= 10;
		numero += num_dig[k];
	}
	numero %= Base;
	arg = dig_t<Base>(numero);
	return is;
}

template<const uchint Base>
std::ostream & operator << (std::ostream & os,dig_t<Base> arg)
{
	os		<< "d#"
			<< static_cast<int>((arg())%Base)
			<< "#B"
			<< static_cast<int>(Base) ;
	return os;
}


/* resumen DIG_T :






   */
#endif
