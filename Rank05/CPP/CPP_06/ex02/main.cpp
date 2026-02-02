#include "include/Base.hpp"
#include "include/A.hpp"
#include "include/B.hpp"
#include "include/C.hpp"
#include "include/baseUtils.hpp"

int main (void)
{
	srand(time(0));
	
	for (int i = 0; i < 4 ; i++)
	{
		std::cout << "--------------------------------" << std::endl;
		Base* object = generate();
		identify(object);
		identify(*object);
		delete object;
	}
	return 0;
}
