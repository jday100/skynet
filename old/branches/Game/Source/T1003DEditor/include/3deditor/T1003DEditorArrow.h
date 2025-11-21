#ifndef T1003DEDITORARROW_H
#define T1003DEDITORARROW_H

#include "entity/T100Line.h"

#define     T100ARROW_VECTOR            std::vector<T1003DEditorArrow*>

class T1003DEditorScene;

class T1003DEditorArrow
{
    public:
        T1003DEditorArrow();
        virtual ~T1003DEditorArrow();

        T100VOID                    Load(T100DX12Scene*);

        T100VOID                    SetPosition(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetPosition(T100Vector3);

        T100VOID                    SetLength(T100FLOAT);
        T100VOID                    SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetRotation(T100Vector3);

        T100VOID                    SetColour(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetColour(T100Vector4u);

    protected:
        T100ENTITY_VECTOR           m_entities;
        T100Line*                   line            = T100NULL;
        T100Line*                   line1           = T100NULL;
        T100Line*                   line2           = T100NULL;
        T100Line*                   line3           = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T1003DEDITORARROW_H
