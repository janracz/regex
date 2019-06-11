#include "User.h"

user::user()
	:name("Unknown"),password("Unkonown")
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(1, 1000);
	id = distribution(generator);
}

