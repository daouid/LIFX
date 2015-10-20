#include <LIFXHTTPApi.h>

size_t writefunc(void *ptr, size_t size, size_t nmemb, std::string *s)
{
    s->append((const char *) ptr, size * nmemb);

    return size*nmemb;
}

std::string LIFXHTTPApi(std::string Method, std::string Selector, std::string APIToken)
{
    CURL *curl;
    CURLcode res;
    std::string result;

    curl = curl_easy_init();
    if (curl) {
        result = std::string();

        std::string url = std::string("https://api.lifx.com/v1/lights/");
        url.append(Selector);

        std::string header = std::string("Authorization: Bearer ");
        header.append(APIToken);
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, header.c_str());

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, Method.c_str());

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