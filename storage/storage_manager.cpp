#include "storage.h"
#include "postgres_storage.h"

DB_Transaction* NewTransaction(DB_Type type) {
    DB_Transaction* dbt;

    switch (type) {
        case ePG:
            dbt = new PostgresTransaction(); 
            break;
        default:
            dbt = nullptr;
            break;
    }

    return dbt;
}

DB_Query* NewQuery(DB_Type type) {
    DB_Query* dbq;

    switch (type) {
        case ePG:
            dbq = new PostgresQuery();
            break;
        default:
            dbt = nullptr;
            break;
    }

    return dbq;
}