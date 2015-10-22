#include <LIFX.h>

LIFX::LIFX(std::string APIToken)
{
	this->APIToken = APIToken;

    std::string result;
    result = LIFXHTTPApi("GET", "all", "", APIToken);

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
        Lamp = LIFXLamp(APIToken);
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
