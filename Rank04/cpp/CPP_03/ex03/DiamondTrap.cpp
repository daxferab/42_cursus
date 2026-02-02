#include "include/DiamondTrap.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "Created DiamondTrap " << _name << std::endl;
	std::cout << "Inherits [HP] from FragTrap -> " << _hitPoints << std::endl;
	std::cout << "Inherits [EP] from ScavTrap -> " << _energyPoints << std::endl;
	std::cout << "Inherits [AD] from FragTrap -> " << _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name")
{
	_name = "default";
	std::cout << "DiamondTrap default constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called, copied from " << other._name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other) {
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
	}
	std::cout << "DiamondTrap Assignment Operator Called" << std::endl;

	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
