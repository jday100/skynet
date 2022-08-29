#ifndef T100EDITORMENUNEW_H
#define T100EDITORMENUNEW_H

#include "T100Common.h"
class T100IDEServe;
class T100IDEView;


class T100EditorMenuNew
{
    public:
        T100EditorMenuNew();
        virtual ~T100EditorMenuNew();

        static T100BOOL         run(T100IDEServe*, T100IDEView*);

    protected:

    private:
};

#endif // T100EDITORMENUNEW_H
