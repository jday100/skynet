#ifndef T100ELEMENTBASE_H
#define T100ELEMENTBASE_H

#include <vector>
#include <unordered_map>
#include <wx/dc.h>
#include "T100Common.h"
#include "T100DiagramCommon.h"

#define     T100DIAGRAM_ELEMENT_VECTOR          std::vector<T100ElementBase*>
#define     T100DIAGRAM_ELEMENT_HASH            std::unordered_map<T100WSTRING, T100ElementBase*>
#define     T100DIAGRAM_ELEMENT_INDEX_HASH      std::unordered_map<T100UINT, T100ElementBase*>

class wxWindow;

class T100ElementBase
{
    friend class T100ElementSource;
    public:
        T100ElementBase();
        virtual ~T100ElementBase();

        T100VOID                    SetName(T100WSTRING);
        T100WSTRING&                GetName();
        T100UINT                    GetType();

        T100VOID                    SetOriginX(T100UINT);
        T100UINT                    GetOriginX();

        T100VOID                    SetOriginY(T100UINT);
        T100UINT                    GetOriginY();

        T100VOID                    SetCentroidX(T100UINT);
        T100UINT                    GetCentroidX();

        T100VOID                    SetCentroidY(T100UINT);
        T100UINT                    GetCentroidY();

        T100VOID                    SetIndex(T100UINT);
        T100UINT                    GetIndex();

        virtual T100BOOL            Draw(wxDC&) = 0;
        virtual T100BOOL            Hit(T100INT, T100INT) = 0;
        virtual T100BOOL            Edit(wxWindow*) = 0;

        virtual T100BOOL            Cross(T100UINT, T100UINT, T100UINT&, T100UINT&) = 0;

        virtual T100VOID            Move(T100UINT, T100UINT);

    protected:
        T100WSTRING                 m_name;
        T100UINT                    m_type      = 0;

        T100UINT                    m_originX   = 0;
        T100UINT                    m_originY   = 0;

        T100UINT                    m_centroidX = 0;
        T100UINT                    m_centroidY = 0;

        T100UINT                    m_index     = 0;

        T100BOOL                    CrossPoint(T100UINT, T100UINT, T100UINT, T100UINT,
                                          T100UINT, T100UINT, T100UINT, T100UINT,
                                          T100UINT&, T100UINT&);

        T100BOOL                    OnLine(T100UINT, T100UINT, T100UINT, T100UINT,
                                          T100UINT, T100UINT, T100UINT, T100UINT,
                                          T100UINT&, T100UINT&);

        T100BOOL                    Arrow(T100UINT, T100UINT, T100UINT, T100UINT,
                                          T100UINT&, T100UINT&, T100UINT&, T100UINT&,
                                          T100UINT&, T100UINT&);

    private:
};

#endif // T100ELEMENTBASE_H
