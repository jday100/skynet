#ifndef T1003DEDITORSPHEREGRID_H
#define T1003DEDITORSPHEREGRID_H

#include "T1003DEditorEntityGrid.h"

class T1003DEditorSphereGrid : public T1003DEditorEntityGrid
{
    public:
        T1003DEditorSphereGrid(wxPropertyGrid*);
        virtual ~T1003DEditorSphereGrid();

        virtual T100VOID            Update(T100Entity*);

        virtual T100VOID            OnPGChanged(wxPropertyGridEvent& event);

    protected:

    private:
};

#endif // T1003DEDITORSPHEREGRID_H
