#ifndef T100HINTLIB_H
#define T100HINTLIB_H

#include "T100Hint.h"
class T100File;


static std::string      T100LIB_HINT_FILE_READ                          =   "Read";
static std::string      T100LIB_HINT_FILE_WRITE                         =   "Write";

static std::string      T100LIB_HINT_FILE_OPEN                          =   "Open file:";
static std::string      T100LIB_HINT_FILE_CLOSE                         =   "Close file:";


class T100HintLib : public T100Hint
{
    public:
        T100HintLib();
        virtual ~T100HintLib();

        static T100STDSTRING        file_hint(T100File*, T100WORD*, T100WORD, T100STDSTRING);
        static T100STDSTRING        file_hint(T100File*, T100STDSTRING);


    protected:

    private:
};

#endif // T100HINTLIB_H
