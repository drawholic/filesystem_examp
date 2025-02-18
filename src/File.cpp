#include "File.hpp"



File::File(std::string n = 0){
	name = n;
	created_at = std::time(0);
	updated_at = std::time(0);
};
 

File::~File()
{

};

const std::string& File::get_name() 
{
	return name;
};

void File::print() const
{
	std::cout << "Name: " << name << ", ";
};