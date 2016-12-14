#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "linkedlist.h"
using namespace std;

Node::Node(int value) {
	this->data = value;
	this->est_time=0; 
	this->next = NULL;
}

Node::Node(int value, double time) {
	this->data = value;
	this->est_time=time; 
	this->next = NULL;
}

LinkedList::LinkedList(){
	this->length = 0; 
	this->head = NULL;
}

LinkedList::~LinkedList(){
	Node *next_node=NULL;
	for (Node *node_ptr=this->head; node_ptr != NULL; node_ptr=next_node) {
		next_node = node_ptr->next; 
		delete node_ptr;
	}
 }

int LinkedList::size() const {
	return(this->length);
}

bool LinkedList::empty() const{
	return(this->length == 0);
}

void LinkedList::print() const{
	for (Node *node_ptr=this->head; node_ptr != NULL; node_ptr=node_ptr->next) {
		cout << node_ptr->data << " ";
	}
	cout << endl;
}

const char* LinkedList::tostring() const{
	string rep="[ ";
	for (Node *node_ptr=this->head; node_ptr != NULL; node_ptr=node_ptr->next) { 
		std::stringstream ss;
		ss << node_ptr->data;
		std::string str = ss.str();
		rep += str + " - ";
	}
	rep += " ]";
	return rep.c_str();
}

int LinkedList::at(int index) {
	if(index < 0 || index >= this->length) { 
		throw out_of_range("index out of bounds");
	}
	Node *node_ptr; 
	for (node_ptr=this->head; node_ptr != NULL; node_ptr=node_ptr->next) {
		if (index == 0) {
			break;
		}
		index--;
	}
	return node_ptr->data;
}

Node* LinkedList::find(int value) const{
	for (Node* node_ptr=this->head; node_ptr != NULL; node_ptr=node_ptr->next) { 
		if (node_ptr->data == value) {
			return node_ptr;
		} 
	}
	return NULL; 
}

bool LinkedList::contains(int value) const{ 
	Node* node_ptr=find(value); 
	return node_ptr != NULL; 
}

void LinkedList::append(int value) { 
	if (this->head == NULL) { 
		Node *new_node=new Node(value); 
		this->head = new_node; 
	} 
	else { 
		Node *last_node=NULL; 
		for (Node *node_ptr=this->head; node_ptr != NULL; node_ptr=node_ptr->next) { 
			last_node = node_ptr; 
		}
		Node *new_node=new Node(value); 
		last_node->next = new_node; 
	}
	this->length++;
}

void LinkedList::append_node(Node* nod){
	if (this->head == NULL) { 
		this->head = nod; 
	} 
	else { 
		Node *last_node=NULL; 
		for (Node *node_ptr=this->head; node_ptr != NULL; node_ptr=node_ptr->next) { 
			last_node = node_ptr; 
		}
		last_node->next = nod; 
	}
	this->length++;	
}

void LinkedList::prepend(int value) { 
	Node *new_node=new Node(value); 
	new_node->next = this->head; 
	this->head = new_node; 
	this->length++;
}

void LinkedList::remove(Node* target_node_ptr) {
	Node* prev_ptr=NULL; 
	Node *node_ptr;
	for (node_ptr=this->head; node_ptr != NULL && node_ptr != target_node_ptr; node_ptr=node_ptr->next) {
		prev_ptr = node_ptr;
	}
	if (node_ptr == NULL) { 
		throw target_node_ptr;
	} 
	else if (prev_ptr == NULL) { 
			this->head = target_node_ptr->next; 
			delete target_node_ptr;
		} 
		else {
			prev_ptr->next = target_node_ptr->next; 
			delete target_node_ptr;
		} 
}

void LinkedList::erase(int index) {
	if(index < 0 || index >= this->length) { 
		throw out_of_range("index out of bounds");
	}
	Node* prev_ptr=NULL; 
	Node *node_ptr;
	for (node_ptr=this->head; node_ptr != NULL; node_ptr=node_ptr->next) {
		if (index == 0) {
			break;
		}
		index--;
		prev_ptr = node_ptr;
	}
	if (prev_ptr == NULL) { 
		this->head = node_ptr->next; 
		delete node_ptr;
	} else {
		prev_ptr->next = node_ptr->next; 
		delete node_ptr;
	}
	length--;
}

double LinkedList::total_time() const{
	double sum=0;
	Node* node_ptr=NULL; 
	for (node_ptr=this->head; node_ptr != NULL; node_ptr=node_ptr->next) {
		sum += node_ptr->est_time;
	}
	return sum*2;
}

int LinkedList::last_ped() {
	int l = this->length;
	return this->at(l-1);
}

