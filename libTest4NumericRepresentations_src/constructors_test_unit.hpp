#ifndef CONSTRUCTORS_TEST_UNIT__HPP
#define CONSTRUCTORS_TEST_UNIT__HPP

#include "src/libTest4NumericRepresentations_src/basic_constants_and_lists_4_test_unit.hpp"

template<class U , template<const U R> class T, const U R, class S>
result_test test_constructores_desde_built_in()
{
    result_test result = {0,0};
	 
    for(S Index = (CTTI<U,T,R,S>::BeginIndex) ; Index <= (CTTI<U,T,R,S>::EndIndex) ; ++Index) {
       T<R> VLR(Index);
		if (Index == (CTTI<U,T,R,S>::BeginIndex)) {
			if (CTTI<U,T,R,S>::with_sign) {
				if ((VLR.is_negative())&&(VLR.abs().is_0()))
					++result.correctos;
				else 
					++result.erroneos;
			}
			else {
				if ((VLR.is_positive())&&(VLR.abs().is_0()))
					++result.correctos;
				else
					++result.erroneos;
			}
		}
		else if ((Index > (CTTI<U,T,R,S>::BeginIndex))&&(Index <= (CTTI<U,T,R,S>::EndIndex))) {
			if (S(VLR)==Index) ++result.correctos;
			else ++result.erroneos;
		}
		else {
			const S temp = Index%(CTTI<U,T,R,S>::MaxPowRadix);
			if (S(VLR)==temp) ++result.correctos;
			else ++result.erroneos;
       }
    }

    return result;
}

template<class U , template<const U R> class T, const U R , class S>
result_test test_constructor_copia()
{
    result_test result = {0,0};

    for(S Index = CTTI<U,T,R,S>::BeginIndex ; Index <= CTTI<U,T,R,S>::EndIndex ; ++Index) {        
		T<R> A(Index);
		T<R> VAR(A);
		if (VAR==A) ++result.correctos;
		else ++result.erroneos;
    }
    return result;
}

template<class U , template<const U R> class T, const U R , class S>
result_test test_constructor_por_defecto()
{
		result_test result = {0,0};

		T<R> VAR;
		if (S(VAR)==S(T<R>()())) ++result.correctos;
		else ++result.erroneos;
		
		return result;
}

template<class U , template<const U R> class T, const U R, class S>
result_test test_asignaciones_desde_built_in()
{
		result_test result = {0,0};
		T<R> VAR;
		for(S Index = CTTI<U,T,R,S>::BeginIndex ; Index <= CTTI<U,T,R,S>::EndIndex ; ++Index) {
			VAR = Index;
			if (Index == CTTI<U,T,R,S>::BeginIndex) {
				if (CTTI<U,T,R,S>::with_sign) {
					if ((VAR.abs().is_0())&&(VAR.is_negative()))
						++result.correctos;
					else 
						++result.erroneos;
				}
				else {
					if ((VAR.abs().is_0())&&(VAR.is_positive()))
						++result.correctos;
					else 
						++result.erroneos;					
				}
			}
			else if ((Index > CTTI<U,T,R,S>::BeginIndex)&&(Index <= CTTI<U,T,R,S>::EndIndex)) {
				//const S temp = (((Index<0)?(-(UnidadAlta+Index)):(Index))%UnidadAlta);
				if (S(VAR)==Index) 
					++result.correctos;
				else 
					++result.erroneos;
			}
		}

    return result;
}

template<class U , template<const U R> class T, const U R, class S>
result_test test_asignaciones_copia()
{
	result_test result = {0,0};
    T<R> VAR;
    for(S Index = CTTI<U,T,R,S>::BeginIndex ; Index <= CTTI<U,T,R,S>::EndIndex ; ++Index) {
        T<R> A(Index);
        VAR = A;
        if (VAR==A) ++result.correctos;
        else ++result.erroneos;
    }

    return result;
}

/* resumen constructor test :

	SE TESTEAN TANTO LOS CONSTRUCTORES (COPIA,
	POR DEFECTO, PASÁNDOLE ARGUMENTOS,...) COMO
	OPERADORES DE ASIGNACIÓN (COPIA, PASÁNDOLE 
	ALGÚN ALRGUMENTO).

   SE PODRÍA TESTEAR LAS SOBRECARGAS DE LOS CASTS

   */

#endif //  CONSTRUCTORS_TEST_UNIT__HPP