struct Node                         
{
   int x, count=1;                
   Node *l,*r;                      
};

bool Check(Node *MyTree);
void Add(int x, Node *&MyTree);
void Delete(Node *&Tree);