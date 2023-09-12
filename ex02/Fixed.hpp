#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
    public:
        //constructors
        Fixed();
        Fixed(const int input);
        Fixed(const float input);

        ~Fixed();
        //copy constructor will be called auto when you try to copy the class obj
        Fixed(const Fixed &other);
        //copy assignment operator overload
        Fixed &operator=(const Fixed &rhs);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        //comparison
        bool operator>(Fixed fixed) const;
        bool operator<(Fixed fixed) const;
        bool operator>=(Fixed fixed) const;
        bool operator<=(Fixed fixed) const;
        bool operator==(Fixed fixed) const;
        bool operator!=(Fixed fixed) const;

        //arithmetic operators
        float operator+(Fixed fixed) const;
        float operator-(Fixed fixed) const;
        float operator*(Fixed fixed) const;
        float operator/(Fixed fixed) const;

        //pre-increment (++i -> i+1, i = i)
        //The prefix form returns the value after the increment or decerement was performed.
        Fixed operator++();
        Fixed operator--();

        //post-increment (i++ -> i = i, i + 1)
        //The postfix form returns the value before the increment or decerement was performed.
        Fixed operator++(int);
        Fixed operator--(int);

        //max/min functions
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
    private:
        int _fixedNum;
        static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif