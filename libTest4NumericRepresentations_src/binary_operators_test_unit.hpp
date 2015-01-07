#ifndef BINARY_OPERATORS_TEST_UNIT__HPP
#define BINARY_OPERATORS_TEST_UNIT__HPP

#include "basic_constants_and_lists_4_test_unit.hpp"

template<class U,template<const U R> class T,const U R,class S >
result_test test_operator_binario_const(unsigned int i)
{

	result_test result = {0,0};

	ARITH_BIN_EQ_const<U,T,R,S>          Resolucion_Clase;
    ARITH_BIN_EQ_T_const<U,T,R,S>   Resolucion_con_enteros;

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

    ARITH_BIN_EQ_const<U,T,R,S>        Resolucion_Clase;
    ARITH_BIN_EQ_T_const<U,T,R,S>      Resolucion_con_enteros;

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