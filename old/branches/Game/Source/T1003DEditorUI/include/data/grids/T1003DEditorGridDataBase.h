#ifndef T1003DEDITORGRIDDATABASE_H
#define T1003DEDITORGRIDDATABASE_H

#include <vector>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include "T100Common.h"

typedef struct{
    wxStringProperty*       Category;
    wxEnumProperty*         Reference;
    wxStringProperty*       Name;
    wxUIntProperty*         Index;
    wxEnumProperty*         Format;
    wxUIntProperty*         Slot;
    wxUIntProperty*         Offset;
    wxEnumProperty*         InputClass;
    wxUIntProperty*         Rate;
}T1003DEDITOR_GRID_DATA_DESCRIPTION;

typedef struct{
    wxStringProperty*       Category;
    wxEnumProperty*         Reference;
    wxEnumProperty*         RangeType;
    wxUIntProperty*         Length;
    wxUIntProperty*         Register;
    wxUIntProperty*         Space;
    wxEnumProperty*         Flags;
    wxUIntProperty*         Offset;
    wxUIntProperty*         NumRanges;
    wxEnumProperty*         Visibility;
}T1003DEDITOR_GRID_DATA_PARAMETER;

typedef struct{
    wxEnumProperty*         Reference;
    wxEnumProperty*         Type;
    wxFileProperty*         File;
    wxStringProperty*       Entry;
    wxStringProperty*       Target;
}T1003DEDITOR_GRID_DATA_SHADER;

#define     T1003DEDITOR_GRID_DATA_VECTOR                       std::vector<wxPGProperty*>
#define     T1003DEDITOR_GRID_DATA_DESCRIPTION_VECTOR           std::vector<T1003DEDITOR_GRID_DATA_DESCRIPTION>
#define     T1003DEDITOR_GRID_DATA_PARAMETER_VECTOR             std::vector<T1003DEDITOR_GRID_DATA_PARAMETER>


class T1003DEditorGridDataBase
{
    public:
        T1003DEditorGridDataBase();
        virtual ~T1003DEditorGridDataBase();

    protected:

    private:
};

#endif // T1003DEDITORGRIDDATABASE_H
