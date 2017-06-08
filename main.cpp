#include <iostream>

#include <lcm/lcm-cpp.hpp>
#include <vector>
#include <string>
#include "obset_t.hpp"
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

    exlcm::obset_t my_data;

    exlcm::point2 point1;
    point1.x = 12;
    point1.y = 13;
    exlcm::obs_t ob1;
    ob1.max_disparity = 15;
//    ob1.noOfPixels = 20;
    ob1.points.clear();
    ob1.points.push_back(point1);
    ob1.points.push_back(point1);
    ob1.noOfPixels = int(ob1.points.size());
    ob1.endingRow = 15;
    ob1.endingCol = 20;
    ob1.startingRow = 1;
    ob1.startingCol = 5;
    ob1.which_class = 1;
//    std::cout << "noOfPixels: " << ob1.noOfPixels << std::endl;

    my_data.utime = 0.015135;
    my_data.position[0] = 1;
    my_data.position[1] = 2;
    my_data.position[2] = 3;

    my_data.orientation[0] = 1.1;
    my_data.orientation[1] = 2.2;
    my_data.orientation[2] = 3.3;
    my_data.orientation[3] = 4.4;
    my_data.obstacle_set.clear();
    my_data.obstacle_set.push_back(ob1);
    my_data.obstacle_set.push_back(ob1);
    my_data.obstacle_set.push_back(ob1);
    my_data.num = int(my_data.obstacle_set.size());
//    my_data.obstacle_set.resize(my_data.num);

    my_data.resolution = 0.77;
    my_data.name = "send_test";
    my_data.status = 1;
//    for(int i=0;i<my_data.num;++i){
//        std::cout << "point: " << my_data.obstacle_set[i].points[0].x << std::endl;
//    }


//    lcm.publish("EXAMPLE", &my_data);
    while(1){
//        int range_number = 20 + index;
//        my_data.obstacle_set.clear();
//        for (size_t i = 0; i < range_number; i ++){
//          my_data.obstacle_set.push_back(i+1);
//        }
//        my_data.num_ranges = my_data.ranges.size();

        my_data.utime = index/100;
        my_data.position[0] = 1;
        my_data.position[1] = 2;
        my_data.position[2] = 3;
        my_data.orientation[0] = 4;
        my_data.orientation[1] = 5;
        my_data.orientation[2] = 6;
        my_data.orientation[3] = 7;
        my_data.status = 2;
        lcm.publish("long", &my_data);

//        std::cout << "noOfObs: " << my_data.num << std::endl;
        sleep(2);
        index++;
        printf("sent %d \n", index);
    }

    return 1;
}
