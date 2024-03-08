#ifndef T100PATHTOOLS_H
#define T100PATHTOOLS_H

#include "T100Common.h"
#include "T100Class.h"
#include "T100DirectoryEntry.h"

namespace T100Library{

class T100PathTools : public T100Class
{
    public:
        T100PathTools();
        virtual ~T100PathTools();

        static T100WSTRING          getCwd();
        static T100BOOL             format(T100WSTRING, T100WSTRING&, T100WSTRING&);
        static T100BOOL             full(T100WSTRING, T100WSTRING&);
        static T100BOOL             split(T100WSTRING, T100WSTRING&, T100WSTRING&);

        static T100BOOL             join(T100WSTRING, T100WSTRING, T100WSTRING&);

        static T100BOOL             mkdir(T100WSTRING);
        static T100BOOL             chdir(T100WSTRING);
        static T100BOOL             rmdir(T100WSTRING);
;
        static T100BOOL             enum_directories(T100WSTRING, T100DIRECTORY_ENTRY_VECTOR&);
        static T100BOOL             enum_files(T100WSTRING, T100DIRECTORY_ENTRY_VECTOR&);

    protected:

    private:
};

}

#endif // T100PATHTOOLS_H
