#include "Czajnik elektryczny.h"

using namespace std;

CzajnikElektryczny::CzajnikElektryczny()
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY CZAJNIK ELEKTRYCZNY" << endl;
#endif

	moc_grzalki = 0;
}

CzajnikElektryczny::CzajnikElektryczny(int kod, string kat, unsigned int pojemnosc_czajnika, string producent_czajnika, string kolor_czajnika, unsigned int moc_czajnika_elektrycznego) :
	                                   Czajnik(kod, kat, pojemnosc_czajnika, producent_czajnika, kolor_czajnika)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY CZAJNIK ELEKTRYCZNY" << endl;
#endif

	moc_grzalki = moc_czajnika_elektrycznego;
}

CzajnikElektryczny::~CzajnikElektryczny()
{
#ifdef _DEBUG
	cout << "USUNIETO OBIEKT KLASY CZAJNIK ELEKTRYCZNY" << endl;
#endif
}

void CzajnikElektryczny::ustawMocGrzalki(unsigned int moc_cz_el)
{
	moc_grzalki = moc_cz_el;
}

void CzajnikElektryczny::opiszSiebie()
{
	cout << "To ja - czajnik elektryczny" << endl;
}

void CzajnikElektryczny::wypiszInformacje()
{
	cout << "Czajnik elektryczny: " << endl;
	cout << *this;
}

void CzajnikElektryczny::wczytaj(istream& wejscie)
{
	Czajnik::wczytaj(wejscie);
	if (!(wejscie >> moc_grzalki))
	{
		throw string("Nie udalo sie wczytac mocy grzalki czajnika elektrycznego!");
	}
	wejscie.clear();
	wejscie.ignore(1000, '\n');
}

void CzajnikElektryczny::zapisz(ofstream& plik_wyjsciowy, bool flaga)
{
	if (flaga)
	{
		plik_wyjsciowy << "CZAJNIK ELEKTRYCZNY" << endl;
	}

	Czajnik::zapisz(plik_wyjsciowy, 0);

	plik_wyjsciowy << moc_grzalki << endl;
}

void CzajnikElektryczny::wczytaj(string nazwa_pliku)
{
	ifstream plik_wejsciowy;
	plik_wejsciowy.open(nazwa_pliku, ios::in);
	if (!plik_wejsciowy.good())
	{
		throw string("Nie udalo sie otworzyc pliku!");
	}
	try
	{
		CzajnikElektryczny::wczytaj(plik_wejsciowy);
	}
	catch (string blad)
	{
		plik_wejsciowy.close();
		throw blad;
	}
	plik_wejsciowy.close();
}

ostream& operator << (ostream& os, const CzajnikElektryczny& cz_el)
{
	os << *(dynamic_cast<Czajnik*>(&CzajnikElektryczny(cz_el)))
	   << "\tMoc grzalki: " << cz_el.moc_grzalki << " W" << endl;
	return os;
}

istream& operator >> (istream& is, CzajnikElektryczny& cz_el)
{
	is >> ((Czajnik&)cz_el);

	cout << endl << "Podaj moc grzalki czajnika elektrycznego: ";
	is >> cz_el.moc_grzalki;
	return is;
}