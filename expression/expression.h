#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <ostream>
#include <string>

class Expr_node; // declare 

class Expr {
    friend std::ostream& operator<<(std::ostream&, const Expr&);
    friend class Expr_node;

    Expr_node *p;
public:
    Expr(int);
    Expr(const std::string&, Expr);
    Expr(const std::string&, Expr, Expr);
    Expr(const std::string&, Expr, Expr, Expr);
    Expr(const Expr& t);
    Expr& operator=(const Expr&);
    ~Expr();
    int eval() const;
};

class Expr_node {
    friend std::ostream& operator << (std::ostream&, const Expr_node&);
    friend std::ostream& operator << (std::ostream&, const Expr&);
    friend class Expr;

    int use;

protected:
    Expr_node():use(1) {}
    virtual void print(std::ostream &) const = 0;
    virtual ~Expr_node() {}
    virtual int eval() const = 0;
};

class Int_node: public Expr_node {
    friend class Expr;
    int n;

    Int_node(int k):n(k){}
    void print(std::ostream& os) const {
        os << n;
    }
    int eval() const {
        return n;
    }
};

class Unary_node: public Expr_node {
    friend class Expr;
    std::string op;
    Expr opnd;

    Unary_node(const std::string& a, Expr b):op(a), opnd(b) {}
    void print(std::ostream& os) const {
        os << "(" << op << opnd << ")";
    }
    int eval() const {
        if (op == "-") {
            return -opnd.eval();
        } else {
            throw "error, bad op" + op + "int unary node";
        }
    }
};

class Binary_node: public Expr_node {
    friend class Expr;
    std::string op;
    Expr left;
    Expr right;
    Binary_node(const std::string& a, Expr b, Expr c)
        :op(a), left(b), right(c) {}
    void print(std::ostream& os) const {
        os << "(" << left << op << right << ")";
    }
    int eval() const;
};

class Ternary_node: public Expr_node {
    friend class Expr;
    std::string op;
    Expr left;
    Expr middle;
    Expr right;

    Ternary_node(const std::string& a, Expr b, Expr c, Expr d)
        :op(a), left(b), middle(c), right(d){}
    void print(std::ostream& os) const {
        os << "(" << left << " ? " << middle << " : " << right << ")";
    }
    int eval() const;
};

#endif // end of EXPRESSION_H

