#ifndef T100CLCHARTOKEN_H
#define T100CLCHARTOKEN_H

#include "develop/compiler/token/T100CharToken.h"

class T100CLCharToken : public T100CharToken
{
    public:
        T100CLCharToken();
        virtual ~T100CLCharToken();

        T100WChar           value;

    protected:

    private:
};

#endif // T100CLCHARTOKEN_H
