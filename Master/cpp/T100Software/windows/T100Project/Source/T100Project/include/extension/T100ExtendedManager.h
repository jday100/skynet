#ifndef T100EXTENDEDMANAGER_H
#define T100EXTENDEDMANAGER_H

#include <unordered_map>
#include "T100Common.h"
#include "gui/handler/T100EventHandler.h"
#include "T100Extension.h"

using namespace T100LIBRARY;
using namespace T100WINDOWS;

#define     T100EXTENSION_HASH                  std::unordered_map<T100WSTRING, T100Extension*>

class T100ExtendedManager
{
    public:
        T100ExtendedManager();
        virtual ~T100ExtendedManager();

        virtual T100VOID                    SignIn(const T100WSTRING&, T100Extension*);
        virtual T100VOID                    SignOut(const T100WSTRING&);

        T100VOID                            Append(const T100WSTRING&, T100UINT, const T100WSTRING&);

        T100VOID                            Bind(const T100WSTRING&, T100UINT, T100EventHandler*, T100EVENT_FUNCTION, T100EventHandler* = T100NULL);

        T100VOID                            ConnectMenu(const T100WSTRING&, T100UINT, T100EventHandler*, T100EVENT_FUNCTION, T100EventHandler* = T100NULL);
        T100VOID                            SendMenu(const T100WSTRING&, T100MenuEvent&);
        T100VOID                            FindMenu(const T100WSTRING&, T100MenuEvent&);

        T100VOID                            SendEvent(const T100WSTRING&, T100Event&);

        T100VOID                            Connect(const T100WSTRING&, T100VOID*);

    protected:
        T100EXTENSION_HASH                  m_extensions;

    private:
};

#endif // T100EXTENDEDMANAGER_H
