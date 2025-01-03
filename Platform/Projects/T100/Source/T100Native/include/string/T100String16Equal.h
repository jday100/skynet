#ifndef T100STRING16EQUAL_H
#define T100STRING16EQUAL_H

#include "T100String16.h"

class T100String16Equal
{
    public:
        T100String16Equal();
        virtual ~T100String16Equal();

        bool operator()(const T100String16& str1, const T100String16& str2) const {
            return str1.m_value == str2.m_value;
        }

    protected:

    private:
};

#endif // T100STRING16EQUAL_H
