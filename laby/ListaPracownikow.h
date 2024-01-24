#pragma once
// #include <iostream>
#include "Pracownik.h"
#include "Kierownik.h"

class ListaPracownikow
{
private:
	Pracownik *m_pPoczatek;
	int m_nLiczbaPracownikow;

public:
	ListaPracownikow();
	void Dodaj(const Pracownik &p);
	void Usun(const Pracownik &wzorzec);
	~ListaPracownikow();
	void WypiszPracownikow() const;
	const Pracownik *Szukaj(const char *nazwisko, const char *imie) const;
	void ZapisDoPliku() const;
	void OdczytZPliku();
};
