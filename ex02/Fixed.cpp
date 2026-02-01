#include "Fixed.hpp"



Fixed::Fixed(){

    std::cout << "Default constructor called" << std::endl;

    this->value_ = 0;

}

Fixed::Fixed(const int value ) : value_ (value << fractionalBits_) {

    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : value_ (roundf (value *( 1 << fractionalBits_))) {

    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){

    std::cout << "Copy constructor called" << std::endl;

    this->value_ = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {

    std::cout << "Copy assignment operator called" << std::endl;
    
    if (this != &other) { 
    
        this->value_ = other.getRawBits();
    }
    
    return *this;                 
}

int Fixed::getRawBits( void ) const{

    std::cout << "getRawBits member function called" << std::endl;

    return this->value_;
}

void Fixed::setRawBits( int const raw ){

    this->value_ = raw;
}

float Fixed::toFloat( void ) const{

	return (float)value_ /256.0f;

}

int Fixed::toInt( void ) const{

	return value_ >> fractionalBits_;

}

std::ostream& operator<<(std::ostream& os,const Fixed& fixed){

	os << fixed.toFloat();

	return os;
}

Fixed::~Fixed(){

    std::cout << "Destructor called" << std::endl;
}


bool Fixed::operator>(const Fixed& rhs) const {
 
	return this->value_ > rhs.value_;
}

bool Fixed::operator<(const Fixed& rhs) const {
 
	return this->value_ < rhs.value_;
}

bool Fixed::operator>=(const Fixed& rhs) const {
 
	return this->value_ >= rhs.value_;
}

bool Fixed::operator<=(const Fixed& rhs) const {
 
	return this->value_ <= rhs.value_;
}

bool Fixed::operator==(const Fixed& rhs) const {
 
	return this->value_ == rhs.value_;
}

bool Fixed::operator!=(const Fixed& rhs) const {
 
	return this->value_ !=rhs.value_;
}

Fixed Fixed::operator+(const Fixed& rhs) const{

	Fixed result;

	result.setRawBits(this->value_ + rhs.value_);

	return result;

}

Fixed Fixed::operator-(const Fixed& rhs) const{

	Fixed result;

	result.setRawBits(this->value_ - rhs.value_);

	return result;

}

Fixed Fixed::operator*(const Fixed& rhs) const{

	return(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const{

	return(this->toFloat() / rhs.toFloat());
}

