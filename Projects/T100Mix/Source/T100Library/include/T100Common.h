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


#define     T100NEW                     new
#define     T100NEWS                    new[]
#define     T100SAFE_DELETE(p)          if((p)){ \
                                            delete(p); \
                                            (p) = T100NULL; \
                                        };

#define     T100SAFE_DELETES(p)         if((p)){ \
                                            delete[](p); \
                                            (p) = T100NULL; \
                                        };

#endif // T100COMMON_H
