#ifndef T100WXFILEINFO_H
#define T100WXFILEINFO_H

#include "T100Common.h"

class T100WxFileInfo
{
    public:
        T100WxFileInfo();
        virtual ~T100WxFileInfo();

        T100STRING          m_filename;
        T100STRING          m_path;

    protected:

    private:
};

#endif // T100WXFILEINFO_H
