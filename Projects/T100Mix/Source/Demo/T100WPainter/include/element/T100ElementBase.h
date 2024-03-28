#ifndef T100ELEMENTBASE_H
#define T100ELEMENTBASE_H

#include <vector>
#include <wx/dc.h>
#include "T100Common.h"

#define     T100WPAINTER_ELEMENT_VECTOR                 std::vector<T100ElementBase*>

class T100ElementBase
{
    public:
        T100ElementBase();
        virtual ~T100ElementBase();

        virtual T100BOOL            Draw(wxDC&) = 0;

    protected:

    private:
};

#endif // T100ELEMENTBASE_H
