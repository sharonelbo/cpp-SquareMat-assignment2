// main.cpp
// Author: YOUR_EMAIL_HERE

#include "include/SquareMat.hpp"
#include <iostream>

using namespace sqaremat;

int main() {
    try {
        SquareMat a(2);
        SquareMat b(2);

        // Manual initialization
        a[0][0] = 1; a[0][1] = 2;
        a[1][0] = 3; a[1][1] = 4;

        b[0][0] = 5; b[0][1] = 6;
        b[1][0] = 7; b[1][1] = 8;

        std::cout << "Matrix A:\n" << a;
        std::cout << "Matrix B:\n" << b;

        std::cout << "A + B:\n" << (a + b);
        std::cout << "A - B:\n" << (a - b);
        std::cout << "-A:\n" << (-a);
        std::cout << "A * B:\n" << (a * b);
        std::cout << "A * 2:\n" << (a * 2);
        std::cout << "2 * B:\n" << (2 * b);
        std::cout << "A % B (element-wise):\n" << (a % b);
        std::cout << "A % 3:\n" << (a % 3);
        std::cout << "A / 2:\n" << (a / 2);
        std::cout << "A ^ 2:\n" << (a ^ 2);

        std::cout << "++A:\n" << (++a);
        std::cout << "A++ (print original):\n" << (a++);
        std::cout << "After A++ (current A):\n" << a;

        std::cout << "--B:\n" << (--b);
        std::cout << "B-- (print original):\n" << (b--);
        std::cout << "After B-- (current B):\n" << b;

        std::cout << "Transpose of A:\n" << (~a);

        std::cout << "A == B: " << (a == b) << '\n';
        std::cout << "A != B: " << (a != b) << '\n';
        std::cout << "A > B: " << (a > b) << '\n';
        std::cout << "A <= B: " << (a <= b) << '\n';

        std::cout << "Determinant of A (!A): " << !a << '\n';
        std::cout << "Determinant of B (!B): " << !b << '\n';

        // Compound assignment test
        a += b;
        std::cout << "A += B:\n" << a;
        a -= b;
        std::cout << "A -= B:\n" << a;
        a *= 2;
        std::cout << "A *= 2:\n" << a;
        a /= 2;
        std::cout << "A /= 2:\n" << a;
        a %= b;
        std::cout << "A %= B:\n" << a;
        a %= 2;
        std::cout << "A %= 2:\n" << a;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    return 0;
}
