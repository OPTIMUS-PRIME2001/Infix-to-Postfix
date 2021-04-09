#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;
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
       { ch=Stack[top];
         return ch;
       } 
       else 
       { 
		return '\0'; 
       }
   }         
}S;
int precedence(char ch) //function to check precendence of the operators
{switch(ch)
  { case '^':return 7;
    case '/':return 6;
    case '*':return 6;
    case '+':return 5;
    case '-':return 5;
    case '<':return 4;
    case '>':return 4;
    case '&':return 3;
    case '|':return 2;
    default: return 0;
  }
}
bool check_braces(string s) //function to check equal number of braces(in out) present or not
{ int leftbr=0, rightbr=0;
  for (int i=0; s[i]; i++)
   { if (s[i]=='(') 
      {  
		leftbr++;
	  }	
     else if (s[i]==')') 
	   { 
		 rightbr++;
	   }
   }
   if(leftbr==rightbr) 
       { 
		   return true; 
	   }
   else 
       { 
		   return false; 
	    }
}
string infixToPostfix( string s ) // The function to calculate 
{ bool chk=check_braces( s ); 
  char ch;
  string postfix; //another string to get the postfix expression
  if (chk==false )
    { 
		cout<<"\nUnbalanced no. of braces\n Extra bracket";    
    }
  for (int i=0; s[i]!='\0'; i++)
   { cout<< s[i] <<endl; 
     if (isalnum( s[i] ) || s[i]=='.')        //alphabet and numeric value encountered
        { 
		   postfix += s[i];  //paste it to postfix expression
        }  
      else if( s[i]=='(' )       // first braces encountered 
        { 
			S.Push( s[i]); //push it to stack
        }
      else if(s[i]==')')     //'close first braces encountered 
        { 
		while( ((ch=S.Topele())!='(') && (S.Topele()!='\0') ) //check no null or no first braces encountered 
	        { S.Pop();     //pop value and movie it to 
                   postfix +=ch;
		}
	      if(S.Topele()=='(')
               {
		S.Pop();
	        }
        }    
      
      else
       { 
	  while((S.Topele()!='\0')&&(precedence(S.Topele())>=precedence(s[i]))&&(s[i]!='&')&&(s[i]!='|'))
          { 
            ch=S.Topele();
            S.Pop();
            postfix +=ch;
          }
          S.Push(s[i]); 
       }
      
    }

  while(S.Topele()!='\0')
   { ch=S.Topele();
     S.Pop();
     postfix +=ch;
   }
   return postfix;
}
int main()
{  int choice; string line;
    cout<<"Infix to Postfix\n";
        ifstream fiP;                     //file opened in read mode
        fiP.open("Infix.txt", ios::in);
        if(!fiP)                          //if statement to check is file is null or doesn't exist
          {
		    cout<<"File can\'t be opened \n";
		  }
        else
          { 
		     while(!fiP.eof())              //while loop untill end of file
               { 
				   getline(fiP,line);    //line take the infix expression from file
                   cout<< infixToPostfix(line) <<endl; 
               }
           }                
  fiP.close(); // read mode file closed
  return 0;
}
