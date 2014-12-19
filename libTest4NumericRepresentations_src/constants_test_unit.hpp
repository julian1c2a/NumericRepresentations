#ifndef CONSTANTS_TEST_UNIT__HPP
#define CONSTANTS_TEST_UNIT__HPP

#include "D:\Dropbox\NumericRepresentations\NumericRepresentations\src\libNumericRepresentations_src\basic_types.hpp"

const uchint Bin1 = 2;
const int iBin1 = static_cast<int>(Bin1);
const int iBin1_2 = iBin1*iBin1;

const uchint Dec = 10;
const int iDec = static_cast<int>(Dec);
const int iDec_2 = iDec*iDec;

const uchint B3x5 = 15;
const int iB3x5 = static_cast<int>(B3x5);
const int iB3x5_2 = iB3x5*iB3x5;

const uchint Bin4x3 = 48;
const int iBin4x3 = static_cast<int>(Bin4x3);
const int iBin4x3_2 = iBin4x3*iBin4x3;

const uchint Bin7 = 128;
const int iBin7 = static_cast<int>(Bin7);
const int iBin7_2 = iBin7*iBin7;

const uchint S210 = 210;
const int iS210 = static_cast<int>(S210);
const int iS210_2 = iS210*iS210;

const uchint M255 = 255;
const int iM255 = static_cast<int>(M255);
const int iM255_2 = iM255*iM255;

struct result_test {
    unsigned int erroneos;
    unsigned int correctos;
};


template<class U,template<const U> class T, const U R, class S>
S MaxPowRadix_Consts_Choosing(){
	S MaxPowRadix=S(1);
	for(ulint I = 0 ; I < (T<R>::NDigs); ++I){
		MaxPowRadix *= S(R);
	}
	return MaxPowRadix;
}

template<class U,template<const U> class T, const U R, class S>
S BeginIndex_Consts_Choosing(){
	S BeginIndex;
	if(T<R>::with_sign) {
		BeginIndex = -(MaxPowRadix_Consts_Choosing<U,T,R,S>());
	}
	else BeginIndex=0;
	return BeginIndex;
}

template<class U,template<const U> class T, const U R, class S>
S EndIndex_Consts_Choosing(){
	S EndIndex = MaxPowRadix_Consts_Choosing<U,T,R,S>()-1;
	return EndIndex;
}

template<class U,template<const U> class T, const U R, class S>
struct Limit {
	static const S EndIndex;
	static const S BeginIndex;
	static const S MaxPowRadix;
};

template<class U,template<const U> class T, const U R, class S>
const S Limit<U,T,R,S>::EndIndex = EndIndex_Consts_Choosing<U,T,R,S>();
template<class U,template<const U> class T, const U R, class S>
const S Limit<U,T,R,S>::BeginIndex = BeginIndex_Consts_Choosing<U,T,R,S>();
template<class U,template<const U> class T, const U R, class S>
const S Limit<U,T,R,S>::MaxPowRadix = MaxPowRadix_Consts_Choosing<U,T,R,S>();

/* resumen constant_test_num :






   */

#endif //  CONSTANTS_TEST_UNIT__HPP
