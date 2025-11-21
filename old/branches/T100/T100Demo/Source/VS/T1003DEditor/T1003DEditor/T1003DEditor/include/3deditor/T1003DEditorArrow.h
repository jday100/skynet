#ifndef T1003DEDITORARROW_H
#define T1003DEDITORARROW_H

#include "entity/T100Line.h"

class T100GameScene;

class T1003DEditorArrow
{
    public:
        T1003DEditorArrow();
        virtual ~T1003DEditorArrow();

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
        T100Line*               m_line          = T100NULL;
        T100Line*               m_arrow1        = T100NULL;
        T100Line*               m_arrow2        = T100NULL;
        T100Line*               m_arrow3        = T100NULL;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T1003DEDITORARROW_H
