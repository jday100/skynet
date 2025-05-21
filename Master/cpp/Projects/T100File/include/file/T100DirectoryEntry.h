#ifndef T100DIRECTORYENTRY_H
#define T100DIRECTORYENTRY_H

#include "object/T100ObjectTree.h"

class T100DirectoryEntry : public T100ObjectTree
{
    public:
        T100DirectoryEntry(T100WSTRING, T100DirectoryEntry*);
        virtual ~T100DirectoryEntry();

        T100BOOL                Exists();
        T100WSTRING             GetName();

    protected:
        T100WSTRING             m_name;

    private:
};

#endif // T100DIRECTORYENTRY_H
