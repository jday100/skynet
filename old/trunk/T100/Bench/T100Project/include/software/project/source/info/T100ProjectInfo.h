#ifndef T100PROJECTINFO_H
#define T100PROJECTINFO_H

#include "T100Project.h"

class T100ProjectInfo
{
    public:
        T100ProjectInfo();
        virtual ~T100ProjectInfo();

        virtual T100VOID                    SetProjectData(const T100Project&);
        virtual const T100Project&          GetProjectData();

    protected:
        T100Project                         m_projectData;

    private:
};

#endif // T100PROJECTINFO_H
