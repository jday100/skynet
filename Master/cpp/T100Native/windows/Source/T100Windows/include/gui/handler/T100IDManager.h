#ifndef T100IDMANAGER_H
#define T100IDMANAGER_H

#include <atomic>
#include "base/T100Class.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100IDManager : public T100Class
{
    public:
        T100IDManager();
        virtual ~T100IDManager();

        T100INT                 Next();
        T100VOID                Get(T100UINT, T100INT&, T100INT&);

    protected:

    private:
        std::atomic_int         m_count;

        T100VOID                init();
        T100VOID                uninit();
};

}

#endif // T100IDMANAGER_H
