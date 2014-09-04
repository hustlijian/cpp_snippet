// ref: http://www.yolinux.com/TUTORIALS/C++Singleton.html
#include <iostream>
#include "singleton.h"

class Test{
public:
    Test():value(0) {}
    void set_value(int v) {
        value = v;
    }
    void print() {
        std::cout << "value: " << value << std::endl;
    }
private:
    int value;
};

int main(int argc, char const* argv[])
{
    typedef Singleton<Test> TestRepo;
    TestRepo::Instance()->print();
    TestRepo::Instance()->set_value(12);
    TestRepo::Instance()->print();
    return 0;
}
