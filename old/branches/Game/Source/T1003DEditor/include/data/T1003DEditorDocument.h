#ifndef T1003DEDITORDOCUMENT_H
#define T1003DEDITORDOCUMENT_H

#include "T100FileGLTF.h"

class T1003DEditorDocument
{
    friend class T1003DEditorServe;
    friend class T1003DEditorSkeletal;
    friend class T1003DEditorTaskReadFile;
    public:
        T1003DEditorDocument();
        virtual ~T1003DEditorDocument();

    protected:
        T100FileGLTF*           m_gltf          = T100NULL;
        T100WSTRING             m_filename;

    private:
};

#endif // T1003DEDITORDOCUMENT_H
