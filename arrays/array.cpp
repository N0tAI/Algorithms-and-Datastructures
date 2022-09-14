#include <iostream>
#include <array>

using namespace std;

template<typename T>
class Array {
private:
	size_t _capacity;
	size_t _length;
	T* _items;
	void ensure_capacity() {
		if (_length == _capacity) {
			resize_to(_capacity * 1.3);
		}
	}
	size_t binary_search(T item, size_t low, size_t high) {
		if (low > high)
			return -1;
		size_t mid = (low + high) / 2;
		if (_items[mid] == item)
			return mid;
		if (_items[mid] < T)
			return binary_search(mid + 1, high);
		else
			return binary_search(low, mid - 1);
	}
public:
	Array(size_t capacity) {
		_length = 0;
		_capacity = capacity;
		_items = new T[capacity];
	}
	Array() : Array(1) { }
	size_t size() {
		return _length;
	}
	void copy_to(Array<T> array) {
		if (_length > array._length)
			array.resize_to(_length);
		for (size_t i = 0; i < _length; i++)
			array.Add(this[i]);
	}
	void copy_to(T* array, size_t size) {
		for (size_t i = 0; i < size; i++)
			array[i] = _items[i];
	}
	void resize_to(size_t newCapacity) {
		if (_capacity == newCapacity)
			return;
		T* tmp = new _items[newCapacity];
		if(tmp != NULL)
			copy_to(tmp, newCapacity > _length ? _length : newCapacity);
		delete _items;
		_items = tmp;
	}
	void size_to_fit() {
		resize_to(_length);
	}
	void insert(T& item, size_t index) {
		if (index > _length)
			throw exception("Cannot insert beyond the end of the array");
		ensure_capacity();
		for (auto i = _length; i > index; i--)
			_items[i] = _items[i - 1];
		items[index] = item;
		_length++;
	}
	void append(T& item) {
		insert(item, _length);
	}
	void prepend(T& item) {
		insert(item, 0);
	}
	T delete_at(size_t index) {
		if (index >= _length)
			throw exception("Cannot delete beyond the end of the array");

		auto ret = _items[index];
		for (size_t i = index; i < _length - 1; i++)
			_items[i] = _items[i + 1];

		_length--;

		return ret;
	}
	size_t linear_search(T item) {
		// Best time complexity O(1)
		// Avg time complexity (n(n-1)) / 2 = O(n)
		// Wrst time complexity = O(n)

		// You can optimize this by moving the element one index down each time, reducing the case by 1 opt per however this falls apart if you expose indexes
		// Can also do this by moving the last searched value to the front of the array but has the same downfalls
		for (size_t i = 0; i < _length; i++)
			if (_items[i] == item)
				return i;
		return -1;
	}
	size_t binary_search(T item) {
		// Min time complexity O(1)
		// Max time complexity O(log2n)
		// Fail time complexity = log2(n-1) or O(log2n)
		// Average = sum(all cases(i * 2^i))/n = (log2n * 2 ^ log2n) / n = log2n 
		return binary_search(item, 0, length - 1);
	}
	T& get(size_t index) {
		if (index > _length)
			throw exception("Attempting to access outside of array boundaries.");
		return _items[index];
	}
	auto& operator[](size_t index) {
		return get(index);
	}
	void insert_sort(T item) {
		size_t i = _length - 1;
		ensure_capacity();
		while (i >= 0 && _items[i] > item) {
			_items[i + 1] = _items[i];
			i--;
		}
		_items[i + 1] = item;
		_length++;
	}

	// You know how to do min, max, average, sum, reverse, and shift/rotating
	bool is_sorted() {
		for (size_t i = 0; i < length - 2; i++)
			if (_items[i] > _items[i + 1])
				return false;
		return true;
	}

	// Set operations
	void union_with(Array<T>& second) {
		Array<T> arr(this->size() + second.size());

		arr.size_to_fit();
	}

	void intersection_with(Array<T>& second) {

	}

	void difference_with(Array<T>& second) {

	}
};