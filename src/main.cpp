#include <clocale>
#include <windows.h>
#include "testunit.hpp"
#include "memory_handler.hpp"


int main() {
  //  COMIENZO PARA PONER ESPAÑOL EN CONSOLA
  //
  std::setlocale(LC_ALL,"es_ES");  // Cambiar locale - Suficiente para máquinas Linux
  SetConsoleCP(1252);         // Cambiar STDIN -  Para máquinas Windows
  SetConsoleOutputCP(1252);   // Cambiar STDOUT - Para máquinas Windows
  //
  // FINAL PARA PONER ESPAÑOL EN CONSOLA
  using dig_t = typename NumRepr::dig_t<10U>;
  using var_list_t = typename NumRepr::memory_handler::dig_var_list<10U>;
  var_list_t varlist;
  varlist.crea_var("A",dig_t(7));
  varlist.crea_var("B",dig_t(6));
  varlist.crea_var("C",dig_t::dig_0());
  std::cout << "Variable A : " << varlist("A").value() << std::endl;
  std::cout << "Variable B : " << varlist("B").value() << std::endl;
  std::cout << "Variable C : " << varlist("C").value() << std::endl;

  return 0;
}
