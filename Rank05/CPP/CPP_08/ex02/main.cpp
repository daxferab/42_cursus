#include "include/MutantStack.hpp"
#include <cstddef>
#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
	MutantStack<int> mutantStack;
	std::vector<int> vectStack;
	int				data[6] = {2, 56, 0, 78, 3, 6};

	std::cout << "---------------------------------------------------" << std::endl;

	std::cout << "Pushing 'data' array into mutantStack and vectStack" << std::endl;
	for (size_t i = 0; i < 6; i++)
	{
		mutantStack.push(data[i]);
		vectStack.push_back(data[i]);
	}
	std::cout << "Mutant top: " << mutantStack.top() << std::endl;
	std::cout << "Vector top: " << vectStack.back() << std::endl;
	std::cout << "Deleting top element in both containers" << std::endl;
	mutantStack.pop();
	vectStack.pop_back();
	std::cout << "Mutant size: " << mutantStack.size() << std::endl;
	std::cout << "Vector size: " << vectStack.size() << std::endl;

	MutantStack<int>::iterator mutBegin = mutantStack.begin();
	std::vector<int>::iterator vecBegin = vectStack.begin();
	MutantStack<int>::iterator mutEnd = mutantStack.end();

	std::cout << std::setw(6) << "Mutant | Vector " << std::endl;
	while (mutBegin != mutEnd)
	{
		std::cout << std::setw(6) << *mutBegin << " | " << *vecBegin <<" " << std::endl;
		mutBegin++;
		vecBegin++;
	}

	std::cout << "---------------------------------------------------" << std::endl;

	MutantStack<int> copyStack(mutantStack);
	MutantStack<int> assignStack = mutantStack;
	mutBegin = mutantStack.begin();
	MutantStack<int>::iterator copBegin = copyStack.begin();
	MutantStack<int>::iterator assBegin = assignStack.begin();

	std::cout << std::setw(6) << "Mutant |  Copy  | Assign " << std::endl;
	while (mutBegin != mutEnd)
	{
		std::cout << std::setw(6) << *mutBegin << " | " << std::setw(6) << *copBegin << " | " << std::setw(6) << *assBegin  << std::endl;
		mutBegin++;
		copBegin++;
		assBegin++;
	}
	mutBegin = mutantStack.begin();
	copBegin = copyStack.begin();
	assBegin = assignStack.begin();

	std::cout << "Changing copies: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		copyStack.pop();
		assignStack.pop();
	}
	for (int i = 1; i < 6; i++)
		copyStack.push(i);
	for (int i = 1; i < 6; i++)
		assignStack.push(i * 9);

	std::cout << std::setw(6) << "Mutant |  Copy  | Assign " << std::endl;
	while (mutBegin != mutEnd)
	{
		std::cout << std::setw(6) << *mutBegin << " | " << std::setw(6) << *copBegin << " | " << std::setw(6) << *assBegin  << std::endl;
		mutBegin++;
		copBegin++;
		assBegin++;
	}
	std::cout << "---------------------------------------------------" << std::endl;
	return 0;
}
