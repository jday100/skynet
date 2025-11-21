#ifndef T100COMMON_H
#define T100COMMON_H

#include "T100DataTypes.h"
#include "T100StringTypes.h"
#include "T100Constants.h"

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

