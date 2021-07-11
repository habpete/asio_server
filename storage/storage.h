#ifndef _STORAGE_H_
#define _STORAGE_H_

#include "decls.h"

enum DB_Type {
    eNone = 0,
    ePG,
};

class DB_Transaction {
public:
    virtual ~DB_Transaction();
    virtual ErrorMsg Start();
    virtual ErrorMsg Finish();
    virtual ErrorMsg Cancel();
};

DB_Transaction* NewTransaction(DB_Type type);

class DB_Query {
public:
    virtual ~DB_Query();
    virtual void Execute();
    virtual void ExecuteParams();
};

DB_Query* NewQuery(DB_Type type);

#endif