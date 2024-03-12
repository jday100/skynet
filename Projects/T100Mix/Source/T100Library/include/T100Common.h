#ifndef T100COMMON_H
#define T100COMMON_H


#ifdef __X86__
#include "T100X86Common.h"
#else
#include "T100X86Common.h"
#endif // __X86__


#define     T100VOID            void
#define     T100BOOL            bool
#define     T100TRUE            true
#define     T100FALSE           false

#endif // T100COMMON_H
