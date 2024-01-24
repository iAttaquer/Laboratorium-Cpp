#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
class Napis
{
private:
	char *m_pszNapis;
	int m_nDl;

public:
	Napis(const char *nap = "");
	Napis(const Napis &wzor);
	~Napis();
	const char *Zwroc() const;
	void Ustaw(const char *nowy_napis);
	void Wypisz() const;
	void Wpisz();
	int SprawdzNapis(const char *por_napis) const;
	Napis &operator=(const Napis &wzor);
	bool operator==(const Napis &wzor) const;
	void operator+=(const char *n);
	friend std::ostream &operator<<(std::ostream &wy, const Napis &p);
	friend std::istream &operator>>(std::istream &we, Napis &p);
};
std::ostream &operator<<(std::ostream &wy, const Napis &p);
std::istream &operator>>(std::istream &we, Napis &p);