NumericRepresentations
======================


The first target of this project is educational.

This is a library of several representations of numbers, that is able to choose any radix of representation between 2 to 255 
(by now), and the format of representation for negative numbers is radix complement.

I'll add Magnitude&Sign format, and the length of the numbers is by now, 1 digit, 2 digits, and variable length,
for numbers as large as they need. I'll add others length formats, as with constant fixed length that is given by the user
of the library.

Too, the library will has ieee 754 format (with variable parameters)  and fixed point.

The library is derived from the (template) type [dig_t].
The list of template classes is:

template<unsigned char R> class dig_t;
template<unsigned char R> class sdig_t;
template<unsigned char R> class pardigs_t;
template<unsigned char R> class spardigs_t;
template<unsigned char R,unsigned n> class fs_uint_t;
template<unsigned char R,unsigned n> class fs_int_t;
template<unsigned char R,unsigned n,unsigned m> class fs_urat_t;
template<unsigned char R,unsigned n,unsigned m> class fs_rat_t;

template<unsigned char R,unsigned nm,unsigned ne> class fp_rat_t;

template<unsigned char R,unsigned n> class uint_t;
template<unsigned char R,unsigned n> class int_t;
template<unsigned char R,unsigned n,unsigned m> class urat_t;
template<unsigned char R,unsigned n,unsigned m> class rat_t;
