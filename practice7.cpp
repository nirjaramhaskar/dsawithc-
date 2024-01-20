#include<iostream>
#include<string.h>
using namespace std;
struct node{

   char data;
   node *left;
   node *right;
};

class tree{

  char prefix[20];

public:
   node *top;
   void expression(char[]);
   void display(node *); 
   void non_rec_postoreder(node *);
   void del(node *);
};

class stack {
 
 node *data[30];
 int top;

public:
  stack(){
     top = -1;
  }
  
  int empty(){
     if(top == -1)
         return 1;
     return 0;
   }

   void push(node *p){
       
      data[++top] = p;
   }
   node *pop(){
      return (data[top--]);

   }
};

void tree::expression(char prefix[]){






    
}

int main()
{



    return 0;
}
