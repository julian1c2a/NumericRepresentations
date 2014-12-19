#ifndef PARDIGS_T_TEST_HPP
#define PARDIGS_T_TEST_HPP



#include <iostream>
#include <numeric>
#include <limits>
#include "D:\Dropbox\NumericRepresentations\NumericRepresentations\src\libNumericRepresentations_src\pardigs_t.hpp"
#include "operator_test.hpp"

void PRUEBA_OPERADORES_UNARIOS_PARDIGS_T()
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
							"OPERADOR !",
							"OPERADOR ++ POST",
							"OPERADOR -- POST",
							"OPERADOR - UNARIO",
							"OPERADOR ES 0",
							"OPERADOR ES 1",
							"OPERADOR ES max",
							"OPERADOR ES submax"
    };
    std::cout << "   TEST_OPERADOR_UNARIO<PARDIGS_T,_>   "   <<  std::endl;
    for(I=0;I<4;++I) {
		std::cout << no_const[I]  << std::endl;
		result = test_operator_unario<uchint,pardigs_t,Bin1,sllint >(I);
		std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result  = test_operator_unario<uchint,pardigs_t,Dec,sllint >(I);
		std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result  = test_operator_unario<uchint,pardigs_t,B3x5,sllint >(I);
		std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result  = test_operator_unario<uchint,pardigs_t,B3x5,sllint >(I);
		std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_unario<uchint,pardigs_t,Bin7,sllint >(I);
//		std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_unario<uchint,pardigs_t,S210,sllint >(I);
//		std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_unario<uchint,pardigs_t,M255,sllint >(I);
//		std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }
    for(I=0;I<8;++I) {
		std::cout << si_const[I]  << std::endl;
		result = test_operator_unario_const<uchint,pardigs_t,Bin1,sllint >(I);
		std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_unario_const<uchint,pardigs_t,Dec,sllint >(I);
		std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_unario_const<uchint,pardigs_t,B3x5,sllint >(I);
		std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_unario_const<uchint,pardigs_t,B3x5,sllint >(I);
		std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//        result = test_operator_unario_const<uchint,pardigs_t,Bin7,sllint >(I);
//        std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//        result = test_operator_unario_const<uchint,pardigs_t,S210,sllint >(I);
//        std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//        result = test_operator_unario_const<uchint,pardigs_t,M255,sllint >(I);
//        std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }
}

void PRUEBA_OPERADORES_BINARIOS_PARDIGS_T()
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
    std::cout << "   TEST_OPERADOR_BINARIO<PARDIGS_T,_>   "   <<  std::endl;
    for(I=0;I<5;++I) {
		std::cout << no_const[I]  << std::endl;
		result = test_operator_binario<uchint,pardigs_t,Bin1,sllint >(I);
		std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario<uchint,pardigs_t,Dec,sllint >(I);
		std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario<uchint,pardigs_t,B3x5,sllint >(I);
		std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario<uchint,pardigs_t,B3x5,sllint >(I);
		std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_binario<uchint,pardigs_t,Bin7,sllint >(I);
//		std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_binario<uchint,pardigs_t,S210,sllint >(I);
//		std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_binario<uchint,pardigs_t,M255,sllint >(I);
//		std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }

    for(I=0;I<11;++I)  {
		std::cout << si_const[I]  << std::endl;
		result = test_operator_binario_const<uchint,pardigs_t,Bin1,sllint >(I);
		std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_const<uchint,pardigs_t,Dec,sllint >(I);
		std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_const<uchint,pardigs_t,B3x5,sllint >(I);
		std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_const<uchint,pardigs_t,B3x5,sllint >(I);
		std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_binario_const<uchint,pardigs_t,Bin7,sllint >(I);
//		std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_binario_const<uchint,pardigs_t,S210,sllint >(I);
//		std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_binario_const<uchint,pardigs_t,M255,sllint >(I);
//		std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }

}

void PRUEBA_OPERADORES_BINARIOS_HETERO_PARDIGS_T()
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
    std::cout << "   TEST_OPERADOR_BINARIO_HETERO<DIG_T,_>   "   <<  std::endl;
    for(I=0;I<5;++I) {
        std::cout << no_const[I]  << std::endl;
        
		result = test_operator_binario_hetero<uchint,pardigs_t,Bin1,sllint >(I);
		std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero<uchint,pardigs_t,Dec,sllint >(I);
		std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero<uchint,pardigs_t,B3x5,sllint >(I);
		std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero<uchint,pardigs_t,Bin4x3,sllint >(I);
		std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_binario_hetero<uchint,pardigs_t,Bin7,sllint >(I);
//		std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_binario_hetero<uchint,pardigs_t,S210,sllint >(I);
//		std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_binario_hetero<uchint,pardigs_t,M255,sllint >(I);
//		std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }

    for(I=0;I<11;++I)  {
        std::cout << si_const[I]  << std::endl;
        
		result = test_operator_binario_hetero_const<uchint,pardigs_t,Bin1,sllint >(I);
		std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero_const<uchint,pardigs_t,Dec,sllint >(I);
		std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero_const<uchint,pardigs_t,B3x5,sllint >(I);
		std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero_const<uchint,pardigs_t,Bin4x3,sllint >(I);
		std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_binario_hetero_const<uchint,pardigs_t,Bin7,sllint >(I);
//		std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_binario_hetero_const<uchint,pardigs_t,S210,sllint >(I);
//		std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_operator_binario_hetero_const<uchint,pardigs_t,M255,sllint >(I);
//		std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }

}

void TEST_CONSTRUCTORES_Y_ASIGNACIONES_PARDIGS_T()
{
    result_test result;

    std::cout << "TEST DE CONSTRUCTORES DESDE TIPOS BUILT-IN DE C++" << std::endl;
	result = test_constructores_desde_built_in<uchint,pardigs_t,Bin1,sllint>();
    std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructores_desde_built_in<uchint,pardigs_t,Dec,sllint>();
    std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructores_desde_built_in<uchint,pardigs_t,B3x5,sllint>();
    std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructores_desde_built_in<uchint,pardigs_t,Bin4x3,sllint>();
    std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//	result = test_constructores_desde_built_in<uchint,pardigs_t,Bin7,sllint>();
//	std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//	result = test_constructores_desde_built_in<uchint,pardigs_t,S210,sllint>();
//	std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//	result = test_constructores_desde_built_in<uchint,pardigs_t,M255,sllint>();
//	std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;

    std::cout << "TEST DEL CONSTRUCTOR POR DEFECTO" << std::endl;
	result = test_constructor_por_defecto<uchint,pardigs_t,Bin1,sllint >();
    std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_por_defecto<uchint,pardigs_t,Dec,sllint >();
    std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructor_por_defecto<uchint,pardigs_t,B3x5,sllint >();
    std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_por_defecto<uchint,pardigs_t,Bin4x3,sllint >();
    std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//	result = test_constructor_por_defecto<uchint,pardigs_t,Bin7,sllint >();
//	std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//	result = test_constructor_por_defecto<uchint,pardigs_t,S210,sllint >();
//	std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//	result = test_constructor_por_defecto<uchint,pardigs_t,M255,sllint >();
//	std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;

    std::cout << "TEST DEL CONSTRUCTOR COPIA" << std::endl;
	result = test_constructor_copia<uchint,pardigs_t,Bin1,sllint >();
    std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_copia<uchint,pardigs_t,Dec,sllint >();
    std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructor_copia<uchint,pardigs_t,B3x5,sllint >();
    std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_copia<uchint,pardigs_t,Bin4x3,sllint >();
    std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//	result = test_constructor_copia<uchint,pardigs_t,Bin7,sllint >();
//	std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//	result = test_constructor_copia<uchint,pardigs_t,S210,sllint >();
//	std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//	result = test_constructor_copia<uchint,pardigs_t,M255,sllint >();
//	std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;

    std::cout << "TEST DEL OPERADOR DE ASIGNACION TIPO COPIA" << std::endl;
	result = test_asignaciones_copia<uchint,pardigs_t,Bin1,sllint >();
    std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_copia<uchint,pardigs_t,Dec,sllint >();
    std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_asignaciones_copia<uchint,pardigs_t,B3x5,sllint >();
    std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_asignaciones_copia<uchint,pardigs_t,Bin4x3,sllint >();
//		std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_asignaciones_copia<uchint,pardigs_t,Bin7,sllint >();
//		std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_asignaciones_copia<uchint,pardigs_t,S210,sllint >();
//		std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_asignaciones_copia<uchint,pardigs_t,M255,sllint >();
//		std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;

    std::cout << "TEST DEL OPERADOR DE ASIGNACION DES UN TIPO BUILT-IN" << std::endl;
	result = test_asignaciones_desde_built_in<uchint,pardigs_t,Bin1,sllint>();
    std::cout << "Base\t" << usint(Bin1) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_desde_built_in<uchint,pardigs_t,Dec,sllint>();
    std::cout << "Base\t" << usint(Dec) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_asignaciones_desde_built_in<uchint,pardigs_t,B3x5,sllint>();
    std::cout << "Base\t" << usint(B3x5) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_desde_built_in<uchint,pardigs_t,Bin4x3,sllint>();
    std::cout << "Base\t" << usint(Bin4x3) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_asignaciones_desde_built_in<uchint,pardigs_t,Bin7,sllint>();
//		std::cout << "Base\t" << usint(Bin7) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_asignaciones_desde_built_in<uchint,pardigs_t,S210,sllint>();
//		std::cout << "Base\t" << usint(S210) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
//		result = test_asignaciones_desde_built_in<uchint,pardigs_t,M255,sllint>();
//		std::cout << "Base\t" << usint(M255) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
}

void PRUEBA_PARDIGS_T()
{
    PRUEBA_OPERADORES_UNARIOS_PARDIGS_T();
    PRUEBA_OPERADORES_BINARIOS_PARDIGS_T();
    PRUEBA_OPERADORES_BINARIOS_HETERO_PARDIGS_T();
    TEST_CONSTRUCTORES_Y_ASIGNACIONES_PARDIGS_T();
}

/* resumen TESTERS:






   */


#endif  // PARDIGS_T_TEST_HPP