#include "User.h"

user::user()
	:name("Unknown"),password("Unkonown")
{
	//Losowanie 2 opcje

	/*srand(time(NULL));
	id = rand() % 1000 + 100;*/

	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(1, 1000);
	id = distribution(generator);
}

bool user::setPassword(std::string _password)
{
	//Warning w przypadku klass podwojne nawiasy
	std::regex rule("[a-z]+[A-Z]+[[:digit:]]+[[:punct:]]{1}"); //Litera ma³¹ litera du¿ min. 1 cyfra min 1 i jeden znak przestankowy 
	if (std::regex_match(_password, rule))
	{
		password = _password;
		return true;
	}
	else
		return false;
}

bool user::setName(std::string _name)
{
	std::regex rule("([[:lower:]]?[[:digit:]]{3})|([[:upper:]]{2,}[[:digit:]]{4,6})");
	if (std::regex_match(_name, rule))
	{
		name = _name;
		return true;
	}
	else
		return false;
}

