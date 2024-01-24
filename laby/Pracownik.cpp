#include "Pracownik.h"
#include <iostream>
#include <cstring>
#include <cctype>

int Pracownik::statyczna = 0;

Pracownik::Pracownik(const char *im, const char *naz, int dzien,
					 int miesiac, int rok)
	: m_Imie(im), m_Nazwisko(naz), m_DataUrodzenia(dzien, miesiac, rok), m_nIDZatrudnienia(++statyczna) {}
Pracownik::Pracownik(const Pracownik &wzor)
	: m_DataUrodzenia(wzor.m_DataUrodzenia), m_nIDZatrudnienia(wzor.m_nIDZatrudnienia)
{
	this->m_Imie = wzor.m_Imie;
	this->m_Nazwisko = wzor.m_Nazwisko;
	this->m_DataUrodzenia = wzor.m_DataUrodzenia;
}
Pracownik::~Pracownik() // destruktor
{
	statyczna--;
	this->m_pNastepny = nullptr;
}
void Pracownik::Imie(const char *nowe_imie)
{
	this->m_Imie.Ustaw(nowe_imie);
}
void Pracownik::Nazwisko(const char *nowe_nazwisko)
{
	this->m_Nazwisko.Ustaw(nowe_nazwisko);
}
void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	this->m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}
void Pracownik::Wypisz() const
{
	std::cout << this->m_nIDZatrudnienia << "\t"
			  << this->m_Imie.Zwroc() << "\t"
			  << this->m_Nazwisko.Zwroc() << "\t"
			  << this->m_DataUrodzenia << std::endl;
}
void Pracownik::Wpisz()
{
	std::cout << "Podaj imie pracownika: " << std::endl;
	this->m_Imie.Wpisz();
	std::cout << "Podaj nazwisko pracownika: " << std::endl;
	this->m_Nazwisko.Wpisz();
	std::cout << "Podaj date urodzenia: " << std::endl;
	this->m_DataUrodzenia.Wpisz();
}
int Pracownik::SprawdzImie(const char *por_imie) const
{
	return m_Imie.SprawdzNapis(por_imie);
}
int Pracownik::SprawdzNazwisko(const char *por_nazwisko) const
{
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}
int Pracownik::Porownaj(const Pracownik &wzorzec) const
{
	if (this->SprawdzNazwisko(wzorzec.m_Nazwisko.Zwroc()) == 0)
	{
		if (this->SprawdzImie(wzorzec.m_Imie.Zwroc()) == 0)
			return 0;
		else
			return this->SprawdzImie(wzorzec.m_Imie.Zwroc());
	}
	else
		return this->SprawdzNazwisko(wzorzec.m_Nazwisko.Zwroc());
}
Pracownik &Pracownik::operator=(const Pracownik &wzor)
{
	if (this == &wzor)
		return *this;
	this->m_Imie = wzor.m_Imie;
	this->m_Nazwisko = wzor.m_Nazwisko;
	this->m_DataUrodzenia = wzor.m_DataUrodzenia;
	return *this;
}
bool Pracownik::operator==(const Pracownik &wzor) const
{
	if (this->Porownaj(wzor) == 0)
		return true;
	else
		return false;
}
std::ostream &operator<<(std::ostream &wy, const Pracownik &p)
{
	return wy << p.m_nIDZatrudnienia << ' '
			  << p.m_Imie << ' '
			  << p.m_Nazwisko << ' '
			  << p.m_DataUrodzenia;
}
std::istream &operator>>(std::istream &we, Pracownik &p)
{
	if (&we == &std::cin)
	{
		std::cout << "Podaj imie: " << std::endl;
		we >> p.m_Imie;
		std::cout << "Podaj nazwisko: " << std::endl;
		we >> p.m_Nazwisko;
		std::cout << "Podaj date urodzenia: " << std::endl;
		we >> p.m_DataUrodzenia;
	}
	else
	{
		we >> p.m_Imie;
		we >> p.m_Nazwisko;
		we >> p.m_DataUrodzenia;
	}
	return we;
}
void Pracownik::WypiszDane()
{
	std::cout << "[ID]: " << this->m_nIDZatrudnienia << ' '
			  << "[Nazwisko]: " << this->m_Nazwisko << ' '
			  << "[Imie]: " << this->m_Imie << ' '
			  << "[Data Urodzenia]: " << this->m_DataUrodzenia << ' ';
}
Pracownik *Pracownik::KopiaObiektu() const
{
	return new Pracownik(*this);
}