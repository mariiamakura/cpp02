/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:35:44 by mparasku          #+#    #+#             */
/*   Updated: 2023/09/12 16:35:45 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->_fixedNum = 0;
}

Fixed::Fixed(const int input) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedNum = input << this->_fractionalBits;
}

Fixed::Fixed(const float input) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedNum = roundf(input * (1 << this->_fractionalBits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    //*this = other; //not good practice
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
        //this->_fixedNum = rhs._fixedNum;
    }
    return *this;
}

int Fixed::getRawBits() const {
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedNum);
}

void Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedNum = raw;
}

float Fixed::toFloat() const {
    return ((float)this->_fixedNum / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt() const {
    return (this->_fixedNum >> this->_fractionalBits);
}
std::ostream &operator<<(std::ostream &o, Fixed const &fixed) {
    o << fixed.toFloat();
    //o << fixed.toInt();
    //o << fixed.getRawBits(); for binary
    return (o);
}


