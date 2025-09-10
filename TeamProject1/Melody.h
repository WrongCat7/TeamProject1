#pragma once

class Melody
{
private:
	const int C4 = 261;
	const int D4 = 294;
	const int E4 = 329;
	const int F4 = 349;
	const int G4 = 392;
	const int A4 = 440;
	const int B4 = 493;
	const int C5 = 523;

public:
	void PlayNote(int freq, int speed);
	void BuySellMelody();
	void ShopInBGM();
	void ShopOutBGM();
	void BattelBGM();
};


//1