#ifndef T100FONTBUILDER_H
#define T100FONTBUILDER_H

#include <mutex>
#include <condition_variable>
#include "T100Common.h"

namespace T100FontBuilder{
class T100FontServe;
class T100FontView;


class T100FontBuilder
{
    public:
        T100FontBuilder();
        virtual ~T100FontBuilder();

        T100VOID                    setServe(T100FontServe*);
        T100FontServe*              getServe();

        T100VOID                    setView(T100FontView*);
        T100FontView*               getView();

        T100VOID                    show();
        T100VOID                    quit();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100FontServe*              m_serve         = T100NULL;
        T100FontView*               m_view          = T100NULL;

        std::mutex                  m_mutex;
        std::condition_variable     m_condition;

};

}

#endif // T100FONTBUILDER_H
