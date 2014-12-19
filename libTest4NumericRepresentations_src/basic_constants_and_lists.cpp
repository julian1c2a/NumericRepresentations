#ifndef BASIC_CONSTANTS_AND_LISTS__HPP
#define BASIC_CONSTANTS_AND_LISTS__HPP


#include <tuple>
#include <string>

const unsigned short int number_of_radixes_to_test = 10;
const unsigned char radixes[number_of_radixes_to_test] = {2,3,10,15,30,48,127,128,210,255};

const unsigned short int number_of_high_radixes_to_test = 4;
const unsigned char high_radixes[number_of_radixes_to_test] = {128,144,210,255};

const unsigned short int number_of_low_radixes_to_test = 11;
const unsigned char low_radixes[number_of_low_radixes_to_test] = {2,3,5,7,10,11,13,15,30,48,127};


template<typename U,template<const U> class T,U R,class S>
using MBUPTR_tt = bool T<R>::* ();

template<typename U,template<const U> class T,U R,class S>
using	operation_order_b1_tt	=	std::tuple<unsigned int,std::string,MBUPTR_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,class S>
operation_order_b1_tt<U,T,R,S> boolean_unary_operators(unsigned int i)	{
	switch(i) {
		case 0 : return {0,"is_0",&(T<R>::is_0)};
		case 1 : return {1,"is_1",&(T<R>::is_1)};
		case 2 : return {2,"is_m1",&(T<R>::is_m1)};
		case 3 : return {3,"is_max",&(T<R>::is_max)};
		case 4 : return {4,"is_submax",&(T<R>::is_submax)};
		case 5 : return {5,"is_min",&(T<R>::is_min)};
		case 6 : return {6,"is_submin",&(T<R>::is_submin)};
		case 7 : return {7,"is_negative",&(T<R>::is_negative)};
		case 8 : return {8,"is_positive",&(T<R>::is_positive)};
	}
}

template<typename U,template<const U> class T,U R,class S>
using MBBEQPTR_tt = bool T<R>::* (T<R>);

template<typename U,template<const U> class T,U R,class S>
using	operation_order_b2eq_tt	=	std::tuple<unsigned int,std::string,MBBEQPTR_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,class S>
operation_order_b2eq_tt<U,T,R,S> boolean_binary_eq_operators(unsigned int i)	{
	switch(i) {
		case 0 : return {0,"==",&(T<R>::operator==)};
		case 1 : return {1,"!=",&(T<R>::operator!=)};
		case 2 : return {2,"<",&(T<R>::operator<)};
		case 3 : return {3,"<=",&(T<R>::operator<=)};
		case 4 : return {4,">",&(T<R>::operator>)};
		case 5 : return {5,">=",&(T<R>::operator>=)};
	}
}


template<typename U,template<const U> class T,U R,typename S>
using MBBDIFPTR_tt = bool T<R>::* (S);

template<typename U,template<const U> class T,U R,typename S>
using	operation_order_b2dif_tt	=	std::tuple<unsigned int,std::string,MBBDIFPTR_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,typename S>
operation_order_b2dif_tt<U,T,R,S> boolean_binary_dif_operators(unsigned int i)	{
	switch(i) {
		case 0 : return {0,"==",&(T<R>::operator==)};
		case 1 : return {1,"!=",&(T<R>::operator!=)};
		case 2 : return {2,"<",&(T<R>::operator<)};
		case 3 : return {3,"<=",&(T<R>::operator<=)};
		case 4 : return {4,">",&(T<R>::operator>)};
		case 5 : return {5,">=",&(T<R>::operator>=)};
	}
}

template<typename U,template<const U> class T,U R,class S>
using MAAUXPTR_tt = T<R>&(T<R>::*)(int);

template<typename U,template<const U> class T,U R,class S>
using	operation_order_aa1x_tt	=	std::tuple<unsigned int,std::string,MAAUXPTR_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,class S>
operation_order_aa1x_tt<U,T,R,S> arithmetic_with_assignation_unary_post_operators(unsigned int i)	{
	switch(i) {
		case 0 : return {0,"++(int)",&(T<R>::operator++)};
		case 1 : return {1,"--(int)",&(T<R>::operator--)};
	}
}

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
		case 4 : return {4,"m_abs",&(T<R>::m_abs)};
	}
}

template<typename U,template<const U> class T,U R,typename S>
using MAUPTR_tt = T<R>(T<R>::*)();

template<typename U,template<const U> class T,U R,typename S>
using	operation_order_a1_tt	=	std::tuple<unsigned int,std::string,MAUPTR_tt<U,T,R,S>>;

template<typename U,template<const U> class T,U R,typename S>
operation_order_a1_tt<U,T,R,S> arithmetic_unary_operators(unsigned int i)	{
	switch(i) {
		case 0 : return {0,"!",&(T<R>::operator!)};
		case 1 : return {1,"-",&(T<R>::operator-)};
		case 2 : return {2,"abs",&(T<R>::abs)};
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
		case 4 : return {4,"%=",&(T<R>::operator%=)};
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
		case 4 : return {4,"%=",&(T<R>::operator%=)};
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
		case 4 : return {4,"%",&(T<R>::operator%)};
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


#endif //BASIC_CONSTANTS_AND_LISTS__HPP