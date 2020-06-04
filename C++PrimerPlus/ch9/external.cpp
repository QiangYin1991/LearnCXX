// external.cpp -- external variables
// compile with support.cpp
#include <iostream>
using namespace std;
// external variable
double warming = 0.3;

void update(double dt);
void local();

int main()
{
    cout << "Global warming is " << warming << " degress.\n";
    update(0.1);
    cout << "Global warming is " << warming << " degress.\n";
    local();
    cout << "Global warming is " << warming << " degress.\n";

    double a[2];
    char cha[2];
    cout << "sizeof(double)" << sizeof(double) << endl;
    cout << "a[0]:" << &a[0] << endl;
    cout << "a[1]:" << &a[1] << endl;
    cout << "sizeof(char) " << sizeof(char) << endl;
    cout << "cha[0]:" << (void*)cha << endl;
    cout << "cha[1]:" << (void*)(cha[1]) << endl;
    return 0;
}