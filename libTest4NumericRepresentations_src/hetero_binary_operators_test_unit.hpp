#ifndef HETERO_BINARY_OPERATORS_TEST_UNIT__HPP
#define HETERO_BINARY_OPERATORS_TEST_UNIT__HPP


#include "src/libTest4NumericRepresentations_src/basic_constants_and_lists_4_test_unit.hpp"

template< class U, template<const U R> class T , const U R , class S >
class BINARIA_hetero_const
{
public:
    T<R>  operator()(int i,T<R> arg_1,S arg_2){
        switch(i){
            case 0 :       return (arg_1 + T<R>(arg_2));
            case 1 :       return (arg_1 - T<R>(arg_2));
            case 2 :       return (arg_1 * T<R>(arg_2));
            case 3 :       return (T<R>(arg_2)==T<R>(0))?(T<R>(0)):(arg_1 / T<R>(arg_2));
            case 4 :       return (T<R>(arg_2)==T<R>(0))?(T<R>(0)):(arg_1 % T<R>(arg_2));
            case 5 :       return ((arg_1 == T<R>(arg_2))?T<R>(1):T<R>(0));
            case 6 :       return ((arg_1 != T<R>(arg_2))?T<R>(1):T<R>(0));
            case 7 :       return ((arg_1 >= T<R>(arg_2))?T<R>(1):T<R>(0));
            case 8 :       return ((arg_1 > T<R>(arg_2))?T<R>(1):T<R>(0));
            case 9 :       return ((arg_1 <= T<R>(arg_2))?T<R>(1):T<R>(0));
            case 10 :      return ((arg_1 < T<R>(arg_2))?T<R>(1):T<R>(0));
            default :      return arg_1;
        }
    }
};

template< class U, template<const U R> class T , const U R , class S >
class BINARIA_hetero_T_const
{
public:
    S  operator()(int i,S arg_1,S arg_2){
        switch(CTTI<U,T,R,S>::NDigs) {
            case 1 :
                switch(i){
                    case 0 :       return (arg_1 + arg_2)%R;
                    case 1 :       return (arg_1 + R - arg_2)%R;
                    case 2 :       return (arg_1 * arg_2)%R;
                    case 3 :       return (arg_2==0)?(0):(arg_1 / arg_2);
                    case 4 :       return (arg_2==0)?(0):(arg_1 % arg_2);
                    case 5 :       return ((arg_1 == arg_2)?1:0);
                    case 6 :       return ((arg_1 != arg_2)?1:0);
                    case 7 :       return ((arg_1 >= arg_2)?1:0);
                    case 8 :       return ((arg_1 > arg_2)?1:0);
                    case 9 :       return ((arg_1 <= arg_2)?1:0);
                    case 10 :      return ((arg_1 < arg_2)?1:0);
                    default :      return arg_1;
                }
            case 2 :
                switch(i){
                    case 0 :       return (arg_1 + arg_2)%(R*R);
                    case 1 :       return (arg_1 + (R*R) - arg_2)%(R*R);
                    case 2 :       return (arg_1 * arg_2)%(R*R);
                    case 3 :       return (arg_2==0)?(0):(arg_1 / arg_2);
                    case 4 :       return (arg_2==0)?(0):(arg_1 % arg_2);
                    case 5 :       return ((arg_1 == arg_2)?1:0);
                    case 6 :       return ((arg_1 != arg_2)?1:0);
                    case 7 :       return ((arg_1 >= arg_2)?1:0);
                    case 8 :       return ((arg_1 > arg_2)?1:0);
                    case 9 :       return ((arg_1 <= arg_2)?1:0);
                    case 10 :      return ((arg_1 < arg_2)?1:0);
                    default :      return arg_1;
                }
			default: return arg_1;
        }
    }
};

template< class U, template<const U R> class T , const U R , class S >
class BINARIA_hetero
{
public:
    void operator()(int i,T<R>& arg_1,const S& arg_2){
        switch(i){
            case 0 : arg_1+= T<R>(arg_2);  break;
            case 1 : arg_1-= T<R>(arg_2);  break;
            case 2 : arg_1*= T<R>(arg_2);  break;
            case 3 : (S(arg_2)==S(0))?(arg_1=T<R>(0)):(arg_1/=T<R>(arg_2));  break;
            case 4 : (S(arg_2)==S(0))?(arg_1=T<R>(0)):(arg_1%=T<R>(arg_2));  break;
        }
    }
};

template< class U, template<const U R> class T , const U R , class S >
class BINARIA_hetero_T
{
public:
       void operator()(int i,S & arg_1,const S & arg_2){
           switch(CTTI<U,T,R,S>::NDigs) {
               case 1 :
                    switch(i){
                        case 0 : arg_1+=arg_2; arg_1=arg_1%R;  break;
                        case 1 : (arg_1<arg_2)?(arg_1 += (R - arg_2) ):(arg_1-=arg_2);  break;
                        case 2 : arg_1*=arg_2;arg_1%=R;  break;
                        case 3 : (arg_2==0)?(arg_1=0):(arg_1/=arg_2);  break;
                        case 4 : (arg_2==0)?(arg_1=0):(arg_1%=arg_2);  break;
                    }
                    break;
                case 2 :
                    switch(i){
                        case 0 : arg_1+=arg_2; arg_1=arg_1%(R*R);  break;
                        case 1 : (arg_1<arg_2)?(arg_1 += ((R*R) - arg_2) ):(arg_1-=arg_2);  break;
                        case 2 : arg_1*=arg_2;arg_1%=(R*R);  break;
                        case 3 : (arg_2==0)?(arg_1=0):(arg_1/=arg_2);  break;
                        case 4 : (arg_2==0)?(arg_1=0):(arg_1%=arg_2);  break;
                    }
                    break;
           }
    }
};



template< class U, template<const U R> class T , const U R , class S >
result_test test_operator_binario_hetero_const(unsigned int i)
{

    result_test result = {0,0};

	BINARIA_hetero_const<U,T,R,S>          Resolucion_Clase;
    BINARIA_hetero_T_const<U,T,R,S>        Resolucion_con_enteros;

	for(S Indice_1 = 0;Indice_1< ((CTTI<U,T,R,S>::NDigs == 1)?(R):(R*R));++Indice_1)	{
            for(S Indice_2 = 0;Indice_2< ((CTTI<U,T,R,S>::NDigs == 1)?(R):(R*R));++Indice_2)	{
                const S a = Indice_1;
                const S b = Indice_2;
                const T<R> A(Indice_1);
                const S B(Indice_2);
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

template< class U, template<const U R> class T , const U R , class S >
result_test test_operator_binario_hetero(unsigned int i)
{

    result_test result = {0,0};

    BINARIA_hetero<U,T,R,S>           Resolucion_Clase;
    BINARIA_hetero_T<U,T,R,S>         Resolucion_con_enteros;

	for(S Indice_1 = 0 ; Indice_1 < ((CTTI<U,T,R,S>::NDigs == 1)?(R):(R*R)) ; ++Indice_1)	{
            for(S Indice_2 = 0 ; Indice_2 < ((CTTI<U,T,R,S>::NDigs == 1)?(R):(R*R)) ; ++Indice_2)	{
                S a=Indice_1;
                const S b=Indice_2;
                T<R> A(Indice_1);
                const S B(Indice_2);
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

/* resumen HETERO_BINARY_OPERATORS_TEST_UNIT:

    SOBRECARGA DEL OPERADOR ()
	 CADA OPERACION SE SELECCIONA CON (i,_,_)
    LOS ARGUMENTOS SE PASAN EN  (_,X,Y)
	 X e Y NO TIENEN EL MISMO TIPO
	 Y TIENE TIPO [built-in]
	 X TIENE TIPO PROPIO (NUESTRO)
	 C(i,x,y) LO QUE HACE ES [x OP(i) y]
    ___________________________________________________________ 
	HETERO_BINARY (NON-CONST)   Y   HETERO_BINARY_T (NON_CONST)
	_________________________       ___________________________
	OPERADORES BINARIOS      		OPERADORES BINARIOS
	DE LA CLASE CONTRUIDA    		DE UN TIPO BUILT-IN
	POR NOSOTROS             		CON ARGUMENTOS QUE
	CON ARGUMENTOS QUE       		PUEDEN VARIAR.
	PUEDEN VARIAR.  
	____________________________________________________________
	LAS FUNCIONES TEST_OPERADOR_HETERO_BINARIO Y 
	TEST_OPERADOR_HETERO_BINARIO_CONST SOLO COMPARAN LOS
	RESULTADOS DE 
	t_built-in(C(i,X,Y))==C_[t_built-in](i,T(X),Y)
	DE ESTA FORMA RELLENAMOS ERRORES O CORRECTOS

****/


#endif //  HETERO_BINARY_OPERATORS_TEST_UNIT__HPP