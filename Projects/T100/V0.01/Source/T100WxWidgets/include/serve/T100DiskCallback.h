#ifndef T100DISKCALLBACK_H
#define T100DISKCALLBACK_H

#include "T100Common.h"
class T100DiskServe;
class T100DiskView;


class T100DiskCallback
{
    public:
        T100DiskCallback();
        virtual ~T100DiskCallback();

        static T100BOOL                 init(T100DiskServe*, T100DiskView*);


    protected:

    private:
        static T100DiskServe*           m_serve;
        static T100DiskView*            m_view;

};

#endif // T100DISKCALLBACK_H
