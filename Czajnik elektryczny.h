#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Czajnik.h"

using namespace std;

/// Klasa dziedziczaca po klasie Czajnik
class CzajnikElektryczny : public Czajnik
{
private:
	unsigned int moc_grzalki; ///< okresla moc grzalki czajnika elektrycznego

public:
	/// konstruktor domyslny czajnika elektrycznego
	CzajnikElektryczny();
	
	/// konstruktor z parametrami czajnika elektrycznego, czajnika i produktu AGD
	CzajnikElektryczny(int kod, string kat, unsigned int poj, string prod, string kol, unsigned int moc);
	
	/// destruktor czajnka elektrycznego
	~CzajnikElektryczny();


	/// ustawia moc grzalki czajnika elektrycznego
	/**
	\param moc_cz_el moc grzalki czajnika elektrycznego
	*/
	void ustawMocGrzalki(unsigned int moc_cz_el);


	/// zwraca moc grzalki czajnika elektrycznego
	/**
	\return moc_grzalki moc grzalki czajnika elektrycznego
	*/
	unsigned int zwrocMocGrzalki() const
	{
		return moc_grzalki;
	}


	/// opisuje siebie samego
	void opiszSiebie();

	/// wypisuje dane o czajniku elektrycznym
	void wypiszInformacje();


	/// wczytuje ze strumienia informacje o czajniku elektrycznym
	/**
	\param wejscie strumien wejsciowy
	*/
	void wczytaj(istream& wejscie);
	
	/// zapisuje do pliku informacje o czajniku elektrycznym
	/**
	\param plik_wyjsciowy plik wyjsciowy do zapisu
	\param flaga wypisuje rodzaj produktu AGD
	*/
	void zapisz(ofstream& plik_wyjsciowy, bool flaga);

	/// wczytuje z pliku informacje o czajniku elektrycznym
	/**
	\param nazwa_pliku nazwa pliku do odczytu
	*/
	void wczytaj(string nazwa_pliku);


	/// operator strumieniowy wypisujacy informacje o czajniku elektrycznym
	/**
	\param os strumien wyjsciowy
	\param cz_el czajnik elektryczny
	*/
	friend ostream& operator << (ostream& os, const CzajnikElektryczny& cz_el);

	/// operator strumieniowy pobierajacy informacje o czajniku elektrycznym
	/**
	\param is strumien wejsciowy
	\param cz_el czajnik elektryczny
	*/
	friend istream& operator >> (istream& is, CzajnikElektryczny& cz_el);
};