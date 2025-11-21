#ifndef T1003DEDITORPLANEGRID_H
#define T1003DEDITORPLANEGRID_H

#include "entity/T100Plane.h"
#include "T1003DEditorEntityGrid.h"

class T1003DEditorPlaneGrid : public T1003DEditorEntityGrid
{
    public:
        T1003DEditorPlaneGrid(wxPropertyGrid*);
        virtual ~T1003DEditorPlaneGrid();

        virtual T100VOID            Update(T100Entity*);
        virtual T100VOID            OnPGChanged(wxPropertyGridEvent& event);

    protected:

    private:
};

#endif // T1003DEDITORPLANEGRID_H
