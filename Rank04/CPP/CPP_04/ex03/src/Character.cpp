#include "../inc/Character.hpp"

AMateria*	Character::_droppedItems = '\0';

/************************* ORTHODOX CANONICAL FORM ****************************/

Character::Character() : 
	_name("Default")
{
	for (int i = 0; i < INV_SIZE; i++)
		_inventory[i] = '\0';
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) : 
	_name(name)
{
	for (int i = 0; i < INV_SIZE; i++)
		_inventory[i] = '\0';
	std::cout << "Character " << name << " created." << std::endl;
}

Character::Character(const Character &other) :
	_name(other._name)
{
	AMateria*	m;
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (other.getItem(i) && other.getItem(i)->getType() == "ice")
			m = new Ice(other.getItem(i));
		if (other.getItem(i) && other.getItem(i)->getType() == "cure")
			m = new Cure(other.getItem(i));
	}
	std::cout << "Character copy constructor called"<< std::endl;
}

Character& Character::operator=(const Character &other)
{
	if (this != &other) {
		_name = other._name;
		deleteInventory(this);
		for (int i = 0; i < INV_SIZE; i++)
		{
			if (other.getItem(i) && other.getItem(i)->getType() == "ice")
				m = new Ice(other.getItem(i));
			if (other.getItem(i) && other.getItem(i)->getType() == "cure")
				m = new Cure(other.getItem(i));
		}
	}
	std::cout << "Character Assignment Operator Called" << std::endl;

	return (*this);
}

Character::~Character()
{
	deleteInventory(this);
	std::cout << "Character was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

std::string const & Character::getName() const
{
	return (_name);
}

AMateria *Character::getItem(int i) const
{
	if (i > 0 && i < INV_SIZE)
		return (_inventory[i]);
	return ('\0');
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (_inventory[idx])
	{
		_inventory[idx] = '\0';
		//TODO: handle materia with dropItem
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx])
		_inventory[idx]->use(target);
}

void	Character::dropItem()
{

}

/****************************** OTHER FUNCTIONS *******************************/

void	deleteInventory(Character *target)
{
	for (int i = 0; i < INV_SIZE; i++)
		if (target->getItem(i))
			delete target->getItem(i);
}
