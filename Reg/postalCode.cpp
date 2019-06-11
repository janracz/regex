#include "postalCode.h"



void postalCode::readFile()
{
	std::ifstream file;
	file.open(fileName, std::ios::in);
	std::string error = "Nie mozna otwozyc pliku!";
	if (!file.good())
		throw error;
	else
	{
		std::regex rule("[[:digit:]]{2}-[0-9]{3}[[:space:]]");
		std::string word;
		while (getline(file,word))
		{
			std::smatch code;
			while (regex_search(word, code ,rule))
			{	
				for(auto & it:code)
				codesArr.push_back(it);
				
				word = code.suffix().str(); //Zwraca dalsz¹ czêœæ linijki po 1 dopasowaniu
			}
		}
	}
}

std::size_t postalCode::codeAmount()
{
	return codesArr.size();
}

postalCode::postalCode(std::string _fileName)
	:fileName(_fileName)
{
}

void postalCode::printCodes()
{
	for (auto& it : this->codesArr)
	{
		std::cout << it << std::endl;
	}
}
