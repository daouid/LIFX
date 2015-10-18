#ifndef LIFX_H_
#define LIFX_H_

#include <string>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>

class LIFX {
	public:
		LIFX(std::string APIToken);

		std::string getAllLamps();

	private:
		std::string APIToken;
};

#endif /* LIFX_H_ */
