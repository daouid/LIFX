#ifndef LIFX_GROUP_H_
#define LIFX_GROUP_H_

#include <string>

class LIFXGroup {
	public:
		LIFXGroup();
		LIFXGroup(std::string ID);
		LIFXGroup(std::string ID, std::string Name);

		std::string getID();
		std::string getName();

		void setID(std::string ID);
		void setName(std::string Name);

	private:
		std::string ID, Name;
};

#endif /* LIFX_GROUP_H_ */
