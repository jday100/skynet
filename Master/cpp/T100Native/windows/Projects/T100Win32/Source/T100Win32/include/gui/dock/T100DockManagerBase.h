#ifndef T100DOCKMANAGERBASE_H
#define T100DOCKMANAGERBASE_H

#include <vector>
#include <unordered_map>
#include "gui/T100Window.h"
#include "gui/dock/T100DockInfo.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

typedef struct T100DOCK_DATA{
    T100WSTRING         LABEL;
    T100Window*         WINDOW;
    T100DockInfo        INFO;
}T100DOCK_DATA;

#define     T100DOCK_WINDOW_VECTOR                  std::vector<T100DOCK_DATA*>
#define     T100DOCK_WINDOW_HASH                    std::unordered_map<T100Window*, T100DOCK_DATA*>
#define     T100DOCK_LABEL_HASH                     std::unordered_map<T100WSTRING, T100DOCK_DATA*>

class T100Frame;

class T100DockManagerBase : public T100Class
{
    public:
        T100DockManagerBase();
        T100DockManagerBase(T100Frame*);
        virtual ~T100DockManagerBase();

        T100VOID                        SetFrame(T100Frame*);
        T100Frame*                      GetFrame();

    protected:
        T100Frame*                      m_frame         = T100NULL;
        T100DOCK_LABEL_HASH             m_labels;
        T100DOCK_WINDOW_HASH            m_windows;
        T100DOCK_WINDOW_VECTOR          m_children;

        T100VOID                        UpdateLeft();
        T100VOID                        UpdateRight();
        T100VOID                        UpdateTop();
        T100VOID                        UpdateBottom();
        T100VOID                        UpdateCenter();

        T100VOID                        Classify(T100DOCK_DATA*);

    protected:
        T100DOCK_WINDOW_VECTOR          m_leftWindows;
        T100DOCK_WINDOW_VECTOR          m_rightWindows;
        T100DOCK_WINDOW_VECTOR          m_topWindows;
        T100DOCK_WINDOW_VECTOR          m_bottomWindows;
        T100DOCK_DATA*                  m_centerWindow      = T100NULL;

    private:
        T100INT                         m_leftSize          = 0;
        T100INT                         m_rightSize         = 0;
        T100INT                         m_topSize           = 0;
        T100INT                         m_bottomSize        = 0;
};

}

#endif // T100DOCKMANAGERBASE_H
