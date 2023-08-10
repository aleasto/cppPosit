#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <posit.h>
#include <iostream>

TEST_CASE("FP Initialization", "[short]") {
  using P = posit::Posit<int16_t, 16, 2, uint32_t, posit::PositSpec::WithInfs>;
  P a = P::from_sraw(14336);
  P b(0.5f);
  P c(0.5);
  P d(6.40675e-27f);
  P empty;
  REQUIRE(a == b);
  REQUIRE(a == c);
  REQUIRE(d.v == 1);
  REQUIRE(empty == P(0.f));
}

TEST_CASE("Arithmetic", "[short]") {
  using P = posit::Posit<int16_t, 16, 2, uint32_t, posit::PositSpec::WithInfs>;
  P a(0.5f);
  P b(0.5f);
  REQUIRE(a+b == P(1.f));
  REQUIRE(a*b == P(0.25f));
  REQUIRE(a-b == P(0.f));
  REQUIRE(a/b == P(1.f));

  P c(0.5f);
  c+=a;
  REQUIRE(c == P(1.f));
  c-=a;
  REQUIRE(c == P(0.5f));
  c*=a;
  REQUIRE(c == P(0.25f));
  c/=a;
  REQUIRE(c == P(0.5f));

  REQUIRE(c+c >= c);
  REQUIRE(c+c > c);
  REQUIRE(c*c <= c);
  REQUIRE(c*c < c);
  REQUIRE(c == 0.5f);
  REQUIRE(c == 0.5);
  REQUIRE(c != P(0.f));
}

TEST_CASE("Utility functions", "[short]") {
    using P = posit::Posit<int16_t, 16, 2, uint32_t, posit::PositSpec::WithNan>;
    using P2 = posit::Posit<int16_t, 16, 2, uint32_t, posit::PositSpec::WithInfs>;

    P a(0.5f), c = P::nan(), z = P::zero();
    P b = a.next();
    P2 d = P2::inf(), e = P2::ninf(), f =P2::infinity(), g = P2::pinf();
    REQUIRE(a.v + 1 == b.v);
    REQUIRE(c.next().v == c.v);
    REQUIRE((c+c).is_nan());
    REQUIRE(d.is_infinity());
    REQUIRE((e+e).is_infinity());
    REQUIRE((f+f).is_infinity());
    REQUIRE((g+g).is_infinity());
    REQUIRE((d+d).is_infinity());
    REQUIRE((z+z).is_zero());
    std::cout << a << std::endl;
    std::cout << std::hex << a << std::endl;
}

TEST_CASE("Test Unpacked","[short]") {
    using P = posit::Posit<int16_t, 16, 2, uint32_t, posit::PositSpec::WithNan>;
    using UP = P::BackendT;
    UP uinf = UP::infinity(), pinf = UP::pinfinity(), ninf = UP::ninfinity();
    UP unan = UP::nan(), one = UP::one(), zero = UP::zero();

    UP a1 = uinf+zero;
    UP a2 = uinf+one;

    REQUIRE((uinf+uinf).isInfinity());
    REQUIRE((a2).isInfinity());
    REQUIRE((a1).isInfinity());
    REQUIRE((pinf+pinf).isInfinity());
    REQUIRE((ninf+ninf).isInfinity());
    REQUIRE((unan+unan).isNaN());
    REQUIRE((one-one).isZero());
    REQUIRE((zero+zero).isZero());
}