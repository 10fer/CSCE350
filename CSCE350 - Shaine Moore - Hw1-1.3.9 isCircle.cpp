/*
/Written by Shaine Moore
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <cmath>
using namespace std;
 
// Function to find the circle on
// which the given three points lie
//int givenPoints[3][2] = {{-1,-1}, {0,0}, {1,1}}; // non circle points
//int givenPoints[3][2] = {{0,1}, {0,-1}, {0,0}}; // non circle points
int givenPoints[3][2] = {{-6,3}, {-3,2}, {0,3}};
int numPoints = *(&givenPoints+1)-givenPoints;

string isCircle(int points[][2]) {
    //equation of a circle = x^2 + y^2 = 1, x^2 + y^2 + 2gx + 2fy + c = 0, 
    int x12 = points[0][0]-points[1][0]; int y12 = points[0][1]-points[1][1];
    int x13 = points[0][0]-points[2][0]; int y13 = points[0][1]-points[2][1];
    int x31 = points[2][0]-points[0][0]; int y31 = points[2][1]-points[0][1];
    int x21 = points[1][0]-points[0][0]; int y21 = points[1][1]-points[0][1];

    int sx13 = pow(points[0][0],2)-pow(points[3][0],2);
    int sy13 = pow(points[0][1],2)-pow(points[3][1],2);
    int sx21 = pow(points[1][0],2)-pow(points[0][0],2);
    int sy21 = pow(points[1][1],2)-pow(points[0][1],2);

    if((2 * ((y31) * (x12) - (y21) * (x13))) == 0)//checks to make sure the points are not colinear.
        return "is contained: false (co-linear)";
    int f = ((sx13) * (x12) + (sy13) * (x12) + (sx21) * (x13) + (sy21) * (x13)) / (2 * ((y31) * (x12) - (y21) * (x13)));
    if((2 * ((x31) * (y12) - (x21) * (y13))) == 0)//just incase, to avoid divide by zero errors.
        return "is contained: false";
    int g = ((sx13) * (y12) + (sy13) * (y12) + (sx21) * (y13) + (sy21) * (y13)) / (2 * ((x31) * (y12) - (x21) * (y13)));
    int c = -1*pow(points[0][0],2)-pow(points[0][1],2) - 2 * g * points[0][0] - 2 * f * points[0][1];

    int midPoint[2] = {{g*(-1)},{f*(-1)}};

    cout << "Circle Center = (" << midPoint[0] << ", " << midPoint[1] << ")" << endl;
    return "is contained: true";
}
// Driver
int main()
{
    cout<< isCircle(givenPoints)<< endl;
    return 0;
}