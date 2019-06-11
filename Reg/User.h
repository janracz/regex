#pragma once
#include <string>
#include <random>
#include <regex>

class user
{
	int id;
	std::string name;
	std::string password;

public:
	user();
	bool setPassword(std::string _password); //Ustawia has�o zgodnie z wytycznymi wyra�enia regularnego.
	bool setName(std::string _name); //Ustawia imie zgodnie z wytycznymi wyra�enia regularnego.
	~user() = default;
};

