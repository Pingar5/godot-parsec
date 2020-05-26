#ifndef PARSECGD_H
#define PARSECGD_H

#include "core/reference.h"
#include "sdk/parsec-dso.h"

#if defined(_WIN32)
	#if !defined(BITS)
		#define BITS 64
	#endif
	#if (BITS == 64)
		#define SDK_PATH "windows/parsec.dll"
	#else
		#define SDK_PATH "windows/parsec32.dll"
	#endif
#elif defined(__APPLE__)
	#define GL_SILENCE_DEPRECATION
	#define SDK_PATH "macos/libparsec.dylib"
#else
	#define SDK_PATH "linux/libparsec.so"
#endif

class ParsecGD : public Reference {
    GDCLASS(ParsecGD, Reference);
	ParsecDSO *p;

protected:
    static void _bind_methods();

public:
	int initialize(int upnp, int client_port, int host_port);
	bool is_upnp();
	int get_client_port();
	int get_host_port();
	void destroy();

    ParsecGD();
};

#endif //PARSECGD_H