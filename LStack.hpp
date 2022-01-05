#include "LStack.h"

namespace lein {
	template<typename T>
	inline LStack<T>::LStack()
	{
		shrink_to_fit(10);
	}

	template<typename T>
	inline LStack<T>::~LStack()
	{
		delete[] _data;
	}

	template<typename T>
	inline T LStack<T>::top()
	{
		// error occurred if _current_size <= -1
		if (empty())
			throw std::out_of_range("top() exception : stack is empty!");

		return _data[_current_size - 1];
	}

	template<typename T>
	inline void LStack<T>::push(const T& data)
	{
		// shrink to fit if current size is less than capacity
		if (_current_size >= _capacity) {
			shrink_to_fit(_capacity * 2);
		}
		
		_data[_current_size++] = data;
	}

	template<typename T>
	inline void LStack<T>::pop()
	{
		if (empty())
			throw std::out_of_range("top() exception : stack is empty!");

		--_current_size;
	}

	template<typename T>
	inline bool LStack<T>::empty()
	{
		return (_current_size == 0);
	}

	template<typename T>
	inline size_t LStack<T>::size()
	{
		return _current_size;
	}

	template<typename T>
	inline void LStack<T>::shrink_to_fit(size_t capacity)
	{
		if (_capacity > capacity)
			capacity = _capacity;

		T* tmp = new T[_current_size];
		for (size_t i = 0; i < _current_size; i++) {
			tmp[i] = _data[i];
		}

		_capacity = capacity;
		_data = new T[_capacity];
		for (size_t i = 0; i < _current_size; i++) {
			_data[i] = tmp[i];
		}
	}
}