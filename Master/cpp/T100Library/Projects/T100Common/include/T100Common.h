#ifndef T100COMMON_H
#define T100COMMON_H

#include "common/T100Constants.h"
#include "common/T100StringTypes.h"

namespace T100LIBRARY{

#ifdef __LEAK__

#else
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
#endif // __T100LEAK__

}

#endif // T100COMMON_H
