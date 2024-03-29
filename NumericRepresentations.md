# NumRepr
NumRepr == reduced( Numeric Representations )


Este proyecto tiene como objetivo dar una codificación en C++ Moderno, incluyendo el último estándard, C++20, de las distintas formas de representación de números que nos podemos encontrar en sistemas digitales y algunas formas que son especialmente útiles aunque no tengan posibilidad cercana de implementarse como hardware.


Estas formas de representación tienen como finalidad la didáctica de este tema en concreto de los sitemas digitales. Por lo tanto no estaremos preocupados porque las implementaciones sean especialmente veloces o que ocupen poca memoria, sino que estaremos centrados en la visibilidad de las representaciones.


El tipo sobre el que por ahora se comienza es el tipo plantilla `dig_t<typename UInt_t,UInt_t B>`. No es más que un recubrimiento en una plantilla de estructura de un tipo entero sin signo (`std::is_unsigned_v<UInt_t>`).


A partir de aquí todos las representaciones como por ejemplo `reg_int<typename UInt_t,UInt_t B,size_t L>`, serán de tipo `std::array<dig_t<UInt_t,B>,L>` o derivados. Para los tipos de fracciones de punto fijo tendremos dos parámetros de plantilla distintos LE y LF, longitud de la parte entera y longitud de la parte fraccionaria.


Para los tipos racionales tendremos una implementación más como par de enteros numerador-denominador. Igualmente para los tipos IEEE 754 Generalizados podemos tenerlo todo en un solo array o bien en un par mantisa-exponente.


Por último tenemos otras representaciones que haremos como representación en fracciones continuas y representación p-ádica.