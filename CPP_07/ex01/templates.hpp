#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>

template <typename T>
void iter(T *array, size_t len, void (*f)(T const &)) {
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}

template <typename T>
void print(T const &value) {
	std::cout << value << " ";
}

#endif /* TEMPLATES_HPP */
