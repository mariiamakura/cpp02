#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
    public:
        Fixed();
        ~Fixed();
        //copy constructor will be called auto when you try to copy the class obj
        Fixed(const Fixed &other);
        //copy assignment operator overload
        Fixed &operator=(const Fixed &rhs);
        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _fixedNum;
        static const int _fractionalBits = 8;
};

#endif