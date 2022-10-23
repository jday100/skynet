#ifndef T100APPMANAGER_H
#define T100APPMANAGER_H

#include "T100Class.h"

namespace T100Library{

class T100AppManager : public T100Class
{
    public:
        T100AppManager();
        virtual ~T100AppManager();

        virtual T100BOOL            start();

        virtual T100BOOL            stop();

    protected:

    private:
};

}

#endif // T100APPMANAGER_H
