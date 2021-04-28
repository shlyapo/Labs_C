#include <iostream>
#include "main.h"

using namespace std;
 
 
void Show(Node *&Tree)              
{
	if (Tree != NULL)               
	{
	   Show(Tree->l);               
	   cout << Tree->x << '\t';               
	   Show(Tree->r);              
	}
}
 
void Delete(Node *&Tree)
{
   if (Tree != NULL)               
	{
	   Delete(Tree->l);                
	   Delete(Tree->r);                
	   delete Tree;                 
	   Tree = NULL;                 
	}
}
 
int GetCount(Node *MyTree) 
{
	if (MyTree == NULL) 
	{
		return 0;
	} 
	else 
	{
		return MyTree->count;
	}
}

void Add(int x, Node *&MyTree) 
{
	if (NULL == MyTree)            
	{
		MyTree = new Node;         
		MyTree->x = x;              
		MyTree->l = MyTree->r = NULL;
	}
    if (x < MyTree->x)   
    {
        if (MyTree->l != NULL) 
		Add(x, MyTree->l);
        else          
        {
        MyTree->l = new Node;                
        MyTree->l->l = MyTree->l->r = NULL;   
        MyTree->l->x = x;                    
		}
	}
    if (x > MyTree->x)              
    {
        if (MyTree->r != NULL) 
		Add(x, MyTree->r);
        else              
        {
        MyTree->r = new Node;                
        MyTree->r->l = MyTree->r->r = NULL;   
        MyTree->r->x = x;                     
        }
	}
	MyTree->count = GetCount(MyTree->l) + GetCount(MyTree->r) + 1;
}

bool Check(Node *MyTree)
 {
	if (MyTree == NULL) 
	{
		return true;
	}
	if (abs(GetCount(MyTree->l) - GetCount(MyTree->r)) > 1) 
	{
		return false;
	} 
	else 
	{
		return Check(MyTree->l) & Check(MyTree->r);
	}	
}
 
int main()
{
   int a;
   Node *Tree = NULL;
   cout<<"Enter\n";  
   while(a!=0)
   {  
	cin >> a;
	if(a==0)
	break;
	Add(a, Tree); 
   } 
	Show(Tree); 
	cout << '\n';
	bool b=Check(Tree);             
	if(b==1)
	cout<<"Tree is balanced";
	else
	cout<<"Tree isn't balanced";
	Delete(Tree);                        
}