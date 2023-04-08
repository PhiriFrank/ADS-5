// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
   char ch, elem;
 int i = 0, k = 0;
 
 RemoveSpaces(infix);
 push('#');
 
 while ((ch = infix[i++]) != '\n') {
 if (ch == '(')
 push(ch);
 else if (isalnum(ch))
 postfix[k++] = ch;
 else if (ch == ')') {
 while (s[top] != '(')
 postfix[k++] = pop();
 elem = pop(); /* Remove ( */
 } else { /* Operator */
 while (pr(s[top]) >= pr(ch))
 postfix[k++] = pop();
 push(ch);
 }
 }
 
 while (s[top] != '#') /* Pop from stack till empty */
 postfix[k++] = pop();
 
 postfix[k] = 0; /* Make postfix as valid string */
}

  return std::string("");
}

int eval(std::string pref) {
  char ch;
 int i = 0, op1, op2;
 while((ch = postfix[i++]) != 0) {
 if(isdigit(ch)) 
 push(ch-'0'); /* Push the operand */
 else { /* Operator,pop two operands */
 op2 = pop();
 op1 = pop();
 switch(ch) {
 case '+' : push(op1+op2); 
 break;
 case '-' : push(op1-op2); 
 break;
 case '*' : push(op1*op2);
 break;
 case '/' : push(op1/op2);
 break;
 }
 }
 }
 return s[top];
}

void main() { /* Main Program */
 
 char infx[50], pofx[50];
 printf("\nInput the infix expression: ");
 fgets(infx, 50, stdin);
 
 infix_to_postfix(infx, pofx);

 printf("\nGiven Infix Expression: %sPostfix Expression: %s", infx, pofx);
 top = -1;
 printf("\nResult of evaluation of postfix expression : %d", eval_postfix(pofx));

  return 0;
}
