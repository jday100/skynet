#ifndef T100EDITORDOCUMENT_H
#define T100EDITORDOCUMENT_H

#include "T100Common.h"

class T100EditorDocument
{
    public:
        T100EditorDocument();
        virtual ~T100EditorDocument();

        T100VOID                setFileName(T100WString&);
        T100WString&            getFileName();

        T100VOID                setExtension(T100WString&);
        T100WString&            getExtension();

        T100VOID                setPath(T100WString&);
        T100WString&            getPath();

    protected:

    private:
        T100WString             m_filename;
        T100WString             m_extension;
        T100WString             m_path;
};

#endif // T100EDITORDOCUMENT_H
