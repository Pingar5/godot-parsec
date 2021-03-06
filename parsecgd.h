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
	ParsecDSO* p;

protected:
    static void _bind_methods();
	ParsecConfig get_cfg();
	void* get_buffer(int key);
	void free(void* pointer);

public:
	// Instance Functions
    ParsecGD();
	int initialize(int upnp, int client_port, int host_port);
	bool is_upnp();
	int get_client_port();
	int get_host_port();
	int get_version();
	void destroy();
	
	//Host Functions
	int start_hosting(char* session_id);
	void stop_hosting();
	ParsecHostStatus get_host_status();
	int set_host_config(ParsecHostConfig cfg, char* session_id);
	int allow_guest(int guest_id, bool allow);
	int kick_guest(int guest_id);

	//Client Functions
	int connect(char* session_id, char* peer_id);
	void disconnect();
	int get_status();
	int set_dimensions(int width, int height, float scale);
	int poll_frame(int timeout, void* opaque);
	int poll_audio(int timeout, void* opaque);
	int send_message();
	int pause(bool pause_video, bool pause_audio);

	//Host or Client Functions
	int send_user_data(int message_id, char* message_text, int guest_id = -1);
	int get_guests(int status = 0x04);
	bool poll_events(int timeout);
};

class ParsecGDHostConfig : public Reference {
	GDCLASS(ParsecGDHostConfig, Reference);

protected:
    static void _bind_methods();
	int gamepad_type;
	int encoder_fps;
	int encoder_max_bitrate;
	int encoder_h265;
	int max_guests;
	String name;
	String desc;
	String game_id;
	String secret;
	bool is_public;

public:
	ParsecGDHostConfig();
	ParsecGDHostConfig(ParsecHostConfig cfg);
	ParsecHostConfig to_sdk_form();

	int get_gamepad_type();
	void set_gamepad_type(int value);
	int get_encoder_fps();
	void set_encoder_fps(int value);
	int get_encoder_max_bitrate();
	void set_encoder_max_bitrate(int value);
	int get_encoder_h265();
	void set_encoder_h265(int value);
	int get_max_guests();
	void set_max_guests(int value);
	String get_name();
	void set_name(String value);
	String get_desc();
	void set_desc(String value);
	String get_game_id();
	void set_game_id(String value);
	String get_secret();
	void set_secret(String value);
	bool get_is_public();
	void set_is_public(bool value);
};

#endif //PARSECGD_H