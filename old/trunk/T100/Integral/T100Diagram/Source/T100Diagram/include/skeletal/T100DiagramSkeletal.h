#ifndef T100DIAGRAMSKELETAL_H
#define T100DIAGRAMSKELETAL_H

#include "T100DiagramSkeletalBase.h"

class wxAuiPaneInfo;
class T100DiagramFrame;
class T100SourceImportInfo;

class T100DiagramSkeletal : public T100DiagramSkeletalBase
{
    public:
        T100DiagramSkeletal();
        virtual ~T100DiagramSkeletal();

        virtual T100VOID            Create(T100DiagramFrame*);
        virtual T100VOID            Destroy();

        T100VOID                    OnFileCreate();
        T100VOID                    OnFileOpen();
        T100VOID                    OnFileClose();
        T100VOID                    OnFileSave();
        T100VOID                    OnFileSaveAs();
        T100VOID                    OnFileQuit();

        T100VOID                    OnEditUndo();
        T100VOID                    OnEditRedo();
        T100VOID                    OnEditCut();
        T100VOID                    OnEditCopy();
        T100VOID                    OnEditPaste();

        T100VOID                    OnViewManager(T100BOOL);
        T100VOID                    OnViewProperty(T100BOOL);

        T100VOID                    OnSearchFind();

        T100VOID                    OnDevelopImport();

        T100VOID                    OnSetupConfig();

        T100VOID                    OnHelpAbout();

        T100VOID                    OnAuiPaneClose(wxAuiPaneInfo*);

        T100VOID                    OnItemSelect(T100UINT);
        T100VOID                    OnItemAppend();

        T100VOID                    OnTieSelect(T100UINT);
        T100VOID                    OnTieStart(wxPoint&);
        T100VOID                    OnTieEnd(wxPoint&);

        T100VOID                    OnSelect(T100INT, T100INT);
        T100VOID                    OnModified();

        T100VOID                    OnMouseDClick(T100INT, T100INT);

        T100VOID                    OnCanvasState(T100STRING&);
        T100VOID                    OnCanvasPosition(T100STRING&);

        T100VOID                    OnSourceImport(T100SourceImportInfo*);

    protected:

    private:
};

#endif // T100DIAGRAMSKELETAL_H
