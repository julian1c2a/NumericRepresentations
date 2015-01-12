#ifndef SPARDIGS_T_TEST_HPP
#define SPARDIGS_T_TEST_HPP



#include <iostream>
#include <numeric>
#include <limits>
#include "src/libNumericRepresentations_src/spardigs_t.hpp"
#include "operator_test.hpp"

void PRUEBA_OPERADORES_UNARIOS_SPARDIGS_T()
{
    result_test result;
    int I;
    std::string no_const[]={
						"OPERADOR ++ PREVIO",
                      "OPERADOR -- PREVIO",
                      "OPERADOR mC_Bm1",
                      "OPERADOR mC_B"
    };
    std::string si_const[]={
						"OPERADOR ! UNARIO",
						"OPERADOR - UNARIO",
						"OPERADOR -- POST",
						"OPERADOR ++ POST",
						"OPERADOR ES 0",
						"OPERADOR ES 1",
						"OPERADOR ES max",
						"OPERADOR ES submax",
						"OPERADOR ES -1",
						"OPERADOR ES min",
						"OPERADOR ES submin"
    };
    cout << "   TEST_OPERADOR_UNARIO<SPARDIGS_T,_>   "   <<  endl;
    for(I=0;I<4;++I) {
		cout << no_const[I]  << endl;
		result = test_operator_unario<uchint,spardigs_t,radixes[1],sllint>(I);
		cout << "Base\t" << usint(radixes[1]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result  = test_operator_unario<uchint,spardigs_t,radixes[2],sllint >(I);
		cout << "Base\t" << usint(radixes[2]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		
		result  = test_operator_unario<uchint,spardigs_t,radixes[3],sllint >(I);
		cout << "Base\t" << usint(radixes[3]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		/*
		result  = test_operator_unario<uchint,spardigs_t,radixes[4],sllint >(I);
		cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_unario<uchint,spardigs_t,radixes[4],sllint >(I);
		cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_unario<uchint,spardigs_t,radixes[5],sllint >(I);
		cout << "Base\t" << usint(radixes[5]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_unario<uchint,spardigs_t,radixes[6],sllint >(I);
		cout << "Base\t" << usint(radixes[6]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		*/
    }
    for(I=0;I<11;++I) {
		cout << si_const[I]  << endl;
		result = test_operator_unario_const<uchint,spardigs_t,radixes[1],sllint >(I);
		cout << "Base\t" << usint(radixes[1]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_unario_const<uchint,spardigs_t,radixes[2],sllint >(I);
		cout << "Base\t" << usint(radixes[2]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		
		result = test_operator_unario_const<uchint,spardigs_t,radixes[3],sllint >(I);
		cout << "Base\t" << usint(radixes[3]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		/*
		result = test_operator_unario_const<uchint,spardigs_t,radixes[4],sllint >(I);
		cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_unario_const<uchint,spardigs_t,radixes[4],sllint >(I);
		cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_unario_const<uchint,spardigs_t,radixes[5],sllint >(I);
		cout << "Base\t" << usint(radixes[5]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_unario_const<uchint,spardigs_t,radixes[6],sllint >(I);
		cout << "Base\t" << usint(radixes[6]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		*/
    }
}

void TEST_CONSTRUCTORES_Y_ASIGNACIONES_SPARDIGS_T()
{
	result_test result;
	
	result = test_constructores_desde_built_in<uchint,spardigs_t,radixes[1],sllint>();
	cout << "Base\t" << usint(radixes[1]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_constructores_desde_built_in<uchint,spardigs_t,radixes[2],sllint>();
	cout << "Base\t" << usint(radixes[2]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	
	result = test_constructores_desde_built_in<uchint,spardigs_t,radixes[3],sllint>();
	cout << "Base\t" << usint(radixes[3]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	/*
	result = test_constructores_desde_built_in<uchint,spardigs_t,radixes[3],sllint>();
	cout << "Base\t" << usint(radixes[3]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_constructores_desde_built_in<uchint,spardigs_t,radixes[4],sllint>();
	cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_constructores_desde_built_in<uchint,spardigs_t,radixes[5],sllint>();
	cout << "Base\t" << usint(radixes[5]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_constructores_desde_built_in<uchint,spardigs_t,radixes[6],sllint>();
	cout << "Base\t" << usint(radixes[6]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	*/
	result = test_constructor_por_defecto<uchint,spardigs_t,radixes[1],sllint >();
	cout << "Base\t" << usint(radixes[1]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_constructor_por_defecto<uchint,spardigs_t,radixes[2],sllint >();
	cout << "Base\t" << usint(radixes[2]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	
	result = test_constructor_por_defecto<uchint,spardigs_t,radixes[3],sllint >();
	cout << "Base\t" << usint(radixes[3]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	/*
	result = test_constructor_por_defecto<uchint,spardigs_t,radixes[4],sllint >();
	cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_constructor_por_defecto<uchint,spardigs_t,radixes[4],sllint >();
	cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_constructor_por_defecto<uchint,spardigs_t,radixes[5],sllint >();
	cout << "Base\t" << usint(radixes[5]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_constructor_por_defecto<uchint,spardigs_t,radixes[6],sllint >();
	cout << "Base\t" << usint(radixes[6]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	*/
	result = test_constructor_copia<uchint,spardigs_t,radixes[1],sllint >();
	cout << "Base\t" << usint(radixes[1]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_constructor_copia<uchint,spardigs_t,radixes[2],sllint >();
	cout << "Base\t" << usint(radixes[2]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	
	result = test_constructor_copia<uchint,spardigs_t,radixes[3],sllint >();
	cout << "Base\t" << usint(radixes[3]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	/*
	result = test_constructor_copia<uchint,spardigs_t,radixes[4],sllint >();
	cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_constructor_copia<uchint,spardigs_t,radixes[4],sllint >();
	cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_constructor_copia<uchint,spardigs_t,radixes[5],sllint >();
	cout << "Base\t" << usint(radixes[5]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_constructor_copia<uchint,spardigs_t,radixes[6],sllint >();
	cout << "Base\t" << usint(radixes[6]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	*/
	result = test_asignaciones_copia<uchint,spardigs_t,radixes[1],sllint >();
	cout << "Base\t" << usint(radixes[1]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_asignaciones_copia<uchint,spardigs_t,radixes[2],sllint >();
	cout << "Base\t" << usint(radixes[2]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	
	result = test_asignaciones_copia<uchint,spardigs_t,radixes[3],sllint >();
	cout << "Base\t" << usint(radixes[3]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	/*
	result = test_asignaciones_copia<uchint,spardigs_t,radixes[4],sllint >();
	cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_asignaciones_copia<uchint,spardigs_t,radixes[4],sllint >();
	cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_asignaciones_copia<uchint,spardigs_t,radixes[5],sllint >();
	cout << "Base\t" << usint(radixes[5]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_asignaciones_copia<uchint,spardigs_t,radixes[6],sllint >();
	cout << "Base\t" << usint(radixes[6]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	*/
	result = test_asignaciones_desde_built_in<uchint,spardigs_t,radixes[1],sllint>();
	cout << "Base\t" << usint(radixes[1]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_asignaciones_desde_built_in<uchint,spardigs_t,radixes[2],sllint>();
	cout << "Base\t" << usint(radixes[2]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	
	result = test_asignaciones_desde_built_in<uchint,spardigs_t,radixes[3],sllint>();
	cout << "Base\t" << usint(radixes[3]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	/*
	result = test_asignaciones_desde_built_in<uchint,spardigs_t,radixes[4],sllint>();
	cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_asignaciones_desde_built_in<uchint,spardigs_t,radixes[4],sllint>();
	cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_asignaciones_desde_built_in<uchint,spardigs_t,radixes[5],sllint>();
	cout << "Base\t" << usint(radixes[5]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	result = test_asignaciones_desde_built_in<uchint,spardigs_t,radixes[6],sllint>();
	cout << "Base\t" << usint(radixes[6]) << ";\t ERRORES    =    " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
	*/
}


void PRUEBA_OPERADORES_BINARIOS_SPARDIGS_T()
{
    result_test result;
    int I;
    std::string si_const[]={ 
						"OPERADOR +     ",
						"OPERADOR -     ",
						"OPERADOR *     ",
						"OPERADOR /     ",
						"OPERADOR %     ",
						"OPERADOR ==    ",
						"OPERADOR !=    ",
						"OPERADOR >=    ",
						"OPERADOR >     ",
						"OPERADOR <=    ",
						"OPERADOR <     "
    };
    std::string no_const[]={ 
						"OPERADOR +=",
						"OPERADOR -=",
						"OPERADOR *=",
						"OPERADOR /=",
						"OPERADOR %="
    };
    cout << "   TEST_OPERADOR_BINARIO<SPARDIGS_T,_>   "   <<  endl;
    for(I=0;I<5;++I) {
		cout << no_const[I]  << endl;
		result = test_operator_binario<uchint,spardigs_t,radixes[1],sllint >(I);
		cout << "Base\t" << usint(radixes[1]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_binario<uchint,spardigs_t,radixes[2],sllint >(I);
		cout << "Base\t" << usint(radixes[2]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		
		result = test_operator_binario<uchint,spardigs_t,radixes[3],sllint >(I);
		cout << "Base\t" << usint(radixes[3]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		/*
		result = test_operator_binario<uchint,spardigs_t,radixes[4],sllint >(I);
		cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_binario<uchint,spardigs_t,radixes[4],sllint >(I);
		cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_binario<uchint,spardigs_t,radixes[5],sllint >(I);
		cout << "Base\t" << usint(radixes[5]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_binario<uchint,spardigs_t,radixes[6],sllint >(I);
		cout << "Base\t" << usint(radixes[6]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		*/
    }

    for(I=0;I<11;++I)  {
		cout << si_const[I]  << endl;
		result = test_operator_binario_const<uchint,spardigs_t,radixes[1],sllint >(I);
		cout << "Base\t" << usint(radixes[1]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_binario_const<uchint,spardigs_t,radixes[2],sllint >(I);
		cout << "Base\t" << usint(radixes[2]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		
		result = test_operator_binario_const<uchint,spardigs_t,radixes[3],sllint >(I);
		cout << "Base\t" << usint(radixes[3]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		/*
		result = test_operator_binario_const<uchint,spardigs_t,radixes[4],sllint >(I);
		cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_binario_const<uchint,spardigs_t,radixes[4],sllint >(I);
		cout << "Base\t" << usint(radixes[4]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_binario_const<uchint,spardigs_t,radixes[5],sllint >(I);
		cout << "Base\t" << usint(radixes[5]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		result = test_operator_binario_const<uchint,spardigs_t,radixes[6],sllint >(I);
		cout << "Base\t" << usint(radixes[6]) << ";\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << endl;
		*/
    }

}

void PRUEBA_SPARDIGS_T()
{
    PRUEBA_OPERADORES_UNARIOS_SPARDIGS_T();
    PRUEBA_OPERADORES_BINARIOS_SPARDIGS_T();
    //PRUEBA_OPERADORES_BINARIOS_HETERO_SPARDIGS_T();
    TEST_CONSTRUCTORES_Y_ASIGNACIONES_SPARDIGS_T();
}


/* resumen TESTERS:






   */


#endif  // SPARDIGS_T_TEST_HPP