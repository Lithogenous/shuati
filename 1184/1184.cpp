#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int distanceClockwise = 0;
        int distanceCounterClockwise = 0;
        for(int i=start; i != destination;){
            distanceClockwise += distance[i];
            i++;
            i = (i + distance.size())%distance.size();
        }
        for(int i=start; i != destination;){
            i--;
            i = (i + distance.size())%distance.size();
            distanceCounterClockwise += distance[i];
        }
        printf("%d %d", distanceClockwise, distanceCounterClockwise);
        return distanceClockwise>distanceCounterClockwise? distanceCounterClockwise: distanceClockwise;
    }
};

int main()
{
    vector<int> distance;
    distance.push_back(1);
    distance.push_back(2);
    distance.push_back(3);
    distance.push_back(4);
    Solution a;
    a.distanceBetweenBusStops(distance, 0, 3);
}
