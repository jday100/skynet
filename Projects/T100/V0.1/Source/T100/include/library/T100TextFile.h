#ifndef T100TEXTFILE_H
#define T100TEXTFILE_H

#include "T100File.h"

namespace T100Library{

class T100TextFile : public T100File
{
    public:
        T100TextFile(T100WSTRING);
        virtual ~T100TextFile();

    protected:

    private:
};

}

#endif // T100TEXTFILE_H
