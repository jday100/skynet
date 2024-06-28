#ifndef T100RENDER_H
#define T100RENDER_H

#include "T100Common.h"
#include "T100RenderBase.h"
#include "T100ViewBase.h"
#include "T100Entity.h"

class T100Render
{
    public:
        T100Render();
        virtual ~T100Render();

        T100VOID                    Draw(T100VOID*);
        T100VOID                    SetSize(T100INT, T100INT);
        T100BYTE*                   GetData();
        T100INT                     GetWidth();
        T100INT                     GetHeight();

        T100ENTITY_VECTOR&          GetEntities();

        T100VOID                    Move(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    Rotate(T100FLOAT, T100FLOAT, T100FLOAT);

    public:
        T100VOID                    SetView(T100ViewBase*);
        T100ViewBase*               GetView();

        T100VOID                    SetOrigin(T100FLOAT, T100FLOAT, T100FLOAT);

    public:
        T100VOID                    project(T100INT, T100INT, T100FLOAT&, T100FLOAT&, T100FLOAT&);

    protected:
        T100RenderBase*             m_render            = T100NULL;
        T100ViewBase*               m_view              = T100NULL;

    private:
        T100VOID                    TurnOn();
        T100VOID                    TurnOff();
};

#endif // T100RENDER_H
