#include "lib.h"

int isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^'){
    return 1;
    }

}

int priority(char oper) {
    if(oper == '^'){
    return 3;
    } 
    if(oper == '*' || oper == '/' || oper == '%'){
    return 2;
    }
    if(oper == '+' || oper == '-'){
        return 1;
    }
    return 0;
}

double addoperator(char oper, double b, double a) {
    switch(oper) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return fmod(a, b);
        case '^': return pow(a, b);
    }
    return 0;
}

double calculator(char* expr) {
    int i;
    int len = strlen(expr);
    double val_stack[100];
    int val_top = -1;
    char op_stack[100];
    int op_top = -1;

    for(i = 0; i < len; i++) {
        if(isdigit(expr[i])) {
            double val = 0;
            while(i < len && isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            val_stack[++val_top] = val;
        } else if(expr[i] == '(') {
            op_stack[++op_top] = expr[i];
        } else if(expr[i] == ')') {
            while(op_top != -1 && op_stack[op_top] != '(') {
                double val2 = val_stack[val_top--];
                double val1 = val_stack[val_top--];
                char op = op_stack[op_top--];
                val_stack[++val_top] = addoperator(op, val2, val1);
            }
            if(op_top != -1 && op_stack[op_top] == '(') {
                op_top--;
            }
        } else if(isOperator(expr[i])) {
            while(op_top != -1 && priority(op_stack[op_top]) >= priority(expr[i])) {
                double val2 = val_stack[val_top--];
                double val1 = val_stack[val_top--];
                char op = op_stack[op_top--];
                val_stack[++val_top] = addoperator(op, val2, val1);
            }
            op_stack[++op_top] = expr[i];
        }
    }

    while(op_top != -1) {
        double val2 = val_stack[val_top--];
        double val1 = val_stack[val_top--];
        char op = op_stack[op_top--];
        val_stack[++val_top] = addoperator(op, val2, val1);
    }

    return val_stack[val_top];
}