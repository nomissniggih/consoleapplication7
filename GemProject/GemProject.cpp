// GemProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


const float quaterion[4] = {};
const float acceleration[3] = {};

const unsigned char mystr[6] = { 0x98,0x7b,0xf3,0x5a,0x5c,0xd6 }; //987bf35a5cd6



void OnCombinedDataEventHandler(const float quaterion[4], const float acceleration[3]) {
	cout << "x: " << quaterion[0] << ", " << "y: " << quaterion[1] << ", " << "z: " << quaterion[2] << ", " << "w: " << quaterion[3] << endl;
	return;
};


int main()
{

	gemInitialize();

	cout << gemConnect(mystr);

	gemOnCombinedData gc = &OnCombinedDataEventHandler;
	gemSetOnCombinedData(mystr, gc);

	

	return 0;

}