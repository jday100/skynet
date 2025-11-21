#ifndef T1003DEDITORMESHGRID_H
#define T1003DEDITORMESHGRID_H

#include "T1003DEditorEntityGrid.h"

class T1003DEditorMeshGrid : public T1003DEditorEntityGrid
{
    public:
        T1003DEditorMeshGrid(wxPropertyGrid*);
        virtual ~T1003DEditorMeshGrid();

        virtual T100VOID            Update(T100Entity*);

        virtual T100VOID            OnPGChanged(wxPropertyGridEvent& event);

    protected:

    private:
};

#endif // T1003DEDITORMESHGRID_H
