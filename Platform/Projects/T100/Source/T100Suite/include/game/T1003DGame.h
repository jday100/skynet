#ifndef T1003DGAME_H
#define T1003DGAME_H

#include "T100Common.h"
#include "graph/render/T100Renderer.h"

class T1003DGame
{
    public:
        T1003DGame();
        virtual ~T1003DGame();

        virtual T100BOOL        run();

    protected:
        T100Renderer            m_renderer;

        T100BOOL                show_lobby();

    private:
        T100VOID                create();
        T100VOID                destroy();

};

#endif // T1003DGAME_H
