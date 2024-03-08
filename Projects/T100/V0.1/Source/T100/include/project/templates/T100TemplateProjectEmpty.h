#ifndef T100TEMPLATEPROJECTEMPTY_H
#define T100TEMPLATEPROJECTEMPTY_H

#include "T100ProjectTemplate.h"

namespace T100PROJECT{

class T100TemplateProjectEmpty : public T100ProjectTemplate
{
    public:
        T100TemplateProjectEmpty(T100MansionDrawer*, T100ProjectInfo*);
        virtual ~T100TemplateProjectEmpty();

        T100BOOL            Create();

    protected:

    private:
};

}

#endif // T100TEMPLATEPROJECTEMPTY_H
