/**
 * Written by Shaine Moore
 */
#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;
//Specifies how many points to expect within the array
int numberOfPoints = 3;
//float** givenPoints = new float*[3];
/*givenPoints[0] = new float(1,0);
givenPoints[1] = new float(1,0);
givenPoints[2] = new float(0,1);*/

float givenPoints[3][2] = {{-6,3}, {-3,2}, {0,3}};
float testPoints[4][2] = {{-6,3}, {-3,2}, {0,3}, {-3,7}};
//float arr[2][2] = {{1,0}, {1,0}};
//float vectors;
int numPoints = *(&givenPoints+1)-givenPoints;
float radius = 20;
//float circleCenterPoint[2] = {0, 0};
string circumferenceContainsPoints (float radius, float points[][2], int numPoints) {
    float distance;
    for(int i=0;i<numberOfPoints;i++)
    {
        //Using pythagoras' theorem to calculate the distance between the center of the circle and the point in question.
        //sqrt[(0-Xb)^2+(0-Yb)^2];
        distance = sqrt((pow(points[numberOfPoints][0] - points[i][0], 2)) + (pow(points[numberOfPoints][1] - points[i][1], 2)));
        //If the distance is ever greater than the radius of the circle then the point is outside the circumference.
        cout << "Point "<<i+1<<"'s distance: "<<distance<< endl;
        if(distance > radius) 
        {
            //breaks the loop and returns false to the user.
            return "false";
            break;
        }
    }
    return "true";
}
string isCircle(float points[][2]) {
    //{x coord},{y coord},{slope},{y intersect}
    float vectors[numPoints*2][6];
    //find midpoint between points
    for(int i=0;i<numPoints;i++)
    {
        int k = 0;
        //compare each point with every other point except itself
        for(int j=i+1;j<numPoints && j!=i;j++) 
        {
            //cout << "i: "<< i<<", j: "<<j<<endl;
            //find vector
            vectors[k][0] = (points[i][0]+points[j][0])/2; //x value
            vectors[k][1] = (points[i][1]+points[j][1])/2; //y value
            if((points[j][0]-points[i][0]) != 0) //to avoid divide by zero errors.
                vectors[k][2] = (points[j][1]-points[i][1])/(points[j][0]-points[i][0]);//gradient (slope)
            else
                vectors[k][2] = (points[j][1]-points[i][1]);
            vectors[k][3] = (vectors[k][1] - (vectors[k][2]+vectors[k][2]));//b value in y=mx+b
            vectors[k][4] = (points[j][1]-points[i][1])*(vectors[k][0]);//*(-1);//A (Standard Form)
            vectors[k][5] = (points[j][0]-points[i][0])*vectors[k][1];//B (Standard Form)
            vectors[k][6] = (points[j][0]-points[i][0])*vectors[k][3];//C (Standard Form)
            //cout << vectors[k][0]<< "   "<<vectors[k][1]<< "   "<<vectors[k][2]<< "   "<<vectors[k][3]<< endl;
            cout << "Y-intercept: "<<vectors[k][1]<<" = ("<<points[j][1]-points[i][1]<<"/"<<points[j][0]-points[i][0]<<")("<<vectors[k][0]<<") + "<<vectors[k][3]<<endl;
            cout<<"standard form: "<<vectors[k][4]<<"A + "<<vectors[k][5]<<"B + "<<vectors[k][6]<<"C"<<endl;
            k++;
        }
    }
    float midPoint[2];
    //determine if vectors connect and keep track of common midpoint
    float point[2]; //temp var
    for(int i=0;i<numPoints*2;i++) //compares the points in pairs, then compares the derived midpoint.
    {
        if((vectors[i][4]*vectors[i+1][5]-vectors[i+1][4]*vectors[i][5]) != 0)
            point[0] = ((vectors[i][5]*vectors[i+1][6]-vectors[i+1][5]*vectors[i][6])/(vectors[i][4]*vectors[i+1][5]-vectors[i+1][4]*vectors[i][5]));//finds the x value of the midpoint from 2 lines.
        else
            point[0] = (vectors[i][5]*vectors[i+1][6]-vectors[i+1][5]*vectors[i][6]);
        cout<<vectors[i][5]<<"*"<<vectors[i+1][6]<<"-"<<vectors[i+1][5]<<"*"<<vectors[i][6]<<endl;
        cout << (vectors[i][5]*vectors[i+1][6]-vectors[i+1][5]*vectors[i][6])<<" / "<<(vectors[i][4]*vectors[i+1][5]-vectors[i+1][4]*vectors[i][5])<< "     ";
        if((vectors[i][4]*vectors[i+1][5]-vectors[i+1][4]*vectors[i][5]) != 0)
            point[1] = ((vectors[i][6]*vectors[i+1][4]-vectors[i+1][6]*vectors[i][4])/(vectors[i][4]*vectors[i+1][5]-vectors[i+1][4]*vectors[i][5]));//finds the y value of the midpoint from 2 lines.
        else
            point[1] = (vectors[i][6]*vectors[i+1][4]-vectors[i+1][6]*vectors[i][4]);
        cout << (vectors[i][6]*vectors[i+1][4]-vectors[i+1][6]*vectors[i][4]) <<" / "<< (vectors[i][4]*vectors[i+1][5]-vectors[i+1][4]*vectors[i][5])<<"   --->   ";
        cout << point[0] << "   "<< point[1] << endl;
        if(i <= 0)
            midPoint[0] = point[0], midPoint[1] = point[1];
        else if(midPoint[0] != point[0] || midPoint[1] != point[1])
            return "false";

    }
    return "true. Midpoint: \\midpoint[0],\\midpoint[1]";
}

//Driver
int main() 
{
    cout << "Is contained: " << endl<< isCircle(givenPoints) << endl;
    cout << "Is contained: " << endl << circumferenceContainsPoints(radius, testPoints, numberOfPoints) << endl;
    return 0;
}