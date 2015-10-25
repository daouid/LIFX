#ifndef LIFX_H_
#define LIFX_H_

#include <string>
#include <vector>
#include <jsoncpp/json/json.h>
#include <LIFXHTTPApi.h>
#include <LIFXColor.h>
#include <LIFXGroup.h>
#include <LIFXLamp.h>
#include <LIFXLocation.h>
#include <LIFXProduct.h>

class LIFX {
	public:
		LIFX();
		LIFX(std::string APIToken);

		std::vector<LIFXLamp> getLamps();

		void setAPIToken(std::std string APIToken);

	private:
		std::string APIToken;
		std::vector<LIFXLamp> Lamps;
};

#endif /* LIFX_H_ */
