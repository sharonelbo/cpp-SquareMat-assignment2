// Email: sharon4homework@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/SquareMat.hpp"

using namespace sqaremat;

TEST_CASE("Addition operator +") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 5; b[0][1] = 6; b[1][0] = 7; b[1][1] = 8;
    SquareMat c = a + b;
    CHECK(c[0][0] == 6);
    CHECK(c[1][1] == 12);

    SUBCASE("Addition size mismatch throws") {
        SquareMat d(3);
        CHECK_THROWS_AS(a + d, std::invalid_argument);
    }
}

TEST_CASE("Subtraction operator -") {
    SquareMat a(2), b(2);
    a[0][0] = 9; a[0][1] = 5; a[1][0] = 2; a[1][1] = 1;
    b[0][0] = 4; b[0][1] = 3; b[1][0] = 2; b[1][1] = 1;
    SquareMat c = a - b;
    CHECK(c[0][0] == 5);
    CHECK(c[1][1] == 0);

    SUBCASE("Subtraction size mismatch throws") {
        SquareMat d(3);
        CHECK_THROWS_AS(a - d, std::invalid_argument);
    }
}

TEST_CASE("Unary minus operator") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = -2;
    a[1][0] = 0; a[1][1] = 4;
    SquareMat b = -a;
    CHECK(b[0][0] == -1);
    CHECK(b[0][1] == 2);
    CHECK(b[1][0] == 0);
    CHECK(b[1][1] == -4);
}

TEST_CASE("Matrix multiplication operator *") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 2; b[0][1] = 0; b[1][0] = 1; b[1][1] = 2;
    SquareMat c = a * b;
    CHECK(c[0][0] == 4);
    CHECK(c[0][1] == 4);
    CHECK(c[1][0] == 10);
    CHECK(c[1][1] == 8);

    SUBCASE("Multiplication size mismatch throws") {
        SquareMat d(3);
        CHECK_THROWS_AS(a * d, std::invalid_argument);
    }
}

TEST_CASE("Scalar multiplication operator *") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
    SquareMat b = a * 2;
    CHECK(b[0][0] == 2);
    CHECK(b[1][1] == 8);

    SquareMat c = 3 * a;
    CHECK(c[0][1] == 6);
    CHECK(c[1][0] == 9);
}

TEST_CASE("Scalar division operator /") {
    SquareMat a(2);
    a[0][0] = 2; a[0][1] = 4; a[1][0] = 6; a[1][1] = 8;
    SquareMat b = a / 2;
    CHECK(b[0][0] == 1);
    CHECK(b[1][1] == 4);

    SUBCASE("Division by zero throws") {
        CHECK_THROWS_AS(a / 0, std::invalid_argument);
    }
}

TEST_CASE("Modulo operations") {
    SquareMat a(2), b(2);
    a[0][0] = 5; a[0][1] = 12; a[1][0] = 9; a[1][1] = 7;
    b[0][0] = 2; b[0][1] = 3; b[1][0] = 1; b[1][1] = 4;
    SquareMat c = a % b;
    CHECK(c[0][0] == 10);
    CHECK(c[1][1] == 28);

    SUBCASE("Element-wise modulo with size mismatch throws") {
        SquareMat d(3);
        CHECK_THROWS_AS(a % d, std::invalid_argument);
    }

    SUBCASE("Modulo with scalar") {
        SquareMat m = a % 4;
        CHECK(m[0][0] == 1);
        CHECK(m[0][1] == 0);
    }
}

TEST_CASE("Power operator ^") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    SquareMat b = a ^ 2;
    CHECK(b[0][0] == 7);
    CHECK(b[0][1] == 10);
    CHECK(b[1][0] == 15);
    CHECK(b[1][1] == 22);

    SUBCASE("Power of zero returns identity") {
        SquareMat id = a ^ 0;
        CHECK(id[0][0] == 1);
        CHECK(id[0][1] == 0);
        CHECK(id[1][0] == 0);
        CHECK(id[1][1] == 1);
    }

    SUBCASE("Negative power throws") {
        CHECK_THROWS_AS(a ^ -1, std::invalid_argument);
    }
}

TEST_CASE("Determinant operator !") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;
    CHECK(!a == doctest::Approx(-2.0));

    SquareMat b(1);
    b[0][0] = 5;
    CHECK(!b == 5);
}

TEST_CASE("Equality and comparison operators") {
    SquareMat a(2), b(2), c(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4; // sum = 10
    b[0][0] = 4; b[0][1] = 3; b[1][0] = 2; b[1][1] = 1; // sum = 10
    c[0][0] = 5; c[0][1] = 5; c[1][0] = 5; c[1][1] = 5; // sum = 20

    CHECK(a == b);
    CHECK(a != c);
    CHECK(c > a);
    CHECK(a <= c);
    CHECK(!(a < b));
}

TEST_CASE("Transpose operator ~") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    SquareMat t = ~a;
    CHECK(t[0][0] == 1);
    CHECK(t[1][0] == 2);
    CHECK(t[0][1] == 3);
    CHECK(t[1][1] == 4);
}

TEST_CASE("Increment and decrement operators") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    SquareMat pre = ++a;
    CHECK(pre[0][0] == 2);
    CHECK(a[1][1] == 5);

    SquareMat post = a++;
    CHECK(post[0][0] == 2);
    CHECK(a[0][0] == 3);

    SquareMat preD = --a;
    CHECK(preD[0][0] == 2);

    SquareMat postD = a--;
    CHECK(postD[0][0] == 2);
    CHECK(a[0][0] == 1);
}
