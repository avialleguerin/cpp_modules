#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(" ")
{
	_name = "*NoName*";
	std::cout << "DiamondTrap " << _name << " has been created" << std::endl;
	_hitPoints = ScavTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = ScavTrap::_attackDamage;
	
}

DiamondTrap::DiamondTrap(const std::string& name) : ScavTrap(name)
{
	std::cout << "DiamondTrap " << _name << " has been created" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
	std::cout << "Copy DimaondTrap " << _name << " has been created\n" << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DimaondTrap " << _name << " has been destroyed" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return(*this);
}

void DiamondTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "DiamondTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "DiamondTrap " << _name << " need Hit Points and Energy Point to attack." << std::endl;
}

void	DiamondTrap::displayPoints(void)
{
	std::cout << std::endl;
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Hit Points: " << _hitPoints << std::endl;
	std::cout << "Energy Points: " << _energyPoints << std::endl;
	std::cout << "Attack Damages: " << _attackDamage << std::endl;
	std::cout << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My Diamond name is " << _name << std::endl;
}
