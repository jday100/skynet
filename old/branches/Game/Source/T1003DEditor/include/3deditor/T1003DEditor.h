#ifndef T1003DEDITOR_H
#define T1003DEDITOR_H

#include "T100Vector2u.h"
#include "T100Game.h"
#include "T100Entity.h"
#include "T1003DEditorScene.h"

class T1003DEditor
{
    public:
        T1003DEditor();
        virtual ~T1003DEditor();

        virtual T100VOID            Create(HWND, UINT, UINT);
        virtual T100VOID            SetSize(UINT, UINT);

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

        virtual T100VOID            Append(T100Entity*);

        virtual T100VOID            Render();

        virtual T100VOID            OnKeyDown(UINT8);
        virtual T100VOID            OnKeyUp(UINT8);

        virtual T100VOID            OnMouseMove(T100Vector2u);
        virtual T100VOID            OnLeftDown();

        virtual T100VOID            Clear();

    protected:
        UINT                        m_width;
        UINT                        m_height;
        T100Game                    m_game;
        T1003DEditorScene*          m_scene         = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T1003DEDITOR_H
