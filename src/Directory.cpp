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
	std::string created(std::ctime(&created_at));
	created.pop_back();
	std::string updated(std::ctime(&updated_at));

	std::cout << get_name() << " | " << created << " | " << updated;
	for(auto i : children)
	{
		i->print();
	};
 
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

void Directory::remove_child(std::string n)
{
	auto it = children.begin();
	auto pend = children.end();

	it = std::find_if(it, pend, [&n](Node* el){
		return el->get_name() == n;
	});

	if(it != pend)
	{
		children.erase(it);
	};
};

void  Directory::remove_child(Node* el)
{
	if(el->get_type() == DIR_TYPE)
	{
		remove_directory(el);
	}else
	{
		children.remove(el);		
	}
};

void Directory::remove_children()
{
	for(auto i : children)
	{
		remove_child(i);
	};
};

void Directory::remove_directory(Node* el)
{
	Directory* dir = dynamic_cast<Directory*>(el);
	if(!dir->empty())
	{ 
		dir->remove_children();
	};
	delete dir;
	children.remove(dir);
};
 
bool Directory::empty()
{
	return children.empty();
};