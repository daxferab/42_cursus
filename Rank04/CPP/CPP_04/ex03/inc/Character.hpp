#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#define INV_SIZE 4

class Character : public ICharacter
{
	private:
		std::string			_name;
		AMateria*			_inventory[INV_SIZE];

		static AMateria*	_droppedItems;

	public:
		Character();
		Character(std::string name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();

		std::string const	&getName() const;
		AMateria 			*getItem(int i) const;
		void 				equip(AMateria* m);
		void 				unequip(int idx);
		void				use(int idx, ICharacter& target);
		void				dropItem();
};

void	deleteInventory(Character *target);

#endif
