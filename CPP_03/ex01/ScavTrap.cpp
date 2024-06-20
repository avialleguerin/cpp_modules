#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "*NoName*";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Default Constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	*this = other;
}

ScavTrap::~ScavTrap() {}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return(*this);
}

void	ScavTrap::displayPoints(void)
{
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Hit Points: " << _hitPoints << std::endl;
	std::cout << "Energy Points: " << _energyPoints << std::endl;
	std::cout << "Attack Damages: " << _attackDamage << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap named " << _name << "is now in Gate keeper mode";
}
