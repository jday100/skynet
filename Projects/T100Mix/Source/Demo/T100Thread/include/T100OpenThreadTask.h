#ifndef T100OPENTHREADTASK_H
#define T100OPENTHREADTASK_H

#include <wx/frame.h>
#include "T100ThreadTask.h"
class T100ThreadFrame;

class T100OpenThreadTask : public T100ThreadTask
{
    public:
        T100OpenThreadTask(wxFrame*);
        virtual ~T100OpenThreadTask();

    protected:
        void                run();

        void                send(int);

    private:
        T100ThreadFrame*    m_frame         = nullptr;
};

#endif // T100OPENTHREADTASK_H
