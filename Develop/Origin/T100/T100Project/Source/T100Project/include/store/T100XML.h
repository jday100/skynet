#ifndef T100XML_H
#define T100XML_H

#include <wx/xml/xml.h>
#include "T100Common.h"

class T100XML
{
    public:
        T100XML(const T100WSTRING&);
        virtual ~T100XML();

        T100VOID                SetPath(const T100WSTRING&);
        const T100WSTRING&      GetPath();

        T100BOOL                IsExists();

    protected:
        T100WSTRING             m_path;

    private:
};

#endif // T100XML_H
