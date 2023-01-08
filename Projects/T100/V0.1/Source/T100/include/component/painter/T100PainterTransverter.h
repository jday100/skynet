#ifndef T100PAINTERTRANSVERTER_H
#define T100PAINTERTRANSVERTER_H

#include "T100StateAlone.h"
#include "T100StateEmbed.h"

#include "T100StateTransverter.h"

namespace T100Component{

class T100PainterTransverter : public T100StateTransverter
{
    public:
        T100PainterTransverter();
        virtual ~T100PainterTransverter();

        T100BOOL                Change(T100State*);

        T100BOOL                Change(T100WORD);

        T100Painter::T100PainterState*          GetCurrent();

    protected:
        T100Painter::T100PainterState*          m_state             = T100NULL;

    private:
        T100Painter::T100StateAlone*            m_alone             = T100NULL;
        T100Painter::T100StateEmbed*            m_embed             = T100NULL;

};

}

#endif // T100PAINTERTRANSVERTER_H
