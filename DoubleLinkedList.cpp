#include <iostream>
using namespace std;
struct node
{
	int val;
	node *nxt, *prv;
	node(int v)
		{
		val= v;
		nxt= prv= NULL;
		}
};

class DoubleList
{
node *front, *back;
public:
	DoubleList()
		{front= back = NULL;}
	~DoubleList() {destroyList();}
	void addNodeFront(int item);
	void addNodeBack(int item);
	void delNodeFront();
	void delNodeback();
	void delNodeMiddle(int data);
	void displayNodeForward(void);
	void displayNodeReverse(void);
	void destroyList();
};
void DoubleList::delNodeMiddle(int data)
{
if(front== NULL) return;
else{
	node *temp= front;
	while(temp->val != data)
	temp= temp->nxt;
			
	/* if(temp->prv == NULL) delNodeFront();
	else if(temp->nxt == NULL) delNodeback();
	 */		
	temp->prv->nxt = temp->nxt;
	temp->nxt->prv = temp->prv;
	delete temp;
	}
}

void DoubleList::delNodeFront()
{
node *temp= front;
	if(front != NULL)
		{
		front= front->nxt;
		front->prv= NULL;
		}
	delete temp; 
return;
}

void DoubleList::delNodeback()
{
node *temp= back;
	if(back != NULL)
		{
		back= back->prv;
		back->nxt= NULL;
		}
	delete temp;
	
return;
}

void DoubleList::addNodeFront(int item)
{
	node *ptr= new node(item);
	if(front == NULL) { front= back= ptr; }
		else
		{
		ptr->nxt= front;
		front->prv= ptr;
		front= ptr;
		}
}

void DoubleList::addNodeBack(int item)
{
	node *ptr= new node(item);
	if(back== NULL) { front= back= ptr; }
	else
	{
	ptr->prv= back;
	back->nxt= ptr;
	back= ptr;	
	}
}

void DoubleList::displayNodeForward()
{
node *temp= front;
cout<<"\nnodes in forward order: ";
	while(temp != NULL)
	{
	cout<<" "<<temp->val;
	temp= temp->nxt;
	}
}

void DoubleList::displayNodeReverse()
{
node *temp= back;
cout<<"\nnodes in backward order: ";
	while(temp != NULL)
		{
		cout<<" "<<temp->val;
		temp= temp->prv;
		}
}

void DoubleList::destroyList()
{
	while(front != NULL)
		{
		node *temp= front;
		front= front->nxt;
		delete temp;
		}
front= back= NULL;
cout<<"\nWhole list destroyed!!";
}

int main()
{
int data;
DoubleList *list= new DoubleList;
list->addNodeFront(1);
list->addNodeFront(3);
list->addNodeFront(5);
list->addNodeFront(7);
list->displayNodeForward();
list->addNodeBack(11);
list->addNodeBack(22);
list->addNodeBack(33);
list->displayNodeForward();
list->displayNodeReverse();

list->delNodeFront();
list->delNodeback();
cout<<"\nafter delete front\n";
list->displayNodeForward();

cout<<"\nenter data to delete: ";
cin>>data;
list->delNodeMiddle(data);
list->displayNodeForward();
delete list;


return 0;
}