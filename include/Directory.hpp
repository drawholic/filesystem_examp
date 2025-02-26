#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include "Node.hpp"
#include <list>
#include <iostream>

class Directory: public Node
{

	std::list<Node*> children;

	void refresh_updated_date() override;

public:

	Directory(const std::string n = 0);
	~Directory() override = default;

	NodeType get_type() const override;

	const std::string& get_name() const override;

	void add_child();

	void remove_child(std::string);

	void print() const override;

	void set_name(const std::string& new_name);
};

#endif