#ifndef T100TESTNODE_H
#define T100TESTNODE_H

#include "test/T100TestNodeBase.h"

class T100TestNode : public T100TestNodeBase
{
    public:
        T100TestNode(T100WSTRING, T100TestNode*);
        virtual ~T100TestNode();

        virtual T100RESULT          TestAll();

        virtual T100VOID            ShowResult(T100RESULT, T100WSTRING&);

    protected:

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100TESTNODE_H
