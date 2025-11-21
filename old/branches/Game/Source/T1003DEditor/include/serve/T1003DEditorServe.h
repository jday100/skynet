#ifndef T1003DEDITORSERVE_H
#define T1003DEDITORSERVE_H

#include "T100Common.h"
#include "T1003DEditorDocument.h"

class T1003DEditorServe
{
    public:
        T1003DEditorServe();
        virtual ~T1003DEditorServe();

        T100BOOL                    Open(T1003DEditorDocument&);

        T1003DEditorDocument&       GetDocument();

    protected:

    private:
};

#endif // T1003DEDITORSERVE_H
