#ifndef T100WORKSPACEFILE_H
#define T100WORKSPACEFILE_H

#include "T100XML.h"
#include "T100WorkSpaceInfo.h"

class T100WorkSpaceFile : public T100XML
{
    public:
        T100WorkSpaceFile(const T100WSTRING&);
        virtual ~T100WorkSpaceFile();

        T100BOOL            Load(T100WorkSpaceInfo*);
        T100BOOL            Save(T100WorkSpaceInfo*);

    protected:

    private:
};

#endif // T100WORKSPACEFILE_H
