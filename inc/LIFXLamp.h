#ifndef LIFX_LAMP_H_
#define LIFX_LAMP_H_

#include <string>
#include <LIFXColor.h>
#include <LIFXGroup.h>
#include <LIFXLocation.h>
#include <LIFXProduct.h>

class LIFXLamp {
	public:
		LIFXLamp();

		std::string getID();
		std::string getUUID();
		std::string getLabel();
		bool getConnected();
		std::string getPower();
		double getBrightness();
		std::string getLastSeen();
		double getSecondsSinceLastSeen();
		LIFXColor getColor();
		LIFXGroup getGroup();
		LIFXLocation getLocation();
		LIFXProduct getProduct();

	private:
		std::string ID, UUID, Label, Power, LastSeen;
		bool Connected;
		double Brightness, SecondsSinceSeen;
		LIFXColor Color;
		LIFXGroup Group;
		LIFXLocation Location;
		LIFXProduct Product;
};

#endif /* LIFX_LAMP_H_ */
