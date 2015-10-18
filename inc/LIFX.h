#ifndef LIFX_H_
#define LIFX_H_

#include <string>
#include <vector>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include <LIFXColor.h>
#include <LIFXGroup.h>
#include <LIFXLamp.h>
#include <LIFXLocation.h>
#include <LIFXProduct.h>

class LIFX {
	public:
		LIFX(std::string APIToken);

		std::vector<LIFXLamp> getLamps();

	private:
		std::string APIToken;
		std::vector<LIFXLamp> Lamps;
};

#endif /* LIFX_H_ */
