#ifndef T1003DEDITORDOCUMENT_H
#define T1003DEDITORDOCUMENT_H

#include "T100Common.h"
#include "link/T100Entity.h"
#include "link/T1003DLight.h"
#include "link/T1003DCamera.h"
#include "3d/T1003DFile3DF.h"
#include "3d/T1003DFileGLTF.h"

class T1003DEditorDocument
{
    friend class T1003DEditorStore;
    friend class T1003DEditorSkeletal;
    public:
        T1003DEditorDocument();
        virtual ~T1003DEditorDocument();

        T100VOID                    Append(T100Entity*);
        T100VOID                    Remove(T100Entity*);

        T100VOID                    Append(T1003DCamera*);
        T100VOID                    Remove(T1003DCamera*);

        T100VOID                    Append(T1003DLight*);
        T100VOID                    Remove(T1003DLight*);

        T100ENTITY_VECTOR&          GetEntities();
        T1003DCAMERA_VECTOR&        GetCameras();
        T1003DLIGHT_VECTOR&         GetLights();

        T100VOID                    Decode(T1003DFile3DF&);
        T100VOID                    Encode(T1003DFile3DF&);

        T100VOID                    Decode(T1003DFileGLTF&);
        T100VOID                    Encode(T1003DFileGLTF&);

    protected:
        T100WSTRING                 m_filename;

        T100ENTITY_VECTOR           m_entities;
        T1003DCAMERA_VECTOR         m_cameras;
        T1003DLIGHT_VECTOR          m_lights;

    private:
        T100VOID                    DecodeEntity(JSON&);

        T100VOID                    DecodeDot(JSON&);
        T100VOID                    DecodeLine(JSON&);
        T100VOID                    DecodeCity(JSON&);
        T100VOID                    DecodeTriangle(JSON&);
};

#endif // T1003DEDITORDOCUMENT_H
