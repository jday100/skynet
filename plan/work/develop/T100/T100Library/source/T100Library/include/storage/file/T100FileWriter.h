#ifndef T100FILEWRITER_H
#define T100FILEWRITER_H

#include <fstream>
#include "storage/T100Writer.h"

namespace T100LIBRARY{

class T100FileWriter : public T100Writer
{
    public:
        T100FileWriter();
        virtual ~T100FileWriter();

    protected:

    private:
};

}

#endif // T100FILEWRITER_H
