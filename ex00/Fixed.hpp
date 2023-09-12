/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:35:35 by mparasku          #+#    #+#             */
/*   Updated: 2023/09/12 16:35:36 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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