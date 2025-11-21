#ifndef T100INSTRUCT_H
#define T100INSTRUCT_H

#include <unordered_map>
#include "T100Common.h"

#define     T100INSTRUCT_HASH           std::unordered_map<T100BYTE, T100Instruct*>

class T100Instruct
{
    public:
        T100Instruct();
        virtual ~T100Instruct();

        virtual T100VOID            Execute(T100BYTE) = 0;

    protected:

    private:
};

#endif // T100INSTRUCT_H
