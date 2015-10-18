#ifndef LIFX_COLOR_H_
#define LIFX_COLOR_H_

class LIFXColor {
	public:
		LIFXColor();
		LIFXColor(int Hue, int Saturation, int Kelvin);

		int getHue();
		int getSaturation();
		int getKelvin();

		void setHue(int Hue);
		void setSaturation(int Saturation);
		void setKelvin(int Kelvin);

	private:
		int Hue, Saturation, Kelvin;
};

#endif /* LIFX_COLOR_H_ */
