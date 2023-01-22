/**
 * Written by Shaine Moore
 */
#include <iostream>
#include <vector>
using namespace std;
// O(log n) -> binary search
double CalculateSquareRoot(int input)
{
    //range 0 <= mid <= input
    int start = 0, mid, end = input;
    float result;
    //Finding the integral part
    while(start <= end)
    {
        mid = (start + end)/2;
        if(mid*mid == input)
        {
            result = mid;
            break;
        }
        if(mid*mid < input)
            start = mid+1;
        else
            end = mid-1;
    }
    //Finding decimal part
    float increment = 0.1;
    for(int i=0;i<5;i++)
    {
        while (result*result <= input)
            result += increment;
        result = result-increment;
        increment = increment/10;
    }
    return result;
}
//Driver
int main() {
    int input;
    cout << "what do you want to compute the root of?" << endl;
    cin >> input;
    if(input <= 0)
    {
        cout << "Your input cannot be zero or less." << endl;
        return 0;
    }
    cout << "Result: " << CalculateSquareRoot(input) << endl;
}