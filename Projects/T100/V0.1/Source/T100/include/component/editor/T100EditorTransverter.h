#ifndef T100EDITORTRANSVERTER_H
#define T100EDITORTRANSVERTER_H

#include "T100EditorState.h"
#include "T100StateTransverter.h"

namespace T100Editor{

class T100EditorTransverter : public T100Component::T100StateTransverter
{
    public:
        T100EditorTransverter();
        virtual ~T100EditorTransverter();

        T100EditorState*            GetCurrent();

    protected:

    private:
};

}

#endif // T100EDITORTRANSVERTER_H
