#include "Fixed.hpp"



Fixed &Fixed::operator--()
{
    --fixed_point;
    return *this;
}
Fixed &Fixed::operator++()
{
    ++fixed_point;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->fixed_point++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->fixed_point--;
    return tmp;
}

Fixed Fixed::operator*(Fixed const &other)
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other)
{
    return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator > (Fixed const &other)
{
    return this->fixed_point > other.fixed_point;
}

bool Fixed::operator < (Fixed const &other)
{
    return this->fixed_point < other.fixed_point;
}

bool Fixed::operator >= (Fixed const &other)
{
    return this->fixed_point >= other.fixed_point;
}

bool Fixed::operator <= (Fixed const &other)
{
    return this->fixed_point <= other.fixed_point;
}

bool Fixed::operator != (Fixed const &other)
{
    return this->fixed_point <= other.fixed_point;
}


bool Fixed::operator == (Fixed const &other)
{
    return this->fixed_point == other.fixed_point;
}

Fixed& Fixed::max(Fixed  &a, Fixed  &b)
{
    if(a.fixed_point > b.fixed_point)
        return a;
	return b;
}

Fixed& Fixed::min(Fixed  &a, Fixed  &b)
{
    if(a.fixed_point < b.fixed_point)
        return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if(a.fixed_point > b.fixed_point)
        return a;
	return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if(a.fixed_point < b.fixed_point)
        return a;
	return b;
}

int Fixed::toInt( void ) const
{
	return fixed_point / (1 << fractionalBits);
}

float Fixed::toFloat( void ) const
{
	return (float)fixed_point / (1 << fractionalBits);
}

Fixed::Fixed(float nbr):fixed_point(nbr)
{
    // std::cout << "Float constructor called" << std::endl;
	fixed_point = roundf(nbr * (1 << fractionalBits));
}

Fixed::Fixed(int nbr):fixed_point(nbr)
{
    // std::cout << "Int constructor called" << std::endl;
	fixed_point = nbr * (1 << fractionalBits);
}

Fixed::Fixed() : fixed_point()
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    *this = copy;
    // std::cout << "Copy constructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return out;
}

Fixed &Fixed::operator = (const Fixed &copy) {
    if (this != &copy)
        this->fixed_point = copy.fixed_point;
    // std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}