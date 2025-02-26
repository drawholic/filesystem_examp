#include "Node.hpp"
#include <iostream>

class File: public Node
{

	void refresh_updated_date();
public: 
	File(const std::string n = 0);
	~File() override = default;
	const std::string& get_name() override;
	void print() const override;

	void set_name(const std::string& new_name);
};