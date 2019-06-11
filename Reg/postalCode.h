#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include <iostream>
class postalCode
{
	std::string fileName; //Nazwa pliku.
	std::vector <std::string> codesArr; //Vector na kody pocztowe
public:
	void readFile(); //Funkcja odczytuj�ca kody.
	std::size_t codeAmount(); //Zwraca ilo�� kod�w w tablicy.
	postalCode(std::string _fileName); //Konstruktor
	void printCodes(); //Wyswietla wczytane kody.
	~postalCode()=default;
};

