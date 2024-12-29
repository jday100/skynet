#ifndef T100EDITORDOCUMENT_H
#define T100EDITORDOCUMENT_H

#include "T100Common.h"

class T100EditorDocument
{
    public:
        T100EditorDocument();
        virtual ~T100EditorDocument();

    protected:

    private:
        T100WString             m_filename;
        T100WString             m_extension;
        T100WString             m_path;
};

#endif // T100EDITORDOCUMENT_H
