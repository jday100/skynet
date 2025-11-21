#ifndef T1003DEDITORINPUT_H
#define T1003DEDITORINPUT_H

#include "T100Common.h"
#include "T100Vector3.h"

class T1003DEditorInput
{
    public:
        T1003DEditorInput();
        virtual ~T1003DEditorInput();

        static T100VOID         OnKeyDown(T100UINT);
        static T100VOID         OnKeyUp(T100UINT);

        static T100VOID         OnLeftDown(T100Vector3);
        static T100VOID         OnLeftUp(T100Vector3);

    protected:

    private:
};

#endif // T1003DEDITORINPUT_H
