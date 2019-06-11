#include <iostream>
#include "User.h"
#include"Zadania.h"
#include "postalCode.h"


void regexReplace(std::string text)
{
	std::regex rule1("a{2}bc{1,2}"); //Na in
	std::regex rule2("abc{3,}"); //Na v
	std::regex rule3("[A-Z][[:digit:]][:punct:]"); //Na itas
	std::regex rule4("[[:upper:]]{2}[[:digit:]]{3,}"); //Na a
	std::string result;

	result= regex_replace(text, rule1, "in");
	result= regex_replace(result, rule2, "v");
	result= regex_replace(result, rule3, "itas");
	result= regex_replace(result, rule4, "a");

	std::cout << result << std::endl;
}
void regexReplace1(std::string text)
{
	std::vector <std::regex> rules;
	rules.push_back(std::regex("a{2}bc{1,2}"));
	rules.push_back(std::regex("abc{3,}"));
	rules.push_back(std::regex("[A-Z][[:digit:]][[:punct:]]"));
	rules.push_back(std::regex("[[:upper:]]{2}[[:digit:]]{3,}"));
	std::string replace[] = { "in","v","itas","a" };

	for (int i = 0; i < 4; i++)
	{
		text =regex_replace(text, rules[i], replace[i]);
	}

	std::cout << text << std::endl;
}
void countWords()
{
	std::regex wordRule("[^\\s]+");
	auto beginning = std::sregex_iterator(student.begin(), student.end(), wordRule);
	auto end = std::sregex_iterator();

	std::cout << "Ilosc slow: " << std::distance(beginning, end) << std::endl;
	std::cout << "Slowa:" << std::endl;
	
	for (auto it = beginning; it != end; it++)
	{
		std::smatch match = *it;
		std::cout << match.str() << std::endl;
	}
}




int main()
{
///Zadanie 1
	user u1;
	{
		int good = 0; //Dobre haslo
		int bad = 0; //Zle haslo
		for (int i = 0; i < PASS; i++)
		{
			bool result= u1.setPassword(password[i]);
		
				if (result)
					good++;
				else if (!result)
					bad++;
		}
		std::cout << "Hasla poprawne: " << good << std::endl;
		std::cout << "Hasla zle: " << bad << std::endl;
	}
	{
		int good = 0; //Dobre haslo
		int bad = 0; //Zle haslo
		for (int i = 0; i < LOG; i++)
		{
			bool result = u1.setName(login[i]);

			if (result)
				good++;
			else if (!result)
				bad++;
		}
		std::cout << "Loginy poprawne: " << good << std::endl;
		std::cout << "Loginy zle: " << bad << std::endl;
	}
	std::regex rx;
	std::string napis;
	std::string zmiana;
	std::smatch wynik;

	
	
///Zadanie 2
	postalCode p1(POST);
	try { p1.readFile(); }
	catch (std::string error)
	{
		std::cout << error << std::endl;
	}
	std::cout << "Ilosc odczytanych kodow: " << p1.codeAmount() << std::endl;
	p1.printCodes();

///Zadanie 3
	regexReplace1(TEXT);

///Zadanie 4
	countWords();
	
	return 0;
}
