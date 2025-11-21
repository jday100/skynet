// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the shared library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

#include "T100Actuator.h"

static T100Actuator*        g_actuator      = nullptr;

extern "C"
{
    int Init()
    {
        if(g_actuator){

        }else{
            g_actuator      = new T100Actuator();
        }
        return 1;
    }

    int Message()
    {
        g_actuator->Message();
        return 1;
    }
}
