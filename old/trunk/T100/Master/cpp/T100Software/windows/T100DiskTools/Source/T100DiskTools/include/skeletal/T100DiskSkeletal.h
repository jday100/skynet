#ifndef T100DISKSKELETAL_H
#define T100DISKSKELETAL_H

#include "T100Common.h"
#include "T100DiskView.h"
#include "T100DiskServe.h"
#include "T100DiskStore.h"

class T100DiskApp;

using namespace T100LIBRARY;

class T100DiskSkeletal
{
    public:
        T100DiskSkeletal();
        virtual ~T100DiskSkeletal();

        virtual T100VOID            Create(T100DiskApp*);
        virtual T100VOID            Destroy();

    protected:
        T100DiskView                m_view;
        T100DiskServe               m_serve;
        T100DiskStore               m_store;

    private:
};

#endif // T100DISKSKELETAL_H
