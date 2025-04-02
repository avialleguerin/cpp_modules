#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

template <typename T>
class Array {
	private:
		T *_array;
		unsigned int _size;
	public:
		Array() : _array(new T[0]), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(Array const & src) : _array(new T[src._size]), _size(src._size)
		{
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
		}
		Array & operator=(Array const & src) {
			if (this != &src) {
				delete[] _array;
				_array = new T[src._size];
				_size = src._size;
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = src._array[i];
			}
			return *this;
		}
		~Array() { delete[] _array; }
		size_t size() const { return _size; }

		T & operator[](unsigned int i) {
			if (i >= _size)
				throw outOfRangeException();
			return _array[i]; }

		class outOfRangeException : public std::exception {
			public:
				const char * what() const throw() { return RED"Index out of range"RESET; }
		};

};

#endif /* ARRAY_HPP */
