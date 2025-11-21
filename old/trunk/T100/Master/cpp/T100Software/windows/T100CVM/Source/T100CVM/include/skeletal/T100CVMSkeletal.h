#ifndef T100CVMSKELETAL_H
#define T100CVMSKELETAL_H

#include "T100CVMView.h"
#include "T100CVMServe.h"
#include "T100CVMStore.h"

class T100CVMApp;

class T100CVMSkeletal
{
    public:
        T100CVMSkeletal();
        virtual ~T100CVMSkeletal();

        virtual T100VOID        Create(T100CVMApp*);
        virtual T100VOID        Destroy();

        T100VOID                Start();
        T100VOID                Stop();

    protected:
        T100CVMView             m_view;
        T100CVMServe            m_serve;
        T100CVMStore            m_store;

    private:
};

#endif // T100CVMSKELETAL_H
