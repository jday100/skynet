#ifndef T100DISKCTRL_H
#define T100DISKCTRL_H

#include <wx/menu.h>
#include <wx/dcclient.h>
#include <wx/control.h>
#include "T100Common.h"
#include "T100DiskCommon.h"


class T100DiskCtrl : public wxControl
{
    friend class T100FileSystemCtrl;
    friend class T100DiskBrowseCtrl;
    public:
        T100DiskCtrl(wxWindow* parent, wxWindowID id,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize, long style = 0,
                     const wxValidator& validator = wxDefaultValidator,
                     const wxString& name = wxControlNameStr);
        virtual ~T100DiskCtrl();

        T100BOOL                    Clear();

        T100BOOL                    Load(T100DISK_PART_CTRL_VECTOR&);

        T100BOOL                    Load(T100DISK_PART_VECTOR&);


        T100VOID                    SetLength(T100DWORD);
        T100DWORD                   GetLength();

        T100BOOL                    splitPart(T100DISK_PART_CTRL*, T100DISK_PART*, T100DISK_PART_CTRL*&, T100DISK_PART_CTRL*&, T100DISK_PART_CTRL*&);
        T100BOOL                    splitPart(T100DISK_PART_CTRL*, T100DISK_PART*, T100DISK_PART_CTRL*&, T100DISK_PART_CTRL*&);
        T100BOOL                    updatePart(T100DISK_PART_CTRL*, T100DISK_PART_CTRL*, T100DISK_PART_CTRL*);
        T100BOOL                    updatePart(T100DISK_PART_CTRL*, T100DISK_PART_CTRL*, T100DISK_PART_CTRL*, T100DISK_PART_CTRL*);

        T100BOOL                    createPart(T100DISK_PART*, T100DISK_PART_CTRL*&);
        T100BOOL                    resize(T100DISK_PART_CTRL*);

        T100BOOL                    CreatePart(T100DISK_PART_CTRL*, T100DISK_PART&);

        T100BOOL                    AppendPart(T100DISK_PART*);
        T100BOOL                    EditPart(T100DISK_PART*);
        T100BOOL                    RemovePart(T100DISK_PART*);

        T100DISK_PART_CTRL_VECTOR&  GetAllParts();

        T100BOOL                    FormatPart(T100DISK_PART*);
        T100BOOL                    BrowsePart(T100DISK_PART*);

        T100BOOL                    AppendPartCtrl(T100DISK_PART_CTRL*);
        T100BOOL                    RemovePartCtrl(T100DISK_PART_CTRL*);


    protected:
        virtual T100BOOL            OnMenuCreate(void* = T100NULL) = 0;
        virtual T100BOOL            OnMenuEdit(void* = T100NULL) = 0;
        virtual T100BOOL            OnMenuRemove(void* = T100NULL) = 0;

        virtual T100BOOL            OnMenuFormat(void* = T100NULL) = 0;

        virtual T100BOOL            OnMenuBrowse(void* = T100NULL) = 0;

        virtual T100BOOL            OnFolderCreate(void* = T100NULL) = 0;
        virtual T100BOOL            OnFolderRemove(void* = T100NULL) = 0;
        virtual T100BOOL            OnFileCopy(void* = T100NULL) = 0;
        virtual T100BOOL            OnFileRemove(void* = T100NULL) = 0;

        ///
        virtual T100BOOL            OnGetAllDrivers(wxArrayString&, wxArrayString&, wxArrayInt&) = 0;

    protected:
        virtual T100BOOL            DoGetAllParts(T100DISK_PART_CTRL_VECTOR&) = 0;
        virtual T100BOOL            DoGetAllItems(wxString, wxString, T100DISK_ITEM_VECTOR&) = 0;

        virtual T100BOOL            DoCreateDir() = 0;
        virtual T100BOOL            DoRemoveDir() = 0;
        virtual T100BOOL            DoCopyFile() = 0;
        virtual T100BOOL            DoRemoveFile() = 0;

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        T100BOOL                    init();

        wxMenu                      m_menu;

    private:
        static const long ID_PAINT;

        static const long ID_PART_CREATE;
        static const long ID_PART_EDIT;
        static const long ID_PART_REMOVE;
        static const long ID_PART_BROWSE;
        static const long ID_PART_FORMAT;

        void OnEraseBackground(wxEraseEvent& event);

        void OnPaint(wxPaintEvent& event);
        void OnMouse(wxMouseEvent& event);
        void OnSize(wxSizeEvent& event);

        void OnCreatePart(wxCommandEvent& event);
        void OnEditPart(wxCommandEvent& event);
        void OnRemovePart(wxCommandEvent& event);
        void OnBrowsePart(wxCommandEvent& event);
        void OnFormatPart(wxCommandEvent& event);

    private:
        T100INT                     m_current           = -1;

        T100BOOL                    ReSize();
        T100BOOL                    resize(T100WORD, T100WORD, T100DISK_PART_CTRL*);

        T100BOOL                    hasBoot(T100BOOL&);

        T100VOID                    DrawDisk(wxDC&);
        T100VOID                    DrawParts(wxDC&);
        T100VOID                    DrawPart(wxDC&, T100DISK_PART_CTRL*);

        T100INT                     Hit(T100WORD);

        T100VOID                    ShowMenu(T100WORD);
        T100VOID                    SetMenu(T100INT);

        T100DISK                    m_disk;

        T100DISK_PART_CTRL_VECTOR   m_parts;
        T100DWORD                   m_location          = 1;



        const wxBrush*              GetBrush(T100COLOUR_PRIMITIVE_TYPE);



};

#endif // T100DISKCTRL_H
