#include "Directory.hpp"



Directory::Directory(const std::string n): Node(DIR_TYPE, n)
{
	this->created_at = updated_at = std::time(0);
};

const std::string& Directory::get_name() const 
{
	return name;
};

void Directory::print() const
{
	std::cout << "Directory: " << get_name() << 
	"\ncreated_at: " << std::ctime(&created_at) <<
	"updated_at: " << std::ctime(&updated_at);
};

void Directory::refresh_updated_date() 
{
	updated_at = std::time(0);
};

void Directory::set_name(const std::string& new_name)
{
	name = std::move(new_name);
	refresh_updated_date();
};

NodeType Directory::get_type() const
{
	return type;
};