#ifndef T100FOLDERTOOLS_H
#define T100FOLDERTOOLS_H

#include "base/T100Class.h"

namespace T100LIBRARY{

class T100FolderTools : public T100Class
{
    public:
        T100FolderTools();
        virtual ~T100FolderTools();

        static T100INT          GetAllFiles(const T100WSTRING&, T100WSTRING_VECTOR&, const T100WSTRING&, T100INT);

    protected:

    private:
};

}

#endif // T100FOLDERTOOLS_H
