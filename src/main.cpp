#include <clocale>
#include <windows.h>
#include <fstream>
#include "../include/testunit.hpp"
#include "../include/memory_handler.hpp"
#include "../include/get.hpp"

using namespace std::literals;
using genRadixDig_t = typename NumRepr::memory_handler::genRadixDig_t;

/// PARA CUANDO LOS *.O SEAN DEMASIADO GRANDES:
///    --param ggc-min-expand=0 --param ggc-min-heapsize=4096

template<std::uint64_t IX>
using dig_t = typename NumRepr::dig_t<IX>;

using dig10_t = dig_t<10>;
using digFF_t = dig_t<255>;
using var_list_t = typename NumRepr::memory_handler::var_list;

int main() {
  //  COMIENZO PARA PONER ESPAÑOL EN CONSOLA
  //
  std::setlocale(LC_ALL,"es_ES");  // Cambiar locale - Suficiente para máquinas Linux
  SetConsoleCP(1252);         // Cambiar STDIN -  Para máquinas Windows
  SetConsoleOutputCP(1252);   // Cambiar STDOUT - Para máquinas Windows
  //
  // FINAL PARA PONER ESPAÑOL EN CONSOLA



  var_list_t varlist;
  varlist.create_var("A",dig10_t(7));
  varlist.create_var("B",dig10_t(6));
  varlist.create_var("C",dig10_t::dig_0());
  std::cout << " Creación de variables con valores explícitos o por defecto:\n "s;

  std::cout << "Variable A : "s << std::get<10>(varlist("A")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("A")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("A").index() << '\n';

  std::cout << "Variable B : "s << std::get<10>(varlist("B")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("B")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("B").index() << '\n';

  std::cout << "Variable C : "s << std::get<10>(varlist("C")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("C")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("C").index() << '\n';

  varlist.create_var("E",digFF_t(7));
  varlist.create_var("F",digFF_t(6));
  varlist.create_var("G",digFF_t::dig_0());
  std::cout << " Creación de variables con valores explícitos o por defecto:\n "s;

  std::cout << "Variable E : "s << std::get<255>(varlist("E")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("E")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("E").index() << '\n';

  std::cout << "Variable F : "s << std::get<255>(varlist("F")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("F")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("F").index() << '\n';

  std::cout << "Variable G : "s << std::get<255>(varlist("G")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("G")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("G").index() << '\n';

  std::cout << " Asignación de variables con operaciones de otras variables:\n "s;
  if (varlist("C",(std::get<10>(varlist("A"))*std::get<10>(varlist("B")))))
  	std::cout << "Variable C : "s << std::get<10>(varlist("C")) << std::endl;
  else
  	std::cout << "La asignación ha devuelto false"s << std::endl;

//  if (
//	varlist(
//		"D",
//		std::get<10>(varlist("A"))*std::get<10>(varlist("B"))*std::get<10>(varlist("C"))
//		)
//	)
//  	std::cout << "Variable D : " << std::get<10>(varlist("D")) << std::endl;
//  else
//  	std::cout << "La asignación ha devuelto false"s << std::endl;

//  using generic_dig_t = NumRepr::memory_handler::genRadixDig_t;
//  generic_dig_t variable{NumRepr::dig_t<101>(9)};
//
//  std::cout << "Variant generic_dig_t : " << std::get<101>(variable) << '\n';
//  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(variable) << '\n';
//  std::cout << " std::variant::index me devuelve : " << variable.index() << '\n';

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
