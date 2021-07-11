#include "config.h"

struct ConfigTable {
    int Port;
};

class RealTimeConfig {
public:
    RealTimeConfig();
    ~RealTimeConfig();
private:
    ConfigTable* values;
public:
    void Set();
    ConfigMessage* Get();
};

InterfaceConfig* NewRTConfig() {
    return new RealTimeConfig();
}

void RealTimeConfig::Set() {}

ConfigMessage* RealTimeConfig::Get() {
    ConfigMessage* msg = new ConfigMessage();
    msg->Port = &msg->Port;
    return msg;
}