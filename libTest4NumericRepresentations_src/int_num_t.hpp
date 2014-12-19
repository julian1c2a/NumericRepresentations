#ifndef num_int__hpp
#define num_int__hpp

#include "dig_t.hpp"
#include "spardigs_t.hpp"
#include "uint_num_t.hpp"

using namespace std;

enum forma_t {noraw,raw};

template< const uchint B >
class num_int : private basic_num_t< B > {
    private:
		typedef dig_t<B>			 							dig;
		typedef basic_num_t<B>									basic_num;
		typedef basic_string< dig_t<B> >						nbstr;
		typedef typename nbstr::iterator						striterator;
		typedef typename nbstr::reverse_iterator				rstriterator;
		typedef typename nbstr::const_iterator					cstriterator;
		typedef typename nbstr::const_reverse_iterator			crstriterator;
		typedef typename basic_num::iterator					b_iterator;
		typedef typename basic_num::reverse_iterator			b_riterator;
		typedef typename basic_num::const_iterator				b_citerator;
		typedef typename basic_num::const_reverse_iterator		b_criterator;
		typedef typename num_int::iterator						iterator;
		typedef typename num_int::reverse_iterator				riterator;
		typedef typename num_int::const_iterator				citerator;
		typedef typename num_int::const_reverse_iterator		criterator;
		typedef n2digs_t<B>										n2digs;
		typedef pardigs_t<B>									pardigs;
		typedef spardigs_t<B>									spardigs;

private:
		sign_e			signo;
		spardigs		aux;

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

		inline dig_t<B> operator()(size_t index) const{
			const num_int & cthis = *this;
			const size_t szthis = cthis.size();
			if (index < szthis) return cthis[index];
			else if (cthis.signo == vminus) return dig(B-1);
			else return dig(0);
		}

private:

		inline void mC_B_incondicionado() {
			num_int & cthis = *this;
			// Complementación a la base menos 1
			// complementar a Bm1
			for(usint i=0; i < cthis.size() ;i++) {
				(cthis[i]).mC_Bm1();
			}
			// Sumar 1
			aux = spardigs(vplus,0,cthis[0]);
			aux += spardigs(vplus,0,dig(1));
			cthis[0]=aux.g_uds();
			aux = spardigs(vplus,0,aux.g_decs());
			usint i = 1;
			for(;i < cthis.size(); ++i) {
				aux += spardigs(vplus,0,cthis[i]);
				cthis[i]=aux.g_uds();
				aux = spardigs(vplus,0,aux.g_decs());

			}
			aux = spardigs();
		}

public:

		inline void resize(size_t arg) {
			basic_num & cthis = (*this);
			cthis.basic_num::resize(arg);
			return;
		}

		inline void push_front(dig_t<B> parg) {
			basic_num & cthis = (*this);
			cthis.basic_num::push_front(parg);
			return;
		}

		inline void push_back(dig_t<B> arg) {
			basic_num & cthis = (*this);
			cthis.basic_num_t<B>::push_back(arg);
		}

		inline dig_t<B> & operator[] (size_t index) {
			basic_num & cthis = (*this);
			return (cthis.basic_num_t<B>::operator[](index));
		}

		inline dig_t<B> operator[] (size_t index) const {
			const basic_num & cthis = (*this);
			return (cthis.basic_num_t<B>::operator[](index));
		}

private:

		inline num_int& insert ( size_t pos1, const dig_t<B> chardig ){
			basic_num & cthis = (*this);
			cthis.basic_num::insert(pos1,1,chardig);
			return (*this);
		}

		inline num_int& insert ( size_t pos1, size_t n, dig_t<B> c ){
			basic_num & cthis = (*this);
			cthis.basic_num::insert(pos1,n,c);
			return (*this);
		}

public:

		inline const num_int & operator &= (const num_int & arg) {
			basic_num & cthis = (*this);
			cthis.basic_num::operator+=(arg);
			return (*this);
		}

private:

		// string& erase ( size_t pos = 0, size_t n = npos );
		inline num_int& erase ( size_t pos, size_t npos ){
			num_int & cthis = (*this);
			size_t npos_2= npos;
			const size_t sz = size();
			if ((sz == npos) and (pos == 0)) {
				npos_2--;
				if (signo==vplus)
					cthis[sz-1] = dig_t<B>(0);
				else
					cthis[sz-1] = dig_t<B>(B-1);
			}
			cthis.basic_num::erase(pos,npos_2);
			return (*this);
		}

		inline iterator erase ( iterator first, iterator last ){
			num_int & cthis = (*this);
			size_t npos= last-first;
			const size_t sz = size();
			if (sz == npos) {
				last--;
				cthis[sz-1] = d_0<B>();
			}
			return basic_num::erase(first,last);
		}

public:

		num_int() {
			num_int & cthis = *this;
			signo=vplus;
			aux = spardigs();
			cthis.basic_num::clear();
			cthis.basic_num::push_back(dig_t<B>(0));
		}

		num_int(const num_int & a) {
			num_int & cthis = *this;
			signo=a.signo;
			aux=a.aux;
			cthis.clear();
			cthis.resize(a.size());
			for (usint k=0; k < a.size() ; ++k)
				cthis[k]=a[k];
			cthis.reduce();
		}

		num_int(const string & a ) {
			num_int & cthis = *this;
			signo=vplus;
			cthis.clear();
			cthis.resize(a.size());
			unsigned int l=0;
			bool Exit = false;
			usint k = 0;
			while ((a[k]<'0')||(a[k] > (char(B-1)+'0'))) ++k;
			if (k >= a.size()) { num_int & cthis = *this;
				cthis.resize(0);
				Exit=true;
			}
			if (!Exit) {
				for ( ; (k < a.size())&&(!Exit) ; ++k) {
					if ((a[k]>='0')&&(a[k] <= (char(B-1)+'0')))
					{
						cthis[l]=Char2Dig<B>(a[k]);
						++l;
					}
					else Exit=true;
				}
			}
			cthis.reduce();
		}

		num_int(dig a0) {
			num_int & cthis = *this;
			signo=vplus;
			cthis.clear();
			cthis.resize(1);
			cthis[0]=a0;
		}

		num_int(dig a1,dig a0 ) {
			num_int & cthis = *this;
			signo=vplus;
			cthis.clear();
			cthis.resize(2);
			cthis[0]=a0;
			cthis[1]=a1;
			cthis.reduce();
		}

		num_int(dig a2,dig a1,dig a0) {
			num_int & cthis = *this;
			signo=vplus;
			cthis.clear();
			cthis.resize(3);
			cthis[0]=a0;
			cthis[1]=a1;
			cthis[2]=a2;
			cthis.reduce();
		}

		num_int(const std::vector<dig> & arg) {
			num_int & cthis = *this;
			signo=vplus;
			cthis.clear();
			cthis.resize( arg.size() );
			for ( uint ix=0; ix < arg.size() ; ++ix )
				cthis[ix]=arg[ix];
			cthis.reduce();
		}

		num_int(const std::list<dig> & arg) {
			num_int & cthis = *this;
			signo=vplus;
			cthis.clear();
			typename list<dig>::iterator it=arg.begin();
			typename list<dig>::const_iterator itf=arg.end();
			for ( ; it != itf ; ++it )
				cthis.push_back(*it);
			cthis.reduce();
		}

		num_int(sign_e s,dig a0) {
			num_int & cthis = *this;
			signo=s;
			aux = spardigs(vplus,0,a0);
			cthis.clear();
			cthis.resize(1);
			cthis[0]=aux.g_uds();
			aux = spardigs(vplus,0,0);
			cthis.reduce();
		}

		num_int(sign_e s,dig a1,dig a0) {
			num_int & cthis = *this;
			signo=s;
			aux = spardigs(vplus,0,0);
			cthis.clear();
			cthis.resize(2);
			cthis[0]=a0;
			cthis[1]=a1;
			cthis.reduce();
		}

		num_int(sign_e s,dig a2,dig a1,dig a0)
		{
			num_int & cthis = *this;
			signo=s;
			aux = spardigs(vplus,0,0);
			cthis.clear();
			cthis.resize(3);
			cthis[0]=a0;
			cthis[1]=a1;
			cthis[2]=a2;
			cthis.reduce();
		}

		num_int(sign_e s,const std::vector<dig> & arg) {
			num_int & cthis = *this;
			signo=s;
			cthis.clear();
			cthis.resize( arg.size() );
			for ( size_t ix=0; ix < arg.size() ; ++ix ){
				cthis[ix]=arg[ix];
			}
			cthis.reduce();
		}

		num_int( sign_e s,const std::list<dig> & arg ) {
			num_int & cthis = *this;
			signo=s;
			cthis.clear();
			cthis.resize( arg.size() );
			typename std::list<dig>::const_iterator it=arg.begin();
			typename std::list<dig>::const_iterator it_end=arg.end();
			for ( ; it != it_end ; ++it )
				cthis.push_front(*it);
			cthis.reduce();
		}

		num_int(spardigs a) {
			num_int & cthis = *this;
			signo=a.g_sign();
			cthis.clear();
			cthis.resize(2);
			cthis[0] = a.g_first();
			cthis[1] = a.g_second();
			cthis.reduce();
		}

		num_int(pardigs a) {
			num_int & cthis = *this;
			signo=vplus;
			cthis.clear();
			cthis.resize(2);
			cthis[0] = a.g_first();
			cthis[1] = a.g_second();
			cthis.reduce();
		}

		num_int(sign_e s , pardigs a) {
			num_int & cthis = *this;
			cthis.signo=s;
			cthis.clear();
			cthis.resize(2);
			cthis[0] = a.g_first();
			cthis[1] = a.g_second();
			cthis.reduce();
		}

		num_int(char ch) {
			num_int & cthis = *this;
			cthis.clear();
			signo=vplus;
			cthis.resize(1);
			cthis[0] = Char2Dig<B>(ch);
		}

		num_int(uchint a) {
			num_int & cthis = *this;
			signo=vplus;
			cthis.clear();
			cthis.resize(1);
			cthis[0] = UInt2Dig<B>(a);
		}

		template<typename Int_T>
		num_int(Int_T a) {
			num_int & cthis = *this;
			cthis.clear();
			const Int_T longitud = num_digs_max_base_B_en_Int_T<Int_T,B>()+1;
			cthis.resize(longitud);
			uint indice = 0;
			if (a>=0) {
				for(Int_T i=0;i<longitud;i++) cthis[i]=dig(0);
				signo=vplus;
				Int_T rem=0,coc=a;
				while (coc >= B) {
					rem = coc%B;
					cthis[indice] = Int2Dig<B>(rem);
					++indice;
					coc = coc/B;
				}
				cthis[indice] = Int2Dig<B>(coc);
			}
			else {
				for(Int_T i=0;i<longitud;++i) cthis[i]=dig(B-1);
				signo=vminus;
				Int_T rem=0,coc=-a;
				while (coc >= B) {
					rem = coc%B;
					cthis[indice] = !(Int2Dig<B>(rem));
					++indice;
					coc = coc/B;
				}
				cthis[indice] = !(Int2Dig<B>(coc));
				++cthis;
				cthis.signo = vminus;
			}
			cthis.reduce();
		}

		const num_int & operator = (const num_int & a) {
			num_int & cthis = *this;
			signo=a.signo;
			aux=a.aux;
			cthis.clear();
			cthis.resize(a.size());
			for (usint k=0; k < a.size() ; ++k)
				cthis[k]=a[k];
			cthis.reduce();
			return cthis;
		}

		const num_int & operator = (const uint_num<B> & a) {
			num_int & cthis = *this;
			signo=vplus;
			aux=vplus;
			cthis.clear();
			cthis.resize(a.size());
			for (usint k=0; k < a.size() ; ++k)
				cthis[k]=a[k];
			cthis.reduce();
			return cthis;
		}

		const num_int & operator = (const pardigs_t<B> & a) {
			num_int & cthis = *this;
			signo=vplus;
			aux.p_sign(vplus);
			aux.n2digs::m_decs(0);
			aux.p_uds(0);
			cthis.clear();
			cthis.resize(2);
			cthis[1]=a.g_decs();
			cthis[0]=a.g_uds();
			cthis.reduce();
			return cthis;
		}

		const num_int & operator = (const spardigs_t<B> & a) {
			num_int & cthis = *this;
			signo=a.signo;
			aux.p_sign(vplus);
			aux.n2digs::m_decs(0);
			aux.p_uds(0);
			cthis.clear();
			cthis.resize(2);
			cthis[1]=a.g_decs();
			cthis[0]=a.g_uds();
			cthis.reduce();
			return cthis;
		}

		const num_int & operator = (const dig_t<B> & a) {
			num_int & cthis = *this;
			signo=vplus;
			aux.p_sign(vplus);
			aux.n2digs::m_decs(0);
			aux.p_uds(0);
			cthis.clear();
			cthis.resize(1);
			cthis[0]=a;
			return cthis;
		}

		template<typename Int_T>
		const num_int & operator = (Int_T a) {
			num_int & cthis = *this;
			cthis.clear();
			const Int_T longitud = num_digs_max_base_B_en_Int_T<Int_T,B>();
			cthis.resize(longitud);
			uint indice = 0;
			if (a>=0) {
				for(Int_T i=0;i<longitud;i++) cthis[i]=dig(0);
				signo=vplus;
				Int_T rem=0,coc=a;
				while (coc >= B) {
					rem = coc%B;
					cthis[indice] = Int2Dig<B>(rem);
					++indice;
					coc = coc/B;
				}
				cthis[indice] = Int2Dig<B>(coc);
			}
			else {
				for(Int_T i=0;i<longitud;++i) cthis[i]=dig(B-1);
				signo=vminus;
				Int_T rem=0,coc=-a;
				while (coc >= B) {
					rem = coc%B;
					cthis[indice] = !(Int2Dig<B>(rem));
					++indice;
					coc = coc/B;
				}
				cthis[indice] = !(Int2Dig<B>(coc));
				++cthis;
				cthis.signo = vminus;
			}
			cthis.reduce();
			return cthis;
		}


		const num_int & operator = (const std::vector<dig> & arg) {
			num_int & cthis = *this;
			signo=vplus;
			cthis.clear();
			cthis.resize( arg.size() );
			for ( uint ix=0; ix < arg.size() ; ++ix ){
				cthis[ix]=arg[ix];
			}
			cthis.reduce();
			return cthis;
		}

		const num_int & operator = (const std::list<dig> & arg) {
			num_int & cthis = *this;
			signo=vplus;
			cthis.clear();
			cthis.resize( arg.size() );
			typename std::list<dig>::const_iterator it=arg.begin();
			typename std::list<dig>::const_iterator it_end=arg.end();
			for ( ; it != it_end ; ++it )
				cthis.push_front(*it);
			cthis.reduce();
			return cthis;
		}

		template<typename Int_T>
		operator Int_T()
		{
			const num_int & cthis = (*this);
			Int_T ret  = 0;
			Int_T potB = 1;
			for(Int_T I=0; I < cthis.size(); ++I) {
				ret += (potB * cthis[I]());
				potB *= B;
			}
			if (cthis.signo==vminus) ret -= potB;
			return ret;
		}


						/************************************/
						/*									*/
						/*	DIGITOS NO SIGNIFICATIVOS		*/
						/*									*/
						/************************************/


		usint ceros_a_la_izqda () const {
			const num_int & cthis = (*this);
			//digitos no significativos para números positivos
			bool Exit = false;
			int sz=0;
			const size_t fin= this->size();
			for ( int i=fin-1 ; (i >= 0) and (!Exit) ; --i) {
				bool char_es_0 = (cthis[i]==0);
				if (char_es_0){
					++sz;
				}
				else Exit=true;
			}
			return sz;
		}
		//digitos no significativos para números positivos

		usint unos_a_la_izqda () const {
			const num_int & cthis = (*this);
			//digitos no significativos para números negativos
			bool Exit = false;
			int sz=0;
			const size_t fin = cthis.size();
			for ( int i=fin-1 ; (i >= 0) and (!Exit) ; --i) {
				bool char_es_max = (cthis[i]==(dig_t<B>::d_Bm1()));
				if (char_es_max){
					++sz;
				}
				else Exit=true;
			}
			return sz;
			}
			//digitos no significativos para números negativos

			size_t ceros_a_la_drcha () const {
			const num_int & cthis = (*this);
			bool Exit = false;
			size_t sz=0;
			const size_t fin=this->size();
			const size_t finl = fin-1;
			if (cthis[finl]==0) {
				for ( int i=finl ; (i >=0) and (!Exit) ; --i) {
					if (cthis[i]==0) ++sz;
					else Exit=true;
				}
			}
			return sz;
		}


		size_t unos_a_la_drcha () const {
			const num_int & cthis = (*this);
			bool Exit = false;
			size_t sz=0;
			const size_t fin=cthis.size();
			const size_t finl = fin-1;
			if (cthis[finl]==0) {
				for ( int i=finl ; (i >=0) and (!Exit) ; --i) {
					if (cthis[i]==dig_t<B>::max) ++sz;
					else Exit=true;
				}
			}
			return sz;
		}

		bool is_filled_of_Bm1() const {
			const num_int & cthis = (*this);
			const int longitud = cthis.size();
			for(int i=0;i<longitud;i++)
				if (cthis[i]!=dig(B-1)) return false;
			return true;
		}

		bool is_filled_of_0() const {
			const num_int & cthis = (*this);
			const int longitud = cthis.size();
			for(int i=0;i<longitud;++i)
				if (cthis[i]!=dig(0)) return false;
			return true;
		}

		usint digs_no_significativos () const {
			const num_int & cthis = (*this);
			//digitos no significativos
			usint retorno;
			//if ((size()<1) and (signo==vminus)) return 0;
			if (signo==vplus) {
				retorno = cthis.ceros_a_la_izqda();
				return retorno;
			}
			else {
				retorno = cthis.unos_a_la_izqda();
				return retorno;
			}
		}

		usint digs_fracc_no_significativos () const {
			const uint_num<B> & cthis = (*this);
			//digitos no significativos
			return cthis.ceros_a_la_drcha();
		}

		//digitos no significativos para números positivos fraccionaria
		usint Bm1_a_la_izqda () const {
			num_int & cthis = *this;
			//digitos no significativos para números negativos
			bool Exit = false;
			usint sz=0;
			usint k=(cthis.size()-1);
			for ( ; (k > 0) and (!Exit) ; --k) {
				if (cthis[k]==(B-1)) ++sz;
				else Exit=true;
			}
			if ((k==0) and (cthis[0]==(B-1)) and (!Exit)) ++sz;
			return sz;
		}

		// digitos no significativos para números negativo
		usint Bm1_a_la_drcha () const {
			num_int & cthis = *this;
			// digitos no significativos para números negativos fraccionarios
			const size_t fin = cthis.size();
			bool Exit = false;
			usint sz=0;
			usint k=0;
			for ( ; (k < fin) and (!Exit) ; ++k) {
				if (cthis[k]==(B-1)) ++sz;
				else Exit=true;
			}
			return sz;
		}

					/************************************/
					/*									*/
					/*   OPERACIONES COMPARATIVAS  		*/
					/*									*/
					/************************************/

		bool operator == (const num_int & arg) const {
			const num_int & cthis = *this;
			const slint thisnsz = cthis.digs_no_significativos();
			const slint thisvsz = cthis.size()-thisnsz;
			const slint argnsz = arg.digs_no_significativos();
			const slint argvsz = arg.size()-argnsz;
			if ((thisvsz > argvsz)||(thisvsz < argvsz)||(signo!=arg.signo)) return false;
			else {
				for (slint k=(thisvsz-1);k>0;--k) {
					if (arg[k]!=cthis[k]) return false;
				}
				if ((arg[0])!=(cthis[0])) return false;
				else return true;
			}
		}

		bool operator != (const num_int & arg) const {
			const num_int & cthis = *this;
			const slint thisnsz = digs_no_significativos();
			const slint thisvsz = (cthis.size())-thisnsz;
			const slint argnsz = arg.digs_no_significativos();
			const slint argvsz = arg.size()-argnsz;
			if ((thisvsz > argvsz)||(thisvsz < argvsz)||(signo!=arg.signo))
				return true;
			else {
				for (slint k=(thisvsz-1);k>0;--k)
					if (arg[k]!=cthis[k])
						return true;
				if (arg[0]!= cthis[0])
					return true;
				else return false;
			}
		}

		bool operator >= (const num_int & arg) const {
			const num_int & cthis = *this;
			const slint thissz  = cthis.size();
			const slint thisnsz = ((thissz==1)?0:(cthis.digs_no_significativos()));
			const slint thisvsz = thissz-thisnsz;
			const slint argsz  = arg.size();
			const slint argnsz = ((argsz==1)?0:(arg.digs_no_significativos()));
			const slint argvsz = argsz-argnsz;

			if ((signo == vplus)and(arg.signo == vminus)) return true;
			else if ((signo == vminus)and(arg.signo == vplus)) return false;
			else if ((signo == vminus)and(arg.signo == vminus)){
				if (thisvsz < argvsz) return true;
				else if (thisvsz > argvsz) return false;
			}
			else if ((signo == vplus)and(arg.signo == vplus)){
				if (thisvsz > argvsz) return true;
				else if (thisvsz < argvsz) return false;
			}
			for (slint k=(thisvsz-1);k>-1;--k) {
				if ((cthis[k] > arg[k])) return true;
				else if ((cthis[k] < arg[k])) return false;
			}
			return true;
		}

		bool operator <= (const num_int & arg) const {
			const num_int & cthis = *this;
			const slint thissz  = cthis.size();
			const slint thisnsz = ((thissz==1)?0:(cthis.digs_no_significativos()));
			const slint thisvsz = thissz-thisnsz;
			const slint argsz  = arg.size();
			const slint argnsz = ((argsz==1)?0:(arg.digs_no_significativos()));
			const slint argvsz = argsz-argnsz;

			if ((signo == vplus)and(arg.signo == vminus)) return false;
			else if ((signo == vminus)and(arg.signo == vplus)) return true;
			else if ((signo == vminus)and(arg.signo == vminus)){
				if (thisvsz < argvsz) return false;
				else if (thisvsz > argvsz) return true;
			}
			else if ((signo == vplus)and(arg.signo == vplus)){
				if (thisvsz > argvsz) return false;
				else if (thisvsz < argvsz) return true;

			}
			for (slint k=(thisvsz-1);k>-1;--k) {
				if ((cthis[k] > arg[k])) return false;
				else if ((cthis[k] < arg[k])) return true;
			}
			return true;
		}

		bool operator >  (const num_int & arg ) const {
			const num_int & cthis = *this;
			const slint thissz  = cthis.size();
			const slint thisnsz = ((thissz==1)?0:(cthis.digs_no_significativos()));
			const slint thisvsz = thissz-thisnsz;
			const slint argsz  = arg.size();
			const slint argnsz = ((argsz==1)?0:(arg.digs_no_significativos()));
			const slint argvsz = argsz-argnsz;

			if ((signo == vplus)and(arg.signo == vminus)) return true;
			else if ((signo == vminus)and(arg.signo == vplus)) return false;
			else if ((signo == vminus)and(arg.signo == vminus))
			{
				if (thisvsz < argvsz) return true;
				else if (thisvsz > argvsz) return false;
			}
			else if ((signo == vplus)and(arg.signo == vplus))
			{
				if (thisvsz > argvsz) return true;
				else if (thisvsz < argvsz) return false;

			}
			for (slint k=(thisvsz-1);k>-1;--k)
			{
				if ((cthis[k] > arg[k])) return true;
				else if ((cthis[k] < arg[k])) return false;
			}
			return false;
		}

		bool operator < (const num_int & arg) const {
			const num_int & cthis = *this;
			const slint thissz  = cthis.size();
			const slint thisnsz = ((thissz==1)?0:(cthis.digs_no_significativos()));
			//cout << "J vale   " << cthis << endl;
			const slint thisvsz = thissz-thisnsz;
			const slint argsz  = arg.size();
			const slint argnsz = ((argsz==1)?0:(arg.digs_no_significativos()));
			//cout << "I vale   " << arg << endl;
			const slint argvsz = argsz-argnsz;

			if ((signo == vplus)and(arg.signo == vminus)) return false;
			else if ((signo == vminus)and(arg.signo == vplus)) return true;
			else if ((signo == vminus)and(arg.signo == vminus)){
				if (thisvsz < argvsz) return false;
				else if (thisvsz > argvsz) return true;
			}
			else if ((signo == vplus)and(arg.signo == vplus)){
				if (thisvsz > argvsz) return false;
				else if (thisvsz < argvsz) return true;
			}
			for (slint k=(thisvsz-1);k>-1;--k) {
				if ((cthis[k] > arg[k])) return false;
				else if ((cthis[k] < arg[k])) return true;
			}
			return false;
		}

				/************************************/
				/*									*/
				/*	OPERACIONES ARITMETICAS 		*/
				/*									*/
				/************************************/

		// el nuevo codigo de operator +
		num_int operator + (const num_int & arg) const {
			const num_int & cthis = *this;
			num_int ret(cthis);
			const size_t szt = cthis.size();
			const size_t sza = arg.size();
			const size_t szd = ((szt>=sza)?(szt):(sza))+2;
			ret.resize(szd);
			size_t k = 0;
			pardigs tempt;
			dig tempa;
			dig carry = dig(0);
			for(;k<szd;++k)
			{
				tempt = pardigs_t<B>(dig(0),cthis(k));
				tempt += arg(k);
				tempt += carry;
				ret[k] = tempt.g_uds();
				carry  = tempt.g_decs();
			}
			if (cthis.signo==arg.signo)
				ret.signo = cthis.signo;
			else
				if (carry != dig(0))
					ret.signo = vplus;
				else
					ret.signo = vminus;
			ret.aux = spardigs();
			ret.reduce();
			return ret;
		}

		num_int operator - (const num_int & arg) const {
			const num_int & cthis = (*this);
			num_int ret;
			const size_t szt = cthis.size();
			const size_t sza = arg.size();
			const size_t szd = ((szt>=sza)?(szt):(sza))+2;
			ret.resize(szd);
			size_t k = 0;
			pardigs tempt;
			dig tempa;
			dig carry = dig(1);
			for(;k<szd;++k)
			{
				tempt = pardigs_t<B>(dig(0),cthis(k));
				tempt += !(arg(k));
				tempt += carry;
				ret[k] = tempt.g_uds();
				carry  = tempt.g_decs();
			}
			if (cthis.signo!=arg.signo) {
				ret.signo = cthis.signo;
			}
			else if (cthis.signo==arg.signo) {
				if (carry != dig(0)) {
					ret.signo = vplus;
				}
				else {
					ret.signo = vminus;
				}
			}
			ret.aux = spardigs();
			ret.reduce();
			return ret;
		}

		num_int operator - () const {
			const num_int & cthis = *this;
			num_int ret;
			if (cthis==num_int<B>(0)) return num_int<B>(0);
			const size_t szd = cthis.size()+1;
			ret.resize(szd);
			size_t k = 0;
			pardigs tempt;
			dig carry = dig(1);
			for(;k<szd;++k)
			{
				tempt = pardigs_t<B>(dig(0),!(cthis(k)));
				tempt += carry;
				ret[k] = tempt.g_uds();
				carry  = tempt.g_decs();
			}
			if (cthis.signo==vminus) {
				ret.signo = vplus;
			}
			else {
				ret.signo = vminus;
			}
			ret.aux = -(cthis.aux);
			ret.reduce();
			return ret;
		}

		// Utilizamos una funcion num_int * dig_t
		num_int operator * (const num_int & arg) const {
			num_int & cthis = *this;
			num_int sumatemp;
			num_int multtemp;
			num_int m1(cthis.abs());
			m1.reduce();
			num_int m2(arg.abs());
			m2.reduce();
			multtemp = cthis*m2[0];
			sumatemp = multtemp;
			for (usint j = 1 ; j < m2.size() ; ++j) {
				multtemp = cthis*m2[j]; // num_int * dig_t
				multtemp.insert(0,j,0);
				sumatemp += multtemp;
			}
			if (signo!=arg.signo) sumatemp.mC_B();
			return sumatemp;
		}

		num_int operator / (const num_int & arg) const {
			num_int & cthis = *this;
			const sign_e sgn_ndo = signo;
			const sign_e sgn_sor = arg.signo;
			num_int dvndo_int(this->abs());
			dvndo_int.reduce();
			num_int rem(dvndo_int);

			num_int dvsor_int(arg.abs());
			dvsor_int.reduce();

			const usint cssor = dvsor_int.ceros_a_la_drcha(); //¿?

			num_int dvndo_fra(dvndo_int.substr(0,cssor));
			dvsor_int.erase(0,cssor);// division por una potencia de B

			dvsor_int.reduce();
			dvndo_int.reduce();

			dvndo_fra.reduce();

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

				rem = rem.lst_digs.insert(0,cssor,0);
				rem += dvndo_fra;
			* */
			if (sgn_ndo!=sgn_sor) dvndo_int.mC_B();
			// rehacer el resto tomando en cuenta los ceros quitados
			// acomodar el formato al signo de la operacion
			// determinar el signo de la operacion
			return dvndo_int;
		}

		num_int operator % (const num_int & arg) const {
			num_int & cthis = *this;
			num_int dvndo_int(this->abs());
			dvndo_int.reduce();
			num_int rem(dvndo_int);

			num_int dvsor_int(arg.abs());
			dvsor_int.reduce();

			const usint cssor = dvsor_int.ceros_a_la_drcha(); //¿?

			num_int dvndo_fra(dvndo_int.substr(0,cssor));
			dvsor_int.lst_digs.erase(0,cssor);// division por una potencia de B

			dvsor_int.reduce();
			dvndo_int.reduce();

			dvndo_fra.reduce();

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
			// rehacer el resto tomando en cuenta los ceros quitados
			// acomodar el formato al signo de la operacion
			// determinar el signo de la operacion
			return rem;
		}

		//num_int operator + (spardigs) const;
		//num_int operator - (spardigs) const;
		//num_int operator * (spardigs) const;
		//num_int operator / (spardigs) const;
		//num_int operator % (spardigs) const;
		//num_int operator + (n2digs_t) const;
		//num_int operator - (n2digs_t) const;
		//num_int operator * (n2digs_t) const;
		//num_int operator / (n2digs_t) const;
		//num_int operator % (n2digs_t) const;
		//num_int operator + (pardigs) const;
		//num_int operator - (pardigs) const;

		num_int operator + (dig arg) const {
			const num_int<B> & cthis = (*this);
			num_int<B> ret(cthis);
			const num_int<B> ARG(arg);
			ret += ARG;
			return ret;
		}

		num_int operator - (dig arg) const {
			const num_int<B> & cthis = (*this);
			num_int<B> ret(cthis);
			const num_int<B> ARG(arg);
			ARG.mC_B();
			ret += ARG;
			return ret;
		}

		num_int operator * (dig a) const {
			const num_int & cthis = *this;
			pardigs temp;
			dig  	carry=0;
			num_int ret(cthis);

			if (a==dig_t<B>(0)) return num_int<B>(0);
			else if	(a==dig_t<B>(1)) return ret;

			if(cthis==num_int<B>(0)) return ret;
			else if (cthis==num_int<B>(1)) {
				ret = a;
				return ret;
			}
			// Caso GENERAL
			if (cthis.signo==vminus) ret.mC_B();
			for ( usint k=0 ; k < (cthis.size()) ; ++k ) {
				temp = pardigs_t<B>(dig_t<B>(0),ret[k]);
				temp *= a;
				temp += carry;
				ret[k]= temp.g_first();
				carry=temp.g_second();
			}

			temp = pardigs_t<B>(dig_t<B>(0),ret[cthis.size()]);
			temp *= a;
			temp += carry;
			ret.push_back(temp.g_first());
			ret.push_back(temp.g_second());

			if (cthis.signo==vminus) ret.mC_B();

			ret.reduce();
			return ret;
		}

		// num_int operator / (dig) const;
		// num_int operator % (dig) const;

		num_int operator + (pardigs_t<B> arg) const {
			const num_int<B> & cthis = (*this);
			num_int<B> ret(cthis);
			const num_int<B> ARG(arg);
			ret += ARG;
			return ret;
		}

		num_int operator - (pardigs_t<B> arg) const {
			const num_int<B> & cthis = (*this);
			num_int<B> ret(cthis);
			const num_int<B> ARG(arg);
			ARG.mC_B();
			ret += ARG;
			return ret;
		}

		num_int operator * (pardigs_t<B> a) const {
			const num_int & cthis = *this;
			const ullint szt = cthis.size();
			pardigs_t<B>	temp(0,0);
			pardigs_t<B>	carry(0,0);
			num_int ret;
			ret.resize(szt+2);
			for(ullint i=0 ; i<szt+2 ; ++i) {
				ret[i]=cthis(i);
			}
			ret.signo = cthis.signo;
			if (a==pardigs_t<B>(0,0)) return num_int<B>(0);
			else if	(a==pardigs_t<B>(0,1)) return ret;

			if(cthis==num_int<B>(0)) return ret;
			else if (cthis==num_int<B>(1)) {
				ret = a;
				return ret;
			}
			else if (cthis.signo == vminus) {
				if (cthis.is_filled_of_0()) {
					pardigs_t<B> b(a);
					b.mC_B();
					ret.push_back(b.g_uds());
					ret.push_back(b.g_decs());
					return ret;
				}
			}
			// Caso GENERAL
			if (cthis.signo==vminus)
				ret.mC_B();
			for ( ullint k=0 ; k < szt ; ++k ) {
				temp   = pardigs_t<B>(dig_t<B>(0),cthis[k]);
				temp  *= a.g_uds();
				temp  += carry;
				ret[k] = temp.g_uds();
				carry  = pardigs_t<B>(0,temp.g_decs());
			}

			temp = pardigs_t<B>(dig_t<B>(0),cthis(szt));
			temp *= a.g_uds();
			temp += carry;
			ret[szt]=temp.g_uds();
			ret[szt+1]=temp.g_decs();

			const dig_t<B>		dig_mult(a.g_decs());
			carry = pardigs_t<B>(0,0);
			ullint K=1;
			for ( ullint k=0 ; k < szt ; ++k,++K ) {
				temp = pardigs_t<B>(dig_t<B>(0),cthis[k]);
				temp *= dig_mult;
				temp += carry;
				carry = pardigs_t<B>(0,temp.g_decs());
				temp.n2digs::m_decs(0);
				temp += ret(K);
				ret[K]= temp.g_uds();
				carry += temp.g_decs();
			}

			temp = pardigs_t<B>(dig_t<B>(0),cthis(szt));
			temp *= dig_mult;
			temp += carry;
			carry = pardigs_t<B>(0,temp.g_decs());
			temp.n2digs::m_decs(0);
			temp += ret(K);
			ret[K]= temp.g_uds();
			carry += temp.g_decs();
			++K;

			temp = pardigs_t<B>(dig_t<B>(0),cthis(szt+1));
			temp *= dig_mult;
			temp += carry;
			carry = pardigs_t<B>(0,temp.g_decs());
			temp.n2digs::m_decs(0);
			temp += ret(K);
			ret[K]= temp.g_uds();
			//carry += temp.g_decs();

			if (cthis.signo==vminus) ret.mC_B();

			ret.reduce();
			return ret;
		}

		// num_int operator / (pardigs) const;
		// num_int operator % (pardigs) const;


		num_int operator + (spardigs_t<B> arg) const {
			const num_int<B> & cthis = (*this);
			num_int<B> ret(cthis);
			const num_int<B> ARG(arg);
			ret += ARG;
			return ret;
		}

		num_int operator - (spardigs_t<B> arg) const {
			const num_int<B> & cthis = (*this);
			num_int<B> ret(cthis);
			const num_int<B> ARG(arg);
			ARG.mC_B();
			ret += ARG;
			return ret;
		}
/*
		num_int operator * (spardigs_t<B> a) const {
			const num_int & cthis = *this;
			pardigs_t<B> temp;
			dig  	carry=0;
			num_int ret(cthis);

			if (a==spardigs_t<B>(0)) return num_int<B>(0);
			else if	(a==spardigs_t<B>(vplus,0,1)) return ret;
			else if	(a==spardigs_t<B>(vplus,0,B-1)) {
				ret.push_front(dig_t<B>(0));
				ret -= cthis;
				return ret;
			}
			else if	(a==spardigs_t<B>(vplus,B-1,B-1)) {
				ret.push_front(dig_t<B>(0));
				ret -= cthis;
				return ret;
			}
			else if	(a==spardigs_t<B>(vminus,B-1,0)) {

			}
			else if	(a==spardigs_t<B>(vminus,B-1,B-1)) {

			}
			else if	(a==spardigs_t<B>(vminus,0,B-1)) {

			}
			else if	(a==spardigs_t<B>(vminus,0,1)) {

			}
			if(cthis==num_int<B>(0)) return ret;
			else if (cthis==num_int<B>(1)) {
				ret = a;
				return ret;
			}
			else if (cthis==num_int<B>(-1)) {
				ret = a;
				ret.mC_B();
				return ret;
			}
			else if (cthis.signo == vminus) {
				if (cthis.is_filled_of_0()) {
					pardigs_t<B> b(a);
					b.mC_B();
					ret.push_back(b.uds());
					ret.push_back(b.decs());
					return ret;
				}
				else if (cthis.is_filled_of_Bm1()) {
					pardigs_t<B> b(a);
					b.mC_B();
					for(size_t i=0;i<cthis.size();++i)
						ret[i]=dig_t<B>(0);
					ret.push_back(0);
					ret.push_back(b.uds());
					ret.push_back(b.decs());
					ret -= cthis;
					return ret;
				}
			}
			else if (cthis.signo == vplus) {
				if (cthis.is_filled_of_Bm1()) {
					for(size_t i=0;i<cthis.size();++i)
						ret[i]=dig_t<B>(0);
					ret.push_back(a.uds());
					ret.push_back(a.decs());
					ret -= a;
					return ret;
				}
			}
			// Caso GENERAL
			if (cthis.signo==vminus) ret.mC_B();
			for ( usint k=0 ; k < (cthis.size()) ; ++k ) {
				temp = pardigs_t<B>(dig_t<B>(0),cthis[k];
				temp *= a.uds();
				temp += carry;
				ret[k]= temp.g_first();
				carry=temp.g_second();
			}

			temp = pardigs_t<B>(dig_t<B>(0),ret(cthis.size()));
			temp *= a.uds();
			temp += carry;
			ret.push_back(temp.g_first());
			ret.push_back(temp.g_second());

			pardigs_t<B>	pardigstemp(0,0);
			dig_t<B>		digtemp(0);
			usint K=1;
			for ( usint k=0 ; k < (cthis.size()) ; ++k,++K ) {
				temp = pardigs_t<B>(dig_t<B>(0),cthis[k]);
				temp *= a.decs();
				temp += carry;
				digtemp = temp.g_first();
				pardigstemp.p_first(ret(K));
				pardigstemp += digtemp;
				ret[K]= pardistemp.g_first();
				pardigstemp.p_first(pardistemp.g_second());
				pardigstemp.p_second(0);
				pardigstemp += temp.g_second();
				carry=pardigstemp.g_first();
			}

			temp = pardigs_t<B>(dig_t<B>(0),cthis(cthis.size());
			temp *= a.decs();
			temp += carry;
			digtemp = temp.g_first();
			pardigstemp.p_first(ret(K));
			++K;
			pardigstemp += digtemp;
			ret.push_back(pardistemp.g_first());
			pardigstemp.p_first(pardistemp.g_second());
			pardigstemp.p_second(0);
			pardigstemp += temp.g_second();
			carry=pardigstemp.g_first();
			temp = pardigs_t<B>(dig_t<B>(0),cthis(cthis.size()+1);
			temp *= a.decs();
			temp += carry;
			digtemp = temp.g_first();
			pardigstemp.p_first(ret(K));
			++K;
			pardigstemp += digtemp;
			ret.push_back(pardistemp.g_first());
			pardigstemp.p_first(pardistemp.g_second());
			pardigstemp.p_second(0);
			pardigstemp += temp.g_second();
			carry=pardigstemp.g_first();
			temp = pardigs_t<B>(dig_t<B>(0),cthis(cthis.size()+2);
			temp *= a.decs();
			temp += carry;
			digtemp = temp.g_first();
			pardigstemp.p_first(ret(K));
			pardigstemp += digtemp;
			ret.push_back(pardistemp.g_first());

			if (cthis.signo==vminus) ret.mC_B();

			ret.reduce();
			return ret;
		}
*/
		// num_int operator * (spardigs) const;
		// num_int operator / (spardigs) const;
		// num_int operator % (spardigs) const;


					/************************************/
					/*									*/
					/*		OPERACIONES ARITMETICAS		*/
					/*		CON ASIGNACION				*/
					/*									*/
					/************************************/

		const num_int & operator += (const num_int & arg) {
			num_int & cthis = *this;
			const size_t szt = cthis.size();
			const size_t sza = arg.size();
			const size_t szd = ((szt>=sza)?(szt):(sza))+2;
			size_t k = 0;
			pardigs tempt;
			dig tempa;
			dig carry = dig(0);
			for(;k<szt;++k)
			{
				tempt = pardigs_t<B>(dig(0),cthis(k));
				tempt += arg(k);
				tempt += carry;
				cthis[k] = tempt.g_uds();
				carry  = tempt.g_decs();
			}
			for(;k<szd;++k)
			{
				tempt = pardigs_t<B>(dig(0),cthis(k));
				tempt += arg(k);
				tempt += carry;
				cthis.push_back(tempt.g_uds());
				carry  = tempt.g_decs();
			}
			if (cthis.signo!=arg.signo) {
				if (carry != dig(0)) {
					cthis.signo = vplus;
				}
				else {
					cthis.signo = vminus;
				}
			}
			cthis.aux = spardigs();
			cthis.reduce();
			return cthis;
		}

		const num_int & operator -= (const num_int & arg) {
			num_int & cthis = *this;
			const size_t szt = cthis.size();
			const size_t sza = arg.size();
			const size_t szd = ((szt>=sza)?(szt):(sza))+2;
			size_t k = 0;
			pardigs tempt;
			dig tempa;
			dig carry = dig(1);
			for(;k<szt;++k)
			{
				tempt = pardigs_t<B>(dig(0),cthis(k));
				tempt += !(arg(k));
				tempt += carry;
				cthis[k] = tempt.g_uds();
				carry  = tempt.g_decs();
			}
			for(;k<szd;++k)
			{
				tempt = pardigs_t<B>(dig(0),cthis(k));
				tempt += !(arg(k));
				tempt += carry;
				cthis.push_back(tempt.g_uds());
				carry  = tempt.g_decs();
			}
			if (cthis.signo==arg.signo) {
				if (carry != dig(0)) {
					cthis.signo = vplus;
				}
				else {
					cthis.signo = vminus;
				}
			}
			cthis.aux = spardigs();
			cthis.reduce();
			return cthis;
		}

		const num_int & operator *= (const num_int & arg) {
			num_int & cthis = *this;
			num_int multtemp;
			const sign_e sgn_ndo = signo;
			this->absp();
			this->reduce();
			num_int & m1 = (*this);
			num_int m2(arg.abs());
			m2.reduce();

			cthis *= m2[0];
			for (usint j = 1 ; j < m2.size() ; ++j) {
				multtemp = m1*m2[j];
				multtemp.insert(0,j,0);
				cthis += multtemp;
			}
			if (sgn_ndo!=arg.signo) m1.mC_B();
			return (*this);
		}

		const num_int & operator /= (const num_int & arg) {
			num_int & cthis = *this;
			const sign_e sgn_ndo = signo;
			const sign_e sgn_sor = arg.signo;
			this->absp();
			num_int & dvndo_int = *this;
			dvndo_int.reduce();
			num_int rem(dvndo_int);

			num_int dvsor_int(arg.abs());
			dvsor_int.reduce();

			const usint cssor = dvsor_int.ceros_a_la_drcha(); //¿?

			num_int dvndo_fra(dvndo_int.substr(0,cssor));
			dvsor_int.lst_digs.erase(0,cssor);// division por una potencia de B

			dvsor_int.reduce();
			dvndo_int.reduce();

			dvndo_fra.reduce();

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

				rem = rem.lst_digs.insert(0,cssor,0);
				rem += dvndo_fra;
			* */
			if (sgn_ndo!=sgn_sor) dvndo_int.mC_B();
			// rehacer el resto tomando en cuenta los ceros quitados
			// acomodar el formato al signo de la operacion
			// determinar el signo de la operacion
			return dvndo_int;
		}

		const num_int & operator %= (const num_int & arg) {
			num_int & cthis = *this;
			(*this).absp();
			num_int & rem = *this;
			rem.reduce();
			num_int dvndo_int(rem);

			num_int dvsor_int(arg.abs());
			dvsor_int.reduce();

			const usint cssor = dvsor_int.ceros_a_la_drcha(); //¿?

			num_int dvndo_fra(dvndo_int.substr(0,cssor));
			dvsor_int.lst_digs.erase(0,cssor);// division por una potencia de B


			dvsor_int.reduce();
			dvndo_int.reduce();

			dvndo_fra.reduce();

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

			rem = rem.lst_digs.insert(0,cssor,0);
			rem += dvndo_fra;

			return rem;
		}

		//const num_int & operator += (spardigs);
		//const num_int & operator -= (spardigs);
		//const num_int & operator *= (spardigs);
		//const num_int & operator /= (spardigs);
		//const num_int & operator %= (spardigs);
		//const num_int & operator += (pardigs);
		//const num_int & operator -= (pardigs);

		const num_int & operator *= (pardigs a) {
			num_int & cthis = *this;
			pardigs 		temp;
			dig  			carry = 0;
			num_int & 		ret = (*this);
			for ( usint k=0 ; k < cthis.size() ; ++k ) {
				temp = cthis[k]*(a.g_first());
				temp += carry;
				ret[k]= temp.g_first();
				carry=temp.g_second();
			}
			if (carry != 0)
				ret.insert((cthis.size())-1,1,carry);
			ret.reduce();
			carry = 0;
			for ( usint k=0 ; k < ((cthis.size())-1) ; ++k ) {
				temp = cthis[k]*(a.g_second());
				temp += carry;
				ret.substr(k+1,ret.size()-1)+= temp.g_first();//¿?
				carry=temp.g_second();
			}
			if (carry != 0)
				ret.insert((cthis.size())-1,1,carry);
			ret.reduce();

			if (signo==vminus) ret.mC_B();

			return ret;
		}

		//const num_int & operator /= (pardigs);
		//const num_int & operator %= (pardigs);

		const num_int & operator += (dig arg) {
			num_int & cthis = *this;
			num_int<B> ARG(arg);
			cthis+=ARG;
			return cthis;
		}

		const num_int & operator -= (dig arg) {
			num_int & cthis = *this;
			num_int<B> ARG(arg);
			cthis-=ARG;
			return cthis;
		}

		const num_int & operator *= (dig a) {
			num_int & cthis = *this;
			pardigs temp;
			dig		carry=0;

			if (a==dig_t<B>(0)) {
				cthis = num_int<B>(0);
				return cthis;
			}
			else if	(a==dig_t<B>(1)) {
				return cthis;
			}
			else if	(a==dig_t<B>(B-1)) {
				cthis.push_front(dig_t<B>(0));
				num_int<B> temp(cthis);
				temp.pop_front();
				cthis -= temp;
				return cthis;
			}

			if(cthis==num_int<B>(0)) {
				return cthis;
			}
			else if (cthis==num_int<B>(1)) {
				cthis[0] = a;
				return cthis;
			}
			else if (cthis==num_int<B>(-1)) {
				dig_t<B> b(a);
				b.mC_B();
				cthis[0]=b;
				return cthis;
			}
			else if (cthis.signo == vminus) {
				if (cthis.is_filled_of_0()) {
					dig_t<B> b(a);
					b.mC_B();
					cthis.push_back(b);
					return cthis;
				}
				else if (cthis.is_filled_of_Bm1()) {
					dig_t<B> b(a);
					b.mC_B();
					num_int<B> temp(cthis);
					temp.pop_front();
					for(size_t i=0;i<cthis.size();++i) cthis[i]=dig_t<B>(0);
					cthis.push_back(0);
					cthis.push_back(b);
					cthis -= temp;
					return cthis;
				}
			}
			else if (cthis.signo == vplus) {
				if (cthis.is_filled_of_Bm1()) {
					for(size_t i=0;i<cthis.size();++i) cthis[i]=dig_t<B>(0);
					cthis.push_back(a);
					cthis -= a;
					return cthis;
				}
			}
			// Caso GENERAL
			const sign_e signe_place = cthis.signo;
			if (signe_place==vminus) cthis.mC_B();
			for ( size_t k=0 ; k < (cthis.size()) ; ++k ) {
				temp = pardigs_t<B>(dig_t<B>(0),cthis[k]);
				temp *= a;
				temp += carry;
				cthis[k]= temp.g_first();
				carry=temp.g_second();
			}

			temp = pardigs_t<B>(dig_t<B>(0),cthis(cthis.size()));
			temp *= a;
			temp += carry;
			cthis.push_back(temp.g_first());
			cthis.push_back(temp.g_second());

			if (signe_place==vminus) cthis.mC_B();

			cthis.reduce();
			return cthis;
		}

		//	const num_int & operator /= (dig);
		//	const num_int & operator %= (dig);

					/****************************/
					/*							*/
					/*   COMPLEMENTO A BASE Y 	*/
					/* 		BASE MENOS 1		*/
					/*							*/
					/****************************/

		num_int operator !() const {
			num_int & cthis = *this;
			num_int cpy(*this);
			const striterator fin = cpy.end();
			striterator  it = cpy.begin();
			for ( ; it != fin ; ++it )
				(*it) = (!(*it));
			cpy.signo = ((cpy.signo==vminus)?vplus:vminus);
			cpy.aux = spardigs();
			cpy.reduce();
			return cpy;
		}

					/****************************/
					/*							*/
					/*  	 MODIFICADOR		*/
					/* 	COMPLEMENTO A BASE Y 	*/
					/* 		BASE MENOS 1		*/
					/*							*/
					/****************************/

		const num_int & mC_B() {
			num_int & cthis = (*this);

			if (cthis==num_int<B>(0)) return cthis;

			const size_t szt = cthis.size();
			size_t k = 0;
			pardigs tempt;
			dig carry = dig(1);
			for(;k<szt;++k)
			{
				tempt = pardigs_t<B>(dig(0),!(cthis(k)));
				tempt += carry;
				cthis[k] = tempt.g_uds();
				carry  = tempt.g_decs();
			}

			tempt = pardigs_t<B>(dig(0),!(cthis(szt)));
			tempt += carry;
			cthis.push_back(tempt.g_uds());
			carry  = tempt.g_decs();
			tempt = pardigs_t<B>(dig(0),!(cthis(szt+1)));
			tempt += carry;
			cthis.push_back(tempt.g_uds());

			if (cthis.signo==vminus) {
				cthis.signo = vplus;
			}
			else {
				cthis.signo = vminus;
			}
			cthis.aux = -(cthis.aux);
			cthis.reduce();
			return cthis;
		}

		num_int & mC_Bm1()
		{
			num_int & cthis = (*this);

			if (cthis.is_filled_of_0()) {
				if (cthis.signo==vplus) {
					cthis.signo=vminus;
				}
				else if (cthis.signo==vminus) {
					cthis.signo=vplus;
				}
				return cthis;
			}

			const size_t szt = cthis.size();
			size_t k = 0;
			pardigs tempt;
			dig carry = dig(0);
			for(;k<szt;++k)
			{
				tempt = pardigs_t<B>(dig(0),!(cthis(k)));
				tempt += carry;
				cthis[k] = tempt.g_uds();
				carry  = tempt.g_decs();
			}

			tempt = pardigs_t<B>(dig(0),!(cthis(szt)));
			tempt += carry;
			cthis.push_back(tempt.g_uds());

			if (cthis.signo==vminus) {
				cthis.signo = vplus;
			}
			else {
				cthis.signo = vminus;
			}
			cthis.aux = -(cthis.aux);
			cthis.reduce();
			return cthis;
		}

		num_int C_Bm1() const
		{
			num_int & cthis = (*this);
			num_int ret(cthis);
			ret.mC_Bm1();
			return ret;
		}

					/****************************/
					/*							*/
					/*		ABSOLUTO			*/
					/*							*/
					/****************************/

		num_int abs() const {
			const num_int ret(*this);
			if (signo==vminus)	ret.mC_B();
			ret.reduce();
			return ret;
		}

		const num_int & m_abs() {
			num_int & cthis = (*this);
			if (signo==vminus) cthis.mC_B();
			cthis.reduce();
			return cthis;
		}

					/****************************/
					/*							*/
					/*  DIVIDIR ENTRE BASE O 2	*/
					/*							*/
					/****************************/

		num_int divB () const {
			num_int cpy(*this);
			cpy.reduce();
			sign_e sgn = cpy.signo;
			cpy.absp();
			cpy.cthis.erase(0,1);
			if (sgn==vminus) cpy.mC_B();
			cpy.reduce();
			return cpy;
		}

		dig remB () const {
			num_int cpy(*this);
			cpy.reduce();
			if (signo==vminus) return cpy.absp();
			return cpy.lst_digs[0];
		}

		const num_int & m_divB() {
			num_int & cpy = (*this);
			cpy.reduce();
			sign_e sgn = cpy.signo;
			cpy.absp();
			cpy.cthis.erase(0,1);
			if (sgn==vminus) cpy.mC_B();
			cpy.reduce();
			return cpy;
		}

		dig m_remB() {
			num_int & cpy = (*this);
			cpy.reduce();
			if (signo==vminus) return cpy.m_abs();
			return cpy[0];
		}

		num_int div2 () const {
			num_int & cthis = *this;
			const sign_e sgn = signo;
			num_int dvndo_int(cthis.abs());
			dvndo_int.reduce();
			num_int rem(dvndo_int);
			const dig dos = 2;

			num_int dvsor_int(dos);

			const usint cssor = ((B==2)?(1):(0));

			num_int dvndo_fra(dvndo_int.substr(0,cssor));
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
			if (sgn==vminus) dvndo_int.mC_B();
			// rehacer el resto tomando en cuenta los ceros quitados
			// acomodar el formato al signo de la operacion
			// determinar el signo de la operacion
			return dvndo_int;
		}

		dig rem2 () const {
			num_int & cthis = *this;
			sign_e sgn = signo;
			num_int cpy = cthis.reduce();
			cpy.absp();
			cpy.reduce();
			if (B%2==1) {
				if (cpy.lst_digs.size()==1)
					return dig::Rem2(cpy.lst_digs[0]);
				else {
					usint paridad = 0;
					for ( usint k=0 ; k < cpy.lst_digs.size() ; ++k )
						paridad += dig::Dig2UInt(dig::Rem2(cpy[k]));
					paridad %= 2;
					return dig(paridad);
				}
			}
			else {
				return dig::Rem2(cpy[0]);
			}
		}

		const num_int & m_div2() {
			num_int & cthis = *this;
			sign_e sgn = signo;
			cthis.absp();
			cthis.reduce();
			num_int & dvndo_int = (*this);
			num_int rem(dvndo_int);
			const dig dos = 2;

			num_int dvsor_int(dos);

			const usint cssor = ((B==2)?(1):(0));

			num_int dvndo_fra(dvndo_int.substr(0,cssor));
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

				rem = rem.lst_digs.insert(0,cssor,0);
				rem += dvndo_fra;
			* */
			if (sgn==vminus) dvndo_int.mC_B();
			// rehacer el resto tomando en cuenta los ceros quitados
			// acomodar el formato al signo de la operacion
			// determinar el signo de la operacion
			return dvndo_int;
		}

		dig m_rem2() {
			num_int & cthis = *this;
			sign_e sgn = signo;
			cthis.absp();
			cthis.reduce();
			num_int & cpy = (*this);
			if (B%2==1) {
				if (cpy.size()==1)
					return dig::Rem2(cpy.lst_digs[0]);
				else {
					usint paridad = 0;
					for ( usint k=0 ; k < cpy.size() ; ++k )
						paridad += dig::Dig2UInt(dig::Rem2(cpy[k]));
					paridad %= 2;
					return dig(paridad);
				}
			}
			else {
				return dig::Rem2(cpy[0]);
			}
		}

		/*		num_int div3() const;
				const num_int & div3p();
				dig rem3() const;
				const num_int & rem3p();
				const dig rem4() const;
				dig rem5() const;
				dig rem6() const;
				num_int div7 () const;
				dig rem7 () const;
				const num_int & div7p();
				dig rem7p();
				const dig rem8() const;
		*/

		dig	 		remBm1() 	const {
			num_int cthis(*this),suma;
			sign_e sgn = signo;
			cthis.abs();
			cthis.reduce();
			suma.reduce();
			suma.lst_digs.insert(0,1,0);
			suma.lst_digs.erase(0,(cthis.size())-1);
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
		// num_int	 		divBm1() 	const;
		// const num_int	& 	divBm1p()		;

private:

		//		inline void	div3_step(pair< n2digs_t , usint > & S) const;
		//		inline void div3p_step(pair< n2digs_t , usint > & S);
		//		inline void	div7_step(pair< n2digs_t , usint > & S) const;
		//		inline void div7p_step(pair< n2digs_t , usint > & S);

					/****************************/
					/*							*/
					/*	Division Generica		*/
					/*							*/
					/****************************/


		inline void	div_gen_step(const num_int & dvsor, num_int & rem, num_int & coc, usint & ndig) const {
			num_int & cthis = *this;
			const usint maxpos = (cthis.size())-1;
			const num_int & dvndo = (*this);
			rem.insert(0,1,dvndo[maxpos-ndig]);
			if (rem < coc) {
				coc.insert(0,1,0);
			}
			else if (rem == coc) {
				coc.insert(0,1,1);
				rem.erase(0,rem.size()-1);
				rem[0]=0;
			}
			else {
				if (rem.size() > dvsor.size()) {
					pardigs dighrem        = pardigs(rem[rem.size()-1],rem[rem.size()-2]) ;
					pardigs dighsor        = pardigs(0,dvsor[dvsor.size()-1]) ;
					pardigs & digcocprueba = dighrem ;
					digcocprueba /= dighsor ;
					num_int remprueba = dvsor*digcocprueba ;
					for ( dig_t<B> ix = 0  ; ix < pardigs(1,0) ; ix += 1 ) {
						if ( remprueba > rem ) {
							--digcocprueba;
							remprueba -= dvsor;
						}
						else {
							rem -= remprueba;
							coc.insert(0,1,digcocprueba);
							break;
						}
					}
				}
				else {
					dig_t<B> dighrem        = rem[rem.size()-1];
					dig_t<B> dighsor        = dvsor[dvsor.size()-1];
					dig_t<B> & digcocprueba = dighrem;
					digcocprueba /= dighsor;
					num_int remprueba = dvsor*digcocprueba; // no está implementada esta función
					dig_t<B> ix = 0 ;
					for (  ; ix < pardigs(1,0) ; ix += 1 ) {
						if ( remprueba > rem ) {
							--digcocprueba;
							remprueba -= dvsor;
						}
						else {
							rem -= remprueba;
							coc.insert(0,1,digcocprueba);
							break;
						}
					}
				}
			}
			++ndig;
			return;
		}

		inline void divp_gen_step(const num_int & dvsor, num_int & rem, num_int & coc, usint & ndig) {
			num_int & cthis = *this;
			const usint maxpos = (cthis.size())-1;
			num_int & dvndo = (*this);
			rem.insert(0,1,dvndo[maxpos-ndig]);
			if (rem < coc) {
				coc.insert(0,1,0);
			}
			else if (rem == coc) {
				coc.insert(0,1,1);
				rem.erase(0,rem.size()-1);
				rem[0]=0;
			}
			else {
				if (rem.size() > dvsor.size()) {
					pardigs dighrem        = pardigs(rem[rem.size()-1],rem[rem.size()-2]);
					const pardigs dighsor  = pardigs(0,dvsor[dvsor.size()-1]);
					pardigs & digcocprueba = dighrem;
					digcocprueba /= dighsor;
					num_int remprueba = dvsor*digcocprueba;
					for ( dig_t<B> Id = 0 ; Id < pardigs(1,0) ; Id+=1 ) {
						if ( remprueba > rem ) {
							--digcocprueba;
							remprueba -= dvsor;
						}
						else {
							rem -= remprueba;
							coc.insert(0,1,digcocprueba);
							break;
						}
					}
				}
				else {
					dig_t<B> dighrem		=	rem[rem.size()-1];
					const dig_t<B> dighsor	=	dvsor[dvsor.size()-1];
					dig_t<B> & digcocprueba	=	dighrem;
					digcocprueba /= dighsor;
					num_int remprueba = dvsor*digcocprueba;
					for ( dig_t<B> Id = 0 ; Id < pardigs(1,0) ; Id+=1 ) {
						if ( remprueba > rem ) {
							--digcocprueba;
							remprueba -= dvsor;
						}
						else {
							rem -= remprueba;
							coc.insert(0,1,digcocprueba);
							break;
						}
					}
				}
			}
			++ndig;
			return;
		}

								/****************************/
								/*							*/
								/* 	  Division entre Uno	*/
								/*							*/
								/****************************/

		inline void div_uno( num_int & rem , num_int & dvndo, num_int & dvsor, const usint long_dvndo, const usint long_dvsor) const {
			num_int & cthis = *this;
			rem = dvndo;
			if ((long_dvsor==0)||((long_dvsor==1)&&(dvsor[0]=0))) { // caso de division por 0
				return;
			}
			else if ((long_dvndo==0)||(long_dvndo < long_dvsor)) { // caso de 0 dividido por !=0 ó caso de cociente 0
				rem = dvndo;
				dvndo.erase(0,(cthis.size())-1);
				dvndo[0]=0;
				return;
				// rem=dvndo; hecho por defecto
			}
			else if (dvndo==dvsor) { // caso de dividir por si mismo
				dvndo.erase(0,(cthis.size())-1);
				dvndo[0]=1;
				rem.erase(0,rem.size()-1);
				rem[0]=0;
				return;
			}
			else if ((long_dvsor==1)&&(dvsor[0]==1)) { // caso de dividir por potencias de B
				//dvndo;
				rem.erase(0,rem.size()-1);
				rem[0]=0;
			}
			/*		else if ((long_dvsor==1)&&((dvsor[0]==2)||(dvsor[0]==4)||(dvsor[0]==8))) {
					// caso de dividir por potencias de B multiplicadas por 2, 4 u 8
						//dvndo;
						switch(dvsor[0]) {
							case 2  : rem=num_int(rem.rem2()); break;
							case 4  : rem=num_int(rem.rem4()); break;
							case 8  :
							default : rem=num_int(rem.rem8());
						}
						dvndo.div2p();
						switch(dvsor[0]) {
							case 4:  dvndo.div2p(); break;
							case 8:  dvndo.div2p(); dvndo.div2p();
						}

					}
					else if ((long_dvsor==1)&&((dvsor[0]==3)||(dvsor[0]==9))) {
					// caso de dividir por potencias de B multiplicadas por 3 u 9
						//dvndo;
						switch(dvsor[0]) {
							case 3  : rem=num_int(rem.rem3()); break;
							case B-1  :
							default : rem=num_int(rem.rem9()); break;
						}
						dvndo.div3p();
						if(dvsor[0]==n) dvndo.div3p();
					}
					else if ((long_dvsor==1)&&(dvsor[0]==6)) {
					// caso de dividir por potencias de B multiplicadas por 6
						//dvndo;
						rem.rem6();
						dvndo.div2p();
						dvndo.div3p();
					}
					else if ((long_dvsor==1)&&(dvsor[0]==5)) {
					// caso de dividir por potencias de B multiplicadas por 5
						rem.rem5();
						if (long_dvndo > 1) {
							dvndolst_digs.erase(0,1);
							// Divido por B
							dvndo *= d;
							// y he multiplicado por 2 (*2/B ó *1/5)
						}
						else {
							//dvndo;
							//dvndolst_digs.erase(0,(cthis.size())-1);
							switch (dvndo[0]) {
								case 0 :
								case 1 :
								case 2 :
								case 3 :
								case 4 :  dvndo[0] = 0; break;
								default : dvndo[0] = 1;
							}
						}
					}
					else if ((long_dvsor==1)&&(dvsor[0]==7)) {
					// caso de dividir por potencias de B multiplicadas por 7
						//dvndo;
						rem.rem7();
						dvndo.div7();
					}*/
			else if ((long_dvndo == long_dvsor) && (dvndo < dvsor)) {
				rem = dvndo;
				dvndo.erase(0,(cthis.size())-1);
				dvndo[0]    =0;
			}
			else {
				// algoritmo de resta general
				// implementar div_step pasamos (resto,cociente,i,dividendo,divisor) devuelve (resto,cociente,i,dividendo,divisor)
				// se puede hacer con una tupla
				//dvndo;
				num_int rem   = (dvndo = dvndo.substr((cthis.size())-1-long_dvsor,long_dvsor));
				num_int coc(0);
				usint ndig = 0;
				do {
					div_gen_step(dvsor,rem,coc,ndig);
				} while ( rem >= dvsor );
				dvndo = coc;
				return;
			}
		}
		//END PRIVATE


					/****************************/
					/*							*/
					/* 	  Division Euclidea		*/
					/*							*/
					/****************************/

public:

		pair< num_int , num_int > EuclidDiv (const num_int & arg) const {
			num_int & cthis = *this;
			const sign_e sgn_ndo = signo;
			const sign_e sgn_sor = arg.signo;
			num_int dvndo_int = cthis;
			dvndo_int.absp();
			dvndo_int.reduce();
			num_int dvsor_int = arg.abs();
			dvsor_int.reduce();

			num_int rem(dvndo_int);

			const usint cssor = dvsor_int.ceros_a_la_drcha(); //¿?

			num_int dvndo_fra(dvndo_int.substr(0,cssor));
			dvsor_int.erase(0,cssor);// division por una potencia de B

			dvsor_int.reduce();
			dvndo_int.reduce();

			dvndo_fra.reduce();

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

			if (sgn_ndo != sgn_sor) dvndo_int.mC_B();
			// rehacer el resto tomando en cuenta los ceros quitados
			// acomodar el formato al signo de la operacion
			// determinar el signo de la operacion
			return make_pair(rem,dvndo_int);
		}

		pair< num_int , const num_int & > m_EuclidDiv (const num_int & arg) {
			num_int & cthis = *this;
			const sign_e sgn_ndo = signo;
			const sign_e sgn_sor = arg.signo;
			cthis.absp();
			cthis.reduce();
			num_int & dvndo_int = cthis;
			num_int dvsor_int = arg.abs();
			dvsor_int.reduce();

			num_int rem(dvndo_int);

			const usint cssor = dvsor_int.ceros_a_la_drcha(); //¿?

			num_int dvndo_fra(dvndo_int.substr(0,cssor));
			dvsor_int.erase(0,cssor);// division por una potencia de B

			dvsor_int.reduce();
			dvndo_int.reduce();

			dvndo_fra.reduce();

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

			if (sgn_ndo != sgn_sor) dvndo_int.mC_B();
			// rehacer el resto tomando en cuenta los ceros quitados
			// acomodar el formato al signo de la operacion
			// determinar el signo de la operacion
			return make_pair(rem,dvndo_int);
		}


					/************************************/
					/*									*/
					/* 			PRE Y POST				*/
					/*									*/
					/************************************/


public:

		const num_int & operator ++ () {
			num_int & cthis = *this;
			const size_t long_inic = cthis.size();
			if (long_inic>1){
				cthis.reduce();}
			if (cthis==num_int(vminus,dig(B-1),dig(B-1))){
				cthis.clear();
				cthis.resize(1);
				cthis[0]=dig(0);
				signo = vplus;
				cthis.reduce();
				return cthis;}
			bool es_negativo = (signo==vminus);
			signo = vplus;
			aux=spardigs(vplus,0,1);
			aux += spardigs(vplus,0,cthis[0]);
			cthis[0] = aux.g_uds();
			aux.p_uds(aux.g_decs());
			aux.n2digs::m_decs(0);
			bool seguir = (aux.g_uds()!=dig(0));
			ullint i=1;
			while( seguir and (i<long_inic)) {
				aux += spardigs(vplus,0,cthis[i]);
				cthis[i]=(aux.g_uds());
				aux.p_uds(aux.g_decs());
				seguir = (aux.g_uds()!=dig(0));
				aux.n2digs::m_decs(0);
				++i;
			}
			if( seguir and (i >= long_inic) ) {
				cthis.resize(long_inic+1);
				cthis[i]=aux.g_uds();
			}
			((seguir)and(es_negativo)?(signo=vplus):(signo=vminus));//
			signo=(es_negativo?vminus:vplus);
			cthis.reduce();
			return cthis;
		}

		const num_int operator ++ (int) {
			num_int cpThis(*this);
			num_int & cthis = (*this);
			const size_t long_inic = cthis.size();
			if (cthis==num_int(vminus,dig(B-1),dig(B-1))){
				cthis.clear();
				cthis.resize(1);
				cthis[0]=dig(0);
				signo = vplus;
				cthis.reduce();
				return cpThis;
			}
			bool es_negativo = (signo==vminus);
			signo = vplus;
			aux=spardigs(vplus,0,1);
			aux += spardigs(vplus,0,cthis[0]);
			cthis[0] = aux.g_uds();
			aux.p_uds(aux.g_decs());
			aux.n2digs::m_decs(0);
			bool seguir = (aux.g_uds()!=dig(0));
			ullint i=1;
			while( seguir and (i<long_inic)) {
				aux += spardigs(vplus,0,cthis[i]);
				cthis[i]=(aux.g_uds());
				aux.p_uds(aux.g_decs());
				seguir = (aux.g_uds()!=dig(0));
				aux.n2digs::m_decs(0);
				++i;
			}
			if( seguir and (i >= long_inic) ) {
				cthis.resize(long_inic+1);
				cthis[i]=aux.g_uds();
			}
			((seguir)and(es_negativo)?(signo=vplus):(signo=vminus));//
			signo=(es_negativo?vminus:vplus);
			cthis.reduce();
			return cpThis;
		}

		const num_int & operator -- () {
			num_int & cthis = *this;
			const size_t long_inic = cthis.size();
			// BEGIN TRATAMIENTO DEL 0
			if (cthis==num_int(vplus,dig(0),dig(0))){
				cthis.clear();
				cthis.resize(1);
				cthis[0]=dig(B-1);
				signo = vminus;
				return cthis;
			}
			bool es_negativo = (signo==vminus);
			// END TRATAMIENTO DEL 0
			// BEGIN TRATAMIENTO DE POTENCIA DE B NEGATIVAS
			bool es_pot_de_B_neg = false;
			if (es_negativo) {
				es_pot_de_B_neg = true;
				for(slint i=0 ; (i < long_inic) and es_pot_de_B_neg ; ++i)
				{
					es_pot_de_B_neg = es_pot_de_B_neg and (cthis[i]==dig(0));
				}
			} // Hemos calculado si es potencia de 10 negativa
			if (es_pot_de_B_neg) {
				cthis.resize(long_inic+1);
				for(slint i=0; i < long_inic; ++i)
					cthis[i]=dig(B-1);
				cthis[long_inic] = dig(B-2);
				signo = vminus;
				return cthis;
			} // Vemos que -000 pasa a -8999
			// END TRATAMIENTO DE POTENCIA DE B NEGATIVAS
			signo = vplus;
			aux=spardigs(vminus,dig(B-1),dig(B-1));
			aux+= spardigs(vplus,0,cthis[0]);
			cthis[0] = aux.g_uds();
			aux.p_uds(aux.g_decs());
			aux.n2digs::m_decs(B-1);
			bool seguir = (aux.g_uds()!=dig(0));
			ullint i=1;
			while( seguir and (i<long_inic)) {
				aux += spardigs(vplus,0,cthis[i]);
				cthis[i]=(aux.g_uds());
				aux.p_uds(aux.g_decs());
				seguir = (aux.g_uds()!=dig(0));
				aux.n2digs::m_decs(B-1);
				++i;
			}
			if( seguir and (i >= long_inic) ) {
				cthis.resize(long_inic+1);
				cthis[i]=aux.g_uds();
			}
			signo=(es_negativo?vminus:vplus);
			cthis.reduce();
			return cthis;
		}

		const num_int operator -- (int) {
			num_int & cthis = (*this);
			const num_int cpThis(*this);
			const size_t long_inic = cthis.size();
			// BEGIN TRATAMIENTO DEL 0
			if (cthis==num_int(vplus,dig(0),dig(0))){
				cthis.clear();
				cthis.resize(1);
				cthis[0]=dig(B-1);
				signo = vminus;
				return cpThis;
			}
			bool es_negativo = (signo==vminus);
			// END TRATAMIENTO DEL 0
			// BEGIN TRATAMIENTO DE POTENCIA DE B NEGATIVAS
			bool es_pot_de_B_neg = false;
			if (es_negativo) {
				es_pot_de_B_neg = true;
				for(slint i=0 ; (i < long_inic) and es_pot_de_B_neg ; ++i)
				{
					es_pot_de_B_neg = es_pot_de_B_neg and (cthis[i]==dig(0));
				}
			} // Hemos calculado si es potencia de 10 negativa
			if (es_pot_de_B_neg) {
				cthis.resize(long_inic+1);
				for(slint i=0; i < long_inic; ++i)
					cthis[i]=dig(B-1);
				cthis[long_inic] = dig(B-2);
				signo = vminus;
				return cpThis;
			} // Vemos que -000 pasa a -8999
			// END TRATAMIENTO DE POTENCIA DE B NEGATIVAS
			signo = vplus;
			aux=spardigs(vminus,dig(B-1),dig(B-1));
			aux+= spardigs(vplus,0,cthis[0]);
			cthis[0] = aux.g_uds();
			aux.p_uds(aux.g_decs());
			aux.n2digs::m_decs(B-1);
			bool seguir = (aux.g_uds()!=dig(0));
			ullint i=1;
			while( seguir and (i<long_inic)) {
				aux += spardigs(vplus,0,cthis[i]);
				cthis[i]=(aux.g_uds());
				aux.p_uds(aux.g_decs());
				seguir = (aux.g_uds()!=dig(0));
				aux.n2digs::m_decs(B-1);
				++i;
			}
			if( seguir and (i >= long_inic) ) {
				cthis.resize(long_inic+1);
				cthis[i]=aux.g_uds();
			}
			signo=(es_negativo?vminus:vplus);
			cthis.reduce();
			return cpThis;
		}

			/****************************/
			/*							*/
			/*			REDUCE			*/
			/*							*/
			/****************************/

		const num_int & reduce() {
			num_int & cthis = *this;
			const usint nsz = cthis.digs_no_significativos();
			const usint longitud = cthis.size();
			if ((longitud==1)or(longitud==0)) return cthis;
			const usint pos_p1 = ((cthis.size())-nsz);
			return cthis.erase(pos_p1,nsz);
		}

		num_int reduce() const {
			const num_int & cthis = *this;
			num_int cpyreducida(cthis);
			const usint nsz = cpyreducida.digs_no_significativos();
			const usint longitud = cpyreducida.size();
			const usint pos = (longitud-nsz);
			if ((nsz==0)or(nsz==1))
				return cpyreducida;
			else
				return cpyreducida.erase(pos,nsz);
		}

		const num_int & reduce_fracc() {
			num_int & cthis = *this;
			const usint nsz = cthis.digs_fracc_no_significativos()-1;
			const usint pos = 0;
			cthis.erase(pos,nsz);
			return cthis;
		}

		num_int reduce_fracc() const {
			num_int & cthis = *this;
			num_int cpyreducida(cthis);
			const usint nsz = cpyreducida.digs_no_significativos()-1;
			const usint pos = 0;
			cpyreducida.erase(pos,nsz);
			return cpyreducida;
		}

			/****************************/
			/*							*/
			/* 		ISTREAM Y OSTREAM	*/
			/*							*/
			/****************************/

		template<const uchint Base>
		friend
		istream & operator >> (istream & is,num_int<Base> & arg) {
			enum estado_e {e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11};
			vector<string> num(255);
			string num_sgn;
			string num_base;
			estado_e est_act = e0;
			uchint i=0;
			char c;
			do {
				is >> c;
				switch (est_act) {
				case e0 :
					if (c=='i') est_act = e1;
					break;
				case e1 :
					if (c=='n') est_act = e2;
					else est_act = e0;
					break;
				case e2 :
					if (c=='t') est_act = e3;
					else est_act = e0;
					break;
				case e3 :
					if (c=='#') est_act = e4;
					else est_act = e0;
					break;
				case e4 :
					if ((c=='1')||(c=='0')||(c=='-')||(c=='+')) {
						est_act = e5;
						num_sgn.push_back(c-'0');
					}
					else est_act = e0;
					break;
				case e5 :
					if (c==':') est_act = e6;
					else est_act = e0;
					break;
				case e6 :
					if (c==':') est_act = e7;
					else est_act = e0;
					break;
				case e7 :
					if ((c<='9')and(c>='0')) {
						num[i].push_back(c-'0');
					}
					else if (c==':') {
						++i;
						est_act = e6;
					}
					else if (c=='#') est_act = e8;
					else est_act=e0;
					break;
				case e8 :
					if (c == 'B') est_act = e9;
					else est_act = e0;
					break;
				case e9 :
					if ((c<='9')and(c>='0')) {
						est_act = e10;
						num_base.push_back(c-'0');
					}
					else est_act = e0;
					break;
				case e10 :
					if ((c<='9')and(c>='0')) {
						num_base.push_back(c-'0');
					}
					else est_act = e11;
					break;
				case e11 :
					break;
				default :
					est_act = e0;
				}
				uint numero_base_recogido=0;
				if (est_act==e11) {
					for (uint k=num_base.size() ; k > 0 ; --k ) {
						numero_base_recogido *= 10;
						numero_base_recogido += num_base[k];
					}
					numero_base_recogido *= 10;
					numero_base_recogido += num_base[0];
					if (numero_base_recogido!=Base) est_act = e0;
				}
			} while ((est_act!=e11)and(c!='\n'));
			basic_string< dig_t<Base> > digito;
			digito.resize(i+1);
			for (uchint j=0 ; j < 256 ; ++j) {
				digito[j]=0;
				for (uint k=num[j].size() ; k > 0 ; --k ) {
					digito[j] *= 10;
					digito[j] += (num[j][k]-'0');
				}
				digito[j] *= 10;
				digito[j] += (num[j][0]-'0');
			}
			sign_e sgn;
			if ((num_sgn[0]=='1') || (num_sgn[0]=='-')) sgn = vminus;
			else sgn = vplus;
			arg.signo = sgn;
			arg = digito;
			arg.aux = spardigs_t<Base>();
			return is;
		}

		template<const uchint Base>
		friend
		ostream & operator << (ostream & os,num_int<Base> arg) {
			const uchint sz = arg.size();
			os << "int#"
			<< ((arg.signo == vplus)?('+'):('-'));
			for (int k=sz-1 ; k>-1 ; --k) {
				if (k!=sz-1)
					os << ":";
				os << static_cast<usint>(arg[k]());
			}
			os <<"#B"
			<< static_cast<usint>(Base) ;
			return os;
		}

};
/* resumen INT_NUM_T:






   */



#endif


