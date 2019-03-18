#ifndef STACKQUEUE_H
#define STACKQUEUE_H

#include <iostream>
#include <string>


static int count;
	class Node
		{
		public:
			int nem;
			std::string name;
			int level;
			Node* up;
			Node* down;
			Node* left;
			Node* right;
			Node* next;
			Node* prev;
			Node* parent;
		
			Node()
			{
				nem = count++;
				up = NULL;
				down = NULL;
				left = NULL;
				right = NULL;
				next = NULL;
				prev = NULL;
				parent = NULL;
			}
			
			Node(std::string nam)
			{
				nem = count++;
				name = nam;
				up = NULL;
				down = NULL;
				left = NULL;
				right = NULL;
				next = NULL;
				prev = NULL;
				parent = NULL;
			}
			
			~Node()
			{
					std::cout<<"deleting "<<nem<<std::endl;
			}
		};
	
class StackQueue
{
	private:
	
		Node* tail;
		Node* head;
		
	public:
		StackQueue()
		{
			count = 0;
			tail  = NULL;
			head = NULL;
		}
	
		void addFront(Node* nodeptr)
		{
			nodeptr->prev = NULL;
			nodeptr->next = NULL;
			if(tail == NULL && head == NULL)
			{
				tail = nodeptr;
				head = nodeptr;
			}
			else
			{
				nodeptr->next = head;
				head->prev = nodeptr;
				head = nodeptr;
			}
		}

		Node* removeBest()
		{
			if(head == NULL)
			{
				return NULL;
			}
			else
			{
				Node* nodeptr = head;
				int l = 999999999;
				std::string n;
				while(nodeptr != NULL)
				{
					if(nodeptr->level < l)
					{
						l = nodeptr->level;
						n = nodeptr->name;
					}
					nodeptr = nodeptr->next;
				}


				nodeptr = head;
				if(head->name == n)
				{
					return removeFront();
				}
				else if(tail->name == n)
				{
					return removeBack();
				}
				else
				{
					while(nodeptr->name != n)
						nodeptr = nodeptr->next;

					Node* nextPtr = nodeptr->next;
					Node* prevPtr = nodeptr->prev;

					nodeptr->next = NULL;
					nodeptr->prev = NULL;

					nextPtr->prev = prevPtr;
					prevPtr->next = nextPtr;

					return nodeptr;
				}
				
			}
			
		}
		
		void addBack(Node* nodeptr)
		{
				nodeptr->prev = NULL;
			nodeptr->next = NULL;
			if(tail == NULL && head == NULL)
			{
				tail = nodeptr;
				head = nodeptr;
			}
			else
			{
				nodeptr->prev = tail;
				tail->next = nodeptr;
				tail = nodeptr;
			}
		}
		
		Node* removeFront()
		{
			Node* temp;
			if(tail == NULL && head == NULL)
			{
				return NULL;
			}
			else if(tail == head)
			{
				temp = head;
				head = NULL;
				tail = NULL;
				return temp;
			}
			else
			{
				temp = head;
				head = head->next;
				head->prev = NULL;
				return temp;
			}
		}
		
		Node* removeBack()
		{
			Node* temp;
			if(tail == NULL)
			{
				return NULL;
			}
			else if(tail == head)
			{
				temp = head;
				tail = NULL;
				head = NULL;
				return temp;
			}
			else
			{
				temp = tail;
				tail = tail->prev;
				tail->next = NULL;
				return temp;
			}
		}
		
	
		//~ if(x-1 >= 0)
				//~ {
					//~ cout<<"top";
				//~ }
				//~ if(x+1 < 3)
				//~ {
					//~ cout<<"bottom";
				//~ }
				//~ if(y-1 >= 0)
				//~ {
					//~ cout<<"letf";
				//~ }
				//~ if(y+1 < 3)
				//~ {
					//~ cout<<"right";
				//~ }
};

#endif