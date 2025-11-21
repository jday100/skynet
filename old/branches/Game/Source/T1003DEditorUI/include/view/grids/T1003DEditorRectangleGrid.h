#ifndef T1003DEDITORRECTANGLEGRID_H
#define T1003DEDITORRECTANGLEGRID_H

#include "T1003DEditorEntityGrid.h"
#include "T1003DEditorEntityGridData.h"

class T1003DEditorRectangleGrid : public T1003DEditorEntityGrid
{
    public:
        T1003DEditorRectangleGrid(wxPropertyGrid*);
        virtual ~T1003DEditorRectangleGrid();

        virtual T100VOID                Update(T100Entity*);

        virtual T100VOID                OnPGChanged(wxPropertyGridEvent& event);

    protected:
        T1003DEditorEntityGridData      m_entityData;

    private:
        T100VOID                        CreateShader();
};

#endif // T1003DEDITORRECTANGLEGRID_H
