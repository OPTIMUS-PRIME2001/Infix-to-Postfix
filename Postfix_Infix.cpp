#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
/*
struct node
{
	char data ;
	node *next ;
};
class stack
{
	private : 
	node *top;
	public :
	stack()
	{
		top = NULL;
	}
	void push(char a)
	{
		node * temp = new node();
		temp ->data = a ;
		temp -> next = top ; 
		top = temp ;
	}
	char pop()
	{
		node *temp = top ;
		top = temp->next ;
		char a = temp->data ;
		delete temp;
		return a;
	}
	char see_top()
	{
		if(is_empty())
			return '0' ;
		node * temp = top ;
		return (temp->data);
	}
	int is_empty()
	{
		if(top == NULL)
			return 1;
		else
			return 0 ;
	}
}S;
*/

class Stack
{ private:  
  int top= -1, size= 100; 
  char Stack[100];

  public: 
  char Push(char ch)
   {    if (top!= size-1)
       {  
		  top++;
          Stack[top]=ch;
       }
   }

  char Pop()
   {   char temp;
       if (top!= -1)
       { 
		 temp=Stack[top];
         top--;
         return temp;
       }
      else 
      { 
	   return '\0';
      }
   }

  char Topele()
   {    char ch;
       if(top!= -1)
       { if(is_empty())
	        return 0;
		 ch=Stack[top];
         return ch;
       } 
       else 
       { 
		return '\0'; 
       }
   }         

	/*char gettop()
	{
		if(is_empty())
			return '0' ;
		node * temp = head ;
		return (temp->data);
	}*/
	int is_empty()
	{
		if(top!=-1)
			return 1;
		else
			return 0;
	}
}S ;
int is_allnum(char an)
{
	if(isalnum(an))
		return 1;
	else
		return 0;
}
int is_operand(char ch)
{
	switch(ch)
	{
		case '*' :return 2;
		case '/' :return 2;
		case '+' : return 1;
		case '-' : return 1;
		default  : return 0;
	}
}
void reverse(string c, int l)
{
	int i=0;
	for(int j=0;j<l;j++)
	{
		S.Push(c[j]);
	}
	while(!S.is_empty())
		c[i++]=S.Pop();
	return ;
}
	
string PostfixToInfix(string s)
{	
	string infix;
	int size= s.length();
	reverse(s,size);
	for(int i=0;i<size;i++)
	{
		if(is_allnum(s[i]))
		{
			infix  += s[i];
			if(i==size-1)
				break ;
			infix += S.Pop() ;
		}
		else
			S.Push(s[i]);
	}
	while(!S.is_empty())
	{	
		infix +=S.Pop();
	}	
	reverse(infix,size);
	return infix;
}

int main()
{  int choice; string line;
    cout<<" Postfix to Infix\n";
        ifstream fPi;                     //file opened in read mode
        fPi.open("Postfix.txt", ios::in);
        if(!fPi)                          //if statement to check is file is null or doesn't exist
          {
		    cout<<"File can\'t be opened \n";
		  }
        else
          { 
		     while(!fPi.eof())              //while loop untill end of file
               { 
				   getline(fPi,line);    //line take the infix expression from file
                   cout<< PostfixToInfix(line) <<endl; 
               }
           }                
  fPi.close(); // read mode file closed
  return 0;
}