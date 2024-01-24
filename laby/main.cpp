#include <iostream>
#include "Data.h"
#include "Napis.h"
#include "Pracownik.h"
#include "ListaPracownikow.h"
#include "Kierownik.h"

int main()
{
	int wybor;
	do
	{
		std::cout << "=======Menu=======\n"
				  << "1) Data \n2) Napis\n"
				  << "3) Pracownik\n4) ListaPracownikow\n"
				  << "0) Koniec" << std::endl;
		std::cin >> wybor;
		switch (wybor)
		{
		case 1:
		{
			std::cout << "Testowanie Klasy Data:" << std::endl;
			std::cout << "Pierwszy obiekt:" << std::endl;
			Data jeden(1, 1, 1);
			std::cout << "Metoda Wypisz():" << std::endl;
			jeden.Wypisz();
			std::cout << "Metoda Ustaw():" << std::endl;
			jeden.Ustaw(10, 10, 2000);
			jeden.Wypisz();
			std::cout << "Drugi obiekt:" << std::endl;
			Data drugi(1, 1, 1);
			std::cout << "Metoda Wpisz():" << std::endl;
			drugi.Wpisz();
			std::cout << "Gettery:" << std::endl;
			std::cout << drugi.Dzien() << std::endl
					  << drugi.Miesiac() << std::endl
					  << drugi.Rok() << std::endl;
			std::cout << "Operator>>: " << std::endl;
			std::cin >> jeden;
			std::cout << "Wczytano do obiektu 'jeden'" << std::endl;
			std::cout << "Operator<<: " << jeden << std::endl;
			std::cout << "Metoda Porownaj():" << std::endl;
			std::cin >> drugi;
			std::cout << "Wczytano do obiektu 'drugi'" << std::endl;
			std::cout << "Wynik porownania 'jeden' z 'drugi': "
					  << jeden.Porownaj(drugi) << std::endl;
			std::cin.get();
		}
		break;
		case 2:
		{
			std::cout << "Testowanie klasy Napis:" << std::endl;
			std::cout << "Pierwszy obiekt:" << std::endl;
			Napis jeden("pierwszy");
			std::cout << "Metoda Wypisz():" << std::endl;
			jeden.Wypisz();
			std::cout << "Destruktor: " << std::endl;
			jeden.~Napis();
			std::cout << "Drugi obiekt: " << std::endl;
			Napis drugi;
			std::cout << "Metoda Wpisz():" << std::endl;
			drugi.Wpisz();
			std::cout << "Metoda Zwroc(): " << drugi.Zwroc() << std::endl;
			std::cout << "Konstruktor kopiujacy:" << std::endl;
			Napis trzeci(drugi);
			std::cout << "Operator= : " << std::endl;
			jeden = drugi;
			std::cout << "Operator>>" << std::endl;
			std::cin >> drugi >> jeden;
			std::cout << "Operator<< : " << drugi << jeden << std::endl;
			std::cout << "Metoda jeden.SprawdzNapis(drugi.Zwroc()): " << jeden.SprawdzNapis(drugi.Zwroc()) << std::endl;
			std::cout << "Operator== : " << (jeden == drugi) << std::endl;
			std::cin.get();
			break;
		}
		case 3:
		{
			std::cout << "Testowanie klasy Pracownik: " << std::endl;
			std::cout << "Pierwszy obiekt: " << std::endl;
			Pracownik jeden("Dariusz", "Wiacek", 18, 12, 2003);
			jeden.Wypisz();
			std::cout << "Konstrukto kopiujacy: " << std::endl;
			Pracownik drugi(jeden);
			drugi.Wypisz();
			std::cout << "Metoda Imie():" << std::endl;
			jeden.Imie("Jan");
			std::cout << "Metoda Nazwisko():" << std::endl;
			jeden.Nazwisko("Kowalski");
			std::cout << "Metoda DataUrodzenia():" << std::endl;
			jeden.DataUrodzenia(1, 1, 2000);
			jeden.Wypisz();
			std::cout << "Metoda Wpisz(): " << std::endl;
			jeden.Wpisz();
			std::cout << "Metoda Wypisz():" << std::endl;
			jeden.Wypisz();
			std::cout << "Metoda SprawdzImie(): "
					  << jeden.SprawdzImie("jan") << std::endl;
			std::cout << "Metoda SprawdzNazwisko(): "
					  << jeden.SprawdzNazwisko("akowal") << std::endl;
			std::cout << "Metoda Porownaj(): " << jeden.Porownaj(drugi) << std::endl;
			std::cout << "Operator== : " << (jeden == drugi) << std::endl;
			std::cout << "Operator>> : " << std::endl;
			std::cin >> jeden;
			std::cout << "Operator<< : " << jeden << std::endl;
			std::cout << "Operator= : " << std::endl;
			drugi = jeden;
			std::cout << drugi << std::endl;
			std::cout << "Metoda KopiaObiektu():" << std::endl;
			Pracownik *trzeci = jeden.KopiaObiektu();
			std::cout << *trzeci << std::endl;
			std::cout << "Metoda WypiszDane():" << std::endl;
			trzeci->WypiszDane();
			std::cin.get();
			std::cin.get();
			break;
		}
		case 4:
		{
			std::cout << "Testowanie klasy ListaPracownikow:" << std::endl;
			ListaPracownikow lista;
			int wybor;
			do
			{
				std::cout << "\nLISTA PRACOWNIKOW:\n"
						  << "1) Dodaj Pracownika lub Kierownika\n"
						  << "2) Usun Pracownika lub Kierownika\n"
						  << "3) Wypisz liste\n"
						  << "4) Szukaj Pracownika lub Kierownika\n"
						  << "5) Usuniecie wszystkich z listy\n"
						  << "6) Zapis listy do pliku\n"
						  << "7) Odczyt listy z pliku\n"
						  << "0) Zakoncz\n";
				std::cin >> wybor;
				switch (wybor)
				{
				case 1:
				{
					std::cout << "Dodawanie pracownika/kierownika-podaj dane:\n";
					std::cout << "Podaj P jesli to pracownik, albo K jesli to Kierownik: ";
					char znak;
					std::cin >> znak;
					if (znak == 'p' || znak == 'P')
					{
						Pracownik dododania;
						std::cin >> dododania;
						lista.Dodaj(dododania);
					}
					else if (znak == 'k' || znak == 'K')
					{
						Kierownik dododania;
						std::cin >> dododania;
						lista.Dodaj(dododania);
					}
					break;
				}
				case 2:
				{
					Pracownik dousuniecia;
					std::cout << "Usuwanie pracownika-podaj dane:\n";
					std::cin >> dousuniecia;
					lista.Usun(dousuniecia);
					break;
				}
				case 3:
				{
					std::cout << "Lista Pracownikow:" << std::endl;
					lista.WypiszPracownikow();
					break;
				}
				case 4:
				{
					Napis imie;
					Napis nazwisko;
					std::cout << "Podaj imie:\n";
					std::cin >> imie;
					std::cout << "Podaj nazwisko:\n";
					std::cin >> nazwisko;
					const Pracownik *prac = lista.Szukaj(nazwisko.Zwroc(), imie.Zwroc());
					std::cout << "\nSzukany pracownik:\n";
					if (prac != nullptr)
					{
						prac->KopiaObiektu()->WypiszDane();
						std::cout << std::endl;
					}
					else
						std::cout << "Nie znaleziono!\n"
								  << std::endl;
					break;
				}
				case 5:
				{
					std::cout << "Wyczyszczenie listy" << std::endl;
					lista.~ListaPracownikow();
					break;
				}
				case 6:
				{
					std::cout << "Zapis do pliku" << std::endl;
					lista.ZapisDoPliku();
					break;
				}
				case 7:
				{
					std::cout << "Odczyt z pliku" << std::endl;
					lista.OdczytZPliku();
					break;
				}
				}
			} while (wybor != 0);
			std::cin.get();
			break;
		}
		case 5:
		{
			std::cout << "Testowanie klasy Pracownik:" << std::endl;
			std::cout << "Pierwszy obiekt:" << std::endl;
			Kierownik *jeden = new Kierownik();
			std::cout << *jeden << std::endl;
			std::cin >> *jeden;
			std::cout << *jeden << std::endl;
			std::cin.get();
			break;
		}
		}
	} while (wybor != 0);
	return 0;
}