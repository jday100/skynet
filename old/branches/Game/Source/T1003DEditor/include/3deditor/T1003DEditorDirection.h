#ifndef T1003DEDITORDIRECTION_H
#define T1003DEDITORDIRECTION_H

#include "T1003DEditorArrow.h"

class T1003DEditorScene;

class T1003DEditorDirection
{
    public:
        T1003DEditorDirection();
        virtual ~T1003DEditorDirection();

        T100VOID                    Load(T100DX12Scene*);

        T100VOID                    SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetRotation(T100Vector3);

        T100VOID                    SetLength(T100FLOAT);
        T100VOID                    SetColour(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetColour(T100Vector4u);

        T100VOID                    SetPosition(T100UINT, T100UINT);

    protected:
        T100ARROW_VECTOR            m_arrows;
        T1003DEditorArrow*          m_arrowX        = T100NULL;
        T1003DEditorArrow*          m_arrowY        = T100NULL;
        T1003DEditorArrow*          m_arrowZ        = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T1003DEDITORDIRECTION_H
