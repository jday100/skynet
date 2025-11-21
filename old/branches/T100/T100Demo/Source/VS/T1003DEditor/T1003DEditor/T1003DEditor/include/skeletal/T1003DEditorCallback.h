#ifndef T1003DEDITORCALLBACK_H
#define T1003DEDITORCALLBACK_H

#include "T100Common.h"

class T100Entity;
class T1003DCamera;
class T1003DLight;
class T1003DEditorFrame;
class T1003DEditorSkeletal;

class T1003DEditorCallback
{
    public:
        T1003DEditorCallback();
        virtual ~T1003DEditorCallback();

        static T100VOID             Create(T1003DEditorFrame*);
        static T100VOID             Destroy();

        static T100VOID             MenuNew();
        static T100VOID             MenuOpen();
        static T100VOID             MenuClose();
        static T100VOID             MenuSave();
        static T100VOID             MenuSaveAs();
        static T100VOID             MenuImport();
        static T100VOID             MenuExport();
        static T100VOID             MenuQuit();

        static T100VOID             MenuUndo();
        static T100VOID             MenuRedo();

        static T100VOID             MenuCut();
        static T100VOID             MenuCopy();
        static T100VOID             MenuPaste();

        static T100VOID             SetMenu(T100WSTRING, T100BOOL);
        static T100VOID             MenuManager(T100BOOL);
        static T100VOID             MenuProperties(T100BOOL);

        static T100VOID             MenuConfig();

        static T100VOID             MenuAbout();

        static T100VOID             OnKeyDown(T100INT);
        static T100VOID             OnKeyUp(T100INT);

        static T100VOID             Update(T100INT);
        static T100VOID             Update(T100Entity*);
        static T100VOID             Update(T1003DCamera*);
        static T100VOID             Update(T1003DLight*);

        static T100VOID             UpdateInfo();

        static T100VOID             SetBundle(T100BOOL, T100Entity*);

        static T100VOID             Append();
        static T100VOID             Remove();
        static T100VOID             Append(T100Entity*);
        static T100VOID             Remove(T100Entity*);
        static T100VOID             Move(T100UINT, T100UINT);

        static T100VOID             Position(T100UINT, T100UINT);
        static T100VOID             Rotation(T100INT, T100INT);

        static T100VOID             SetDirty();

        static T100VOID             Cancel();

        static T100VOID             AppendMesh();
        static T100VOID             AppendCamera();
        static T100VOID             AppendLight();

        static T100VOID             Append(T1003DCamera*);

    protected:
        static T1003DEditorSkeletal*            m_skeletal;

    private:
};

#endif // T1003DEDITORCALLBACK_H
