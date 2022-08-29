#ifndef ISENTENCE_H
#define ISENTENCE_H

#include "T100Common.h"
#include "T100TokenTypes.h"
class T100FileData;



class ISentence
{
    public:
        ISentence();
        virtual ~ISentence();

        T100TOKEN_TYPE          type        = T100TOKEN_NONE;
        virtual T100BOOL        parse()=0;
        virtual T100BOOL        build(T100FileData*)=0;

    protected:

    private:
};

#endif // ISENTENCE_H
