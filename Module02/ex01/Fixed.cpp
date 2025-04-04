#include "Fixed.hpp"

void Fixed::setRawBits( int const raw )
{
	fixed_point = raw;
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
	return fixed_point;
}

int Fixed::toInt( void ) const
{
	return fixed_point / (1 << fractionalBits);
}

float Fixed::toFloat( void ) const
{
	return (float)fixed_point / (1 << fractionalBits);
}

Fixed::Fixed(const float nbr):fixed_point(nbr)
{
    std::cout << "Float constructor called" << std::endl;
	fixed_point = roundf(nbr * (1 << fractionalBits));
}

Fixed::Fixed(const int nbr):fixed_point(nbr)
{
    std::cout << "Int constructor called" << std::endl;
	fixed_point = nbr * (1 << fractionalBits);
}

Fixed::Fixed() : fixed_point()
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    *this = copy;
    std::cout << "Copy constructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return out;
}

Fixed &Fixed::operator = (const Fixed &copy) {
    if (this != &copy)
        this->fixed_point = copy.getRawBits();
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}