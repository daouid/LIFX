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
		bool isConnected();
		std::string getPower();
		double getBrightness();
		std::string getLastSeen();
		double getSecondsSinceSeen();
		LIFXColor getColor();
		LIFXGroup getGroup();
		LIFXLocation getLocation();
		LIFXProduct getProduct();

		void setID(std::string ID);
		void setUUID(std::string UUID);
		void setLabel(std::string Label);
		void setConnected(bool Connected);
		void setPower(std::string Power);
		void setBrightness(double Brightness);
		void setLastSeen(std::string LastSeen);
		void setSecondsSinceSeen(double SecondsSinceSeen);
		void setColor(LIFXColor Color);
		void setGroup(LIFXGroup Group);
		void setLocation(LIFXLocation Location);
		void setProduct(LIFXProduct Product);

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
