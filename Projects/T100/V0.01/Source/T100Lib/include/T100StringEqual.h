#ifndef T100STRINGEQUAL_H
#define T100STRINGEQUAL_H

#include "T100String.h"


class T100StringEqual
{
    public:
        T100StringEqual();
        virtual ~T100StringEqual();

        bool operator()(const T100String& str1, const T100String& str2) const {
            return str1.m_wstring == str2.m_wstring;
        }

    protected:

    private:
};

#endif // T100STRINGEQUAL_H
