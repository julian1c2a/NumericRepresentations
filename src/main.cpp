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

using dig2_t  = dig_t<2>;
using dig10_t = dig_t<10>;
using digF_t  = dig_t<16>;
using dig60_t = dig_t<60>;
using digPI_t = dig_t<180>;
using digFA_t = dig_t<210>;
using digFF_t = dig_t<255>;
using var_list_t = typename NumRepr::memory_handler::digvar_list;
using int_list_t = typename NumRepr::memory_handler::intvar_list;
using nat_list_t = typename NumRepr::memory_handler::natvar_list;

int main() {
  //  COMIENZO PARA PONER ESPAÑOL EN CONSOLA
  //
  std::setlocale(LC_ALL,"es_ES");  // Cambiar locale - Suficiente para máquinas Linux
  SetConsoleCP(1252);         // Cambiar STDIN -  Para máquinas Windows
  SetConsoleOutputCP(1252);   // Cambiar STDOUT - Para máquinas Windows
  //
  // FINAL PARA PONER ESPAÑOL EN CONSOLA



  var_list_t varlist;
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.create_var("A",dig10_t(7));
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.create_var("B",dig10_t(6));
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.create_var("C",dig10_t::dig_0());
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  std::cout << " Creación de variables con valores explícitos o por defecto [BASE 10]:\n "s;
  std::cout << '\n';
  std::cout << "Variable A : "s << std::get<10>(varlist("A")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("A")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("A").index() << '\n';
  std::cout << '\n';
  std::cout << "Variable B : "s << std::get<10>(varlist("B")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("B")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("B").index() << '\n';
  std::cout << '\n';
  std::cout << "Variable C : "s << std::get<10>(varlist("C")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("C")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("C").index() << '\n';
  std::cout << '\n';
  std::cout << '\n';
  varlist.create_var("E",digFF_t(7));
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.create_var("F",digFF_t(6));
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.create_var("G",digFF_t::dig_0());
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  std::cout << " Creación de variables con valores explícitos o por defecto [BASE 255]:\n "s;
  std::cout << '\n';
  std::cout << "Variable E : "s << std::get<255>(varlist("E")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("E")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("E").index() << '\n';
  std::cout << '\n';
  std::cout << "Variable F : "s << std::get<255>(varlist("F")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("F")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("F").index() << '\n';
  std::cout << '\n';
  std::cout << "Variable G : "s << std::get<255>(varlist("G")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("G")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("G").index() << '\n';
  std::cout << '\n';
  std::cout << '\n';
  std::cout << " Asignación de variables con operaciones de otras variables:\n "s;
  varlist.create_var("H",digFA_t(20));
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.create_var("I",digFA_t(36));
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.create_var("J",digFA_t::dig_Bm1());
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  std::cout << " Creación de variables con valores explícitos o por defecto [BASE 210]:\n "s;
  std::cout << '\n';
  std::cout << "Variable H : "s << std::get<210>(varlist("H")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("H")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("H").index() << '\n';
  std::cout << '\n';
  std::cout << "Variable I : "s << std::get<210>(varlist("I")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("I")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("I").index() << '\n';
  std::cout << '\n';
  std::cout << "Variable J : "s << std::get<210>(varlist("J")) << std::endl;
  std::cout << " get_radix_of_type me devuelve : " << get_radix_of_type(varlist("J")) << '\n';
  std::cout << " std::variant::index me devuelve : " << varlist("J").index() << '\n';
  std::cout << '\n';
  std::cout << '\n';
  varlist.erase_var("A");
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.erase_var("B");
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.erase_var("C");
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.erase_var("E");
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.erase_var("F");
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.erase_var("G");
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.erase_var("H");
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.erase_var("I");
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';
  varlist.erase_var("J");
  std::cout << "varlist.size() == "  << varlist.size() << '\n';
  std::cout << '\n';


//  std::cout << " Asignación de variables con operaciones de otras variables:\n "s;
//  if (varlist("C",(std::get<10>(varlist("A"))*std::get<10>(varlist("B")))))
//  	std::cout << "Variable C : "s << std::get<10>(varlist("C")) << std::endl;
//  else
//  	std::cout << "La asignación ha devuelto false"s << std::endl;

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
