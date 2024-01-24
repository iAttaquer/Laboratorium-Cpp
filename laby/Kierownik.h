#pragma once
#include "Pracownik.h"

class Kierownik : public Pracownik
{
private:
    Napis m_NazwaDzialu;
    int m_nliczbaPracownikow;

public:
    Kierownik(const char *im = "", const char *naz = "", int dzien = 1,
              int miesiac = 1, int rok = 2000, const char *dzia = "", int liczbap = 0);
    Kierownik(const Kierownik &wzor);
    Kierownik &operator=(const Kierownik &wzor);
    bool operator==(const Kierownik &wzor) const;
    virtual void WypiszDane();
    virtual Pracownik *KopiaObiektu() const;
    friend std::ostream &operator<<(std::ostream &wy, const Kierownik &s);
    friend std::istream &operator>>(std::istream &we, Kierownik &s);
};

std::ostream &operator<<(std::ostream &wy, const Kierownik &s);
std::istream &operator>>(std::istream &we, Kierownik &s);