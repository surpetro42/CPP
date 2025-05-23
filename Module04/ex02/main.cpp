#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	test_constructor()
{
	std::cout << "----- Test Constructors and Destructors START -----" << std::endl;
	const Animal* meta = new Dog();
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

	const WrongAnimal* WrongMeta = new WrongAnimal();
	const WrongAnimal* WrongI = new WrongCat();

	delete(WrongMeta);
	delete(WrongI);
	std::cout << "----- Test Constructors and Destructors END -----" << std::endl;
}

void	primary_part()
{
	std::cout << "----- (Animal) START -----" << std::endl;
	const Animal* meta = new Cat();
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
	Animal *originalDog = new Dog();
	Animal *originalCat = new Cat();
	

	WrongAnimal WrongCopyCat = WrongCat();
	Animal *copyDog;
	Animal *CopyCat;

	copyDog = originalCat;
	CopyCat = originalDog;

	std::cout << "Copy dog - " << copyDog->getType() << std::endl;
	std::cout << "Copy cat - " << CopyCat->getType() << std::endl;
	std::cout << "WrongCopy cat - " << WrongCopyCat.getType() << std::endl;
	delete copyDog;
	delete CopyCat;
    std::cout << "----- Test Copy Constructor and Assignment Operator and Copy Constructor END -----" << std::endl;
}

void test_deep_copy() {
    std::cout << "----- Test Deep Copy START -----" << std::endl;

    Animal* animals[6];

    for (int i = 0; i < 3; ++i) {
        animals[i] = new Dog();
        animals[i + 3] = new Cat();
    }

    static_cast<Dog*>(animals[0])->setIdea(0, "Dog idea 0");
    static_cast<Cat*>(animals[3])->setIdea(0, "Cat idea 0");

    Animal* dog_copy = new Dog(*static_cast<Dog*>(animals[0]));
    Animal* cat_copy = new Cat(*static_cast<Cat*>(animals[3]));

    std::cout << "Original Dog Idea 0: " << static_cast<Dog*>(animals[0])->getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea 0: " << static_cast<Dog*>(dog_copy)->getIdea(0) << std::endl;

    std::cout << "Original Cat Idea 0: " << static_cast<Cat*>(animals[3])->getIdea(0) << std::endl;
    std::cout << "Copied Cat Idea 0: " << static_cast<Cat*>(cat_copy)->getIdea(0) << std::endl;

    for (int i = 0; i < 6; ++i) {
        delete animals[i];
    }
    delete dog_copy;
    delete cat_copy;

    std::cout << "----- Test Deep Copy END -----" << std::endl;
}
int main()
{
	std::cout << "\n----- project > (Polymorphism) -----" << std::endl;
	test_constructor();
	test_copy_assignment();
	primary_part();
	wrong_part();
	test_deep_copy();
	return 0;
}