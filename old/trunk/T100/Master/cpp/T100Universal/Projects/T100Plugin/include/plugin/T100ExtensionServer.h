#ifndef T100EXTENSIONSERVER_H
#define T100EXTENSIONSERVER_H

#include "vessel/T100Vessel.h"
#include "plugin/T100Extension.h"

using namespace T100LIBRARY;

namespace T100UNIVERSAL{

#define     T100EXTENSION_VESSEL            T100Vessel<T100WSTRING, T100Extension*>

class T100ExtensionServer : public T100Class
{
    public:
        T100ExtensionServer();
        virtual ~T100ExtensionServer();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

        virtual T100VOID            CreateExtension(const T100WSTRING&, T100Extension*);
        virtual T100VOID            DestroyExtension(const T100WSTRING&);

        virtual T100Extension*      Find(const T100WSTRING&);

    protected:
        T100EXTENSION_VESSEL        m_extensions;

    private:
};

}

#endif // T100EXTENSIONSERVER_H
