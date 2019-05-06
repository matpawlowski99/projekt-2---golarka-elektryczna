#include "Golarka elektryczna.h"
#include <iostream>
#include <conio.h>

using namespace std;

unsigned int GolarkaElektryczna::licznik_stworzonych_golarek = 0;
unsigned int GolarkaElektryczna::licznik_aktualnie_istniejacych_golarek = 0;

GolarkaElektryczna::GolarkaElektryczna()
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY GOLARKA ELEKTRYCZNA" << endl;
#endif

	producent = "brak danych";
	model = "brak danych";
	stan = 0;
	waga = 0;
	cena = 0;

	glowica = nullptr;
	licznik_stworzonych_golarek++;
	licznik_aktualnie_istniejacych_golarek++;
}

GolarkaElektryczna::GolarkaElektryczna(string producent_golarki, string model_golarki, bool stan_golarki, unsigned int waga_golarki, unsigned int cena_golarki)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY GOLARKA ELEKTRYCZNA" << endl;
#endif

	producent = producent_golarki;
	model = model_golarki;
	stan = stan_golarki;
	waga = waga_golarki;
	cena = cena_golarki;

	glowica = nullptr;
	licznik_stworzonych_golarek++;
	licznik_aktualnie_istniejacych_golarek++;
}

GolarkaElektryczna::GolarkaElektryczna(string producent_golarki, string model_golarki, bool stan_golarki, unsigned int waga_golarki, unsigned int cena_golarki, // golarka elektryczna
	unsigned int pojemnosc_akumulatora, unsigned int sprawnosc_akumulatora, string elektrolit_akumulatora, // akumulator
	string material_obudowy, string kolor_obudowy, unsigned int liczba_przyciskow_obudowy) : // obudowa
	akumulator(pojemnosc_akumulatora, sprawnosc_akumulatora, elektrolit_akumulatora),
	obudowa(material_obudowy, kolor_obudowy, liczba_przyciskow_obudowy)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY GOLARKA ELEKTRYCZNA" << endl;
#endif

	producent = producent_golarki;
	model = model_golarki;
	stan = stan_golarki;
	waga = waga_golarki;
	cena = cena_golarki;

	glowica = nullptr;
	licznik_stworzonych_golarek++;
	licznik_aktualnie_istniejacych_golarek++;
}

GolarkaElektryczna::GolarkaElektryczna(int kod, string kategoria, string producent_golarki, string model_golarki, bool stan_golarki, unsigned int waga_golarki, unsigned int cena_golarki, // golarka elektryczna
	unsigned int pojemnosc_akumulatora, unsigned int sprawnosc_akumulatora, string elektrolit_akumulatora, // akumulator
	string material_obudowy, string kolor_obudowy, unsigned int liczba_przyciskow_obudowy) : // obudowa
	GolarkaElektryczna(producent_golarki, model_golarki, stan_golarki, waga_golarki, cena_golarki,
		pojemnosc_akumulatora, sprawnosc_akumulatora, elektrolit_akumulatora,
		material_obudowy, kolor_obudowy, liczba_przyciskow_obudowy)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY GOLARKA ELEKTRYCZNA" << endl;
#endif

	AGD::ustawKodProduktu(kod);
	AGD::ustawKategorie(kategoria);
}

GolarkaElektryczna::GolarkaElektryczna(const GolarkaElektryczna& gol)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY GOLARKA ELEKTRYCZNA" << endl;
#endif

	AGD::ustawKodProduktu(gol.zwrocKodProduktu());
	AGD::ustawKategorie(gol.zwrocKategorie());

	producent = gol.producent;
	model = gol.model;
	stan = gol.stan;
	waga = gol.waga;
	cena = gol.cena;

	akumulator = gol.akumulator;
	obudowa = gol.obudowa;

	if (gol.glowica != nullptr)
		glowica = new Glowica(*(gol.glowica));
	else
		glowica = nullptr;
	licznik_stworzonych_golarek++;
	licznik_aktualnie_istniejacych_golarek++;
}

GolarkaElektryczna::~GolarkaElektryczna()
{
#ifdef _DEBUG
	cout << "USUNIETO OBIEKT KLASY GOLARKA ELEKTRYCZNA" << endl;
#endif

	delete glowica;
	glowica = nullptr;
	licznik_aktualnie_istniejacych_golarek--;
}

void GolarkaElektryczna::ustawProducenta(string producent_gol)
{
	producent = producent_gol;
}

void GolarkaElektryczna::ustawModel(string model_gol)
{
	model = model_gol;
}

void GolarkaElektryczna::ustawWage(unsigned int waga_gol)
{
	waga = waga_gol;
}

void GolarkaElektryczna::ustawCene(unsigned int cena_gol)
{
	cena = cena_gol;
}

void GolarkaElektryczna::opiszSiebie()
{
	cout << "To ja - golarka elektryczna" << endl;
}

void GolarkaElektryczna::wypiszInformacje()
{
	cout << "Golarka elektryczna: " << endl;
	cout << *this;
}

void GolarkaElektryczna::opiszAkumulator() const
{
	cout << akumulator;
}

void GolarkaElektryczna::opiszObudowe() const
{
	cout << obudowa;
}

string GolarkaElektryczna::czyWlaczona() const
{
	if (stan)
		return string("Golarka wlaczona");
	else
		return string("Golarka wylaczona");
}

void GolarkaElektryczna::zainstalujGlowice(unsigned int liczba_glowic_g, unsigned int liczba_oslonek_g, unsigned int liczba_nozykow_g)
{
	if (glowica != nullptr)
		cout << "Golarka jest juz zainstalowana" << endl;
	else
	{
		glowica = new Glowica(liczba_glowic_g, liczba_oslonek_g, liczba_nozykow_g);
		cout << "Zainstalowano glowice" << endl;
	}
}

void GolarkaElektryczna::opiszGlowice() const
{
	if (glowica != nullptr)
		cout << *glowica;
	else
		cout << "Zadna glowica nie jest zainstalowana" << endl;
}

void GolarkaElektryczna::usunGlowice()
{
	if (glowica != nullptr)
	{
		cout << "Usunieto glowice" << endl;
		delete glowica;
		glowica = nullptr;
	}
	else
		cout << "Zadna glowica nie jest zainstalowana" << endl;
}

GolarkaElektryczna& GolarkaElektryczna::operator = (const GolarkaElektryczna& gol)
{
	if (this == &gol)
		return *this;
	else
	{
		producent = gol.producent;
		model = gol.model;
		stan = gol.stan;
		waga = gol.waga;
		cena = gol.cena;
		akumulator = gol.akumulator;
		obudowa = gol.obudowa;
		delete glowica;
		if (gol.glowica != nullptr)
			glowica = new Glowica(*(gol.glowica));
		else
			glowica = nullptr;
		return *this;
	}
}

GolarkaElektryczna& GolarkaElektryczna::operator - (const Obudowa& o)
{
	obudowa = o;
	return *this;
}

GolarkaElektryczna& GolarkaElektryczna::operator += (const Akumulator& a)
{
	akumulator = a;
	return *this;
}

void GolarkaElektryczna::wczytaj(istream& wejscie)
{
	AGD::wczytaj(wejscie);

	getline(wejscie, producent);
	getline(wejscie, model);
	wejscie.clear();

	if (!(wejscie >> stan))
	{
		throw string("Nie udalo sie wczytac stanu golarki elektrycznej!");
	}
	wejscie.clear();
	wejscie.ignore(1000, '\n');

	if (!(wejscie >> waga))
	{
		throw string("Nie udalo sie wczytac wagi golarki elektrycznej!");
	}
	wejscie.clear();
	wejscie.ignore(1000, '\n');

	if (!(wejscie >> cena))
	{
		throw string("Nie udalo sie wczytac ceny golarki elektrycznej!");
	}
	wejscie.clear();
	wejscie.ignore(1000, '\n');

	akumulator.wczytaj(wejscie);
	obudowa.wczytaj(wejscie);

	int g;
	if (wejscie >> g) // sprawdza obecnosc glowicy
	{
		wejscie.clear();
		wejscie.ignore(1000, '\n');

		if (g == 1)
		{
			delete glowica;
			glowica = new Glowica();
			try
			{
				glowica->wczytaj(wejscie);
			}
			catch (string blad)
			{
				delete glowica; // usuwa zaalokowana glowice w przypadku wystapienia bledu
				glowica = nullptr;
				throw blad;
			}
		}
		else
		{
			if (g != 0)
			{
				throw string("Nie udalo sie okreslic istnienia glowicy na podstawie tego parametru!");
			}
		}
	}
	else
	{
		throw string("Nie udalo sie sprawdzic obecnosci glowicy!");
	}
}


void GolarkaElektryczna::zapisz(ofstream& plik_wyjsciowy, bool flaga)
{
	if (flaga)
	{
		plik_wyjsciowy << "GOLARKA ELEKTRYCZNA" << endl;
	}
	
	AGD::zapisz(plik_wyjsciowy, 0);
	
	plik_wyjsciowy << producent << endl
	               << model << endl
	               << stan << endl
	               << waga << endl
	               << cena << endl;

	akumulator.zapisz(plik_wyjsciowy);
	obudowa.zapisz(plik_wyjsciowy);
	if (glowica != nullptr)
	{
		plik_wyjsciowy << 1 << endl;
		glowica->zapisz(plik_wyjsciowy);
	}
	else
		plik_wyjsciowy << 0 << endl;
}

void GolarkaElektryczna::wczytaj(string nazwa_pliku)
{
	ifstream plik_wejsciowy;
	plik_wejsciowy.open(nazwa_pliku, ios::in);
	if (!plik_wejsciowy.good())
	{
		throw string("Nie udalo sie otworzyc pliku!");
	}
	try
	{
		GolarkaElektryczna::wczytaj(plik_wejsciowy);
	}
	catch (string blad)
	{
		plik_wejsciowy.close();
		throw blad;
	}
	plik_wejsciowy.close();
}

ostream& operator << (ostream& os, const GolarkaElektryczna& gol)
{
	os << *(dynamic_cast<AGD*>(&GolarkaElektryczna(gol))) // wypisuje informacje o AGD
		<< "\tProducent: " << gol.producent << endl
		<< "\tModel: " << gol.model << endl
		<< "\tStan: " << gol.stan << endl
		<< "\tWaga: " << gol.waga << " g" << endl
		<< "\tCena: " << gol.cena << " zl" << endl
		<< gol.akumulator // wypisuje informacje o akumulatorze
		<< gol.obudowa; // wypisuje informacje o obudowie

	if (gol.glowica)
	{
		os << *gol.glowica; // wypisuje informacje o glowicy
	}

	return os;
}

istream& operator >> (istream& is, GolarkaElektryczna& gol)
{
	is >> ((AGD&)gol);

	cout << "Podaj producenta golarki elektrycznej: ";
	is >> gol.producent;
	cout << "Podaj model golarki elektrycznej: ";
	is >> gol.model;
	bool flaga;
	char stan;
	do
	{
		cout << "Podaj stan golarki elektrycznej (0/1): ";
		stan = _getch();
		cout << stan;
		if (stan != '0' && stan != '1')
		{
			cout << endl << "Niepoprawny stan!" << endl << endl;
			flaga = false;
		}
		else if (stan == '1')
		{
			gol.stan = false;
			flaga = true;
		}
		else
		{
			gol.stan = true;
			flaga = true;
		}
	} while (flaga == false);
	cout << endl << "Podaj wage golarki elektrycznej: ";
	is >> gol.waga;
	cout << "Podaj cene golarki elektrycznej: ";
	is >> gol.cena;

	is >> gol.akumulator;
	is >> gol.obudowa;

	char czyGlowica;
	do
	{
		cout << "Zainstalowac glowice? (0/1): ";
		czyGlowica = _getch();
		cout << czyGlowica;
		if (czyGlowica != '0' && czyGlowica != '1')
		{
			cout << endl << "Niepoprawna odpowiedz!" << endl << endl;
			flaga = false;
		}
		else if (czyGlowica == '1')
		{
			cout << endl;
			if (gol.glowica == nullptr)
			{
				gol.glowica = new Glowica();
			}
			is >> *gol.glowica;
			flaga = true;
		}
		else if (gol.glowica != nullptr)
		{
			delete gol.glowica;
			gol.glowica = nullptr;
			flaga = true;
		}
	} while (flaga == false);
	return is;
}