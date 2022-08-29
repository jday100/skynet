#ifndef T100EDITORSERVEBASE_H
#define T100EDITORSERVEBASE_H

#include "T100Common.h"
class T100EditorServe;


class T100EditorServeBase
{
    public:
        T100EditorServeBase(T100EditorServe*);
        virtual ~T100EditorServeBase();

    protected:
        T100EditorServe*        m_serve         = T100NULL;

    private:
};

#endif // T100EDITORSERVEBASE_H
