#ifndef T100FILLLAYOUT_H
#define T100FILLLAYOUT_H

#include <windows.h>
#include "gui/layout/T100Layout.h"
#include "gui/common/T100WindowCommon.h"

class T100FillLayout : public T100Layout
{
    public:
        T100FillLayout(T100ORIENTATION_TYPE = T100VERTICAL);
        virtual ~T100FillLayout();

        virtual T100VOID            Update();

        T100VOID                    SetOrientationType(T100ORIENTATION_TYPE);
        T100ORIENTATION_TYPE        GetOrientationType();

    protected:
        T100ORIENTATION_TYPE        m_orientationType;

    private:
        T100VOID                    UpdateHorizontal();
        T100VOID                    UpdateVertical();
};

#endif // T100FILLLAYOUT_H
