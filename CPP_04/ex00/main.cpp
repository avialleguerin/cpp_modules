#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrong = new WrongCat();
	std::cout << animal->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrong->getType() << " " << std::endl;
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	wrong->makeSound();
	delete animal;
	delete dog;
	delete cat;
	delete wrong;
	return 0;
}
