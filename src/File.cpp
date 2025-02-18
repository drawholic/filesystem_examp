#include "File.hpp"



File::File(const std::string n): Node(FILE_TYPE, n){ 
	this->created_at = updated_at = std::time(0);
};
 
const std::string& File::get_name() 
{
	return name;
};
void File::set_name(const std::string& new_name)
{
	name = std::move(new_name);
};
void File::print() const
{
	std::cout << "Name: " << name << ", created at: " << std::ctime(&created_at) << ", " << std::endl;
};