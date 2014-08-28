#include "expression.h"

std::ostream& operator<<(std::ostream& os, const Expr_node& e)
{
    e.print(os);
    return os;
}

std::ostream& operator<<(std::ostream& os, const Expr& t)
{
    t.p->print(os);
    return os;
}

Expr::Expr(int n)
{
    p = new Int_node(n);
}

Expr::Expr(const std::string& op, Expr t)
{
    p = new Unary_node(op, t);
}

Expr::Expr(const std::string& op, Expr left, Expr right)
{
    p = new Binary_node(op, left, right);
}

Expr::Expr(const std::string& op, Expr left, Expr middle, Expr right)
{
    p = new Ternary_node(op, left, middle, right);
}

Expr& Expr::operator=(const Expr& rhs)
{
    rhs.p->use ++;
    if (--(p->use) == 0) {
        delete p;
    }
    p = rhs.p;
    return *this;
}

Expr::Expr(const Expr& t)
{
    p = t.p;
    ++(p->use);
}

Expr::~Expr() { 
    if (--(p->use) == 0) {
        delete p;
    }
}
int Expr::eval() const {
    return p->eval();
}

int Binary_node::eval() const
{
    int op1 = left.eval();
    int op2 = right.eval();

    if (op == "-") {
        return op1 - op2;
    }
    if (op == "+") {
        return op1 + op2;
    }
    if (op == "*") {
        return op1 * op2;
    }
    if (op == "/") {
        if (op2) {
            return op1/op2;
        } else {
            throw "0 in / operator";
        }
    }
    throw "error, bad op " + op + " in Binary_node" ;
}

int Ternary_node::eval() const
{
    if (left.eval()) {
        return middle.eval();
    } else {
        return right.eval();
    }
}
