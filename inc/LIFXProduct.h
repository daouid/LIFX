#ifndef LIFX_PRODUCT_H_
#define LIFX_PRODUCT_H_

#include <string>

class LIFXProduct {
	public:
		LIFXProduct();
		LIFXProduct(std::string Name, std::string Identifier,
					std::string Company, bool HasColor,
					bool HasVariableColorTemp);

		std::string getName();
		std::string getIdentifier();
		std::string getCompany();
		bool hasColor();
		bool hasVariableColorTemp();

		void setName(std::string Name);
		void setIdentifier(std::string Identifier);
		void setCompany(std::string Company);
		void setHastColor(bool HasColor);
		void setHasVariableColorTemp(bool HasVariableColorTemp);

	private:
		std::string Name, Identifier, Company;
		bool HasColor, HasVariableColorTemp;
};

#endif /* LIFX_PRODUCT_H_ */