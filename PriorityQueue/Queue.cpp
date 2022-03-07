#include "Queue.h"

Queue::Queue() {										//constructor without parameters
	head = nullptr;
	rear_high = nullptr;
	rear_medium = nullptr;
	rear_low = nullptr;
}

Queue::Queue(const Queue& other) {					//copy constructor
	clear();
	Clone(other);
}

Queue& Queue::operator=(const Queue& other) {		//copy operator
	if (this != &other) {
		clear();
		Clone(other);
	}
	return *this;
}

Queue::Queue(Queue&& other) noexcept {				//move constructor
	Move(head, other.head);
}

Queue& Queue::operator= (Queue&& other) noexcept {	//move operator
	if (this != &other) {
		clear();
		Move(head, other.head);
	}
	return *this;
}

Queue::~Queue() {									//destructor
	clear();
}

void Queue::Insert(Node*& a, Node*& b) noexcept {
	a->next = b;
	b = a;
}

void Queue::Move(Node*& a, Node*& b) noexcept {
	a = b;
	b = nullptr;
}

void Queue::push(int DATA, Priority priority) {
	Node* element = new Node;
	element->data = DATA;
	element->priority = priority;
	size_++;
	switch (priority) {
	case Priority::high: {
		if (rear_high != nullptr) {
			Insert(element, rear_high->next);
		}
		else {
			Insert(element, head);
		}
		rear_high = element;
		size_h++;
		break;
	}
	case Priority::medium: {
		if (rear_medium != nullptr) {
			Insert(element, rear_medium->next);
		}
		else if (rear_high != nullptr) {
			Insert(element, rear_high->next);
		}
		else {
			Insert(element, head);
		}
		rear_medium = element;
		size_m++;
		break;
	}
	case Priority::low: {
		if (rear_low != nullptr) {
			Insert(element, rear_low->next);
		}
		else if (rear_medium != nullptr) {
			Insert(element, rear_medium->next);
		}
		else if (rear_high != nullptr) {
			Insert(element, rear_high->next);
		}
		else {
			Insert(element, head);
		}
		rear_low = element;
		size_l++;
		break;
	}
	}
}

void Queue::pop() {
	if (size_ == 0) {
		throw std::exception("ERROR: queue was empty before pop");
	}

	Node* element = head;
	switch (element->priority) {
	case Priority::high: {
		size_h--;
		break;
	}
	case Priority::medium: {
		size_m--;
		break;
	}
	case Priority::low: {
		size_l--;
		break;
	}
	}

	if (size_ == 1) {
		head = nullptr;
	}
	else {
		head = head->next;
	}
	delete element;
	size_--;
}

void Queue::Clone(const Queue& other) {
	Node* element = other.head;
	while (element != nullptr) {
		push(element->data, element->priority);
		element = element->next;
	}
}

void Queue::clear() {
	Node* element = head;
	while (element != nullptr) {
		element = element->next;
		pop();
	}
	rear_high = nullptr;
	rear_medium = nullptr;
	rear_low = nullptr;
	head = nullptr;
}

int Queue::size() const {
	return size_;
}

int Queue::size_low() const {
	return size_l;
}

int Queue::size_medium() const {
	return size_m;
}

int Queue::size_high() const {
	return size_h;
}

bool Queue::empty() {
	return size_ == 0;
}

int Queue::front_value() {
	if (empty()) {
		throw std::exception("ERROR: queue is empty");
	}
	return head->data;
}

std::string Queue::front_priority() {
	if (empty()) {
		throw std::exception("ERROR: queue is empty");
	}
	switch (head->priority) {
	case Priority::high: return "HIGH";
	case Priority::medium: return "MEDIUM";
	case Priority::low: return "LOW";
	}
}

std::ostream& operator<< (std::ostream& out, const Queue& current) {
	Queue::Node* element = current.head;
	out << "( ";
	while (element != nullptr) {
		out << element->data << " ";
		element = element->next;
	}
	out << ")";
	return out;
}
