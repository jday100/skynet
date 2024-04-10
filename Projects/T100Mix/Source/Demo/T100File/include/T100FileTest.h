#ifndef T100FILETEST_H
#define T100FILETEST_H

#include "T100File.h"
#include "T100StdFile.h"

class T100FileTest
{
    public:
        T100FileTest();
        virtual ~T100FileTest();

        T100BOOL            load();
        T100BOOL            save();

        T100BOOL            std_save();

    protected:

    private:
};

#endif // T100FILETEST_H
