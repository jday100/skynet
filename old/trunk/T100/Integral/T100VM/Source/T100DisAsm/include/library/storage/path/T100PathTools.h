#ifndef T100PATHTOOLS_H
#define T100PATHTOOLS_H

#include "T100Common.h"

class T100PathTools
{
    public:
        T100PathTools();
        virtual ~T100PathTools();

        static const T100STRING             GetCwd();

        static T100BOOL                     Format(const T100STRING&, T100STRING&, T100STRING&);
        static T100BOOL                     FullPath(const T100STRING&, T100STRING&);
        static T100BOOL                     Split(const T100STRING&, T100STRING&, T100STRING&);

    protected:

    private:
};

#endif // T100PATHTOOLS_H
