#include <LIFX.h>

size_t writefunc(void *ptr, size_t size, size_t nmemb, std::string *s)
{
    s->append((const char *) ptr, size * nmemb);

    return size*nmemb;
}

std::string REQUEST(const char *request, const char *action, const char *token)
{
    CURL *curl;
    CURLcode res;
    std::string result;

    curl = curl_easy_init();
    if (curl) {
        result = std::string();

        std::string url = std::string("https://api.lifx.com/v1/lights/");
        url.append(action);

        std::string header = std::string("Authorization: Bearer ");
        header.append(token);
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, header.c_str());

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, request);

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    return result;
}

LIFX::LIFX(std::string APIToken)
{
	this->APIToken = APIToken;
}

std::string LIFX::getAllLamps()
{
	std::string result;

	result = REQUEST("GET", "all", APIToken.c_str());

	return result;
}