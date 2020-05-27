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

void ParsecGDHostConfig::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_gamepad_type"), &ParsecGDHostConfig::get_gamepad_type);
    ClassDB::bind_method(D_METHOD("set_gamepad_type", "value"), &ParsecGDHostConfig::set_gamepad_type);
    ClassDB::bind_method(D_METHOD("get_encoder_fps"), &ParsecGDHostConfig::get_encoder_fps);
    ClassDB::bind_method(D_METHOD("set_encoder_fps", "value"), &ParsecGDHostConfig::set_encoder_fps);
    ClassDB::bind_method(D_METHOD("get_encoder_max_bitrate"), &ParsecGDHostConfig::get_encoder_max_bitrate);
    ClassDB::bind_method(D_METHOD("set_encoder_max_bitrate", "value"), &ParsecGDHostConfig::set_encoder_max_bitrate);
    ClassDB::bind_method(D_METHOD("get_encoder_h265"), &ParsecGDHostConfig::get_encoder_h265);
    ClassDB::bind_method(D_METHOD("set_encoder_h265", "value"), &ParsecGDHostConfig::set_encoder_h265);
    ClassDB::bind_method(D_METHOD("get_max_guests"), &ParsecGDHostConfig::get_max_guests);
    ClassDB::bind_method(D_METHOD("set_max_guests", "value"), &ParsecGDHostConfig::set_max_guests);
    ClassDB::bind_method(D_METHOD("get_name"), &ParsecGDHostConfig::get_name);
    ClassDB::bind_method(D_METHOD("set_name", "value"), &ParsecGDHostConfig::set_name);
    ClassDB::bind_method(D_METHOD("get_desc"), &ParsecGDHostConfig::get_desc);
    ClassDB::bind_method(D_METHOD("set_desc", "value"), &ParsecGDHostConfig::set_desc);
    ClassDB::bind_method(D_METHOD("get_game_id"), &ParsecGDHostConfig::get_game_id);
    ClassDB::bind_method(D_METHOD("set_game_id", "value"), &ParsecGDHostConfig::set_game_id);
    ClassDB::bind_method(D_METHOD("get_secret"), &ParsecGDHostConfig::get_secret);
    ClassDB::bind_method(D_METHOD("set_secret", "value"), &ParsecGDHostConfig::set_secret);
    ClassDB::bind_method(D_METHOD("get_is_public"), &ParsecGDHostConfig::get_is_public);
    ClassDB::bind_method(D_METHOD("set_is_public", "value"), &ParsecGDHostConfig::set_is_public);
    
    ADD_PROPERTY(PropertyInfo(Variant::INT, "gamepad_type", PROPERTY_HINT_ENUM, "0,Xbox 360,DS4"), "set_gamepad_type", "get_gamepad_type");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "encoder_fps"), "set_encoder_fps", "get_encoder_fps");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "encoder_max_bitrate"), "set_encoder_max_bitrate", "get_encoder_max_bitrate");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "encoder_h265"), "set_encoder_h265", "get_encoder_h265");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "max_guests"), "set_max_guests", "get_max_guests");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "name"), "set_name", "get_name");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "desc"), "set_desc", "get_desc");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "game_id"), "set_game_id", "get_game_id");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "secret"), "set_secret", "get_secret");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "is_public"), "set_is_public", "get_is_public");

}

ParsecGDHostConfig::ParsecGDHostConfig() {
    gamepad_type = 1;
    encoder_fps = 0;
    encoder_max_bitrate = 10;
	encoder_h265 = 0;
	max_guests = 20;
    name = "";
    desc = "";
    game_id = "";
    secret = "";
	is_public = false;
}

ParsecGDHostConfig::ParsecGDHostConfig(ParsecHostConfig cfg) {
    gamepad_type = cfg.gamepadType;
    encoder_fps = cfg.encoderFPS;
    encoder_max_bitrate = cfg.encoderMaxBitrate;
	encoder_h265 = cfg.encoderFPS;
	max_guests = cfg.maxGuests;
	name = String(cfg.name);
	desc = String(cfg.desc);
	game_id = String(cfg.gameID);
	secret = String(cfg.secret);
	is_public = cfg.publicGame;
}

ParsecHostConfig ParsecGDHostConfig::to_sdk_form() {
    ParsecHostConfig cfg;
    cfg.gamepadType = (ParsecGamepadType) gamepad_type;
    cfg.encoderFPS = encoder_fps;
    cfg.encoderMaxBitrate = encoder_max_bitrate;
	cfg.encoderFPS = encoder_h265;
	cfg.maxGuests = max_guests;
    wcstombs(cfg.name, name.c_str(), sizeof cfg.name);
    wcstombs(cfg.desc, desc.c_str(), sizeof cfg.desc);
    wcstombs(cfg.gameID, game_id.c_str(), sizeof cfg.gameID);
    wcstombs(cfg.secret, secret.c_str(), sizeof cfg.secret);
	cfg.publicGame = is_public;
    return cfg;
}

//Accessors and Mutators

int ParsecGDHostConfig::get_gamepad_type() { return gamepad_type; }
void ParsecGDHostConfig::set_gamepad_type(int value) { gamepad_type = value; } 

int ParsecGDHostConfig::get_encoder_fps() { return encoder_fps; }
void ParsecGDHostConfig::set_encoder_fps(int value) { encoder_fps = value; } 

int ParsecGDHostConfig::get_encoder_max_bitrate() { return encoder_max_bitrate; }
void ParsecGDHostConfig::set_encoder_max_bitrate(int value) { encoder_max_bitrate = value; } 

int ParsecGDHostConfig::get_encoder_h265() { return encoder_h265; }
void ParsecGDHostConfig::set_encoder_h265(int value) { encoder_h265 = value; } 

int ParsecGDHostConfig::get_max_guests() { return max_guests; }
void ParsecGDHostConfig::set_max_guests(int value) { max_guests = value; } 

String ParsecGDHostConfig::get_name() { return name; }
void ParsecGDHostConfig::set_name(String value) { 
    if (value.length() > HOST_NAME_LEN) {
        value.resize(HOST_NAME_LEN);
    }
    name = value; 
} 

String ParsecGDHostConfig::get_desc() { return desc; }
void ParsecGDHostConfig::set_desc(String value) {
    if (value.length() > HOST_DESC_LEN) {
        value.resize(HOST_DESC_LEN);
    }
    desc = value;
} 

String ParsecGDHostConfig::get_game_id() { return game_id; }
void ParsecGDHostConfig::set_game_id(String value) {
    if (value.length() > GAME_ID_LEN) {
        value.resize(GAME_ID_LEN);
    }
    game_id = value;
} 

String ParsecGDHostConfig::get_secret() { return secret; }
void ParsecGDHostConfig::set_secret(String value) {
    if (value.length() > HOST_SECRET_LEN) {
        value.resize(HOST_SECRET_LEN);
    }
    secret = value;
} 

bool ParsecGDHostConfig::get_is_public() { return is_public; }
void ParsecGDHostConfig::set_is_public(bool value) { is_public = value; } 