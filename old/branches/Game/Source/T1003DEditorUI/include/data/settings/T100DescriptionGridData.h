#ifndef T100DESCRIPTIONGRIDDATA_H
#define T100DESCRIPTIONGRIDDATA_H

#include "T1003DEditorSettingsDescriptionPanel.h"
#include "T100SettingsGridClientData.h"

class T100DescriptionGridData : public T100SettingsGridClientData
{
    public:
        T100DescriptionGridData();
        virtual ~T100DescriptionGridData();

        T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION*        Desc        = T100NULL;

    protected:

    private:
};

#endif // T100DESCRIPTIONGRIDDATA_H
