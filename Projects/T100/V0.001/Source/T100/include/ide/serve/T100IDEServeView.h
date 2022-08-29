#ifndef T100IDESERVEVIEW_H
#define T100IDESERVEVIEW_H

#include "T100IDEServeBase.h"
#include "T100IDEProjectData.h"


class T100IDEServeView : public T100IDEServeBase
{
    public:
        T100IDEServeView(T100IDEServe*);
        virtual ~T100IDEServeView();

        T100BOOL            project(T100IDE_PROJECT_VECTOR&);

    protected:

    private:
};

#endif // T100IDESERVEVIEW_H
