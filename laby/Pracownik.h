#pragma once
#include "Napis.h"
#include "Data.h"
#include <iostream>

class Pracownik
{
private:
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
	const int m_nIDZatrudnienia;

public:
	static int statyczna;
	Pracownik *m_pNastepny = nullptr;
	Pracownik(const char *im = "", const char *naz = "", int dzien = 1,
			  int miesiac = 1, int rok = 2000);
	Pracownik(const Pracownik &wzor);
	virtual ~Pracownik();
	const char *Imie() const { return this->m_Imie.Zwroc(); }
	const char *Nazwisko() const { return this->m_Nazwisko.Zwroc(); }
	void Imie(const char *nowe_imie);
	void Nazwisko(const char *nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void Wypisz() const;
	void Wpisz();
	int SprawdzImie(const char *por_imie) const;
	int SprawdzNazwisko(const char *por_nazwisko) const;
	int Porownaj(const Pracownik &wzorzec) const;
	Pracownik &operator=(const Pracownik &wzor);
	bool operator==(const Pracownik &wzor) const;
	friend std::ostream &operator<<(std::ostream &wy, const Pracownik &p);
	friend std::istream &operator>>(std::istream &we, Pracownik &p);
	virtual void WypiszDane();
	virtual Pracownik* KopiaObiektu()const;
};
std::ostream &operator<<(std::ostream &wy, const Pracownik &p);
std::istream &operator>>(std::istream &we, Pracownik &p);