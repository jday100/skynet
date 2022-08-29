#ifndef T100IDEPROJECTDATA_H
#define T100IDEPROJECTDATA_H

#include "T100Common.h"


#define T100IDE_PROJECT_VECTOR      std::vector<T100IDEProjectData*>


class T100IDEProjectData
{
    public:
        T100IDEProjectData();
        virtual ~T100IDEProjectData();

        T100String          m_folder;

    protected:

    private:
};

#endif // T100IDEPROJECTDATA_H
