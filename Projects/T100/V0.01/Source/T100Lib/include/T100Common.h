#ifndef T100COMMON_H
#define T100COMMON_H

#ifdef __LEAK__
    #include "T100Leak.h"
#else
    #define T100NEW                         new
    #define T100NEWS                        new[]
    #define T100SAFE_DELETE(p)              if((p)){ \
                                                delete(p); \
                                                (p) = T100NULL; \
                                            };

    #define T100SAFE_DELETES(p)             if((p)){ \
                                                delete[](p); \
                                                (p) = T100NULL; \
                                            };


    #include "T100DataTypes.h"
#endif // __LEAK__

#include "T100StringTypes.h"
#include "T100DataStructure.h"


#endif // T100COMMON_H
