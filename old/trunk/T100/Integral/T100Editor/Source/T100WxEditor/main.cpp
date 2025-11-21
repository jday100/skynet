#include "main.h"

#include "T100PluginEditor.h"

T100Plugin* Launch()
{
    return T100NEW T100PluginEditor();
}
