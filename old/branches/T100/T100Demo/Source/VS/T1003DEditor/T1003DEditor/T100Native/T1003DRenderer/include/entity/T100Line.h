#ifndef T100LINE_H
#define T100LINE_H

#include "link/T100Entity.h"

class T100Line : public T100Entity
{
    public:
        T100Line();
        virtual ~T100Line();

        static T100WSTRING          Name;
        static T100UINT             Type;

        virtual T100VOID            Load();

        T100VOID                    SetLength(T100FLOAT);
        T100FLOAT                   GetLength();

        T100VOID                    SetTerminus(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetTerminus(T100Vector3f);
        T100Vector3f                GetTerminus();

        T100VOID                    SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetRotation(T100Vector3f&);

        virtual T100VOID            ToJSON(JSON&);
        virtual T100VOID            FromJSON(JSON&);

    protected:
        T100FLOAT                   m_length            = 0.0f;
        T100Vector3f                m_terminus;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100LINE_H
