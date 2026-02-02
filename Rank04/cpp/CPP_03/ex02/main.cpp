#include "include/FragTrap.hpp"

int	main(void)
{
	FragTrap	Berta("Berta");
	std::string	target = "Dax";

	Berta.takeDamage(9);
	Berta.beRepaired(2);
	for (int i = 0; i < 10; i++)
		Berta.attack(target);
	Berta.highFivesGuys();
	Berta.takeDamage(92);
	Berta.takeDamage(1);
	Berta.highFivesGuys();
}
