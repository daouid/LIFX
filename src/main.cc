#include <fstream>
#include <string>
#include <cerrno>
#include <iostream>
#include <cstdlib>

#include <LIFX.h>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2) {
		cout << "Specify API access token" << endl;

		return EXIT_FAILURE;
	}

	string lifx_token = (argv[1]);

	LIFX lifx = LIFX(lifx_token);
	vector<LIFXLamp> Lamps = lifx.getLamps();

	for (unsigned int i = 0; i < Lamps.size(); i++) {
		cout << "Toggling state of " << Lamps[i].getLabel() << endl;
		Lamps[i].toggle();
	}

	return EXIT_SUCCESS;
}
