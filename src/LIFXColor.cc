#include <LIFXColor.h>

LIFXColor::LIFXColor() {}

LIFXColor::LIFXColor(int Hue, int Saturation, int Kelvin)
{
	this->Hue = Hue;
	this->Saturation = Saturation;
	this->Kelvin = Kelvin;
}

int LIFXColor::getHue()
{
	return Hue;
}

int LIFXColor::getSaturation()
{
	return Saturation;
}

int LIFXColor::getKelvin()
{
	return Kelvin;
}

void LIFXColor::setHue(int Hue)
{
	this->Hue = Hue;
}

void LIFXColor::setSaturation(int Saturation)
{
	this->Saturation = Saturation;
}

void LIFXColor::setKelvin(int Kelvin)
{
	this->Kelvin = Kelvin;
}