#ifndef T100WINDOWSFILE_H
#define T100WINDOWSFILE_H

#include "storage/file/binary/T100BinaryFile.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100WindowsFile : public T100BinaryFile
{
    public:
        T100WindowsFile(const T100WSTRING&);
        virtual ~T100WindowsFile();

        virtual T100BOOL            Load();

    protected:

    private:
};

}

#endif // T100WINDOWSFILE_H
