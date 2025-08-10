#ifndef T100XML_H
#define T100XML_H

#include <wx/xml/xml.h>
#include "T100Common.h"

class T100XML
{
    public:
        T100XML(const T100WSTRING&);
        virtual ~T100XML();

    protected:
        T100WSTRING         m_filename;

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100XML_H
