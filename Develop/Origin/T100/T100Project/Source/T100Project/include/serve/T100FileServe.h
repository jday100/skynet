#ifndef T100FILESERVE_H
#define T100FILESERVE_H

#include <unordered_map>
#include "T100FileInfo.h"
#include "T100WxFileInfo.h"

#define     T100FILE_INFO_HASH                      std::unordered_map<T100WSTRING, T100FileInfo*>

class T100FileServe
{
    public:
        T100FileServe();
        virtual ~T100FileServe();

        T100BOOL                    IsOpened(const T100WSTRING&);
        T100FileInfo*               GetFileInfo(const T100WSTRING&);

        T100FileInfo*               Create();

        T100BOOL                    Open(T100FileInfo*);
        T100BOOL                    Open(T100WxFileInfo&);
        T100BOOL                    Close(const T100WSTRING&);

        T100BOOL                    Clear();

    protected:
        T100FILE_INFO_HASH          m_openedFiles;

    private:
};

#endif // T100FILESERVE_H
