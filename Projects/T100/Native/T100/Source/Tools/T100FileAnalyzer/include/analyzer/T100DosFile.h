#ifndef T100DOSFILE_H
#define T100DOSFILE_H

#include "T100CodeFile.h"



class T100DosFile : public T100CodeFile
{
    public:
        T100DosFile(T100ByteBuffer&);
        virtual ~T100DosFile();

        bool    parse();

    protected:

    private:
};

#endif // T100DOSFILE_H
