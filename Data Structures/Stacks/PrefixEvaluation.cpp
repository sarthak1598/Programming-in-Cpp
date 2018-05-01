#include<iostream>
#include<stack>


/*Program to do Prefix expression evaluation using stack
It is similar to the Postfix evaluation using stack, in this case we just have to read the expression from right to left;

*/

using namespace std;

//function protorypes-

int getResultPre(string exp);

bool isOperand(char c);

bool isOperator(char c);

int PerfromOps(int a,int b ,char c);

int getResultPre(string exp)
{
	stack<int>S;
	//scanning the expression from right to left
	for(int i = exp.length() ; i > 0 ; i--)
	{
		if(exp[i]=="," || exp[i]==" ") continue;
		
		//if the scanned input is an operator, then pop 2 operands from stack and operate them
		else if(isOperator(exp[i]) && !S.empty())
		{
			int a = S.top(); S.pop();
			
			int b = S.top() ; S.pop();
			
			int result  = PerformOps(a,b,exp[i]);
			
			//pusing the result in stack
			S.push(result);
			
			
		}
		
		
		//push it to the stack
		else if(isOperand(exp[i]) && !S.empty()) 
		{
			int op = 0;
			
			//converting the string to integer
			op = (exp[i]-'0');
			
		
			S.push(op);
		}
		
	}
	
	if(S.empty())
	{
		return 0;
	}
	
	return S.top(); //result is stored at top;
}


bool isOperand(char c)
{
	if(c >= 'a' && c <= 'z' ) return true;
	if(c >='A' && c<= 'Z') return true;
	
	if(c>='0' && c<='9') return true;
	
	
	return false;
}


bool isOperator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/') return true;
	
	return false;
}


int main()
{
	return 0;
}

