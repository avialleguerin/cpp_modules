#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {
		_vector = src._vector;
		_deque = src._deque;
	}
	return *this;
}

void PmergeMe::checkArgs(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Invalid number of arguments");
	for (int i = 1; i < argc; i++)
	{
		if (std::atoi(argv[i]) < 0)
			throw std::runtime_error("Invalid arguments");
	}
}

void PmergeMe::fillContainers(char **argv, int argc) {
	for (int i = 1; i < argc; i++)
		_vector.push_back(std::atoi(argv[i]));
	for (int i = 1; i < argc; i++)
		_deque.push_back(std::atoi(argv[i]));
}

void PmergeMe::printContainer(std::string msg) {
	std::cout << msg;
	int size = _vector.size();
	if (size > 10)
		size = 10;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end() && size > 0; it++)
	{
		std::cout << *it << " ";
		size--;
	}
	if (_vector.size() > 10)
		std::cout << "[...] ";
	std::cout << std::endl;
}

template <typename T>
void PmergeMe::mergInsertSort(T &container)
{
	if (container.size() <= 1)
		return;
	
	typedef typename T::iterator Iterator;
	typedef std::vector<int> Chain;
	typedef typename Chain::iterator ChainIterator;

	std::vector<std::pair<int, int> > pairs;
	bool hasOdd = (container.size() % 2 != 0);
	int oddElement;

	Iterator it = container.begin();
	while (it != container.end())
	{
		Iterator first = it++;
		if (it != container.end())
		{
			Iterator second = it++;
			int a = *first;
			int b = *second;
			pairs.push_back(a > b ? std::make_pair(a, b) : std::make_pair(b, a));
		}
		else if (hasOdd)
			oddElement = *first;
	}

	Chain bigNumbers, littleNumbers;

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		bigNumbers.push_back(pairs[i].first);
		littleNumbers.push_back(pairs[i].second);
	}

	if (bigNumbers.size() > 1)
	{
		T tempContainer;
		for (ChainIterator it = bigNumbers.begin(); it != bigNumbers.end(); ++it)
			tempContainer.insert(tempContainer.end(), *it);
		
		mergInsertSort(tempContainer);
		
		bigNumbers.clear();
		for (Iterator it = tempContainer.begin(); it != tempContainer.end(); ++it)
			bigNumbers.push_back(*it);
	}

	std::vector<int> jacobIndices;
	int jac1 = 1, jac2 = 1;
	jacobIndices.push_back(1);
	
	while (jacobIndices.back() < static_cast<int>(littleNumbers.size()))
	{
		int jac3 = jac2 + 2 * jac1;
		jacobIndices.push_back(jac3);
		jac1 = jac2;
		jac2 = jac3;
	}

	std::vector<bool> inserted(littleNumbers.size(), false);

	if (!littleNumbers.empty())
	{
		ChainIterator pos = std::lower_bound(bigNumbers.begin(), bigNumbers.end(), littleNumbers[0]);
		bigNumbers.insert(pos, littleNumbers[0]);
		inserted[0] = true;
	}

	for (size_t i = 0; i < jacobIndices.size(); ++i)
	{
		int jacIndex = jacobIndices[i];
		if (jacIndex <= static_cast<int>(littleNumbers.size()))
		{
			if (!inserted[jacIndex - 1])
			{
				ChainIterator pos = std::lower_bound(bigNumbers.begin(), bigNumbers.end(), littleNumbers[jacIndex - 1]);
				bigNumbers.insert(pos, littleNumbers[jacIndex - 1]);
				inserted[jacIndex - 1] = true;
			}

			int prevJac = (i > 0) ? jacobIndices[i - 1] : 0;
			for (int j = jacIndex - 1; j > prevJac; --j)
			{
				if (!inserted[j - 1])
				{
					ChainIterator pos = std::lower_bound(bigNumbers.begin(), bigNumbers.end(), littleNumbers[j - 1]);
					bigNumbers.insert(pos, littleNumbers[j - 1]);
					inserted[j - 1] = true;
				}
			}
		}
	}

	for (size_t i = 0; i < littleNumbers.size(); ++i)
	{
		if (!inserted[i])
		{
			ChainIterator pos = std::lower_bound(bigNumbers.begin(), bigNumbers.end(), littleNumbers[i]);
			bigNumbers.insert(pos, littleNumbers[i]);
		}
	}

	if (hasOdd)
	{
		ChainIterator pos = std::lower_bound(bigNumbers.begin(), bigNumbers.end(), oddElement);
		bigNumbers.insert(pos, oddElement);
	}

	container.clear();
	for (ChainIterator it = bigNumbers.begin(); it != bigNumbers.end(); ++it)
		container.insert(container.end(), *it);
}



void PmergeMe::merge(int argc, char **argv) {
	checkArgs(argc, argv);
	fillContainers(argv, argc);

	printContainer("Before: ");

	clock_t startVector = clock();
	mergInsertSort(_vector);
	clock_t endVector = clock();

	clock_t startDeque = clock();
	mergInsertSort(_deque);
	clock_t endDeque = clock();

	printContainer("After: ");

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000 << " us\n";
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000 << " us\n";
}
