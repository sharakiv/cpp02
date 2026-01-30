#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{

    private:

    int value_; 

    static const int fractionalBits_ = 8;


    public:

    Fixed();

    Fixed(const int);

    Fixed(const float);

    Fixed(const Fixed& other );

    Fixed& operator=(const Fixed& other);

    ~Fixed();

    void setRawBits( int const raw );

    int getRawBits( void ) const;

    float toFloat( void ) const;

    int toInt( void ) const;
};

#endif