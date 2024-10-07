#ifndef T100FILE_H
#define T100FILE_H

#include "T100Common.h"
#include "T100WString.h"
class T100BinaryFileReader;

class T100File
{
    friend class T100BinaryFileReader;
    public:
        T100File();
        T100File(T100WString);
        virtual ~T100File();

        T100BOOL                        open();
        T100BOOL                        close();

        T100BinaryFileReader&           GetBinaryReader();

    protected:
        T100WString                     m_name;

    private:
};

#endif // T100FILE_H
