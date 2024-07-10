#include "Character.hpp"

Character::Character(): _name("*NoName*")
{
	for (int i = 0; i <= 3; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	for (int i = 0; i <= 3; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other)
{
	*this = other;
}

std::string const&	Character::getName() const
{
	return (_name);
}

Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i <= 3; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);

}

void	Character::equip(AMateria* m)
{
	int	i = 0;

	while (i <= 3 && _inventory[i])
		i++;
	if (i > 3)
		return ;
	_inventory[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx])
		_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx])
		_inventory[idx]->use(target);
}
