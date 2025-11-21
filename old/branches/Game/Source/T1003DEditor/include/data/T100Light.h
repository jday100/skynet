#ifndef T100LIGHT_H
#define T100LIGHT_H

#include <vector>
#include "T100Common.h"
#include "common/T100EntityCommon.h"
#include "math/T100Vector3.h"

#include "entity/T100Editable.h"

class T100DX12Light;

#define     T100LIGHT_VECTOR            std::vector<T100Light*>

class T100Light : public T100Editable
{
    friend class T100DX12LightManager;
    public:
        T100Light();
        virtual ~T100Light();

        static T100ENTITY_TYPE      Type;
        static T100WSTRING          Name;

        T100_LIGHT_TYPE             LightType;

        /*
        T100VOID                    SetPosition(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetPosition(T100Vector3);
        T100Vector3                 GetPosition();
        */

        T100VOID                    SetDirection(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetDirection(T100Vector3);
        T100Vector3                 GetDirection();

        virtual T100VOID            Load(T100DX12Scene*);
        virtual T100DX12Model*      Convert(T100DX12Studio*);

        virtual T100VOID            ToJSON(JSON&);
        virtual T100VOID            FromJSON(JSON&);

    protected:
        T100DX12Light*              m_light         = T100NULL;

        //T100Vector3                 m_position;
        T100Vector3                 m_direction;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100LIGHT_H
