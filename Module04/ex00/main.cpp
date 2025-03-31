#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	test_constructor()
{
	std::cout << "----- Test Constructors and Destructors START -----" << std::endl;
	const Animal* meta = new Animal();
	const Animal* x;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	x = i;

	std::cout << "Dog type: " << x->getType() << std::endl;
	x->makeSound();

	x = j;
	std::cout << "Cat type: " << x->getType() << std::endl;
	x->makeSound();

	delete(meta);
	delete(i);
	delete(j);
	// delete(x);

	const WrongAnimal* WrongMeta = new WrongAnimal();
	const WrongAnimal* WrongI = new WrongCat();

	delete(WrongMeta);
	delete(WrongI);
	std::cout << "----- Test Constructors and Destructors END -----" << std::endl;
}

void	primary_part()
{
	std::cout << "----- (Animal) START -----" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete(meta);
	delete(i);
	delete(j);
	std::cout << "----- (Animal) END -----" << std::endl;
}

void	wrong_part()
{
	std::cout << "----- (WrongAnimal) START -----" << std::endl;
	const WrongAnimal* WrongMeta = new WrongAnimal();
	const WrongAnimal* WrongI = new WrongCat();
	std::cout << WrongI->getType() << " " << std::endl;
	WrongI->makeSound();
	WrongMeta->makeSound();

	delete (WrongMeta);
	delete (WrongI);
	std::cout << "----- (WrongAnimal) END -----" << std::endl;
}

void test_copy_assignment()
{
    std::cout << "----- Test Copy Constructor and Assignment Operator and Copy Constructor START -----" << std::endl;
	WrongAnimal originalWrongDog = WrongCat();
	Animal originalDog = Dog();
	Animal originalCat = Cat();
	Animal originalCat1 = originalCat;
	

	WrongAnimal WrongCopyCat = WrongCat();
	Animal copyDog = Dog();
	Animal CopyCat = Cat();

	copyDog = originalCat;
	CopyCat = originalDog;
	WrongCopyCat = originalWrongDog;

	std::cout << "Copy dog - " << copyDog.getType() << std::endl;
	std::cout << "Copy cat - " << CopyCat.getType() << std::endl;
	std::cout << "WrongCopy cat - " << WrongCopyCat.getType() << std::endl;
    std::cout << "----- Test Copy Constructor and Assignment Operator and Copy Constructor END -----" << std::endl;
}

int main()
{
	std::cout << "\n----- project > (Polymorphism) -----" << std::endl;
	test_constructor();
	test_copy_assignment();
	primary_part();
	wrong_part();
	return 0;
}