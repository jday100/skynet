#ifndef T1003DEDITORGLTFDECODER_H
#define T1003DEDITORGLTFDECODER_H

#include "T100Entity.h"
#include "T100FileGLTF.h"

class T1003DEditorGLTFDecoder
{
    public:
        T1003DEditorGLTFDecoder();
        virtual ~T1003DEditorGLTFDecoder();

        T100VOID            Decode(T100FileGLTF*, T100ENTITY_VECTOR&);

    protected:
        T100VOID            DecodeMaterials(T100FileGLTF*, T100ENTITY_VECTOR&);

    private:
};

#endif // T1003DEDITORGLTFDECODER_H
