#ifndef TEST_DIG_T_HPP_INCLUDED
#define TEST_DIG_T_HPP_INCLUDED

#include "pardigs_t.hpp"

namespace NumRepr {

template<type_traits::allowable_base_type_c UINT_T,UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_constr_UINT_dig_t(){
	using base_B_dig_t = dig_t<UINT_T,B>;
	ullint k{0};
	for (ullint i{0} ; i<1030 ; ++i) {
		base_B_dig_t unidades(i);
		if ((k%static_cast<ullint>(B))!=static_cast<ullint>(B-1)) {
			std::cout << k << "->" << unidades << ";";
		}
		else {
			std::cout << k << "->" << unidades << "|" << std::endl;
		}
		++k;
	}
	std::cout << std::endl;
}

template<type_traits::allowable_base_type_c UINT_T,UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_constr_SINT_dig_t(){
	using base_B_dig_t = dig_t<UINT_T,B>;
	sllint k{-1000}; sllint kold{0};
	for (sllint i{-1030} ; i<1030 ; ++i) {
		base_B_dig_t unidades(i);
		if ((k%static_cast<sllint>(B))!=static_cast<sllint>(B-1)) {
			if ((k%static_cast<sllint>(B))==0) {
				std::cout << k << "->" << unidades << ";";
			}
			else {
				std::cout << k << "->" << unidades << ";";
			}
		}
		else {
			std::cout << kold << "->" << unidades << "|" << std::endl;
		}
		++k;
	}
	std::cout << std::endl;
}

template<type_traits::allowable_base_type_c UINT_T,UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_constr_defecto_dig_t(){
	using base_B_dig_t = dig_t<UINT_T,B>;
	base_B_dig_t unidades_parentesis=base_B_dig_t();
	std::cout << "unidades llamadas con parentesis vacios : "
						<< unidades_parentesis << std::endl;
	base_B_dig_t unidades_llaves{};
	std::cout << "unidades llamadas con llaves vacias : "
						<< unidades_llaves << std::endl;
	base_B_dig_t unidades;
	std::cout << "unidades llamadas sin inicializacion aparente : "
						<< unidades << std::endl;
}

template<type_traits::allowable_base_type_c UINT_T,UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_constr_copia_dig_t(){
	using base_B_dig_t = dig_t<UINT_T,B>;
	{
		base_B_dig_t unidades(static_cast<UINT_T>((B/2)+1));
		base_B_dig_t unidades_copiadas(unidades);
		std::cout << unidades << " =?= " << unidades_copiadas << std::endl;
	}
	{
		base_B_dig_t unidades{static_cast<UINT_T>((B/2)+1)};
		base_B_dig_t unidades_copiadas(unidades);
		std::cout << unidades << " =?= " << unidades_copiadas << std::endl;
	}
	{
		base_B_dig_t unidades=static_cast<UINT_T>((B/2)+1);
		base_B_dig_t unidades_copiadas(unidades);
		std::cout << unidades << " =?= " << unidades_copiadas << std::endl;
	}
}

template<type_traits::allowable_base_type_c UINT_T,UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_constr_movimiento_dig_t(){
	using base_B_dig_t = dig_t<UINT_T,B>;
	{
		base_B_dig_t A((B/2)+1);
		std::cout << A <<std::endl;
		base_B_dig_t unidades(std::move(A));
		std::cout << unidades << std::endl;
		std::cout << A << std::endl;
	}
	{
		base_B_dig_t A{(B/2)+1};
		std::cout << A << std::endl;
		base_B_dig_t unidades(std::move(A));
		std::cout << unidades << std::endl;
		std::cout << A << std::endl;
	}
	{
		base_B_dig_t A=(B/2)+1;
		base_B_dig_t unidades(std::move(A));
		std::cout << unidades << std::endl;
		std::cout << A << std::endl;
	}
}

template<type_traits::allowable_base_type_c UINT_T,UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_assign_UINT_dig_t()									{
	using base_B_dig_t = dig_t<UINT_T,B>;
	ullint k{0}; ullint kold{0};
	for (ullint i{0} ; i<1024+6 ; ++i) 										{
		base_B_dig_t unidades;
		unidades = i;
		if ((k%static_cast<ullint>(B))!=static_cast<ullint>(B-1))	 	{
			if ((k%static_cast<ullint>(B))==0)
				std::cout << kold << "->" << unidades << ";";
			else
				std::cout << kold << "->" << unidades << ";";
			++k;														}
		else 															{
			std::cout << kold << "->" << unidades << "|" << std::endl;
			++k;
			kold = k;													}	}
	std::cout << std::endl;													}

template<type_traits::allowable_base_type_c UINT_T,UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_assign_SINT_dig_t(){
	using base_B_dig_t = dig_t<UINT_T,B>;
	sllint k{0};
	for (sllint i{-1000} ; i<1001 ; ++i) {
		base_B_dig_t unidades;
		unidades = i;
		if ((k%static_cast<sllint>(B))!=static_cast<sllint>(B-1)) {
			std::cout << i << "->" << unidades << ";";
		}
		else
			std::cout << i << "->" << unidades << "|" << std::endl;
		++k;
	}
	std::cout << std::endl;
}

template<type_traits::allowable_base_type_c UINT_T,UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_assign_copia_dig_t(){
	using base_B_dig_t = dig_t<UINT_T,B>;
	sllint k{0};
	for (sllint i{-1000} ; i<1001 ; ++i) {
		base_B_dig_t A{i};
		base_B_dig_t unidades;
		unidades = A;
		if ((k%static_cast<sllint>(B))!=static_cast<sllint>(B-1)) {
			if ((k%static_cast<sllint>(B))==0)
				std::cout << i << "->" << unidades << ";";
			else {
				std::cout << i << "->" << unidades << ";";
			}
		}
		else {
			std::cout << i << "->" << unidades << "|" << std::endl;
		}
		++k;
	}
	std::cout << std::endl;											}

template<type_traits::allowable_base_type_c UINT_T,UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_assign_movimiento_dig_t()								{
	using base_B_dig_t = dig_t<UINT_T,B>;
	sllint k{0};

	for (sllint i{-1000} ; i<1001 ; ++i) 									{
		base_B_dig_t A{i};
		base_B_dig_t C{A};
		base_B_dig_t unidades{};
		unidades = A;
		if ((k%static_cast<sllint>(B))!=static_cast<sllint>(B-1)) 			 {
			if ((k%static_cast<sllint>(B))==0)
				std::cout << i << "|1->" << unidades << ";" << C << "-;-";
			else                                                        	{
				std::cout << i << "|2->" << unidades << ";" << C << "-;-";  }}
		else 														        {
			std::cout << i << "|3->" << unidades << C << "-|" << std::endl; }
		++k;
	}
	std::cout << std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_preincrement() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::int64_t md{};
	base_B_dig_t uds{};
	for(std::int64_t idx{0} ; idx < 2*B+1 ; ++idx) {
		if ((++uds).get()==((++md)%B))
			++contador_buenos;
		else
			++contador_malos;
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "___BEGIN__TESTS__PRE_INCREMENTOS___BEGIN___"<< std::endl;
	std::cout 	<< " Numero de incrementos correctos	= "
				<< contador_buenos 					<< std::endl;
	std::cout 	<< " Numero de incrementos fallidos		= "
				<< contador_malos 					<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos	<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< static_cast<std::uint64_t>(2*B+1)<< std::endl;
	std::cout	<< "___END____TESTS__PRE_INCREMENTOS_____END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_postincrement() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::int64_t md{};
	base_B_dig_t uds{};
	for(std::int64_t idx{0} ; idx < 2*B+1 ; ++idx) {
		if ((uds++).get()==((md++)%B))
			++contador_buenos;
		else
			++contador_malos;
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "___BEGIN__TESTS__POSTINCREMENTOS___BEGIN___"<< std::endl;
	std::cout 	<< " Numero de incrementos correctos	= "
				<< contador_buenos 					<< std::endl;
	std::cout 	<< " Numero de incrementos fallidos		= "
				<< contador_malos 					<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos	<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< static_cast<std::uint64_t>(2*B+1)<< std::endl;
	std::cout	<< "___END____TESTS__POSTINCREMENTOS_____END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_predecrement() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::int64_t md{2*B+1};
	base_B_dig_t uds{B+1};
	for(std::int64_t idx{0} ; idx < 2*B+1 ; ++idx) {
		if ((--uds).get()==((--md)%B))
			++contador_buenos;
		else
			++contador_malos;
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "___BEGIN__TESTS__PRE_DECREMENTOS___BEGIN___"<< std::endl;
	std::cout 	<< " Numero de decrementos correctos	= "
				<< contador_buenos 					<< std::endl;
	std::cout 	<< " Numero de decrementos fallidos		= "
				<< contador_malos 					<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos	<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< static_cast<std::uint64_t>(2*B+1)<< std::endl;
	std::cout	<< "___END____TESTS__PRE_DECREMENTOS_____END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_postdecrement() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::int64_t md{2*B+1};
	base_B_dig_t uds{B+1};
	for(std::int64_t idx{0} ; idx < 2*B+1 ; ++idx) {
		if ((uds--).get()==((md--)%B))
			++contador_buenos;
		else
			++contador_malos;
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "___BEGIN__TESTS__POSTDECREMENTOS___BEGIN___"<< std::endl;
	std::cout 	<< " Numero de decrementos correctos	= "
				<< contador_buenos 					<< std::endl;
	std::cout 	<< " Numero de decrementos fallidos		= "
				<< contador_malos 					<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos	<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< static_cast<std::uint64_t>(2*B+1)<< std::endl;
	std::cout	<< "___END____TESTS__POSTDECREMENTOS_____END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_add_assign() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::int64_t md{0};
	std::int64_t nd{0};
	base_B_dig_t nos{0};
	base_B_dig_t uds{0};
	for(std::int64_t idx_nos{0} ; idx_nos < 2*B+1 ; ++idx_nos) {
		for(std::int64_t idx_uds{0} ; idx_uds < 2*B+1 ; ++idx_uds) {
			uds = md;
			uds += nos;
			if (uds.get() == (md+nd)%B)
				++contador_buenos;
			else
				++contador_malos;
			++md;
		}
		++nd;
		nos = nd;
	}
	constexpr std::uint64_t ciclos{
		static_cast<std::uint64_t>(2*B+1)*static_cast<std::uint64_t>(2*B+1)};
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "___BEGIN__TESTS____ADD_&_ASSIGN____BEGIN___"<< std::endl;
	std::cout 	<< " Numero de sumasignaciones correctas= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de sumasignaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< ciclos										<< std::endl;
	std::cout	<< "___END_____TESTS____ADD_&_ASSIGN_____END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_add_assign_uint() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	for(std::int64_t nd{0} ; nd < 2*B+1 ; ++nd) {
		for(std::int64_t md{0} ; md < 2*B+1 ; ++md) {
			base_B_dig_t uds{md};
			uds += nd;
			if (uds.get() == ((md+nd)%B))
				++contador_buenos;
			else
				++contador_malos;
		}
	}
	constexpr std::uint64_t ciclos{
		static_cast<std::uint64_t>(2*B+1)*static_cast<std::uint64_t>(2*B+1)};
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "___BEGIN__TESTS_ADD_&_ASSIGN_UINT__BEGIN___"<< std::endl;
	std::cout 	<< " Numero de sumasignaciones correctas= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de sumasignaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< ciclos										<< std::endl;
	std::cout	<< "___END____TESTS_ADD_&_ASSIGN_UINT____END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_substract_assign() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{1-int64_B} ; nd < int64_B ; ++nd) {
		for(std::int64_t md{1-int64_B} ; md < int64_B ; ++md) {
			std::int64_t mmd{md};
			base_B_dig_t nos{nd};
			base_B_dig_t uds{mmd};
			uds -= nos;
			mmd -= nd;

			while (mmd<0)
				mmd += int64_B;
			while (mmd>=int64_B)
				mmd -= int64_B;

			if (uds.get() == mmd)
				++contador_buenos;
			else
				++contador_malos;

			++contador;
		}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "__BEGIN__TESTS_SUBSTRACT_&_ASSIGN__BEGIN___"<< std::endl;
	std::cout 	<< " Numero de sumasignaciones correctas= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de sumasignaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< contador										<< std::endl;
	std::cout	<< "__END____TESTS_SUBSTRACT_&_ASSIGN____END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_substract_assign_uint() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{1-int64_B} ; nd < int64_B ; ++nd) {
		for(std::int64_t md{1-int64_B} ; md < int64_B ; ++md) {
			std::int64_t mmd{md};
			base_B_dig_t uds{mmd};
			uds -= nd;
			mmd -= nd;
			while (mmd<0) {
				mmd += B;
			}
			while (mmd>=B) {
				mmd -= B;
			}
			if (uds.get() == mmd) {
				++contador_buenos;
			}
			else {
				++contador_malos;
			}
			++contador;
		}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "_BEGIN_TESTS_SUBSTRACT_&_ASSIGN_INT_BEGIN__"<< std::endl;
	std::cout 	<< " Numero de sumasignaciones correctas= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de sumasignaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< contador										<< std::endl;
	std::cout	<< "_END___TESTS_SUBSTRACT_&_ASSIGN_INT__END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_mult_assign() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{1-int64_B} ; nd < int64_B ; ++nd) {
		for(std::int64_t md{1-int64_B} ; md < int64_B ; ++md) {
			std::int64_t mmd{md};
			base_B_dig_t nos{nd};
			base_B_dig_t uds{mmd};
			uds *= nos;
			mmd *= nd;

			while (mmd<0)
				mmd += int64_B;
			while (mmd>=int64_B)
				mmd -= int64_B;

			if (uds.get() == mmd)
				++contador_buenos;
			else
				++contador_malos;

			++contador;
		}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "__BEGIN__TESTS____MULT_&_ASSIGN____BEGIN___"<< std::endl;
	std::cout 	<< " Numero de sumasignaciones correctas= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de sumasignaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< contador										<< std::endl;
	std::cout	<< "__END____TESTS____MULT_&_ASSIGN______END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_mult_assign_uint() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int32_t int32_B{B};
	std::uint32_t contador_buenos{};
	std::uint32_t contador_malos{};
	std::uint32_t contador{};
	for(std::int32_t nd{1-int32_B} ; nd < int32_B ; ++nd) {
		for(std::int32_t md{1-int32_B} ; md < int32_B ; ++md) {
			std::int32_t mmd{md};
			base_B_dig_t uds{mmd};
			uds *= nd;
			mmd *= nd;
			while (mmd<0) {
				mmd += B;
			}
			while (mmd>=int32_B) {
				mmd -= B;
			}
			if (uds.get() == mmd) {
				++contador_buenos;
			}
			else {
				++contador_malos;
			}
			++contador;
		}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "_BEGIN_TESTS___MULT_&_ASSIGN_INT____BEGIN__"<< std::endl;
	std::cout 	<< " Numero de sumasignaciones correctas= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de sumasignaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< contador										<< std::endl;
	std::cout	<< "_END___TESTS___MULT_&_ASSIGN_INT_____END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_ediv_assign() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{1-int64_B} ; nd < int64_B ; ++nd) {
		if ((nd%int64_B) != 0) {
			for(std::int64_t md{1-int64_B} ; md < int64_B ; ++md) {
				base_B_dig_t uds{md};
				std::int64_t mmd{md};
				while (mmd<0)
					mmd += int64_B;
				base_B_dig_t nos{nd};
				std::int64_t nnd{nd};
				while (nnd<0)
					nnd += int64_B;

				uds /= nos;
				mmd /= nnd;

				while (mmd<0)
					mmd += int64_B;
				while (mmd>=int64_B)
					mmd -= int64_B;

				if (uds.get() == mmd)
					++contador_buenos;
				else
					++contador_malos;

				++contador;
			}
		}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "__BEGIN__TESTS____EDIV_&_ASSIGN____BEGIN___"<< std::endl;
	std::cout 	<< " Numero de sumasignaciones correctas= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de sumasignaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< contador										<< std::endl;
	std::cout	<< "__END____TESTS____EDIV_&_ASSIGN______END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_ediv_assign_uint() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int32_t int32_B{B};
	std::uint32_t contador_buenos{};
	std::uint32_t contador_malos{};
	std::uint32_t contador{};
	for(std::int32_t nd{1-int32_B} ; nd < int32_B ; ++nd) {
		if (nd != 0) {
			for(std::int32_t md{1-int32_B} ; md < int32_B ; ++md) {
				std::int32_t mmd{md};
				std::int32_t nnd{nd};
				base_B_dig_t uds{mmd};

				while (mmd<0) {
					mmd += int32_B;
				}
				while (nnd<0) {
					nnd += int32_B;
				}

				uds /= nnd;
				mmd /= nnd;

				while (mmd<0) {
					mmd += B;
				}
				while (mmd>=int32_B) {
					mmd -= B;
				}

				if (uds.get() == mmd) {
					++contador_buenos;
				}
				else {
					++contador_malos;
				}

				++contador;
			}
		}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "_BEGIN_TESTS___EDIV_&_ASSIGN_INT____BEGIN__"<< std::endl;
	std::cout 	<< " Numero de sumasignaciones correctas= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de sumasignaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< contador										<< std::endl;
	std::cout	<< "_END___TESTS___EDIV_&_ASSIGN_INT_____END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}


template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_erem_assign() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{1-int64_B} ; nd < int64_B ; ++nd) {
		if (nd != 0) {
			for(std::int64_t md{1-int64_B} ; md < int64_B ; ++md) {
				std::int64_t mmd{md};
				std::int64_t nnd{nd};
				base_B_dig_t nos{nd};
				base_B_dig_t uds{mmd};

				while (mmd<0)
					mmd += int64_B;
				while (nnd<0)
					nnd += int64_B;

				uds %= nos;
				mmd %= nnd;

				while (mmd<0)
					mmd += int64_B;
				while (mmd>=int64_B)
					mmd -= int64_B;

				if (uds.get() == mmd)
					++contador_buenos;
				else
					++contador_malos;

				++contador;
			}
		}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "__BEGIN__TESTS____EREM_&_ASSIGN____BEGIN___"<< std::endl;
	std::cout 	<< " Numero de sumasignaciones correctas= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de sumasignaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< contador										<< std::endl;
	std::cout	<< "__END____TESTS____EREM_&_ASSIGN______END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_erem_assign_uint() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int32_t int32_B{B};
	std::uint32_t contador_buenos{};
	std::uint32_t contador_malos{};
	std::uint32_t contador{};
	for(std::int32_t nd{1-int32_B} ; nd < int32_B ; ++nd) {
		if (nd != 0) {
			for(std::int32_t md{1-int32_B} ; md < int32_B ; ++md) {
				std::int32_t mmd{md};
				std::int32_t nnd{nd};
				base_B_dig_t uds{mmd};

				while (mmd<0) {
					mmd += int32_B;
				}
				while (nnd<0) {
					nnd += int32_B;
				}

				uds %= nnd;
				mmd %= nnd;

				while (mmd<0) {
					mmd += B;
				}
				while (mmd>=int32_B) {
					mmd -= B;
				}

				if (uds.get() == mmd) {
					++contador_buenos;
				}
				else {
					++contador_malos;
				}

				++contador;
			}
		}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "_BEGIN_TESTS___EREM_&_ASSIGN_INT____BEGIN__"<< std::endl;
	std::cout 	<< " Numero de sumasignaciones correctas= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de sumasignaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< contador										<< std::endl;
	std::cout	<< "_END___TESTS___EREM_&_ASSIGN_INT_____END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_add() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{1-int64_B} ; nd < int64_B ; ++nd) {
			for(std::int64_t md{1-int64_B} ; md < int64_B ; ++md) {
				std::int64_t suma_int{md+nd};
				base_B_dig_t nos{nd};
				base_B_dig_t uds{md};
				base_B_dig_t suma_dig{nos+uds};

				while (suma_int < 0)
					suma_int += int64_B;
				while (suma_int >= int64_B)
					suma_int -= int64_B;

				if (suma_dig.get() == suma_int)
					++contador_buenos;
				else
					++contador_malos;

				++contador;
			}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "___BEGIN_______TESTS____SUMA_______BEGIN___"<< std::endl;
	std::cout 	<< " Numero de sumasignaciones correctas= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de sumasignaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< contador										<< std::endl;
	std::cout	<< "___END_________TESTS____SUMA_________END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_add_int() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int32_t int32_B{B};
	std::uint32_t contador_buenos{};
	std::uint32_t contador_malos{};
	std::uint32_t contador{};
	for(std::int32_t nd{1-int32_B} ; nd < int32_B ; ++nd) {
			for(std::int32_t md{1-int32_B} ; md < int32_B ; ++md) {
				std::int32_t suma_int{md+nd};
				base_B_dig_t uds{md};
				base_B_dig_t suma_dig{uds+nd};

				while (suma_int < 0)
					suma_int += int32_B;
				while (suma_int >= int32_B)
					suma_int -= int32_B;

				if (suma_dig.get() == suma_int)
					++contador_buenos;
				else
					++contador_malos;

				++contador;
			}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "___BEGIN______TESTS_SUMA_INT_______BEGIN___"<< std::endl;
	std::cout 	<< " Numero de sumasignaciones correctas= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de sumasignaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< contador										<< std::endl;
	std::cout	<< "___END________TESTS_SUMA_INT_________END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_substract() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{1-int64_B} ; nd < int64_B ; ++nd) {
			for(std::int64_t md{1-int64_B} ; md < int64_B ; ++md) {
				std::int64_t suma_int{md-nd};
				base_B_dig_t nos{nd};
				base_B_dig_t uds{md};
				base_B_dig_t suma_dig{uds-nos};

				while (suma_int < 0)
					suma_int += int64_B;
				while (suma_int >= int64_B)
					suma_int -= int64_B;

				if (suma_dig.get() == suma_int)
					++contador_buenos;
				else
					++contador_malos;

				++contador;
			}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "___BEGIN_____TESTS__SUBSTRACT______BEGIN___"<< std::endl;
	std::cout 	<< " Numero de restas correctas			= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de restas fallidas			= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< contador										<< std::endl;
	std::cout	<< "___END_______TESTS__SUBSTRACT________END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_substract_int() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int32_t int32_B{B};
	std::uint32_t contador_buenos{};
	std::uint32_t contador_malos{};
	std::uint32_t contador{};
	for(std::int32_t nd{1-int32_B} ; nd < int32_B ; ++nd) {
			for(std::int32_t md{1-int32_B} ; md < int32_B ; ++md) {
				std::int32_t suma_int{md-nd};
				base_B_dig_t uds{md};
				base_B_dig_t suma_dig{uds-nd};

				while (suma_int < 0)
					suma_int += int32_B;
				while (suma_int >= int32_B)
					suma_int -= int32_B;

				if (suma_dig.get() == suma_int)
					++contador_buenos;
				else
					++contador_malos;

				++contador;
			}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "___BEGIN______TESTS_RESTA_INT______BEGIN___"<< std::endl;
	std::cout 	<< " Numero de restas correctas			= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de restas fallidas			= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas			= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"	= "
				<< contador										<< std::endl;
	std::cout	<< "___END________TESTS_RESTA_INT________END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_multiply() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{1-int64_B} ; nd < int64_B ; ++nd) {
			for(std::int64_t md{1-int64_B} ; md < int64_B ; ++md) {
				std::int64_t result_int{md*nd};
				base_B_dig_t nos{nd};
				base_B_dig_t uds{md};
				base_B_dig_t result_dig{uds*nos};

				while (result_int < 0)
					result_int += int64_B;
				while (result_int >= int64_B)
					result_int -= int64_B;

				if (result_dig.get() == result_int)
					++contador_buenos;
				else
					++contador_malos;

				++contador;
			}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "___BEGIN___TESTS_MULTIPLICACIONES__BEGIN___"<< std::endl;
	std::cout 	<< " Numero de multiplicaciones correctas	= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de multiplicaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas				= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"		= "
				<< contador										<< std::endl;
	std::cout	<< "___END_____TESTS_MULTIPLICACIONES____END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_multiply_int() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int32_t int32_B{B};
	std::uint32_t contador_buenos{};
	std::uint32_t contador_malos{};
	std::uint32_t contador{};
	for(std::int32_t nd{1-int32_B} ; nd < int32_B ; ++nd) {
			for(std::int32_t md{1-int32_B} ; md < int32_B ; ++md) {
				std::int32_t result_int{md*nd};
				base_B_dig_t uds{md};
				base_B_dig_t result_dig{uds*nd};

				while (result_int < 0)
					result_int += int32_B;
				while (result_int >= int32_B)
					result_int -= int32_B;

				if (result_dig.get() == result_int)
					++contador_buenos;
				else
					++contador_malos;

				++contador;
			}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "__BEGIN_TESTS_MULTIPLICACIONES_INT_BEGIN___"<< std::endl;
	std::cout 	<< " Numero de multiplicaciones correctas	= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de multiplicaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas				= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"		= "
				<< contador										<< std::endl;
	std::cout	<< "___END__TESTS_MULTIPLICACIONES_INT___END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_edivision() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{-1} ; nd < int64_B ; ++nd) {
		if (nd%B != 0) {
			for(std::int64_t md{-1} ; md < int64_B ; ++md) {

				base_B_dig_t nos{nd};
				base_B_dig_t uds{md};
				base_B_dig_t result_dig{uds/nos};
				base_B_dig_t prueba_ediv_dig{uds-(result_dig*nos)};

				std::int64_t mmd{md};
				while (mmd < 0)
					mmd += int64_B;
				while (mmd >= int64_B)
					mmd -= int64_B;
				std::int64_t nnd{nd};
				while (nnd < 0)
					nnd += int64_B;
				while (nnd >= int64_B)
					nnd -= int64_B;
				std::int64_t result_int{mmd/nnd};
				while (result_int < 0)
					result_int += int64_B;
				while (result_int >= int64_B)
					result_int -= int64_B;
				std::int64_t prueba_ediv_int{mmd-(result_int*nnd)};
				while (prueba_ediv_int < 0)
					prueba_ediv_int += int64_B;
				while (prueba_ediv_int >= int64_B)
					prueba_ediv_int -= int64_B;
				if (prueba_ediv_dig.get() == prueba_ediv_int) {
					++contador_buenos;
				}
				else {
					++contador_malos;
				}
				++contador;
			}
		}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "___BEGIN_____TESTS_EDIVISIONES_____BEGIN___"<< std::endl;
	std::cout 	<< " Numero de divisiones euclideas correctas	= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de divisiones euclideas fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas					= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"			= "
				<< contador										<< std::endl;
	std::cout	<< "___END_______TESTS_EDIVISIONES_______END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_edivision_int() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{1-int64_B} ; nd < int64_B ; ++nd) {
		if (nd%B != 0) {
			for(std::int64_t md{1-int64_B} ; md < int64_B ; ++md) {
				std::int64_t mmd{md};
				while (mmd < 0)
					mmd += int64_B;
				while (mmd >= int64_B)
					mmd -= int64_B;
				std::int64_t nnd{nd};
				while (nnd < 0)
					nnd += int64_B;
				while (nnd >= int64_B)
					nnd -= int64_B;
				std::int64_t result_int{mmd/nnd};
				while (result_int < 0)
					result_int += int64_B;
				while (result_int >= int64_B)
					result_int -= int64_B;

				base_B_dig_t uds{mmd};
				base_B_dig_t result_dig{uds/nnd};

				if (result_dig.get() == result_int)
					++contador_buenos;
				else
					++contador_malos;

				++contador;
			}
		}
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "__BEGIN___TESTS_EDIVISIONES_INT____BEGIN___"<< std::endl;
	std::cout 	<< " Numero de divisiones euclideas correctas	= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de divisiones euclideas fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas					= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"			= "
				<< contador										<< std::endl;
	std::cout	<< "___END____TESTS_EDIVISIONES_INT______END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_C_B() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{-2*int64_B} ; nd < 2*int64_B ; ++nd) {
			std::int64_t nnd{nd};
			while (nnd < 0)
				nnd += int64_B;
			while (nnd >= int64_B)
				nnd -= int64_B;

			std::int64_t result_int{int64_B-nnd};
			while (result_int < 0)
				result_int += int64_B;
			while (result_int >= int64_B)
				result_int -= int64_B;

			base_B_dig_t uds{nnd};
			base_B_dig_t result_dig{uds.C_B()};

			if (result_dig.get() == result_int)
				++contador_buenos;
			else
				++contador_malos;

			++contador;
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "__BEGIN___TESTS_COMPLEMENTO_BASE___BEGIN___"<< std::endl;
	std::cout 	<< " Numero de complementos a la base correctas	= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de complementos a la base fallidos	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas					= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"			= "
				<< contador										<< std::endl;
	std::cout	<< "__END_____TESTS_COMPLEMENTO_BASE_____END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_operator_C_Bm1() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{-2*int64_B} ; nd < 2*int64_B ; ++nd) {
			std::int64_t nnd{nd};
			while (nnd < 0)
				nnd += int64_B;
			while (nnd >= int64_B)
				nnd -= int64_B;

			std::int64_t result_int{int64_B-nnd-1};
			while (result_int < 0)
				result_int += int64_B;
			while (result_int >= int64_B)
				result_int -= int64_B;

			base_B_dig_t uds{nnd};
			base_B_dig_t result_dig{uds.C_Bm1()};

			if (result_dig.get() == result_int)
				++contador_buenos;
			else
				++contador_malos;

			++contador;
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "__BEGIN__TESTS_COMPLEMENTO_BASEm1__BEGIN___"<< std::endl;
	std::cout 	<< " Numero de complementos a la Bm1 correctas	= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de complementos a la Bm1 fallidos	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas					= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"			= "
				<< contador										<< std::endl;
	std::cout	<< "__END_____TESTS_COMPLEMENTO_BASEm1___END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_prop_C_B_eq_inv_C_B() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{-2*int64_B} ; nd < 2*int64_B ; ++nd) {
			base_B_dig_t uds{nd};
			base_B_dig_t result_interm_dig{uds.C_B()};
			base_B_dig_t result_dig{result_interm_dig.C_B()};

			if (result_dig == uds)
				++contador_buenos;
			else
				++contador_malos;

			++contador;
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "__BEGIN__TESTS_dig.C_B().C_B()=dig__BEGIN__"<< std::endl;
	std::cout 	<< " Numero de C_B(C_B())=Id() correctas	= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de C_B(C_B())=Id() fallidos	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas					= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"			= "
				<< contador										<< std::endl;
	std::cout	<< "__END____TESTS_dig.C_B().C_B()=dig____END__"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_prop_C_Bm1_eq_inv_C_Bm1() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{-2*int64_B} ; nd < 2*int64_B ; ++nd) {
			base_B_dig_t uds{nd};
			base_B_dig_t result_interm_dig{uds.C_Bm1()};
			base_B_dig_t result_dig{result_interm_dig.C_Bm1()};

			if (result_dig == uds)
				++contador_buenos;
			else
				++contador_malos;

			++contador;
	}
	std::cout	<< "_______________________________________________"<< std::endl;
	std::cout	<< "__BEGIN__TESTS_dig.C_Bm1().C_Bm1()=dig__BEGIN__"<< std::endl;
	std::cout 	<< " Numero de C_Bm1(C_Bm1())=Id() correctas	= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de C_B(C_B())=Id() fallidos	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas					= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"			= "
				<< contador										<< std::endl;
	std::cout	<< "__END____TESTS_dig.C_Bm1().C_Bm1()=dig____END__"<< std::endl;
	std::cout	<< "_______________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_prop_C_B_minus_1_eq_C_Bm1() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{-2*int64_B} ; nd < 2*int64_B ; ++nd) {
			base_B_dig_t uds{nd};
			base_B_dig_t uds_C_Bm1_p1{uds.C_Bm1()};
			++uds_C_Bm1_p1;
			base_B_dig_t uds_C_B{uds.C_B()};

			if (uds_C_Bm1_p1 == uds_C_B)
				++contador_buenos;
			else
				++contador_malos;

			++contador;
	}
	std::cout	<< "_______________________________________________"<< std::endl;
	std::cout	<< "__BEGIN__TESTS_dig.C_Bm1()+1=dig.C_B()__BEGIN__"<< std::endl;
	std::cout 	<< " Numero de C_Bm1(C_Bm1())=Id() correctas	= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de C_B(C_B())=Id() fallidos	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas					= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"			= "
				<< contador										<< std::endl;
	std::cout	<< "__END____TESTS_dig.C_Bm1()+1=dig.C_B()____END__"<< std::endl;
	std::cout	<< "_______________________________________________"<< std::endl;
}


template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_unary_operator_minus() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{-2*int64_B} ; nd < 2*int64_B ; ++nd) {
			std::int64_t nnd{nd};
			while (nnd < 0)
				nnd += int64_B;
			while (nnd >= int64_B)
				nnd -= int64_B;

			std::int64_t result_int{int64_B-nnd};
			while (result_int < 0)
				result_int += int64_B;
			while (result_int >= int64_B)
				result_int -= int64_B;

			base_B_dig_t uds{nnd};
			base_B_dig_t result_dig{-uds};

			if (result_dig.get() == result_int)
				++contador_buenos;
			else
				++contador_malos;

			++contador;
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "__BEGIN___TESTS_OPERATOR_-_UNARIO__BEGIN___"<< std::endl;
	std::cout 	<< " Numero de cambios de signo correctas	= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de cambios de signo fallidos	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas					= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"			= "
				<< contador										<< std::endl;
	std::cout	<< "__END_____TESTS_OPERATOR_-_UNARIO____END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

template<type_traits::allowable_base_type_c UINT_T, UINT_T B>
	requires (type_traits::suitable_base<UINT_T,B>())
void display_unary_operator_neg() {
	using base_B_dig_t = dig_t<UINT_T,B>;
	constexpr std::int64_t int64_B{B};
	std::uint64_t contador_buenos{};
	std::uint64_t contador_malos{};
	std::uint64_t contador{};
	for(std::int64_t nd{-2*int64_B} ; nd < 2*int64_B ; ++nd) {
			std::int64_t nnd{nd};
			while (nnd < 0)
				nnd += int64_B;
			while (nnd >= int64_B)
				nnd -= int64_B;

			std::int64_t result_int{int64_B-nnd-1};
			while (result_int < 0)
				result_int += int64_B;
			while (result_int >= int64_B)
				result_int -= int64_B;

			base_B_dig_t uds{nnd};
			base_B_dig_t result_dig{!uds};

			if (result_dig.get() == result_int)
				++contador_buenos;
			else
				++contador_malos;

			++contador;
	}
	std::cout	<< "___________________________________________"<< std::endl;
	std::cout	<< "__BEGIN___TESTS_OPERATOR_!_UNARIO__BEGIN___"<< std::endl;
	std::cout 	<< " Numero de negaciones correctas	= "
				<< contador_buenos 								<< std::endl;
	std::cout 	<< " Numero de negaciones fallidas	= "
				<< contador_malos 								<< std::endl;
	std::cout   << " Numero total de pruebas					= "
				<< contador_buenos+contador_malos				<< std::endl;
	std::cout   << " Numero limite del ciclo \"for\"			= "
				<< contador										<< std::endl;
	std::cout	<< "__END_____TESTS_OPERATOR_!_UNARIO____END___"<< std::endl;
	std::cout	<< "___________________________________________"<< std::endl;
}

}
#endif // TEST_DIG_T_HPP_INCLUDED
