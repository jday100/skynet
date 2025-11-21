#ifndef T100EXTENSIONMANAGER_H
#define T100EXTENSIONMANAGER_H

#include "T100Vessel.h"
#include "T100Extension.h"

#define     T100EXTENSION_VESSEL            T100Vessel<T100WSTRING, T100Extension*>

class T100ExtensionManager
{
    public:
        T100ExtensionManager();
        virtual ~T100ExtensionManager();

        virtual T100VOID            Create(const T100WSTRING&, T100Extension*);
        virtual T100VOID            Destroy(const T100WSTRING&);

        virtual T100Extension*      Find(const T100WSTRING&);

    protected:

    private:
        T100EXTENSION_VESSEL        m_extensions;
};

#endif // T100EXTENSIONMANAGER_H
