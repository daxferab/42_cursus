#include "include/ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Berta("Berta");
	std::string	target = "Dax";

	Berta.takeDamage(9);			// Lose 9hp
	Berta.beRepaired(2);			// Repair 2hp
	for (int i = 0; i < 10; i++)
		Berta.attack(target);		// Attack 10 times (-10ep)
	Berta.takeDamage(9);			// Lose 9hp (die)
	Berta.attack(target);			// Attack when dead
	Berta.takeDamage(1);			// Lose hp when dead
	Berta.beRepaired(1);			// Repair when dead
}
