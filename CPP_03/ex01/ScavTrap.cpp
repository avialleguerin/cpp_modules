#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "*NoName*";
	std::cout << "ScavTrap " << _name << " has been created" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) 
{
	std::cout << "ScavTrap " << _name << " has been created" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "Copy ScavTrap " << _name << " has been created" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been destroyed" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return(*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << " need Hit Points and Energy Point to attack." << std::endl;
}

void	ScavTrap::displayPoints(void)
{
	std::cout << std::endl;
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Hit Points: " << _hitPoints << std::endl;
	std::cout << "Energy Points: " << _energyPoints << std::endl;
	std::cout << "Attack Damages: " << _attackDamage << std::endl;
	std::cout << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap named " << _name << " is now in Gate keeper mode" << std::endl;
}
