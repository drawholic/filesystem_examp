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

void Directory::add_child(const std::string& name, NodeType type)
{
	Node* n;

	auto it = children.begin();
	auto pend = children.end();

	it = std::find_if(children.begin(), pend, [&name](Node* el){
		return el->get_name() == name;
	});
	if(it != pend)
	{
		std::cout << "There is already an file or directory with the name: " << name << std::endl;
		return;
	};

	switch(type)
	{
	case DIR_TYPE:
		n = new Directory(name);
		break;
	case FILE_TYPE:
		n = new File(name);
		break;
	default:
		return;
		break;
	};
	add_child(n);
};

void Directory::add_child(Node* child)
{
	if(child)
		children.push_back(child);
};