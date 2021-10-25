#include <iostream>
using namespace std;

class Test{
    public:
        void operator=(Test const & isnt)
        {
            cout<<"hello\n";
        }
        void print()
        {
            cout<<"hello world\n";
        }
};

int main(void)
{
    Test *inst = new Test;
    Test *p1;
    *p1 = *inst;
    return 0;
}