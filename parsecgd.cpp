#include <iostream>
#include <exception>
#include "parsecgd.h"

int ParsecGD::initialize(int upnp, int client_port, int host_port) {
    ParsecConfig *cfg = new ParsecConfig();
    cfg->upnp = 1;
    cfg->clientPort = client_port;
    cfg->hostPort = host_port;
    return ParsecInit(cfg, NULL, SDK_PATH, &p);
}

bool ParsecGD::is_upnp() {
    ParsecConfig *cfg;
    ParsecGetConfig(p, cfg);
    return cfg->upnp == 1;
}

int ParsecGD::get_client_port() {
    ParsecConfig *cfg;
    ParsecGetConfig(p, cfg);
    return cfg->clientPort;    
}

int ParsecGD::get_host_port() {
    ParsecConfig *cfg;
    ParsecGetConfig(p, cfg);
    return cfg->hostPort;
}

void ParsecGD::destroy() {
    try {
        ParsecDestroy(p);
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
    }
}

void ParsecGD::_bind_methods() {
    ClassDB::bind_method(D_METHOD("initialize", "upnp", "client_port", "host_port"), &ParsecGD::initialize);
    ClassDB::bind_method(D_METHOD("is_upnp"), &ParsecGD::destroy);
    ClassDB::bind_method(D_METHOD("get_client_port"), &ParsecGD::destroy);
    ClassDB::bind_method(D_METHOD("get_host_port"), &ParsecGD::destroy);
    ClassDB::bind_method(D_METHOD("destroy"), &ParsecGD::destroy);
}

ParsecGD::ParsecGD() {
    
}
