#include <LIFXProduct.h>

LIFXProduct::LIFXProduct() {}

LIFXProduct::LIFXProduct(std::string Name, std::string Identifier,
						 std::string Company, bool HasColor,
						 bool HasVariableColorTemp)
{
	this->Name = Name;
	this->Identifier = Identifier;
	this->Company = Company;
	this->HasColor = HasColor;
	this->HasVariableColorTemp = HasVariableColorTemp;
}

std::string LIFXProduct::getName()
{
	return Name;
}

std::string LIFXProduct::getIdentifier()
{
	return Identifier;
}

std::string LIFXProduct::getCompany()
{
	return Company;
}

bool LIFXProduct::hasColor()
{
	return HasColor;
}

bool LIFXProduct::hasVariableColorTemp()
{
	return HasVariableColorTemp;
}

void LIFXProduct::setName(std::string Name)
{
	this->Name = Name;
}

void LIFXProduct::setIdentifier(std::string Identifier)
{
	this->Identifier = Identifier;
}

void LIFXProduct::setCompany(std::string Company)
{
	this->Company = Company;
}

void LIFXProduct::setHasColor(bool HasColor)
{
	this->HasColor = HasColor;
}

void LIFXProduct::setHasVariableColorTemp(bool HasVariableColorTemp)
{
	this->HasVariableColorTemp = HasVariableColorTemp;
}
