#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include "Node.hpp"
#include "File.hpp"
#include <list>
#include <iostream>
#include <algorithm>

class Directory: public Node
{

	std::list<Node*> children;

	void refresh_updated_date() override;

public:

	Directory(const std::string n = 0);
	~Directory() override = default;

	NodeType get_type() const override;

	const std::string& get_name() const override;

	void add_child(Node*);
	void add_child(const std::string&, NodeType);

	void remove_child(std::string);
	void remove_child(Node*);
	
	void remove_children();

	void print() const override;

	void set_name(const std::string& new_name);

	void remove_directory(Node*);


	bool empty();
};

#endif