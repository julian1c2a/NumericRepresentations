#ifndef SDIG_T_TEST_HPP
#define SDIG_T_TEST_HPP


#include <iostream>
#include <numeric>
#include <limits>
#include "src/libNumericRepresentations_src/sdig_t.hpp"
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
        result = test_operator_unario<uchint,sdig_t,radixes[1],sllint>(I);
        std::cout << "Base\t" << usint(radixes[1]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result  = test_operator_unario<uchint,sdig_t,radixes[2],sllint>(I);
        std::cout << "Base\t" << usint(radixes[2]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result  = test_operator_unario<uchint,sdig_t,radixes[3],sllint >(I);
        std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result  = test_operator_unario<uchint,sdig_t,radixes[3],sllint >(I);
        std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_unario<uchint,sdig_t,radixes[4],sllint >(I);
        std::cout << "Base\t" << usint(radixes[4]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_unario<uchint,sdig_t,radixes[5],sllint >(I);
        std::cout << "Base\t" << usint(radixes[5]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_unario<uchint,sdig_t,radixes[6],sllint >(I);
        std::cout << "Base\t" << usint(radixes[6]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }
    for(I=0;I<8;++I) {
        std::cout << si_const[I]  << std::endl;
        result = test_operator_unario_const<uchint,sdig_t,radixes[1],sllint>(I);
        std::cout << "Base\t" << usint(radixes[1]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_unario_const<uchint,sdig_t,radixes[2],sllint>(I);
        std::cout << "Base\t" << usint(radixes[2]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_unario_const<uchint,sdig_t,radixes[3],sllint >(I);
        std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_unario_const<uchint,sdig_t,radixes[3],sllint >(I);
        std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_unario_const<uchint,sdig_t,radixes[5],sllint >(I);
        std::cout << "Base\t" << usint(radixes[5]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_unario_const<uchint,sdig_t,radixes[6],sllint >(I);
        std::cout << "Base\t" << usint(radixes[6]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
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
        
        result = test_operator_binario<uchint,sdig_t,radixes[1],sllint>(I);
        std::cout << "Base\t" << usint(radixes[1]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario<uchint,sdig_t,radixes[2],sllint>(I);
        std::cout << "Base\t" << usint(radixes[2]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario<uchint,sdig_t,radixes[3],sllint >(I);
        std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario<uchint,sdig_t,radixes[3],sllint >(I);
        std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario<uchint,sdig_t,radixes[4],sllint >(I);
        std::cout << "Base\t" << usint(radixes[4]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario<uchint,sdig_t,radixes[5],sllint >(I);
        std::cout << "Base\t" << usint(radixes[5]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario<uchint,sdig_t,radixes[6],sllint >(I);
        std::cout << "Base\t" << usint(radixes[6]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }

    for(I=0;I<11;++I)  {
        std::cout << si_const[I]  << std::endl;
        
        result = test_operator_binario_const<uchint,sdig_t,radixes[1],sllint>(I);
        std::cout << "Base\t" << usint(radixes[1]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_const<uchint,sdig_t,radixes[2],sllint>(I);
        std::cout << "Base\t" << usint(radixes[2]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_const<uchint,sdig_t,radixes[3],sllint >(I);
        std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_const<uchint,sdig_t,radixes[3],sllint >(I);
        std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_const<uchint,sdig_t,radixes[4],sllint >(I);
        std::cout << "Base\t" << usint(radixes[4]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_const<uchint,sdig_t,radixes[5],sllint >(I);
        std::cout << "Base\t" << usint(radixes[5]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_const<uchint,sdig_t,radixes[6],sllint >(I);
        std::cout << "Base\t" << usint(radixes[6]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
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
        
        result = test_operator_binario_hetero<uchint,sdig_t,radixes[1],sllint >(I);
        std::cout << "Base\t" << usint(radixes[1]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_hetero<uchint,sdig_t,radixes[2],sllint >(I);
        std::cout << "Base\t" << usint(radixes[2]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero<uchint,sdig_t,radixes[3],sllint >(I);
        std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_hetero<uchint,sdig_t,radixes[3],sllint >(I);
        std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_hetero<uchint,sdig_t,radixes[4],sllint >(I);
        std::cout << "Base\t" << usint(radixes[4]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero<uchint,sdig_t,radixes[5],sllint >(I);
        std::cout << "Base\t" << usint(radixes[5]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero<uchint,sdig_t,radixes[6],sllint >(I);
        std::cout << "Base\t" << usint(radixes[6]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }

    for(I=0;I<11;++I)  {
        std::cout << si_const[I]  << std::endl;
        
        result = test_operator_binario_hetero_const<uchint,sdig_t,radixes[1],sllint >(I);
        std::cout << "Base\t" << usint(radixes[1]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_hetero_const<uchint,sdig_t,radixes[2],sllint >(I);
        std::cout << "Base\t" << usint(radixes[2]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero_const<uchint,sdig_t,radixes[3],sllint >(I);
        std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_hetero_const<uchint,sdig_t,radixes[3],sllint >(I);
        std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
        result = test_operator_binario_hetero_const<uchint,sdig_t,radixes[4],sllint >(I);
        std::cout << "Base\t" << usint(radixes[4]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero_const<uchint,sdig_t,radixes[5],sllint >(I);
        std::cout << "Base\t" << usint(radixes[5]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
		result = test_operator_binario_hetero_const<uchint,sdig_t,radixes[6],sllint >(I);
        std::cout << "Base\t" << usint(radixes[6]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    }

}

void TEST_CONSTRUCTORES_Y_ASIGNACIONES_SDIG_T()
{
    result_test result;
	
	std::cout << "PRUEBAS PARA LOS CONSTRUCTORES DESDE UN TIPO BUILT-IN" << std::endl;
    result = test_constructores_desde_built_in<uchint,sdig_t,radixes[1],sllint>();
    std::cout << "Base\t" << usint(radixes[1]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructores_desde_built_in<uchint,sdig_t,radixes[2],sllint>();
    std::cout << "Base\t" << usint(radixes[2]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructores_desde_built_in<uchint,sdig_t,radixes[3],sllint>();
    std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructores_desde_built_in<uchint,sdig_t,radixes[3],sllint>();
    std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructores_desde_built_in<uchint,sdig_t,radixes[4],sllint>();
    std::cout << "Base\t" << usint(radixes[4]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructores_desde_built_in<uchint,sdig_t,radixes[5],sllint>();
    std::cout << "Base\t" << usint(radixes[5]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructores_desde_built_in<uchint,sdig_t,radixes[6],sllint>();
    std::cout << "Base\t" << usint(radixes[6]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;

    std::cout << "PRUEBAS PARA EL CONSTRUCTOR POR DEFECTO" << std::endl;
	result = test_constructor_por_defecto<uchint,sdig_t,radixes[1],sllint>();
    std::cout << "Base\t" << usint(radixes[1]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_por_defecto<uchint,sdig_t,radixes[2],sllint>();
    std::cout << "Base\t" << usint(radixes[2]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructor_por_defecto<uchint,sdig_t,radixes[3],sllint>();
    std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_por_defecto<uchint,sdig_t,radixes[3],sllint>();
    std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_por_defecto<uchint,sdig_t,radixes[4],sllint>();
    std::cout << "Base\t" << usint(radixes[4]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructor_por_defecto<uchint,sdig_t,radixes[5],sllint>();
    std::cout << "Base\t" << usint(radixes[5]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_por_defecto<uchint,sdig_t,radixes[6],sllint>();
    std::cout << "Base\t" << usint(radixes[6]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;

    std::cout << "PRUEBAS PARA EL CONSTRUCTOR COPIA" << std::endl;
	result = test_constructor_copia<uchint,sdig_t,radixes[1],sllint>();
    std::cout << "Base\t" << usint(radixes[1]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_copia<uchint,sdig_t,radixes[2],sllint>();
    std::cout << "Base\t" << usint(radixes[2]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructor_copia<uchint,sdig_t,radixes[3],sllint>();
    std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_copia<uchint,sdig_t,radixes[3],sllint>();
    std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_copia<uchint,sdig_t,radixes[4],sllint>();
    std::cout << "Base\t" << usint(radixes[4]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_constructor_copia<uchint,sdig_t,radixes[5],sllint>();
    std::cout << "Base\t" << usint(radixes[5]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_constructor_copia<uchint,sdig_t,radixes[6],sllint>();
    std::cout << "Base\t" << usint(radixes[6]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;

    std::cout << "PRUEBAS PARA EL OPERADOR DE ASIGNACION COPIA" << std::endl;
	result = test_asignaciones_copia<uchint,sdig_t,radixes[1],sllint >();
    std::cout << "Base\t" << usint(radixes[1]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_copia<uchint,sdig_t,radixes[2],sllint >();
    std::cout << "Base\t" << usint(radixes[2]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_asignaciones_copia<uchint,sdig_t,radixes[3],sllint >();
    std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_copia<uchint,sdig_t,radixes[3],sllint >();
    std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_copia<uchint,sdig_t,radixes[4],sllint >();
    std::cout << "Base\t" << usint(radixes[4]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_asignaciones_copia<uchint,sdig_t,radixes[5],sllint >();
    std::cout << "Base\t" << usint(radixes[5]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_copia<uchint,sdig_t,radixes[6],sllint >();
    std::cout << "Base\t" << usint(radixes[6]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;

    std::cout << "PRUEBAS PARA EL OPERADOR DE ASIGNACION DESDE BUILT-IN" << std::endl;
	result = test_asignaciones_desde_built_in<uchint,sdig_t,radixes[1],sllint>();
    std::cout << "Base\t" << usint(radixes[1]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_desde_built_in<uchint,sdig_t,radixes[2],sllint>();
    std::cout << "Base\t" << usint(radixes[2]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_asignaciones_desde_built_in<uchint,sdig_t,radixes[3],sllint>();
    std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_desde_built_in<uchint,sdig_t,radixes[3],sllint>();
    std::cout << "Base\t" << usint(radixes[3]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
	result = test_asignaciones_desde_built_in<uchint,sdig_t,radixes[4],sllint>();
    std::cout << "Base\t" << usint(radixes[4]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_desde_built_in<uchint,sdig_t,radixes[5],sllint>();
	std::cout << "Base\t" << usint(radixes[5]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
    result = test_asignaciones_desde_built_in<uchint,sdig_t,radixes[6],sllint>();
    std::cout << "Base\t" << usint(radixes[6]) << "\t ERRORES    =   " << result.erroneos << ";\t  CORRECTOS  =   " << result.correctos << std::endl;
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