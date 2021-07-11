#ifndef _STORAGE_H_
#define _STORAGE_H_

enum DB_Type {
    eNone = 0,
    ePG,
};

class DB_Transaction {
public:
    virtual ~DB_Transaction();
    virtual void Start();
    virtual void Finish();
    virtual void Cancel();
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