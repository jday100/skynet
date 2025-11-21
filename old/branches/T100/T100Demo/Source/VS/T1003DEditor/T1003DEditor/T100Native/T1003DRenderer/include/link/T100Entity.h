#ifndef T100ENTITY_H
#define T100ENTITY_H

#include <vector>
#include "T100Common.h"
#include "T1003DCommon.h"
#include "vector/T100Vector4u.h"
#include "link/T1003DMesh.h"
#include "json/json.hpp"

#define     T100ENTITY_VECTOR           std::vector<T100Entity*>

using JSON = nlohmann::json;

class T100Entity : public T1003DMesh
{
    public:
        T100Entity();
        virtual ~T100Entity();

        T100VOID                    SetColour(T100UINT8, T100UINT8, T100UINT8, T100UINT8);
        T100VOID                    SetColour(T100Vector4u&);
        T100Vector4u&               GetColour();

        virtual T100VOID            ToJSON(JSON&) = 0;
        virtual T100VOID            FromJSON(JSON&) = 0;

    protected:
        T100Vector4u                m_colour;

    private:
};

#endif // T100ENTITY_H
