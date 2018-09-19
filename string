#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cctype>
#include <stack>
#include <cstdio>

#define N_OPTR 9
using namespace std;

typedef enum {ADD=0, SUB, MUL, DIV, POW, FAC, L_B, R_B, EOE} Operator;
const char pri[N_OPTR][N_OPTR] = {
/*  +      -      *      /      ^      !      (      )    \0 */
  '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
  '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
  '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
  '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
  '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
  '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
  '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
   '<',   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '='
};

//convert num2float
void readNumber(const string &s, int &pos, stack<float> &stk){
    stk.push( (float)(s[pos]-'0'));
    while(isdigit(s[++pos])){
        float tmp = stk.top();
        stk.pop();
        stk.push(tmp*10 + (s[pos]-'0'));
    }
    //cout << "on top:" << stk.top() << endl;
    if(s[pos]!='.') return;  // no fraction part
    //fraction part
    float base = 1;
    float fraction = 0;
    while(isdigit(s[++pos])){
        fraction += (s[pos]-'0')*(base/=10);
    }
    float tmp = stk.top();
    stk.pop();
    stk.push(tmp+fraction);
    // at last pos point at next non digit value
}

//append float2RPN
void append2RPN(string &RPN, const float num){
    char c_num[32];
    if(num != (float)(int)num){
        // have fractional part
        sprintf(c_num, "%.2f", (float)num);
    }else{
        // num is integer
        sprintf(c_num, "%d", (int)num);
    }
    RPN.append(c_num); // append(char*)
}

//append operator2RPN
void append2RPN(string &RPN, const char oprt){
    RPN.append(1, oprt); // appen(size_t, char)
}

//get operator index
Operator oprt2index(const char opt){
    switch(opt){
        case '+' : return ADD;
        case '-' : return SUB;
        case '*' : return MUL;
        case '/' : return DIV;
        case '^' : return POW;
        case '!' : return FAC;  //fractorial
        case '(' : return L_B;  //left bracket
        case ')' : return R_B;
        case '\0' : return EOE;
        default : exit(-1); // wrong oprator
    }
}
//get order of operators
char orderBetween(const char a, const char b){
    return pri[oprt2index(a)][oprt2index(b)];
}

//calculate
float calcu(float num, char oprt){
    float ret=0;
    // TODO
    cout << "calcu:" << num << oprt << endl;
    return ret;
}
float calcu(float na, char oprt, float nb){
    float ret=0;
    // TODO
    cout << "calcu:" << na << oprt << nb << endl;
    return ret;
}

//convert infix to RPN
float infix2RPN(string S, string &RPN){
    stack<float> opnd;/*operand*/ stack<char> oprt;/*operator*/
    oprt.push('\0');
    int pos = 0;
    while( !oprt.empty()){
        //until operation empty
        if(isdigit(S[pos])){
            //handle digits
            readNumber(S, pos, opnd);
            append2RPN(RPN, opnd.top());// push num 2 RPN
        }else{
            //handle operators
            switch(orderBetween(oprt.top(), S[pos])){
            case '<' : oprt.push(S[pos]);pos++;break;
            case '=' : oprt.pop();pos++;break;
            case '>' : {
                char op = oprt.top(); oprt.pop();
                append2RPN( RPN, op); // push cur operator 2 RPN
                if( op == '!'){
                    //unary operator
                    float n = opnd.top();
                    opnd.pop();
                    opnd.push(calcu(n, op));
                }else{
                    //binary operator
                    float nb = opnd.top(); opnd.pop();
                    float na = opnd.top(); opnd.pop();
                    opnd.push(calcu(na, op, nb));
                }
                break;
            }//case '>'
            default : exit(-1); // grama wrong
            }//switch
        }
    }//while
    float ret = opnd.top();
    opnd.pop();
    return ret;
}


// infix expression to Reverse polish
int main()
{
    string infix = "1+2*3/(4^5!)"; //can't read like 1E5, float, <= 6 valid num
    string rpn;
    infix2RPN(infix, rpn);
    cout << "rpn:" << rpn << endl;
    return 0;
}


