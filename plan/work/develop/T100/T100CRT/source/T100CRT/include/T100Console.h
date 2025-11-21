#ifndef T100CONSOLE_H
#define T100CONSOLE_H

#include <T100String.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#undef print
#define print  crt_print

void crt_print(const char*);

#ifdef __cplusplus
}
#endif // __cplusplus


#endif // T100CONSOLE_H
