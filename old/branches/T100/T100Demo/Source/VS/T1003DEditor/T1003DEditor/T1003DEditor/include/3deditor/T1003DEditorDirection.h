#ifndef T1003DEDITORDIRECTION_H
#define T1003DEDITORDIRECTION_H

#include "T1003DEditorArrow.h"

class T100GameScene;

class T1003DEditorDirection
{
    public:
        T1003DEditorDirection();
        virtual ~T1003DEditorDirection();

        T100VOID                Load(T100GameScene*);

        T100VOID                SetPosition(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                SetPosition(T100Vector3f&);
        T100Vector3f&           GetPosition();

        T100VOID                SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                SetRotation(T100Vector3f&);
        T100Vector3f&           GetRotation();

        T100VOID                SetScaling(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                SetScaling(T100Vector3f&);
        T100Vector3f&           GetScaling();

        T100VOID                SetColour(T100UINT8, T100UINT8, T100UINT8, T100UINT8 = 0);
        T100Vector4u&           GetColour();

        T100VOID                SetVisible(T100BOOL);
        T100BOOL                IsVisible();

        T100VOID                SetLength(T100FLOAT);
        T100FLOAT               GetLength();

    protected:
        T1003DEditorArrow       m_arrowX;
        T1003DEditorArrow       m_arrowY;
        T1003DEditorArrow       m_arrowZ;

    private:
};

#endif // T1003DEDITORDIRECTION_H
