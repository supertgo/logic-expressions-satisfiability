#ifndef BOOL_EXPR
#define BOOL_EXPR

unsigned int precedence(char op);
int applyOp(int a, int b, char op);
int returnASCIIDigit(const char c);
int evaluate(const char *expression, const char *expression_values);

#endif // !DEBUG
