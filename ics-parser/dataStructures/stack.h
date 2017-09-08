/*
 * stack.h
 *
 *  Created on: Feb 26, 2015
 *      Author: 7cm5_000
 */

#ifndef STACK_H_
#define STACK_H_

#include <vector>
#include <stdexcept>

using namespace std;

class EmptyStackException : public runtime_error {
public:
	EmptyStackException() :
		runtime_error("Attempted to pop element from empty stack.") {}
};

template <class T>
class Stack {
private:
	vector<T> stack;
public:
	void push(const T& element);
	T pop() throw (EmptyStackException);
	T peak() throw (EmptyStackException);
	bool isEmpty();
	int getSize();
};

template <class T>
void Stack<T>::push(const T& element) {
	stack.push_back(element);
}

template <class T>
T Stack<T>::pop() throw (EmptyStackException) {
	if (stack.size() <= 0) throw EmptyStackException();

	T element = stack.back();
	stack.pop_back();
	return element;
}

template <class T>
T Stack<T>::peak() throw (EmptyStackException) {
	if (stack.size() <= 0) throw EmptyStackException();

	T element = stack.back();
	return element;
}

template <class T>
bool Stack<T>::isEmpty() {
	return stack.size() == 0;
}

template <class T>
int Stack<T>::getSize(){
	return stack.size();
}

#endif /* STACK_H_ */
