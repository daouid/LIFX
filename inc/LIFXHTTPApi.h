#ifndef LIFX_HTTP_API_H_
#define LIFX_HTTP_API_H_

#include <string>
#include <curl/curl.h>

std::string LIFXHTTPApi(std::string Method, std::string Selector, std::string APIToken);

#endif /* LIFX_H_ */