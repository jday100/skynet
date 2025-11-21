#ifndef T100INSTRUCTSETINTELI386_H
#define T100INSTRUCTSETINTELI386_H

#include "T100InstructSet.h"

class T100InstructActuator;

class T100InstructSetIntelI386 : public T100InstructSet
{
    public:
        T100InstructSetIntelI386(T100InstructActuator&);
        virtual ~T100InstructSetIntelI386();

        T100BOOL                        Load();

    protected:
        T100InstructActuator&           m_actuator;

    private:
};

#endif // T100INSTRUCTSETINTELI386_H
