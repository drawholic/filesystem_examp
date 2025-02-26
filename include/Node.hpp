#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <ctime>

enum NodeType
{
	DIR_TYPE,
	FILE_TYPE
};

struct NodeAttributes
{
	NodeType type;
	std::string name;
	std::time_t created_at;
	std::time_t updated_at;
	NodeAttributes(NodeType t, std::string n): type(t), name(std::move(n)){
		created_at = updated_at = std::time_t(0);
	};
};

class NodeMethods
{
public:
	virtual const std::string& get_name() const = 0;
	virtual void print(unsigned) const = 0; 
	virtual ~NodeMethods() = default;
	virtual void refresh_updated_date();
	virtual NodeType get_type() const;
};

class Node: public NodeMethods, public NodeAttributes
{
public: 
	Node(NodeType t, std::string n): NodeAttributes(t, n){};
	~Node() override;
};

#endif