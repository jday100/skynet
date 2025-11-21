#ifndef T1003DEDITORDOTGRID_H
#define T1003DEDITORDOTGRID_H

#include "T1003DEditorEntityGrid.h"

class T1003DEditorDotGrid : public T1003DEditorEntityGrid
{
    public:
        T1003DEditorDotGrid(wxPropertyGrid*);
        virtual ~T1003DEditorDotGrid();

        virtual T100VOID            Update(T100Entity*);

        virtual T100VOID            OnPGChanged(wxPropertyGridEvent& event);

    protected:

    private:
};

#endif // T1003DEDITORDOTGRID_H
