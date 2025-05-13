#ifndef T100SERVER_H
#define T100SERVER_H

#include "base/T100Class.h"

class T100Server : public T100Class
{
    public:
        T100Server();
        virtual ~T100Server();

        virtual T100BOOL            Start() = 0;
        virtual T100BOOL            Stop() = 0;

    protected:

    private:
};

#endif // T100SERVER_H
