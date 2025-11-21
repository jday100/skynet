#ifndef MAIN_H
#define MAIN_H

class wxFrame;
class T100Actuator;

static T100Actuator*        g_actuator          = nullptr;

extern "C"
{
    int Init(wxFrame*);
}


#endif // MAIN_H
