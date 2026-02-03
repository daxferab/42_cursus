#include "include/ScavTrap.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Created ScavTrap " << _name << ". Overrides ClapTrap with the stats:" << std::endl;
	std::cout << "	[HP] -> " << _hitPoints << std::endl;
	std::cout << "	[EP] -> " << _energyPoints << std::endl;
	std::cout << "	[AD] -> " << _attackDamage << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called, copied from " << other._name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap Assignment Operator Called" << std::endl;

	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
		std::cout << "ScavTrap " << _name << " can't attack from the afterlife." << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ScavTrap " << _name << " ran out of energy points." << std::endl;
	else
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage." << std::endl;
	}
}

void	ScavTrap::guardGate() const
{
	if (_hitPoints <= 0)
		std::cout << "ScavTrap " << _name << " is dead:(" << std::endl;
	else
		std::cout << "Scavtrap " << _name << " is now in Gate-keeper mode." << std::endl;
}
