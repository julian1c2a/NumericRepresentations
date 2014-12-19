#ifndef SDIG_T_TEST_HPP
#define SDIG_T_TEST_HPP


#include <iostream>
#include <numeric>
#include <limits>
#include "D:\Dropbox\NumericRepresentations\NumericRepresentations\src\libNumericRepresentations_src\sdig_t.hpp"
#include "operator_test.hpp"

void PRUEBA_OPERADORES_UNARIOS_SDIG_T()
{
    result_test result = {0,0};
    int I;
    std::string no_const[]={
						"OPERADOR ++() PREFIJO",
						"OPERADOR --() PREFIJO",
						"OPERADOR mC_Bm1()",
						"OPERADOR mC_B()"
    };
    std::string si_const[]={ 
						"OPERADOR ++(int) POSTFIJO",
						"OPERADOR --(int) POSTFIJO",
						"OPERADOR !()",
						"OPERADOR -() UNARIO",
						"OPERADOR es_0",
						"OPERADOR es_1",
						"OPERADOR es_max",
						"OPERADOR es_submax"
    };
    std::cout << "   TEST_OPERADOR_UNARIO<SDIG_T,_>   "   <<  std::endl;
    for(I=0;I<4;++I) {
        std::cout << no_const[I]  << std::endl;
        result = test_operator_unario<uchint,sdig_t,Bin1,sllint>(I);
        std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result  = test_operator_unario<uchint,sdig_t,Dec,sllint>(I);
        std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result  = test_operator_unario<uchint,sdig_t,B3x5,sllint >(I);
        std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result  = test_operator_unario<uchint,sdig_t,Bin4x3,sllint >(I);
        std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_unario<uchint,sdig_t,Bin7,sllint >(I);
        std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_unario<uchint,sdig_t,S210,sllint >(I);
        std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_unario<uchint,sdig_t,M255,sllint >(I);
        std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }
    for(I=0;I<8;++I) {
        std::cout << si_const[I]  << std::endl;
        result = test_operator_unario_const<uchint,sdig_t,Bin1,sllint>(I);
        std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_unario_const<uchint,sdig_t,Dec,sllint>(I);
        std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_unario_const<uchint,sdig_t,B3x5,sllint >(I);
        std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_unario_const<uchint,sdig_t,Bin4x3,sllint >(I);
        std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_unario_const<uchint,sdig_t,S210,sllint >(I);
        std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_unario_const<uchint,sdig_t,M255,sllint >(I);
        std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }
}

void PRUEBA_OPERADORES_BINARIOS_SDIG_T()
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
    std::cout << "   TEST_OPERADOR_BINARIO<SDIG_T,_>   "   <<  std::endl;
    for(I=0;I<5;++I) {
        std::cout << no_const[I]  << std::endl;
        
        result = test_operator_binario<uchint,sdig_t,Bin1,sllint>(I);
        std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario<uchint,sdig_t,Dec,sllint>(I);
        std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario<uchint,sdig_t,B3x5,sllint >(I);
        std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario<uchint,sdig_t,Bin4x3,sllint >(I);
        std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario<uchint,sdig_t,Bin7,sllint >(I);
        std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario<uchint,sdig_t,S210,sllint >(I);
        std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario<uchint,sdig_t,M255,sllint >(I);
        std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }

    for(I=0;I<11;++I)  {
        std::cout << si_const[I]  << std::endl;
        
        result = test_operator_binario_const<uchint,sdig_t,Bin1,sllint>(I);
        std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_const<uchint,sdig_t,Dec,sllint>(I);
        std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_const<uchint,sdig_t,B3x5,sllint >(I);
        std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_const<uchint,sdig_t,Bin4x3,sllint >(I);
        std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_const<uchint,sdig_t,Bin7,sllint >(I);
        std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_const<uchint,sdig_t,S210,sllint >(I);
        std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_const<uchint,sdig_t,M255,sllint >(I);
        std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }

}

void PRUEBA_OPERADORES_BINARIOS_HETERO_SDIG_T()
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
    std::cout << "   TEST_OPERADOR_BINARIO_HETERO<SDIG_T,_>   "   <<  std::endl;
    for(I=0;I<5;++I) {
        std::cout << no_const[I]  << std::endl;
        
        result = test_operator_binario_hetero<uchint,sdig_t,Bin1,sllint >(I);
        std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_hetero<uchint,sdig_t,Dec,sllint >(I);
        std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero<uchint,sdig_t,B3x5,sllint >(I);
        std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_hetero<uchint,sdig_t,Bin4x3,sllint >(I);
        std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_hetero<uchint,sdig_t,Bin7,sllint >(I);
        std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero<uchint,sdig_t,S210,sllint >(I);
        std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero<uchint,sdig_t,M255,sllint >(I);
        std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }

    for(I=0;I<11;++I)  {
        std::cout << si_const[I]  << std::endl;
        
        result = test_operator_binario_hetero_const<uchint,sdig_t,Bin1,sllint >(I);
        std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_hetero_const<uchint,sdig_t,Dec,sllint >(I);
        std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero_const<uchint,sdig_t,B3x5,sllint >(I);
        std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_hetero_const<uchint,sdig_t,Bin4x3,sllint >(I);
        std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_hetero_const<uchint,sdig_t,Bin7,sllint >(I);
        std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero_const<uchint,sdig_t,S210,sllint >(I);
        std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero_const<uchint,sdig_t,M255,sllint >(I);
        std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }

}

void TEST_CONSTRUCTORES_Y_ASIGNACIONES_SDIG_T()
{
    result_test result;
	
	std::cout << "PRUEBAS PARA LOS CONSTRUCTORES DESDE UN TIPO BUILT-IN" << std::endl;
    result = test_constructores_desde_built_in<uchint,sdig_t,Bin1,sllint>();
    std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructores_desde_built_in<uchint,sdig_t,Dec,sllint>();
    std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructores_desde_built_in<uchint,sdig_t,B3x5,sllint>();
    std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructores_desde_built_in<uchint,sdig_t,Bin4x3,sllint>();
    std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructores_desde_built_in<uchint,sdig_t,Bin7,sllint>();
    std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructores_desde_built_in<uchint,sdig_t,S210,sllint>();
    std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructores_desde_built_in<uchint,sdig_t,M255,sllint>();
    std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;

    std::cout << "PRUEBAS PARA EL CONSTRUCTOR POR DEFECTO" << std::endl;
	result = test_constructor_por_defecto<uchint,sdig_t,Bin1,sllint>();
    std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_por_defecto<uchint,sdig_t,Dec,sllint>();
    std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructor_por_defecto<uchint,sdig_t,B3x5,sllint>();
    std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_por_defecto<uchint,sdig_t,Bin4x3,sllint>();
    std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_por_defecto<uchint,sdig_t,Bin7,sllint>();
    std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructor_por_defecto<uchint,sdig_t,S210,sllint>();
    std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_por_defecto<uchint,sdig_t,M255,sllint>();
    std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;

    std::cout << "PRUEBAS PARA EL CONSTRUCTOR COPIA" << std::endl;
	result = test_constructor_copia<uchint,sdig_t,Bin1,sllint>();
    std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_copia<uchint,sdig_t,Dec,sllint>();
    std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructor_copia<uchint,sdig_t,B3x5,sllint>();
    std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_copia<uchint,sdig_t,Bin4x3,sllint>();
    std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_copia<uchint,sdig_t,Bin7,sllint>();
    std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructor_copia<uchint,sdig_t,S210,sllint>();
    std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_copia<uchint,sdig_t,M255,sllint>();
    std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;

    std::cout << "PRUEBAS PARA EL OPERADOR DE ASIGNACION COPIA" << std::endl;
	result = test_asignaciones_copia<uchint,sdig_t,Bin1,sllint >();
    std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_copia<uchint,sdig_t,Dec,sllint >();
    std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_asignaciones_copia<uchint,sdig_t,B3x5,sllint >();
    std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_copia<uchint,sdig_t,Bin4x3,sllint >();
    std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_copia<uchint,sdig_t,Bin7,sllint >();
    std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_asignaciones_copia<uchint,sdig_t,S210,sllint >();
    std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_copia<uchint,sdig_t,M255,sllint >();
    std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;

    std::cout << "PRUEBAS PARA EL OPERADOR DE ASIGNACION DESDE BUILT-IN" << std::endl;
	result = test_asignaciones_desde_built_in<uchint,sdig_t,Bin1,sllint>();
    std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_desde_built_in<uchint,sdig_t,Dec,sllint>();
    std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_asignaciones_desde_built_in<uchint,sdig_t,B3x5,sllint>();
    std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_desde_built_in<uchint,sdig_t,Bin4x3,sllint>();
    std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_asignaciones_desde_built_in<uchint,sdig_t,Bin7,sllint>();
    std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_desde_built_in<uchint,sdig_t,S210,sllint>();
	std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_desde_built_in<uchint,sdig_t,M255,sllint>();
    std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
}



void PRUEBA_SDIG_T()
{
    PRUEBA_OPERADORES_UNARIOS_SDIG_T();
    PRUEBA_OPERADORES_BINARIOS_SDIG_T();
    PRUEBA_OPERADORES_BINARIOS_HETERO_SDIG_T();
    TEST_CONSTRUCTORES_Y_ASIGNACIONES_SDIG_T();
}


/* resumen TESTERS:






   */

#endif  // SDIG_T_TEST_HPP