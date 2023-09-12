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
    private:
        int _fixedNum;
        static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif