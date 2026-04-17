#include "include/easyfind.hpp"
#include <exception>
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main(void)
{
	{
		std::vector<int> vectorCont;
		int n = 3;
		std::cout << "My vector container: " << std::endl;
		for (int i = 0; i < 10; i++)
		{
			vectorCont.push_back(i);
			std::cout << vectorCont[i] << " ";
		}
		std::cout << std::endl << "Find " << n << std::endl;
		std::vector<int>::iterator pos = easyfind(vectorCont, n);
		std::cout << "The integer " << n << " is in the " << *pos + 1 << " position." << std::endl << std::endl;
	}
	{
		std::list<int> listCont;
		int n = 5;
		std::cout << "My list container: " << std::endl;
		for (int i = 0; i < 10; i++)
			listCont.push_back(i);
		for (std::list<int>::iterator i = listCont.begin(); i != listCont.end(); i++)
			std::cout << *i << " ";
		std::cout << std::endl << "Find " << n << std::endl;
		std::list<int>::iterator pos = easyfind(listCont, n);
		std::cout << "The integer " << n << " is in the " << *pos + 1 << " position." << std::endl << std::endl;
	}

	{
		std::deque<int> dequeCont;
		int n = 8;
		std::cout << "My deque container: " << std::endl;
		for (int i = 0; i < 10; i++)
		{
			dequeCont.push_back(i);
			std::cout << dequeCont[i] << " ";
		}
		std::cout << std::endl << "Find " << n << std::endl;
		std::deque<int>::iterator pos = easyfind(dequeCont, n);
		std::cout << "The integer " << n << " is in the " << *pos + 1 << " position." << std::endl << std::endl;
	}

	// -------------------------- Catch exception --------------------------- //
	{
		std::vector<int> vectExcept;
		int n = 10;
		std::cout << "Catching exception: " << std::endl;
		for (int i = 0; i < 10; i++)
		{
			vectExcept.push_back(i);
			std::cout << vectExcept[i] << " ";
		}
		std::cout << std::endl << "Find " << n << std::endl;
		try
		{
			std::vector<int>::iterator pos = easyfind(vectExcept, n);
			std::cout << "The integer " << n << " is in the " << *pos + 1 << " position." << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
