#ifndef pardigs_t__hpp
#define pardigs_t__hpp


#include <iostream>
#include <sstream>
#include <string>
#include "src/libNumericRepresentations_src/n2digs_t.hpp"
using namespace std;

//template<const uchint B> using n2digs_t = std::pair<dig_t<B>,dig_t<B>>;


template<const uchint B>
class pardigs_t : public n2digs_t<B>{
public:

       typedef dig_t<B> dig;
       typedef n2digs_t<B> n2digs;
		//typedef typename std::basic_string<dig> basic_num_t;
		typedef pardigs_t<B> pardigs;
private:

					/****************************/
					/*							*/
					/*	CONSTRUIR NUMERO		*/
					/*							*/
					/****************************/
public:
	inline dig g_uds() const {
		return this->n2digs::g_uds();
	}

    inline dig g_decs() const {
		return this->n2digs::g_decs();
	}

    inline void p_decs(sllint a) {
        this->n2digs::p_decs(a);
        return;
    }

    inline void p_uds(sllint a) {
        this->n2digs::p_uds(a);
        return;
    }

    inline void p_decs(dig a) {
        return this->n2digs::p_decs(a);
        return;
    }

	inline sign_e g_sign() const {
		return vplus;
	}

	inline void p_inc_decs() {
        this->n2digs::p_inc_decs();
        return;
    }

	inline void p_dec_decs() {
        this->n2digs::p_dec_decs();
        return;
    }

	inline void p_inc_uds() {
        this->n2digs::p_inc_uds();
        return;
    }

	inline void p_dec_uds() {
        this->n2digs::p_dec_uds();
        return;
    }

    inline void p_uds(dig a) {
        this->n2digs::p_uds(a);
        return;
    }


		inline pardigs_t() : n2digs() {}
		inline pardigs_t(dig decenas,dig unidades) : n2digs(decenas,unidades) {}
		inline explicit pardigs_t(const pair<dig,dig> & arg) : n2digs(arg) {}
		inline pardigs_t(sllint decenas,sllint unidades) :
			n2digs(((decenas<0)?(-decenas):(decenas))%B,((unidades<0)?(-unidades):(unidades))%B)
		{}
		inline pardigs_t(sllint numero) {
			const bool menor_q_0 = (numero<(sllint(0)));
			const sllint B_3 = sllint(B)*sllint(B)*sllint(B);
			sllint abs_numero = ((menor_q_0)?(-numero):(numero));
			if (menor_q_0) {	abs_numero = B_3-abs_numero; }
				p_decs((abs_numero/B)%B);
				p_uds(abs_numero%B);
		}
		//inline pardigs_t(unsigned long long int decenas,unsigned long long int unidades) :
        //            m_2digs(decenas%B,unidades%B) {}
		inline pardigs_t<B>(const pardigs_t & arg) :
		n2digs(arg.g_decs(),arg.g_uds()) {}

		inline const pardigs_t & operator = (const pardigs_t & arg) {
			p_decs(arg.g_decs());
			p_uds(arg.g_uds());
			return (*this);
		}

		inline pardigs_t & operator = (pardigs_t & arg) {
			p_decs(arg.g_decs());
			p_uds(arg.g_uds());
			return (*this);
		}

		inline const pardigs_t & operator = (const sllint & arg) {
			p_decs((arg/B)%B);
			p_uds(arg%B);
			return (*this);
		}

		inline pardigs_t & operator = (ullint & arg) {
			p_decs((arg/B)%B);
			p_uds(arg%B);
			return (*this);
		}

			/************************************/
			/*									*/
			/*		Algunas Conversiones		*/
			/*									*/
			/************************************/

		inline explicit operator ullint() const {
		    ullint ret = this->g_decs()();
		    ret *= B;
		    ret += this->g_uds()();
			return ret;
		}

		inline explicit operator sllint() const {
		    sllint ret = this->g_decs()();
		    ret *= B;
		    ret += this->g_uds()();
			return ret;
		}

					/********************************/
					/*								*/
					/*	OPERADORES COMPARATIVOS		*/
					/*  CON NUMEROS DESTACADOS      */
					/*								*/
					/********************************/

        inline bool is_0() const {
            return (this->g_decs().is_0()) && (this->g_uds().is_0());
        }

        inline bool is_1() const {
            return (this->g_decs().is_0()) && (this->g_uds().is_1());
        }

        inline bool is_max() const {
            return (this->g_decs().is_max()) && (this->g_uds().is_max());
        }


        inline bool is_submax() const {
            return (this->g_decs().is_max()) && (this->g_uds().is_submax());
        }

		inline bool is_m1() const {
            return false;
        }

       inline bool is_min() const {
            return (this->is_0());
        }

       inline bool is_submin() const {
            return (this->is_1());
        }

		inline bool is_negative() const {
			return false;
		}

		inline bool is_positive() const {
			return true;
		}

		inline pardigs_t abs() const {
			return (*this);
		}

		inline const pardigs_t& m_abs() const {
			return (*this);
		}

					/********************************/
					/*								*/
					/*	OPERADORES COMPARATIVOS		*/
					/*								*/
					/********************************/

		inline bool operator == (pardigs_t arg) const {
			if ((this->g_decs()==arg.g_decs())&&(this->g_uds()==arg.g_uds()))
				return true;
			else
				return false;
		}

		inline bool operator != (pardigs_t arg) const {
			if ((this->g_decs()!=arg.g_decs())||(this->g_uds()!=arg.g_uds()))
				return true;
			else
				return false;
		}

		inline bool operator <= (pardigs_t arg) const {
			if (this->g_decs() < arg.g_decs()) return true;
			else if (this->g_decs() > arg.g_decs()) return false;
			else {
				if (this->g_uds() <=  arg.g_uds()) return true;
				else return false;
			}
		}

		inline bool operator >= (pardigs_t arg) const {
			if (this->g_decs() > arg.g_decs()) return true;
			else if (this->g_decs() < arg.g_decs()) return false;
			else {
				if (this->g_uds() >=  arg.g_uds()) return true;
				else return false;
			}
		}

		inline bool operator <  (pardigs_t arg) const {
			if (this->g_decs() < arg.g_decs()) return true;
			else if (this->g_decs() > arg.g_decs()) return false;
			else {
				if (this->g_uds() <  arg.g_uds()) return true;
				else return false;
			}
		}

		inline bool operator > (pardigs_t arg) const {
			if (this->g_decs() > arg.g_decs()) return true;
			else if (this->g_decs() < arg.g_decs()) return false;
			else {
				if (this->g_uds() > arg.g_uds()) return true;
				else return false;
			}
		}

								/****************************/
								/*							*/
								/* OPERADORES ARITMETICOS	*/
								/*			pardigs_t		*/
								/*                          */
								/****************************/

		inline pardigs_t operator + (const pardigs_t & arg) const {
			pardigs_t ret(*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint arguds = arg.g_uds()();
			ullint argdecs = arg.g_decs()();
			retuds += arguds;
			if (retuds > (B-1))	++ retdecs;
			retdecs += argdecs;
			ret.p_decs(dig(retdecs));
			ret.p_uds(dig(retuds));
			return ret;
		}

		inline pardigs_t operator - (const pardigs_t & arg) const {
			pardigs_t ret(*this);
			ret -= arg;
			return ret;
		}

		inline pardigs_t operator * (const pardigs_t & arg) const {
			pardigs_t ret(*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint arguds = arg.g_uds()();
			ullint argdecs = arg.g_decs()();
			ullint mult_low,mult_high;
			mult_low = (retuds * arguds);
			mult_high = (retdecs * arguds)+(retuds * argdecs);

			retuds = mult_low % B;
			retdecs = ((mult_low/B)+mult_high)%B;
			ret.p_decs(dig(retdecs));
			ret.p_uds(dig(retuds));
			return ret;
		}

		inline pardigs_t operator / (const pardigs_t & arg) const {
			pardigs_t ret(*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint arguds = arg.g_uds()();
			ullint argdecs = arg.g_decs()();

			retuds += (B*retdecs);
			arguds += (B*argdecs);
			retuds /= arguds;
			retdecs = retuds;
			retdecs /= B;
			retdecs %= B;
			retuds %= B;
			ret.p_decs(dig(retdecs));
			ret.p_uds(dig(retuds));
			return ret;
		}

		inline pardigs_t operator % (const pardigs_t & arg) const {
			pardigs_t ret(*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint arguds = arg.g_uds()();
			ullint argdecs = arg.g_decs()();

			retuds += (B*retdecs);
			arguds += (B*argdecs);
			retuds %= arguds;
			retdecs = retuds;
			retdecs /= B;
			retuds %= B;
			ret.p_decs(dig(retdecs));
			ret.p_uds(dig(retuds));
			return ret;
		}

			/****************************************/
			/*										*/
			/*		ARITMETICOS CON ASIGNACION		*/
			/*				pardigs_t				*/
			/*										*/
			/****************************************/

		inline const pardigs_t & operator += (const pardigs_t & arg) {
			pardigs_t & ret = (*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint arguds = arg.g_uds()();
			ullint argdecs = arg.g_decs()();
			retuds += arguds;
			if (retuds > (B-1))	++ retdecs;
			retdecs += argdecs;
			ret.p_decs(dig(retdecs));
			ret.p_uds(dig(retuds));
			return (*this);
		}

		inline const pardigs_t & operator -= (const pardigs_t & arg) {
			pardigs_t& ret = (*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint rettot = (retuds+(B*retdecs))%(B*B);
			ullint arguds = arg.g_uds()();
			ullint argdecs = arg.g_decs()();
			ullint argtot = (arguds+(B*argdecs))%(B*B);

			if (rettot < argtot) {
				argtot = (B*B) - argtot;
				rettot += argtot;
				rettot %= (B*B);
				ret.p_uds(dig(rettot));
				ret.p_decs(dig(rettot / B));
				return (*this);
			} else if (rettot == argtot) {
				ret.p_uds(d_0<B>());
				ret.p_decs(d_0<B>());
				return (*this);
			} else {
				rettot -= argtot;
				rettot %= (B*B);
				ret.p_uds(dig(rettot));
				ret.p_decs(dig(rettot / B));
				return (*this);
			}
		}

		inline const pardigs_t & operator *= (const pardigs_t & arg) {
			pardigs_t & ret = (*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint arguds = arg.g_uds()();
			ullint argdecs = arg.g_decs()();
			ullint mult_low,mult_high;
			mult_low = (retuds * arguds);
			mult_high = (retdecs * arguds)+(retuds * argdecs);

			retuds = mult_low % B;
			retdecs = ((mult_low/B)+mult_high)%B;
			ret.p_decs(dig(retdecs));
			ret.p_uds(dig(retuds));
			return (*this);
		}

		inline const pardigs_t & operator /= (const pardigs_t & arg) {
			pardigs_t & ret = (*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint arguds = arg.g_uds()();
			ullint argdecs = arg.g_decs()();

			retuds += (B*retdecs);
			arguds += (B*argdecs);
			retuds /= arguds;
			retdecs = retuds;
			retdecs /= B;
			retuds %= B;
			ret.p_decs(dig(retdecs));
			ret.p_uds(dig(retuds));
			return (*this);
		}

		inline const pardigs_t & operator %= (const pardigs_t & arg) {
			pardigs_t & ret = *this;
			ullint retuds  = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint arguds  = arg.g_uds()();
			ullint argdecs = arg.g_decs()();

			retuds += (B*retdecs);
			arguds += (B*argdecs);
			retuds %= arguds;
			retdecs = retuds;
			retdecs /= B;
			retuds %= B;
			ret.p_decs(dig(retdecs));
			ret.p_uds(dig(retuds));
			return (*this);
		}

			/****************************/
			/*							*/
			/*	COMPLEMENTO BASE		*/
			/*		Y BASE MENOS 1		*/
			/*							*/
			/****************************/

		inline pardigs_t operator !  () const {
		// Complemento a B menos 1
			pardigs_t ret(*this);
			ret.p_uds(!(this->g_uds()));
			ret.p_decs(!(this->g_decs()));
			return ret;
		}
		// Complemento a B menos 1

		inline pardigs_t operator -() const {
		// menos unario (cambio de signo, en Complemento a B);
			if (!(this->is_0())) {
				pardigs_t ret = !(*this);
				++ret;
				return ret;
			}
			return (*this);
		}
		// menos unario (cambio de signo, en Complemento a B);

			/********************************/
			/*								*/
			/*	MODIFICADOR COMPLEMENTO		*/
			/*								*/
			/********************************/

		inline const pardigs_t & mC_Bm1 () {
		// auto modificación Complemento a B menos 1
			this->p_uds(!(this->g_uds()));
			this->p_decs(!(this->g_decs()));
			return (*this);
		}
		// auto modificación Complemento a B menos 1

		inline const pardigs_t & mC_B () {
		// auto modificación menos unario (cambio de signo, en Complemento B);
			this->p_uds(!(this->g_uds()));
			this->p_decs(!(this->g_decs()));
			++(*this);
			return (*this);
		}

			/********************************/
			/*								*/
			/*		OPERADORES ARITMETICOS	*/
			/*			dig_t				*/
			/*								*/
			/********************************/

		inline pardigs_t operator + (dig_t<B> arg) const {
			pardigs_t ret(*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint arguds = arg();

			retuds += arguds;
			if (retuds > (B-1))	++ retdecs;
			ret.p_decs(retdecs);
			ret.p_uds(retuds);
			return ret;
		}

		inline pardigs_t operator - (dig_t<B> arg) const {
			pardigs_t ret(*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint rettot  = (retuds+(B*retdecs));
			ullint argtot = arg();

			if (rettot < argtot) {
				argtot = (B*B)-argtot;
				rettot += argtot;
				retuds = dig_t<B>(rettot%B);
				retdecs = dig_t<B>((rettot/B)%B);
				ret.p_decs(retdecs);
				ret.p_uds(retuds);
				return ret;
			} else if (rettot == argtot) {
				ret.p_decs(0);
				ret.p_uds(0);
				return ret;
			} else {
				rettot -= argtot;
				retuds = dig_t<B>(rettot%B);
				retdecs = dig_t<B>((rettot/B)%B);
				ret.p_decs(retdecs);
				ret.p_uds(retuds);
				return ret;
			}
		}

		inline pardigs_t operator * (dig_t<B>arg) const {
			pardigs_t ret(*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint argtot = arg();
			ullint mult_low,mult_high;
			mult_low = (retuds * argtot);
			mult_high = (retdecs * argtot);

			retuds = mult_low % B;
			retdecs = ((mult_low/B)+mult_high)%B;
			ret.p_decs(retdecs);
			ret.p_uds(retuds);
			return ret;
		}

		inline pardigs_t operator / (dig_t<B>arg) const {
			pardigs_t ret(*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint argtot = arg();
			ullint cociente,resto;

			retuds += (B*retdecs);
			retuds /= argtot;
			retdecs = retuds;
			retdecs /= B;
			retdecs %= B;
			retuds %= B;
			ret.p_decs(retdecs);
			ret.p_uds(retuds);
			return ret;
		}

		inline pardigs_t operator % (dig_t<B> arg) const {
			pardigs_t ret(*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint argtot = arg();
			ullint cociente,resto;

			retuds += (B*retdecs);
			retuds %= argtot;
			retdecs = retuds;
			retdecs /= B;
			retuds %= B;
			ret.p_decs(retdecs);
			ret.p_uds(retuds);
			return ret;
		}

			/************************************/
			/*									*/
			/*		ARITMETICOS CON ASIGNACION	*/
			/*				dig_t				*/
			/*									*/
			/************************************/

		inline const pardigs_t & operator += (dig_t<B> arg) {
			pardigs_t ret(*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint argtot = arg();

			retuds += argtot;
			if (retuds > (B-1))	++ retdecs;
			this->p_decs(retdecs);
			this->p_uds(retuds);
			return (*this);
		}

		inline const pardigs_t & operator -= (dig_t<B>arg) {
			pardigs_t ret(*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint rettot = (retuds+(B*retdecs))%(B*B);
			ullint argtot = arg();

			if (rettot < argtot) {
				argtot = (B*B) - argtot;
				rettot += argtot;
				rettot %= (B*B);
				this->p_uds(rettot % B);
				this->p_decs((rettot / B)%B);
				return (*this);
			} else if (rettot == argtot) {
				this->p_uds(0);
				this->p_decs(0);
				return (*this);
			} else {
				rettot -= argtot;
				rettot %= (B*B);
				this->p_uds(rettot % B);
				this->p_decs((rettot / B)%B);
				return (*this);
			}
		}

		inline const pardigs_t & operator *= (dig_t<B> arg) {
			pardigs_t ret(*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint argtot = arg();
			ullint mult_low,mult_high;
			mult_low = (retuds * argtot);
			mult_high = (retdecs * argtot);

			retuds = mult_low % B;
			retdecs = ((mult_low/B)+mult_high)%B;
			this->p_decs(retdecs);
			this->p_uds(retuds);
			return (*this);
		}

		inline const pardigs_t & operator /= (dig_t<B> arg) {
			pardigs_t ret(*this);
			ullint retuds = ret.g_uds()();
			ullint retdecs = ret.g_decs()();
			ullint argtot = arg();
			ullint cociente,resto;

			retuds += (B*retdecs);
			retuds /= argtot;
			retdecs = retuds;
			retdecs /= B;
			retuds %= B;
			this->p_decs(retdecs);
			this->p_uds(retuds);
			return (*this);
		}

		inline const pardigs_t & operator %= (dig_t<B> arg) {
			pardigs_t ret(*this);
			ullint retuds    = ret.g_uds()();
			ullint retdecs  = ret.g_decs()();
			ullint argtot    = arg();
			ullint cociente,resto;

			retuds += (B*retdecs);
			retuds %= argtot;
			retdecs = retuds;
			retdecs /= B;
			retuds %= B;
			this->p_decs(retdecs);
			this->p_uds(retuds);
			return (*this);
		}

			/*****************************/
			/*								*/
			/*		PRE Y POST				*/
			/*								*/
			/*****************************/

		inline const pardigs_t & operator ++ () {
			if (this->g_uds()() < (B-1)) {
				dig_t<B> uds = this->g_uds();
				++uds;
				this->p_uds(uds);
			} else if (this->g_decs()() < (B-1)){
				dig_t<B> decs = this->g_decs();
				++decs;
				this->p_uds(0);
				this->p_decs(decs);
			} else {
				this->p_uds(0);
				this->p_decs(0);
			}
			return (*this);
		}

		inline pardigs_t operator ++ (int) {
			pardigs_t ret(*this);
			++(*this);
			return ret;
		}

		inline const pardigs_t & operator -- () {
			if (this->g_uds()() > 0) {
				dig_t<B> uds(this->g_uds());
				--uds;
				this->p_uds(uds);
			} else if (this->g_decs()() > 0){
				dig_t<B> decs(this->g_decs());
				--decs;
				this->p_uds(B-1);
				this->p_decs(decs);
			} else {
				this->p_uds(B-1);
				this->p_decs(B-1);
			}
			return (*this);
		}

		inline pardigs_t operator -- (int) {
			pardigs_t ret(*this);
			--(*this);
           return ret;
		}

			/********************************/
			/*								*/
			/* 			PRIMER DIGITO		*/
			/*			SEGUNDO DIGITO		*/
			/*								*/
			/********************************/


        inline ullint operator()(ullint a) const {
            if ((a%2)==0)	return ullint(this->g_uds()());
            else			return ullint(this->g_decs()());
        }

		inline ullint operator()() const {
            return ullint(this->g_uds()()+(B*this->g_decs()()));
        }

		template <const uchint R>
		inline operator pardigs_t<R> () const {
			const uint num = ((this->g_decs())*B+(this->g_uds()));
			const ullint dig_decs = num/R;
			const ullint dig_uds = num%R;
			pardigs_t<R> ret;
			ret.p_decs(dig_decs);
			ret.p_uds(dig_uds);
			return ret;
		}

		template <const uchint R>
		inline operator dig_t<R> () const {
			const uint num = ((this->g_decs()())*uint(B)+(this->g_uds()()));
			const uchint dig_uds = num%uint(R);
			dig_t<R> ret(dig_uds);
			return ret;
		}

        istream & operator>> (istream & is) {
            enum estado_e {e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10};
            string sds;
            string num_dec;
            string num_uds;
            string num_base;
            usint numero_base_recogido = 0;
            usint indice = 0;
            usint decena = 0;
            usint unidad = 0;
            estado_e est_act = e0;
            char c;
            is >> sds;
            do {
                c = sds[indice];
                switch(est_act) {
                    case e0 :
                            if (c=='p') est_act = e1; break;
                    case e1 :
                            if (c=='d') est_act = e2;
                            else {
                                est_act = e0;
                                num_base.clear();
                                num_dec.clear();
                                num_uds.clear();
                            }
                            break;
                    case e2 :
                            if (c=='#') est_act = e3;
                            else  {
                                est_act = e0;
                                num_base.clear();
                                num_dec.clear();
                                num_uds.clear();
                            }
                            break;
                    case e3 :
                            if ((c<='9')and(c>='0')) {
                                est_act = e4;
                                num_dec.push_back(c-'0');
                            }
                            else  {
                                est_act = e0;
                                num_base.clear();
                                num_dec.clear();
                                num_uds.clear();
                            }
                            break;
                    case e4 :
                            if ((c<='9')and(c>='0')) num_dec.push_back(c-'0');
                            else if (c == ':') est_act = e5;
                            else  {
                                est_act = e0;
                                num_base.clear();
                                num_dec.clear();
                                num_uds.clear();
                            }
                            break;
                    case e5 :
                            if ((c<='9')and(c>='0')) {
                                est_act = e6;
                                num_uds.push_back(c-'0');
                            }
                            else  {
                                est_act = e0;
                                num_base.clear();
                                num_dec.clear();
                                num_uds.clear();
                            }
                            break;
                    case e6 :
                            if ((c<='9')and(c>='0')) num_uds.push_back(c-'0');
                            else if (c == '#') est_act = e7;
                            else  {
                                est_act = e0;
                                num_base.clear();
                                num_dec.clear();
                                num_uds.clear();
                            }
                            break;
                    case e7 :
                            if (c == 'B') est_act = e8;
                            else  {
                                est_act = e0;
                                num_base.clear();
                                num_dec.clear();
                                num_uds.clear();
                            }
                            break;
                    case e8 :
                            if ((c<='9')and(c>='0')) {
                                est_act = e9;
                                num_base.push_back(c-'0');
                            }
                            else if ((c==' ') || (c=='\0')) est_act = e10;
                            else  {
                                est_act = e0;
                                num_base.clear();
                                num_dec.clear();
                                num_uds.clear();
                            }
                            break;
                    case e9 :
                            if ((c<='9')and(c>='0')) num_base.push_back(c-'0');
                            else if ((c==' ') || (c=='\0')) est_act = e10;
                            else {
                                est_act = e0;
                                num_base.clear();
                                num_dec.clear();
                                num_uds.clear();
                            }
                            break;
                    case e10 : if ((c!=' ')||(c!='\0')){
                                est_act = e0;
                                num_base.clear();
                                num_dec.clear();
                                num_uds.clear();
                            }
                }
                ++indice;

                if (est_act==e10) {
                    for (usint k=0 ; k < num_base.size() ; ++k ) {
                        numero_base_recogido *= 10;
                        numero_base_recogido += num_base[k];
                    }

                    if (numero_base_recogido!=B) {
                        est_act = e0;
                        num_base.clear();
                        num_dec.clear();
                        num_uds.clear();
                    }
                }
            } while ((est_act!=e10)and(c!='\0'));

            for (usint k=0 ; k < num_dec.size() ; ++k ) {
                decena *= 10;
                decena += num_dec[k];
            }

            for (usint k=0 ; k < num_uds.size() ; ++k ) {
                unidad *= 10;
                unidad += num_uds[k];
            }

            (*this) = pardigs(decena,unidad);
            return is;
        }

        string to_string() const {
            stringstream os;
            uchint a = (this->g_decs()())%B;
            dig argdec(a);
            uchint numdec = argdec();
            uchint b = (this->g_uds()())%B;
            dig arguds(b);
            uchint numuds = arguds();
            os << "pd#";
            os << static_cast<int>(numdec);
            os << ":";
            os << static_cast<int>(numuds);
            os << "#B";
            os << static_cast<int>(B);
            string ret(os.str());
            return ret;
        }
};

template<const unsigned char Q>
const pardigs_t<Q> pd_0() {
	static const pardigs_t<Q> d = pardigs_t<Q>(0,0);
	return d;
}

template<const uchint Q>
const pardigs_t<Q> pd_1() {
	static const pardigs_t<Q> d = pardigs_t<Q>(0,1);
	return d;
}

template<const uchint Q>
const pardigs_t<Q> pd_Bm1() {
	static const pardigs_t<Q> d = pardigs_t<Q>(0,Q-1);
	return d;
}

template<const uchint Q>
const pardigs_t<Q> pd_B() {
	static const pardigs_t<Q> d = pardigs_t<Q>(1,0);
	return d;
}

template<const uchint Q>
const pardigs_t<Q> pd_Bp1() {
	static const pardigs_t<Q> d = pardigs_t<Q>(1,1);
	return d;
}

template<const uchint Q>
const pardigs_t<Q> pd_max() {
	static const pardigs_t<Q> d = pardigs_t<Q>(Q-1,Q-1);
	return d;
}

template<const uchint Q>
const pardigs_t<Q> pd_submax() {
	static const pardigs_t<Q> d = pardigs_t<Q>(Q-1,Q-2);
	return d;
}


/* resumen PARDIGS_T:






   */

#endif
