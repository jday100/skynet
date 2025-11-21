#ifndef T100ZIP_H
#define T100ZIP_H

#include <wx/wx.h>
#include "T100Common.h"

class T100Zip
{
    public:
        T100Zip();
        virtual ~T100Zip();

        T100BOOL            Compress(const wxArrayString&, const wxString&);

    protected:

    private:
};

#endif // T100ZIP_H
