#include <iostream>
#include <exception>
#include "parsecgd.h"


/************/
/* ParsecGD */
/************/

// Helper Functions

void ParsecGD::_bind_methods() {
    ClassDB::bind_method(D_METHOD("initialize", "upnp", "client_port", "host_port"), &ParsecGD::initialize);
    ClassDB::bind_method(D_METHOD("is_upnp"), &ParsecGD::is_upnp);
    ClassDB::bind_method(D_METHOD("get_client_port"), &ParsecGD::get_client_port);
    ClassDB::bind_method(D_METHOD("get_host_port"), &ParsecGD::get_host_port);
    ClassDB::bind_method(D_METHOD("get_version"), &ParsecGD::get_version);
    ClassDB::bind_method(D_METHOD("destroy"), &ParsecGD::destroy);
}

ParsecConfig ParsecGD::get_cfg() {
    ParsecConfig cfg = {0};
    ParsecGetConfig(p, &cfg);
    return cfg;
}

void* ParsecGD::get_buffer(int key) {
    return ParsecGetBuffer(p, key);
}

void ParsecGD::free(void *pointer) {
    ParsecFree(p, pointer);
}



//Instance Functions

ParsecGD::ParsecGD() {
    p = NULL;
}

int ParsecGD::initialize(int upnp, int client_port, int host_port) {
    ParsecConfig* cfg = new ParsecConfig();
    cfg->upnp = 1;
    cfg->clientPort = client_port;
    cfg->hostPort = host_port;
    return ParsecInit(cfg, NULL, SDK_PATH, &p);
}

bool ParsecGD::is_upnp() {
    return get_cfg().upnp == 1;
}

int ParsecGD::get_client_port() {
    return get_cfg().clientPort;    
}

int ParsecGD::get_host_port() {
    return get_cfg().hostPort;
}

int ParsecGD::get_version() {
    return ParsecVersion(p);
}

void ParsecGD::destroy() {
    try {
        ParsecDestroy(p);
        p = NULL;
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
    }
}

// Host Functions

int ParsecGD::start_hosting(char* session_id) {
    return 0;
}

void ParsecGD::stop_hosting() {
    return;
}

ParsecHostStatus ParsecGD::get_host_status() {
    ParsecHostStatus retval = {};
    return retval;
}

int ParsecGD::set_host_config(ParsecHostConfig cfg, char* session_id) {
    return 0;
}

int ParsecGD::allow_guest(int guest_id, bool allow) {
    return 0;
}

int ParsecGD::kick_guest(int guest_id) {
    return 0;
}



// Client Functions

int ParsecGD::connect(char* session_id, char* peer_id) {
    return 0;
}

void ParsecGD::disconnect() {
    return;
}

int ParsecGD::get_status() {
    return 0;
}

int ParsecGD::set_dimensions(int width, int height, float scale) {
    return 0;
}

int ParsecGD::poll_frame(int timeout, void* opaque) {
    return 0;
}

int ParsecGD::poll_audio(int timeout, void* opaque) {
    return 0;
}

int ParsecGD::send_message() {
    return 0;
}

int ParsecGD::pause(bool pause_video, bool pause_audio) {
    return 0;
}



// Host & Client Functions

int ParsecGD::send_user_data(int message_id, char* message_text, int guest_id) {
    return 0;
}

int ParsecGD::get_guests(int status) {
    return 0;
}

bool ParsecGD::poll_events(int timeout) {
    return false;
}


/**********************/
/* ParsecGDHostConfig */
/**********************/

ParsecGDHostConfig::ParsecGDHostConfig(ParsecHostConfig cfg) {
    gamepad_type = cfg.gamepadType;
    encoder_fps = cfg.encoderFPS;
    encoder_max_bitrate = cfg.encoderMaxBitrate;
	encoder_h265 = cfg.encoderFPS;
	max_guests = cfg.maxGuests;
	name = cfg.name;
	desc = cfg.desc;
	game_id = cfg.gameID;
	secret = cfg.secret;
	is_public = cfg.isPublic;
}

ParsecHostConfig ParsecGDHostConfig::to_sdk_form() {
    ParsecHostConfig cfg;
    cfg.gamepadType = gamepad_type;
    cfg.encoderFPS = encoder_fps;
    cfg.encoderMaxBitrate = encoder_max_bitrate;
	cfg.encoderFPS = encoder_h265;
	cfg.maxGuests = max_guests;
	cfg.name = name;
	cfg.desc = desc;
	cfg.gameID = game_id;
	cfg.secret = secret;
	cfg.isPublic = is_public;
    return cfg;
}