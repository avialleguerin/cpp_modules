#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string	_type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal();
	WrongAnimal&	operator=(const WrongAnimal& other);
	std::string		getType() const;
	virtual void	makeSound() const;
};

#endif