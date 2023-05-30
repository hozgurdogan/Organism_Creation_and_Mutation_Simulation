#ifndef Queuee_HPP
#define Queuee_HPP

#include <iostream>

template <typename T>
class Queue{
private:
	struct Node{
		T data;
		Node *next;
	};
	Node *head;
	Node *tail;
	int count;
public:
	Queue();
	~Queue();
	void enqueue(T data);
	T dequeue();
	T peek();
	int count();
	bool isEmpty();
};

template <typename T>
Queue<T>::Queue(){
	head=tail=NULL;
	count=0;
}
template <typename T>
Queue<T>::~Queue(){
	while(!isEmpty()){
		dequeue();
	}
}
template <typename T>
void Queue<T>::enqueue(T data){
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(isEmpty()){
		head = temp;
		tail = temp;
	}
	else{
		tail->next = temp;
		tail = temp;
	}
	count++;
}
template <typename T>
T Queue<T>::dequeue(){
	if(isEmpty()) throw "Queue is empty";
	Node *temp = head;
	head = head->next;
	count--;
	T data = temp->data;
	delete temp;
	return data;
}
template <typename T>
T Queue<T>::peek(){
	if(isEmpty()) throw "Queue is empty";
	return head->data;
}
template <typename T>
int Queue<T>::count(){
	return count;
}
template <typename T>
bool Queue<T>::isEmpty(){
	return head==NULL;
}

class Radix{
private:
	int *numbers;
	int length;
	Queue<int> **queues;
	int maxStep;
	int MaxStepNumber();
	int StepCount(int number);
	int power(int e);
	int *QueueCurrentLengths();
public:
	Radix(int *numbers, int length);
	~Radix();
	int* Sort();
};

#endif