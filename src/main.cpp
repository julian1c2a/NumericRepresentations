#include "testunit.hpp"
#include "TplMp_typelist_t.hxx"
#include <clocale>

int main() {
  std::setlocale(LC_ALL,"es_ES.UTF-8");
  //NumRepr::testing::show_test_convert_to_int_driver();
  using tipo0 = typename TplMp::typelist_t<int,std::string,double,double*>::head_t;
  using body_t= typename TplMp::typelist_t<int,std::string,double,double*>::body_t;
  using tipo1 = typename body_t::head_t;
  using tipo2 = typename body_t::last_t;
  using tipo3 = typename TplMp::typelist_t<int,std::string,double,long double*>::last_t;
  tipo0 elem_0{4};
  tipo1 elem_1{"Esto es magnífico"};
  tipo2 elem_2{-13254576.1293488976*16};
  tipo3 elem_3 = new long double{-13254576.1293488976};
  std::cout << elem_0 << std::endl;
  std::cout << elem_1 << std::endl;
  std::cout << elem_2 << std::endl;
  std::cout << *elem_3 << std::endl;
  delete elem_3;
  return 0;
}
