#ifndef T100CODEFILE_H
#define T100CODEFILE_H

#include "T100FileReader.h"


class T100CodeFile
{
    public:
        T100CodeFile(T100FileReader&);
        virtual ~T100CodeFile();

        int run();

    protected:

    private:
        T100FileReader&             m_reader;
};

#endif // T100CODEFILE_H
