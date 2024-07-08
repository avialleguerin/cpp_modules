#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("*NoName*"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :  _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy ClapTrap " << _name << " has been created" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return(*this);
}
void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " need Hit Points and Energy Point to attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already disabled" << std::endl;
		return ;
	}
	if (_hitPoints >= amount)
		std::cout << "ClapTrap " << _name << " took " << amount << " points of damage" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " took " << _hitPoints << " points of damage" << std::endl;
	if (_hitPoints >= amount)
		_hitPoints -= amount;
	else
		_hitPoints = 0;
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is now disabled" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " recovered " << amount << " Hit Points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " can't repair because he has no Energy or Hit Points left" << std::endl;
}

void	ClapTrap::displayPoints(void)
{
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Hit Points: " << _hitPoints << std::endl;
	std::cout << "Energy Points: " << _energyPoints << std::endl;
	std::cout << "Attack Damages: " << _attackDamage << std::endl;
	std::cout << std::endl;
}
