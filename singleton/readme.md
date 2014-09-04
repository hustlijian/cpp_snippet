##singleton
c++ singleton pattern, use template.

###usage:

    class YourClass {
        ...
    }

    typedef Singleton<YourClass> YourClassRepo;

    YourClass* object  = YourClassRepo::Instance();

    // do any thing use object.
    ...

###ref:
- http://www.yolinux.com/TUTORIALS/C++Singleton.html
