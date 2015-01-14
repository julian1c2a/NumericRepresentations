#ifndef N2DIGS_T__HPP
#define N2DIGS_T__HPP

#include "src/libNumericRepresentations_src/dig_t.hpp"

using namespace std;


template<const uchint B>
struct n2digs_t
{
private:

	typedef		dig_t<B>				dig;
	typedef		n2digs_t<B>			n2digs;

    dig m_decs;
    dig m_uds;

public:
	inline n2digs_t() : m_decs(0),m_uds(0) {}
	inline n2digs_t(dig a, dig b) : m_decs(a),m_uds(b) {}
	//inline explicit n2digs_t(dig a) : m_decs(0),m_uds(a) {}
	inline n2digs_t(const n2digs & A) : m_decs(A.m_decs),m_uds(A.m_uds){}
	inline explicit n2digs_t(const pair< dig , dig > & A) : m_decs(A.first),m_uds(A.second) {}
	inline explicit n2digs_t(ullint d,ullint u) : m_decs(d),m_uds(u) {}

	inline explicit operator pair<dig,dig>() const {
	    pair<dig,dig> ret = make_pair(m_decs,m_uds);
	    return ret;
	}

	inline const n2digs & operator=(const n2digs & rarg) {
		m_uds = rarg.m_uds;
		m_decs = rarg.m_decs;
		return (*this);
	}

	inline n2digs & operator=(n2digs & rarg) {
		m_uds = rarg.m_uds;
		m_decs = rarg.m_decs;
		return (*this);
	}

	inline const n2digs & operator=(const  pair< dig , dig > & rarg) {
		m_uds = rarg.first;
		m_decs = rarg.second;
		return (*this);
	}

	inline n2digs & operator=(pair< dig , dig > & rarg) {
		m_uds = rarg.first;
		m_decs = rarg.second;
		return (*this);
	}

	inline dig g_uds() const {
		return m_uds;
	}

    inline dig g_decs() const {
		return m_decs;
	}

    inline void p_decs(sllint a) {
        m_decs = a;
        return;
    }

    inline void p_uds(sllint a) {
        m_uds = a;
        return;
    }

    inline void p_decs(dig a) {
        m_decs = a;
        return;
    }
	
	inline void p_inc_decs() {
        ++m_decs;
        return;
    }
	
	inline void p_dec_decs() {
        --m_decs;
        return;
    }
	
	inline void p_inc_uds() {
        ++m_uds;
        return;
    }
	
	inline void p_dec_uds() {
        --m_uds;
        return;
    }

    inline void p_uds(dig a) {
        m_uds = a;
        return;
    }

	inline uchint operator()(ullint a) const {
		if ((a%2)==0)	return m_uds();
		else			return m_decs();
	}

};

template<const uchint Base>
const n2digs_t<Base> n2d_0() {
	static const n2digs_t<Base> d = n2digs_t<Base>();
	return d;
}

template<const uchint Base>
const n2digs_t<Base> n2d_1() {
	static const n2digs_t<Base> d = n2digs_t<Base>(0,1);
	return d;
}

template<const uchint Base>
const n2digs_t<Base> n2d_Bm1() {
	static const n2digs_t<Base> d = n2digs_t<Base>(0,Base-1);
	return d;
}

template<const uchint Base>
const n2digs_t<Base> n2d_B() {
	static const n2digs_t<Base> d = n2digs_t<Base>(1,0);
	return d;
}

template<const uchint Base>
const n2digs_t<Base> n2d_Bp1() {
	static const n2digs_t<Base> d = n2digs_t<Base>(1,1);
	return d;
}

template<const uchint Base>
const n2digs_t<Base> n2d_max() {
	static const n2digs_t<Base> d = n2digs_t<Base>(Base-1,Base-1);
	return d;
}

template<const uchint Base>
const n2digs_t<Base> n2d_submax() {
	static const n2digs_t<Base> d = n2digs_t<Base>(Base-1,Base-2);
	return d;
}


template<const uchint Base>
istream & operator >> (istream & is,n2digs_t<Base> & arg)
{
	enum estado_e {e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11};
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
			case e0 : if (c=='n') est_act = e1; break;
			case e1 : if (c=='2') est_act = e2;
					  else {
						est_act = e0;
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e2 : if (c=='d') est_act = e3;
					  else {
						est_act = e0;
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e3 : if (c=='#') est_act = e4;
					  else {
						est_act = e0;
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e4 : if ((c<='9')and(c>='0')) {
						est_act = e5;
						num_dec.push_back(c-'0');
					  }
					  else {
						est_act = e0;
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e5 : if ((c<='9')and(c>='0')) num_dec.push_back(c-'0');
					  else if (c == ':') est_act = e6;
					  else {
						est_act = e0;
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e6 : if ((c<='9')and(c>='0')) {
						est_act = e7;
						num_uds.push_back(c-'0');
					  }
					  else {
						est_act = e0;
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e7 : if ((c<='9')and(c>='0')) num_uds.push_back(c-'0');
					  else if (c == '#') est_act = e8;
					  else {
						est_act = e0;
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e8 : if (c == 'B') est_act = e9;
					  else {
						est_act = e0;
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e9 : if ((c<='9')and(c>='0')) {
						est_act = e10;
						num_base.push_back(c-'0');
					  }
					  else {
						est_act = e0;
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
					  break;
			case e10 : if ((c<='9')and(c>='0')) num_base.push_back(c-'0');
					   else if ((c!=' ')||(c!='\0')) est_act = e11;
					   else {
						est_act = e0;
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					   }
					   break;
			case e11 : if ((c!=' ')||(c!='\0')){
						est_act = e0;
						num_base.clear();
						num_dec.clear();
						num_uds.clear();
					  }
		}
		++indice;
		if (est_act==e11) {
			for (usint k=0 ; k < num_base.size() ; ++k ) {
				numero_base_recogido *= 10;
				numero_base_recogido += num_base[k];
			}
			if (numero_base_recogido!=Base){
				est_act = e0;
				num_base.clear();
				num_dec.clear();
				num_uds.clear();
			}
		}
	} while ((est_act!=e11)and(c!='\0'));

	for (usint k=0 ; k < num_dec.size() ; ++k ) {
		decena *= 10;
		decena += num_dec[k];
	}

	for (usint k=0 ; k < num_uds.size() ; ++k ) {
		unidad *= 10;
		unidad += num_uds[k];
	}

	arg = n2digs_t<Base>(decena%Base,unidad%Base);
	return is;
}

template<const uchint Base>
ostream & operator << (ostream & os,const n2digs_t<Base> & arg)
{
	os << "n2d#"
		 << static_cast<int>(((arg.g_decs())())%Base)
		 << ":"
		 << static_cast<int>(((arg.g_uds())())%Base)
		 << "#B"
		 << static_cast<int>(Base) ;
	return os;
}

/* resumen N2DIGS:






   */



#endif // N2DIGS_T_HPP_INCLUDED
