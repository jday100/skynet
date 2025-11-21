#ifndef T1003DEDITORENTITYMANAGER_H
#define T1003DEDITORENTITYMANAGER_H

#include <atomic>
#include "T100Common.h"
#include "link/T100Entity.h"
#include "link/T100Editable.h"

class T1003DEditorEntityManager
{
    public:
        T1003DEditorEntityManager();
        virtual ~T1003DEditorEntityManager();

        T100VOID                Update(T100INT);
        T100VOID                Clear();

        T100Entity*             GetCurrent();
        T100Editable*           GetEditable();

    protected:
        std::atomic_bool        m_appendState;
        std::atomic_int         m_type;
        T100Entity*             m_entity            = T100NULL;

        std::atomic_int         m_dotCount;
        std::atomic_int         m_lineCount;
        std::atomic_int         m_triangleCount;
        std::atomic_int         m_planeCount;
        std::atomic_int         m_cityCount;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T1003DEDITORENTITYMANAGER_H
