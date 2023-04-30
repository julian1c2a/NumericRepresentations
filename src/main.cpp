#include <clocale>
#include <windows.h>
#include <fstream>
#include "testunit.hpp"
#include "memory_handler.hpp"

using namespace std::literals;
using genRadixDig_t = typename NumRepr::memory_handler::genRadixDig_t;


int main() {
  //  COMIENZO PARA PONER ESPAÑOL EN CONSOLA
  //
  std::setlocale(LC_ALL,"es_ES");  // Cambiar locale - Suficiente para máquinas Linux
  SetConsoleCP(1252);         // Cambiar STDIN -  Para máquinas Windows
  SetConsoleOutputCP(1252);   // Cambiar STDOUT - Para máquinas Windows
  //
  // FINAL PARA PONER ESPAÑOL EN CONSOLA

  using dig_t = typename NumRepr::dig_t<10U>;
  using var_list_t = typename NumRepr::memory_handler::var_list;
  var_list_t varlist;
  varlist.create_var("A",dig_t(7));
  varlist.create_var("B",dig_t(6));
  varlist.create_var("C",dig_t::dig_0());
  std::cout << " Creación de variables con valores explícitos o por defecto:\n "s;
  std::cout << "Variable A : "s << std::get<10>(varlist("A")) << std::endl;
  std::cout << "Variable B : "s << std::get<10>(varlist("B")) << std::endl;
  std::cout << "Variable C : "s << std::get<10>(varlist("C")) << std::endl;
  std::cout << " Asignación de variables con operaciones de otras variables:\n "s;
  if (varlist("C",(std::get<10>(varlist("A"))*std::get<10>(varlist("B")))))
  	std::cout << "Variable C : "s << std::get<10>(varlist("C")) << std::endl;
  else
  	std::cout << "La asignación ha devuelto false"s << std::endl;

  if (
	varlist(
		"D",
		std::get<10>(varlist("A"))*std::get<10>(varlist("B"))*std::get<10>(varlist("C"))
		)
	)
  	std::cout << "Variable D : " << std::get<10>(varlist("D")) << std::endl;
  else
  	std::cout << "La asignación ha devuelto false"s << std::endl;

  using generic_dig_t = NumRepr::memory_handler::genRadixDig_t;
  generic_dig_t variable{NumRepr::dig_t<10>(9)};

  std::cout << "Variant generic_dig_t : " << std::get<10>(variable) << '\n';

//  std::ofstream file("variant.txt");
//  file << "std::variant<std::monostate,";
//  for(int i=2 ; i < 255 ; ++i)
//  	file << "dig_t<" << i << ">,";
//  file << "dig_t<" << 255 << "> >";
//  file.close();

//  std::ofstream file("get.txt");
//  file << "std::variant<std::monostate,";
//  for(int i=2 ; i < 256 ; ++i)
//  	file << "        case " << i << " : return std::get<" << i << ">(arg).radix();\n";
//  file.close();

  return 0;
}
