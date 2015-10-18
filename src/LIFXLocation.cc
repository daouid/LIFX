#include <LIFXLocation.h>

LIFXLocation::LIFXLocation() {}

LIFXLocation::LIFXLocation(std::string ID)
{
	this->ID = ID;
}

LIFXLocation::LIFXLocation(std::string ID, std::string Name)
{
	this->ID = ID;
	this->Name = Name;
}

std::string LIFXLocation::getID()
{
	return ID;
}

std::string LIFXLocation::getName()
{
	return Name;
}

void LIFXLocation::setID(std::string ID)
{
	this->ID = ID;
}

void LIFXLocation::setName(std::string Name)
{
	this->Name = Name;
}
