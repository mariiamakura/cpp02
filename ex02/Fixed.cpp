/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:35:54 by mparasku          #+#    #+#             */
/*   Updated: 2023/09/13 11:45:28 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    //std::cout << "Default constructor called" << std::endl;
    this->_fixedNum = 0;
}

Fixed::Fixed(const int input) {
    //std::cout << "Int constructor called" << std::endl;
    this->_fixedNum = input << this->_fractionalBits;
}

Fixed::Fixed(const float input) {
    //std::cout << "Float constructor called" << std::endl;
    this->_fixedNum = roundf(input * (1 << this->_fractionalBits));
}

Fixed::~Fixed() {
    //std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    //std::cout << "Copy constructor called" << std::endl;
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

//comparison
bool Fixed::operator>(Fixed fixed) const {
    return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(Fixed fixed) const {
    return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator<=(Fixed fixed) const {
    return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator>=(Fixed fixed) const {
    return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator==(Fixed fixed) const {
    return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(Fixed fixed) const {
    return (this->toFloat() != fixed.toFloat());
}

//arithmetic operators
Fixed Fixed::operator+(Fixed fixed) const {
    return (this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(Fixed fixed) const {
    return (this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(Fixed fixed) const {
    return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(Fixed fixed) const {
    return (this->toFloat() / fixed.toFloat());
}

//increments
Fixed Fixed::operator++() {
    //std::cout << "preincrement" << std::endl;
    this->_fixedNum++;
    return (*this);
}

Fixed Fixed::operator--() {
    this->_fixedNum--;
    return (*this);
}

Fixed Fixed::operator++(int) {
    //std::cout << "post-increment" << std::endl;
    Fixed temp = *this;
    this->_fixedNum++;
    return (temp);
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_fixedNum--;
    return (temp);
}

//min/max functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a.toFloat() <= b.toFloat())
        return (a);
    else
        return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a.toFloat() <= b.toFloat())
        return (a);
    else
        return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a.toFloat() >= b.toFloat())
        return (a);
    else
        return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a.toFloat() >= b.toFloat())
        return (a);
    else
        return (b);
}


