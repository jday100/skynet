#ifndef T100STRING_H
#define T100STRING_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#undef strlen
#define strlen  crt_str_len

int crt_str_len(const char*);

#ifdef __cplusplus
}
#endif // __cplusplus


#endif // T100STRING_H
