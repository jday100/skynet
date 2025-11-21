#include "T100CRT.h"

static int g_initialized    = 0;

typedef void (__cdecl *_PVFV)(void);
typedef int (__cdecl *_PIFV)(void);
typedef void (__cdecl *_PVFI)(int);

typedef void(*func_ptr)(void);
extern func_ptr __CTOR_LIST__[];
extern func_ptr __DTOR_LIST__[];

int __cdecl atexit(_PVFV func)
{
    //return _onexit((_onexit_t)func) ? 0 : -1;
    return 0;
}

void __do_global_dtors(void)
{
    static func_ptr* p = __DTOR_LIST__ + 1;

    while(*p){
        (*(p))();
        p++;
    }
}

void __do_global_ctors(void)
{
    unsigned long nptrs = (unsigned long)(ptrdiff_t)__CTOR_LIST__[0];
    unsigned long i;

    if(nptrs == (unsigned long)-1){
        for(nptrs = 0; __CTOR_LIST__[nptrs + 1] != 0; nptrs++);
    }

    for(i = nptrs; i >= 1; i--){
        __CTOR_LIST__[i]();
    }

    atexit(__do_global_dtors);
}

void __main(void)
{
    if(!g_initialized){
        g_initialized   = 1;
        __do_global_ctors();
    }
}

