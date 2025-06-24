#ifndef T100FONT_H
#define T100FONT_H

#include "gui/font/T100FontBase.h"

namespace T100WINDOWS{

class T100Font : public T100FontBase
{
    public:
        T100Font();
        T100Font(const T100WSTRING&);
        virtual ~T100Font();

        virtual T100VOID            Create(const T100WSTRING&);
        virtual T100VOID            Destroy();

        const T100Font& operator=(const T100Font&);

    protected:


    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100FONT_H
