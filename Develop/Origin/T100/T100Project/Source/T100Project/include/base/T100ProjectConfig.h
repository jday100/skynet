#ifndef T100PROJECTCONFIG_H
#define T100PROJECTCONFIG_H

#include "T100Common.h"

class T100ProjectConfig
{
    public:
        T100ProjectConfig();
        virtual ~T100ProjectConfig();

        static const T100WSTRING        T100PROJECT_WORKSPACE_FILENAME;
        static const T100WSTRING        T100PROJECT_PROJECT_FILENAME;

        static const T100WSTRING        T100PROJECT_PROJECT_COMPILE_FILENAME;
        static const T100WSTRING        T100PROJECT_PROJECT_CREATE_FILENAME;

        static const T100WSTRING        T100PROJECT_EDITOR_FONT;

    protected:

    private:
};

#endif // T100PROJECTCONFIG_H
