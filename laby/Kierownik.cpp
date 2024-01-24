#include "Kierownik.h"

Kierownik::Kierownik(const char *im, const char *naz, int dzien,
					 int miesiac, int rok, const char *dzia, int liczbap)
	: Pracownik(im, naz, dzien, miesiac, rok), m_NazwaDzialu(dzia), m_nliczbaPracownikow(liczbap) {}
Kierownik::Kierownik(const Kierownik &wzor) : Pracownik(wzor)
{
	this->m_NazwaDzialu = wzor.m_NazwaDzialu;
	this->m_nliczbaPracownikow = wzor.m_nliczbaPracownikow;
}
Kierownik &Kierownik::operator=(const Kierownik &wzor)
{
	if (this == &wzor)
		return *this;
	Pracownik::operator=(wzor);
	this->m_NazwaDzialu = wzor.m_NazwaDzialu;
	this->m_nliczbaPracownikow = wzor.m_nliczbaPracownikow;
	return *this;
}
bool Kierownik::operator==(const Kierownik &wzor) const
{
	if (this->Pracownik::operator==(wzor) &&
		this->m_NazwaDzialu == wzor.m_NazwaDzialu &&
		this->m_nliczbaPracownikow == wzor.m_nliczbaPracownikow)
		return true;
	return false;
}
void Kierownik::WypiszDane()
{
	std::cout << "Kierownik ";
	Pracownik::WypiszDane();
	std::cout << "[Nazwa dzialu]: " << this->m_NazwaDzialu << ' '
			  << "[Liczba pracownikow]: " << this->m_nliczbaPracownikow;
}
Pracownik *Kierownik::KopiaObiektu() const
{
	return new Kierownik(*this);
}
std::ostream &operator<<(std::ostream &wy, const Kierownik &s)
{
	return wy << (const Pracownik &)s << ' '
			  << s.m_NazwaDzialu << ' '
			  << s.m_nliczbaPracownikow;
}
std::istream &operator>>(std::istream &we, Kierownik &s)
{
	if (&we == &std::cin)
	{
		we >> (Pracownik &)s;
		std::cout << "Podaj nazwe dzialu: ";
		we >> s.m_NazwaDzialu;
		std::cout << "Podaj liczbe pracownikow: ";
		we >> s.m_nliczbaPracownikow;
	}
	else
	{
		we >> (Pracownik &)s;
		we >> s.m_NazwaDzialu;
		we >> s.m_nliczbaPracownikow;
	}
	return we;
}