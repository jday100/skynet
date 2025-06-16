#ifndef T100EDITOR_H
#define T100EDITOR_H

#include "base/T100Class.h"

class T100TextCtrl;
class T100EditorFrame;

class T100Editor : public T100Class
{
    public:
        T100Editor();
        virtual ~T100Editor();

        T100VOID                SetFrame(T100EditorFrame*);

        T100VOID                New();
        T100VOID                Open();
        T100VOID                Close();
        T100VOID                Save();
        T100VOID                SaveAs();
        T100VOID                Quit();

        T100VOID                Undo();
        T100VOID                Redo();
        T100VOID                Cut();
        T100VOID                Copy();
        T100VOID                Paste();

        T100VOID                Font();

        T100VOID                Find();
        T100VOID                Replace();

        T100VOID                Config();

        T100VOID                About();

    protected:

    private:
        T100EditorFrame*        m_frame         = T100NULL;
        T100TextCtrl*           m_textCtrl      = T100NULL;
        T100WSTRING             m_filename;
};

#endif // T100EDITOR_H
