#ifndef T100FILELOGIC_H
#define T100FILELOGIC_H

#include <unordered_map>
#include "T100FileInfo.h"

#define     T100FILE_INFO_HASH                  std::unordered_map<T100WSTRING, T100FileInfo*>

class T100FileLogic
{
    public:
        T100FileLogic();
        virtual ~T100FileLogic();

        T100BOOL                    IsExists(const T100WSTRING&);

        T100BOOL                    Create(T100FileInfo*);
        T100BOOL                    Remove(T100FileInfo*);

        T100VOID                    Clear();

        T100BOOL                    Open(const T100WSTRING&, T100FileInfo*);
        T100BOOL                    Close(const T100WSTRING&);

        T100BOOL                    Rename(T100FileInfo*);

    protected:
        T100FILE_INFO_HASH          m_openedFiles;

    private:
};

#endif // T100FILELOGIC_H
