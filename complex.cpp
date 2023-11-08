#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    // Overload the + operator to add complex numbers
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overload the - operator to subtract complex numbers
    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Overload the * operator to multiply complex numbers
    Complex operator*(const Complex& other) {
        return Complex(real * other.real - imaginary * other.imaginary, real * other.imaginary + imaginary * other.real);
    }

    // Overload the << operator to display complex numbers
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex) {
        os << complex.real;
        if (complex.imaginary >= 0) {
            os << " + " << complex.imaginary << "i";
        } else {
            os << " - " << -complex.imaginary << "i";
        }
        return os;
    }
};

int main() {
    Complex num1(3.0, 4.0);
    Complex num2(1.0, -2.0);

    Complex sum = num1 + num2;
    Complex difference = num1 - num2;
    Complex product = num1 * num2;

    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;

    return 0;
}
