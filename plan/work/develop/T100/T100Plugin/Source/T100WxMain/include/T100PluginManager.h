#ifndef T100PLUGINMANAGER_H
#define T100PLUGINMANAGER_H

class wxFrame;

class T100PluginManager
{
    public:
        T100PluginManager();
        virtual ~T100PluginManager();

        void Start(wxFrame*);
        void Stop();

    protected:

    private:
};

#endif // T100PLUGINMANAGER_H
