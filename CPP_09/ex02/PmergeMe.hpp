#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

#define RED		"\033[0;31m"
#define RESET	"\033[0m"

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void checkArgs(int argc, char **argv);
		void fillContainers(char **argv, int argc);
		void printContainer(std::string msg);
		template <typename T> void mergInsertSort(T &container);
		// std::vector<int> generateJacobsthalNumbers(int n);
		void merge(int argc, char **argv);
};

#endif
