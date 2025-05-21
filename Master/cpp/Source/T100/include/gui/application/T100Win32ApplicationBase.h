#ifndef T100WIN32APPLICATIONBASE_H
#define T100WIN32APPLICATIONBASE_H

#include "gui/event/T100ApplicationEventHandler.h"
#include "gui/event/T100WindowMessageDispatcher.h"

class T100Frame;

#define     T100WINDOW_CLASS_HASH                   std::unordered_map<T100WSTRING, T100BOOL>

class T100Win32ApplicationBase : public T100ApplicationEventHandler
{
    public:
        T100Win32ApplicationBase();
        virtual ~T100Win32ApplicationBase();

    protected:

    private:
};

#endif // T100WIN32APPLICATIONBASE_H
