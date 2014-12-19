
#include "presentacion.hpp"

	template<const uchint base>
	sllint Begin() {
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


	template<const uchint base>
	sllint End() {
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

	template<const uchint base>
	void assign(contenedor_t arg[6],sllint Number[6][14],sllint dir) {
		switch(base-2) {
			case  0:std::get<0>(arg[dir]).spardigs_t<2>::operator=(sllint(Number[dir][base-2]));
			case  1:std::get<1>(arg[dir]).spardigs_t<3>::operator=(sllint(Number[dir][base-2]));
			case  2:std::get<2>(arg[dir]).spardigs_t<4>::operator=(sllint(Number[dir][base-2]));
			case  3:std::get<3>(arg[dir]).spardigs_t<5>::operator=(sllint(Number[dir][base-2]));
			case  4:std::get<4>(arg[dir]).spardigs_t<6>::operator=(sllint(Number[dir][base-2]));
			case  5:std::get<5>(arg[dir]).spardigs_t<7>::operator=(sllint(Number[dir][base-2]));
			case  6:std::get<6>(arg[dir]).spardigs_t<8>::operator=(sllint(Number[dir][base-2]));
			case  7:std::get<7>(arg[dir]).spardigs_t<9>::operator=(sllint(Number[dir][base-2]));
			case  8:std::get<8>(arg[dir]).spardigs_t<10>::operator=(sllint(Number[dir][base-2]));
			case  9:std::get<9>(arg[dir]).spardigs_t<11>::operator=(sllint(Number[dir][base-2]));
			case 10:std::get<10>(arg[dir]).spardigs_t<12>::operator=(sllint(Number[dir][base-2]));
			case 11:std::get<11>(arg[dir]).spardigs_t<13>::operator=(sllint(Number[dir][base-2]));
			case 12:std::get<12>(arg[dir]).spardigs_t<14>::operator=(sllint(Number[dir][base-2]));
			case 13:std::get<13>(arg[dir]).spardigs_t<15>::operator=(sllint(Number[dir][base-2]));
			case 14:std::get<14>(arg[dir]).spardigs_t<16>::operator=(sllint(Number[dir][base-2]));
			default:std::get<14>(arg[dir]).spardigs_t<16>::operator=(sllint(Number[dir][base-2]));
		}
	}
	
	template<const uchint base>
	void assign(contenedor_t arg[6],spardigs_t<base> otro) {
		switch(base-2) {
			case  0:std::get<0>(arg[3])=otro;
			case  1:std::get<1>(arg[3])=otro;
			case  2:std::get<2>(arg[3])=otro;
			case  3:std::get<3>(arg[3])=otro;
			case  4:std::get<4>(arg[3])=otro;
			case  5:std::get<5>(arg[3])=otro;
			case  6:std::get<6>(arg[3])=otro;
			case  7:std::get<7>(arg[3])=otro;
			case  8:std::get<8>(arg[3])=otro;
			case  9:std::get<9>(arg[3])=otro;
			case 10:std::get<10>(arg[3])=otro;
			case 11:std::get<11>(arg[3])=otro;
			case 12:std::get<12>(arg[3])=otro;
			case 13:std::get<13>(arg[3])=otro;
			case 14:std::get<14>(arg[3])=otro;
			default:std::get<14>(arg[3])=otro;
		}
	}
	
	void hacer_oper_plus(sllint base,contenedor_t arg[6]) {
		switch(base-2) {
			case 0: assign(arg,std::get<0>(arg[1]).spardigs_t<2>::operator+(std::get<0>(arg[2])));break;
			case 1: assign(arg,std::get<1>(arg[1]).spardigs_t<3>::operator+(std::get<1>(arg[2])));break;
			case 2: assign(arg,std::get<2>(arg[1]).spardigs_t<4>::operator+(std::get<2>(arg[2])));break;
			case 3: assign(arg,std::get<3>(arg[1]).spardigs_t<5>::operator+(std::get<3>(arg[2])));break;
			case 4: assign(arg,std::get<4>(arg[1]).spardigs_t<6>::operator+(std::get<4>(arg[2])));break;
			case 5: assign(arg,std::get<5>(arg[1]).spardigs_t<7>::operator+(std::get<5>(arg[2])));break;
			case 6: assign(arg,std::get<6>(arg[1]).spardigs_t<8>::operator+(std::get<6>(arg[2])));break;
			case 7: assign(arg,std::get<7>(arg[1]).spardigs_t<9>::operator+(std::get<7>(arg[2])));break;
			case 8: assign(arg,std::get<8>(arg[1]).spardigs_t<10>::operator+(std::get<8>(arg[2])));break;
			case 9: assign(arg,std::get<9>(arg[1]).spardigs_t<11>::operator+(std::get<9>(arg[2])));break;
			case 10: assign(arg,std::get<10>(arg[1]).spardigs_t<12>::operator+(std::get<10>(arg[2])));break;
			case 11: assign(arg,std::get<11>(arg[1]).spardigs_t<13>::operator+(std::get<11>(arg[2])));break;
			case 12: assign(arg,std::get<12>(arg[1]).spardigs_t<14>::operator+(std::get<12>(arg[2])));break;
			case 13: assign(arg,std::get<13>(arg[1]).spardigs_t<15>::operator+(std::get<13>(arg[2])));break;
			case 14: assign(arg,std::get<14>(arg[1]).spardigs_t<16>::operator+(std::get<14>(arg[2])));break;
			default: assign(arg,std::get<14>(arg[1]).spardigs_t<16>::operator+(std::get<14>(arg[2])));
		}
	}
	
	void hacer_oper_minus(sllint base,contenedor_t arg[6]) {
		switch(base-2) {
			case 0: assign<2>(arg,std::get<0>(arg[1]).spardigs_t<2>::operator-(std::get<0>(arg[2])));
			case 1: assign<3>(arg,std::get<1>(arg[1]).spardigs_t<3>::operator-(std::get<1>(arg[2])));
			case 2: assign<4>(arg,std::get<2>(arg[1]).spardigs_t<4>::operator-(std::get<2>(arg[2])));
			case 3: assign<5>(arg,std::get<3>(arg[1]).spardigs_t<5>::operator-(std::get<3>(arg[2])));
			case 4: assign<6>(arg,std::get<4>(arg[1]).spardigs_t<6>::operator-(std::get<4>(arg[2])));
			case 5: assign<7>(arg,std::get<5>(arg[1]).spardigs_t<7>::operator-(std::get<5>(arg[2])));
			case 6: assign<8>(arg,std::get<6>(arg[1]).spardigs_t<8>::operator-(std::get<6>(arg[2])));
			case 7: assign<9>(arg,std::get<7>(arg[1]).spardigs_t<9>::operator-(std::get<7>(arg[2])));
			case 8: assign<10>(arg,std::get<8>(arg[1]).spardigs_t<10>::operator-(std::get<8>(arg[2])));
			case 9: assign<11>(arg,std::get<9>(arg[1]).spardigs_t<11>::operator-(std::get<9>(arg[2])));
			case 10: assign<12>(arg,std::get<10>(arg[1]).spardigs_t<12>::operator-(std::get<10>(arg[2])));
			case 11: assign<13>(arg,std::get<11>(arg[1]).spardigs_t<13>::operator-(std::get<11>(arg[2])));
			case 12: assign<14>(arg,std::get<12>(arg[1]).spardigs_t<14>::operator-(std::get<12>(arg[2])));
			case 13: assign<15>(arg,std::get<13>(arg[1]).spardigs_t<15>::operator-(std::get<13>(arg[2])));
			case 14: assign<16>(arg,std::get<14>(arg[1]).spardigs_t<16>::operator-(std::get<14>(arg[2])));
			default: assign<16>(arg,std::get<14>(arg[1]).spardigs_t<16>::operator-(std::get<14>(arg[2])));
		}
	}
	
	void hacer_oper_times(sllint base,contenedor_t arg[6]) {
		switch(base-2) {
			case 0: assign<2>(arg,std::get<0>(arg[1]).spardigs_t<2>::operator*(std::get<0>(arg[2])));
			case 1: assign<3>(arg,std::get<1>(arg[1]).spardigs_t<3>::operator*(std::get<1>(arg[2])));
			case 2: assign<4>(arg,std::get<2>(arg[1]).spardigs_t<4>::operator*(std::get<2>(arg[2])));
			case 3: assign<5>(arg,std::get<3>(arg[1]).spardigs_t<5>::operator*(std::get<3>(arg[2])));
			case 4: assign<6>(arg,std::get<4>(arg[1]).spardigs_t<6>::operator*(std::get<4>(arg[2])));
			case 5: assign<7>(arg,std::get<5>(arg[1]).spardigs_t<7>::operator*(std::get<5>(arg[2])));
			case 6: assign<8>(arg,std::get<6>(arg[1]).spardigs_t<8>::operator*(std::get<6>(arg[2])));
			case 7: assign<9>(arg,std::get<7>(arg[1]).spardigs_t<9>::operator*(std::get<7>(arg[2])));
			case 8: assign<10>(arg,std::get<8>(arg[1]).spardigs_t<10>::operator*(std::get<8>(arg[2])));
			case 9: assign<11>(arg,std::get<9>(arg[1]).spardigs_t<11>::operator*(std::get<9>(arg[2])));
			case 10: assign<12>(arg,std::get<10>(arg[1]).spardigs_t<12>::operator*(std::get<10>(arg[2])));
			case 11: assign<13>(arg,std::get<11>(arg[1]).spardigs_t<13>::operator*(std::get<11>(arg[2])));
			case 12: assign<14>(arg,std::get<12>(arg[1]).spardigs_t<14>::operator*(std::get<12>(arg[2])));
			case 13: assign<15>(arg,std::get<13>(arg[1]).spardigs_t<15>::operator*(std::get<13>(arg[2])));
			case 14: assign<16>(arg,std::get<14>(arg[1]).spardigs_t<16>::operator*(std::get<14>(arg[2])));
			default: assign<16>(arg,std::get<14>(arg[1]).spardigs_t<16>::operator*(std::get<14>(arg[2])));
		}
	}
	
	void hacer_oper_div(sllint base,contenedor_t arg[6]) {
		switch(base-2) {
			case 0: assign<2>(arg,std::get<0>(arg[1]).spardigs_t<2>::operator/(std::get<0>(arg[2])));
			case 1: assign<3>(arg,std::get<1>(arg[1]).spardigs_t<3>::operator/(std::get<1>(arg[2])));
			case 2: assign<4>(arg,std::get<2>(arg[1]).spardigs_t<4>::operator/(std::get<2>(arg[2])));
			case 3: assign<5>(arg,std::get<3>(arg[1]).spardigs_t<5>::operator/(std::get<3>(arg[2])));
			case 4: assign<6>(arg,std::get<4>(arg[1]).spardigs_t<6>::operator/(std::get<4>(arg[2])));
			case 5: assign<7>(arg,std::get<5>(arg[1]).spardigs_t<7>::operator/(std::get<5>(arg[2])));
			case 6: assign<8>(arg,std::get<6>(arg[1]).spardigs_t<8>::operator/(std::get<6>(arg[2])));
			case 7: assign<9>(arg,std::get<7>(arg[1]).spardigs_t<9>::operator/(std::get<7>(arg[2])));
			case 8: assign<10>(arg,std::get<8>(arg[1]).spardigs_t<10>::operator/(std::get<8>(arg[2])));
			case 9: assign<11>(arg,std::get<9>(arg[1]).spardigs_t<11>::operator/(std::get<9>(arg[2])));
			case 10: assign<12>(arg,std::get<10>(arg[1]).spardigs_t<12>::operator/(std::get<10>(arg[2])));
			case 11: assign<13>(arg,std::get<11>(arg[1]).spardigs_t<13>::operator/(std::get<11>(arg[2])));
			case 12: assign<14>(arg,std::get<12>(arg[1]).spardigs_t<14>::operator/(std::get<12>(arg[2])));
			case 13: assign<15>(arg,std::get<13>(arg[1]).spardigs_t<15>::operator/(std::get<13>(arg[2])));
			case 14: assign<16>(arg,std::get<14>(arg[1]).spardigs_t<16>::operator/(std::get<14>(arg[2])));
			default: assign<16>(arg,std::get<14>(arg[1]).spardigs_t<16>::operator/(std::get<14>(arg[2])));
		}
	}
	
	void hacer_oper_rem(sllint base,contenedor_t arg[6]) {
		switch(base-2) {
			case 0: assign<2>(arg,std::get<0>(arg[1]).spardigs_t<2>::operator%(std::get<0>(arg[2])));
			case 1: assign<3>(arg,std::get<1>(arg[1]).spardigs_t<3>::operator%(std::get<1>(arg[2])));
			case 2: assign<4>(arg,std::get<2>(arg[1]).spardigs_t<4>::operator%(std::get<2>(arg[2])));
			case 3: assign<5>(arg,std::get<3>(arg[1]).spardigs_t<5>::operator%(std::get<3>(arg[2])));
			case 4: assign<6>(arg,std::get<4>(arg[1]).spardigs_t<6>::operator%(std::get<4>(arg[2])));
			case 5: assign<7>(arg,std::get<5>(arg[1]).spardigs_t<7>::operator%(std::get<5>(arg[2])));
			case 6: assign<8>(arg,std::get<6>(arg[1]).spardigs_t<8>::operator%(std::get<6>(arg[2])));
			case 7: assign<9>(arg,std::get<7>(arg[1]).spardigs_t<9>::operator%(std::get<7>(arg[2])));
			case 8: assign<10>(arg,std::get<8>(arg[1]).spardigs_t<10>::operator%(std::get<8>(arg[2])));
			case 9: assign<11>(arg,std::get<9>(arg[1]).spardigs_t<11>::operator%(std::get<9>(arg[2])));
			case 10: assign<12>(arg,std::get<10>(arg[1]).spardigs_t<12>::operator%(std::get<10>(arg[2])));
			case 11: assign<13>(arg,std::get<11>(arg[1]).spardigs_t<13>::operator%(std::get<11>(arg[2])));
			case 12: assign<14>(arg,std::get<12>(arg[1]).spardigs_t<14>::operator%(std::get<12>(arg[2])));
			case 13: assign<15>(arg,std::get<13>(arg[1]).spardigs_t<15>::operator%(std::get<13>(arg[2])));
			case 14: assign<16>(arg,std::get<14>(arg[1]).spardigs_t<16>::operator%(std::get<14>(arg[2])));
			default: assign<16>(arg,std::get<14>(arg[1]).spardigs_t<16>::operator%(std::get<14>(arg[2])));
		}
	}
	
	void hacer_oper(sllint base,contenedor_t arg[6],char oper){
		switch(oper) {
			case '+': hacer_oper_plus(base,arg);break;
			case '-': hacer_oper_minus(base,arg);break;
			case '*': hacer_oper_times(base,arg);break;
			case '/': hacer_oper_div(base,arg);break;
			case '%': hacer_oper_rem(base,arg);break;
			default : hacer_oper_plus(base,arg);
		}
	}
	
	void sacar_oper(sllint base,contenedor_t arg[6],char operacion) {
		switch(base) {
			case 0:{std::cout << std::get<0>(arg[1]) << operacion << std::get<0>(arg[2]) << " = " << std::get<0>(arg[3]) << std::endl;}break;
			case 1:{std::cout << std::get<1>(arg[1]) << operacion << std::get<1>(arg[2]) << " = " << std::get<1>(arg[3]) << std::endl;}break;
			case 2:{std::cout << std::get<2>(arg[1]) << operacion << std::get<2>(arg[2]) << " = " << std::get<2>(arg[3]) << std::endl;}break;
			case 3:{std::cout << std::get<3>(arg[1]) << operacion << std::get<3>(arg[2]) << " = " << std::get<3>(arg[3]) << std::endl;}break;
			case 4:{std::cout << std::get<4>(arg[1]) << operacion << std::get<4>(arg[2]) << " = " << std::get<4>(arg[3]) << std::endl;}break;
			case 5:{std::cout << std::get<5>(arg[1]) << operacion << std::get<5>(arg[2]) << " = " << std::get<5>(arg[3]) << std::endl;}break;
			case 6:{std::cout << std::get<6>(arg[1]) << operacion << std::get<6>(arg[2]) << " = " << std::get<6>(arg[3]) << std::endl;}break;
			case 7:{std::cout << std::get<7>(arg[1]) << operacion << std::get<7>(arg[2]) << " = " << std::get<7>(arg[3]) << std::endl;}break;
			case 8:{std::cout << std::get<8>(arg[1]) << operacion << std::get<8>(arg[2]) << " = " << std::get<8>(arg[3]) << std::endl;}break;
			case 9:{std::cout << std::get<9>(arg[1]) << operacion << std::get<9>(arg[2]) << " = " << std::get<9>(arg[3]) << std::endl;}break;
			case 10:{std::cout << std::get<10>(arg[1]) << operacion << std::get<10>(arg[2]) << " = " << std::get<10>(arg[3]) << std::endl;}break;
			case 11:{std::cout << std::get<11>(arg[1]) << operacion << std::get<11>(arg[2]) << " = " << std::get<11>(arg[3]) << std::endl;}break;
			case 12:{std::cout << std::get<12>(arg[1]) << operacion << std::get<12>(arg[2]) << " = " << std::get<12>(arg[3]) << std::endl;}break;
			case 13:{std::cout << std::get<13>(arg[1]) << operacion << std::get<13>(arg[2]) << " = " << std::get<13>(arg[3]) << std::endl;}break;
			case 14:{std::cout << std::get<14>(arg[1]) << operacion << std::get<14>(arg[2]) << " = " << std::get<14>(arg[3]) << std::endl;}break;
			default:{std::cout << std::get<14>(arg[1]) << operacion << std::get<14>(arg[2]) << " = " << std::get<14>(arg[3]) << std::endl;}
		}
	}
	
	void PROBAR() {
		sllint Num_B[6][14];
		contenedor_t N[6];
		char Q=0;
		do {
			std::cout << "Dame una primera Base entre 2 y 16 inclusivas		";
			sllint B1 = 0;
			while ((B1<2) && (B1>16)) {
				std::cin  >> B1 ;
			}
			std::cout << "Dame un número para que lo ponga en la base " << B1; 
			std::cout << " que esté entre " << Begin(B1);
			std::cout << " y " << End(B1);
			std::cout << " incluyendo los limites." << std::endl;
			Num_B[1][B1-2] = B1*B1*B1;
			while((Num_B[1][B1-2]<Begin(B1)) || (Num_B[1][B1-2]>End(B1))){
				std::cin  >> Num_B[1][B1-2];
			}
			assign(B1,N,Num_B,1);
			std::cout << "Dame otro número para que lo ponga en la base " << B1;
			std::cout << " que esté entre " << Begin(B1);
			std::cout << " y " << End(B1);
			std::cout << " incluyendo los limites." << std::endl;
			Num_B[2][B1-2] = B1*B1*B1;
			while(Num_B[2][B1-2]<Begin(B1) || Num_B[2][B1-2]>End(B1)){
				std::cin  >> Num_B[2][B1-2];
			}
			assign(B1,N,Num_B,2);
			std::cout << "Dame una segunda Base B	(entre 2 y 16) distinta de " << B1 << "  ";
			sllint B2 = 0;
			while ((B2<2) && (B2>16) && (B2==B1)) {
				std::cin  >> B2;
			}
			std::cout << "Dame un número para la segunda base " << B2 << " ";
			std::cout << " que esté entre " << Begin(B1);
			std::cout << " y " << End(B1);
			std::cout << " incluyendo los limites " << std::endl;
			Num_B[1][B2-2] = B2*B2*B2;
			while(Num_B[1][B2-2]<Begin(B2) || Num_B[1][B2-2]>End(B2)){
				std::cin  >> Num_B[1][B2-2];
			}
			assign(B2,N,Num_B,1);
			std::cout << "Dame otro número para que lo ponga en la base " << B2; 
			std::cout << " que esté entre " << Begin(B2);
			std::cout << " y " << End(B2);
			std::cout << " incluyendo los limites." << std::endl;
			Num_B[2][B2-2] = B2*B2*B2;
			while(Num_B[2][B2-2]<Begin(B2) || Num_B[2][B2-2]>End(B2)){
				std::cin  >> Num_B[2][B2-2];
			}
			assign(B2,N,Num_B,2);
			std::cout << " Teclea +,-,*./,% para elegir operacion ";
			char operacion = 0;
			while(
					(operacion!='+')&&
					(operacion!='-')&&
					(operacion!='*')&&
					(operacion!='/')&&
					(operacion!='%')	) 
			{std::cin >> operacion;}
			hacer_oper(B1,N,operacion);
			hacer_oper(B2,N,operacion);
			std::cout << "La operacion elegida es " << operacion << std::endl;
			sacar_oper(B1,N);
			sacar_oper(B2,N);
//			std::cout << " La conversion de base " << B1 << " a base " << B2;
//			std::cout << "se muestra a continuación:" << std::endl;
//			Num4_B2 = spardigs_t<B2>(Num1_B1);
//			Num5_B2 = spardigs_t<B2>(Num2_B1);
//			Num6_B2 = spardigs_t<B2>(Num3_B1);
//			std::cout << Num1_B1 << " == " << Num4_B2 << std::endl;
//			std::cout << Num2_B1 << " == " << Num5_B2 << std::endl;
//			std::cout << Num3_B1 << " == " << Num6_B2 << std::endl;
//			std::cout << " La conversion de base " << B2 << " a base " << B1;
//			std::cout << "se muestra a continuación:" << std::endl;
//			Num4_B1 = spardigs_t<B1>(Num1_B2);
//			Num5_B1 = spardigs_t<B1>(Num2_B2);
//			Num6_B1 = spardigs_t<B1>(Num3_B2);
//			std::cout << Num1_B2 << " == " << Num4_B1 << std::endl;
//			std::cout << Num2_B2 << " == " << Num5_B1 << std::endl;
//			std::cout << Num3_B2 << " == " << Num6_B1 << std::endl;
			std::cout << "_________________________________________";
			std::cout << "¿Quieres hacer mas pruebas?" << std::endl;
			
			while ((Q!='S')&&(Q!='s')&&(Q!='n')&&(Q!='N')) {
				std::cin >> Q;
			}
		} while((Q=='s')||(Q=='S'));

	}