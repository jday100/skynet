#ifndef T100ACTUATOR_H
#define T100ACTUATOR_H

#include "T100Editor.h"

class T100Actuator
{
    public:
        T100Actuator();
        virtual ~T100Actuator();

        void            Message();

    protected:
        T100Editor      m_editor;

    private:
};

#endif // T100ACTUATOR_H
