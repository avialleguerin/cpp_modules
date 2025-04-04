#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << YELLOW << "=== Test with MutantStack ===" << RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << GREEN << mstack.top() << RESET << std::endl;
	mstack.pop();
	std::cout << "Size: " << GREEN << mstack.size() << RESET << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	std::cout << YELLOW << "Content of the stack (via iterators):" << RESET << std::endl;
	MutantStack<int>::iterator itBegin = mstack.begin();
	MutantStack<int>::iterator itEnd = mstack.end();
	while (itBegin != itEnd)
		std::cout << GREEN << *itBegin++ << RESET << std::endl;
	
	std::cout << YELLOW << "=== Test with std::list ===" << RESET << std::endl;
	std::list<int> lstack;
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << "Front: " << GREEN << lstack.front() << RESET << std::endl;
	lstack.pop_front();
	std::cout << "Size: " << GREEN << lstack.size() << RESET << std::endl;
	
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	lstack.push_back(0);
	
	std::cout << YELLOW << "Content of the list (via iterators):" << RESET << std::endl;
	for (std::list<int>::iterator lit = lstack.begin(); lit != lstack.end(); ++lit)
	{
		std::cout << GREEN << *lit << RESET << std::endl;
	}
	
	return 0;
}