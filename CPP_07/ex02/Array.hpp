#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
	private:
		T *_array;
		unsigned int _size;
	public:
		Array() : _array(new T[0]), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(Array const & src) : _array(new T[src._size]), _size(src._size) {}
		Array & operator=(Array const & src) { (void)src; return *this; }
		~Array() { delete[] _array; }
		size_t size() const { return _size; }

		T & operator[](unsigned int i) { return _array[i]; }

		class outOfRangeException : public std::exception {
			public:
				const char * what() const throw() { return "Array index out of range"; }
			};

};

#endif /* ARRAY_HPP */
