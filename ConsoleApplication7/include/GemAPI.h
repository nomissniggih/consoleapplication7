#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef GEMSDKNATIVE_STATIC
	#define GEMSDKNATIVE_API
#else
	#ifdef GEMSDKNATIVE_EXPORTS
		#define GEMSDKNATIVE_API __declspec(dllexport)
	#else
		#define GEMSDKNATIVE_API __declspec(dllimport)
	#endif
#endif

#include "Common.h"

typedef void(*gemOnStateChanged)(GemState state);
typedef void(*gemOnCombinedData)(const float quaternion[4], const float acceleration[3]);
typedef void(*gemOnTapData)(unsigned int direction);
typedef void(*gemOnPedometerData)(unsigned int steps, float walkTime);

/**
* Call this before anything else.
*/
GEMSDKNATIVE_API GemStatusCode gemInitialize();

/**
* Call when your done using the library.
*/
GEMSDKNATIVE_API GemStatusCode gemTerminate();

/**
* Connects a Gem with a given address.
* @param  The address of the Gem. (An array of 6 bytes)
*/
GEMSDKNATIVE_API GemStatusCode gemConnect(const unsigned char* address);

/**
* Disconnects a Gem with a given address.
* @param  The address of the Gem. (An array of 6 bytes)
*/
GEMSDKNATIVE_API GemStatusCode gemDisconnect(const unsigned char* address);

/**
* TODO
*/
GEMSDKNATIVE_API unsigned long gemGetWin32LastError();

/**
* Get the Gem list count, use this number to allocate the list for gemGetDescriptionList.
* @returns The number of Gems on the internal list.
*/
GEMSDKNATIVE_API unsigned int gemGetDescriptionListCount();

/**
* Fills the Gem list.
* @param list The pre-allocated list to be filled.
* @param size The count of the list (not the size in bytes!).
*/
GEMSDKNATIVE_API GemStatusCode gemGetDescriptionList(GemDescription* list, unsigned int size);

/**
* Get a Gem's infomation.
* @param address The address of the Gem. (An array of 6 bytes).
* @param gemInfo Out, the Gem information.
*/
GEMSDKNATIVE_API GemStatusCode gemGetInfo(const unsigned char* address, GemInfo* gemInfo);

/**
* Use this to set a callback for a Gem.
* @param  The address of the Gem. (An array of 6 bytes)
* @param func The callback
*/
GEMSDKNATIVE_API GemStatusCode gemSetOnStateChanged(const unsigned char* address, gemOnStateChanged func);

/**
* Use this to set a callback for a Gem.
* @param  The address of the Gem. (An array of 6 bytes)
* @param func The callback
*/
GEMSDKNATIVE_API GemStatusCode gemSetOnCombinedData(const unsigned char* address, gemOnCombinedData func);

/**
* Use this to set a callback for a Gem.
* @param  The address of the Gem. (An array of 6 bytes)
* @param func The callback
*/
GEMSDKNATIVE_API GemStatusCode gemSetOnTapData(const unsigned char* address, gemOnTapData func);

/**
* Enables Tap on a Gem with a given address.
* @param  The address of the Gem. (An array of 6 bytes)
*/
GEMSDKNATIVE_API GemStatusCode gemEnableTap(const unsigned char* address);

/**
* Disables Tap on a Gem with a given address.
* @param  The address of the Gem. (An array of 6 bytes)
*/
GEMSDKNATIVE_API GemStatusCode gemDisableTap(const unsigned char* address);

/**
* Use this to set a callback for a Gem.
* @param  The address of the Gem. (An array of 6 bytes)
* @param func The callback
*/
GEMSDKNATIVE_API GemStatusCode gemSetOnPedometerData(const unsigned char* address, gemOnPedometerData func);

/**
* Enables Pedometer on a Gem with a given address.
* @param  The address of the Gem. (An array of 6 bytes)
*/
GEMSDKNATIVE_API GemStatusCode gemEnablePedometer(const unsigned char* address);

/**
* Disables Pedometer on a Gem with a given address.
* @param  The address of the Gem. (An array of 6 bytes)
*/
GEMSDKNATIVE_API GemStatusCode gemDisablePedometer(const unsigned char* address);

#ifdef __cplusplus
}
#endif

