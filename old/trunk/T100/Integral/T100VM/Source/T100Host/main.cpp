#include "T100Host.h"

#include <thread>

int main()
{
    T100Host    host;

    //host.Start();

    std::thread     thread(&T100Host::Start, &host);

    thread.join();
    return 0;
}
