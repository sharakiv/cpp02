#include "Fixed.hpp"



Fixed::Fixed(){

    this->value_ = 0;

}

Fixed::Fixed(const int value ) : value_ (value << fractionalBits_) {

}

Fixed::Fixed(const float value) : value_ (roundf (value *( 1 << fractionalBits_))) {

}

Fixed::Fixed(const Fixed& other){
	
    this->value_ = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {

    if (this != &other) { 
    
        this->value_ = other.getRawBits();
    }
    
    return *this;                 
}

int Fixed::getRawBits( void ) const{

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


Fixed& Fixed::operator++(){

	this->value_ += 1;

	return* this;
}

Fixed Fixed::operator++(int){

	Fixed temp(*this);

	this->value_ += 1;

	return temp;
}

Fixed& Fixed::operator--(){

	this->value_ -= 1;

	return* this;
}

Fixed Fixed::operator--(int){

	Fixed temp(*this);

	this->value_ -= 1;

	return temp;
}

Fixed& Fixed::min(Fixed& a,Fixed& b){

		if(a < b){

			return(a);
		}

		else 

		return(b);
	}

const Fixed& Fixed::min(const Fixed& a,const Fixed& b){

			if(a < b){

			return(a);
		}

		else 

		return(b);
	}
Fixed& Fixed::max(Fixed& a,Fixed& b){

			if(a > b){

			return(a);
		}

		else 

		return(b);
	}

const Fixed& Fixed::max(const Fixed& a,const Fixed& b){

			if(a > b){

			return(a);
		}

		else 

		return(b);
	}


