#ifndef T100DOCKINFO_H
#define T100DOCKINFO_H

#include "base/T100Class.h"
#include "gui/base/T100Size.h"
#include "gui/common/T100DockCommon.h"

class T100DockInfo : public T100Class
{
    public:
        T100DockInfo();
        virtual ~T100DockInfo();

        T100DOCK_POSITION_TYPE&         GetPosition();
        T100Size&                       GetMaxSize();
        T100Size&                       GetMinSize();
        T100Size&                       GetBestSize();

        T100DockInfo&                   Left();
        T100DockInfo&                   Right();
        T100DockInfo&                   Top();
        T100DockInfo&                   Bottom();
        T100DockInfo&                   Center();

        T100DockInfo&                   MaxSize(T100INT, T100INT);
        T100DockInfo&                   MaxSize(T100Size&);

        T100DockInfo&                   MinSize(T100INT, T100INT);
        T100DockInfo&                   MinSize(T100Size&);

        T100DockInfo&                   BestSize(T100INT, T100INT);
        T100DockInfo&                   BestSize(T100Size&);

    protected:

    private:
        T100Size                        m_maxSize;
        T100Size                        m_minSize;
        T100Size                        m_bestSize;
        T100DOCK_POSITION_TYPE          m_position      = T100DOCK_NONE;
};

#endif // T100DOCKINFO_H
