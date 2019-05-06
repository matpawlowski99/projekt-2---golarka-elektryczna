#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "AGD.h"

using namespace std;

/// Klasa dziedziczaca po klasie AGD
class Czajnik : public AGD
{
protected:
	unsigned int pojemnosc; ///< okresla pojemnosc czajnika
	string producent; ///< okresla producenta czajnika
	string kolor; ///< okresla kolor czajnika

public:
	/// konstruktor domyslny czajnika
	Czajnik();
	
	/// konstruktor z parametrami samego czajnika
	Czajnik(unsigned int poj, string prod, string kol);
	
	/// konstruktor z parametrami czajnika i produktu AGD
	Czajnik(int kod, string kat, unsigned int poj, string prod, string kol);
	
	/// destruktor czajnika
	~Czajnik();

	
	/// ustawia pojemnosc czajnika
	/**
	\param pojemnosc_cz pojemnosc czajnika
	*/
	void ustawPojemnosc(unsigned int pojemnosc_cz);

	/// ustawia producenta czajnika
	/**
	\param producent_cz producent czajnika
	*/
	void ustawProducenta(string producent_cz);

	/// ustawia kolor czajnika
	/**
	\param kolor_cz kolor czajnika
	*/
	void ustawKolor(string kolor_cz);

	
	/// zwraca pojemnosc czajnika
	/**
	\return pojemnosc pojemnosc czajnika
	*/
	int zwrocPojemnosc() const
	{
		return pojemnosc;
	}

	/// zwraca producenta czajnika
	/**
	\return producent producent czajnika
	*/
	string zwrocProducenta() const
	{
		return producent;
	}

	/// zwraca kolor czajnika
	/**
	\return kolor kolor czajnika
	*/
	string zwrocKolor() const
	{
		return kolor;
	}

	
	/// opisuje siebie samego
	void opiszSiebie();

	/// wypisuje dane o czajniku
	void wypiszInformacje();


	/// wczytuje ze strumienia informacje o czajniku
	/**
	\param wejscie strumien wejsciowy
	*/
	void wczytaj(istream& wejscie);
	
	/// zapisuje do pliku informacje o czajniku
	/**
	\param plik_wyjsciowy plik wyjsciowy do zapisu
	\param flaga wypisuje rodzaj produktu AGD
	*/
	void zapisz(ofstream& plik_wyjsciowy, bool flaga);
	
	/// wczytuje z pliku informacje o czajniku
	/**
	\param nazwa_pliku nazwa pliku do odczytu
	*/
	void wczytaj(string nazwa_pliku);


	/// operator strumieniowy wypisujacy informacje o czajniku
	/**
	\param os strumien wyjsciowy
	\param cz czajnik
	*/
	friend ostream& operator << (ostream& os, const Czajnik& cz);

	/// operator strumieniowy pobierajacy informacje o czajniku
	/**
	\param is strumien wejsciowy
	\param cz czajnik
	*/
	friend istream& operator >> (istream& is, Czajnik& cz);
};