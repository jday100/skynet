#ifndef T100LOGAPPENDER_H
#define T100LOGAPPENDER_H

#include "T100LogCommon.h"


class T100LogAppender
{
    public:
        T100LogAppender();
        virtual ~T100LogAppender();

        virtual T100VOID        outline(T100WORD, T100WSTRING) = 0;

    protected:

    private:
};

#endif // T100LOGAPPENDER_H
