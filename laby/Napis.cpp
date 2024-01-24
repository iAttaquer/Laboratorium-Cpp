#include "Napis.h"
#include <cstring>
#include <iostream>

Napis::Napis(const char *nap)
{
	this->m_nDl = strlen(nap);
	this->m_pszNapis = new char[this->m_nDl + 1];
	strcpy(this->m_pszNapis, nap);
}
Napis::Napis(const Napis &wzor)
{
	this->m_nDl = wzor.m_nDl;
	this->m_pszNapis = new char[wzor.m_nDl + 1];
	strcpy(this->m_pszNapis, wzor.m_pszNapis);
}
Napis::~Napis()
{
	if (this->m_pszNapis)
		delete[] this->m_pszNapis;
	this->m_pszNapis = nullptr;
	this->m_nDl = 0;
}
const char *Napis::Zwroc() const
{
	return this->m_pszNapis;
}
void Napis::Ustaw(const char *nowy_napis)
{
	delete[] this->m_pszNapis;
	this->m_nDl = strlen(nowy_napis) + 1;
	this->m_pszNapis = new char[this->m_nDl];
	strcpy(this->m_pszNapis, nowy_napis);
}
void Napis::Wypisz() const
{
	std::cout << this->Zwroc() << std::endl;
}
void Napis::Wpisz()
{
	char nowy[40];
	std::cout << "Podaj napis: ";
	std::cin >> std::ws;
	std::cin.get(nowy, 40, '\n');
	std::cin.get();
	this->Ustaw(nowy);
}
int Napis::SprawdzNapis(const char *por_napis) const
{
	char *pierwszy = new char[strlen(this->m_pszNapis) + 1];
	char *drugi = new char[strlen(por_napis) + 1];
	strcpy(pierwszy, this->m_pszNapis);
	strcpy(drugi, por_napis);
	for (int i = 0; pierwszy[i] != '\0'; i++)
		pierwszy[i] = toupper(pierwszy[i]);
	for (int i = 0; drugi[i] != '\0'; i++)
		drugi[i] = toupper(drugi[i]);
	int wynik = strcmp(pierwszy, drugi);
	delete[] pierwszy;
	delete[] drugi;
	return wynik;
}
Napis &Napis::operator=(const Napis &wzor)
{
	if (this == &wzor)
		return *this;
	delete[] this->m_pszNapis;
	this->m_pszNapis = new char[wzor.m_nDl+1];
	strcpy(this->m_pszNapis, wzor.m_pszNapis);
	this->m_nDl = wzor.m_nDl;
	return *this;
}
bool Napis::operator==(const Napis &wzor) const
{
	if (this->SprawdzNapis(wzor.Zwroc()) == 0)
		return true;
	else
		return false;
}
void Napis::operator+=(const char *n)
{
	if (n == nullptr || *n == '\0')
		return;
	if (this->m_pszNapis == nullptr)
	{
		this->m_nDl = strlen(n);
		this->m_pszNapis = new char[this->m_nDl + 1];
		strcpy(this->m_pszNapis, n);
	}
	else
	{
		this->m_nDl += strlen(n);
		char *ns = new char[this->m_nDl + 1];
		strcpy(ns, this->m_pszNapis);
		strcat(ns, n);
		delete[] this->m_pszNapis;
		this->m_pszNapis = ns;
	}
}
std::ostream &operator<<(std::ostream &wy, const Napis &p)
{
	return wy << p.m_pszNapis;
}
std::istream &operator>>(std::istream &we, Napis &p)
{
	// char temp[256];
	// char znak;
	// int i = 0;
	// we >> std::ws;
	// while (we.get(znak) && znak != ' ' && znak != '\n')
	p.Ustaw("");
	char znak[2];
	we >> std::ws;
	// we.get(znak, 1, ' ');
	// znak[1] = '\0';
	// p.Ustaw(znak);
	while (true)
	{
		znak[0] = we.get();
		if (znak[0] == ' ' || znak[0] == '\n')
			break;
		znak[1] = '\0';
		p += znak;
	}
	// we.get(); //'\n'
	return we;
}