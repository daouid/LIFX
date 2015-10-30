#include <fstream>
#include <string>
#include <cerrno>
#include <iostream>
#include <cstdlib>
#include <unistd.h>

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
		cout << "Turning " << Lamps[i].getLabel() << " on" << endl;
		Lamps[i].turnOn();
	}

	sleep(5);

	for (unsigned int i = 0; i < Lamps.size(); i++) {
		cout << "Turning " << Lamps[i].getLabel() << " off" << endl;
		Lamps[i].turnOff();
	}

	return EXIT_SUCCESS;
}
