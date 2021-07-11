#include "storage.h"

#include "libpq-fe.h"

class PostgresTransaction : public DB_Transaction {
public:
    PostgresTransaction(ConnectionParams*& params);
    ~PostgresTransaction();
private:
    const char* m_host;
    const char* m_dbName;
    int m_port;
    const char* m_username;
    const char* m_password;
private:
    PGconn* m_connection;
    const char* buildConnectionString();
public:
    ErrorMsg Start();
    ErrorMsg Finish();
    ErrorMsg Cancel();
};

class PostgresQuery : public DB_Query {
public:
    PostgresQuery();
    ~PostgresQuery();
public:
    void Execute();
    void ExecuteParams();
};