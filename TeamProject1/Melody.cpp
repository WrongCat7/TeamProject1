#include "Melody.h"
#include <Windows.h>

void Melody::PlayNote(int freq, int speed)
{
	Beep(freq, speed);
}

void Melody::BuySellMelody()
{
	int melody[] = { C4, E4, G4, C5 };
	int speed[] = { 150, 150, 150, 300 };

	for (int i = 0; i < 4; i++)
	{
		Beep(melody[i], speed[i]);
	}
}


void Melody::ShopInBGM()
{
	int melody[] = { G4, A4, B4, C5, B4, A4, G4 };
	int speed[] = { 200, 200, 200, 300, 200, 200, 200 };

	for (int i = 0; i < 7; i++)
	{
		Beep(melody[i], speed[i]);
	}

}

void Melody::ShopOutBGM()
{
	int melody[] = { C5, B4, A4, G4, F4, E4 };
	int speed[] = { 200, 200, 200, 200, 200, 300 };

	for (int i = 0; i < 6; i++)
	{
		Beep(melody[i], speed[i]);
	}
}

void Melody::BattelBGM()
{
	int melody[] = { C4, E4, G4, C5, G4, E4 };
	int speed[] = { 300, 300, 300, 400, 300, 300 };

	for (int i = 0; i < 6; i++)
	{
		Beep(melody[i], speed[i]);
	}
}
//1