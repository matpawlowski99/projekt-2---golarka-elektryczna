#include "Czajnik.h"

using namespace std;

Czajnik::Czajnik()
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY CZAJNIK" << endl;
#endif

	pojemnosc = 0;
	producent = "brak danych";
	kolor = "brak danych";
}

Czajnik::Czajnik(unsigned int pojemnosc_czajnika, string producent_czajnika, string kolor_czajnika)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY CZAJNIK" << endl;
#endif

	pojemnosc = pojemnosc_czajnika;
	producent = producent_czajnika;
	kolor = kolor_czajnika;
}

Czajnik::Czajnik(int kod, string kat, unsigned int pojemnosc_czajnika, string producent_czajnika, string kolor_czajnika) : AGD(kod, kat)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY CZAJNIK" << endl;
#endif

	pojemnosc = pojemnosc_czajnika;
	producent = producent_czajnika;
	kolor = kolor_czajnika;
}

Czajnik::~Czajnik()
{
#ifdef _DEBUG
	cout << "USUNIETO OBIEKT KLASY CZAJNIK" << endl;
#endif
}

void Czajnik::ustawPojemnosc(unsigned int pojemnosc_cz)
{
	pojemnosc = pojemnosc_cz;
}

void Czajnik::ustawProducenta(string producent_cz)
{
	producent = producent_cz;
}

void Czajnik::ustawKolor(string kolor_cz)
{
	kolor = kolor_cz;
}

void Czajnik::opiszSiebie()
{
	cout << "To ja - czajnik" << endl;
}

void Czajnik::wypiszInformacje()
{
	cout << "Czajnik: " << endl;
	cout << *this;
}

void Czajnik::wczytaj(istream& wejscie)
{
	AGD::wczytaj(wejscie);

	if (!(wejscie >> pojemnosc))
	{
		throw string("Nie udalo sie wczytac pojemnosci czajnika!");
	}
	wejscie.clear();
	wejscie.ignore(1000, '\n');

	getline(wejscie, producent);
	getline(wejscie, kolor);
	wejscie.clear();
}

void Czajnik::zapisz(ofstream& plik_wyjsciowy, bool flaga)
{
	if (flaga)
	{
		plik_wyjsciowy << "CZAJNIK" << endl;
	}

	AGD::zapisz(plik_wyjsciowy, 0);

	plik_wyjsciowy << pojemnosc << endl
		           << producent << endl
		           << kolor << endl;
}

void Czajnik::wczytaj(string nazwa_pliku)
{
	ifstream plik_wejsciowy;
	plik_wejsciowy.open(nazwa_pliku, ios::in);
	if (!plik_wejsciowy.good())
	{
		throw string("Nie udalo sie otworzyc pliku!");
	}
	try
	{
		Czajnik::wczytaj(plik_wejsciowy);
	}
	catch (string blad)
	{
		plik_wejsciowy.close();
		throw blad;
	}
	plik_wejsciowy.close();
}

ostream& operator << (ostream& os, const Czajnik& cz)
{
	Czajnik czajnik(cz);
	os << *(dynamic_cast<AGD*>(&czajnik))
	   << "\tPojemnosc: " << cz.pojemnosc << " l" << endl
	   << "\tProducent: " << cz.producent << endl
	   << "\tKolor: " << cz.kolor << endl;
	return os;
}

istream& operator >> (istream& is, Czajnik& cz)
{
	is >> ((AGD&)cz);

	cout << endl << "Podaj pojemnosc czajnika: ";
	is >> cz.pojemnosc;
	cout << "Podaj producenta czajnika: ";
	is >> cz.producent;
	cout << "Podaj kolor czajnika: ";
	is >> cz.kolor;
	return is;
}