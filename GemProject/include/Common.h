#pragma once

typedef unsigned int GemStatusCode;

#define GEM_SUCCESS				0x00
#define GEM_FAILED_WIN32		0x01
#define GEM_FAILED_BLUETOOTH	0x02
#define GEM_NOT_FOUND			0x03
#define GEM_ALREADY_CONNECTED	0x04
#define GEM_NOT_CONNECTED		0x05
#define GEM_INSUFFICIENT_BUFFER	0x06
#define GEM_EMPTY				0x07
#define GEM_INVALID_PARAMETER	0x08
#define GEM_BAD_CONFIG			0x0A
#define GEM_ALREADY_INITIALIZED	0x0B
#define GEM_NOT_INITIALIZED		0x0C
#define GEM_ERROR_UNKNOWN		0xFF

typedef unsigned int GemState;

#define GEM_STATE_CONNECTING	0x00
#define GEM_STATE_CONNECTED		0x01
#define GEM_STATE_DISCONNECTING	0x02
#define GEM_STATE_DISCONNECTED	0x03

typedef struct
{
	unsigned char address[6];
	char deviceName[32];
} GemDescription;

typedef struct
{
	char name[32];
	char firmwareVer[32];
	char hardwareVer[32];
	char batteryLevel;
} GemInfo;
