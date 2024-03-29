# NumericRepresentations
## Library for several ways of numeric representations with weights power of a radix B by columns

This software project has a didactic purpose.
This project by initial decision is written in 2020 Standard C++, with Modern C++ style.
This software is modeling part of the concept of number representation: natural numbers, integers, rational numbers, non-negative rational numbers, either with fixed width or with arbitrary precision (adjustable length).
Since the number of representations is huge, we will model only the most common shapes.
The basis of all this software is the modeling of a digit in any radix that users want to represent. For now we are limited by the integer types in the C++ standard.
With more time the digit can be represented by any natural representation that we have already constructed.

As a basic rule we have that the digit model cannot fail because of the size of the containing type with the addition or multiplication operations, so we will provide a type for results and set the unsigned integer type to contain a number like B^2-1.
The results will be equipped with modular arithmetic (module B, the chosen radix B).

The version of the declaration will be:

    template<std::unsigned T, T B>
      requires (B>1)
    class dig_t;

But we give an adequate alias:
    
    template<std::uint64_t B>
      requires (B>1)
    class digit_t;

This alias choice the best unsigned integer type for the chosen radix.
 
The unique variable-object member in the class will be a integer:

    template<std::uint64_t B>
      requires (B>1)
    struct dig_t {
    private:
      T m_d{};
    };
    
 The value `dig_t<T,B>::m_d` can't be less than 0 or greater than B-1 in any moment.
 Then B is part of the definition of the digit representation. It would necessarily be **digit __radix B__**.
 
 As base class of any fixed width representation, we will have
 
    template<std::unsigned T, T B, std::size_t L>
      requires (L > 0)
    struct reg_digs_t : public std::array<dig_t<T,B>,L>;
    
This class only has methods to order and compare the arrays of digits as if they were natural numbers. The operations will be in a derived class:

    template<std::unsigned T, T B, std::size_t L>
    struct nat_reg_digs_t : public reg_digs_t<T,B,L>; // FOR NATURAL NUMBERS IN A FIXED WIDTH REPRESENTATION
    
    template<std::unsigned T, T B, std::size_t L>
    struct int_reg_digs_t : public nat_reg_digs_t<T,B,L>; // FOR INTEGER NUMBERS IN A FIXED WIDTH REPRESENTATION
                                                          // COMPLEMENT TO THE BASE REPRESENTATION AS FIRST SHAPE

Now we can extend to magnitude and sign (M&S) shape of representation as a second shape.
For these representations of integers we need a suplementary object-member: the sign. It can be a bool or a special digit in the MSB that only has two values: 0 and B-1.

From this point is easy to think how to follow the project. First of all, we will get a pair of classes of numeric representations of fractional numbers with fixed width of the integer part and a fixed width of the fractional part. The declaration of classes will be:

    template<std::unsigned T,T B,std::size_t IL,std::size_t FL>
        requires ((IL > 0)||(FL > 0))
    struct nat_rat_fixed_point_t : public nat_reg_digs_t<T,B,IL+FL>;
    
    template<std::unsigned T,T B,std::size_t IL,std::size_t FL>
        requires ((IL > 0)||(FL > 0))
    struct int_rat_fixed_point_t : public int_reg_digs_t<T,B,IL+FL>;
    
 In these first version, we want get a version of these numeric representation types but without limits of length, for infinite precision:
    
    template<std::unsigned T, T B>
    struct base_num_t : public std::basic_string<dig_t<T,B>>; // BASE CLASS FOR HOLD THE DIGITS, 
                                                              // COMPARE (NUMERIC) STRINGS, 
                                                              // AND NORMALIZE OF THE LENGTHS
 
    template<std::unsigned T, T B>
    struct nat_num_t : public base_num_t<T,B>; // FOR NATURAL NUMBERS AND ITS OPERATIONS
    
    template<std::unsigned T, T B>
    struct int_num_t : public nat_reg_digs_t<T,B>; // FOR INTEGER NUMBERS AND ITS OPERATIONS
                                                   // COMPLEMENT TO THE BASE REPRESENTATION AS FIRST SHAPE
    
    template<std::unsigned T,T B>
    struct nat_rat_num_t : public nat_num_t<T,B>;
    
    template<std::unsigned T,T B>
    struct rat_num_t : public nat_rat_num_t<T,B>;
    
The firsts classes to build are rational numbers with numerator/denominator format (fixed width and infinite length), and the types IEEE754 GENERALIZED, with its two flavours, fixed width for mantissa and exponent and variable length.

Before develop M&S flavours of the integer representation types, we could develop some shapes of representation as **continuous fractions** and **p_adic numbers**.
                                                          
