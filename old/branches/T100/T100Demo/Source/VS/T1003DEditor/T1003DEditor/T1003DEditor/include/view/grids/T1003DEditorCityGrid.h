#ifndef T1003DEDITORCITYGRID_H
#define T1003DEDITORCITYGRID_H

#include "T1003DEditorEntityGrid.h"

class T1003DEditorCityGrid : public T1003DEditorEntityGrid
{
    public:
        T1003DEditorCityGrid(wxPropertyGrid*);
        virtual ~T1003DEditorCityGrid();

        virtual T100VOID            Update(T100Entity*);

        virtual T100VOID            OnPGChanged(wxPropertyGridEvent& event);

    protected:

    private:
};

#endif // T1003DEDITORCITYGRID_H
