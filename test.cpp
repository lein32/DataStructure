#include <iostream>
#include "LStack.h"
using namespace std;

int main()
{
	lein::LStack<int> st;
	st.push(113);
	st.push(5);
	cout << "size : " << st.size() << '\n';
	cout << "top : " << st.top() << '\n';
	st.pop();
	cout << "size : " << st.size() << '\n';
	cout << "top : " << st.top() << '\n';
	st.pop();
	cout << "is empty : " << st.empty() << '\n';
	st.push(-9);
	cout << "is empty : " << st.empty() << '\n';
	return 0;
}