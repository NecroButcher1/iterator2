#pragma once
#include <iostream>
template<typename T>
class list {
private:
	struct node
	{
		T data;
		node* next;
	};
	node* ptr;
	size_t s;
public:
	class iterator {
	private:
		 list* tmp;
		size_t idx;
	public:
		iterator() :tmp(nullptr), idx(0) {};
		iterator(list<T>* in,size_t idx) :tmp(in),idx(idx) {};
		iterator& operator++() {
			tmp->ptr = tmp->ptr->next;
			idx++;
			return *this;
		}
		iterator& operator=(const iterator* in) {
			*this = *(new iterator(in));
			return *this;
		}
		T operator* () {
			return tmp->ptr->data;
		}
		const bool operator==(const iterator equal) {
			return ((tmp->ptr->data == equal.tmp->ptr->data)&&(idx==equal.idx));
		}
		const bool operator!=(const iterator noequal) {
			return !operator==(noequal);
		}
		const bool end() {
			return tmp->empty();
		}
	};
	list() :ptr(nullptr), s(0) {};
	list(const list<T>* in){
		while (!in->empty) {
			this->push(in->top);
			in->pop();
		}
	}
	list& operator=(const list<T>* in) {
		*this = *(new list(in));
		return *this;
	}
	const bool operator==(const list<T>* in) {
		 list<T>* kek(*this);	
		 list<T>* lol(in);
		 if (kek->size() != lol->size())return false;
		 bool flag(true);
		 while (!kek->empty() and lol->empty()) {
			 if (kek->top() != lol->top())flag = true;
		}
		 return flag;
	}
	void push(T data) {
		node* new_node = new node;
		new_node->next = ptr;
		new_node->data = data;
		s++;
		ptr = new_node;
	}
	void pop() {
		if (!empty()) {
			ptr = ptr->next;
			s--;
		}
	}
	size_t size() {
		return s;
	}
	T top() {
		return ptr->data;
	}
	const bool empty() {
		return !ptr;
	}
	iterator end() {
		list<T>* buff(this);
		while (buff->ptr->next != nullptr)buff->ptr=buff->ptr->next;
		return *(new iterator(buff,buff->size()));
	}
	iterator begin() {
		return *(new iterator(this,s));
	}
};