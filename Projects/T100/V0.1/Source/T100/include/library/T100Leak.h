#ifndef T100LEAK_H
#define T100LEAK_H

#include <unordered_map>
#include "T100DataTypes.h"
//#include "T100String.h"

#ifndef __LEAK__
    #define __LEAK__    1
#endif // __LEAK__

typedef struct{
    const char*             FILE;
    int                     LINE;
    T100DWORD               ADDRESS;
    T100WORD                COUNT;
}T100LEAK_ITEM;

#define     T100LEAK_HASH       std::unordered_map<T100DWORD, T100LEAK_ITEM*>

static      T100LEAK_HASH       g_leak_hash;
static      T100WORD            g_leak_total        = 0;

#define     T100NEW             new(__FILE__, __LINE__)
#define     T100NEWS            new[](__FILE__,__LINE__)

#define     T100DELETE(p)       \
            global_delete(p, __FILE__, __LINE__)

#define     T100DELETES(p)      \
            global_deletes(p, __FILE__, __LINE__)

#define     T100SAFE_DELETE(p)  \
            global_delete(p, __FILE__, __LINE__);   \
            (p)=T100NULL;

#define     T100SAFE_DELETES(p) \
            global_deletes(p, __FILE__, __LINE__);  \
            (p)=T100NULL;

#define     T100LEAK_REPORT     \
            global_leak_report();

void global_out(const char*);
void global_fatal(const char*);
void global_error(const char*);
void global_warn(const char*);

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
