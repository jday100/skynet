#ifndef T1003DGAME_H
#define T1003DGAME_H

#include <windows.h>
#include "T100Common.h"
#include "graph/render/T100Renderer.h"
#include "windows/gui/T100ApplicationWindow.h"

class T1003DGame
{
    public:
        T1003DGame(HINSTANCE, HINSTANCE, LPSTR, int);
        virtual ~T1003DGame();

        virtual T100BOOL                create(T100WORD, T100WORD, T100WString);
        virtual T100BOOL                destroy();

        virtual T100BOOL                show();
        virtual T100INT                 run();

    protected:
        T100ApplicationWindow*          m_frame             = T100NULL;

    private:
        T100VOID                        init(HINSTANCE, HINSTANCE, LPSTR, int);
        T100VOID                        uninit();

};

#endif // T1003DGAME_H
