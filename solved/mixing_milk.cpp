#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ifstream cin("mixmilk.in");
    ofstream cout("mixmilk.out");
    array<array<long long, 2>, 3> arr;
    for (size_t i = 0; i < 3; i++)
        cin >> arr[i][0] >> arr[i][1];
    int j = 1;
    for (size_t i = 0; i < 100; i++)
    {
        //pour bucket 1 in bucket 2
        if (j == 1)
        {
            int res = arr[1][0] - arr[1][1];
            if (res >= arr[0][1])
            {
                arr[1][1] += arr[0][1];
                arr[0][1] = 0;
            }
            else if (res > 0)
            {
                arr[1][1] += res;
                arr[0][1] -= res;
            }
        }
        //pour bucket 2 in bucket 3
        if (j == 2)
        {
            int res = arr[2][0] - arr[2][1];
            if (res >= arr[1][1])
            {
                arr[2][1] += arr[1][1];
                arr[1][1] = 0;
            }
            else if (res > 0)
            {
                arr[2][1] += res;
                arr[1][1] -= res;
            }
        }
        //pour bucket 3 in bucket 1
        if (j == 3)
        {
            int res = arr[0][0] - arr[0][1];
            if (res >= arr[2][1])
            {
                arr[0][1] += arr[2][1];
                arr[2][1] = 0;
            }
            else if (res > 0)
            {
                arr[0][1] += res;
                arr[2][1] -= res;
            } 
        }
        j++;
        if (j == 4)
             j = 1;
    }
    cout << arr[0][1] <<'\n' <<  arr[1][1] << '\n' << arr[2][1];
    return 0;
}