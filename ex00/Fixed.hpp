#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{

    private:

    int value_; 

    static const int fractionalBits_ = 8;


    public:

    Fixed();

    Fixed(const Fixed& other );

    Fixed& operator=(const Fixed& other);

    ~Fixed();

    void setRawBits( int const raw );

    int getRawBits( void ) const;
};

#endif