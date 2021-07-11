#include "postgres_storage.h"

// Transaction implementation

PostgresTransaction::PostgresTransaction(ConnectionParams*& params) {}

PostgresTransaction::~PostgresTransaction() {}

const char* PostgresTransaction::buildConnectionString() {
    return "postgresql://" + m_username + ":" + m_password + "@" + m_host + "/" + m_dbName;
}

ErrorMsg PostgresTransaction::Start() {
    m_connection = PQconnectdb(buildConnectionString());
}
ErrorMsg PostgresTransaction::Finish() {}
ErrorMsg PostgresTransaction::Cancel() {}

// Query implementation

PostgresQuery::PostgresQuery() {}

PostgresQuery::~PostgresQuery() {}

void PostgresQuery::Execute() {}
void PostgresQuery::ExecuteParams() {}