#ifndef T100STRINGHASH_H
#define T100STRINGHASH_H

#include "T100Common.h"
#include "T100String.h"


class T100StringHash
{
    public:
        T100StringHash();
        virtual ~T100StringHash();

        std::size_t operator()(const T100String& str) const {
            return std::hash<std::u32string>()(str.m_string);
        }

    protected:

    private:
};

#endif // T100STRINGHASH_H
