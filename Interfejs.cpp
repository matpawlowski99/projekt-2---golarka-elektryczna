#include "Interfejs.h"

using namespace std;

Interfejs::Interfejs()
{

}

Interfejs::~Interfejs()
{
	for (auto w : wektor_obiektow)
		delete w;
}

bool Interfejs::menuGlowne()
{
	cout << "\tMENU GLOWNE" << endl << endl;
	cout << "Wybierz opcje: " << endl
		 << "1. Dodaj obiekt do wektora" << endl
		 << "2. Usun obiekt z wektora" << endl
		 << "3. Modyfikuj obiekt z wektora" << endl
		 << "4. Zapisz obiekty do pliku" << endl
		 << "5. Wczytaj obiekty z pliku" << endl
		 << "6. Wypisz wszystkie obiekty" << endl
		 << "7. Zaprezentuj dzialanie polimorfizmu" << endl
		 << "0. Zamknij program" << endl << endl;

	int wybor = 0;
	if (!(cin >> wybor) || (wybor > 7 || wybor < 0))
	{
		system("cls");
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Niepoprawna cyfra!" << endl;
		return 1;
	}

	switch (wybor)
	{
	case 0:
		return 0;
	case 1:
		system("cls");
		Interfejs::dodajObiekt();
		break;
	case 2:
		system("cls");
		Interfejs::usunObiekt();
		break;
	case 3:
		system("cls");
		Interfejs::modyfikujObiekt();
		break;
	case 4:
		system("cls");
		Interfejs::zapisz();
		break;
	case 5:
		system("cls");
		Interfejs::wczytaj();
		break;
	case 6:
		system("cls");
		Interfejs::wypiszWszystko();
		break;
	case 7:
		system("cls");
		Interfejs::zaprezentujPolimorfizm();
		break;
	}
	return 1;
}

unsigned int Interfejs::czyPrzedzial(unsigned int pierwszy, unsigned int ostatni)
{
	unsigned int wybor;
	cin.exceptions(ifstream::failbit | ifstream::badbit);
	do
	{
		try
		{
			cin >> wybor;
		}
		catch (fstream::failure)
		{
			cout << "Niepoprawna cyfra!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while (wybor < pierwszy || wybor > ostatni);
	return wybor;
}

void Interfejs::dodajObiekt()
{
	cout << "Wybierz obiekt, ktory chcesz dodac: " << endl << endl
	     << "1. Golarka elektryczna" << endl
	     << "2. Czajnik" << endl
	     << "3. Czajnik elektryczny" << endl
	     << "0. Powrot do menu glownego" << endl << endl;
	
	AGD* nowy_obiekt = nullptr;
	unsigned int wybor;
	wybor = Interfejs::czyPrzedzial(0, 3);

	switch (wybor)
	{
	case 0:
		system("cls");
		break;
	case 1:
	{
		nowy_obiekt = new GolarkaElektryczna();
		cin >> (GolarkaElektryczna&)*nowy_obiekt;
		wektor_obiektow.push_back(nowy_obiekt);
		cout << "Dodano obiekt klasy golarka elektryczna" << endl;
		Sleep(1000);
		system("cls");
		break;
	}
	case 2:
	{
		nowy_obiekt = new Czajnik();
		cin >> (Czajnik&)*nowy_obiekt;
		wektor_obiektow.push_back(nowy_obiekt);
		cout << "Dodano obiekt klasy czajnik" << endl;
		Sleep(1000);
		system("cls");
		break;
	}
	case 3:
	{
		nowy_obiekt = new CzajnikElektryczny();
		cin >> (CzajnikElektryczny&)*nowy_obiekt;
		wektor_obiektow.push_back(nowy_obiekt);
		cout << "Dodano obiekt klasy czajnik elektryczny" << endl;
		Sleep(1000);
		system("cls");
		break;
	}
	default:
	{
		cout << "Niepoprawna cyfra!" << endl;
		Sleep(1000);
		system("cls");
		break;
	}
	}
}

void Interfejs::usunObiekt()
{
	if (wektor_obiektow.size() == 0)
	{
		cout << "Obiekty nie sa stworzone!" << endl << endl;
		return;
	}
	cout << "0. Powrot do menu glownego" << endl << endl;
	cout << "Wybierz obiekt, ktory chcesz usunac: " << endl;
	for (int i = 1; i <= wektor_obiektow.size(); i++)
	{
		cout << "[" << i << "]; ";
	}
	cout << endl;

	unsigned int wybor;
	wybor = Interfejs::czyPrzedzial(0, wektor_obiektow.size());

	switch (wybor)
	{
	case 0:
		system("cls");
		break;
	}
	if (wybor >= 1 && wybor <= wektor_obiektow.size())
	{
		AGD* obiekt = wektor_obiektow[wybor - 1];
		wektor_obiektow.erase(wektor_obiektow.begin() + wybor - 1);
		delete obiekt;
		cout << "Usunieto obiekt" << endl;
	}
	Sleep(1000);
	system("cls");
}

void Interfejs::modyfikujObiekt()
{
	if (wektor_obiektow.size() == 0)
	{
		cout << "Obiekty nie sa stworzone!" << endl << endl;
		return;
	}
	cout << "0. Powrot do menu glownego" << endl << endl;
	cout << "Wybierz obiekt, ktory chcesz zmodyfikowac: " << endl;
	for (int i = 1; i <= wektor_obiektow.size(); i++)
	{
		cout << "\t[" << i << "]; ";
	}
	cout << endl;

	unsigned int wybor;
	wybor = Interfejs::czyPrzedzial(0, wektor_obiektow.size());

	switch (wybor)
	{
	case 0:
		system("cls");
		break;
	}
	if (wybor >= 1 && wybor <= wektor_obiektow.size())
	{
		cin >> *wektor_obiektow[wybor - 1];
		cout << "Zmodyfikowano obiekt" << endl;
	}
	Sleep(1000);
	system("cls");
}

void Interfejs::wczytaj(string nazwa_pliku)
{
	cout << "Podaj nazwe pliku do odczytu obiektow: ";
	cin >> nazwa_pliku;
	cout << "Wczytywanie obiektow z pliku: " << nazwa_pliku << "..." << endl << endl;

	ifstream plik_wejsciowy;
	plik_wejsciowy.open(nazwa_pliku, ios::in);
	if (!plik_wejsciowy.good())
	{
		throw string("Nie udalo sie otworzyc pliku!");
	}
	string linijka;
	try
	{
		while (!plik_wejsciowy.eof())
		{
			getline(plik_wejsciowy, linijka);
			AGD* nowy_obiekt = nullptr;
			if (linijka == "GOLARKA ELEKTRYCZNA")
			{
				nowy_obiekt = new GolarkaElektryczna();
				nowy_obiekt->wczytaj(plik_wejsciowy);
				wektor_obiektow.push_back(nowy_obiekt);
			}
			else if (linijka == "CZAJNIK")
			{
				nowy_obiekt = new Czajnik();
				nowy_obiekt->wczytaj(plik_wejsciowy);
				wektor_obiektow.push_back(nowy_obiekt);
			}
			else if (linijka == "CZAJNIK ELEKTRYCZNY")
			{
				nowy_obiekt = new CzajnikElektryczny();
				nowy_obiekt->wczytaj(plik_wejsciowy);
				wektor_obiektow.push_back(nowy_obiekt);
			}
		}
	}
	catch (string blad)
	{
		cout << blad << endl << endl;
	}
	cout << "Wczytano!" << endl;
	plik_wejsciowy.close();
}

void Interfejs::zapisz(string nazwa_pliku)
{
	if (wektor_obiektow.size() == 0)
	{
		cout << "Obiekty nie sa stworzone!" << endl << endl;
		return;
	}
	
	cout << "Podaj nazwe pliku do zapisu obiektow: ";
	cin >> nazwa_pliku;
	cout << "Zapisywanie obiektow do pliku: " << nazwa_pliku << "..." << endl << endl;

	ofstream plik_wyjsciowy;
	plik_wyjsciowy.open(nazwa_pliku, ios::out | ios::app);
	if (!plik_wyjsciowy.good())
	{
		throw string("Nie udalo sie otworzyc pliku!");
	}
	for (int i = 0; i < wektor_obiektow.size(); i++)
	{
		wektor_obiektow[i]->zapisz(plik_wyjsciowy, 1);
	}
	cout << "Zapisano!" << endl;
	plik_wyjsciowy.close();
}

void Interfejs::wypiszWszystko()
{
	if (wektor_obiektow.size() == 0)
	{
		cout << "Obiekty nie sa stworzone!" << endl << endl;
		return;
	}
	for (auto w : wektor_obiektow)
	{
		w->wypiszInformacje();
		cout << endl;
	}
}

void Interfejs::zaprezentujPolimorfizm()
{
	if (wektor_obiektow.size() == 0)
	{
		cout << "Obiekty nie sa stworzone!" << endl << endl;
		return;
	}
	for (auto w : wektor_obiektow)
	{
		w->opiszSiebie();
	}
}