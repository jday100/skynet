#ifndef T1003DGAME_H
#define T1003DGAME_H

#include <windows.h>
#include "T100Common.h"
#include "T100Scene.h"
#include "T100Character.h"
#include "graph/render/dx12/T100DX12Renderer.h"
#include "windows/gui/T100ApplicationWindow.h"

class T1003DGame
{
    public:
        T1003DGame(HINSTANCE, HINSTANCE, LPSTR, int);
        virtual ~T1003DGame();

        virtual T100BOOL                create(T100WORD, T100WORD, T100WString);
        virtual T100BOOL                destroy();

        virtual T100BOOL                load();
        virtual T100BOOL                release();

        virtual T100BOOL                show();
        virtual T100INT                 run();

        T100VOID                        setScene(T100Scene*);
        T100Scene*                      getScene();

        T100VOID                        setCharacter(T100Character*);
        T100Character*                  getCharacter();

    protected:
        T100ApplicationWindow*          m_frame             = T100NULL;
        T100DX12Renderer*               m_renderer          = T100NULL;
        T100Scene*                      m_scene             = T100NULL;
        T100Character*                  m_character         = T100NULL;

        static LRESULT CALLBACK         GameWindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

        T100BOOL                        render();

    private:
        T100VOID                        init(HINSTANCE, HINSTANCE, LPSTR, int);
        T100VOID                        uninit();

        T100BOOL                        load_scene();
        T100BOOL                        load_character();

};

#endif // T1003DGAME_H
