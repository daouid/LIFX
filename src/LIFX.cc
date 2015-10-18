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

    std::string result;
    result = REQUEST("GET", "all", APIToken.c_str());

    Json::Value root;
    Json::Reader reader;
    bool parsedSuccess = reader.parse(result.c_str(), root, false);
    if (!parsedSuccess) {
        printf("Failed to parse JSON: %s\n", reader.getFormatedErrorMessages().c_str());
    }

    LIFXLamp Lamp;
    LIFXColor Color;
    LIFXGroup Group;
    LIFXLocation Location;
    LIFXProduct Product;

    for (unsigned int i = 0; i < root.size(); i++) {
        Lamp = LIFXLamp();
        Color = LIFXColor();
        Group = LIFXGroup();
        Location = LIFXLocation();
        Product = LIFXProduct();

        Lamp.setID(root[i]["id"].asString());
        Lamp.setUUID(root[i]["uuid"].asString());
        Lamp.setLabel(root[i]["label"].asString());
        Lamp.setConnected(root[i]["connected"].asBool());
        Lamp.setPower(root[i]["power"].asString());

        Color.setHue(root[i]["color"]["hue"].asInt());
        Color.setSaturation(root[i]["color"]["saturation"].asInt());
        Color.setKelvin(root[i]["color"]["kelvin"].asInt());
        Lamp.setColor(Color);

        Lamp.setBrightness(root[i]["brightness"].asDouble());

        Group.setID(root[i]["group"]["id"].asString());
        Group.setName(root[i]["group"]["name"].asString());
        Lamp.setGroup(Group);

        Location.setID(root[i]["location"]["id"].asString());
        Location.setName(root[i]["location"]["name"].asString());
        Lamp.setLocation(Location);

        Product.setName(root[i]["product"]["name"].asString());
        Product.setIdentifier(root[i]["product"]["identifier"].asString());
        Product.setCompany(root[i]["product"]["company"].asString());
        Product.setHasColor(root[i]["product"]["has_color"].asBool());
        Product.setHasVariableColorTemp(root[i]["product"]["has_variable_color_temp"].asBool());
        Lamp.setProduct(Product);

        Lamp.setLastSeen(root[i]["last_seen"].asString());
        Lamp.setSecondsSinceSeen(root[i]["seconds_since_seen"].asDouble());

        Lamps.push_back(Lamp);
    }
}

std::vector<LIFXLamp> LIFX::getLamps()
{
    return Lamps;
}
