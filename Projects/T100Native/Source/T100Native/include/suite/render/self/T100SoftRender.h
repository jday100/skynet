#ifndef T100SOFTRENDER_H
#define T100SOFTRENDER_H

#include "T100Matrix4.h"
#include "T100Entity.h"
#include "T100RenderBase.h"
#include "T100SoftSpace.h"


class T100SoftRender : public T100RenderBase
{
    public:
        T100SoftRender();
        virtual ~T100SoftRender();

        T100VOID                    Start();
        T100VOID                    Stop();

        T100VOID                    Draw();
        T100VOID                    DrawPoint(T100Point&, T100INT);

        T100VOID                    Rotate(T100Point&, T100Matrix4&, T100Point&);

        T100VOID                    SetSize(T100INT, T100INT);

        T100BYTE*                   GetData();
        T100INT                     GetWidth();
        T100INT                     GetHeight();

        T100ENTITY_VECTOR&          GetEntities();
        T100LIGHT_VECTOR&           GetLights();
        T100CAMERA_VECTOR&          GetCameras();

    public:
        T100VOID                    Move(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    Rotate(T100FLOAT, T100FLOAT, T100FLOAT);

        T100VOID                    Pyramid();

    protected:
        T100SoftSpace               m_space;

        T100INT                     m_length            = 0;

        T100BYTE*                   m_screen            = T100NULL;

    private:
        T100ENTITY_VECTOR           m_entities;
        T100LIGHT_VECTOR            m_lights;
        T100CAMERA_VECTOR           m_cameras;
};

#endif // T100SOFTRENDER_H
