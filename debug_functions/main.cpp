#include <iostream>
#include "debug.h"

int main(int argc, char const* argv[])
{
    debug("I am %d years old", 12);
    log_err("there are %d problem in %s.", 1, "test");
    printf("this is test %d" "hello %s" "\n", 12, "test");

    return 0;
}
