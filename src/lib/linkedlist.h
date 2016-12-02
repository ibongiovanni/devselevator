#ifndef LINKEDLIST_H_ 
#define LINKEDLIST_H_
#include <string>
class Node{ 
  public: 
	int data;
	Node* next; 
  public: 
  	Node(int value); 
};

class LinkedList{ 
	private:
	 	Node* head; 	 	
	 	int length;
	public:
	 	LinkedList(); 	 	
	 	~LinkedList();
	 	int size() const;
		bool empty() const; 
		void print() const; 
		const char* tostring() const; 
		int at(int index); 
		Node* find(int value) const; 
		bool contains(int value) const; 
		void append(int value); 
		void prepend(int value); 
		void remove(Node* node_ptr); 
		void erase(int index); 
};
#endif