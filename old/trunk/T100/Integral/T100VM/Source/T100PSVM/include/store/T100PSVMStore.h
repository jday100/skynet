#ifndef T100PSVMSTORE_H
#define T100PSVMSTORE_H

#include "T100PSVMFile.h"
#include "T100WxFileInfo.h"

class T100PSVMStore
{
    public:
        T100PSVMStore();
        virtual ~T100PSVMStore();

        T100WxFileInfo*     GetFile();

        T100BOOL            Load(T100WxFileInfo*, T100PSVMInfo*);
        T100BOOL            Save(T100WxFileInfo*, T100PSVMInfo*);

    protected:
        T100WxFileInfo*     m_file      = T100NULL;

    private:
};

#endif // T100PSVMSTORE_H
