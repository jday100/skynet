#ifndef T100DIAGRAMINVOKING_H
#define T100DIAGRAMINVOKING_H

#include "T100Common.h"

class wxPoint;
class wxAuiPaneInfo;
class T100DiagramFrame;
class T100DiagramSkeletal;
class T100SourceImportInfo;

class T100DiagramInvoking
{
    public:
        T100DiagramInvoking();
        virtual ~T100DiagramInvoking();

        static T100VOID                         Init(T100DiagramFrame*);
        static T100VOID                         Uninit();

        static T100VOID                         OnFileCreate();
        static T100VOID                         OnFileOpen();
        static T100VOID                         OnFileClose();
        static T100VOID                         OnFileSave();
        static T100VOID                         OnFileSaveAs();
        static T100VOID                         OnFileQuit();

        static T100VOID                         OnEditUndo();
        static T100VOID                         OnEditRedo();
        static T100VOID                         OnEditCut();
        static T100VOID                         OnEditCopy();
        static T100VOID                         OnEditPaste();

        static T100VOID                         OnViewManager(T100BOOL);
        static T100VOID                         OnViewProperty(T100BOOL);

        static T100VOID                         OnSearchFind();

        static T100VOID                         OnDevelopImport();

        static T100VOID                         OnSetupConfig();

        static T100VOID                         OnHelpAbout();

        static T100VOID                         OnAuiPaneClose(wxAuiPaneInfo*);

        static T100VOID                         OnItemSelect(T100UINT);
        static T100VOID                         OnItemAppend();

        static T100VOID                         OnTieSelect(T100UINT);
        static T100VOID                         OnTieStart(wxPoint&);
        static T100VOID                         OnTieEnd(wxPoint&);

        static T100VOID                         OnSelect(T100INT, T100INT);
        static T100VOID                         OnModified();

        static T100VOID                         OnMouseDClick(T100INT, T100INT);

        static T100VOID                         OnCanvasState(T100STRING);
        static T100VOID                         OnCanvasPosition(T100STRING);

        static T100VOID                         OnSourceImport(T100SourceImportInfo*);

    protected:

    private:
        static T100DiagramSkeletal*             m_skeletal;
};

#endif // T100DIAGRAMINVOKING_H
