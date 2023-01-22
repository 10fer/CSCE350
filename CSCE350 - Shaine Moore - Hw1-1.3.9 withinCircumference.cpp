/**
 * Written by Shaine Moore
 */
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//Specifies how many points to expect within the array
int numberOfPoints = 3;
//Last point in the array is the center of the circle
float points[4][2] = {{1,3}, {3,5}, {-4,5}, {0,0}};
float radius = 6;
//float circleCenterPoint[2] = {0, 0};
string circumferenceContainsPoints (float redius, float points[4][2], int numPoints) {
    float distance;
    for(int i=0;i<numberOfPoints;i++)
    {
        //Using pythagoras' theorem to calculate the distance between the center of the circle and the point in question.
        //sqrt[(0-Xb)^2+(0-Yb)^2]
        /*distance = pow(points[numberOfPoints][0] - points[i][0], 2);
        distance = distance + (pow(points[numberOfPoints][1] - points[i][1], 2));
        distance = sqrt(distance);
        cout << distance << endl;*/
        distance = sqrt((pow(points[numberOfPoints][0] - points[i][0], 2)) + (pow(points[numberOfPoints][1] - points[i][1], 2)));
        //If the distance is ever greater than the radius of the circle then the point is outside the circumference.
        //cout << "Point "<<i+1<<"'s distance: "<<distance<< endl;
        if(distance > radius) 
        {
            //breaks the loop and returns false to the user.
            return "false";
            break;
        }
    }
    return "true";
}
//Driver
int main() 
{
    cout << "Is contained: " << circumferenceContainsPoints(radius, points, numberOfPoints) << endl;
}