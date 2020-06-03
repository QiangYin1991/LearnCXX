#include <iostream>
#include <memory>

using namespace std;

class TestPtr {
public:
    TestPtr(){ std::cout << "TestPtr" << std::endl;}
    ~TestPtr() {std::cout << "~TestPtr" << std::endl;}
};

void Test()
{
    std::shared_ptr<TestPtr> ptr(new TestPtr); 
}

int main() {
    std::cout << "begin " << std::endl;
    Test();
    std::cout << "end" << std::endl;
    return 0;
}