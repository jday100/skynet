#include "main.h"

#include "T100Actuator.h"


int Init(wxFrame* frame)
{
    if(g_actuator){

    }else{
        g_actuator  = new T100Actuator();

        g_actuator->Create(frame);
    }
    return 0;
}
