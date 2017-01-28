/* Question  Your task is to fill code in the function prefix_to_infix() **/
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool ifoperator(char val)
{
    bool checker = 1;
    if (val>= 48 && val<=57)
    {
        checker = 0;
    }
    return checker;
}

string prefix_to_infix(string expr) {
    stack<char> temp;
    string toReturn = "";
    bool prev=0;
    int len  = expr.size();
    for(int i=0;i<len;i++)
    {
        if(prev)
        {
            toReturn += temp.top();
            temp.pop();
        }
        if (ifoperator(expr[i]))
        {
            temp.push(')');
            temp.push(expr[i]);
            toReturn += "(";
            prev = 0;
            continue;
        }
        else 
        {
            toReturn += expr[i];
            if(prev)
            {
                while(!temp.empty() && temp.top() == ')')
                {
                     toReturn += temp.top();
                     temp.pop();
                }
            }
            prev = 1;
        }
        
    }
    return toReturn;
    
    
    // fill in this function
    // create extra functions if needed
}


int main()
{
	string input = "*+/+34*56/+23*452";
	cout<<prefix_to_infix(input);
}
