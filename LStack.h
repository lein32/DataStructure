#pragma once

namespace lein {
	template<typename T>
	class LStack {
	public:
		LStack();
		~LStack();

		T top();
		void push(const T&);
		void pop();
		bool empty();
		size_t size();

	private:
		T* _data;
		size_t _current_size;
		size_t _capacity;

		void shrink_to_fit(size_t capacity);
	};
}

#include "LStack.hpp"