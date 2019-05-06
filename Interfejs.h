#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

#include "AGD.h"
#include "Czajnik.h"
#include "Czajnik elektryczny.h"
#include "Golarka elektryczna.h"

using namespace std;

/// Klasa obslugujaca aplikacje konsolowa
class Interfejs
{
private:
	vector<AGD*> wektor_obiektow; ///< wektor przechowujacy wskazniki na obiekty (produkty AGD)

public:
	/// konstruktor domyslny interfejsu
	Interfejs();
	
	/// destruktor interfejsu
	~Interfejs();


	/// wyswietla menu programu
	bool menuGlowne();


	/// sprawdza czy dana liczba nalezy do odpowiedniego przedzialu
	/**
	\param pierwsza pierwsza liczba z przedzialu
	\param ostatnia ostatnia liczba z przedzialu
	*/
	unsigned int czyPrzedzial(unsigned int pierwsza, unsigned int ostatnia);


	/// dodaje obiekt do wektora
	void dodajObiekt();
	
	/// usuwa obiekt z wektora
	void usunObiekt();
	
	/// modyfikuje obiekt z wektora
	void modyfikujObiekt();
	

	/// wczytuje informacje o wszystkich obiektach z pliku
	/**
	\param nazwa_pliku nazwa pliku do odczytu
	*/
	void wczytaj(string nazwa_pliku = "wczytaj.txt");
	
	/// zapisuje informacje o wszystkich obiektach do pliku
	/**
	\param nazwa_pliku nazwa pliku do zapisu
	*/
	void zapisz(string nazwa_pliku = "zapisz.txt");
	

	/// wypisuje informacje o wszystkich obiektach z wektora
	void wypiszWszystko();

	/// prezentuje dzialanie polimorfizmu po usunieciu slowa "virtual" w deklaracji funkcji opiszSiebie() w klasie AGD
	void zaprezentujPolimorfizm();
};