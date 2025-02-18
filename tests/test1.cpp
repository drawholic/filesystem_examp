#include "File.hpp"
#include <cassert>
#include <cstring>
#include <string>
void test();

int main(int argc, char const *argv[])
{
	test(); 

	/* code */
	return 0;
}


void test()
{

	std::string fname = "hello";
	std::string new_name = "hello new";
	File* f = new File(fname);

	assert(strcmp(fname.c_str(), f->get_name().c_str()) == 0);

	f->set_name(new_name);

	assert(strcmp(new_name.c_str(), f->get_name().c_str()) == 0);


	delete f;
};