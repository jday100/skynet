#ifndef T100AL_H
#define T100AL_H

#include "T100AppBase.h"

namespace T100AL{

class T100AL : public T100Library::T100AppBase
{
    public:
        T100AL(T100Library::T100AppManager*);
        virtual ~T100AL();

    protected:

    private:
};

}

#endif // T100AL_H
