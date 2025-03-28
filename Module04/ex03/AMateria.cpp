#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}

AMateria::AMateria(const AMateria& other)
{
	this->_type = other._type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}
