#include "../handlers/base_handler.h"

#include <list>

struct ServiceParams {
    int port;
    std::list<BHandler*> handlers;
};

class IService {
public:
    virtual ~IService() = 0;
    virtual void Start(ServiceParams* serviceParams) = 0;
    virtual void Listening() = 0;
    virtual void Stop() = 0;
};

IService* NewService();
