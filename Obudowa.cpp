#include "Obudowa.h"
#include <iostream>

using namespace std;

Obudowa::Obudowa()
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY OBUDOWA" << endl;
#endif

	material = "brak danych";
	kolor = "brak danych";
	liczba_przyciskow = 0;
}

Obudowa::Obudowa(string material_o, string kolor_o, unsigned int liczba_przyciskow_o)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY OBUDOWA" << endl;
#endif

	material = material_o;
	kolor = kolor_o;
	liczba_przyciskow = liczba_przyciskow_o;
}

Obudowa::~Obudowa()
{
#ifdef _DEBUG
	cout << "USUNIETO OBIEKT KLASY OBUDOWA" << endl;
#endif
}

void Obudowa::ustawMaterial(string material_o)
{
	material = material_o;
}

void Obudowa::ustawKolor(string kolor_o)
{
	kolor = kolor_o;
}

void Obudowa::ustawLiczbePrzyciskow(unsigned int liczba_przyciskow_o)
{
	liczba_przyciskow = liczba_przyciskow_o;
}

Obudowa& Obudowa::operator++()
{
	liczba_przyciskow++;
	return *this;
}

void Obudowa::wczytaj(istream& wejscie)
{
	getline(wejscie, material);
	getline(wejscie, kolor);
	wejscie.clear();

	if (!(wejscie >> liczba_przyciskow))
	{
		throw string("Nie udalo sie wczytac liczby przyciskow obudowy!");
	}
	wejscie.clear();
	wejscie.ignore(1000, '\n');
}

void Obudowa::zapisz(ofstream& wyjscie)
{
	wyjscie << material << endl
		    << kolor << endl
		    << liczba_przyciskow << endl;
}

void Obudowa::wczytaj(string nazwa_pliku)
{
	ifstream plik_wejsciowy;
	plik_wejsciowy.open(nazwa_pliku, ios::in);
	if (!plik_wejsciowy.good())
	{
		throw string("Nie udalo sie otworzyc pliku!");
	}
	try
	{
		Obudowa::wczytaj(plik_wejsciowy);
	}
	catch (string blad)
	{
		plik_wejsciowy.close();
		throw blad;
	}
	plik_wejsciowy.close();
}

ostream& operator << (ostream& os, const Obudowa& o)
{
	os << "Specyfikacja obudowy:" << endl
		<< "\tMaterial: " << o.material << endl
		<< "\tKolor: " << o.kolor << endl
		<< "\tLiczba przyciskow: " << o.liczba_przyciskow << endl;
	return os;
}

istream& operator >> (istream& is, Obudowa& o)
{
	cout << endl << "Podaj material obudowy: ";
	is >> o.material;
	cout << "Podaj kolor obudowy: ";
	is >> o.kolor;
	cout << "Podaj liczbe przyciskow obudowy: ";
	is >> o.liczba_przyciskow;
	cout << endl;
	return is;
}