#include "Fixed.hpp"

Fixed::Fixed() : _nbInt(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed::Fixed(const int nbInt)
{
	std::cout << "Int constructor called" << std::endl;
	_nbInt = nbInt << _fractionalBits;
}

Fixed::Fixed(const float nbFloat)
{
	std::cout << "Float constructor called" << std::endl;
	_nbInt = (int)roundf(nbFloat * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	_nbInt = other.getRawBits();
	return *this;
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
