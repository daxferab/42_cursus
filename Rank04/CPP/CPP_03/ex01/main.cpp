#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"

int	main(void)
{
	ScavTrap	Berta("Berta");
	std::string	target = "Dax";

	Berta.takeDamage(9);
	Berta.beRepaired(2);
	for (int i = 0; i < 5; i++)
		Berta.attack(target);
	Berta.takeDamage(9);
	Berta.guardGate();
}
