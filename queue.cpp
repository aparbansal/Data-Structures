//Queues using LL. FIFO structure.
#include<iostream>


class node
{
public:
	int data;
	node* link = NULL;
};

node* head = NULL;		// remove at head
node* tail = NULL;		// insert at tail

void Enqueue(int data_in)
{
	node* temp	= new node();
	temp->data	= data_in;
	
	if(head==NULL && tail==NULL)
	{
		head	= temp;
		tail	= temp;
		return;
	}
	
	tail->link	= temp;		//Changes current node's link from NULL to temp 
	tail		= temp;		//Resets tail to temp
}

void Dequeue()
{
	node* temp = head;
	
	if(head == NULL)			//Empty queue
	{
		std::cout << "ERROR: Nothing to pop...Returning from function...\n";
		return;
	}
	else if(head == tail)		//Only 1 element
	{
		head	= NULL;
		tail	= NULL;
	}
	else
	{
		head = temp->link;
	}
	
	delete temp;
}


int Front()
{
	if(head == NULL)
	{
		printf("ERROR: Queue is empty...Exiting...\n");
		exit(0);
	}
	return head->data;
}

void Print()
{
	node* temp = head;
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int main()
{
	/* Drive code to test the implementation. */
	// Printing elements in Queue after each Enqueue or Dequeue
	Enqueue(2);
	Print();
	Enqueue(4);
	Print();
	Enqueue(6);
	Print();
	Dequeue();
	Print();
	Enqueue(8);
	Print();
}