#include <iostream>
#include "expression.h"

using namespace std;

int main(int argc, char const* argv[])
{
    Expr t = Expr("*", Expr("-", 5), Expr("+", 3, 4));
    cout << t << "=" << t.eval() << endl;
    t = Expr("*", t, t);
    cout << t << "=" << t.eval() << endl;
    Expr ternary = Expr("T", 1, 5, 4);
    cout << ternary << "=" << ternary.eval() << endl;

    return 0;
}

