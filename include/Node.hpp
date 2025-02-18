#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <ctime>

enum NodeType
{
	DIR_TYPE,
	FILE_TYPE
};

class NodeAttributes
{
public:
	NodeType type;
	std::string name;
	std::time_t created_at;
	std::time_t updated_at;
};

class NodeMethods
{
public:
	virtual const std::string& get_name() = 0;
	virtual void print() const = 0; 
	virtual ~NodeMethods();
};

class Node: public NodeMethods, public NodeAttributes
{
	virtual const std::string& get_name() = 0;
	virtual void print() const = 0;
	// virtual ~Node();

};

#endif