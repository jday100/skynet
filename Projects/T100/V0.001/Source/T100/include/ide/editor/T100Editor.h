#ifndef T100EDITOR_H
#define T100EDITOR_H

#include "T100Common.h"


class T100Editor
{
    public:
        T100Editor();
        virtual ~T100Editor();

        T100BOOL            load(T100STDSTRING);
        T100BOOL            save();

    protected:

    private:
        T100String          m_file;

};

#endif // T100EDITOR_H
