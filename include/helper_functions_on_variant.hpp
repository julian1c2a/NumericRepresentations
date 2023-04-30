#ifndef HELPER_FUNCTIONS_ON_VARIANT_HPP_INCLUDED
#define HELPER_FUNCTIONS_ON_VARIANT_HPP_INCLUDED

#include "memory_handler.hpp"

enum type_e {
	zero  ,one   ,dig002,dig003,dig004,dig005,dig006,dig007,dig008,dig009,
	dig010,dig011,dig012,dig013,dig014,dig015,dig016,dig017,dig018,dig019,
	dig020,dig021,dig022,dig023,dig024,dig025,dig026,dig027,dig028,dig029,
	dig030,dig031,dig032,dig033,dig034,dig035,dig036,dig037,dig038,dig039,
	dig040,dig041,dig042,dig043,dig044,dig045,dig046,dig047,dig048,dig049,
	dig050,dig051,dig052,dig053,dig054,dig055,dig056,dig057,dig058,dig059,
	dig060,dig061,dig062,dig063,dig064,dig065,dig066,dig067,dig068,dig069,
	dig070,dig071,dig072,dig073,dig074,dig075,dig076,dig077,dig078,dig079,
	dig080,dig081,dig082,dig083,dig084,dig085,dig086,dig087,dig088,dig089,
	dig090,dig091,dig092,dig093,dig094,dig095,dig096,dig097,dig098,dig099,
	dig100,dig101,dig102,dig103,dig104,dig105,dig106,dig107,dig108,dig109,
	dig110,dig111,dig112,dig113,dig114,dig115,dig116,dig117,dig118,dig119,
	dig120,dig121,dig122,dig123,dig124,dig125,dig126,dig127,dig128,dig129,
	dig130,dig131,dig132,dig133,dig134,dig135,dig136,dig137,dig138,dig139,
	dig140,dig141,dig142,dig143,dig144,dig145,dig146,dig147,dig148,dig149,
	dig150,dig151,dig152,dig153,dig154,dig155,dig156,dig157,dig158,dig159,
	dig160,dig161,dig162,dig163,dig164,dig165,dig166,dig167,dig168,dig169,
	dig170,dig171,dig172,dig173,dig174,dig175,dig176,dig177,dig178,dig179,
	dig180,dig181,dig182,dig183,dig184,dig185,dig186,dig187,dig188,dig189,
	dig190,dig191,dig192,dig193,dig194,dig195,dig196,dig197,dig198,dig199,
	dig200,dig201,dig202,dig203,dig204,dig205,dig206,dig207,dig208,dig209,
	dig210,dig211,dig212,dig213,dig214,dig215,dig216,dig217,dig218,dig219,
	dig220,dig221,dig222,dig223,dig224,dig225,dig226,dig227,dig228,dig229,
	dig230,dig231,dig232,dig233,dig234,dig235,dig236,dig237,dig238,dig239,
	dig240,dig241,dig242,dig243,dig244,dig245,dig246,dig247,dig248,dig249,
	dig250,dig251,dig252,dig253,dig254,dig255
};

if (std::holds_alternative<std::false_type>(my_variant)) 		return 0;
else if (std::holds_alternative<std::true_type>(my_variant)) 	return 1;
else if (std::holds_alternative<NumRepr::dig_t<2>>(my_variant)) return 2;





#endif // HELPER_FUNCTIONS_ON_VARIANT_HPP_INCLUDED
