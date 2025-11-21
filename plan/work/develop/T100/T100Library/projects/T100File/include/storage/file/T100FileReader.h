#ifndef T100FILEREADER_H
#define T100FILEREADER_H

#include <fstream>
#include "storage/T100Reader.h"

namespace T100LIBRARY{

class T100FileReader : public T100Reader
{
    public:
        T100FileReader();
        virtual ~T100FileReader();

    protected:

    private:
};

}

#endif // T100FILEREADER_H
