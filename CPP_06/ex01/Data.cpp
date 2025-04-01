#include "Data.hpp"

Data::Data(): name("test") {}
Data::Data(std::string name) : name(name) {}

Data::Data(const Data& src) { *this = src; }

Data& Data::operator=(const Data& src) { (void)src; return *this; }

Data::~Data() {}

std::string Data::getName() const { return name; }

std::ostream& operator<<(std::ostream& os, const Data& data)
{
	os << "Data = " << "\"" << data.getName() << "\"";
	return os;
}