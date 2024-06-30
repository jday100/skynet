#ifndef T100RENDERBASE_H
#define T100RENDERBASE_H

#include "T100Common.h"
#include "T100Entity.h"
#include "T100Light.h"
#include "T100Camera.h"
#include "T100Point.h"

class T100RenderBase
{
    public:
        T100RenderBase();
        virtual ~T100RenderBase();

        virtual T100BYTE*                   GetData() = 0;

        virtual T100VOID                    Start() = 0;
        virtual T100VOID                    Stop() = 0;

        virtual T100VOID                    Draw() = 0;

        virtual T100VOID                    SetSize(T100INT, T100INT) = 0;

        virtual T100INT                     GetWidth() = 0;
        virtual T100INT                     GetHeight() = 0;

        virtual T100ENTITY_VECTOR&          GetEntities() = 0;
        virtual T100LIGHT_VECTOR&           GetLights() = 0;
        virtual T100CAMERA_VECTOR&          GetCameras() = 0;

        virtual T100VOID                    SetOrigin(T100FLOAT, T100FLOAT, T100FLOAT);

    public:
        virtual T100VOID                    Move(T100FLOAT, T100FLOAT, T100FLOAT) = 0;
        virtual T100VOID                    Rotate(T100FLOAT, T100FLOAT, T100FLOAT) = 0;

        virtual T100VOID                    Pyramid() = 0;

    protected:
        T100INT                             m_view_width        = 0;
        T100INT                             m_view_height       = 0;
        T100INT                             m_view_origin_x     = 0;
        T100INT                             m_view_origin_y     = 0;
        T100Point                           m_origin;

    private:
};

#endif // T100RENDERBASE_H
