#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
 private:
  int value_;

  static const int fractionalBits_ = 8;

 public:
  Fixed();

  Fixed(const int);

  Fixed(const float);

  Fixed(const Fixed& other);

  Fixed& operator=(const Fixed& other);

  ~Fixed();

  void setRawBits(int const raw);

  int getRawBits(void) const;

  float toFloat(void) const;

  int toInt(void) const;

  bool operator>(const Fixed& rhs) const;

  bool operator<(const Fixed& rhs) const;

  bool operator>=(const Fixed& rhs) const;

  bool operator<=(const Fixed& rhs) const;

  bool operator==(const Fixed& rhs) const;

  bool operator!=(const Fixed& rhs) const;

  Fixed operator+(const Fixed& rhs) const;

  Fixed operator-(const Fixed& rhs) const;

  Fixed operator*(const Fixed& rhs) const;

  Fixed operator/(const Fixed& rhs) const;

  Fixed& operator++();

  Fixed operator++(int);

  Fixed& operator--();

  Fixed operator--(int);

  static Fixed& min(Fixed& a, Fixed& b);

  static const Fixed& min(const Fixed& a, const Fixed& b);

  static Fixed& max(Fixed& a, Fixed& b);

  static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
