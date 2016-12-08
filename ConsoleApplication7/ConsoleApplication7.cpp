// ConsoleApplication7.cpp : Defines the entry point for the console application.
// Add the following in the linker and additional includes to make it work
// Properties->Linker->Input: your.lib
// Properties->Linker->Additional Library Directories : .. / your / bin
// Properties->General->Compiler->Additional Include Directories : .. / your / include

#include "stdafx.h"

using namespace std;

GemInfo gemstuff;
GemInfo* gemstuffed = &gemstuff;
GemDescription lot;
GemDescription* list = &lot;
GemState* state;
GemStatusCode status;
GemStatusCode GemList;


const float quaterion[4] = {};
const float acceleration[3] = {};

const unsigned char mystr[6] = { 0x98,0x7b,0xf3,0x5a,0x5c,0xd6 }; //987bf35a5cd6
int number = 0;
unsigned int num = gemGetDescriptionListCount();

void OnCombinedDataEventHandler(const float quaterion[4], const float acceleration[3]) {

	cout << "x: " << quaterion[0] << ", " << "y: " << quaterion[1] << ", " << "z: " << quaterion[2] << ", " << "w: " << quaterion[3] << endl;
	return;
};



void(StateChanged)(GemState state) {
	switch (state) {
	case GEM_STATE_CONNECTING:
		cout << "GEM_STATE_CONNECTING" << endl;
		break;
	case GEM_STATE_CONNECTED:
		cout << "GEM_STATE_CONNECTED" << endl;
		gemGetInfo(mystr, gemstuffed);
		cout << "gemGetInfoFirmwareVer: " << gemstuff.firmwareVer << endl;
		gemGetDescriptionList(list, num);
		cout << "gemGetDescriptionList: " << lot.deviceName << endl;
		number = 1;
		break;
	case GEM_STATE_DISCONNECTING:
		cout << "GEM_STATE_DISCONNECTING" << endl;
		break;
	case GEM_STATE_DISCONNECTED:
		cout << "GEM_STATE_DISCONNECTED" << endl;
		break;
	}
};



int main()
{

	gemInitialize();

	status = gemConnect(mystr);

	gemOnStateChanged gs = &StateChanged;
	gemSetOnStateChanged(mystr, gs);

	if (GemState State = GEM_STATE_CONNECTED)
	{

	}


	gemOnCombinedData gc = &OnCombinedDataEventHandler;
	gemSetOnCombinedData(mystr, gc);



	//if (GemState state = GEM_STATE_CONNECTED)
	//{
	//	gemOnCombinedData gc = &OnCombinedDataEventHandler;
	//	gemSetOnCombinedData(mystr, gc);
	//}



	while (true) {
	}

	return 0;

};
