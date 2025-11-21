#ifndef T1003DEDITORTRIANGLEGRID_H
#define T1003DEDITORTRIANGLEGRID_H

#include "T1003DEditorEntityGrid.h"

class T1003DEditorTriangleGrid : public T1003DEditorEntityGrid
{
    public:
        T1003DEditorTriangleGrid(wxPropertyGrid*);
        virtual ~T1003DEditorTriangleGrid();

        virtual T100VOID            Update(T100Entity*);

        virtual T100VOID            OnPGChanged(wxPropertyGridEvent& event);

    protected:

    private:
};

#endif // T1003DEDITORTRIANGLEGRID_H
