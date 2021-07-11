#ifndef _REALTIME_CONFIG_H_
#define _REALTIME_CONFIG_H_

struct __declspec(dllexport) ConfigMessage {
    int& Port;
};

class __declspec(dllexport) InterfaceConfig {
public:
    virtual ~RealtimeConfig();
public:
    virtual void Set();
    virtual ConfigMessage* Get();
};

InterfaceConfig* __declspec(dllexport) NewRTConfig();

#endif _REALTIME_CONFIG_H_