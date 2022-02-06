//adnan-ullah
#include<bits/stdc++.h>
using namespace std;

#define show(a) cout<<a<<endl
bool postfix_check(string s)
{
    for(int i = s.size()-1; i>=0 ; i--)
    {
        if(s[i]== '+' || s[i]== '-' || s[i]=='*' || s[i]=='/')
            return true;
        else
            return false;
    }
    return false;
}
bool prefix_check(string s)
{
    for(int i = 0; i<s.size() ; i++)
    {
        if(s[i]== '+' || s[i]== '-' || s[i]=='*' || s[i]=='/')
            return true;
        else
            return false;
    }
    return false;
}
bool infix_check(string s)
{

    if(!postfix_check(s) && !prefix_check(s))
    {
        for(int i = 0; i<s.size() ; i++)
        {
            if(s[i]== '+' || s[i]== '-' || s[i]=='*' || s[i]=='/')
                return true;
        }
    }

    return false;
}



int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return 0;
}
bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
  case '^':
  case '%':
    return true;
  }
  return false;
}

string pre_To_Post(string pre_exp)
{

    stack<string> s;

    int length = pre_exp.size();


    for (int i = length - 1; i >= 0; i--)
    {

        if (isOperator(pre_exp[i]))
        {

            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();


            string temp = op1 + op2 + pre_exp[i];


            s.push(temp);
        }


        else {


            s.push(string(1, pre_exp[i]));
        }
    }

    return s.top();
}
string inf_to_prefix(string infix)
{
    string postfix = "";
    stack <char> myStack;
    char ch;

    for(int i=0; infix[i]; i++)
    {
        ch = infix[i];

            int priority = prec(ch);
            if(priority==0)
                postfix = postfix + ch;
            else
            {
                if(myStack.empty())
                    myStack.push(ch);
                else
                {
                    while(!myStack.empty()
                            && priority<=prec(myStack.top()))
                    {
                        postfix = postfix + myStack.top();
                        myStack.pop();
                    }
                    myStack.push(ch);
                }


        }
    }

    while(!myStack.empty())
    {
        postfix += myStack.top();
        myStack.pop();
    }

    return postfix;
}

int myResult(string  exp)
{
    stack <int> STACK;
    int len = exp.length();

    string indv="";

    for (int i = 0; i < len; i++)
    {

        if ( isdigit(exp[i]))
            STACK.push( exp[i] - '0');

        else
        {
            int a = STACK.top();  STACK.pop();
            int b = STACK.top();  STACK.pop();


            stringstream ss1,ss2;
            string left,right, op(1,exp[i]);
            ss1<<a;;
            ss2<<b;
            ss1>>left;
            ss2>>right;

            indv =  left + op + right;

            string later= "";
            for(int j=i+1; j< len ; j++)
            {
                later = later +exp[j];
            }
            cout<<"=> "<<indv+later<<endl;


            switch (exp[i])
            {
            case '+':
                STACK.push(b + a);
                break;

            case '-':
                STACK.push(b - a);
                break;
            case '*':
                STACK.push(b * a);
                break;
            case '/':
                STACK.push(b / a);
                break;

            }
        }
    }

    return STACK.top();
}

int main()
{
        string s;
        cin>>s;

        if(postfix_check(s))
        {
            show("The expression is postfix notation");

            show("\nAnswer:\n");
            show(myResult(s));

        }
        if(prefix_check(s))
        {
            show("The expression is prefix notation");


            string postfix =  pre_To_Post(s);

            show("\nAnswer:\n");
            show(myResult(postfix));
        }
        if(infix_check(s))
        {

            show("The expression is Infix notation");

             string postfix =  inf_to_prefix(s);
             show("\nAnswer:\n");
             show(myResult(postfix));
        }

    // prefix   : *-2/45-/421
    // postfix : 54*9-
    // infix : 9+8-2

}
