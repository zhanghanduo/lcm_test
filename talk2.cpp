#include <iostream>

#include <lcm/lcm-cpp.hpp>
#include <vector>
#include <string>
#include "obs_t.hpp"
#include <unistd.h>

int main(int argc, char ** argv)
{
    int index = 0;
    lcm::LCM lcm("udpm://239.255.76.67:7667?ttl=1");
//    lcm::LCM lcm("udpm://239.255.76.67:7667");
//    lcm::LCM lcm;
    if(!lcm.good()){
        std::cerr <<"ERROR: lcm is not good()" <<std::endl;
        return 1;
    }

    exlcm::obs_t my_data;

//    my_data.timestamp = 15031;
//    my_data.position[0] = 1;
//    my_data.position[1] = 2;
//    my_data.position[2] = 3;
//
//    my_data.orientation[0] = 1.1;
//    my_data.orientation[1] = 2.2;
//    my_data.orientation[2] = 3.3;
//    my_data.orientation[3] = 4.4;
//    my_data.num_ranges = 15;
    exlcm::point2 point1;
    point1.x = 12;
    point1.y = 13;
    exlcm::obs_t ob1;
    my_data.max_disparity = 15;

    my_data.noOfPixels = 2;
    my_data.points.resize(my_data.noOfPixels);
    my_data.points[0] = point1;
    my_data.points[1] = point1;


    my_data.endingRow = 15;
    my_data.endingCol = 20;
    my_data.startingRow = 1;
    my_data.startingCol = 5;
    my_data.which_class = 1;
    
//    my_data.ranges.resize(my_data.num_ranges);
//    for(int i = 0; i < my_data.num_ranges; i++)
//        my_data.ranges[i] = i;
//
//    my_data.name = "example string";
//    my_data.enabled = false;

//    lcm.publish("EXAMPLE", &my_data);
    while(1){
//        int range_number = 20 + index;
//        my_data.obstacle_set.clear();
//        for (size_t i = 0; i < range_number; i ++){
//          my_data.obstacle_set.push_back(i+1);
//        }
//        my_data.num_ranges = my_data.ranges.size();

//        my_data.timestamp = index*100;
//        my_data.position[0] = 1;
//        my_data.position[1] = 2;
//        my_data.position[2] = 3;
//        my_data.orientation[0] = 4;
//        my_data.orientation[1] = 5;
//        my_data.orientation[2] = 6;
//        my_data.orientation[3] = 7;
//        my_data.enabled = true;
        lcm.publish("long", &my_data);

//        std::cout << "noOfObs: " << my_data.num << std::endl;
        sleep(2);
        index++;
        printf("sent %d \n", index);
    }

    return 1;
}
