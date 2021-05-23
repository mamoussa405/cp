#include <vector>
#include <iostream>
#include "std++.h"
using namespace std;

int main(void)
{
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    swap(v[0], v[max_element(v.begin(), v.end()) - v.begin()]);
    cout << v[0] << endl;
    return 0;
}