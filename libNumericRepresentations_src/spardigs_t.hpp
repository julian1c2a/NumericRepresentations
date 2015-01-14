#ifndef spardigs_t__hpp
#define spardigs_t__hpp

#include "src/libNumericRepresentations_src/pardigs_t.hpp"

using namespace std;

template< const uchint B >
class spardigs_t : public pardigs_t<B> {
	typedef dig_t<B> 		dig;
	//typedef sdig_t<B> 	sdig;
	typedef n2digs_t<B> 	n2digs;
	typedef pardigs_t<B> 	pardigs;
	typedef spardigs_t<B>	spardigs;
private:

	sign_e		 signo;

public:
	static const int		iB				= static_cast<long long int>(B); 
	static const sllint 	spd_0			= static_cast<long long int>(0);
	static const sllint 	spd_1			= static_cast<long long int>(1);
	static const sllint 	spd_m1			= static_cast<long long int>(-1);
	static const sllint 	spd_2			= static_cast<long long int>(2);
	static const sllint 	spd_Bm1		= iB-spd_1;
	static const sllint 	spd_mBm1		= -iB+spd_1;
	static const sllint 	spd_B			= iB;
	static const sllint 	spd_mB			= -iB;
	static const sllint  	spd_Bp1		= iB+spd_1;
	static const sllint  	spd_mBp1		= -iB+spd_1;
	static const sllint 	spd_max		= (iB*iB)+spd_m1;
	static const sllint 	spd_submax		= (iB*iB)+(spd_2*spd_m1);
	static const sllint  	spd_min		= -(iB*iB);
	static const sllint  	spd_submin		= -(iB*iB)+spd_1;

public:

			/********************************/
			/*									*/
			/*		PRIMER DIGITO				*/
			/*		SEGUNDO DIGITO			*/
			/*									*/
			/********************************/

	inline dig g_uds() const {
		return this->pardigs::g_uds();
	}

    inline dig g_decs() const {
		return this->pardigs::g_decs();
	}

    inline void p_decs(sllint a) {
        this->pardigs::p_decs(a);
        return;
    }

    inline void p_uds(sllint a) {
        this->pardigs::p_uds(a);
        return;
    }

    inline void p_decs(dig a) {
        return this->pardigs::p_decs(a);
        return;
    }
	
	inline void p_inc_decs() {
        this->pardigs::p_inc_decs();
        return;
    }
	
	inline void p_dec_decs() {
        this->pardigs::p_dec_decs();
        return;
    }
	
	inline void p_inc_uds() {
        this->pardigs::p_inc_uds();
        return;
    }
	
	inline void p_dec_uds() {
        this->pardigs::p_dec_uds();
        return;
    }

    inline void p_uds(dig a) {
        this->pardigs::p_uds(a);
        return;
    }

	inline sign_e g_sign() const {
		return signo;
	}

	inline void p_sign(sign_e arg) {
		signo = arg;
		return;
	}

			/****************************/
			/*							   */
			/*		CONSTRUIR NUMERO	   */
			/*			CON SIGNO		   */
			/*							   */
			/****************************/

public:

		spardigs_t() : pardigs(), signo(vplus) {}

		spardigs_t(sign_e mp,dig_t<B> decs,dig_t<B> uds) : pardigs(decs,uds), signo(mp) {}

		spardigs_t(dig_t<B> decs,dig_t<B> uds) : pardigs(decs,uds),signo(vplus) {}
		
		spardigs_t(sllint arg) : pardigs(arg),signo((arg<0)?vminus:vplus) {}
		
		spardigs_t(ullint decs,ullint uds) : 
			pardigs(dig(decs),dig(uds)),signo(vplus) {}

		spardigs_t(sign_e csigno, uchint decs, uchint uds) : 
			pardigs(dig(decs),dig(uds)),signo(csigno) {}

		spardigs_t(const spardigs_t & arg) : 
			pardigs(arg.g_decs(),arg.g_uds()),signo(arg.signo) {}

		spardigs_t(const pardigs_t<B> & arg) : 
			pardigs(arg.g_decs(),arg.g_uds()),signo(vplus) {}

		spardigs_t(const n2digs_t<B> & arg) : 
			pardigs(arg),signo(vplus) {}

		inline operator pardigs_t<B>() const {
			pardigs_t<B> ret;
			if (signo==vplus)
			        ret=pardigs_t<B>(this->second,this->first);
			else {
					ret=pardigs_t<B>(!this->second,!this->first);
					++ret;
			}
			return ret;
		}

		inline pardigs_t<B> & raw_copy(const spardigs_t & arg) const {
			pardigs ret;
			ret.p_decs(this->g_decs());
			ret.p_uds(this->g_uds());
			return ret;
		}

			/****************************/
			/*								*/
			/*			ABSOLUTO			*/
			/*								*/
			/****************************/

		inline bool is_0() const {
			const bool is_positive = (g_sign()==vplus);
			const bool is_dig_decs_0 = (g_decs()==dig(0));
			const bool is_dig_uds_0 = (g_uds()==dig(0));
			const bool ret_is_0 = (is_positive&&is_dig_decs_0&&is_dig_uds_0);
			return ret_is_0;
		}
		
		inline bool is_1() const {
			const bool is_positive = (g_sign()==vplus);
			const bool is_dig_decs_0 = (g_decs()==dig(0));
			const bool is_dig_uds_1 = (g_uds()==dig(1));
			const bool ret_is_1 = (is_positive&&is_dig_decs_0&&is_dig_uds_1);
			return ret_is_1;
		}
		
		inline bool is_max() const {
			const bool is_positive = (g_sign()==vplus);
			const bool is_dig_decs_Bm1 = (g_decs()==dig(B-1));
			const bool is_dig_uds_Bm1 = (g_uds()==dig(B-1));
			const bool ret_is_max = (is_positive&&is_dig_decs_Bm1&&is_dig_uds_Bm1);
			return ret_is_max;
		}
		
		inline bool is_submax() const {
			const bool is_positive = (g_sign()==vplus);
			const bool is_dig_decs_Bm1 = (g_decs()==dig(B-1));
			const bool is_dig_uds_Bm2 = (g_uds()==dig(B-2));
			const bool ret_is_submax = (is_positive&&is_dig_decs_Bm1&&is_dig_uds_Bm2);
			return ret_is_submax;
		}

		inline bool is_m1() const {
			const bool is_negative = (g_sign()==vminus);
			const bool is_dig_decs_Bm1 = (g_decs()==dig(B-1));
			const bool is_dig_uds_Bm1 = (g_uds()==dig(B-1));
			const bool ret_is_m1 = (is_negative&&is_dig_decs_Bm1&&is_dig_uds_Bm1);
			return ret_is_m1;
		}
		
		inline bool is_min() const {
			const bool is_negative = (g_sign()==vminus);
			const bool is_dig_decs_0 = (g_decs()==dig(0));
			const bool is_dig_uds_0 = (g_uds()==dig(0));
			const bool ret_is_min = (is_negative&&is_dig_decs_0&&is_dig_uds_0);
			return ret_is_min;
		}
		
		inline bool is_submin() const {
			const bool is_negative = (g_sign()==vminus);
			const bool is_dig_decs_0 = (g_decs()==dig(0));
			const bool is_dig_uds_1 = (g_uds()==dig(1));
			const bool ret_is_submin = (is_negative&&is_dig_decs_0&&is_dig_uds_1);
			return ret_is_submin;
		}
		
		inline bool is_negative() const {
			return (g_sign()==vminus);
		}
		
		inline bool is_positive() const {
			return (g_sign()==vplus);
		}
		
		inline const spardigs_t & m_abs() {
			if ((this->g_sign()) != vplus) {
				if(((g_uds()())==0)&&((g_decs()())==0)) {
					(*this) = spardigs_t<B>(vplus,0,0);
				}
				else {
					this->mC_B();
				}
			}
			return (*this);
		}

		inline spardigs_t abs() const {
			spardigs_t ret(*this);
			ret.m_abs();
			return ret;
		}

		inline const spardigs_t & operator = (const spardigs_t & arg) {
			this->pardigs::p_uds(arg.g_uds());
			this->pardigs::p_decs(arg.g_decs());
			signo = arg.signo;
			return (*this);
		}

		inline spardigs_t & operator = (spardigs_t & arg) {
			this->pardigs::p_uds(arg.g_uds());
			this->pardigs::p_decs(arg.g_decs());
			signo  = arg.signo;
			return (*this);
		}

		inline operator n2digs_t<B>() const {
			n2digs_t<B> ret;
			ret.first=this->first;
			ret.second=this->second;
			return ret;
		}

		inline operator dig_t<B>() const {
			if (signo==vplus) return this->first;
			else {
				pardigs_t<B> temp(this->second,this->first);
				temp.mC_B();
				return temp.first;
			}
		}

		inline explicit operator ullint () const {
			spardigs_t cthis(*this);
			if (signo==vminus)
				cthis.mC_B();
			cthis.signo = vplus;
			ullint vabs = ullint((cthis.pardigs::g_decs())())*ullint(B);
			vabs += ullint((cthis.pardigs::g_uds())());
			return vabs;
		}

		inline operator sllint () const {
			sllint vabs = sllint((this->g_decs())())*sllint(B);
			vabs += sllint((this->g_uds())());
			if (signo==vminus) {
				vabs -= sllint(B*B);
			}
			return vabs;
		}

			/****************************/
			/*							*/
			/*		COMPLEMENTO BASE	*/
			/*		Y BASE MENOS 1		*/
			/*							*/
			/****************************/

		inline spardigs_t operator -() const {
		// menos unario (cambio de signo, en Complemento BCD);
			spardigs_t cpy(*this);
			cpy.mC_B();
			return cpy;
		}
		// menos unario (cambio de signo, en Complemento BCD);

		inline spardigs_t operator ! () const {
		// Complemento BCD menos 1
			spardigs_t cpy(*this);
			cpy.mC_Bm1();
			return cpy;
		}
		// Complemento BCD menos 1

			/****************************************/
			/*											*/
			/*		MODIFICADOR DE COMPLEMENTO		*/
			/*											*/
			/****************************************/

		inline const spardigs_t & mC_B  () {
		// auto modificación menos unario (cambio de signo, en Complemento BCD);
			dig cthissigno = ((g_sign()==vminus)?(dig(0)):(dig(B-1)));
//			if ((this->g_decs()==dig(0))&&(this->g_uds()==dig(0))){
//				(*this)= spardigs_t();
//				return (*this);
//			}
			this->p_uds(!(this->g_uds()));
			this->p_decs(!(this->g_decs()));
			pardigs carry(0,this->g_uds());
			++carry;
			this->p_uds(carry.g_uds());
			carry.p_uds(carry.g_decs());
			carry.p_decs(dig(0));
			pardigs temp(0,this->g_decs());
			carry += temp;
			this->p_decs(carry.g_uds());
			cthissigno += carry.g_decs(); 
			this->p_sign((cthissigno==dig(0))?(vplus):(vminus));
			return (*this);
		}
		// auto modificación menos unario (cambio de signo, en Complemento BCD);

		inline const spardigs_t & mC_Bm1   () {
		// auto modificación Complemento BCD menos 1
			this->p_uds(!(this->g_uds()));
			this->p_decs(!(this->g_decs()));
			signo = ((signo==vminus)?vplus:vminus);
			return (*this);
		}
		// auto modificación Complemento BCD menos 1

			/************************************/
			/*										*/
			/*		OPERADOR COMPARACION			*/
			/*										*/
			/************************************/

		inline bool operator == (spardigs_t arg) const {
			if ((this->g_decs()==arg.g_decs())&&
				(this->g_uds()==arg.g_uds())&&
				(this->g_sign()==arg.g_sign()))
			    return true;
			else
			    return false;
		}

		inline bool operator != (spardigs_t arg) const {
			if ((this->g_decs()!=arg.g_decs())||
				(this->g_uds()!=arg.g_uds())||
				(signo!=arg.signo))
			    return true;
			else
			    return false;
		}

		inline bool operator <= (spardigs_t arg) const {
			if ((signo==vminus)&&(arg.signo==vplus)) return true;
			else if ((signo==vplus)&&(arg.signo==vminus)) return false;
			else {
				if (this->g_decs() < arg.g_decs()) return true;
				else if (this->g_decs() > arg.g_decs()) return false;
				else {
					if (this->g_uds() <=  arg.g_uds()) return true;
					else return false;
				}
			}
		}

		inline bool operator >= (spardigs_t arg) const {
			if ((signo==vminus)&&(arg.signo==vplus)) return false;
			else if ((signo==vplus)&&(arg.signo==vminus)) return true;
			else {
				if (this->g_decs() < arg.g_decs()) return false;
				else if (this->g_decs() > arg.g_decs()) return true;
				else {
					if (this->g_uds() < arg.g_uds()) return false;
					else return true;
				}
			}
		}

		inline bool operator < (spardigs_t arg) const {
			if ((signo==vminus)&&(arg.signo==vplus)) return true;
			else if ((signo==vplus)&&(arg.signo==vminus)) return false;
			else {
				if (this->g_decs() < arg.g_decs()) return true;
				else if (this->g_decs() > arg.g_decs()) return false;
				else {
					if (this->g_uds() <  arg.g_uds()) return true;
					else return false;
				}
			}
		}

		inline bool operator >  (spardigs_t arg) const {
			if ((signo==vminus)&&(arg.signo==vplus)) return false;
			else if ((signo==vplus)&&(arg.signo==vminus)) return true;
			else {
				if (this->g_decs() < arg.g_decs()) return false;
				else if (this->g_decs() > arg.g_decs()) return true;
				else {
					if (this->g_uds() <=  arg.g_uds()) return false;
					else return true;
				}
			}
		}

			/************************************/
			/*										*/
			/*		SIGUIENTE Y ANTERIOR			*/
			/*										*/
			/************************************/

	inline const spardigs_t & operator ++ () { // PREINCREMENT
		if (this->g_uds() < (B-1)) {
			this->p_inc_uds();
		}
		else if (this->g_uds() >= (B-1)) {
			this->p_uds(0);
			if (this->g_decs() < (B-1)) {
				this->p_inc_decs();
			}
			else if (this->g_decs() >= (B-1)) {
				this->p_decs(0);
				this->signo = ((this->signo==vplus)?vminus:vplus);
			}
		}
		return (*this);
	}

	inline spardigs_t operator ++ (int) { // POSTINCREMENT
		spardigs_t thism(*this);
		++(*this);
		return thism;
	}

	inline const spardigs_t & operator -- () { // PREINCREMENT
		if (this->g_uds() > 0) {
			p_dec_uds();
			return (*this);
		}
		else if (this->g_uds() <= 0) {
			p_uds(B-1);
			if (this->g_decs() > 0) {
				p_dec_decs();
				return (*this);
			}
			else if (this->g_decs() <= 0) {
				p_decs(B-1);
				this->signo = (this->signo == vplus? vminus : vplus);
				return (*this);
			}
		}
		return (*this); // ¿¿¿¿?????
	}

	inline spardigs_t operator -- (int) { // POSTINCREMENT
		spardigs_t cthism(*this);
		--(*this);
		return cthism;
	}

			/********************************/
			/*								   */
			/*		OPERADOR ARITMETICO	   */
			/*								   */
			/********************************/

		inline const spardigs_t & operator += (const spardigs_t & arg) {
			spardigs_t & cthis = (*this);
			pardigs_t<B> sumuds(pardigs_t<B>(0,cthis.g_uds())+pardigs_t<B>(0,arg.g_uds()));
			cthis.p_uds(sumuds.g_uds());
			sumuds.p_uds(sumuds.g_decs());
			sumuds.p_decs(dig(0));
			const pardigs_t<B> sumdecs(pardigs_t<B>(0,cthis.g_decs())+pardigs_t<B>(0,arg.g_decs()));
			sumuds += sumdecs;
			cthis.p_decs(sumuds.g_uds());
			sumuds.p_uds(sumuds.g_decs());
			sumuds.p_decs(dig(0));
			const pardigs_t<B> sumsigns(pardigs_t<B>(dig(0),((this->g_sign()==vplus)?dig(0):dig(B-1))) + pardigs_t<B>(dig(0),(arg.g_sign()==vplus)?dig(0):dig(B-1)));
			sumuds += sumsigns;
			if(this->is_negative() && arg.is_negative())
				cthis.p_sign((sumuds.g_uds()!=dig(B-1))?vplus:vminus);
			else
				cthis.p_sign((sumuds.g_uds()!=dig(0))?vminus:vplus);
			return cthis;
		}

		inline spardigs_t operator + (const spardigs_t & arg) const {
			spardigs_t cthis = (*this);
			cthis += arg;
			return cthis;
		}


		inline const spardigs_t & operator -= (const spardigs_t & arg) {
			spardigs_t & cthis = (*this);
			spardigs_t carg(arg);
			carg.mC_B();
			pardigs_t<B> sumuds(pardigs_t<B>(0,cthis.g_uds())+pardigs_t<B>(0,carg.g_uds()));
			cthis.p_uds(sumuds.g_uds());
			sumuds.p_uds(sumuds.g_decs());
			sumuds.p_decs(dig(0));
			const pardigs_t<B> sumdecs(pardigs_t<B>(0,cthis.g_decs())+pardigs_t<B>(0,carg.g_decs()));
			sumuds += sumdecs;
			cthis.p_decs(sumuds.g_uds());
			sumuds.p_uds(sumuds.g_decs());
			sumuds.p_decs(dig(0));
			const pardigs_t<B> sumsigns(pardigs_t<B>(dig(0),((this->is_positive())?dig(0):dig(B-1))) + pardigs_t<B>(dig(0),(carg.is_positive())?dig(0):dig(B-1)));
			sumuds += sumsigns;
			if(this->is_negative() && carg.is_negative())
				cthis.p_sign((sumuds.g_uds()!=dig(B-1))?vplus:vminus);
			else
				cthis.p_sign((sumuds.g_uds()!=dig(0))?vminus:vplus);
			return cthis;
		}

		inline spardigs_t operator - (const spardigs_t & arg) const {
			spardigs_t cthis = (*this);
			cthis -= arg;
			return cthis;
		}
		
		inline const spardigs_t & operator *= (const spardigs_t & arg) {
			sign_e  sfin = vplus;
			if (g_sign() != arg.g_sign()) sfin = vminus;
			this->m_abs();
			spardigs_t carg(arg);
			carg.m_abs();
			usint ret0  = this->g_uds()();
			usint ret1 = this->g_decs()();
			usint arg0  = carg.g_uds()();
			usint arg1 = carg.g_decs()();
			usint r00 = ret0 * arg0;
			usint r01pr10 = ret0*arg1 + ret1*arg0;
			//usint r11  = ret1*arg1;
			this->p_uds(r00);
			usint sr001pr010pr101 = (r00/B)+(r01pr10%B);
			this->p_decs(sr001pr010pr101);
			//usint s2   = (sr001pr010pr101/B)+(r01pr10%B)+(r11%B);
			//usint s3   = (r11/B)+(r01pr10/B);
			// (B*B)*(argde*retde)+B*((argde*retud)+(argud*retde))+(argud+retud);

			if(sfin==vminus)
				this->mC_B();
			return (*this);
		}

		inline spardigs_t operator * (const spardigs_t & arg) const {
			spardigs_t ret(*this);
			ret *= arg;
			return ret;
		}

		inline const spardigs_t & operator /= (const spardigs_t & arg) {
			const bool signos_iguales = (arg.g_sign()==g_sign());
			const spardigs cabscthis(this->abs());
			const spardigs cabsarg(arg.abs());
			const bool cthis_eq_carg = ((*this)==(arg));
			const bool cthis_is_min	= this->is_min();
			const bool carg_is_min	= arg.is_min();
			const bool carg_is_not_min_and_cthis_is_not_min = ((!(cthis_is_min))&&(!(carg_is_min)));
			const bool abs_cthis_ltraw_abs_carg = (cabscthis < cabsarg);
			//const bool cthis_is_min_carg_is_not_min = ((!(cthis_is_min)) && (arg.is_min()));
			const bool cthis_is_not_min_carg_is_min = ((!(cthis_is_min))&&(carg_is_min));
			const bool abs_cthis_lt_abs_carg =  (abs_cthis_ltraw_abs_carg||cthis_is_not_min_carg_is_min);
			const bool abs_cthis_eq_abs_carg = (cabscthis == cabsarg);
			//const bool arg_is_not_min = (!(arg.is_min()));
			//const sign_e retsign = ((signos_iguales)?(vplus):(vminus));
			if (cthis_eq_carg) {
				(*this)=spardigs_t(vplus,dig(0),dig(1));
				return (*this);
			}
			else if (arg.is_1()) {
				return (*this);
			}
			else if (arg.is_m1()) {
				this->mC_B();
				return (*this);
			}
			else if ((carg_is_min) && (!(cthis_is_min))) {
				(*this)=spardigs_t(vplus,dig(0),dig(0));
				return (*this);
			}
			else if (carg_is_not_min_and_cthis_is_not_min) {
				if (abs_cthis_eq_abs_carg) {
					(*this)=spardigs_t(vminus,dig(spd_Bm1),dig(spd_Bm1));
				}
				else if (abs_cthis_lt_abs_carg) {
					(*this)=spardigs_t(vplus,dig(0),dig(0));				
				}
				else if (!cthis_is_min){
					this->m_abs();
					spardigs_t<B> cpy(arg);
					cpy.m_abs();
					
					sllint retuds = (this->g_uds()());
					sllint retdec = (this->g_decs()());
					sllint rettot = (retdec*iB)+retuds;
					const sllint arguds = (cpy.g_uds()());
					const sllint argdec = (cpy.g_decs()());
					const sllint argtot = (argdec*iB)+arguds;
					
					rettot /= argtot;
					retuds = rettot % B;
					retdec = (rettot/B)%B;
					
					this->p_decs(dig_t<B>(retdec));
					this->p_uds(dig_t<B>(retuds));
					this->p_sign(vplus);
					
					if (!signos_iguales)
						this->mC_B();
				}
				return (*this);
			}
			else if (cthis_is_min) {
				spardigs_t<B> cpy(arg);
				cpy.m_abs();

				const sllint arguds = (cpy.g_uds()());
				const sllint argdec = (cpy.g_decs()());
				const sllint argtot = (argdec*spd_B)+arguds;
				const sllint rettot = -(spardigs::spd_min)/argtot;
				const sllint retuds = rettot;
				const sllint retdec = (rettot/B);
				
				this->p_decs(dig_t<B>(retdec));
				this->p_uds(dig_t<B>(retuds));
				this->p_sign(vplus);
				
				if (arg.g_sign()==vplus) 
					this->mC_B();
				return (*this);
			}
			else return (*this);
		}

		inline spardigs_t operator / (const spardigs_t & arg) const {
			spardigs_t<B> ret(*this);
			spardigs_t<B> cpy(arg);
			ret /= cpy;
			return ret;
		}

		inline const spardigs_t & operator %= (const spardigs_t & arg) {
			//const spardigs_t spd_mB(vminus,0,0);// == -B*B
			//const spardigs_t spd_0(vplus,0,0);// == +0
			const bool ret_sign_is_vminus = (this->is_negative());
			//const bool signos_iguales_y_negativos = signos_iguales && (g_sign()==vminus);
			//const bool signos_iguales_y_positivos = signos_iguales && (g_sign()==vplus);
			const spardigs abscthis(this->abs());
			const spardigs absarg(arg.abs());
			const bool cthis_eq_carg = ((*this)==(arg));
			const bool cthis_is_min	= this->is_min();
			const bool carg_is_min	= arg.is_min();
			const bool abs_cthis_ltraw_abs_carg = ((!(carg_is_min))&&(!(cthis_is_min))&&(abscthis < absarg));
			//const bool cthis_is_min_carg_not_is_min = ((cthis_is_min) && (!(arg.is_min())));
			const bool cthis_is_not_min_carg_is_min = ((carg_is_min)&&(!(cthis_is_min)));
			const bool abs_cthis_lt_abs_carg =  (abs_cthis_ltraw_abs_carg||cthis_is_not_min_carg_is_min);
			const bool abs_cthis_eqraw_abs_carg = ((!(cthis_is_min))&&(!(carg_is_min))&&(abscthis == absarg));
			const bool abs_cthis_eq_abs_carg = (abs_cthis_eqraw_abs_carg||cthis_eq_carg);
			//const bool arg_is_not_min = (!(arg.is_min()));
			//const sign_e retsign = ((signos_iguales)?(vplus):(vminus));
			if ((abs_cthis_eq_abs_carg)||(arg.is_1())||(arg.is_m1())) {
				(*this)=spardigs_t(vplus,dig(0),dig(0));
				return (*this);
			}
			else if (abs_cthis_lt_abs_carg) {
				return (*this);
			}
			else if ((cthis_is_min)&&(!(carg_is_min))) {
				spardigs_t<B> cpy(arg);
				cpy.m_abs();

				sllint rettot = (iB*iB);
				const sllint arguds = (cpy.g_uds()());
				const sllint argdec = (cpy.g_decs()());
				const sllint argtot = (argdec*iB)+arguds;

				rettot %= argtot;
				sllint retuds = rettot % iB;
				sllint retdec = (rettot/iB)%iB;

				this->p_decs(dig_t<B>(retdec));
				this->p_uds(dig_t<B>(retuds));
				this->p_sign(vplus);

				if (ret_sign_is_vminus)
					this->mC_B();
								
				return (*this);
			}
			else {
				this->m_abs();
				spardigs_t<B> cpy(arg);
				cpy.m_abs();

				sllint retuds = (this->g_uds()());
				sllint retdec = (this->g_decs()());
				sllint rettot = (retdec*iB)+retuds;
				const sllint arguds = (cpy.g_uds()());
				const sllint argdec = (cpy.g_decs()());
				const sllint argtot = (argdec*iB)+arguds;

				rettot %= argtot;
				retuds = rettot % iB;
				retdec = (rettot/iB)%iB;

				this->p_decs(dig_t<B>(retdec));
				this->p_uds(dig_t<B>(retuds));
				this->p_sign(vplus);

				if (ret_sign_is_vminus) 
					this->mC_B();
								
				return (*this);
			}
		}

		inline spardigs_t operator % (const spardigs_t & arg) const {
			spardigs_t<B> ret(*this);
			spardigs_t<B> cpy(arg);
			ret %= cpy;
			return ret;
		}

};

//
//template<uchint Base>
//const spardigs_t<Base> & spd_0() {
//	static const spardigs_t<Base> d = spardigs_t<Base>(vplus,0,0);
//	return d;
//}
//
//template<uchint Base>
//const spardigs_t<Base> & spd_1() {
//	static const spardigs_t<Base> d = spardigs_t<Base>(vplus,0,1);
//	return d;
//}
//
//template<uchint Base>
//const spardigs_t<Base> & spd_m1() {
//	static const spardigs_t<Base> d = spardigs_t<Base>(vminus,B-1,B-1);
//	return d;
//}
//
//template<uchint Base>
//const spardigs_t<Base> & spd_Bm1() {
//	static const spardigs_t<Base> d = spardigs_t<Base>(vplus,0,B-1);
//	return d;
//}
//
//template<uchint Base>
//const spardigs_t<Base> & spd_mBm1() {
//	static const spardigs_t<Base> d = spardigs_t<Base>(vminus,B-1,1);
//	return d;
//}
//
//template<uchint Base>
//const spardigs_t<Base> & spd_B() {
//	static const spardigs_t<Base> d = spardigs_t<Base>(vplus,1,0);
//	return d;
//}
//
//template<uchint Base>
//const spardigs_t<Base> & spd_mB() {
//	static const spardigs_t<Base> d = spardigs_t<Base>(vminus,B-1,0);
//	return d;
//}
//
//template<uchint Base>
//const spardigs_t<Base> & spd_Bp1() {
//	static const spardigs_t<Base> d = spardigs_t<Base>(vplus,1,1);
//	return d;
//}
//
//template<uchint Base>
//const spardigs_t<Base> & spd_mBp1() {
//	static const spardigs_t<Base> d = spardigs_t<Base>(vminus,B-2,B-1);
//	return d;
//}
//
//template<uchint Base>
//const spardigs_t<Base> & spd_max() {
//	static const spardigs_t<Base> d = spardigs_t<Base>(vplus,B-1,B-1);
//	return d;
//}
//
//template<uchint Base>
//const spardigs_t<Base> & spd_min() {
//	static const spardigs_t<Base> d = spardigs_t<Base>(vminus,0,0);
//	return d;
//}
//
//template<uchint Base>
//const spardigs_t<Base> & spd_submax() {
//	static const spardigs_t<Base> d = spardigs_t<Base>(vplus,B-1,B-2);
//	return d;
//}
//
//template<uchint Base>
//const spardigs_t<Base> & spd_submin() {
//	static const spardigs_t<Base> d = spardigs_t<Base>(vminus,0,1);
//	return d;
//}

			/********************************/
			/*								   */
			/*		ISTREAM Y OSTREAM		   */
			/*								   */
			/********************************/

template<const uchint Base>
std::istream & operator >> (std::istream & is,spardigs_t<Base> & arg) {
	enum estado_e {e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14};
	string sds;
	string num_dec;
	string num_uds;
	string num_base;
	string num_sgn;
	usint numero_base_recogido = 0;
	usint indice = 0;
	usint decena = 0;
	usint unidad = 0;
	sign_e sgn = vplus;
	estado_e est_act = e0;
	char c;
	is >> sds;
	do {
		c = sds[indice];
		switch(est_act) {
			case e0 : if (c=='s') est_act = e1;
					  break;
			case e1 : if (c=='p') est_act = e2;
					  else {
						est_act = e0;
						num_sgn.clear();
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e2 : if (c=='d') est_act = e3;
					  else {
						est_act = e0;
						num_sgn.clear();
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e3 : if (c=='#') est_act = e4;
					  else {
						est_act = e0;
						num_sgn.clear();
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e4 : if ((c=='1')||(c=='-')||(c=='+')) {
						est_act = e5;
						num_sgn.push_back(c);
					  }
					  else if (c = ':') {
						  est_act = e7;
						  num_sgn.push_back(0);
					  }
					  else {
						est_act = e0;
						num_sgn.clear();
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e5 : if ((c=='1')and((sds[indice-1]=='-')or(sds[indice-1]=='+'))) {
						est_act = e6;
						num_sgn.push_back(c);
					  }
					  else if (c==':') est_act = e7;
					  else {
						est_act = e0;
						num_sgn.clear();
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e6 : if (c==':') est_act = e7;
					  else {
						est_act = e0;
						num_sgn.clear();
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e7 : if ((c<='9')and(c>='0')) {
						est_act = e8;
						num_dec.push_back(c-'0');
					  }
					  else {
						est_act = e0;
						num_sgn.clear();
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e8 : if ((c<='9')and(c>='0')) num_dec.push_back(c-'0');
					  else if (c == ':') est_act = e9;
					  else {
						est_act = e0;
						num_sgn.clear();
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e9 : if ((c<='9')and(c>='0')) {
						est_act = e10;
						num_uds.push_back(c-'0');
					  }
					  else if ( c == '#' ) est_act = e11;
					  else {
						est_act = e0;
						num_sgn.clear();
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e10 : if ((c<='9')and(c>='0')) num_uds.push_back(c-'0');
					  else if (c == '#') est_act = e11;
					  else {
						est_act = e0;
						num_sgn.clear();
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e11 : if (c == 'B') est_act = e12;
					   else {
						est_act = e0;
						num_sgn.clear();
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					   }
					   break;
			case e12 : if ((c<='9')and(c>='0')) {
						 est_act = e13;
						 num_base.push_back(c-'0');
					   }
					   else {
						est_act = e0;
						num_sgn.clear();
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					   }
					   break;
			case e13 : if ((c<='9')and(c>='0')) num_base.push_back(c-'0');
					   else if ((c==' ')or(c=='\0')) est_act = e14;
					   else {
						est_act = e0;
						num_sgn.clear();
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					   }
					   break;
			case e14 : if ((c!=' ')||(c!='\0')){
						est_act = e0;
						num_sgn.clear();
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
		}
		++indice;

		if (est_act==e14) {
			for (usint k=0 ; k < num_base.size() ; ++k ) {
				numero_base_recogido *= 10;
				numero_base_recogido += num_base[k];
			}
			if (num_sgn.empty()||(num_sgn=="1") ||(num_sgn=="+1") ||(num_sgn[0]=='+'))
				sgn = vplus;
			else if ((num_sgn==string("-1"))or(num_sgn==string("-")))
				sgn = vminus;
			else  {
				est_act = e0;
				num_sgn.clear();
				num_base.clear();
				num_dec.clear();
				num_uds.clear();
			}

			if (numero_base_recogido!=Base) {
				est_act = e0;
				num_sgn.clear();
				num_base.clear();
				num_dec.clear();
				num_uds.clear();
			}
		}
	} while ((est_act!=e14)and(c!='\0'));

	for (usint k=0 ; k < num_dec.size() ; ++k ) {
		decena *= 10;
		decena += num_dec[k];
	}
	decena %= Base;

	for (usint k=0 ; k < num_uds.size() ; ++k ) {
		unidad *= 10;
		unidad += num_uds[k];
	}
	unidad %= Base;

	arg = spardigs_t<Base>(sgn,decena,unidad);

	return is;
}

template<const uchint Base>
std::ostream & operator << (std::ostream & os,const spardigs_t<Base> & arg) {
	os << "spd#"
		 << (arg.g_sign()==vplus?'+':'-')
		 << static_cast<int>(((arg.g_decs())())%Base)
		 << ":"
		 << static_cast<int>(((arg.g_uds())())%Base)
		 <<"#B"
		 << static_cast<int>(Base) ;
	return os;
}


/* resumen SPARDIGS_T:






   */

#endif
