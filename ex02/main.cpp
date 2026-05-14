#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;

  std::cout << "========== 比較演算子のテスト ==========" << std::endl;
  Fixed c1(5.5f);
  Fixed c2(5.5f);
  Fixed c3(2.1f);
  std::cout << std::boolalpha;  // booleanをtrue/falseで表示
  std::cout << "c1(5.5), c2(5.5), c3(2.1)" << std::endl;
  std::cout << "c1 > c3  : " << (c1 > c3) << " (expected: true)" << std::endl;
  std::cout << "c3 > c1  : " << (c3 > c1) << "(expected: false)" << std::endl;
  std::cout << "c3 < c1  : " << (c3 < c1) << " (expected: true)" << std::endl;
  std::cout << "c1 < c3  : " << (c1 < c3) << "(expected: false)" << std::endl;
  std::cout << "c1 >= c2 : " << (c1 >= c2) << " (expected: true)" << std::endl;
  std::cout << "c3 >= c1 : " << (c3 >= c1) << "(expected: false)" << std::endl;
  std::cout << "c3 <= c1 : " << (c3 <= c1) << " (expected: true)" << std::endl;
  std::cout << "c1 <= c3 : " << (c1 <= c3) << "(expected: false)" << std::endl;
  std::cout << "c1 == c2 : " << (c1 == c2) << " (expected: true)" << std::endl;
  std::cout << "c1 == c3 : " << (c1 == c3) << "(expected: false)" << std::endl;
  std::cout << "c1 != c3 : " << (c1 != c3) << " (expected: true)" << std::endl;
  std::cout << "c1 != c2 : " << (c1 != c2) << "(expected: false)" << std::endl;

  std::cout << "\n========== 算術演算子のテスト（負の値含む） =========="
            << std::endl;
  Fixed a1(-2.5f);
  Fixed a2(2.0f);
  std::cout << "a1(-2.5), a2(2.0)" << std::endl;
  std::cout << "a1 + a2 : " << (a1 + a2) << " (expected: -0.5)" << std::endl;
  std::cout << "a1 - a2 : " << (a1 - a2) << " (expected: -4.5)" << std::endl;
  std::cout << "a1 * a2 : " << (a1 * a2) << " (expected: -5)" << std::endl;
  std::cout << "a1 / a2 : " << (a1 / a2) << " (expected: -1.25)" << std::endl;

  std::cout << "\n========== インクリメント/デクリメントのテスト =========="
            << std::endl;
  Fixed inc(0);
  std::cout << "[インクリメント]" << std::endl;
  std::cout << "初期値          : " << inc << std::endl;
  std::cout << "前置 (++inc)    : " << ++inc << " <- 増加後の値が返る"
            << std::endl;
  std::cout << "前置実行後の値  : " << inc << std::endl;
  std::cout << "後置 (inc++)    : " << inc++ << " <- 増加前の値が返る"
            << std::endl;
  std::cout << "後置実行後の値  : " << inc << std::endl;

  Fixed dec(0);
  std::cout << "\n[デクリメント]" << std::endl;
  std::cout << "初期値          : " << dec << std::endl;
  std::cout << "前置 (--dec)    : " << --dec << " <- 減少後の値が返る"
            << std::endl;
  std::cout << "前置実行後の値  : " << dec << std::endl;
  std::cout << "後置 (dec--)    : " << dec-- << " <- 減少前の値が返る"
            << std::endl;
  std::cout << "後置実行後の値  : " << dec << std::endl;

  std::cout << "\n========== min/maxのテスト ==========" << std::endl;
  Fixed m1(10.5f);
  Fixed m2(20.5f);
  const Fixed cm1(10.5f);
  const Fixed cm2(20.5f);
  std::cout << "非const版 min(10.5, 20.5) : " << Fixed::min(m1, m2)
            << std::endl;
  std::cout << "非const版 max(10.5, 20.5) : " << Fixed::max(m1, m2)
            << std::endl;
  std::cout << "const版 min(10.5, 20.5)   : " << Fixed::min(cm1, cm2)
            << std::endl;
  std::cout << "const版 max(10.5, 20.5)   : " << Fixed::max(cm1, cm2)
            << std::endl;
  Fixed equal1(5.0f);
  Fixed equal2(5.0f);
  std::cout << "equal1's address   : " << &equal1 << std::endl;
  std::cout << "equal2's address   : " << &equal2 << std::endl;
  Fixed& minRef = Fixed::min(equal1, equal2);
  std::cout << "min returned value : " << minRef << std::endl;
  std::cout << "min returned addr  : " << &minRef << std::endl;

  std::cout << "\n========== toInt/toFloatのテスト ==========" << std::endl;
  Fixed conv(42.42f);
  std::cout << "Fixedオブジェクト : " << conv << std::endl;
  std::cout << "toInt()の結果     : " << conv.toInt() << std::endl;
  std::cout << "toFloat()の結果   : " << conv.toFloat() << std::endl;

  std::cout << "\n========== ゼロ、境界値のテスト ==========" << std::endl;
  Fixed zero(0);
  Fixed neg_zero(-0.0f);
  std::cout << "zero == -0.0f : " << (zero == neg_zero) << " (expected: true)"
            << std::endl;
  std::cout << "Fixed(0.001f) : " << Fixed(0.001f)
            << " (expected: 0, precision以下)" << std::endl;
  return 0;
}
