#ifndef T100UNZIP_H
#define T100UNZIP_H

#include <wx/wx.h>
#include "T100Common.h"

class T100Unzip
{
    public:
        T100Unzip();
        virtual ~T100Unzip();

        T100BOOL            Uncompress(const wxString&, const wxString&);

    protected:

    private:
};

#endif // T100UNZIP_H
