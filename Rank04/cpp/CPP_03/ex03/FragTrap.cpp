#include "include/FragTrap.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Created FragTrap " << _name << ". Overrides ClapTrap with the stats:" << std::endl;
	std::cout << "	[HP] -> " << _hitPoints << std::endl;
	std::cout << "	[EP] -> " << _energyPoints << std::endl;
	std::cout << "	[AD] -> " << _attackDamage << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called, copied from " << other._name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap Assignment Operator Called" << std::endl;

	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

void	FragTrap::highFivesGuys() const
{
	if (_hitPoints <= 0)
		std::cout << "FragTrap " << _name << " is dead:(" << std::endl;
	else
		std::cout << "FragTrap " << _name << " wants to high five!" << std::endl;
}
