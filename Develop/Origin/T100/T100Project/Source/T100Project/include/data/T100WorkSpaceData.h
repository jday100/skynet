#ifndef T100WORKSPACEDATA_H
#define T100WORKSPACEDATA_H

#include "T100TreeItemData.h"

class T100WorkSpaceData : public T100TreeItemData
{
    public:
        T100WorkSpaceData();
        virtual ~T100WorkSpaceData();

        virtual wxMenu*         ShowMenu();

    protected:

    private:
};

#endif // T100WORKSPACEDATA_H
