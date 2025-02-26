#include "File.hpp"

File::File(const std::string n): Node(FILE_TYPE, n){ 
	this->created_at = updated_at = std::time(0);
};
 
const std::string& File::get_name() const
{
	return name;
};

void File::refresh_updated_date()
{
	updated_at = std::time(0);
};

void File::set_name(const std::string& new_name)
{
	name = std::move(new_name);
	refresh_updated_date();

};
void File::print(unsigned level) const
{
	std::string created(std::ctime(&created_at));
	std::string updated(std::ctime(&updated_at));

	created.pop_back();

	for(unsigned i = 0; i < level; i++)
	{
		std::cout << "   ";
	};
	std::cout << " - ";

	std::cout << get_name() << " | " << created << " | " << updated;
};

NodeType File::get_type() const
{
	return type;
};
