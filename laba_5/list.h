 #include <iostream>
 
using namespace std;
 
 struct Elem
{
   int data; 
   Elem * next, * prev;
};
 
class List
{
   Elem * Head, * Tail;
   int Count;
 
public:
 
   List();
   List(const List&);
   ~List();
   int GetCount();
   void DelAll();
   void Del(int pos = 0);
   void AddTail(int n);
   void Print();	
};
 
List::List()
{
   Head = Tail = NULL;
   Count = 0;
}
 
List::List(const List & L)
{
   Head = Tail = NULL;
   Count = 0;
   Elem * temp = L.Head;
   while(temp != 0)
   {
      AddTail(temp->data);
      temp = temp->next;
   }
}
 
List::~List()
{
   DelAll();
}
 
void List::AddTail(int n)
{
   Elem * temp = new Elem;
   temp->next = 0;
   temp->data = n;
   temp->prev = Tail;
   if(Tail != 0)
      Tail->next = temp;
   if(Count == 0)
      Head = Tail = temp;
   else
   Tail = temp;			
   Count++;
}
 

void List::Del(int pos)
{
   int i = 1;
   Elem * Del = Head;
   while(i < pos)
   {
      Del = Del->next;
      i++;
   }
   Elem * PrevDel = Del->prev;
   Elem * AfterDel = Del->next;
   if(PrevDel != 0 && Count != 1)
      PrevDel->next = AfterDel;
    if(AfterDel != 0 && Count != 1)
      AfterDel->prev = PrevDel;
   if(pos == 1)
       Head = AfterDel;
   if(pos == Count)
       Tail = PrevDel;
   delete Del;
   Count--;
}
 
void List::Print()
{
   if(Count != 0)
   {
      Elem * temp = Head;
      while(temp->next != 0)
      {
          cout<< temp->data << " ";
          temp = temp->next;
      }
   }
}
 
void List::DelAll()
{
   while(Count != 0)
      Del(1);
}
 
int List::GetCount()
{
    return Count;
}
