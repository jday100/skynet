#include "T100PainterInvoking.h"

#include "T100Painter.h"

T100Painter*        T100PainterInvoking::m_painterPtr           = T100NULL;

T100PainterInvoking::T100PainterInvoking()
{
    //ctor
}

T100PainterInvoking::~T100PainterInvoking()
{
    //dtor
}

T100VOID T100PainterInvoking::Create(T100Painter* painter)
{
    m_painterPtr    = painter;
}

T100VOID T100PainterInvoking::Destroy()
{
    T100SAFE_DELETE m_painterPtr;
}

T100VOID T100PainterInvoking::MenuNew()
{
    m_painterPtr->New();
}

T100VOID T100PainterInvoking::MenuQuit()
{
    m_painterPtr->Quit();
}

T100VOID T100PainterInvoking::FrameResize()
{
    m_painterPtr->Resize();

}

T100VOID T100PainterInvoking::EntitySelected(T100WORD index)
{
    m_painterPtr->Select(index);
}

T100VOID T100PainterInvoking::LeftDown()
{

}

T100VOID T100PainterInvoking::LeftUp()
{

}
