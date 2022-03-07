#ifndef __Queue_defined__
#define __Queue_defined__

#include <iostream>
#include <string>
#include <exception>

enum class Priority { low, medium, high };
class Queue
{
public:
	Queue();
	Queue(const Queue& other);
	Queue& operator=(const Queue& other);
	Queue(Queue&& other) noexcept;
	Queue& operator= (Queue&& other) noexcept;
	~Queue();

	void push(int DATA, Priority priority);
	void pop();
	void clear();

	int size() const;
	int size_low() const;
	int size_medium() const;
	int size_high() const;

	bool empty();

	std::string front_priority();
	int front_value();

	friend std::ostream& operator<< (std::ostream& out, const Queue& current);

private:
	struct Node {
		Node* next = nullptr;
		int data;
		Priority priority;
	};
	Node* head;
	Node* rear_high;
	Node* rear_medium;
	Node* rear_low;
	int size_ = 0;
	int size_l = 0;
	int size_m = 0;
	int size_h = 0;
	void Clone(const Queue& other);
	void Move(Node*& a, Node*& b) noexcept;
	void Insert(Node*& a, Node*& b) noexcept;
};
#endif
