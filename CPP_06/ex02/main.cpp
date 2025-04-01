#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	srand(time(NULL));
	int i = rand() % 3;
	if (i == 0)
	{
		std::cout << "A is generated" << std::endl;
		return new A;
	}
	else if (i == 1)
	{
		std::cout << "B is generated" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "C is generated" << std::endl;
		return new C;
	}
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A is identified" << std::endl;
	} catch (const std::exception&) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B is identified" << std::endl;
	} catch (const std::exception&) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C is identified" << std::endl;
	} catch (const std::exception&) {}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A is identified" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B is identified" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C is identified" << std::endl;
}


int main(void)
{
	Base* base = generate();
	std::cout << "\nPointer test:" << std::endl;
	identify(base);
	std::cout << "\nReference test:" << std::endl;
	identify(*base);
	delete base;
	return 0;
}