#include <iostream>

#include <thread>
#include <chrono>
#include "T100Main.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    T100Main    app;

    app.run();

    std::this_thread::sleep_for(std::chrono::seconds(10));

    app.quit();

    return 0;
}
