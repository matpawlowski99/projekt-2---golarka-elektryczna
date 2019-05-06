#include "Akumulator.h"
#include <iostream>

using namespace std;

Akumulator::Akumulator()
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY AKUMULATOR" << endl;
#endif

	pojemnosc = 0;
	sprawnosc = 0;
	elektrolit = "brak danych";
}

Akumulator::Akumulator(unsigned int pojemnosc_a, unsigned int sprawnosc_a, string elektrolit_a)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY AKUMULATOR" << endl;
#endif

	pojemnosc = pojemnosc_a;
	sprawnosc = sprawnosc_a;
	elektrolit = elektrolit_a;
}

Akumulator::Akumulator(const Akumulator& a)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY AKUMULATOR" << endl;
#endif
	pojemnosc = a.pojemnosc;
	sprawnosc = a.sprawnosc;
	elektrolit = a.elektrolit;
}

Akumulator::~Akumulator()
{
#ifdef _DEBUG
	cout << "USUNIETO OBIEKT KLASY AKUMULATOR" << endl;
#endif
}

void Akumulator::ustawPojemnosc(unsigned int pojemnosc_a)
{
	pojemnosc = pojemnosc_a;
}

void Akumulator::ustawSprawnosc(unsigned int sprawnosc_a)
{
	sprawnosc = sprawnosc_a;
}

void Akumulator::ustawElektrolit(string elektrolit_a)
{
	elektrolit = elektrolit_a;
}

bool Akumulator::operator == (const Akumulator& a) const
{
	if (pojemnosc == a.pojemnosc && sprawnosc == a.sprawnosc && elektrolit == a.elektrolit)
		return true;
	else
		return false;
}

bool Akumulator::operator < (const Akumulator& a) const
{
	if (sprawnosc < a.sprawnosc)
		return true;
	else
		return false;
}

bool Akumulator::operator > (const Akumulator& a) const
{
	if (sprawnosc > a.sprawnosc)
		return true;
	else
		return false;
}

void Akumulator::wczytaj(istream& wejscie)
{
	if (!(wejscie >> pojemnosc))
	{
		throw string("Nie udalo sie wczytac pojemnosci akumulatora!");
	}
	wejscie.clear();
	wejscie.ignore(1000, '\n');

	if (!(wejscie >> sprawnosc))
	{
		throw string("Nie udalo sie wczytac sprawnosci akumulatora!");
	}
	wejscie.clear();
	wejscie.ignore(1000, '\n');

	getline(wejscie, elektrolit);
	wejscie.clear();
}

void Akumulator::zapisz(ofstream& wyjscie)
{
	wyjscie << pojemnosc << endl
		    << sprawnosc << endl
		    << elektrolit << endl;
}

void Akumulator::wczytaj(string nazwa_pliku)
{
	ifstream plik_wejsciowy;
	plik_wejsciowy.open(nazwa_pliku, ios::in);
	if (!plik_wejsciowy.good())
	{
		throw string("Nie udalo sie otworzyc pliku!");
	}
	try
	{
		Akumulator::wczytaj(plik_wejsciowy);
	}
	catch (string blad)
	{
		plik_wejsciowy.close();
		throw blad;
	}
	plik_wejsciowy.close();
}

ostream& operator << (ostream& os, const Akumulator& a)
{
	os << "Specyfikacja akumulatora:" << endl
		<< "\tPojemnosc: " << a.pojemnosc << " Ah" << endl
		<< "\tSprawnosc: " << a.sprawnosc << " %" << endl
		<< "\tElektrolit: " << a.elektrolit << endl;
	return os;
}

istream& operator >> (istream& is, Akumulator& a)
{
	cout << endl << "Podaj pojemnosc akumulatora: ";
	is >> a.pojemnosc;
	bool flaga;
	do
	{
		cout << "Podaj sprawnosc akumulatora (w %): ";
		is >> a.sprawnosc;
		if (a.sprawnosc <= 0 || a.sprawnosc >= 100)
		{
			cout << endl << "Niepoprawna sprawnosc!" << endl << endl;
			flaga = false;
		}
		else
		{
			flaga = true;
		}
	} while (flaga == false);
	cout << "Podaj elektrolit akumulatora: ";
	is >> a.elektrolit;
	return is;
}