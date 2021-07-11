#include "storage.h"

class PostgresTransaction : public DB_Transaction {
public:
    PostgresTransaction();
    ~PostgresTransaction();
};

class PostgresQuery : public DB_Query {
public:
    PostgresQuery();
    ~PostgresQuery();
};