#include<iostream>

int main()
{
    using namespace std;
    int rats = 101;
    int *pt = &rats;
    int &rodents = *pt;
    int* &ptRodents = pt;
    cout << "rats = " << rats \
         << " rodents = " << rodents \
         << " *pt = " << *pt \
         << " *ptRodents = " << *ptRodents << endl;

    cout << "&rats = " << &rats \
         << " &rodents = " << &rodents \
         << " &pt = " << &pt \
         << " &ptRodents = " << &ptRodents << endl;
    
    return 0;
}