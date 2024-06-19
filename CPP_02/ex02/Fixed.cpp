#include "Fixed.hpp"

Fixed::Fixed() : _nbInt(0){}

Fixed::Fixed(const Fixed& to_copy)
{
	*this = to_copy;
}

Fixed::Fixed(const int nbInt)
{
	_nbInt = nbInt << _fractionalBits;
}

Fixed::Fixed(const float nbFloat)
{
	_nbInt = (int)roundf(nbFloat * (1 << _fractionalBits));
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)
		return *this;
	_nbInt = other.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_nbInt > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_nbInt < other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_nbInt <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_nbInt == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_nbInt != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	newNb(_nbInt + other.getRawBits());
	return (newNb);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	newNb(_nbInt - other.getRawBits());
	return (newNb);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	newNb(this->toFloat() * other.toFloat());
	return (newNb);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	newNb(this->toFloat() / other.toFloat());
	return (newNb);
}


Fixed&	Fixed::operator++(void)
{
	_nbInt++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	_nbInt++;
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	_nbInt--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	_nbInt--;
	return (tmp);
}

Fixed&	min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return (os);
}

int	Fixed::getRawBits( void ) const
{
	return _nbInt;
}

void	Fixed::setRawBits( int const raw )
{
	_nbInt = raw;
}

int	Fixed::toInt( void ) const
{
	return (_nbInt >> _fractionalBits);
}

float	Fixed::toFloat( void ) const
{
	return ((float) _nbInt / (1 << _fractionalBits));
}
