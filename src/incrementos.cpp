
#include <variant>
#include "../include/dig_t.hpp"
#include "../include/variant_types.hpp"


namespace NumRepr::memory_handler {

const varRadixDig_t& varRadixDig_t::operator++() noexcept {
  const std::size_t indice{this->genRadixDig_t::index()};
  if ((indice >= 2)&&(indice < 64)) {
    switch(indice) {
      case  2 : {dig_t< 2>& este{std::get< 2>(*this)};++este;return (*this);}
      case  3 : {dig_t< 3>& este{std::get< 3>(*this)};++este;return (*this);}
      case  4 : {dig_t< 4>& este{std::get< 4>(*this)};++este;return (*this);}
      case  5 : {dig_t< 5>& este{std::get< 5>(*this)};++este;return (*this);}
      case  6 : {dig_t< 6>& este{std::get< 6>(*this)};++este;return (*this);}
      case  7 : {dig_t< 7>& este{std::get< 7>(*this)};++este;return (*this);}
      case  8 : {dig_t< 8>& este{std::get< 8>(*this)};++este;return (*this);}
      case  9 : {dig_t< 9>& este{std::get< 9>(*this)};++este;return (*this);}
      case 10 : {dig_t<10>& este{std::get<10>(*this)};++este;return (*this);}
      case 11 : {dig_t<11>& este{std::get<11>(*this)};++este;return (*this);}
      case 12 : {dig_t<12>& este{std::get<12>(*this)};++este;return (*this);}
      case 13 : {dig_t<13>& este{std::get<13>(*this)};++este;return (*this);}
      case 14 : {dig_t<14>& este{std::get<14>(*this)};++este;return (*this);}
      case 15 : {dig_t<15>& este{std::get<15>(*this)};++este;return (*this);}
      case 16 : {dig_t<16>& este{std::get<16>(*this)};++este;return (*this);}
      case 17 : {dig_t<17>& este{std::get<17>(*this)};++este;return (*this);}
      case 18 : {dig_t<18>& este{std::get<18>(*this)};++este;return (*this);}
      case 19 : {dig_t<19>& este{std::get<19>(*this)};++este;return (*this);}
      case 20 : {dig_t<20>& este{std::get<20>(*this)};++este;return (*this);}
      case 21 : {dig_t<21>& este{std::get<21>(*this)};++este;return (*this);}
      case 22 : {dig_t<22>& este{std::get<22>(*this)};++este;return (*this);}
      case 23 : {dig_t<23>& este{std::get<23>(*this)};++este;return (*this);}
      case 24 : {dig_t<24>& este{std::get<24>(*this)};++este;return (*this);}
      case 25 : {dig_t<25>& este{std::get<25>(*this)};++este;return (*this);}
      case 26 : {dig_t<26>& este{std::get<26>(*this)};++este;return (*this);}
      case 27 : {dig_t<27>& este{std::get<27>(*this)};++este;return (*this);}
      case 28 : {dig_t<28>& este{std::get<28>(*this)};++este;return (*this);}
      case 29 : {dig_t<29>& este{std::get<29>(*this)};++este;return (*this);}
      case 30 : {dig_t<30>& este{std::get<30>(*this)};++este;return (*this);}
      case 31 : {dig_t<31>& este{std::get<31>(*this)};++este;return (*this);}
      case 32 : {dig_t<32>& este{std::get<32>(*this)};++este;return (*this);}
      case 33 : {dig_t<33>& este{std::get<33>(*this)};++este;return (*this);}
      case 34 : {dig_t<34>& este{std::get<34>(*this)};++este;return (*this);}
      case 35 : {dig_t<35>& este{std::get<35>(*this)};++este;return (*this);}
      case 36 : {dig_t<36>& este{std::get<36>(*this)};++este;return (*this);}
      case 37 : {dig_t<37>& este{std::get<37>(*this)};++este;return (*this);}
      case 38 : {dig_t<38>& este{std::get<38>(*this)};++este;return (*this);}
      case 39 : {dig_t<39>& este{std::get<39>(*this)};++este;return (*this);}
      case 40 : {dig_t<40>& este{std::get<40>(*this)};++este;return (*this);}
      case 41 : {dig_t<41>& este{std::get<41>(*this)};++este;return (*this);}
      case 42 : {dig_t<42>& este{std::get<42>(*this)};++este;return (*this);}
      case 43 : {dig_t<43>& este{std::get<43>(*this)};++este;return (*this);}
      case 44 : {dig_t<44>& este{std::get<44>(*this)};++este;return (*this);}
      case 45 : {dig_t<45>& este{std::get<45>(*this)};++este;return (*this);}
      case 46 : {dig_t<46>& este{std::get<46>(*this)};++este;return (*this);}
      case 47 : {dig_t<47>& este{std::get<47>(*this)};++este;return (*this);}
      case 48 : {dig_t<48>& este{std::get<48>(*this)};++este;return (*this);}
      case 49 : {dig_t<49>& este{std::get<49>(*this)};++este;return (*this);}
      case 50 : {dig_t<50>& este{std::get<50>(*this)};++este;return (*this);}
      case 51 : {dig_t<51>& este{std::get<51>(*this)};++este;return (*this);}
      case 52 : {dig_t<52>& este{std::get<52>(*this)};++este;return (*this);}
      case 53 : {dig_t<53>& este{std::get<53>(*this)};++este;return (*this);}
      case 54 : {dig_t<54>& este{std::get<54>(*this)};++este;return (*this);}
      case 55 : {dig_t<55>& este{std::get<55>(*this)};++este;return (*this);}
      case 56 : {dig_t<56>& este{std::get<56>(*this)};++este;return (*this);}
      case 57 : {dig_t<57>& este{std::get<57>(*this)};++este;return (*this);}
      case 58 : {dig_t<58>& este{std::get<58>(*this)};++este;return (*this);}
      case 59 : {dig_t<59>& este{std::get<59>(*this)};++este;return (*this);}
      case 60 : {dig_t<60>& este{std::get<60>(*this)};++este;return (*this);}
      case 61 : {dig_t<61>& este{std::get<61>(*this)};++este;return (*this);}
      case 62 : {dig_t<62>& este{std::get<62>(*this)};++este;return (*this);}
      default : {dig_t<63>& este{std::get<63>(*this)};++este;return (*this);}
    }
  }
  return (*this);
}

const varRadixDig_t& varRadixDig_t::operator--() noexcept {
  const std::size_t indice{this->genRadixDig_t::index()};
  if ((indice >= 2)&&(indice < 64)) {
    switch(indice) {
      case  2 : {dig_t< 2>& este{std::get< 2>(*this)};--este;return (*this);}
      case  3 : {dig_t< 3>& este{std::get< 3>(*this)};--este;return (*this);}
      case  4 : {dig_t< 4>& este{std::get< 4>(*this)};--este;return (*this);}
      case  5 : {dig_t< 5>& este{std::get< 5>(*this)};--este;return (*this);}
      case  6 : {dig_t< 6>& este{std::get< 6>(*this)};--este;return (*this);}
      case  7 : {dig_t< 7>& este{std::get< 7>(*this)};--este;return (*this);}
      case  8 : {dig_t< 8>& este{std::get< 8>(*this)};--este;return (*this);}
      case  9 : {dig_t< 9>& este{std::get< 9>(*this)};--este;return (*this);}
      case 10 : {dig_t<10>& este{std::get<10>(*this)};--este;return (*this);}
      case 11 : {dig_t<11>& este{std::get<11>(*this)};--este;return (*this);}
      case 12 : {dig_t<12>& este{std::get<12>(*this)};--este;return (*this);}
      case 13 : {dig_t<13>& este{std::get<13>(*this)};--este;return (*this);}
      case 14 : {dig_t<14>& este{std::get<14>(*this)};--este;return (*this);}
      case 15 : {dig_t<15>& este{std::get<15>(*this)};--este;return (*this);}
      case 16 : {dig_t<16>& este{std::get<16>(*this)};--este;return (*this);}
      case 17 : {dig_t<17>& este{std::get<17>(*this)};--este;return (*this);}
      case 18 : {dig_t<18>& este{std::get<18>(*this)};--este;return (*this);}
      case 19 : {dig_t<19>& este{std::get<19>(*this)};--este;return (*this);}
      case 20 : {dig_t<20>& este{std::get<20>(*this)};--este;return (*this);}
      case 21 : {dig_t<21>& este{std::get<21>(*this)};--este;return (*this);}
      case 22 : {dig_t<22>& este{std::get<22>(*this)};--este;return (*this);}
      case 23 : {dig_t<23>& este{std::get<23>(*this)};--este;return (*this);}
      case 24 : {dig_t<24>& este{std::get<24>(*this)};--este;return (*this);}
      case 25 : {dig_t<25>& este{std::get<25>(*this)};--este;return (*this);}
      case 26 : {dig_t<26>& este{std::get<26>(*this)};--este;return (*this);}
      case 27 : {dig_t<27>& este{std::get<27>(*this)};--este;return (*this);}
      case 28 : {dig_t<28>& este{std::get<28>(*this)};--este;return (*this);}
      case 29 : {dig_t<29>& este{std::get<29>(*this)};--este;return (*this);}
      case 30 : {dig_t<30>& este{std::get<30>(*this)};--este;return (*this);}
      case 31 : {dig_t<31>& este{std::get<31>(*this)};--este;return (*this);}
      case 32 : {dig_t<32>& este{std::get<32>(*this)};--este;return (*this);}
      case 33 : {dig_t<33>& este{std::get<33>(*this)};--este;return (*this);}
      case 34 : {dig_t<34>& este{std::get<34>(*this)};--este;return (*this);}
      case 35 : {dig_t<35>& este{std::get<35>(*this)};--este;return (*this);}
      case 36 : {dig_t<36>& este{std::get<36>(*this)};--este;return (*this);}
      case 37 : {dig_t<37>& este{std::get<37>(*this)};--este;return (*this);}
      case 38 : {dig_t<38>& este{std::get<38>(*this)};--este;return (*this);}
      case 39 : {dig_t<39>& este{std::get<39>(*this)};--este;return (*this);}
      case 40 : {dig_t<40>& este{std::get<40>(*this)};--este;return (*this);}
      case 41 : {dig_t<41>& este{std::get<41>(*this)};--este;return (*this);}
      case 42 : {dig_t<42>& este{std::get<42>(*this)};--este;return (*this);}
      case 43 : {dig_t<43>& este{std::get<43>(*this)};--este;return (*this);}
      case 44 : {dig_t<44>& este{std::get<44>(*this)};--este;return (*this);}
      case 45 : {dig_t<45>& este{std::get<45>(*this)};--este;return (*this);}
      case 46 : {dig_t<46>& este{std::get<46>(*this)};--este;return (*this);}
      case 47 : {dig_t<47>& este{std::get<47>(*this)};--este;return (*this);}
      case 48 : {dig_t<48>& este{std::get<48>(*this)};--este;return (*this);}
      case 49 : {dig_t<49>& este{std::get<49>(*this)};--este;return (*this);}
      case 50 : {dig_t<50>& este{std::get<50>(*this)};--este;return (*this);}
      case 51 : {dig_t<51>& este{std::get<51>(*this)};--este;return (*this);}
      case 52 : {dig_t<52>& este{std::get<52>(*this)};--este;return (*this);}
      case 53 : {dig_t<53>& este{std::get<53>(*this)};--este;return (*this);}
      case 54 : {dig_t<54>& este{std::get<54>(*this)};--este;return (*this);}
      case 55 : {dig_t<55>& este{std::get<55>(*this)};--este;return (*this);}
      case 56 : {dig_t<56>& este{std::get<56>(*this)};--este;return (*this);}
      case 57 : {dig_t<57>& este{std::get<57>(*this)};--este;return (*this);}
      case 58 : {dig_t<58>& este{std::get<58>(*this)};--este;return (*this);}
      case 59 : {dig_t<59>& este{std::get<59>(*this)};--este;return (*this);}
      case 60 : {dig_t<60>& este{std::get<60>(*this)};--este;return (*this);}
      case 61 : {dig_t<61>& este{std::get<61>(*this)};--este;return (*this);}
      case 62 : {dig_t<62>& este{std::get<62>(*this)};--este;return (*this);}
      default : {dig_t<63>& este{std::get<63>(*this)};--este;return (*this);}
    }
  }
  return (*this);
}


varRadixDig_t varRadixDig_t::operator++(int) noexcept {
  const std::size_t indice{this->genRadixDig_t::index()};
  if ((indice >= 2)&&(indice < 64)) {
    switch(indice) {
      case  2 : {dig_t< 2> result{std::get< 2>(*this)};++(*this);return result;}
      case  3 : {dig_t< 3> result{std::get< 3>(*this)};++(*this);return result;}
      case  4 : {dig_t< 4> result{std::get< 4>(*this)};++(*this);return result;}
      case  5 : {dig_t< 5> result{std::get< 5>(*this)};++(*this);return result;}
      case  6 : {dig_t< 6> result{std::get< 6>(*this)};++(*this);return result;}
      case  7 : {dig_t< 7> result{std::get< 7>(*this)};++(*this);return result;}
      case  8 : {dig_t< 8> result{std::get< 8>(*this)};++(*this);return result;}
      case  9 : {dig_t< 9> result{std::get< 9>(*this)};++(*this);return result;}
      case 10 : {dig_t<10> result{std::get<10>(*this)};++(*this);return result;}
      case 11 : {dig_t<11> result{std::get<11>(*this)};++(*this);return result;}
      case 12 : {dig_t<12> result{std::get<12>(*this)};++(*this);return result;}
      case 13 : {dig_t<13> result{std::get<13>(*this)};++(*this);return result;}
      case 14 : {dig_t<14> result{std::get<14>(*this)};++(*this);return result;}
      case 15 : {dig_t<15> result{std::get<15>(*this)};++(*this);return result;}
      case 16 : {dig_t<16> result{std::get<16>(*this)};++(*this);return result;}
      case 17 : {dig_t<17> result{std::get<17>(*this)};++(*this);return result;}
      case 18 : {dig_t<18> result{std::get<18>(*this)};++(*this);return result;}
      case 19 : {dig_t<19> result{std::get<19>(*this)};++(*this);return result;}
      case 20 : {dig_t<20> result{std::get<20>(*this)};++(*this);return result;}
      case 21 : {dig_t<21> result{std::get<21>(*this)};++(*this);return result;}
      case 22 : {dig_t<22> result{std::get<22>(*this)};++(*this);return result;}
      case 23 : {dig_t<23> result{std::get<23>(*this)};++(*this);return result;}
      case 24 : {dig_t<24> result{std::get<24>(*this)};++(*this);return result;}
      case 25 : {dig_t<25> result{std::get<25>(*this)};++(*this);return result;}
      case 26 : {dig_t<26> result{std::get<26>(*this)};++(*this);return result;}
      case 27 : {dig_t<27> result{std::get<27>(*this)};++(*this);return result;}
      case 28 : {dig_t<28> result{std::get<28>(*this)};++(*this);return result;}
      case 29 : {dig_t<29> result{std::get<29>(*this)};++(*this);return result;}
      case 30 : {dig_t<30> result{std::get<30>(*this)};++(*this);return result;}
      case 31 : {dig_t<31> result{std::get<31>(*this)};++(*this);return result;}
      case 32 : {dig_t<32> result{std::get<32>(*this)};++(*this);return result;}
      case 33 : {dig_t<33> result{std::get<33>(*this)};++(*this);return result;}
      case 34 : {dig_t<34> result{std::get<34>(*this)};++(*this);return result;}
      case 35 : {dig_t<35> result{std::get<35>(*this)};++(*this);return result;}
      case 36 : {dig_t<36> result{std::get<36>(*this)};++(*this);return result;}
      case 37 : {dig_t<37> result{std::get<37>(*this)};++(*this);return result;}
      case 38 : {dig_t<38> result{std::get<38>(*this)};++(*this);return result;}
      case 39 : {dig_t<39> result{std::get<39>(*this)};++(*this);return result;}
      case 40 : {dig_t<40> result{std::get<40>(*this)};++(*this);return result;}
      case 41 : {dig_t<41> result{std::get<41>(*this)};++(*this);return result;}
      case 42 : {dig_t<42> result{std::get<42>(*this)};++(*this);return result;}
      case 43 : {dig_t<43> result{std::get<43>(*this)};++(*this);return result;}
      case 44 : {dig_t<44> result{std::get<44>(*this)};++(*this);return result;}
      case 45 : {dig_t<45> result{std::get<45>(*this)};++(*this);return result;}
      case 46 : {dig_t<46> result{std::get<46>(*this)};++(*this);return result;}
      case 47 : {dig_t<47> result{std::get<47>(*this)};++(*this);return result;}
      case 48 : {dig_t<48> result{std::get<48>(*this)};++(*this);return result;}
      case 49 : {dig_t<49> result{std::get<49>(*this)};++(*this);return result;}
      case 50 : {dig_t<50> result{std::get<50>(*this)};++(*this);return result;}
      case 51 : {dig_t<51> result{std::get<51>(*this)};++(*this);return result;}
      case 52 : {dig_t<52> result{std::get<52>(*this)};++(*this);return result;}
      case 53 : {dig_t<53> result{std::get<53>(*this)};++(*this);return result;}
      case 54 : {dig_t<54> result{std::get<54>(*this)};++(*this);return result;}
      case 55 : {dig_t<55> result{std::get<55>(*this)};++(*this);return result;}
      case 56 : {dig_t<56> result{std::get<56>(*this)};++(*this);return result;}
      case 57 : {dig_t<57> result{std::get<57>(*this)};++(*this);return result;}
      case 58 : {dig_t<58> result{std::get<58>(*this)};++(*this);return result;}
      case 59 : {dig_t<59> result{std::get<59>(*this)};++(*this);return result;}
      case 60 : {dig_t<60> result{std::get<60>(*this)};++(*this);return result;}
      case 61 : {dig_t<61> result{std::get<61>(*this)};++(*this);return result;}
      case 62 : {dig_t<62> result{std::get<62>(*this)};++(*this);return result;}
      default : {dig_t<63> result{std::get<63>(*this)};++(*this);return result;}
    }
  }
  return (*this);
}

varRadixDig_t varRadixDig_t::operator--(int) noexcept {
  const std::size_t indice{this->genRadixDig_t::index()};
  if ((indice >= 2)&&(indice < 64)) {
    switch(indice) {
      case  2 : {dig_t< 2> result{std::get< 2>(*this)};--(*this); return result;}
      case  3 : {dig_t< 3> result{std::get< 3>(*this)};--(*this); return result;}
      case  4 : {dig_t< 4> result{std::get< 4>(*this)};--(*this); return result;}
      case  5 : {dig_t< 5> result{std::get< 5>(*this)};--(*this); return result;}
      case  6 : {dig_t< 6> result{std::get< 6>(*this)};--(*this); return result;}
      case  7 : {dig_t< 7> result{std::get< 7>(*this)};--(*this); return result;}
      case  8 : {dig_t< 8> result{std::get< 8>(*this)};--(*this); return result;}
      case  9 : {dig_t< 9> result{std::get< 9>(*this)};--(*this); return result;}
      case 10 : {dig_t<10> result{std::get<10>(*this)};--(*this); return result;}
      case 11 : {dig_t<11> result{std::get<11>(*this)};--(*this); return result;}
      case 12 : {dig_t<12> result{std::get<12>(*this)};--(*this); return result;}
      case 13 : {dig_t<13> result{std::get<13>(*this)};--(*this); return result;}
      case 14 : {dig_t<14> result{std::get<14>(*this)};--(*this); return result;}
      case 15 : {dig_t<15> result{std::get<15>(*this)};--(*this); return result;}
      case 16 : {dig_t<16> result{std::get<16>(*this)};--(*this); return result;}
      case 17 : {dig_t<17> result{std::get<17>(*this)};--(*this); return result;}
      case 18 : {dig_t<18> result{std::get<18>(*this)};--(*this); return result;}
      case 19 : {dig_t<19> result{std::get<19>(*this)};--(*this); return result;}
      case 20 : {dig_t<20> result{std::get<20>(*this)};--(*this); return result;}
      case 21 : {dig_t<21> result{std::get<21>(*this)};--(*this); return result;}
      case 22 : {dig_t<22> result{std::get<22>(*this)};--(*this); return result;}
      case 23 : {dig_t<23> result{std::get<23>(*this)};--(*this); return result;}
      case 24 : {dig_t<24> result{std::get<24>(*this)};--(*this); return result;}
      case 25 : {dig_t<25> result{std::get<25>(*this)};--(*this); return result;}
      case 26 : {dig_t<26> result{std::get<26>(*this)};--(*this); return result;}
      case 27 : {dig_t<27> result{std::get<27>(*this)};--(*this); return result;}
      case 28 : {dig_t<28> result{std::get<28>(*this)};--(*this); return result;}
      case 29 : {dig_t<29> result{std::get<29>(*this)};--(*this); return result;}
      case 30 : {dig_t<30> result{std::get<30>(*this)};--(*this); return result;}
      case 31 : {dig_t<31> result{std::get<31>(*this)};--(*this); return result;}
      case 32 : {dig_t<32> result{std::get<32>(*this)};--(*this); return result;}
      case 33 : {dig_t<33> result{std::get<33>(*this)};--(*this); return result;}
      case 34 : {dig_t<34> result{std::get<34>(*this)};--(*this); return result;}
      case 35 : {dig_t<35> result{std::get<35>(*this)};--(*this); return result;}
      case 36 : {dig_t<36> result{std::get<36>(*this)};--(*this); return result;}
      case 37 : {dig_t<37> result{std::get<37>(*this)};--(*this); return result;}
      case 38 : {dig_t<38> result{std::get<38>(*this)};--(*this); return result;}
      case 39 : {dig_t<39> result{std::get<39>(*this)};--(*this); return result;}
      case 40 : {dig_t<40> result{std::get<40>(*this)};--(*this); return result;}
      case 41 : {dig_t<41> result{std::get<41>(*this)};--(*this); return result;}
      case 42 : {dig_t<42> result{std::get<42>(*this)};--(*this); return result;}
      case 43 : {dig_t<43> result{std::get<43>(*this)};--(*this); return result;}
      case 44 : {dig_t<44> result{std::get<44>(*this)};--(*this); return result;}
      case 45 : {dig_t<45> result{std::get<45>(*this)};--(*this); return result;}
      case 46 : {dig_t<46> result{std::get<46>(*this)};--(*this); return result;}
      case 47 : {dig_t<47> result{std::get<47>(*this)};--(*this); return result;}
      case 48 : {dig_t<48> result{std::get<48>(*this)};--(*this); return result;}
      case 49 : {dig_t<49> result{std::get<49>(*this)};--(*this); return result;}
      case 50 : {dig_t<50> result{std::get<50>(*this)};--(*this); return result;}
      case 51 : {dig_t<51> result{std::get<51>(*this)};--(*this); return result;}
      case 52 : {dig_t<52> result{std::get<52>(*this)};--(*this); return result;}
      case 53 : {dig_t<53> result{std::get<53>(*this)};--(*this); return result;}
      case 54 : {dig_t<54> result{std::get<54>(*this)};--(*this); return result;}
      case 55 : {dig_t<55> result{std::get<55>(*this)};--(*this); return result;}
      case 56 : {dig_t<56> result{std::get<56>(*this)};--(*this); return result;}
      case 57 : {dig_t<57> result{std::get<57>(*this)};--(*this); return result;}
      case 58 : {dig_t<58> result{std::get<58>(*this)};--(*this); return result;}
      case 59 : {dig_t<59> result{std::get<59>(*this)};--(*this); return result;}
      case 60 : {dig_t<60> result{std::get<60>(*this)};--(*this); return result;}
      case 61 : {dig_t<61> result{std::get<61>(*this)};--(*this); return result;}
      case 62 : {dig_t<62> result{std::get<62>(*this)};--(*this); return result;}
      default : {dig_t<63> result{std::get<63>(*this)};--(*this); return result;}
    }
  }
  return (*this);
}




//	varRadixDig_t varRadixDig_t::operator++(int) noexcept
//	varRadixDig_t varRadixDig_t::operator--(int) noexcept
} /// END NAMESPACE NUMREPR::MEMORY_HANDLER
