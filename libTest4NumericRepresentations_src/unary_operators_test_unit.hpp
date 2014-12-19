#ifndef UNARY_OPERATORS_TEST_UNIT__HPP
#define UNARY_OPERATORS_TEST_UNIT__HPP

#include "constants_test_unit.hpp"

template<class U,template<const U R> class T,const U R, class S>
class UNARIA_const
{
public:
    T<R>  operator()(int i,T<R> arg){
        switch(i){
            case 0 :                      	return (arg++);
            case 1 :                      	return (arg--);
            case 2 :                      	return (!arg);
            case 3 :                      	return (-arg);
            case 4 : if (arg.is_0())      	return T<R>(S(1));
                     else                 	return T<R>(S(0));
            case 5 : if (arg.is_1())      	return T<R>(S(1));
                     else                 	return T<R>(S(0));
            case 6 : if (arg.is_max())    	return T<R>(S(1));
                     else                 	return T<R>(S(0));
            case 7 : if (arg.is_submax()) 	return T<R>(S(1));
                     else                 	return T<R>(S(0));
            case 8 : if (arg.is_m1())		return T<R>(S(1));
                     else                 	return T<R>(S(0));
            case 9 : if (arg.is_min())		return T<R>(S(1));
                     else                 	return T<R>(S(0));
            case 10 :	
            default :	if (arg.is_submin())	return T<R>(S(1));
						else                	return T<R>(S(0));
        }
    }
};

template<class U,template<const U R> class T,const U R, class S>
class UNARIA_T_const
{
public:
       S operator()(int i,const S & arg){
           switch(i){
              case 0 :	{	
								if (T<R>::with_sign) {
									const bool negative = (arg<0);
									S carg((negative)?(-arg):(arg));
									(negative)?(--carg):(++carg);
									if (!negative) carg*=(-1);
									return carg;
								}
								else {
									const S ret = (Limit<U,T,R,S>::MaxPowRadix)-1-arg;
									return ret;
								}
							}
							break;
              case 1 :	{
								if(T<R>::with_sign) {
									S carg(arg);
									if(arg==Limit<U,T,R,S>::BeginIndex){
										carg=Limit<U,T,R,S>::BeginIndex;
									}
									else{
										carg*=-1;
									}
									return carg;
								}
								else {
									if (arg != 0)
										return (Limit<U,T,R,S>::MaxPowRadix)-arg;
									else
										return arg; 
								}
							}
							break;
				case 2 :	{	
								S carg(arg);
								return (carg--);
							}
							break;
				case 3 :	{	
								S carg(arg);
								return (carg++);
							}
							break;
				case 4 : 
							{
								if (arg==0)		return 1;
								else			return 0;
							}
							break;
				case 5 :
							{ 
								if (arg==1) 	return 1;
								else			return 0;
							}
							break;
				case 6 :
							{ 
								if (arg==Limit<U,T,R,S>::EndIndex)	return 1;
								else										return 0;
							}
							break;
				case 7 :
							{ 
								if (arg==Limit<U,T,R,S>::EndIndex-1)	return 1;
								else										return 0;
							}
							break;
				case 8 :
							{ 
								if (arg==-1)		return 1;
								else				return 0;
							}
							break;
				case 9 :
							{ 
								if (arg==Limit<U,T,R,S>::BeginIndex)	return 1;
								else										return 0;
							}
							break;
				case 10 :
				default :
							{ 
								if (arg==Limit<U,T,R,S>::BeginIndex+1)	return 1;
								else										return 0;
							}
							break;
              }
       }

};

template<class U,template<const U R> class T,const U R, class S>
class UNARIA
{
public:
    void operator()(int i,T<R>& arg){
        switch(i){
            case 0 : (++arg);       break;
            case 1 : (--arg);       break;
            case 2 : (arg.mC_Bm1());break;
            case 3 : (arg.mC_B());  break;
        }
    }
};

template<class U,template<const U R> class T,const U R, class S>
class UNARIA_T
{
public:
       void operator()(int i,S & arg){
           switch(i){
              case 0 :     {if (arg >= Limit<U,T,R,S>::EndIndex) {
									arg = Limit<U,T,R,S>::BeginIndex;
							  }
							  else {
								  arg += 1 ;
								  arg %=Limit<U,T,R,S>::MaxPowRadix;
								}}
                          break;
              case 1 :    {if (arg > Limit<U,T,R,S>::BeginIndex) {
                             arg -= 1;
                          }
                          else {
                             arg = Limit<U,T,R,S>::EndIndex;
								}}
                          break;
              case 2 :    {	
								if(T<R>::with_sign) {
									const bool negative = (arg<0); 
									arg = ((negative)?(-arg):(arg));
									if(negative){--arg;}
									else {++arg;}
									if (!negative) arg*=(-1);
								}
								else {
									arg = (Limit<U,T,R,S>::MaxPowRadix)-1-arg;
								}
							 }
								break;
				case 3 :    
							{
								if(T<R>::with_sign) {
									if(arg==Limit<U,T,R,S>::BeginIndex)
											{arg=Limit<U,T,R,S>::BeginIndex;}
									else	{arg*=-1;}
								}
								else {
									if (arg != 0) {
										arg = (Limit<U,T,R,S>::MaxPowRadix)-arg;
									}
								}
							 }
                          break;
              }
       }
};

template<class U,template<const U R> class T,const U R, class S>
result_test test_operator_unario_const(unsigned int i)
{

	result_test result={0,0};

	UNARIA_const<U,T,R,S> Resolucion_Clase;
	UNARIA_T_const<U,T,R,S> Resolucion_con_enteros;

	for(S Indice = Limit<U,T,R,S>::BeginIndex ; Indice <= Limit<U,T,R,S>::EndIndex ; ++Indice)	{
       S a = Indice;
       T<R> A(Indice);
		const T<R> C(Resolucion_Clase(i,A));
		const S c = Resolucion_con_enteros(i,a);
		const S iC = S(C);
		if (iC==c) {
			++result.correctos;
		}
		else {
			++result.erroneos;
		}
	}
	return result;
}

template<class U,template<const U R> class T,const U R, class S>
result_test test_operator_unario(unsigned int i)
{

    result_test result={0,0};

    UNARIA<U,T,R,S> Resolucion_Clase;
    UNARIA_T<U,T,R,S> Resolucion_con_enteros;

	for(S Indice = Limit<U,T,R,S>::BeginIndex ; Indice <= Limit<U,T,R,S>::EndIndex ; ++Indice)	{
       S a=Indice;
       T<R> A(Indice);
		Resolucion_Clase(i,A);
		Resolucion_con_enteros(i,a);
		//sllint iA = sllint(A);
		if (S(A)==a) {
			++result.correctos;
		}
		else {
			++result.erroneos;
		}
	}

	return result;
}

/* resumen UNARY_OPERATOR_TEST_ UNIT:

    SOBRECARGA DEL OPERADOR ()
	 CADA OPERACION SE SELECCIONA CON (i,_)
    LOS ARGUMENTOS SE PASAN EN  (_,X)
	 X TIENE TIPO PROPIO (NUESTRO) EN CLASE SIN T
	 X TIENE TIPO built-in EN CLASE CON T
	 C(i,x) LO QUE HACE ES [OP(i) x]
    ___________________________________________________________ 
	UNARY (NON-CONST)           Y   UNARY_T (NON-CONST)
	_________________________       ___________________________
	OPERADORES UNARIOS      		OPERADORES UNARIOS
	DE LA CLASE CONTRUIDA    		DE UN TIPO BUILT-IN
	POR NOSOTROS             		CON ARGUMENTOS QUE
	CON ARGUMENTOS QUE       		PUEDEN VARIAR.
	PUEDEN VARIAR.  
	____________________________________________________________
	LAS FUNCIONES TEST_OPERADOR_UNARIO Y 
	SOLO COMPARAN LOS RESULTADOS DE 
	t_built-in(C(i,X))==C_[t_built-in](i,T(X))
	DE ESTA FORMA RELLENAMOS ERRORES O CORRECTOS

*****/

/* resumen UNARY_OPERATOR_CONST_TEST_ UNIT:

    SOBRECARGA DEL OPERADOR ()
	 CADA OPERACION SE SELECCIONA CON (i,_)
    LOS ARGUMENTOS SE PASAN EN  (_,X)
	 X TIENE TIPO PROPIO (NUESTRO) EN CLASE SIN T
	 X TIENE TIPO built-in EN CLASE CON T
	 C(i,x) LO QUE HACE ES [OP(i) x]
    ___________________________________________________________ 
	UNARY CONST               Y     UNARY_T CONST
	_________________________       ___________________________
	OPERADORES UNARIOS      		    OPERADORES UNARIOS
	DE LA CLASE CONTRUIDA    		 DE UN TIPO BUILT-IN
	POR NOSOTROS             		 CON ARGUMENTOS QUE
	CON ARGUMENTOS QUE       		 NO PUEDEN VARIAR.
	NO PUEDEN VARIAR, Y NO VARÍA    Y NO VARÍAN LAS VARIABLES
    EL OBJETO DE CLASE  				 DEL TIPO [built-in]
	____________________________________________________________
	LAS FUNCIONES TEST_OPERADOR_CONST_UNARIO Y 
	SOLO COMPARAN LOS RESULTADOS DE 
	t_built-in(C(i,X))==C_[t_built-in](i,T(X))
	DE ESTA FORMA RELLENAMOS ERRORES O CORRECTOS

*****/


#endif //  UNARY_OPERATORS_TEST_UNIT__HPP