#ifndef T100DIRECTORYENTRY_H
#define T100DIRECTORYENTRY_H

#include <vector>
#include "T100Class.h"
#include "T100FileCommon.h"

namespace T100Library{

#define     T100DIRECTORY_ENTRY_VECTOR          std::vector<T100Library::T100DirectoryEntry*>

class T100DirectoryEntry : public T100Class
{
    public:
        T100DirectoryEntry(T100WSTRING);
        virtual ~T100DirectoryEntry();

        T100BOOL            exists();

        T100WSTRING         getName();

    protected:

    private:
        T100WSTRING         m_name;

};

}

#endif // T100DIRECTORYENTRY_H
