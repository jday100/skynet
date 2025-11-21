#ifndef T1003DEDITORTASKREADFILE_H
#define T1003DEDITORTASKREADFILE_H

#include "T100Common.h"
#include "T1003DEditorDocument.h"

class T1003DEditorTaskReadFile
{
    public:
        T1003DEditorTaskReadFile();
        virtual ~T1003DEditorTaskReadFile();

        T100VOID            Read(T100WSTRING, T1003DEditorDocument&);

    protected:

    private:
};

#endif // T1003DEDITORTASKREADFILE_H
