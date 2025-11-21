#ifndef __MAIN_H__
#define __MAIN_H__

#define DLL_EXPORT __declspec(dllexport)

//#include "editor\T100PluginEditorActuator.h"

#include "T100Common.h"

class T100PluginEditorActuator;

static T100PluginEditorActuator*        m_actuator      = T100NULL;

#ifdef __cplusplus
extern "C"
{
#endif

void DLL_EXPORT SignIn(void*);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
