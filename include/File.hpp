#include "Node.hpp"
#include <iostream>

class File: private Node
{

public:
	// File();
	File(std::string);
	~File();
	const std::string& get_name() override;
	void print() const override;
};