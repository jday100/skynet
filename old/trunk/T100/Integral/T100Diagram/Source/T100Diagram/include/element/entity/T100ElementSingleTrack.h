#ifndef T100ELEMENTSINGLETRACK_H
#define T100ELEMENTSINGLETRACK_H

#include "T100ElementBase.h"

class T100ElementSingleTrack : public T100ElementBase
{
    friend class T100ElementSingleTrackSource;
    public:
        T100ElementSingleTrack();
        virtual ~T100ElementSingleTrack();

        T100BOOL            Draw(wxDC&);
        T100BOOL            Hit(T100INT, T100INT);
        T100BOOL            Edit(wxWindow*);

        T100BOOL            Cross(T100UINT, T100UINT, T100UINT&, T100UINT&);

        T100VOID            Resize(wxDC&);

        T100VOID            SetStart(T100ElementBase*);
        T100ElementBase*    GetStart();

        T100VOID            SetEnd(T100ElementBase*);
        T100ElementBase*    GetEnd();

        T100VOID            SetStartIndex(T100UINT);
        T100UINT            GetStartIndex();

        T100VOID            SetEndIndex(T100UINT);
        T100UINT            GetEndIndex();

    protected:
        T100ElementBase*    m_start         = T100NULL;
        T100ElementBase*    m_end           = T100NULL;

        T100UINT            m_startIndex    = 0;
        T100UINT            m_endIndex      = 0;

    private:
};

#endif // T100ELEMENTSINGLETRACK_H
