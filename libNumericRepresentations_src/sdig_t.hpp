#ifndef SDIG_T_HPP
#define SDIG_T_HPP

#include "basic_types.hpp"
#include "dig_t.hpp" // Base class: dig_t<B>

template<const uchint B>
class sdig_t : public dig_t<B>
{
private:

	typedef dig_t<B>                    dig;
	typedef sdig_t<B>                   sdig;
	sign_e signo;

public:

    static const uchint NDigs = 1;
    static const bool   with_sign = true;

public:

		/*****************************/
		/*								*/
		/*		CONSTRUIR NUMERO		*/
		/*								*/
		/*****************************/

	inline sdig_t() : dig_t<B>(),signo(vplus) {}

	//inline explicit sdig_t(const ullint & a) : dig_t<B>(ullint(a)),signo(vplus) {}

	inline sdig_t(const sllint & a) : dig_t<B>((a<0) ? (dig_t<B>(-dig_t<B>(sllint(-a)))) : (dig_t<B>(a))),signo((a<0) ? vminus : vplus) {}

	inline sdig_t(const sdig & a) : dig_t<B>(a.g_uds()),signo(a.g_sign()) {}

	inline const sdig & operator = (const sllint& a) {
		this->signo = vplus;
		sllint b=a;
		if (a<0) {
			b = sllint(B)+a;
			this->signo = vminus;
		}
		((*this)())=(b%B);
		return (*this);
	}

	inline sdig & operator = (sllint& a) {
		this->signo = vplus;
		if (a<0) {
			a = B - a;
			this->signo = vminus;
		}
		this->p_uds(a%=B);
		return (*this);
	}

	inline const sdig& operator = (const sdig& a) {
		this->p_uds(a());
		(this->signo)=(a.signo);
		return (*this);
	}

	inline sdig& operator = (sdig& a) {
		this->p_uds(a());
		(this->signo)=(a.signo);
		return (*this);
	}

		/********************************/
		/*									*/
		/*	OPERADORES	COMPARACIÓN		*/
		/*									*/
		/********************************/

	inline bool operator == (sllint a) const {
		return ((((*this)()==(a%B))&&((this->signo)==((a<0)?(vminus):(vplus))))? true : false);
	}

	inline bool operator == (sdig a) const {
		return ((((*this)()==(a()))&&((this->signo)==a.signo))? true : false);
	}

	inline bool operator != (sllint a) const {
		return ((((*this)()!=(a%B))||((this->signo)!=((a<0)?(vminus):(vplus))))? true : false);
	}

	inline bool operator != (sdig a) const {
		return ((((*this)()!=(a()))||((this->signo)!=a.signo))? true : false);
	}

	inline bool operator >= (sllint a) const {
		if ((a<0)&&(signo==vminus)){
			return ((sllint((*this)())-sllint(B)<a)?(true):(false));
		}
		else if((a>=0)&&(signo==vplus)){
			return ((sllint((*this)()>=a))?(true):(false));
		}
		else{
			return ((signo==vplus)?(true):(false));
		}
	}

	inline bool operator >= (sdig a) const {
		if ((a.is_negative())&&(this->is_positive())) return true;
		else if ((a.is_positive())&&(this->is_negative())) return false;
		else {
			return (((*this)() >= a())?(true):(false));
		}
	}

	inline bool operator >  (sllint a) const {
		if ((a<0)&&(signo==vminus)){
			if(a+sllint(B)==sllint((*this)())) return false;
			else return ( (sllint((*this)()) < (a+sllint(B))) ? (true) : (false) );
		}
		else if((a>=0)&&(signo==vplus)){
			if(a+sllint(B)==sllint((*this)())) return false;
			else return ( ((sllint((*this)())>=a)) ? (true) : (false) );
		}
		else{
			return ( (signo==vplus)?(true):(false) );
		}
	}

	inline bool operator >  (sdig a) const {
		if ((this->signo == vplus)&&(a.is_negative())) return true;
		else if ((this->signo == vminus)&&(a.is_positive())) return false;
		else return (  ( ((*this)()) > (a()) ) ? (true) : (false)  );
	}

	inline bool operator <= (sllint a) const {
		if ((a<0)&&(signo==vminus)){
			return ( ( ( sllint((*this)()) ) <= (a+sllint(B)) ) ? (false) : (true) );
		}
		else if((a>=0)&&(signo==vplus)){
			return ( (sllint((*this)()) <= a) ? (true) : (false) );
		}
		else{
			return ((signo==vplus)?(true):(false));
		}
	}

	inline bool operator <= (sdig a) const {
		if ((this->signo == vplus)&&(a.is_negative())) return false;
		else if ((this->signo == vminus)&&(a.is_positive())) return true;
		else return (( sllint((*this)()) <= sllint(a()) )?(true):(false));
	}

	inline bool operator <  (sllint a) const {
		if ((a<0)&&(signo==vminus)){
			return ((sllint((*this)()) <= (a+sllint(B)) )?(false):(true));
		}
		else if((a>=0)&&(signo==vplus)){
			return ( (sllint((*this)()) <= a) ? (true) : (false) );
		}
		else{
			sllint b = a;
			if (a<0) {	b = sllint(B) - b;	}
			return ( ( sllint((*this)()) < (b%sllint(B)) ) ? (true) : (false) );
		}
	}

	inline bool operator <  (sdig a) const {
		if ((this->signo == vplus)&&(a.is_negative())) return false;
		else if ((this->signo == vminus)&&(a.is_positive())) return true;
		else return ( ( sllint((*this)()) < sllint(a()) ) ? (true) : (false) );
	}

	inline bool is_negative() const {
		return (this->signo==vminus);
	}

	inline bool is_positive() const {
		return (this->signo==vplus);
	}

		/************************************/
		/*										*/
		/*	ARITMETICOS CON ASIGNACION		*/
		/*										*/
		/************************************/

	inline const sdig& operator +=(const sdig& arg) {
		ssint M_D = (*this)();
		M_D += arg();
		this->p_uds(M_D % B);

		ssint presigno = (M_D/B);
		if (arg.is_negative()) presigno += (B-1);
		if (this->is_negative()) presigno += (B-1);
		if (presigno==0) this->signo = vplus;
		else this->signo = vminus;

		return (*this);
	}

    inline const dig& operator +=(const sllint& arg) {
		ssint M_D = (*this)();
		M_D += arg;
		(*this)() = M_D % B;

		ssint presigno = (M_D/B);
		if (((this->signo == vminus)&&(arg>=0))||((this->signo == vplus)&&(arg<0))) presigno += (B-1);
		else if ((this->signo == vminus)&&(arg<0)) presigno += 2*(B-1);
		this->signo = ((presigno%B==0)?(vplus):(vminus));

		return (*this);
	}

    inline const sdig& operator -=(const sdig& arg) {
		ssint M_D = (*this)();
		M_D += B-arg();
		this->p_uds(M_D % B);

		ssint presigno = (M_D/B);
		if (arg.signo == vplus) presigno += (B-1);
		if (this->signo == vminus) presigno += (B-1);
		if (presigno==0) this->signo=vplus;
		else this->signo=vminus;

		return (*this);
	}

	inline const sdig & operator -=(const sllint & arg) {
		ssint M_D = (*this)();
		M_D += B-arg;
		(*this)() = M_D % B;

		ssint presigno = (M_D/B);
		if (((this->signo == vminus)&&(arg<0))||((this->signo == vplus)&&(arg>=0))) presigno += (B-1);
		else if ((this->signo == vminus)&&(arg>0)) presigno += 2*(B-1);
		this->signo = ((presigno%B==0)?(vplus):(vminus));

		return (*this);
	}

    inline const sdig & operator *=(const sdig& arg) {
		ssint M_D = (*this)();
		M_D *= arg();
		this->p_uds(M_D % B);
		if (((this->is_negative())&&(arg.is_positive()))||((this->is_positive())&&(arg.is_negative()))) {
			this->signo = vminus;
			this->p_uds(B - (*this)());
		}
		else this->signo = vplus;
		return (*this);
	}

    inline const sdig& operator *=(const sllint& arg) {
		sdig ARG = sdig(arg);
		ssint M_D = (*this)();
		M_D *= ARG.m_d;
		(*this)() = M_D % B;
		if (((this->signo==vminus)&&(ARG.signo==vplus))||((this->signo==vplus)&&(ARG.signo==vminus))) {
			this->signo = vminus;
			(*this)() = this->dig::mC_B();
		}
		else this->signo = vplus;
		return (*this);
	}

	inline const dig & operator /=(const sdig & arg) {
		sdig ARG = arg;
		ARG.mC_B();
		ssint M_D = (*this)();
		M_D /= ARG();
		this->dig_t<B>::operator=(M_D);
		if (((this->signo==vminus)&&(ARG.signo==vplus))||((this->signo==vplus)&&(ARG.signo==vminus))) {
			this->signo = vminus;
			this->dig::mC_B();
		}
		else this->signo = vplus;
		return (*this);
	}

    inline const sdig& operator /=(const sllint& arg) {
		sdig ARG(arg);
		if (ARG.signo==vminus) ARG.mC_B();
		ssint M_D = (*this)();
		M_D /= ARG.m_d;
		(*this)() = M_D % B;
		if (((this->signo==vminus)&&(ARG.signo==vplus))||((this->signo==vplus)&&(ARG.signo==vminus))) {
			this->signo = vminus;
			this->dig::m_d = this->dig::mC_B();
		}
		else this->signo = vplus;
		return (*this);
	}

	inline const sdig& operator %=(const sdig& arg) {
		ssint thisint = ssint((*this)())+((this->is_negative())?(-ssint(B)):(0));
		ssint argint = ssint(arg())+((arg.is_negative())?(-ssint(B)):(0));
		thisint %= argint;
		(*this) = sdig(thisint);
		return (*this);
	}

	inline const sdig& operator %=(const sllint & arg) {
		ssint thisint = ssint((*this)())+((this->signo==vminus)?(-ssint(B)):(0));
		thisint %= arg;
		(*this) = sdig(thisint);
		return (*this);
	}


		/*********************************/
		/*									*/
		/*			PRE Y POST				*/
		/*									*/
		/********************************/

	inline sdig& operator ++ () {
		if (this->is_max()) {
			this->dig_t<B>::operator=(dig(0));
			this->signo = vminus;
		}
		else if(this->is_m1()) {
			this->dig_t<B>::operator=(dig(0));
			this->signo=vplus;
		}
		else {
			this->dig_t<B>::operator++();
		}
		return(*this);
	}

	inline sdig operator ++ (int) {
		sdig t(*this);
		++(*this);
		return t;
	}

	inline sdig& operator -- () {
		if (this->is_min()) {
			this->dig_t<B>::operator=(dig(B-1));
			this->signo = vplus;
		}
		else if(this->is_0()) {
			this->dig_t<B>::operator=(dig(B-1));
			this->signo = vminus;
		}
		else {
			this->dig_t<B>::operator--();
		}
		return(*this);
	}

	inline sdig operator -- (int) {
		sdig t(*this);
		--(*this);
		return t;
	}

		/********************************/
		/*									*/
		/*		OPERADORES ARITMETICOS	*/
		/*									*/
		/********************************/

	inline sdig operator + (sdig arg) const {
		sdig ret(*this);
		ssint M_D = ret();
		M_D += arg();
		ret.dig::operator=(M_D);
		uchint presigno = M_D/B;
		if (ret.signo==vminus)
			presigno += (B-1);
		if (arg.signo==vminus)
			presigno += (B-1);
		ret.signo=((presigno==0)?(vplus):(vminus));
		return ret;
	}

	inline sdig operator - (sdig arg) const {
		sdig ret(*this);
		ssint M_D = ret();
		M_D += ssint(B)-ssint(arg());
		ret.dig_t<B>::operator=(M_D);
		uchint presigno = M_D/B;
		if (ret.signo==vminus)
			presigno += (B-1);
		if (arg.signo==vplus)
			presigno += (B-1);
		ret.signo=((presigno==0)?(vplus):(vminus));
		return ret;
	}

	inline sdig operator * (sdig arg) const {
		sdig ret(*this);
		ssint M_D = ret();
		M_D *= ssint(arg());
		ret = sdig(sllint(M_D));
		return ret;
	}

	inline sdig operator / (sdig arg) const {
		sdig ret(*this);
		ssint M_D = ret();
		M_D /= ssint(arg());
		ret = sdig(M_D);
		return ret;
	}

	inline sdig operator % (sdig arg) const {
		sdig ret(*this);
		ssint M_D = ret();
		M_D %= ssint(arg());
		ret = sdig(M_D);
		return ret;
	}

	inline sdig operator + (sllint arg) const {
		sdig ret(arg);
		ret += (*this);
		return ret;
	}

	inline sdig operator - (sllint arg) const {
		sdig ret(arg);
		ret -= (*this);
		return ret;
	}

	inline sdig operator * (sllint arg) const {
		sdig ret(arg);
		ret *= (*this);
		return ret;
	}

	inline sdig operator / (sllint arg) const {
		sdig ret(*this);
		sdig darg(arg);
		ret /= darg;
		return ret;
	}

	inline dig operator % (ullint arg) const {
		sdig ret(*this);
		sdig darg(arg);
		ret %= darg;
		return ret;
	}

				/********************************/
				/*									*/
				/*		COMPLEMENTO BASE			*/
				/*			Y BASE MENOS 1			*/
				/*									*/
				/********************************/

	inline sdig operator ! () const {
		sdig ret(*this);
		ret.mC_Bm1();
		return ret;
	}

	inline sdig operator - () const {
		sdig ret(*this);
		ret.mC_B();
		return ret;
	}

				/************************************/
				/*										*/
				/*		MODIFICADORES COMPLEMENTO	*/
				/*										*/
				/************************************/

	inline sdig& mC_Bm1 () { //modificador a Complemento a la Base menos 1
		this->dig::mC_Bm1();
		this->signo = ((this->signo==vminus)?(vplus):(vminus));
		return (*this);
	}

	inline sdig& mC_B () {  //modificador a Complemento a la Base
		if ((this->abs()).is_0()) {
			this->dig::operator=(dig());
		}
		else {
			this->dig::mC_Bm1();
			this->signo = ((this->signo==vminus)?(vplus):(vminus));
			this->dig::operator++();
		}
		return (*this);
	}

		/********************************/
		/*									*/
		/*		NULO Y MAXIMO				*/
		/*									*/
		/********************************/

	inline bool is_0 () const {
		return ((this->dig_t<B>::is_0())&&(signo==vplus));
	}

	inline bool is_1 () const {
		return ((this->dig_t<B>::is_1())&&(signo==vplus));
	}

	inline bool is_max () const {
		return ((this->dig_t<B>::is_max())&&(signo==vplus));
	}

	inline bool is_submax() const {
		return ((this->dig_t<B>::is_submax())&&(signo==vplus));
	}

	inline bool is_m1 () const {
		return ((this->dig_t<B>::is_max())&&(signo==vminus));
	}

	inline bool is_min () const {
		return ((this->dig_t<B>::is_0())&&(signo==vminus));
	}

	inline bool is_submin() const {
		return ((this->dig_t<B>::is_1())&&(signo==vminus));
	}

		/********************************/
		/*									*/
		/*		VARIOS CASTS				*/
		/*									*/
		/********************************/

	template<const uchint R>
	inline operator sdig_t<R> () {
		sdig_t<R> ret(ullint((*this)()));
		ret.signo = this->signo;
		return ret;
	}

    inline operator sllint() const {
		sllint ret=sllint((*this)());
		if (this->signo==vminus) {
			ret -= sllint(B);
		}
		return ret;
    }

    inline explicit operator ullint() const {
		sllint ret=sllint((*this)());
		if (this->signo==vminus) {
			ret -= sllint(B);
			ret = -ret;
		}
		return static_cast<ullint>(ret);
    }

	inline sllint operator()() const {
		return (this->dig_t<B>::operator sllint());
	}

	/************************************/
	/*										*/
	/*			ABS Y m_ABS				*/
	/*										*/
	/************************************/

	inline sdig abs() const {
		sdig ret(*this);
		if (this->signo==vminus)
			ret.mC_B();
		return ret;
	}

	inline const sdig & m_abs() {
		if (this->signo==vminus)
			this->mC_B();
		return (*this);
	}
};

/* resumen SDIG_T:






   */

#endif // SDIG_T_HPP
