#include <iostream>
#include <map>
#include <string>

typedef void (*Function)();

template<typename T> 
class CallBack {
public:
    typedef std::map<std::string, T> CallBackMapper;
    void addCallBack(const std::string& name, T func) {
        m_mapCallBack.insert(std::pair<std::string, T>(name, func));
    }
    T getCallBack(const std::string& name) {
        auto it = m_mapCallBack.find(name);
        if (it == m_mapCallBack.end()) {
            return NULL;
        } else {
            return it->second;
        }
    }
private:
    CallBackMapper m_mapCallBack;
};

// global values
CallBack<Function> func_map;

#define ADD_FUNC(name)  func_map.addCallBack(#name, name)

void func()
{
    std::cout << "hello func" << std::endl;
}

int main(int argc, char const* argv[])
{
    ADD_FUNC(func);

    if (argc!=2) {
        std::cout << "Usage: " << std::endl;
        std::cout << argv[0] << " functionname" << std::endl;
        return -1;
    }
    std::string func_name = argv[1];

    auto val = func_map.getCallBack(func_name);
    if (NULL == val) {
        std::cout << func_name << " not found" << std::endl;
    } else {
        val();
    }

    return 0;
}
