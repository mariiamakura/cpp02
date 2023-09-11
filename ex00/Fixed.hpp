class Fixed {
    public:
        Fixed();
        ~Fixed();
        //copy constructor will be called auto when you try to copy the class obj
        Fixed(const Fixed &other);
        Fixed operator=(const Fixed &rhs);
};