#include <string>

struct ServerConfig {
    std::string pathToConfig;
};

void Start(ServerConfig*& refConfig);