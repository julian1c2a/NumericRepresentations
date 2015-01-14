#ifndef BASIC_CONSTANTS_AND_LISTS_4_TEST_UNIT__HPP
#define BASIC_CONSTANTS_AND_LISTS_4_TEST_UNIT__HPP


#include <tuple>
#include <string>
#include <list>

#include "src/libNumericRepresentations_src/sdig_t.hpp"
#include "src/libNumericRepresentations_src/spardigs_t.hpp"

constexpr unsigned short int number_of_radixes_to_test = 17;
constexpr unsigned char radixes[number_of_radixes_to_test] = {0,2,3,5,7,10,11,13,15,30,48,127,128,144,210,255,1};
constexpr unsigned short int Begin_It=1;
constexpr unsigned short int Begin_Opened_It=Begin_It-1;
constexpr unsigned short int End_It=number_of_radixes_to_test-1;
constexpr unsigned short int End_Closed_It = End_It -1;
constexpr unsigned short int Succ_It(const short int k){return ((k<End_Closed_It)?((k>Begin_Opened_It)?(k+1):Begin_It):(End_Closed_It));}
constexpr unsigned short int Pred_It(const short int k){return ((k<End_It)?((k>Begin_It)?(k-1):Begin_It):(End_Closed_It));}
constexpr unsigned char Ind_It(const short int k){return ((k<Begin_It)?(radixes[Begin_It]):((k<End_It)?(radixes[k]):(radixes[End_Closed_It])));}

template<typename U,template<const U> class T,U R,class S>
using in_detail_errors_list_t = std::list<std::tuple<std::string,std::string,std::string,T<R>,T<R>,S,S>>;

template<typename U,template<const U> class T,U R,class S>
struct test_results_t {
public:
	unsigned long long int number_of_errors;
	unsigned long long int number_of_corrects;
	in_detail_errors_list_t<U,T,R,S> list_of_erroneus_tests;
};

template<typename U,template<const U> class T,U R,typename S>
using MAUPTR_tt = T<R>(T<R>::*)();

template<typename U,template<const U> class T,U R,typename S>
using	operation_order_a1_tt	=	std::tuple<unsigned int,std::string,MAUPTR_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,typename S>
operation_order_a1_tt<U,T,R,S> arithmetic_unary_operators(unsigned int i)	{
	switch(i) {
		case 0 : return {0,"!",&(T<R>::operator!)};
		case 1 : return {1,"-",&(T<R>::operator-)};
		default : return {2,"abs",&(T<R>::abs)};
	}
}

template<typename U,template<const U> class T,U R,typename S>
using MAABEQPTR_tt = const T<R>&(T<R>::*)(const T<R>&);

template<typename U,template<const U> class T,U R,typename S>
using	operation_order_aa2eq_tt	=	std::tuple<unsigned int,std::string,MAABEQPTR_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,typename S>
operation_order_aa2eq_tt<U,T,R,S> arithmetic_with_assignation_binary_eq_operators(unsigned int i)	{
	switch(i) {
		case 0 : return {0,"+=",&(T<R>::operator+=)};
		case 1 : return {1,"-=",&(T<R>::operator-=)};
		case 2 : return {2,"*=",&(T<R>::operator*=)};
		case 3 : return {3,"/=",&(T<R>::operator/=)};
		default : return {4,"%=",&(T<R>::operator%=)};
	}
}

template<typename U,template<const U> class T,U R,typename S>
using MAABDIFPTR_tt = const T<R>& (T<R>::*)(S);

template<typename U,template<const U> class T,U R,typename S>
using	operation_order_aa2dif_tt	= std::tuple<unsigned int,std::string,MAABDIFPTR_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,typename S>
operation_order_aa2dif_tt<U,T,R,S> arithmetic_with_assignation_binary_dif_operators(unsigned int i)	{
	switch(i) {
		case 0 : return {0,"+=",&(T<R>::operator+=)};
		case 1 : return {1,"-=",&(T<R>::operator-=)};
		case 2 : return {2,"*=",&(T<R>::operator*=)};
		case 3 : return {3,"/=",&(T<R>::operator/=)};
		default : return {4,"%=",&(T<R>::operator%=)};
	}
}

template<typename U,template<const U> class T,U R,typename S>
using MABEQPTR_tt = T<R>(T<R>::*)(T<R>);

template<typename U,template<const U> class T,U R,typename S>
using	operation_order_a2eq_tt = std::tuple<unsigned int,std::string,MABEQPTR_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,typename S>
operation_order_a2eq_tt<U,T,R,S> arithmetic_binary_eq_operators(unsigned int i)	{
	switch(i) {
		case 0 : return {0,"+",&(T<R>::operator+)};
		case 1 : return {1,"-",&(T<R>::operator-)};
		case 2 : return {2,"*",&(T<R>::operator*)};
		case 3 : return {3,"/",&(T<R>::operator/)};
		default : return {4,"%",&(T<R>::operator%)};
	}
}

template<typename U,template<const U> class T,U R,typename S>
using MABDIFPTR_tt = T<R>(T<R>::*)(S);

template<typename U,template<const U> class T,U R,typename S>
using	operation_order_a2dif_tt	=	std::tuple<unsigned int,std::string,MABDIFPTR_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,typename S>
operation_order_a2dif_tt<U,T,R,S> arithmetic_binary_dif_operators(unsigned int i)	{
	switch(i) {
		case 0 : return {0,"+",&(T<R>::operator+)};
		case 1 : return {1,"-",&(T<R>::operator-)};
		case 2 : return {2,"*",&(T<R>::operator*)};
		case 3 : return {3,"/",&(T<R>::operator/)};
		default : return {4,"%",&(T<R>::operator%)};
	}
}

struct result_test {
    unsigned long long int erroneos;
    unsigned long long int correctos;
};

//	boolean_unary_operators
//	boolean_binary_eq_operators
//	boolean_binary_dif_operators
//	arithmetic_with_assignation_unary_post_operators
//	arithmetic_with_assignation_unary_operators
//	arithmetic_unary_operators
//	arithmetic_with_assignation_binary_eq_operators
//	arithmetic_with_assignation_binary_dif_operators
//	arithmetic_binary_eq_operators
//	arithmetic_binary_dif_operators
//	assignation_dif_operators
//	assignation_eq_operators
//	cast

template<class Ug,template<const Ug> class Tg, const Ug Rg, class Sg>
struct CTTI {
public:
	constexpr Sg MaxPowRadix_Consts_Choosing(){return Sg(1);}
	constexpr Sg BeginIndex_Consts_Choosing(){return Sg(0);}
	constexpr Sg EndIndex_Consts_Choosing(){return Sg(1);}
	constexpr Sg NDigs_Consts_Choosing(){return Sg(0);}
	constexpr bool with_sign_Consts_Choosing(){return false;}
public:
	constexpr static Sg EndIndex{1};
	constexpr static Sg BeginIndex{0};
	constexpr static Sg MaxPowRadix{1};
	constexpr static bool with_sign = false;
	constexpr static unsigned NDigs = 1;
};

template<unsigned char Rg>
struct CTTI<unsigned char,dig_t,Rg,long long int> {
public:
	constexpr static long long int EndIndex = Rg;
	constexpr static long long int BeginIndex = 0;
	constexpr static long long int MaxPowRadix = Rg;
	constexpr static bool with_sign = false;
	constexpr static unsigned NDigs =  1;
};

template<unsigned char Rg>
struct CTTI<unsigned char,sdig_t,Rg,long long int> {
public:
	constexpr long long int MaxPowRadix_Consts_Choosing(){return (Rg);}
	constexpr long long int BeginIndex_Consts_Choosing(){return (-Rg);}
	constexpr long long int EndIndex_Consts_Choosing(){return (Rg-1);}
	constexpr long long int NDigs_Consts_Choosing(){return (1);}
	constexpr bool with_sign_Consts_Choosing(){return true;}
public:
	constexpr static long long int EndIndex = Rg-1;
	constexpr static long long int BeginIndex = -Rg;
	constexpr static long long int MaxPowRadix = Rg;
	constexpr static bool with_sign = true;
	constexpr static unsigned NDigs =  1;
};

template<unsigned char Rg>
class CTTI<unsigned char,pardigs_t,Rg,long long int> {
public:
	constexpr static long long int EndIndex = Rg*Rg-1;
	constexpr static long long int BeginIndex = 0;
	constexpr static long long int MaxPowRadix = Rg*Rg;
	constexpr static bool with_sign = false;
	constexpr static unsigned NDigs =  2;
};

template<unsigned char Rg>
class CTTI<unsigned char,spardigs_t,Rg,long long int> {
public:
	constexpr static long long int EndIndex = Rg*Rg-1;
	constexpr static long long int BeginIndex = -Rg*Rg;
	constexpr static long long int MaxPowRadix = Rg*Rg;
	constexpr static bool with_sign = true;
	constexpr static unsigned NDigs = 2;
};

/**
***   COMIENZO DE LA CLASE PARA TESTS DE FUNCIONES BULEANAS BINARIAS
**/

//boolean_binary_eq_operators
template<class U, template<const U R> class T,const U R, class S>
class boolean_binary_eq_operators_class {
	static test_results_t<U,T,R,S> test_results;
	class eS {
	private:
		S dm;
	public:
		constexpr eS(): dm(0) {}
		constexpr eS(const eS& d): dm(d.dm) {}
		explicit constexpr eS(const S& d): dm(d) {}
		constexpr eS(eS&&) = delete;
		constexpr eS(S&& d) = delete;
		constexpr const eS& operator= (const eS& d) { dm = d.dm; return (*this);}
		constexpr eS& operator= (eS& d) { dm = d.dm; return (*this);}
		constexpr const S& operator= (const S& d) { dm = d; return (*this);}
		constexpr S& operator= (S& d) { dm = d; return (*this);}
		bool operator==(eS a) const {return ((this->dm) == (a.dm));}
		bool operator!=(eS a) const {return ((this->dm) != (a.dm));}
		bool operator<(eS a) const {return ((this->dm) < (a.dm));}
		bool operator<=(eS a) const {return ((this->dm) <= (a.dm));}
		bool operator>(eS a) const {return ((this->dm) > (a.dm));}
		bool operator>=(eS a) const {return ((this->dm) >= (a.dm));}
	};

	const static std::string T_template_name;

	static std::string template_name();

	constexpr static std::string R_radix_number {
		(((R/100)%10)+'0'),(((R/10)%10)+'0'),((R%10)+'0')
	};

	constexpr static unsigned short int number_of_function_members_of_this_ttypes = 7;
	constexpr static signed short int Begin_It=0;
	constexpr static signed short int Begin_Opened_It=Begin_It-1;
	constexpr static signed short int End_It=number_of_function_members_of_this_ttypes-1;
	constexpr static signed short int End_Closed_It = End_It -1;
	constexpr static signed short int Succ_It(const short int k){
		return ((k<End_Closed_It)?((k>Begin_Opened_It)?(k+1):Begin_It):(End_Closed_It));
	}
	constexpr static signed short int Pred_It(const short int k){
		return ((k<End_It)?((k>Begin_It)?(k-1):Begin_It):(End_Closed_It));
	}

	using	eS_t					=	typename boolean_binary_eq_operators_class::eS;
	using	MBBEQPTR_ss				=	bool (eS_t::*)(eS_t);
	using	operation_order_b2eq_ss	=	MBBEQPTR_ss;
	using	MBBEQPTR_tt				=	bool (T<R>::*)(T<R>);
	using	operation_order_b2eq_tt	=	typename std::tuple<unsigned int,std::string,MBBEQPTR_tt,MBBEQPTR_ss>;

	constexpr static operation_order_b2eq_tt element_of_type_of_function_member_to_test[6]{
			{0,"==",&(T<R>::operator==),&(eS_t::operator==)},
			{1,"!=",&(T<R>::operator!=),&(eS_t::operator!=)},
			{2,"<",&(T<R>::operator<),&(eS_t::operator!=)},
			{3,"<=",&(T<R>::operator<=),&(eS_t::operator!=)},
			{4,">",&(T<R>::operator>),&(eS_t::operator!=)},
			{5,">=",&(T<R>::operator>=),&(eS_t::operator!=)}
	};

	// (boolean_binary_eq_operators_class(i).get<2>())(arg_1,arg_2)
    constexpr bool operator()(int i,T<R> arg_1,T<R> arg_2){
		auto previo_al_retorno = element_of_type_of_function_member_to_test[i];
		auto retorno = std::get<2>(previo_al_retorno);
        return retorno(arg_1,arg_2);
    }

	// (boolean_binary_eq_operators_class(i).get<3>())(arg_1,arg_2)
    constexpr bool operator()(int i,S arg_1,S arg_2){
		auto previo_al_retorno = element_of_type_of_function_member_to_test[i];
		auto retorno = std::get<3>(previo_al_retorno);
        return retorno(arg_1,arg_2);
    }

	// (boolean_binary_eq_operators_class(i).get<2>())(arg_1,arg_2)
    inline bool operator()(int i,T<R> arg_1,T<R> arg_2,S arg_1_t,S arg_2_t){
        return not(retorno(i,arg_1,arg_2) xor retorno(i,arg_1_t,arg_2_t));
    }

	void operator()(int i,T<R> arg_1,S arg_1_t){
		for(S arg_2_t = CTTI<U,T,R,S>::BeginIndex; arg_2_t < CTTI<U,T,R,S>::BeginIndex; ++arg_2_t) {
			const T<R> arg_2(arg_2_t);
			if (this->operator()(i,arg_1,arg_2,arg_1_t,arg_2_t)) {
				++test_results.number_of_corrects;
			}
			else {
				++test_results.number_of_errors;
				const	std::string	Op_name	=	std::get<1>(element_of_type_of_function_member_to_test[i]);
				test_results.list_of_erroneus_tests.append({T_template_name,R_radix_number,Op_name,arg_1,arg_2,arg_1_t,arg_2_t});
			}
		}
    }

public:

	void operator()(int i){
		for(S arg_1_t = CTTI<U,T,R,S>::BeginIndex; arg_1_t < CTTI<U,T,R,S>::BeginIndex; ++arg_1_t) {
			const T<R> arg_1(arg_1_t);
			this->operator()(i,arg_1,arg_1_t);
		}
    }

	void operator()(){
		for(auto k=Begin_It;k<End_It;k=Succ_It(k)) {
			this->operator()(k);
		}
	}

};

template<class U, template<const U R> class T,const U R, class S>
std::string boolean_binary_eq_operators_class<U,T,R,S>::template_name() {
	return 	"nullclasstemplate";
}

template<class U, template<const U R> class T,const U R, class S>
const std::string boolean_binary_eq_operators_class<U,T,R,S>::T_template_name =
	boolean_binary_eq_operators_class<U,T,R,S>::template_name();

template<unsigned char R>
class boolean_binary_eq_operators_class<unsigned char,dig_t,R,int>{
	static std::string template_name();
	static const std::string T_template_name;
};

template<unsigned char R>
std::string boolean_binary_eq_operators_class<unsigned char,dig_t,R,int>::template_name() {
	return 	"dig";
}

template<unsigned char R> const std::string
boolean_binary_eq_operators_class<unsigned char,dig_t,R,int>::T_template_name =
	boolean_binary_eq_operators_class<unsigned char,dig_t,R,int>::template_name();

template<unsigned char R>
class boolean_binary_eq_operators_class<unsigned char,sdig_t,R,int>{
	static std::string template_name();
	static const std::string T_template_name;
};

template<unsigned char R>
std::string boolean_binary_eq_operators_class<unsigned char,sdig_t,R,int>::template_name() {
	return 	"sdig";
}

template<unsigned char R> const std::string
boolean_binary_eq_operators_class<unsigned char,sdig_t,R,int>::T_template_name =
	boolean_binary_eq_operators_class<unsigned char,sdig_t,R,int>::template_name();

template<unsigned char R>
class boolean_binary_eq_operators_class<unsigned char,pardigs_t,R,long int>{
	static std::string template_name();
	static const std::string T_template_name;
};

template<unsigned char R>
std::string boolean_binary_eq_operators_class<unsigned char,pardigs_t,R,long int>::template_name() {
	return 	"pardigs_t";
}

template<unsigned char R> const std::string
boolean_binary_eq_operators_class<unsigned char,pardigs_t,R,long int>::T_template_name =
	boolean_binary_eq_operators_class<unsigned char,pardigs_t,R,long int>::template_name();

template<unsigned char R>
class boolean_binary_eq_operators_class<unsigned char,spardigs_t,R,long int>{
	static std::string template_name();
	static const std::string T_template_name;
};

template<unsigned char R>
std::string boolean_binary_eq_operators_class<unsigned char,spardigs_t,R,long int>::template_name() {
	return 	"spardigs_t";
}

template<unsigned char R> const std::string
boolean_binary_eq_operators_class<unsigned char,spardigs_t,R,long int>::T_template_name =
	boolean_binary_eq_operators_class<unsigned char,spardigs_t,R,long int>::template_name();

/**
***   FIN DE LA CLASE PARA TESTS DE FUNCIONES BULEANAS BINARIAS
**/

/**
***   COMIENZO DE LA CLASE PARA TESTS DE FUNCIONES BULEANAS UNARIAS
**/

//boolean_unary_operators
template<class U, template<const U R> class T,const U R, class S>
class boolean_unary_eq_operators_class {
	static test_results_t<U,T,R,S> test_results;
	class eS {
	private:
		S dm;
	public:
		constexpr eS(): dm(0) {}
		constexpr eS(const eS& d): dm(d.dm) {}
		constexpr eS(const S& d): dm(d) {}
		constexpr eS(eS&&) = delete;
		constexpr eS(S&& d) = delete;
		constexpr const eS& operator= (const eS& d) { dm = d.dm; return (*this);}
		constexpr eS& operator= (eS& d) { dm = d.dm; return (*this);}
		constexpr const S& operator= (const S& d) { dm = d; return (*this);}
		constexpr S& operator= (S& d) { dm = d; return (*this);}
		bool operator==(eS a) const {return ((this->dm) == (a.dm));}
		bool operator!=(eS a) const {return ((this->dm) != (a.dm));}
		bool operator<(eS a) const {return ((this->dm) < (a.dm));}
		bool operator<=(eS a) const {return ((this->dm) <= (a.dm));}
		bool operator>(eS a) const {return ((this->dm) > (a.dm));}
		bool operator>=(eS a) const {return ((this->dm) >= (a.dm));}
		bool is_0() const {return (dm==S(0));}
		bool is_1() const {return (dm==S(1));}
		bool is_m1() const {return ((CTTI<U,T,R,S>::with_sign)?(dm==S(-1)):(false));}
		bool is_max() const {return (dm==S(CTTI<U,T,R,S>::EndIndex));}
		bool is_submax() const {return (dm==S(CTTI<U,T,R,S>::EndIndex-1));}
		bool is_min() const {return (dm==S(CTTI<U,T,R,S>::BeginIndex));}
		bool is_submin() const {return (dm==S(CTTI<U,T,R,S>::BeginIndex+1));}
		bool is_negative() const {return ((CTTI<U,T,R,S>::with_sign)?(dm<S(0)):(false));}
		bool is_positive() const {return ((CTTI<U,T,R,S>::with_sign)?(dm>=S(0)):(true));}
	};

	const static std::string T_template_name;

	static std::string template_name();

	constexpr static std::string R_radix_number {
		(((R/100)%10)+'0'),(((R/10)%10)+'0'),((R%10)+'0')
	};

	constexpr static unsigned short int number_of_function_members_of_this_ttypes = 9;
	constexpr static signed short int Begin_It=0;
	constexpr static signed short int Begin_Opened_It=Begin_It-1;
	constexpr static signed short int End_It=number_of_function_members_of_this_ttypes-1;
	constexpr static signed short int End_Closed_It = End_It -1;
	constexpr static signed short int Succ_It(const short int k){
		return ((k<End_Closed_It)?((k>Begin_Opened_It)?(k+1):Begin_It):(End_Closed_It));
	}
	constexpr static signed short int Pred_It(const short int k){
		return ((k<End_It)?((k>Begin_It)?(k-1):Begin_It):(End_Closed_It));
	}
	
	using	eS_t					=	typename boolean_unary_eq_operators_class::eS;
	using	MBUPTR_ss				=	bool (eS_t::*)();
	using	operation_order_b1_ss	=	MBUPTR_ss;
	using	MBUPTR_tt				=	bool (T<R>::*)();
	using	operation_order_b1_tt	=	typename std::tuple<unsigned int,std::string,MBUPTR_tt,MBUPTR_ss>;

	constexpr static operation_order_b1_tt element_of_type_of_function_member_to_test[number_of_function_members_of_this_ttypes]{
			{0,"is_0",&(T<R>::is_0),&(eS_t::is_0)},
			{1,"is_1",&(T<R>::is_1),&(eS_t::is_1)},
			{2,"is_m1",&(T<R>::is_m1),&(eS_t::is_m1)},
			{3,"is_max",&(T<R>::is_max),&(eS_t::is_max)},
			{4,"is_submax",&(T<R>::is_submax),&(eS_t::is_submax)},
			{5,"is_min",&(T<R>::is_min),&(eS_t::is_min)},
			{6,"is_submin",&(T<R>::is_submin),&(eS_t::is_submin)},
			{7,"is_negative",&(T<R>::is_negative),&(eS_t::is_negative)},
			{8,"is_positive",&(T<R>::is_positive),&(eS_t::is_positive)}
	};

	// (boolean_unary_eq_operators_class(i).get<2>())(arg)
    constexpr bool operator()(int i,T<R> arg_1){
		auto previo_al_retorno = element_of_type_of_function_member_to_test[i];
		auto retorno = std::get<2>(previo_al_retorno);
        return retorno(arg_1);
    }

	// (boolean_unary_eq_operators_class(i).get<3>())(arg_1)
    constexpr bool operator()(int i,S arg_1){
		auto previo_al_retorno = element_of_type_of_function_member_to_test[i];
		auto retorno = std::get<3>(previo_al_retorno);
        return retorno(arg_1);
    }

	// (boolean_unary_eq_operators_class(i).get<2>())(arg_1)
    inline void operator()(int i,T<R> arg_1,S arg_1_t){
        const bool res = not(retorno(i,arg_1) xor retorno(i,arg_1_t));
		if (res) {
			++test_results.number_of_corrects;
		}
		else {
			++test_results.number_of_errors;
			const	std::string	Op_name	=	std::get<1>(element_of_type_of_function_member_to_test[i]);
			test_results.list_of_erroneus_tests.append({T_template_name,R_radix_number,Op_name,arg_1,arg_1_t});
		}
    }

public:

	void operator()(int i){
		for(S arg_1_t = CTTI<U,T,R,S>::BeginIndex; arg_1_t < CTTI<U,T,R,S>::BeginIndex; ++arg_1_t) {
			const T<R> arg_1(arg_1_t);
			this->operator()(i,arg_1,arg_1_t);
		}
    }

	void operator()(){
		for(auto k=Begin_It;k<End_It;k=Succ_It(k)) {
			this->operator()(k);
		}
	}

};

template<class U, template<const U R> class T,const U R, class S>
std::string boolean_unary_eq_operators_class<U,T,R,S>::template_name() {
	return 	"nullclasstemplate";
}

template<class U, template<const U R> class T,const U R, class S>
const std::string boolean_unary_eq_operators_class<U,T,R,S>::T_template_name =
	boolean_unary_eq_operators_class<U,T,R,S>::template_name();

template<unsigned char R>
class boolean_unary_eq_operators_class<unsigned char,dig_t,R,int>{
	static std::string template_name();
	static const std::string T_template_name;
};

template<unsigned char R>
std::string boolean_unary_eq_operators_class<unsigned char,dig_t,R,int>::template_name() {
	return 	"dig";
}

template<unsigned char R> const std::string
boolean_unary_eq_operators_class<unsigned char,dig_t,R,int>::T_template_name =
	boolean_unary_eq_operators_class<unsigned char,dig_t,R,int>::template_name();

template<unsigned char R>
class boolean_unary_eq_operators_class<unsigned char,sdig_t,R,int>{
	static std::string template_name();
	static const std::string T_template_name;
};

template<unsigned char R>
std::string boolean_unary_eq_operators_class<unsigned char,sdig_t,R,int>::template_name() {
	return 	"sdig";
}

template<unsigned char R> const std::string
boolean_unary_eq_operators_class<unsigned char,sdig_t,R,int>::T_template_name =
	boolean_unary_eq_operators_class<unsigned char,sdig_t,R,int>::template_name();

template<unsigned char R>
class boolean_unary_eq_operators_class<unsigned char,pardigs_t,R,long int>{
	static std::string template_name();
	static const std::string T_template_name;
};

template<unsigned char R>
std::string boolean_unary_eq_operators_class<unsigned char,pardigs_t,R,long int>::template_name() {
	return 	"pardigs_t";
}

template<unsigned char R> const std::string
boolean_unary_eq_operators_class<unsigned char,pardigs_t,R,long int>::T_template_name =
	boolean_unary_eq_operators_class<unsigned char,pardigs_t,R,long int>::template_name();

template<unsigned char R>
class boolean_unary_eq_operators_class<unsigned char,spardigs_t,R,long int>{
	static std::string template_name();
	static const std::string T_template_name;
};

template<unsigned char R>
std::string boolean_unary_eq_operators_class<unsigned char,spardigs_t,R,long int>::template_name() {
	return 	"spardigs_t";
}

template<unsigned char R> const std::string
boolean_unary_eq_operators_class<unsigned char,spardigs_t,R,long int>::T_template_name =
	boolean_unary_eq_operators_class<unsigned char,spardigs_t,R,long int>::template_name();

/**
***   FIN DE LA CLASE PARA TESTS DE FUNCIONES BULEANAS UNARIAS
**/

/**
***   COMIENZO DE LA CLASE PARA TESTS DE FUNCIONES BULEANAS BINARIAS DE TIPOS DIFERENTES
**/

//boolean_binary_dif_operators
template<class U, template<const U R> class T,const U R, class S>
class boolean_binary_dif_operators_class {
	static test_results_t<U,T,R,S> test_results;
	class eS {
	private:
		S dm;
	public:
		constexpr eS(): dm(0) {}
		constexpr eS(const eS& d): dm(d.dm) {}
		constexpr eS(const S& d): dm(d) {}
		constexpr eS(eS&&) = delete;
		constexpr eS(S&& d) = delete;
		constexpr const eS& operator= (const eS& d) { dm = d.dm; return (*this);}
		constexpr eS& operator= (eS& d) { dm = d.dm; return (*this);}
		constexpr const S& operator= (const S& d) { dm = d; return (*this);}
		constexpr S& operator= (S& d) { dm = d; return (*this);}
		bool operator==(eS a) const {return ((this->dm) == (a.dm));}
		bool operator!=(eS a) const {return ((this->dm) != (a.dm));}
		bool operator<(eS a) const {return ((this->dm) < (a.dm));}
		bool operator<=(eS a) const {return ((this->dm) <= (a.dm));}
		bool operator>(eS a) const {return ((this->dm) > (a.dm));}
		bool operator>=(eS a) const {return ((this->dm) >= (a.dm));}
		bool is_0() const {return (dm==S(0));}
		bool is_1() const {return (dm==S(1));}
		bool is_m1() const {return ((CTTI<U,T,R,S>::with_sign)?(dm==S(-1)):(false));}
		bool is_max() const {return (dm==S(CTTI<U,T,R,S>::EndIndex));}
		bool is_submax() const {return (dm==S(CTTI<U,T,R,S>::EndIndex-1));}
		bool is_min() const {return (dm==S(CTTI<U,T,R,S>::BeginIndex));}
		bool is_submin() const {return (dm==S(CTTI<U,T,R,S>::BeginIndex+1));}
		bool is_negative() const {return ((CTTI<U,T,R,S>::with_sign)?(dm<S(0)):(false));}
		bool is_positive() const {return ((CTTI<U,T,R,S>::with_sign)?(dm>=S(0)):(true));}
		operator S() const {return this->dm;}
	};

	static const std::string T_template_name;

	static const std::string template_name();

	constexpr static std::string R_radix_number {
		(((R/100)%10)+'0'),(((R/10)%10)+'0'),((R%10)+'0')
	};

	constexpr static unsigned short int number_of_function_members_of_this_ttypes = 6;
	constexpr static signed short int Begin_It=0;
	constexpr static signed short int Begin_Opened_It=Begin_It-1;
	constexpr static signed short int End_It=number_of_function_members_of_this_ttypes-1;
	constexpr static signed short int End_Closed_It = End_It -1;
	constexpr static signed short int Succ_It(const short int k){
		return ((k<End_Closed_It)?((k>Begin_Opened_It)?(k+1):Begin_It):(End_Closed_It));
	}
	constexpr static signed short int Pred_It(const short int k){
		return ((k<End_It)?((k>Begin_It)?(k-1):Begin_It):(End_Closed_It));
	}
	
	using	eS_t						=	typename boolean_binary_dif_operators_class::eS;
	using	MBBDIFPTR_ss				=	bool (eS_t::*)(eS_t);
	using	operation_order_b2dif_ss	=	MBBDIFPTR_ss;
	using	MBBDIFPTR_tt				=	bool (T<R>::*)(S);
	using	operation_order_b2dif_tt	=	typename std::tuple<unsigned int,std::string,MBBDIFPTR_tt,MBBDIFPTR_ss>;

	constexpr static operation_order_b2dif_tt element_of_type_of_function_member_to_test[number_of_function_members_of_this_ttypes]{
		{0,"==",&(T<R>::operator==,&(eS_t::operator==))},
		{1,"!=",&(T<R>::operator!=,&(eS_t::operator==))},
		{2,"<",&(T<R>::operator<),&(eS_t::operator==)},
		{3,"<=",&(T<R>::operator<=),&(eS_t::operator==)},
		{4,">",&(T<R>::operator>),&(eS_t::operator==)},
		{5,">=",&(T<R>::operator>=),&(eS_t::operator==)}
	};

	// (boolean_binary_eq_operators_class(i).get<2>())(arg_1,arg_2)
    constexpr bool operator()(int i,T<R> arg_1,T<R> arg_2){
		auto previo_al_retorno = element_of_type_of_function_member_to_test[i];
		auto retorno = std::get<2>(previo_al_retorno);
        return retorno(arg_1,arg_2);
    }

	// (boolean_binary_eq_operators_class(i).get<3>())(arg_1,arg_2)
    constexpr bool operator()(int i,S arg_1,S arg_2){
		auto previo_al_retorno = element_of_type_of_function_member_to_test[i];
		auto retorno = std::get<3>(previo_al_retorno);
        return retorno(arg_1,arg_2);
    }

	// (boolean_binary_eq_operators_class(i).get<2>())(arg_1,arg_2)
    inline bool operator()(int i,T<R> arg_1,T<R> arg_2,S arg_1_t,S arg_2_t){
        return not(retorno(i,arg_1,arg_2) xor retorno(i,arg_1_t,arg_2_t));
    }

	void operator()(int i,T<R> arg_1,S arg_1_t){
		for(S arg_2_t = CTTI<U,T,R,S>::BeginIndex; arg_2_t < CTTI<U,T,R,S>::BeginIndex; ++arg_2_t) {
			const T<R> arg_2(arg_2_t);
			if (this->operator()(i,arg_1,arg_2,arg_1_t,arg_2_t)) {
				++test_results.number_of_corrects;
			}
			else {
				++test_results.number_of_errors;
				const	std::string	Op_name	=	std::get<1>(element_of_type_of_function_member_to_test[i]);
				test_results.list_of_erroneus_tests.append({T_template_name,R_radix_number,Op_name,arg_1,arg_2,arg_1_t,arg_2_t});
			}
		}
    }

public:

	void operator()(int i){
		for(S arg_1_t = CTTI<U,T,R,S>::BeginIndex; arg_1_t < CTTI<U,T,R,S>::BeginIndex; ++arg_1_t) {
			const T<R> arg_1(arg_1_t);
			this->operator()(i,arg_1,arg_1_t);
		}
    }

	void operator()(){
		for(auto k=Begin_It;k<End_It;k=Succ_It(k)) {
			this->operator()(k);
		}
	}

};

template<class U, template<const U R> class T,const U R, class S>
const std::string boolean_binary_dif_operators_class<U,T,R,S>::template_name() {
	return 	"nullclasstemplate";
}

template<class U, template<const U R> class T,const U R, class S>
const std::string boolean_binary_dif_operators_class<U,T,R,S>::T_template_name =
	boolean_binary_dif_operators_class<U,T,R,S>::template_name();

template<unsigned char R>
class boolean_binary_dif_operators_class<unsigned char,dig_t,R,int>{
	static std::string template_name();
	static const std::string T_template_name;
};

template<unsigned char R>
std::string boolean_binary_dif_operators_class<unsigned char,dig_t,R,int>::template_name() {
	return 	"dig";
}

template<unsigned char R> const std::string
boolean_binary_dif_operators_class<unsigned char,dig_t,R,int>::T_template_name =
	boolean_binary_dif_operators_class<unsigned char,dig_t,R,int>::template_name();

template<unsigned char R>
class boolean_binary_dif_operators_class<unsigned char,sdig_t,R,int>{
	static std::string template_name();
	static const std::string T_template_name;
};

template<unsigned char R>
std::string boolean_binary_dif_operators_class<unsigned char,sdig_t,R,int>::template_name() {
	return 	"sdig";
}

template<unsigned char R> const std::string
boolean_binary_dif_operators_class<unsigned char,sdig_t,R,int>::T_template_name =
	boolean_binary_dif_operators_class<unsigned char,sdig_t,R,int>::template_name();

template<unsigned char R>
class boolean_binary_dif_operators_class<unsigned char,pardigs_t,R,long int>{
	static std::string template_name();
	static const std::string T_template_name;
};

template<unsigned char R>
std::string boolean_binary_dif_operators_class<unsigned char,pardigs_t,R,long int>::template_name() {
	return 	"pardigs_t";
}

template<unsigned char R> const std::string
boolean_binary_dif_operators_class<unsigned char,pardigs_t,R,long int>::T_template_name =
	boolean_binary_dif_operators_class<unsigned char,pardigs_t,R,long int>::template_name();

template<unsigned char R>
class boolean_binary_dif_operators_class<unsigned char,spardigs_t,R,long int>{
	static std::string template_name();
	static const std::string T_template_name;
};

template<unsigned char R>
std::string boolean_binary_dif_operators_class<unsigned char,spardigs_t,R,long int>::template_name() {
	return 	"spardigs_t";
}

template<unsigned char R> const std::string
boolean_binary_dif_operators_class<unsigned char,spardigs_t,R,long int>::T_template_name =
	boolean_binary_dif_operators_class<unsigned char,spardigs_t,R,long int>::template_name();

/**
***   FIN DE LA CLASE PARA TESTS DE FUNCIONES BULEANAS BINARIAS DE TIPOS DIFERENTES
**/

/**
***   COMIENZO DE LA CLASE PARA TESTS DE FUNCIONES ARITMETICAS UNARIAS POST
**/


template<typename U,template<const U> class T,U R,class S>
using MAAUXPTR_tt = T<R>&(T<R>::*)(int);

template<typename U,template<const U> class T,U R,class S>
using	operation_order_aa1x_tt	=	std::tuple<unsigned int,std::string,MAAUXPTR_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,class S>
operation_order_aa1x_tt<U,T,R,S> arithmetic_with_assignation_unary_post_operators(unsigned int i)	{
	switch(i) {
		case 0 : return {0,"++(int)",&(T<R>::operator++)};
		default : return {1,"--(int)",&(T<R>::operator--)};
	}
}


/**
***   FIN DE LA CLASE PARA TESTS DE FUNCIONES ARITMETICAS UNARIAS POST
**/


/**
***   COMIENZO DE LA CLASE PARA TESTS DE FUNCIONES ARITMETICAS UNARIAS PRE
**/

template<typename U,template<const U> class T,U R,class S>
using MAAUPTR_tt = T<R>& (T<R>::*) ();

template<typename U,template<const U> class T,U R,class S>
using	operation_order_aa1_tt	=	std::tuple<unsigned int,std::string,MAAUPTR_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,class S>
operation_order_aa1_tt<U,T,R,S> arithmetic_with_assignation_unary_operators(unsigned int i)	{
	switch(i) {
		case 0 : return {0,"++",&(T<R>::operator++)};
		case 1 : return {1,"--",&(T<R>::operator--)};
		case 2 : return {2,"mC_Bm1",&(T<R>::mC_Bm1)};
		case 3 : return {3,"mC_B",&(T<R>::mC_B)};
		default : return {4,"m_abs",&(T<R>::m_abs)};
	}
}


/**
***   FIN DE LA CLASE PARA TESTS DE FUNCIONES ARITMETICAS UNARIAS PRE
**/


/**
***   COMIENZO DE LA CLASE PARA TESTS DE ASIGNACIONES HETEROGENEAS
**/

template<typename U,template<const U> class T,U R,typename S>
using ASIGNACION_DIF_tt = T<R>&(T<R>::*)(S);

template<typename U,template<const U> class T,U R,typename S>
using	operation_order_assignation2dif_tt	=	std::tuple<unsigned int,std::string,ASIGNACION_DIF_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,typename S>
operation_order_assignation2dif_tt<U,T,R,S> assignation_dif_operators(unsigned int i)	{
	switch(i) {
		default : return {0,"T<R> object = S object",&(T<R>::operator=)};
	}
}


/**
***   FIN DE LA CLASE PARA TESTS DE ASIGNACIONES HETEROGENEAS
**/


/**
***   COMIENZO DE LA CLASE PARA TESTS DE ASIGNACIONES HOMOGENEAS
**/



template<typename U,template<const U> class T,U R,typename S>
using ASIGNACION_EQ_tt = T<R>&(T<R>::*)(T<R>&);

template<typename U,template<const U> class T,U R,typename S>
using	operation_order_assignation2eq_tt	=	std::tuple<unsigned int,std::string,ASIGNACION_EQ_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,typename S>
operation_order_assignation2eq_tt<U,T,R,S> assignation_eq_operators(unsigned int i)	{
	switch(i) {
		default : return {0,"T<R> object = T<R> object",&(T<R>::operator=)};
	}
}


/**
***   FIN DE LA CLASE PARA TESTS DE ASIGNACIONES HOMOGENEAS
**/


/**
***   COMIENZO DE LA CLASE PARA TESTS DE DISTINTOS CASTS
**/



template<typename U,template<const U> class T,U R,typename S>
using CAST_tt = S (T<R>::*)();

template<typename U,template<const U> class T,U R,typename S>
using	operation_order_cast_tt	=	std::tuple<unsigned int,std::string,CAST_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,typename S>
operation_order_cast_tt<U,T,R,S> cast(unsigned int i)	{
	switch(i) {
		default : return {0,"S(const T<R>&)",&(T<R>::operator S)};
	}
}


/**
***   FIN DE LA CLASE PARA TESTS DE DISTINTOS CASTS
**/


//	arithmetic_binary_eq_operators
//	boolean_binary_eq_operators
template<class U, template<const U R> class T,const U R, class S>
class ARITH_BIN_EQ_const {
public:
    T<R>  operator()(int i,T<R> arg_1,T<R> arg_2){
        switch(i){
            case 0 :       return (arg_1 + arg_2);
            case 1 :       return (arg_1 - arg_2);
            case 2 :       return (arg_1 * arg_2);
            case 3 :       return (((arg_2.is_0())||(arg_1.is_min()&&arg_2.is_m1()))?(T<R>(0)):(arg_1 / arg_2));
            case 4 :       return (arg_2.is_0())?(T<R>(0)):(arg_1 % arg_2);
            case 5 :       return ((arg_1 == arg_2)?T<R>(1):T<R>(0));
            case 6 :       return ((arg_1 != arg_2)?T<R>(1):T<R>(0));
            case 7 :       return ((arg_1 >= arg_2)?T<R>(1):T<R>(0));
            case 8 :       return ((arg_1 > arg_2)?T<R>(1):T<R>(0));
            case 9 :       return ((arg_1 <= arg_2)?T<R>(1):T<R>(0));
            case 10 :
            default :      return ((arg_1 < arg_2)?T<R>(1):T<R>(0));
        }
    }
};

template<class U,template<const U R> class T,const U R , class S>
class ARITH_BIN_EQ_T_const {
public:
    S  operator()(int i,S arg_1,S arg_2){
                switch(i){
                    case 0 :
						{	//return (arg_1 + arg_2)%(CTTI<U,T,R,S>::MaxPowRadix);
							S ret;
							ret = arg_1 + arg_2;
							if(CTTI<U,T,R,S>::with_sign) {
								if (ret < S(CTTI<U,T,R,S>::BeginIndex)) {
									ret +=(2*S(CTTI<U,T,R,S>::MaxPowRadix));
								}
								else if (ret > S(CTTI<U,T,R,S>::EndIndex)) {
									ret -= (2*S(CTTI<U,T,R,S>::MaxPowRadix));
								}
							}
							else {
								if (ret < S(CTTI<U,T,R,S>::BeginIndex)) {
									ret += S(CTTI<U,T,R,S>::MaxPowRadix);
								}
								else if (ret > S(CTTI<U,T,R,S>::EndIndex)) {
									ret -= S(CTTI<U,T,R,S>::MaxPowRadix);
								}
							}
							return ret;
						}
                    case 1 :
						{	//return (arg_1 + arg_2)%(CTTI<U,T,R,S>::MaxPowRadix);
							S ret;
							ret = arg_1 - arg_2;
							if(CTTI<U,T,R,S>::with_sign) {
								if (ret < S(CTTI<U,T,R,S>::BeginIndex)) {
									ret +=(2*S(CTTI<U,T,R,S>::MaxPowRadix));
								}
								else if (ret > S(CTTI<U,T,R,S>::EndIndex)) {
									ret -= (2*S(CTTI<U,T,R,S>::MaxPowRadix));
								}
							}
							else {
								if (ret < S(CTTI<U,T,R,S>::BeginIndex)) {
									ret += S(CTTI<U,T,R,S>::MaxPowRadix);
								}
								else if (ret > S(CTTI<U,T,R,S>::EndIndex)) {
									ret -= S(CTTI<U,T,R,S>::MaxPowRadix);
								}
							}
							return ret;
						}
                    case 2 :
						return (arg_1 * arg_2)%(CTTI<U,T,R,S>::MaxPowRadix);
                    case 3 :
						return ((arg_2==0)||((arg_1==CTTI<U,T,R,S>::BeginIndex)&&(arg_2==-1)))?(0):(arg_1 / arg_2);
                    case 4 :
						return (arg_2==0)?(0):(arg_1 % arg_2);
                    case 5 :
						return ((arg_1 == arg_2)?1:0);
                    case 6 :
						return ((arg_1 != arg_2)?1:0);
                    case 7 :
						return ((arg_1 >= arg_2)?1:0);
                    case 8 :
						return ((arg_1 > arg_2)?1:0);
                    case 9 :
						return ((arg_1 <= arg_2)?1:0);
                    case 10 :
                    default :
						return ((arg_1 < arg_2)?1:0);
                }
        }
};

//	arithmetic_with_assignation_binary_eq_operators
template<class U, template<const U R> class T,const U R , class S>
class ARITH_BIN_EQ {
public:
    void operator()(int i,T<R>& arg_1,const T<R>& arg_2){
		const T<R> Zero;
        switch(i){
            case 0 : arg_1+=arg_2;  break;
            case 1 : arg_1-=arg_2;  break;
            case 2 : arg_1*=arg_2;  break;
            case 3 :{
						if((arg_2==Zero)||((arg_1==T<R>(CTTI<U,T,R,S>::BeginIndex))&&(arg_2.is_m1())))
							arg_1=Zero;
						else
							arg_1/=arg_2;
					}
					break;
            case 4 :{
						if(arg_2==Zero)
							arg_1=Zero;
						else
							arg_1%=arg_2;
					}
					break;
        }
    }
};

template<class U, template<const U R> class T,const U R, class S>
class ARITH_BIN_EQ_T {
public:
       void operator()(int i,S & arg_1,const S & arg_2){
			switch(i){
				case 0 :{
							arg_1 += arg_2;
							if (arg_1 < (CTTI<U,T,R,S>::BeginIndex)) {
								if(CTTI<U,T,R,S>::with_sign) {
									arg_1 +=(2*(CTTI<U,T,R,S>::MaxPowRadix));
								}
							}
							else if (arg_1 > (CTTI<U,T,R,S>::EndIndex)) {
								if(CTTI<U,T,R,S>::with_sign) {
									arg_1 -= (2*(CTTI<U,T,R,S>::MaxPowRadix));
								}
								else {
									arg_1 %= (CTTI<U,T,R,S>::MaxPowRadix);
								}
							}
						}
						break;
				case 1 :{
							arg_1 -= arg_2;
							if (arg_1 < CTTI<U,T,R,S>::BeginIndex) {
								if(CTTI<U,T,R,S>::with_sign) {
									arg_1 +=(2*(CTTI<U,T,R,S>::MaxPowRadix));
								}
								else {
									arg_1 += (CTTI<U,T,R,S>::MaxPowRadix);
								}
							}
							else if (arg_1 > CTTI<U,T,R,S>::EndIndex) {
								if(CTTI<U,T,R,S>::with_sign) {
									arg_1 -=(2*(CTTI<U,T,R,S>::MaxPowRadix));
								}
								else {
									arg_1 -= (CTTI<U,T,R,S>::MaxPowRadix);
								}
							}
						}
						break;
				case 2 :{
							arg_1*=arg_2;
							arg_1%=(CTTI<U,T,R,S>::MaxPowRadix);
						}
						break;
				case 3 :{
							if((arg_2==0)||((arg_1==CTTI<U,T,R,S>::BeginIndex)&&(arg_2==-1)))
								arg_1=0;
							else
								arg_1/=arg_2;
						}
						break;
				case 4 :
				default :{
							if (arg_2==0)
								arg_1=0;
							else
								arg_1%=arg_2;
						}
						break;
			}
    }
};

//	boolean_binary_dif_operators
//	arithmetic_binary_dif_operators
template<class U, template<const U R> class T,const U R, class S>
class ARITH_BIN_DIF_const {
public:
    T<R>  operator()(int i,T<R> arg_1,S arg_2){
        switch(i){
            case 0 :       return (arg_1 + arg_2);
            case 1 :       return (arg_1 - arg_2);
            case 2 :       return (arg_1 * arg_2);
            case 3 :       return (((arg_2.is_0())||(arg_1.is_min()&&arg_2.is_m1()))?(T<R>(0)):(arg_1 / arg_2));
            case 4 :       return (arg_2.is_0())?(T<R>(0)):(arg_1 % arg_2);
            case 5 :       return ((arg_1 == arg_2)?T<R>(1):T<R>(0));
            case 6 :       return ((arg_1 != arg_2)?T<R>(1):T<R>(0));
            case 7 :       return ((arg_1 >= arg_2)?T<R>(1):T<R>(0));
            case 8 :       return ((arg_1 > arg_2)?T<R>(1):T<R>(0));
            case 9 :       return ((arg_1 <= arg_2)?T<R>(1):T<R>(0));
            case 10 :
            default :      return ((arg_1 < arg_2)?T<R>(1):T<R>(0));
        }
    }
};

template<class U,template<const U R> class T,const U R , class S>
class ARITH_BIN_DIF_T_const {
public:
    S  operator()(int i,S arg_1,S arg_2){
                switch(i){
                    case 0 :
						{	//return (arg_1 + arg_2)%(CTTI<U,T,R,S>::MaxPowRadix);
							S ret;
							ret = arg_1 + arg_2;
							if(CTTI<U,T,R,S>::with_sign) {
								if (ret < S(CTTI<U,T,R,S>::BeginIndex)) {
									ret +=(2*S(CTTI<U,T,R,S>::MaxPowRadix));
								}
								else if (ret > S(CTTI<U,T,R,S>::EndIndex)) {
									ret -= (2*S(CTTI<U,T,R,S>::MaxPowRadix));
								}
							}
							else {
								if (ret < S(CTTI<U,T,R,S>::BeginIndex)) {
									ret += S(CTTI<U,T,R,S>::MaxPowRadix);
								}
								else if (ret > S(CTTI<U,T,R,S>::EndIndex)) {
									ret -= S(CTTI<U,T,R,S>::MaxPowRadix);
								}
							}
							return ret;
						}
                    case 1 :
						{	//return (arg_1 + arg_2)%(CTTI<U,T,R,S>::MaxPowRadix);
							S ret;
							ret = arg_1 - arg_2;
							if(CTTI<U,T,R,S>::with_sign) {
								if (ret < S(CTTI<U,T,R,S>::BeginIndex)) {
									ret +=(2*S(CTTI<U,T,R,S>::MaxPowRadix));
								}
								else if (ret > S(CTTI<U,T,R,S>::EndIndex)) {
									ret -= (2*S(CTTI<U,T,R,S>::MaxPowRadix));
								}
							}
							else {
								if (ret < S(CTTI<U,T,R,S>::BeginIndex)) {
									ret += S(CTTI<U,T,R,S>::MaxPowRadix);
								}
								else if (ret > S(CTTI<U,T,R,S>::EndIndex)) {
									ret -= S(CTTI<U,T,R,S>::MaxPowRadix);
								}
							}
							return ret;
						}
                    case 2 :
						return (arg_1 * arg_2)%(CTTI<U,T,R,S>::MaxPowRadix);
                    case 3 :
						return ((arg_2==0)||((arg_1==CTTI<U,T,R,S>::BeginIndex)&&(arg_2==-1)))?(0):(arg_1 / arg_2);
                    case 4 :
						return (arg_2==0)?(0):(arg_1 % arg_2);
                    case 5 :
						return ((arg_1 == arg_2)?1:0);
                    case 6 :
						return ((arg_1 != arg_2)?1:0);
                    case 7 :
						return ((arg_1 >= arg_2)?1:0);
                    case 8 :
						return ((arg_1 > arg_2)?1:0);
                    case 9 :
						return ((arg_1 <= arg_2)?1:0);
                    case 10 :
                    default :
						return ((arg_1 < arg_2)?1:0);
                }
        }
};

//	arithmetic_with_assignation_binary_dif_operators
template<class U, template<const U R> class T,const U R , class S>
class ARITH_BIN_DIF {
public:
    void operator()(int i,T<R>& arg_1,const S& arg_2){
		const T<R> Zero;
        switch(i){
            case 0 : arg_1+=arg_2;  break;
            case 1 : arg_1-=arg_2;  break;
            case 2 : arg_1*=arg_2;  break;
            case 3 :{
						if((arg_2==0)||((arg_1==T<R>(CTTI<U,T,R,S>::BeginIndex))&&(arg_2==-1)))
							arg_1=Zero;
						else
							arg_1/=arg_2;
					}
					break;
            case 4 :{
						if(arg_2==0)
							arg_1=Zero;
						else
							arg_1%=arg_2;
					}
					break;
        }
    }
};

template<class U, template<const U R> class T,const U R, class S>
class ARITH_BIN_DIF_T {
public:
       void operator()(int i,S & arg_1,const S & arg_2){
			switch(i){
				case 0 :{
							arg_1 += arg_2;
							if (arg_1 < (CTTI<U,T,R,S>::BeginIndex)) {
								if(CTTI<U,T,R,S>::with_sign) {
									arg_1 +=(2*(CTTI<U,T,R,S>::MaxPowRadix));
								}
							}
							else if (arg_1 > (CTTI<U,T,R,S>::EndIndex)) {
								if(CTTI<U,T,R,S>::with_sign) {
									arg_1 -= (2*(CTTI<U,T,R,S>::MaxPowRadix));
								}
								else {
									arg_1 %= (CTTI<U,T,R,S>::MaxPowRadix);
								}
							}
						}
						break;
				case 1 :{
							arg_1 -= arg_2;
							if (arg_1 < CTTI<U,T,R,S>::BeginIndex) {
								if(CTTI<U,T,R,S>::with_sign) {
									arg_1 +=(2*(CTTI<U,T,R,S>::MaxPowRadix));
								}
								else {
									arg_1 += (CTTI<U,T,R,S>::MaxPowRadix);
								}
							}
							else if (arg_1 > CTTI<U,T,R,S>::EndIndex) {
								if(CTTI<U,T,R,S>::with_sign) {
									arg_1 -=(2*(CTTI<U,T,R,S>::MaxPowRadix));
								}
								else {
									arg_1 -= (CTTI<U,T,R,S>::MaxPowRadix);
								}
							}
						}
						break;
				case 2 :{
							arg_1*=arg_2;
							arg_1%=(CTTI<U,T,R,S>::MaxPowRadix);
						}
						break;
				case 3 :{
							if((arg_2==0)||((arg_1==CTTI<U,T,R,S>::BeginIndex)&&(arg_2==-1)))
								arg_1=0;
							else
								arg_1/=arg_2;
						}
						break;
				case 4 :
				default :{
							if (arg_2==0)
								arg_1=0;
							else
								arg_1%=arg_2;
						}
						break;
			}
    }
};

//	boolean_unary_operators
//	arithmetic_with_assignation_unary_post_operators
//	arithmetic_with_assignation_unary_operators
//	arithmetic_unary_operators
//	assignation_dif_operators
//	assignation_eq_operators
//	cast_operators

#endif //BASIC_CONSTANTS_AND_LISTS_4_TEST_UNIT__HPP
