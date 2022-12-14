#ifndef T100PARTSCANNER_H
#define T100PARTSCANNER_H

#include "T100AssemblyCommon.h"
#include "T100PartToken.h"
#include "T100SegmentScanner.h"

namespace T100Assembly{

class T100PartScanner : public T100Component::T100Scanner
{
    public:
        T100PartScanner();
        virtual ~T100PartScanner();

        T100VOID                    setSource(T100Component::T100Scanner*);
        T100Component::T100Scanner*                getSource();

        T100BOOL                    next(T100Component::T100Token&);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        T100PartToken*              m_token             = T100NULL;
        T100SegmentToken            m_item;

        T100PartToken*              getToken();
        T100SegmentToken*           getItem();

        T100BOOL                    run();
        T100BOOL                    append();
        T100BOOL                    read();

        T100STRING                  getFile();

    private:
        static T100TOKEN_TYPE       m_type;
        T100SegmentScanner*         m_scanner           = T100NULL;

};

}

#endif // T100PARTSCANNER_H
