#ifndef BINARY_OPERATORS_TEST_UNIT__HPP
#define BINARY_OPERATORS_TEST_UNIT__HPP

#include "constants_test_unit.hpp"

template<class U, template<const U R> class T,const U R, class S> 
class BINARIA_const {
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
class BINARIA_T_const {
public:
    S  operator()(int i,S arg_1,S arg_2){
                switch(i){
                    case 0 :
						{	//return (arg_1 + arg_2)%(Limit<U,T,R,S>::MaxPowRadix);
							S ret;
							ret = arg_1 + arg_2;
							if(T<R>::with_sign) {
								if (ret < S(Limit<U,T,R,S>::BeginIndex)) {
									ret +=(2*S(Limit<U,T,R,S>::MaxPowRadix));
								}
								else if (ret > S(Limit<U,T,R,S>::EndIndex)) {
									ret -= (2*S(Limit<U,T,R,S>::MaxPowRadix));
								}
							}
							else {
								if (ret < S(Limit<U,T,R,S>::BeginIndex)) {
									ret += S(Limit<U,T,R,S>::MaxPowRadix);
								}
								else if (ret > S(Limit<U,T,R,S>::EndIndex)) {
									ret -= S(Limit<U,T,R,S>::MaxPowRadix);
								}
							}
							return ret;
						}
                    case 1 :
						{	//return (arg_1 + arg_2)%(Limit<U,T,R,S>::MaxPowRadix);
							S ret;
							ret = arg_1 - arg_2;
							if(T<R>::with_sign) {
								if (ret < S(Limit<U,T,R,S>::BeginIndex)) {
									ret +=(2*S(Limit<U,T,R,S>::MaxPowRadix));
								}
								else if (ret > S(Limit<U,T,R,S>::EndIndex)) {
									ret -= (2*S(Limit<U,T,R,S>::MaxPowRadix));
								}
							}
							else {
								if (ret < S(Limit<U,T,R,S>::BeginIndex)) {
									ret += S(Limit<U,T,R,S>::MaxPowRadix);
								}
								else if (ret > S(Limit<U,T,R,S>::EndIndex)) {
									ret -= S(Limit<U,T,R,S>::MaxPowRadix);
								}
							}
							return ret;
						}
                    case 2 :
						return (arg_1 * arg_2)%(Limit<U,T,R,S>::MaxPowRadix);
                    case 3 :
						return ((arg_2==0)||((arg_1==Limit<U,T,R,S>::BeginIndex)&&(arg_2==-1)))?(0):(arg_1 / arg_2);
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

template<class U, template<const U R> class T,const U R , class S> 
class BINARIA {
public:
    void operator()(int i,T<R>& arg_1,const T<R>& arg_2){
		const T<R> Zero;
        switch(i){
            case 0 : arg_1+=arg_2;  break;
            case 1 : arg_1-=arg_2;  break;
            case 2 : arg_1*=arg_2;  break;
            case 3 :{
						if((arg_2==Zero)||((arg_1==T<R>(Limit<U,T,R,S>::BeginIndex))&&(arg_2.is_m1())))
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
class BINARIA_T {
public:
       void operator()(int i,S & arg_1,const S & arg_2){
			switch(i){
				case 0 :{
							arg_1 += arg_2;
							if (arg_1 < (Limit<U,T,R,S>::BeginIndex)) {
								if(T<R>::with_sign) {
									arg_1 +=(2*(Limit<U,T,R,S>::MaxPowRadix));
								}
							}
							else if (arg_1 > (Limit<U,T,R,S>::EndIndex)) {
								if(T<R>::with_sign) {
									arg_1 -= (2*(Limit<U,T,R,S>::MaxPowRadix));
								}
								else {
									arg_1 %= (Limit<U,T,R,S>::MaxPowRadix);
								}
							}
						}
						break;
				case 1 :{
							arg_1 -= arg_2;
							if (arg_1 < Limit<U,T,R,S>::BeginIndex) {
								if(T<R>::with_sign) {
									arg_1 +=(2*(Limit<U,T,R,S>::MaxPowRadix));
								}
								else {
									arg_1 += (Limit<U,T,R,S>::MaxPowRadix);
								}
							}
							else if (arg_1 > Limit<U,T,R,S>::EndIndex) {
								if(T<R>::with_sign) {
									arg_1 -=(2*(Limit<U,T,R,S>::MaxPowRadix));
								}
								else {
									arg_1 -= (Limit<U,T,R,S>::MaxPowRadix);
								}
							}
						}
						break;
				case 2 :{
							arg_1*=arg_2;
							arg_1%=(Limit<U,T,R,S>::MaxPowRadix);
						}
						break;
				case 3 :{ 	
							if((arg_2==0)||((arg_1==Limit<U,T,R,S>::BeginIndex)&&(arg_2==-1)))
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



template<class U,template<const U R> class T,const U R,class S >
result_test test_operator_binario_const(unsigned int i)
{

	result_test result = {0,0};

	BINARIA_const<U,T,R,S>          Resolucion_Clase;
    BINARIA_T_const<U,T,R,S>   Resolucion_con_enteros;

	for(S Indice_1 = Limit<U,T,R,S>::BeginIndex ; Indice_1 <= Limit<U,T,R,S>::EndIndex ; ++Indice_1)	{
            for(S Indice_2 = Limit<U,T,R,S>::BeginIndex ;Indice_2 <= Limit<U,T,R,S>::EndIndex;++Indice_2)	{
                const S a = Indice_1;
                const S b = Indice_2;
                const T<R> A(Indice_1);
                const T<R> B(Indice_2);
                T<R> C(Resolucion_Clase(i,A,B));
                const S c = Resolucion_con_enteros(i,a,b);
                const S iC = S(C);
                if (iC==c) {
                    ++result.correctos;
                }
                else {
                    ++result.erroneos;
                }
            }
	}

	return result;
}

template<class U,template<const U R> class T,const U R,class S >
result_test test_operator_binario(unsigned int i)
 {

    result_test result = {0,0};

    BINARIA<U,T,R,S>        Resolucion_Clase;
    BINARIA_T<U,T,R,S>      Resolucion_con_enteros;

	for(S Indice_1 = Limit<U,T,R,S>::BeginIndex ; Indice_1 <= Limit<U,T,R,S>::EndIndex ; ++Indice_1)	{
            for(S Indice_2 = Limit<U,T,R,S>::BeginIndex ; Indice_2 <= Limit<U,T,R,S>::EndIndex ; ++Indice_2)	{
                S a=Indice_1;
                const S b=Indice_2;
                T<R> A(Indice_1);
                const T<R> B(Indice_2);
                Resolucion_Clase(i,A,B);
                Resolucion_con_enteros(i,a,b);
                const S iA = S(A);
                if (iA==a) {
                    ++result.correctos;
                }
                else {
                    ++result.erroneos;
                }
            }
	}
	return result;
}

/* resumen binary test_num :

    SOBRECARGA DEL OPERADOR ()
	 CADA OPERACION SE SELECCIONA CON (i,_,_)
    LOS ARGUMENTOS SE PASAN EN  (_,X,Y)
	 X e Y TIENEN EL MISMO TIPO
	 C(i,x,y) LO QUE HACE ES [x OP(i) y]
    ______________________________________________ 
	BINARY (NON-CONST)   Y   BINARY_T (NON_CONST)
	__________________       ____________________
	OPERADORES BINARIOS      OPERADORES BINARIOS
	DE LA CLASE CONTRUIDA    DE UN TIPO BUILT-IN
	POR NOSOTROS             CON ARGUMENTOS QUE
	CON ARGUMENTOS QUE       PUEDEN VARIAR.
	PUEDEN VARIAR.  
	______________________________________________
	LAS FUNCIONES TEST_OPERADOR_BINARIO Y 
	TEST_OPERADOR_BINARIO_CONST SOLO COMPARAN LOS
	RESULTADOS DE 
	t_built-in(C(i,X,Y))==C_[t_built-in](i,T(X),T(Y))
	DE ESTA FORMA RELLENAMOS ERRORES O CORRECTOS

******/

#endif //  BINARY_OPERATORS_TEST_UNIT__HPP