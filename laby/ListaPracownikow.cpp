#include "ListaPracownikow.h"
#include <cstring>
#include <fstream>
#include <thread>

ListaPracownikow::ListaPracownikow()
{
	this->m_pPoczatek = nullptr;
	this->m_nLiczbaPracownikow = 0;
}
void ListaPracownikow::Dodaj(const Pracownik &p)
{
	Pracownik *kopia = new Pracownik();
	kopia = p.KopiaObiektu();
	if (this->m_pPoczatek == nullptr)
	{
		this->m_pPoczatek = kopia;
		this->m_nLiczbaPracownikow++;
		return;
	}
	else if (this->m_pPoczatek->Porownaj(p) > 0)
	{
		kopia->m_pNastepny = this->m_pPoczatek;
		this->m_pPoczatek = kopia;
		this->m_nLiczbaPracownikow++;
		return;
	}
	Pracownik *obecny = this->m_pPoczatek;
	while (true)
	{
		if (obecny->Porownaj(p) == 0)
		{
			delete kopia;
			return;
		}
		else if (obecny->m_pNastepny == nullptr)
		{
			obecny->m_pNastepny = kopia;
			this->m_nLiczbaPracownikow++;
			return;
		}
		else if (obecny->m_pNastepny->Porownaj(p) > 0)
		{
			kopia->m_pNastepny = obecny->m_pNastepny;
			obecny->m_pNastepny = kopia;
			this->m_nLiczbaPracownikow++;
			return;
		}
		obecny = obecny->m_pNastepny;
	}
}
void ListaPracownikow::Usun(const Pracownik &wzorzec)
{
	if (this->m_pPoczatek == nullptr)
	{
		return;
	}
	if (this->m_pPoczatek->Porownaj(wzorzec) == 0)
	{
		if (this->m_pPoczatek->m_pNastepny == nullptr)
		{
			delete this->m_pPoczatek;
			this->m_pPoczatek = nullptr;
			this->m_nLiczbaPracownikow--;
		}
		else
		{
			Pracownik *kopia = this->m_pPoczatek->m_pNastepny;
			delete this->m_pPoczatek;
			this->m_pPoczatek = kopia;
			this->m_nLiczbaPracownikow--;
			Pracownik::statyczna++;
		}
	}
	else
	{
		Pracownik *obecny = this->m_pPoczatek;
		while (obecny->m_pNastepny != nullptr)
		{
			if (obecny->m_pNastepny->Porownaj(wzorzec) == 0)
			{
				if (obecny->m_pNastepny->m_pNastepny == nullptr)
				{
					delete obecny->m_pNastepny;
					obecny->m_pNastepny = nullptr;
					this->m_nLiczbaPracownikow--;
					Pracownik::statyczna++;
					break;
				}
				else
				{
					Pracownik *doUsuniecia = obecny->m_pNastepny;
					obecny->m_pNastepny = obecny->m_pNastepny->m_pNastepny;
					delete doUsuniecia;
					this->m_nLiczbaPracownikow--;
					Pracownik::statyczna++;
					break;
				}
			}
			obecny = obecny->m_pNastepny;
		}
	}
}
ListaPracownikow::~ListaPracownikow()
{
	if (this->m_pPoczatek != nullptr)
	{
		if (this->m_pPoczatek->m_pNastepny == nullptr)
		{
			delete this->m_pPoczatek;
			this->m_pPoczatek = nullptr;
		}
		else
		{
			Pracownik *doUsuniecia = this->m_pPoczatek;
			Pracownik *obecny = this->m_pPoczatek->m_pNastepny;
			delete doUsuniecia;
			while (obecny != nullptr)
			{
				doUsuniecia = obecny;
				obecny = obecny->m_pNastepny;
				delete doUsuniecia;
			}
			this->m_pPoczatek = nullptr;
		}
	}
}
void ListaPracownikow::WypiszPracownikow() const
{
	if (this->m_pPoczatek != nullptr)
	{
		this->m_pPoczatek->WypiszDane();
		std::cout << std::endl;
		Pracownik *obecny = this->m_pPoczatek;
		while (obecny->m_pNastepny != nullptr)
		{
			obecny->m_pNastepny->WypiszDane();
			std::cout << std::endl;
			obecny = obecny->m_pNastepny;
		}
		std::cout << "Lacznie: " << this->m_nLiczbaPracownikow << std::endl;
	}
	else
		std::cout << "Brak Pracownikow!" << std::endl;
}
const Pracownik *ListaPracownikow::Szukaj(const char *nazwisko, const char *imie) const
{
	Pracownik *obecny = this->m_pPoczatek;
	while (obecny != nullptr)
	{
		if (obecny->SprawdzImie(imie) == 0)
		{
			if (obecny->SprawdzNazwisko(nazwisko) == 0)
			{
				return obecny;
			}
		}
		obecny = obecny->m_pNastepny;
	}
	return nullptr;
}
void ListaPracownikow::ZapisDoPliku() const
{
	std::ofstream plik("lista.txt", std::ios::out);
	if (!plik)
	{
		std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;
		return;
	}
	Pracownik *obecny = this->m_pPoczatek;
	while (obecny != nullptr)
	{
		Kierownik *kto = dynamic_cast<Kierownik *>(obecny);
		if (kto != nullptr)
		{
			plik << "K " << *kto << std::endl;
		}
		else
		{
			plik << "P " << *obecny << std::endl;
		}
		obecny = obecny->m_pNastepny;
	}
	plik.close();
}
void ListaPracownikow::OdczytZPliku()
{
	std::ifstream plik("lista.txt", std::ios::in);
	if (!plik)
	{
		std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;
		return;
	}
	int x;
	char znak;
	while (!plik.eof())
	{
		znak = plik.get();
		if (znak == 'P')
		{
			Pracownik prac;
			plik >> x >> prac >> std::ws;
			this->Dodaj(prac);
		}
		else if (znak == 'K')
		{
			Kierownik kto;
			plik >> x >> kto >> std::ws;
			this->Dodaj(kto);
		}
	}
	plik.close();
}