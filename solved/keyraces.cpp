#include <iostream>
using namespace std;

int main(void)
{
    int s,v1,v2,t1,t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    if (((v1*s) + (t1*2)) < ((v2*s) + (t2*2)))
        cout<<"First\n";
    else if (((v1*s) + (t1*2)) > ((v2*s) + (t2*2)))
        cout<<"Second\n";
    else
        cout<<"Friendship\n";
    return 0;
}