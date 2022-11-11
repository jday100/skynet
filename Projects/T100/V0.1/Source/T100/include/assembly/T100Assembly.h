#ifndef T100ASSEMBLY_H
#define T100ASSEMBLY_H

#include "T100App.h"
#include "T100ThisAppCmdLineResult.h"

namespace T100Assembly{

class T100Assembly : public T100Library::T100App
{
    public:
        T100Assembly(T100Library::T100AppManager*);
        virtual ~T100Assembly();

        T100BOOL            run(T100ThisAppCmdLineResult&);

    protected:

    private:
};

}

#endif // T100ASSEMBLY_H
