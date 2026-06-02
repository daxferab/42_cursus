#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>

class PMergeMe {
	public:
		static std::vector<int> sortVector(int size, char **seq);
		static std::list<int> sortList(int size, char **seq);

	private:
		PMergeMe();
		PMergeMe(const PMergeMe& other);
		PMergeMe operator=(const PMergeMe& other);
		~PMergeMe();

		static void checkSequence(char **seq, int size);

		static void	mergeInsert(std::vector<int> &vect, int size);
		static void	mergeInsert(std::list<int> &list, int size);

		static void insertMain(std::vector<int>& main, std::vector<int> &pend);
		static void insertMain(std::list<int>& main, std::list<int> &pend);
		
		static void insert(int element, std::vector<int> &main);
		static void insert(int element, std::list<int> &main);
};

#endif
