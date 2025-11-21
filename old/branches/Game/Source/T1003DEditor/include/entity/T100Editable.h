#ifndef T100EDITABLE_H
#define T100EDITABLE_H

#include <atomic>
#include "T100Entity.h"

class T100Editable : public T100Entity
{
    friend class T100GameScene;
    friend class T100GameCallback;
    friend class T1003DEditorLightManager;
    public:
        T100Editable();
        virtual ~T100Editable();

        T100VOID                    SetEditable(T100BOOL = T100TRUE);
        T100BOOL                    IsEditable();

        T100VOID                    SetPosition(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetPosition(T100Vector3);

        T100Entity*                 GetSelection();

    protected:
        std::atomic_bool            m_editable;
        T100Entity*                 m_selection         = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100EDITABLE_H
