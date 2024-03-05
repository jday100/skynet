#ifndef T100IDEPROJECTPLATEN_H
#define T100IDEPROJECTPLATEN_H

#include <wx/menu.h>
#include "T100IDEPlatenBase.h"
#include "T100Project.h"


namespace T100IDE{

class T100IDEProjectPlaten : public T100IDEPlatenBase
{
    public:
        T100IDEProjectPlaten(T100IDEView*);
        virtual ~T100IDEProjectPlaten();

        T100BOOL            create();

        T100BOOL            show();
        T100BOOL            hide();

        T100VOID            setProject(T100PROJECT::T100Project*);

    protected:
        T100VOID            destroy();

    private:
};

}

#endif // T100IDEPROJECTPLATEN_H
