#ifndef PRESENTACION__HPP
#define PRESENTACION__HPP

#include "constants_test_unit.hpp"
#include "spardigs_t.hpp"

typedef std::tuple<spardigs_t<2>,
				spardigs_t<3>,
				spardigs_t<4>,
				spardigs_t<5>,
				spardigs_t<6>,
				spardigs_t<7>,
				spardigs_t<8>,
				spardigs_t<9>,
				spardigs_t<10>,
				spardigs_t<11>,
				spardigs_t<12>,
				spardigs_t<13>,
				spardigs_t<14>,
				spardigs_t<15>,
				spardigs_t<16>> contenedor_t;

using arreglo_1d_t = std::array<sllint,6>;
using arreglo_2d_t = std::array<arreglo_1d_t,14>;

typedef std::array<contenedor_t,14> contenedor_1d_t;

	sllint Begin(sllint base) {
		switch(base-2) {
				case  0:return Limit<uchint,spardigs_t,2,sllint>::BeginIndex;
				case  1:return Limit<uchint,spardigs_t,3,sllint>::BeginIndex;
				case  2:return Limit<uchint,spardigs_t,4,sllint>::BeginIndex;
				case  3:return Limit<uchint,spardigs_t,5,sllint>::BeginIndex;
				case  4:return Limit<uchint,spardigs_t,6,sllint>::BeginIndex;
				case  5:return Limit<uchint,spardigs_t,7,sllint>::BeginIndex;
				case  6:return Limit<uchint,spardigs_t,8,sllint>::BeginIndex;
				case  7:return Limit<uchint,spardigs_t,9,sllint>::BeginIndex;
				case  8:return Limit<uchint,spardigs_t,10,sllint>::BeginIndex;
				case  9:return Limit<uchint,spardigs_t,11,sllint>::BeginIndex;
				case 10:return Limit<uchint,spardigs_t,12,sllint>::BeginIndex;
				case 11:return Limit<uchint,spardigs_t,13,sllint>::BeginIndex;
				case 12:return Limit<uchint,spardigs_t,14,sllint>::BeginIndex;
				case 13:return Limit<uchint,spardigs_t,15,sllint>::BeginIndex;
				case 14:return Limit<uchint,spardigs_t,16,sllint>::BeginIndex;
				default:return Limit<uchint,spardigs_t,16,sllint>::BeginIndex;
			}
	}


	sllint End(sllint base) {
		switch(base-2) {
				case  0:return Limit<uchint,spardigs_t,2,sllint>::EndIndex;
				case  1:return Limit<uchint,spardigs_t,3,sllint>::EndIndex;
				case  2:return Limit<uchint,spardigs_t,4,sllint>::EndIndex;
				case  3:return Limit<uchint,spardigs_t,5,sllint>::EndIndex;
				case  4:return Limit<uchint,spardigs_t,6,sllint>::EndIndex;
				case  5:return Limit<uchint,spardigs_t,7,sllint>::EndIndex;
				case  6:return Limit<uchint,spardigs_t,8,sllint>::EndIndex;
				case  7:return Limit<uchint,spardigs_t,9,sllint>::EndIndex;
				case  8:return Limit<uchint,spardigs_t,10,sllint>::EndIndex;
				case  9:return Limit<uchint,spardigs_t,11,sllint>::EndIndex;
				case 10:return Limit<uchint,spardigs_t,12,sllint>::EndIndex;
				case 11:return Limit<uchint,spardigs_t,13,sllint>::EndIndex;
				case 12:return Limit<uchint,spardigs_t,14,sllint>::EndIndex;
				case 13:return Limit<uchint,spardigs_t,15,sllint>::EndIndex;
				case 14:return Limit<uchint,spardigs_t,16,sllint>::EndIndex;
				default:return Limit<uchint,spardigs_t,16,sllint>::EndIndex;
			}
	}

	void assign(sllint base,contenedor_1d_t& arg,const arreglo_2d_t& Number,sllint dir) {
		switch(base-2) {
			case  0:std::get<0>(arg[dir]).spardigs_t<2>::operator=(sllint(Number[base-2][dir]));break;
			case  1:std::get<1>(arg[dir]).spardigs_t<3>::operator=(sllint(Number[base-2][dir]));break;
			case  2:std::get<2>(arg[dir]).spardigs_t<4>::operator=(sllint(Number[base-2][dir]));break;
			case  3:std::get<3>(arg[dir]).spardigs_t<5>::operator=(sllint(Number[base-2][dir]));break;
			case  4:std::get<4>(arg[dir]).spardigs_t<6>::operator=(sllint(Number[base-2][dir]));break;
			case  5:std::get<5>(arg[dir]).spardigs_t<7>::operator=(sllint(Number[base-2][dir]));break;
			case  6:std::get<6>(arg[dir]).spardigs_t<8>::operator=(sllint(Number[base-2][dir]));break;
			case  7:std::get<7>(arg[dir]).spardigs_t<9>::operator=(sllint(Number[base-2][dir]));break;
			case  8:std::get<8>(arg[dir]).spardigs_t<10>::operator=(sllint(Number[base-2][dir]));break;
			case  9:std::get<9>(arg[dir]).spardigs_t<11>::operator=(sllint(Number[base-2][dir]));break;
			case 10:std::get<10>(arg[dir]).spardigs_t<12>::operator=(sllint(Number[base-2][dir]));break;
			case 11:std::get<11>(arg[dir]).spardigs_t<13>::operator=(sllint(Number[base-2][dir]));break;
			case 12:std::get<12>(arg[dir]).spardigs_t<14>::operator=(sllint(Number[base-2][dir]));break;
			case 13:std::get<13>(arg[dir]).spardigs_t<15>::operator=(sllint(Number[base-2][dir]));break;
			case 14:std::get<14>(arg[dir]).spardigs_t<16>::operator=(sllint(Number[base-2][dir]));break;
			default:std::get<14>(arg[dir]).spardigs_t<16>::operator=(sllint(Number[base-2][dir]));
		}
	}

	template<const uchint base>
	void assign(contenedor_1d_t& arg,spardigs_t<base> otro) {
		switch(base-2) {
			case  0:std::get<0>(arg[2])=otro;break;
			case  1:std::get<1>(arg[2])=otro;break;
			case  2:std::get<2>(arg[2])=otro;break;
			case  3:std::get<3>(arg[2])=otro;break;
			case  4:std::get<4>(arg[2])=otro;break;
			case  5:std::get<5>(arg[2])=otro;break;
			case  6:std::get<6>(arg[2])=otro;break;
			case  7:std::get<7>(arg[2])=otro;break;
			case  8:std::get<8>(arg[2])=otro;break;
			case  9:std::get<9>(arg[2])=otro;break;
			case 10:std::get<10>(arg[2])=otro;break;
			case 11:std::get<11>(arg[2])=otro;break;
			case 12:std::get<12>(arg[2])=otro;break;
			case 13:std::get<13>(arg[2])=otro;break;
			case 14:std::get<14>(arg[2])=otro;break;
			default:std::get<14>(arg[2])=otro;
		}
	}

	void hacer_oper_plus(sllint base,contenedor_1d_t& arg) {
		switch(base-2) {
			case 0: assign(arg,std::get<0>(arg[0]).spardigs_t<2>::operator+(std::get<0>(arg[1])));break;
			case 1: assign(arg,std::get<1>(arg[0]).spardigs_t<3>::operator+(std::get<1>(arg[1])));break;
			case 2: assign(arg,std::get<2>(arg[0]).spardigs_t<4>::operator+(std::get<2>(arg[1])));break;
			case 3: assign(arg,std::get<3>(arg[0]).spardigs_t<5>::operator+(std::get<3>(arg[1])));break;
			case 4: assign(arg,std::get<4>(arg[0]).spardigs_t<6>::operator+(std::get<4>(arg[1])));break;
			case 5: assign(arg,std::get<5>(arg[0]).spardigs_t<7>::operator+(std::get<5>(arg[1])));break;
			case 6: assign(arg,std::get<6>(arg[0]).spardigs_t<8>::operator+(std::get<6>(arg[1])));break;
			case 7: assign(arg,std::get<7>(arg[0]).spardigs_t<9>::operator+(std::get<7>(arg[1])));break;
			case 8: assign(arg,std::get<8>(arg[0]).spardigs_t<10>::operator+(std::get<8>(arg[1])));break;
			case 9: assign(arg,std::get<9>(arg[0]).spardigs_t<11>::operator+(std::get<9>(arg[1])));break;
			case 10: assign(arg,std::get<10>(arg[0]).spardigs_t<12>::operator+(std::get<10>(arg[1])));break;
			case 11: assign(arg,std::get<11>(arg[0]).spardigs_t<13>::operator+(std::get<11>(arg[1])));break;
			case 12: assign(arg,std::get<12>(arg[0]).spardigs_t<14>::operator+(std::get<12>(arg[1])));break;
			case 13: assign(arg,std::get<13>(arg[0]).spardigs_t<15>::operator+(std::get<13>(arg[1])));break;
			case 14: assign(arg,std::get<14>(arg[0]).spardigs_t<16>::operator+(std::get<14>(arg[1])));break;
			default: assign(arg,std::get<14>(arg[0]).spardigs_t<16>::operator+(std::get<14>(arg[1])));
		}
	}

	void hacer_oper_minus(sllint base,contenedor_1d_t& arg) {
		switch(base-2) {
			case 0: assign<2>(arg,std::get<0>(arg[0]).spardigs_t<2>::operator-(std::get<0>(arg[1])));break;
			case 1: assign<3>(arg,std::get<1>(arg[0]).spardigs_t<3>::operator-(std::get<1>(arg[1])));break;
			case 2: assign<4>(arg,std::get<2>(arg[0]).spardigs_t<4>::operator-(std::get<2>(arg[1])));break;
			case 3: assign<5>(arg,std::get<3>(arg[0]).spardigs_t<5>::operator-(std::get<3>(arg[1])));break;
			case 4: assign<6>(arg,std::get<4>(arg[0]).spardigs_t<6>::operator-(std::get<4>(arg[1])));break;
			case 5: assign<7>(arg,std::get<5>(arg[0]).spardigs_t<7>::operator-(std::get<5>(arg[1])));break;
			case 6: assign<8>(arg,std::get<6>(arg[0]).spardigs_t<8>::operator-(std::get<6>(arg[1])));break;
			case 7: assign<9>(arg,std::get<7>(arg[0]).spardigs_t<9>::operator-(std::get<7>(arg[1])));break;
			case 8: assign<10>(arg,std::get<8>(arg[0]).spardigs_t<10>::operator-(std::get<8>(arg[1])));break;
			case 9: assign<11>(arg,std::get<9>(arg[0]).spardigs_t<11>::operator-(std::get<9>(arg[1])));break;
			case 10: assign<12>(arg,std::get<10>(arg[0]).spardigs_t<12>::operator-(std::get<10>(arg[1])));break;
			case 11: assign<13>(arg,std::get<11>(arg[0]).spardigs_t<13>::operator-(std::get<11>(arg[1])));break;
			case 12: assign<14>(arg,std::get<12>(arg[0]).spardigs_t<14>::operator-(std::get<12>(arg[1])));break;
			case 13: assign<15>(arg,std::get<13>(arg[0]).spardigs_t<15>::operator-(std::get<13>(arg[1])));break;
			case 14: assign<16>(arg,std::get<14>(arg[0]).spardigs_t<16>::operator-(std::get<14>(arg[1])));break;
			default: assign<16>(arg,std::get<14>(arg[0]).spardigs_t<16>::operator-(std::get<14>(arg[1])));
		}
	}

	void hacer_oper_times(sllint base,contenedor_1d_t& arg) {
		switch(base-2) {
			case 0: assign<2>(arg,std::get<0>(arg[0]).spardigs_t<2>::operator*(std::get<0>(arg[1])));break;
			case 1: assign<3>(arg,std::get<1>(arg[0]).spardigs_t<3>::operator*(std::get<1>(arg[1])));break;
			case 2: assign<4>(arg,std::get<2>(arg[0]).spardigs_t<4>::operator*(std::get<2>(arg[1])));break;
			case 3: assign<5>(arg,std::get<3>(arg[0]).spardigs_t<5>::operator*(std::get<3>(arg[1])));break;
			case 4: assign<6>(arg,std::get<4>(arg[0]).spardigs_t<6>::operator*(std::get<4>(arg[1])));break;
			case 5: assign<7>(arg,std::get<5>(arg[0]).spardigs_t<7>::operator*(std::get<5>(arg[1])));break;
			case 6: assign<8>(arg,std::get<6>(arg[0]).spardigs_t<8>::operator*(std::get<6>(arg[1])));break;
			case 7: assign<9>(arg,std::get<7>(arg[0]).spardigs_t<9>::operator*(std::get<7>(arg[1])));break;
			case 8: assign<10>(arg,std::get<8>(arg[0]).spardigs_t<10>::operator*(std::get<8>(arg[1])));break;
			case 9: assign<11>(arg,std::get<9>(arg[0]).spardigs_t<11>::operator*(std::get<9>(arg[1])));break;
			case 10: assign<12>(arg,std::get<10>(arg[0]).spardigs_t<12>::operator*(std::get<10>(arg[1])));break;
			case 11: assign<13>(arg,std::get<11>(arg[0]).spardigs_t<13>::operator*(std::get<11>(arg[1])));break;
			case 12: assign<14>(arg,std::get<12>(arg[0]).spardigs_t<14>::operator*(std::get<12>(arg[1])));break;
			case 13: assign<15>(arg,std::get<13>(arg[0]).spardigs_t<15>::operator*(std::get<13>(arg[1])));break;
			case 14: assign<16>(arg,std::get<14>(arg[0]).spardigs_t<16>::operator*(std::get<14>(arg[1])));break;
			default: assign<16>(arg,std::get<14>(arg[0]).spardigs_t<16>::operator*(std::get<14>(arg[1])));
		}
	}

	void hacer_oper_div(sllint base,contenedor_1d_t& arg) {
		switch(base-2) {
			case 0: assign<2>(arg,std::get<0>(arg[0]).spardigs_t<2>::operator/(std::get<0>(arg[1])));break;
			case 1: assign<3>(arg,std::get<1>(arg[0]).spardigs_t<3>::operator/(std::get<1>(arg[1])));break;
			case 2: assign<4>(arg,std::get<2>(arg[0]).spardigs_t<4>::operator/(std::get<2>(arg[1])));break;
			case 3: assign<5>(arg,std::get<3>(arg[0]).spardigs_t<5>::operator/(std::get<3>(arg[1])));break;
			case 4: assign<6>(arg,std::get<4>(arg[0]).spardigs_t<6>::operator/(std::get<4>(arg[1])));break;
			case 5: assign<7>(arg,std::get<5>(arg[0]).spardigs_t<7>::operator/(std::get<5>(arg[1])));break;
			case 6: assign<8>(arg,std::get<6>(arg[0]).spardigs_t<8>::operator/(std::get<6>(arg[1])));break;
			case 7: assign<9>(arg,std::get<7>(arg[0]).spardigs_t<9>::operator/(std::get<7>(arg[1])));break;
			case 8: assign<10>(arg,std::get<8>(arg[0]).spardigs_t<10>::operator/(std::get<8>(arg[1])));break;
			case 9: assign<11>(arg,std::get<9>(arg[0]).spardigs_t<11>::operator/(std::get<9>(arg[1])));break;
			case 10: assign<12>(arg,std::get<10>(arg[0]).spardigs_t<12>::operator/(std::get<10>(arg[1])));break;
			case 11: assign<13>(arg,std::get<11>(arg[0]).spardigs_t<13>::operator/(std::get<11>(arg[1])));break;
			case 12: assign<14>(arg,std::get<12>(arg[0]).spardigs_t<14>::operator/(std::get<12>(arg[1])));break;
			case 13: assign<15>(arg,std::get<13>(arg[0]).spardigs_t<15>::operator/(std::get<13>(arg[1])));break;
			case 14: assign<16>(arg,std::get<14>(arg[0]).spardigs_t<16>::operator/(std::get<14>(arg[1])));break;
			default: assign<16>(arg,std::get<14>(arg[0]).spardigs_t<16>::operator/(std::get<14>(arg[1])));
		}
	}

	void hacer_oper_rem(sllint base,contenedor_1d_t& arg) {
		switch(base-2) {
			case 0: assign<2>(arg,std::get<0>(arg[0]).spardigs_t<2>::operator%(std::get<0>(arg[1])));break;
			case 1: assign<3>(arg,std::get<1>(arg[0]).spardigs_t<3>::operator%(std::get<1>(arg[1])));break;
			case 2: assign<4>(arg,std::get<2>(arg[0]).spardigs_t<4>::operator%(std::get<2>(arg[1])));break;
			case 3: assign<5>(arg,std::get<3>(arg[0]).spardigs_t<5>::operator%(std::get<3>(arg[1])));break;
			case 4: assign<6>(arg,std::get<4>(arg[0]).spardigs_t<6>::operator%(std::get<4>(arg[1])));break;
			case 5: assign<7>(arg,std::get<5>(arg[0]).spardigs_t<7>::operator%(std::get<5>(arg[1])));break;
			case 6: assign<8>(arg,std::get<6>(arg[0]).spardigs_t<8>::operator%(std::get<6>(arg[1])));break;
			case 7: assign<9>(arg,std::get<7>(arg[0]).spardigs_t<9>::operator%(std::get<7>(arg[1])));break;
			case 8: assign<10>(arg,std::get<8>(arg[0]).spardigs_t<10>::operator%(std::get<8>(arg[1])));break;
			case 9: assign<11>(arg,std::get<9>(arg[0]).spardigs_t<11>::operator%(std::get<9>(arg[1])));break;
			case 10: assign<12>(arg,std::get<10>(arg[0]).spardigs_t<12>::operator%(std::get<10>(arg[1])));break;
			case 11: assign<13>(arg,std::get<11>(arg[0]).spardigs_t<13>::operator%(std::get<11>(arg[1])));break;
			case 12: assign<14>(arg,std::get<12>(arg[0]).spardigs_t<14>::operator%(std::get<12>(arg[1])));break;
			case 13: assign<15>(arg,std::get<13>(arg[0]).spardigs_t<15>::operator%(std::get<13>(arg[1])));break;
			case 14: assign<16>(arg,std::get<14>(arg[0]).spardigs_t<16>::operator%(std::get<14>(arg[1])));break;
			default: assign<16>(arg,std::get<14>(arg[0]).spardigs_t<16>::operator%(std::get<14>(arg[1])));
		}
	}

	void hacer_operacion(sllint base,contenedor_1d_t& arg,char oper){
		switch(oper) {
			case '+': hacer_oper_plus(base,arg);break;
			case '-': hacer_oper_minus(base,arg);break;
			case '*': hacer_oper_times(base,arg);break;
			case '/': hacer_oper_div(base,arg);break;
			case '%': hacer_oper_rem(base,arg);break;
			default : hacer_oper_plus(base,arg);
		}
	}

	template<const uint caso,const sllint beginoffset>
	void saca_linea(const contenedor_1d_t& arg,char operacion){
		std::cout << std::get<caso>(arg[beginoffset]);
		std::cout << operacion << std::get<caso>(arg[beginoffset+1]);
		std::cout << " = " << std::get<caso>(arg[beginoffset+2]);
		std::cout << std::endl;
	}

	void sacar_operacion(sllint base,const contenedor_1d_t& arg,char operacion) {
		switch(base-2) {
			case 0:saca_linea<0,0>(arg,operacion);break;
			case 1:saca_linea<1,0>(arg,operacion);break;
			case 2:saca_linea<2,0>(arg,operacion);break;
			case 3:saca_linea<3,0>(arg,operacion);break;
			case 4:saca_linea<4,0>(arg,operacion);break;
			case 5:saca_linea<5,0>(arg,operacion);break;
			case 6:saca_linea<6,0>(arg,operacion);break;
			case 7:saca_linea<7,0>(arg,operacion);break;
			case 8:saca_linea<8,0>(arg,operacion);break;
			case 9:saca_linea<9,0>(arg,operacion);break;
			case 10:saca_linea<10,0>(arg,operacion);break;
			case 11:saca_linea<11,0>(arg,operacion);break;
			case 12:saca_linea<12,0>(arg,operacion);break;
			case 13:saca_linea<13,0>(arg,operacion);break;
			case 14:saca_linea<14,0>(arg,operacion);break;
			default:saca_linea<14,0>(arg,operacion);
		}
	}

	void pinta(contenedor_1d_t& N, sllint base,sllint indice){
		switch(base-2) {
			case  0: std::cout << get<0>(N[indice]);break;
			case  1: std::cout << get<1>(N[indice]);break;
			case  2: std::cout << get<2>(N[indice]);break;
			case  3: std::cout << get<3>(N[indice]);break;
			case  4: std::cout << get<4>(N[indice]);break;
			case  5: std::cout << get<5>(N[indice]);break;
			case  6: std::cout << get<6>(N[indice]);break;
			case  7: std::cout << get<7>(N[indice]);break;
			case  8: std::cout << get<8>(N[indice]);break;
			case  9: std::cout << get<9>(N[indice]);break;
			case 10: std::cout << get<10>(N[indice]);break;
			case 11: std::cout << get<11>(N[indice]);break;
			case 12: std::cout << get<12>(N[indice]);break;
			case 13: std::cout << get<13>(N[indice]);break;
			case 14: std::cout << get<14>(N[indice]);break;
			default: std::cout << get<14>(N[indice]);break;
		}
	}

	void PROBAR() {
		arreglo_2d_t Num_B;
		contenedor_1d_t N;
		char Q=0;
		do {
			std::cout << "   Dame una primera Base entre 2 y 16 inclusivas		";
			sllint B1 = 0;
			while ((B1<2) || (B1>16)) {
				std::cin  >> B1 ;
			}
			std::cout << "   Dame un numero para que lo ponga en la base " << B1;
			std::cout << " que este entre " << Begin(B1);
			std::cout << " y " << End(B1);
			std::cout << " incluyendo los limites." << std::endl;
			Num_B[B1-2][0] = B1*B1*B1;
			while((Num_B[B1-2][0]<Begin(B1)) || (Num_B[B1-2][0]>End(B1))){
				std::cin  >> Num_B[B1-2][0];
			}
			assign(B1,N,Num_B,0);
			std::cout << "   Dame otro numero para que lo ponga en la base " << B1;
			std::cout << " que este entre " << Begin(B1);
			std::cout << " y " << End(B1);
			std::cout << " incluyendo los limites." << std::endl;
			Num_B[B1-2][1] = B1*B1*B1;
			while(Num_B[B1-2][1]<Begin(B1) || Num_B[B1-2][1]>End(B1)){
				std::cin  >> Num_B[B1-2][1];
			}
			assign(B1,N,Num_B,1);
			std::cout << "    Dame una segunda Base B	(entre 2 y 16) distinta de " << B1 << "  ";
			sllint B2 = 0;
			while ((B2<2) || (B2>16) || (B2==B1)) {
				std::cin  >> B2;
			}
			std::cout << "   Dame un numero para la segunda base " << B2 << " ";
			std::cout << " que este entre " << Begin(B2);
			std::cout << " y " << End(B2);
			std::cout << " incluyendo los limites " << std::endl;
			Num_B[B2-2][0] = B2*B2*B2;
			while((Num_B[B2-2][0]<Begin(B2))||(Num_B[B2-2][0]>End(B2))){
				std::cin  >> Num_B[B2-2][0];
			}
			assign(B2,N,Num_B,0);
			std::cout << "   Dame otro numero para que lo ponga en la base " << B2;
			std::cout << " que este entre " << Begin(B2);
			std::cout << " y " << End(B2);
			std::cout << " incluyendo los limites. " << std::endl;
			Num_B[B2-2][1] = B2*B2*B2;
			while((Num_B[B2-2][1]<Begin(B2)) || (Num_B[B2-2][1]>End(B2))){
				std::cin  >> Num_B[B2-2][1];
			}
			assign(B2,N,Num_B,1);
			std::cout << " Teclea +,-,*./,% para elegir operacion ";
			char operacion = 0;
			while(
				(operacion!='+')&&
				(operacion!='-')&&
				(operacion!='*')&&
				(operacion!='/')&&
				(operacion!='%')
			){
				std::cin >> operacion;
			}
			hacer_operacion(B1,N,operacion);
			hacer_operacion(B2,N,operacion);
			std::cout << " La operacion elegida es " << operacion << std::endl;
			sacar_operacion(B1,N,operacion);
			sacar_operacion(B2,N,operacion);
//			std::cout << " La conversion de base " << B1 << " a base " << B2;
//			std::cout << "se muestra a continuacion:" << std::endl;
//			Cambio_de_Base_de(N,B1,B2);
//			pinta(N,B1,0); std::cout << " == "; pinta(N,B2,3); std::cout << std::endl;
//			std::cout << Num_B[B1-2][0] << " == " << Num_B[B2-2][3] << std::endl;
//			pinta(N,B1,1); std::cout << " == "; pinta(N,B2,4); std::cout << std::endl;
//			std::cout << Num_B[B1-2][1] << " == " << Num_B[B2-2][4] << std::endl;
//			pinta(N,B1,2); std::cout << " == "; pinta(N,B2,5); std::cout << std::endl;
//			std::cout << Num_B[B1-2][2] << " == " << Num_B[B2-2][5] << std::endl;
//			std::cout << " La conversion de base " << B2 << " a base " << B1;
//			std::cout << "se muestra a continuacion:" << std::endl;
//			Cambio_de_Base_de(N,B2,B1);
//			pinta(N,B2,0); std::cout << " == "; pinta(N,B1,3); std::cout << std::endl;
//			std::cout << Num_B[B2-2][0] << " == " << Num_B[B1-2][3] << std::endl;
//			pinta(N,B2,1); std::cout << " == "; pinta(N,B1,4); std::cout << std::endl;
//			std::cout << Num_B[B2-2][1] << " == " << Num_B[B1-2][4] << std::endl;
//			pinta(N,B2,2); std::cout << " == "; pinta(N,B1,5); std::cout << std::endl;
//			std::cout << Num_B[B2-2][2] << " == " << Num_B[B1-2][5] << std::endl;
			std::cout << "_________________________________________";
			std::cout << "Quieres hacer mas pruebas?" << std::endl;

			while ((Q!='S')&&(Q!='s')&&(Q!='n')&&(Q!='N')) {
				std::cin >> Q;
			}
		} while((Q=='s')||(Q=='S'));

	}


#endif //PRESENTACION__HPP
