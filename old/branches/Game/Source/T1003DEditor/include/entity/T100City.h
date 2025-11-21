#ifndef T100CITY_H
#define T100CITY_H

#include "T100Editable.h"

class T100City : public T100Editable
{
    friend class T100DX12Line;
    public:
        T100City();
        virtual ~T100City();

        static T100WSTRING              Name;
        static T100ENTITY_TYPE          Type;

        virtual T100VOID                ToJSON(JSON&);
        virtual T100VOID                FromJSON(JSON&);

        T100VOID                        Load(T100DX12Scene*);
        T100DX12Model*                  Convert(T100DX12Studio*);

        static const T100UINT           CityRowCount = 15;
        static const T100UINT           CityColumnCount = 8;
        static const T100UINT           CityMaterialCount = CityRowCount * CityColumnCount;
        static const T100UINT           CityMaterialTextureWidth = 64;
        static const T100UINT           CityMaterialTextureHeight = 64;
        static const T100UINT           CityMaterialTextureChannelCount = 4;

        T100WSTRING                     MeshDataFile;

    protected:

    private:
        T100VOID                        init();
        T100VOID                        uninit();
};

#endif // T100CITY_H
