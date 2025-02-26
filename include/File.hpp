#ifndef FILE_HPP
#define FILE_HPP

#include "Node.hpp"
#include <iostream>

class File: public Node
{

	void refresh_updated_date() override;
public: 
	File(const std::string n = 0);
	~File() override = default;
	const std::string& get_name() const override;
	void print() const override;

	void set_name(const std::string& new_name);
};

#endif