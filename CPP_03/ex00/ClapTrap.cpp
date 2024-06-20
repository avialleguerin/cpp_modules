#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(0), _energyPoints(10), _attackDamage(0) {}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

ClapTrap::~ClapTrap() {}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << "attacks" << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << "need Hit Points and Energy Point to attack." << std::endl;
		std::cout << "Hit Point left: " << _hitPoints << std::endl;
		std::cout << "Energy Point left: " << _energyPoints << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
	}
}
