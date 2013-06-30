/**
 * implement a queue by two stacks
 */
#include <iostream>
#include <cstdio>
#include <stack>
#include <exception>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

template <typename T>
class CQueue{
	public:
		CQueue(void);
		~CQueue(void);
		
		void appendTail(const T& node);
		T deleteHead();
	private:
		stack<T> in;
		stack<T> out;
};

template<typename T> CQueue<T>::CQueue(void){}
template<typename T> CQueue<T>::~CQueue(void){}

template<typename T> void CQueue<T>::appendTail(const T& node){
	in.push(node);
}

template<typename T> T CQueue<T>::deleteHead(){
	if(out.size == 0){
		while(in.size > 0){
			T& element = in.top();
			out.push(element);
			in.pop();
		}
	}
	if(out.size == 0)
		throw new exception();
	T head = out.top();
	out.pop();
	return head;
}
