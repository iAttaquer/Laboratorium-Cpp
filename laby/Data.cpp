#include "Data.h"
#include <iostream>

Data::Data(int d, int m, int r)
{
	this->m_nDzien = d;
	this->m_nMiesiac = m;
	this->m_nRok = r;
	this->Koryguj();
}
void Data::Ustaw(int d, int m, int r)
{
	this->m_nDzien = d;
	this->m_nMiesiac = m;
	this->m_nRok = r;
	Koryguj();
}
int Data::Dzien() const
{
	return this->m_nDzien;
}
int Data::Miesiac() const
{
	return this->m_nMiesiac;
}
int Data::Rok() const
{
	return this->m_nRok;
}
void Data::Wypisz() const
{
	std::cout << Dzien() << "-"
			  << Miesiac() << "-"
			  << Rok() << std::endl;
}
void Data::Wpisz()
{
	std::cout << "Podaj dzien: ";
	std::cin >> this->m_nDzien;
	std::cout << "Podaj miesiac: ";
	std::cin >> this->m_nMiesiac;
	std::cout << "Podaj rok: ";
	std::cin >> this->m_nRok;
	Koryguj();
}
void Data::Koryguj()
{
	if (this->m_nMiesiac > 12)
	{
		this->m_nMiesiac = 12;
	}
	if (this->m_nDzien > 31)
	{
		this->m_nDzien = 31;
	}
	if (this->m_nRok % 4 == 0)
	{
		if (this->m_nMiesiac == 2)
			if (this->m_nDzien > 29)
				this->m_nDzien = 29;
	}
	else
	{
		if (this->m_nMiesiac == 2)
			if (this->m_nDzien > 28)
				this->m_nDzien = 28;
	}
}
int Data::Porownaj(const Data &wzor) const
{
	if (wzor.Dzien() == this->Dzien() && wzor.Miesiac() == this->Miesiac() && wzor.Rok() == this->Rok())
		return 0;
	if (wzor.Rok() > this->Rok())
		return 1;
	if (wzor.Rok() == this->Rok())
	{
		if (wzor.Miesiac() > this->Miesiac())
			return 1;
		if (wzor.Miesiac() == this->Miesiac())
		{
			if (wzor.Dzien() > this->Dzien())
				return 1;
			else
				return -1;
		}
	}
	return -1;
}
std::ostream &operator<<(std::ostream &wy, const Data &d)
{
	return wy << d.Dzien() << ' ' << d.Miesiac() << ' ' << d.Rok();
}
std::istream &operator>>(std::istream &we, Data &d)
{
	if (&we == &std::cin)
	{
		std::cout << "Podaj dzien: ";
		we >> d.m_nDzien;
		std::cout << "Podaj miesiac: ";
		we >> d.m_nMiesiac;
		std::cout << "Podaj rok: ";
		we >> d.m_nRok;
	}
	else
	{
		we >> d.m_nDzien;
		we >> d.m_nMiesiac;
		we >> d.m_nRok;
	}
	d.Koryguj();
	return we;
}