#ifndef T100PROJECTAPPLICATION_H
#define T100PROJECTAPPLICATION_H

#include "skeletal/T100ProjectSkeletal.h"
#include "gui/T100Win32Application.h"

using namespace T100WINDOWS;

class T100ProjectApplication : public T100Win32Application
{
    public:
        T100ProjectApplication();
        virtual ~T100ProjectApplication();

        virtual T100VOID            Create();
        virtual T100VOID            Destroy();

        T100ProjectSkeletal&        GetSkeletal();

        T100VOID                    OnMenu(T100MenuEvent&);
        T100VOID                    OnResize(T100WindowEvent&);


    protected:
        T100ProjectSkeletal         m_skeletal;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100PROJECTAPPLICATION_H
