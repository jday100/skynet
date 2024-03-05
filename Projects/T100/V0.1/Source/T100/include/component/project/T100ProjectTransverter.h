#ifndef T100PROJECTTRANSVERTER_H
#define T100PROJECTTRANSVERTER_H

#include "T100ProjectStateAlone.h"
#include "T100ProjectStateEmbed.h"

#include "T100StateTransverter.h"

namespace T100Component{

class T100ProjectTransverter : public T100StateTransverter
{
    public:
        T100ProjectTransverter();
        virtual ~T100ProjectTransverter();

        T100BOOL                                    Change(T100WORD);

        T100PROJECT::T100ProjectState*              GetCurrent();

    protected:
        T100PROJECT::T100ProjectState*              m_state         = T100NULL;

    private:
        T100PROJECT::T100ProjectStateAlone*         m_alone         = T100NULL;
        T100PROJECT::T100ProjectStateEmbed*         m_embed         = T100NULL;
};

}

#endif // T100PROJECTTRANSVERTER_H
