#include "Glowica.h"
#include <iostream>

using namespace std;

Glowica::Glowica()
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY GLOWICA" << endl;
#endif

	liczba_glowic = 0;
	liczba_oslonek = 0;
	liczba_nozykow = 0;
}

Glowica::Glowica(unsigned int liczba_glowic_g, unsigned int liczba_oslonek_g, unsigned int liczba_nozykow_g)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY GLOWICA" << endl;
#endif

	liczba_glowic = liczba_glowic_g;
	liczba_oslonek = liczba_oslonek_g;
	liczba_nozykow = liczba_nozykow_g;
}

Glowica::~Glowica()
{
#ifdef _DEBUG
	cout << "USUNIETO OBIEKT KLASY GLOWICA" << endl;
#endif
}

void Glowica::ustawLiczbeGlowic(unsigned int liczba_glowic_g)
{
	liczba_glowic = liczba_glowic_g;
}

void Glowica::ustawLiczbeOslonek(unsigned int liczba_oslonek_g)
{
	liczba_oslonek = liczba_oslonek_g;
}

void Glowica::ustawLiczbeNozykow(unsigned int liczba_nozykow_g)
{
	liczba_nozykow = liczba_nozykow_g;
}

bool Glowica::operator <= (const Glowica& g) const
{
	if (liczba_glowic <= g.liczba_glowic)
		return true;
	else
		return false;
}

bool Glowica::operator >= (const Glowica& g) const
{
	if (liczba_glowic >= g.liczba_glowic)
		return true;
	else
		return false;
}

void Glowica::wczytaj(istream& wejscie)
{
	if (!(wejscie >> liczba_glowic))
	{
		throw string("Nie udalo sie wczytac liczby glowic glowicy!");
	}
	wejscie.clear();
	wejscie.ignore(1000, '\n');

	if (!(wejscie >> liczba_oslonek))
	{
		throw string("Nie udalo sie wczytac liczby oslonek glowicy!");
	}
	wejscie.clear();
	wejscie.ignore(1000, '\n');

	if (!(wejscie >> liczba_nozykow))
	{
		throw string("Nie udalo sie wczytac liczby nozykow glowicy!");
	}
	wejscie.clear();
	wejscie.ignore(1000, '\n');
}

void Glowica::zapisz(ofstream& wyjscie)
{
	wyjscie << liczba_glowic << endl
		    << liczba_oslonek << endl
		    << liczba_nozykow << endl;
}

void Glowica::wczytaj(string nazwa_pliku)
{
	ifstream plik_wejsciowy;
	plik_wejsciowy.open(nazwa_pliku, ios::in);
	if (!plik_wejsciowy.good())
	{
		throw string("Nie udalo sie otworzyc pliku!");
	}
	try
	{
		Glowica::wczytaj(plik_wejsciowy);
	}
	catch (string blad)
	{
		plik_wejsciowy.close();
		throw blad;
	}
	plik_wejsciowy.close();
}

ostream& operator << (ostream& os, const Glowica& g)
{
	os << "Specyfikacja glowicy:" << endl
		<< "\tLiczba glowic: " << g.liczba_glowic << endl
		<< "\tLiczba oslonek: " << g.liczba_oslonek << endl
		<< "\tLiczba nozykow: " << g.liczba_nozykow << endl;
	return os;
}

istream& operator >> (istream& is, Glowica& g)
{
	cout << endl << "Podaj liczbe glowic glowicy: ";
	is >> g.liczba_glowic;
	cout << "Podaj liczbe oslonek glowicy: ";
	is >> g.liczba_oslonek;
	cout << "Podaj liczbe nozykow glowicy: ";
	is >> g.liczba_nozykow;
	return is;
}