#ifndef _STORAGE_DECLS_H_
#define _STORAGE_DECLS_H_

#include <string>

struct ConnectionParams {
    std::string host;
    int port;
    std::string dbName;
    std::string userName;
    std::string password;
    const char* GetHost();
    const char* GetDatabaseName();
    const char* GetUserName();
    const char* GetPassword();
};

const char* ConnectionParams::GetHost() {
    return host.c_str();
}
const char* ConnectionParams::GetDatabaseName() {
    return dbName.c_str();
}
const char* ConnectionParams::GetUserName() {
    return userName.c_str();
}
const char* ConnectionParams::GetPassword() {
    return password.c_str();
}

struct ErrorMsg {
    ~ErrorMsg();
    const char* title;
};

#endif _STORAGE_DECLS_H_
