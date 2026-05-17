#include "Fixed.hpp"

Fixed::Fixed() : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value_(value * (1 << fractionalBits_)) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
    : value_(roundf(value * (1 << fractionalBits_))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value_(other.value_) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->value_ = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const { return this->value_; }

void Fixed::setRawBits(int const raw) { this->value_ = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(value_) / (1 << fractionalBits_);
}

int Fixed::toInt(void) const { return value_ >> fractionalBits_; }

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();

  return os;
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
  return this->value_ != rhs.value_;
}

Fixed Fixed::operator+(const Fixed& rhs) const {
  Fixed result;

  result.setRawBits(this->value_ + rhs.value_);

  return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
  Fixed result;

  result.setRawBits(this->value_ - rhs.value_);

  return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
  Fixed result;
  result.setRawBits((static_cast<long>(this->value_) * rhs.value_) >>
                    fractionalBits_);
  return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
  Fixed result;
  result.setRawBits((static_cast<long>(this->value_) << fractionalBits_) /
                    rhs.value_);
  return result;
}

Fixed& Fixed::operator++() {
  this->value_ += 1;

  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);

  this->value_ += 1;

  return temp;
}

Fixed& Fixed::operator--() {
  this->value_ -= 1;

  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);

  this->value_ -= 1;

  return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (b < a) ? b : a; }

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  return (b < a) ? b : a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a < b) ? b : a; }

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  return (a < b) ? b : a;
}
