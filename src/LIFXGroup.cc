#include <LIFXGroup.h>

LIFXGroup::LIFXGroup() {}

LIFXGroup::LIFXGroup(std::string ID)
{
	this->ID = ID;
}

LIFXGroup::LIFXGroup(std::string ID, std::string Name)
{
	this->ID = ID;
	this->Name = Name;
}

std::string LIFXGroup::getID()
{
	return ID;
}

std::string LIFXGroup::getName()
{
	return Name;
}

void LIFXGroup::setID(std::string ID)
{
	this->ID = ID;
}

void LIFXGroup::setName(std::string Name)
{
	this->Name = Name;
}
