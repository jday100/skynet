#ifndef T100PSVMFILE_H
#define T100PSVMFILE_H

#include "T100File.h"
#include "T100XML.h"
#include "T100PSVMInfo.h"

class T100PSVMFile : public T100File
{
    public:
        T100PSVMFile(T100STRING);
        virtual ~T100PSVMFile();

        T100BOOL            Load(T100PSVMInfo*);
        T100BOOL            Save(T100PSVMInfo*);

    protected:

    private:
};

#endif // T100PSVMFILE_H
