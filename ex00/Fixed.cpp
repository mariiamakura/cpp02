#include "Fixed.hpp"

Fixed::Fixed() {
    this->_fixedNum = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    //*this = src; - not good practice
    //Using *this = src; inside the copy constructor correctly copies the contents, but you need to be cautious. If your class contains dynamically allocated resources (e.g., memory), this line may result
    //in infinite recursion because it will invoke the copy constructor again and again.
    //To avoid this, you should directly copy the individual data members from src to *this without invoking the copy constructor recursively.
    this->_fixedNum = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_fixedNum = rhs.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedNum);
}

void Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedNum = raw;
}



