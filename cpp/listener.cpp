// file: listener.cpp
//
// LCM example program.
//
// compile with:
//  $ gcc -o listener listener.cpp -llcm
//
// On a system with pkg-config, you can also use:
//  $ gcc -o listener listener.cpp `pkg-config --cflags --libs lcm`

#include <stdio.h>
#include <iostream>
#include <string>
#include <lcm/lcm-cpp.hpp>
#include "../obset_t.hpp"
using namespace std;

class Handler
{
public:
    ~Handler() {}

    void handleMessage(const lcm::ReceiveBuffer* rbuf,
                       const std::string& chan,
                       const exlcm::obset_t* msg)
    {
        int i;
        std::vector <exlcm::obs_t> receive;
        receive.resize(msg->obstacle_set.size());
        receive = msg->obstacle_set;
        printf("Received message on channel \"%s\":\n", chan.c_str());
        cout << "type of the message: " << msg->name.c_str() << endl;
        printf("  timestamp   = %f\n", msg->utime);
        printf("  position    = (%f, %f, %f)\n",
               msg->position[0], msg->position[1], msg->position[2]);
        printf("  orientation = (%f, %f, %f, %f)\n",
               msg->orientation[0], msg->orientation[1],
               msg->orientation[2], msg->orientation[3]);
        cout << "num of obstacles: " << msg->num << endl;
        for(i = 0; i < msg->num; i++)
            printf("max disparity of %d is: %d", i, receive[i].max_disparity);
//                printf("max disparity of %d is: %d", i, msg->obstacle_set[i].max_disparity);
        printf("  enabled     = %d\n", msg->status);
        cout << "point2 " << msg->obstacle_set[0].points[0].y << endl;
    }
};

int main(int argc, char** argv)
{
    lcm::LCM lcm("udpm://239.255.76.67:7667");
//    lcm::LCM lcm;

    if(!lcm.good())
        return 1;

    Handler handlerObject;
    lcm.subscribe("long", &Handler::handleMessage, &handlerObject);

    while(0 == lcm.handle());

    return 0;
}