#ifndef T100SHELLTOOLS_H
#define T100SHELLTOOLS_H

#include "T100Common.h"
#include "T100DataTypes.h"


class T100ShellTools
{
    public:
        T100ShellTools();
        virtual ~T100ShellTools();

        static T100INTEGER      system(T100STDSTRING);

    protected:

    private:
};

#endif // T100SHELLTOOLS_H
