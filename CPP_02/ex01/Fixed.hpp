#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_nbInt;
	static const int	_fractionalBits = 8;
public:
	Fixed();
	Fixed(const int nbInt);
	Fixed(const float nbFloat);
	Fixed(const Fixed& other);
	~Fixed();
	Fixed&	operator=(const Fixed& other);
	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

std::ostream&	operator<<(std::ostream& os, const Fixed& other);

#endif