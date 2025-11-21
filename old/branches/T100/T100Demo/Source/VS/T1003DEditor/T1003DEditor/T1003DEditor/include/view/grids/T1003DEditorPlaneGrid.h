#ifndef T1003DEDITORPLANEGRID_H
#define T1003DEDITORPLANEGRID_H

#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include "T100Common.h"
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


    protected:


    private:
};

#endif // T1003DEDITORPLANEGRID_H
