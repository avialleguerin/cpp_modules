#ifndef DATA_HPP
# define DATA_HPP

#include <string>
#include <iostream>

class Data
{
	private:
		std::string name;

	public:
		Data();
		Data(std::string name);
		Data(const Data& src);
		~Data();
		Data& operator=(const Data& src);
		std::string getName() const;
};

std::ostream& operator<<(std::ostream& os, const Data& data);

#endif