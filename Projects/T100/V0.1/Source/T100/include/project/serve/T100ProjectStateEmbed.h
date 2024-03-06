#ifndef T100PROJECTSTATEEMBED_H
#define T100PROJECTSTATEEMBED_H

#include "T100ProjectState.h"

namespace T100PROJECT{

class T100ProjectStateEmbed : public T100ProjectState
{
    public:
        T100ProjectStateEmbed();
        virtual ~T100ProjectStateEmbed();

        T100BOOL                        Create();

        T100VOID                        SetMenu();
        T100VOID                        ResetMenu();

        T100ProjectProjectsPanel*       GetProjectsPanel();

    protected:

    private:
};

}

#endif // T100PROJECTSTATEEMBED_H
