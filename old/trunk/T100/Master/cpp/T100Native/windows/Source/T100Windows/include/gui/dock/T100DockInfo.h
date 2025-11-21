#ifndef T100DOCKINFO_H
#define T100DOCKINFO_H

#include "base/T100Size.h"
#include "gui/common/T100DockCommon.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100DockInfo : public T100Class
{
    public:
        T100DockInfo();
        virtual ~T100DockInfo();

        T100DOCK_POSITION_TYPE          GetPosition();
        const T100Size&                 GetMaxSize();
        const T100Size&                 GetMinSize();
        const T100Size&                 GetBestSize();

        T100DockInfo&                   Caption(const T100WSTRING&);
        T100DockInfo&                   CloseButton(T100BOOL);
        T100DockInfo&                   Direction();
        T100DockInfo&                   Left();
        T100DockInfo&                   Right();
        T100DockInfo&                   Top();
        T100DockInfo&                   Bottom();
        T100DockInfo&                   Center();

        T100DockInfo&                   MaxSize(T100INT, T100INT);
        T100DockInfo&                   MaxSize(const T100Size&);

        T100DockInfo&                   MinSize(T100INT, T100INT);
        T100DockInfo&                   MinSize(const T100Size&);

        T100DockInfo&                   BestSize(T100INT, T100INT);
        T100DockInfo&                   BestSize(const T100Size&);

    protected:
        T100Size                        m_maxSize;
        T100Size                        m_minSize;
        T100Size                        m_bestSize;
        T100DOCK_POSITION_TYPE          m_position      = T100DOCK_NONE;

        T100WSTRING                     m_caption;
        T100BOOL                        m_closeButton   = T100TRUE;

    private:
};

}

#endif // T100DOCKINFO_H
