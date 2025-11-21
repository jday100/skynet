#ifndef T100LEAFSCANNER_H
#define T100LEAFSCANNER_H

#include <atomic>
#include "T100LeafState.h"
#include "T100LeafToken.h"
#include "base/T100Scanner.h"

namespace T100LIBRARY{

class T100LeafScanner : public T100Scanner
{
    public:
        T100LeafScanner();
        virtual ~T100LeafScanner();

        /*
        virtual T100BOOL            Read();
        virtual T100BOOL            Append();
        virtual T100BOOL            Clear();
        */

        virtual T100VOID            SetLoaded(T100BOOL);
        virtual T100BOOL            IsLoaded();

        virtual T100BOOL            Next(T100LeafState&, T100LeafToken&) = 0;

    protected:
        std::atomic_bool            m_loaded;

        virtual T100BOOL            Run() = 0;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100LEAFSCANNER_H
