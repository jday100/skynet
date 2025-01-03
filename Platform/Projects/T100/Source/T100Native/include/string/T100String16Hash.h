#ifndef T100STRING16HASH_H
#define T100STRING16HASH_H

#include "T100String16.h"

class T100String16Hash
{
    public:
        T100String16Hash();
        virtual ~T100String16Hash();

        std::size_t operator()(const T100String16& str) const {
            return std::hash<std::u16string>()(str.m_value);
        }

    protected:

    private:
};

#endif // T100STRING16HASH_H
