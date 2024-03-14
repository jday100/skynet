#ifndef T100COMMON_H
#define T100COMMON_H


#ifdef __X86__
#include "common\T100X86Common.h"
#else
#include "common\T100X86Common.h"
#endif // __X86__


#define     T100VOID            void
#define     T100NULL            nullptr
#define     T100BOOL            bool
#define     T100TRUE            true
#define     T100FALSE           false


#define     T100NEW             new
#define     T100DELETE          delete

#endif // T100COMMON_H
