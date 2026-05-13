#include "Fixed.hpp"

Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;

  value_ = 0;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;

  value_ = other.value_;
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;

  if (this != &other) {
    value_ = other.value_;
  }

  return *this;
}
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;

  return this->value_;
}

void Fixed::setRawBits(int const raw) { this->value_ = raw; }

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }