#ifndef T100LEAK_H
#define T100LEAK_H

#include "T100DataTypes.h"
#include "T100DataStructure.h"
class T100Log;

/*
T100NEW
T100NEWS
T100DELETE
T100DELETES
*/

typedef struct{
    const char*             FILE;
    int                     LINE;
    T100DWORD               ADDRESS;
    T100WORD                COUNT;
}T100LEAK_ENTRY;

#define     T100LEAK_HASH       std::unordered_map<T100DWORD, T100LEAK_ENTRY*>

static      T100LEAK_HASH       g_leak_hash;
static      T100WORD            g_leak_total        = 0;

void* operator new(size_t, const char*, int);
void* operator new[](size_t, const char*, int);

void global_delete(void*, const char*, int);
void global_deletes(void*, const char*, int);

void global_leak_report();


class T100Leak
{
    public:
        T100Leak();
        virtual ~T100Leak();

    protected:

    private:
};

#endif // T100LEAK_H
