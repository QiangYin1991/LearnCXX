#include<iostream>

void dribble(char *bits);
void dribble(const char *bits);
void test1(int a);
//void test1(double a);

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
    
    const char p1[20] = "How's the weather?";
    char p2[20] = "How's business?";
    cout << " dribble(char *bits): ";
    dribble(p1);
    cout << " dribble(const char *bits): ";
    dribble(p2); 
    cout << " test";
    test1(0.0);
    return 0;
}

void dribble(char *bits)
{
    std::cout << "bits: " << bits << std::endl;
}

void dribble(const char *bits)
{
    std::cout << "const bits: " << bits << std::endl;
}

void test1(int a)
{
    std::cout << "test1(int a)" << std::endl;
}

// void test1(double a)
// {
//     std::cout << "test1(int a, int b)" << std::endl;
// }