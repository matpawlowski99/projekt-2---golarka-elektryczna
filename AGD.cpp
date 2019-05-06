#include "AGD.h"

AGD::AGD()
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY AGD" << endl;
#endif

	kod_produktu = 0;
	kategoria = "brak danych";
}

AGD::AGD(int kod, string kat)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY AGD" << endl;
#endif

	kod_produktu = kod;
	kategoria = kat;
}

AGD::~AGD()
{
#ifdef _DEBUG
	cout << "USUNIETO OBIEKT KLASY AGD" << endl;
#endif
}

void AGD::ustawKodProduktu(int kod)
{
	kod_produktu = kod;
}

void AGD::ustawKategorie(string kat)
{
	kategoria = kat;
}

void AGD::opiszSiebie()
{
	cout << "To ja - AGD" << endl;
}

void AGD::wczytaj(istream& wejscie)
{
	if (!(wejscie >> kod_produktu))
	{
		throw string("Nie udalo sie wczytac kodu produktu AGD!");
	}
	wejscie.clear();
	wejscie.ignore(1000, '\n');

	getline(wejscie, kategoria);
}


void AGD::zapisz(ofstream& plik_wyjsciowy, bool flaga)
{
	if (flaga)
	{
		plik_wyjsciowy << "PRODUKT AGD" << endl;
	}
	
	plik_wyjsciowy << kod_produktu << endl
		           << kategoria << endl;
}
void AGD::wczytaj(string nazwa_pliku)
{
	ifstream plik_wejsciowy;
	plik_wejsciowy.open(nazwa_pliku, ios::in);
	if (!plik_wejsciowy.good())
	{
		throw string("Nie udalo sie otworzyc pliku!");
	}
	try
	{
		AGD::wczytaj(plik_wejsciowy);
	}
	catch (string blad)
	{
		plik_wejsciowy.close();
		throw blad;
	}
	plik_wejsciowy.close();
}

ostream& operator << (ostream& os, const AGD& agd)
{
	os << "\tKod produktu: " << agd.kod_produktu << endl
	   << "\tKategoria: " << agd.kategoria << endl;
	return os;
}

istream& operator >> (istream& is, AGD& agd)
{
	cout << endl << "Podaj kod produktu: ";
	is >> agd.kod_produktu;
	bool flaga;
	do
	{
		cout << "Podaj kategorie (uroda/kuchnia): ";
		is >> agd.kategoria;
		if (agd.kategoria != "uroda" && agd.kategoria != "kuchnia")
		{
			cout << endl << "Niepoprawna kategoria!" << endl << endl;
			flaga = false;
		}
		else
		{
			flaga = true;
		}
	} while (flaga == false);
	return is;
}