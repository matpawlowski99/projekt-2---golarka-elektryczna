#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/// Klasa abstrakcyjna bedaca "rodzicem"
class AGD
{
protected:
	int kod_produktu; ///< okresla kod produktu AGD
	string kategoria; ///< okresla kategoria produktu AGD

public:
	/// konstruktor domyslny produktu AGD
	AGD();
	
	/// konstruktor z parametrami produktu AGD
	AGD(int kod, string kat);
	
	///destruktor produktu AGD
	virtual ~AGD();

	
	/// ustawia kod produktu AGD
	/**
	\param kod kod produktu
	*/
	void ustawKodProduktu(int kod);

	/// ustawia kategorie produktu AGD
	/**
	\param kat kategoria
	*/
	void ustawKategorie(string kat);


	/// zwraca kod produktu AGD
	/**
	\return kod_produktu kod produktu
	*/
	int zwrocKodProduktu() const
	{
		return kod_produktu;
	}

	/// zwraca kategorie produktu AGD
	/**
	\return kategoria kategoria
	*/
	string zwrocKategorie() const
	{
		return kategoria;
	}


	/// opisuje siebie samego
	virtual void opiszSiebie();

	/// wypisuje dane o produkcie AGD
	virtual void wypiszInformacje() = 0;


	/// wczytuje ze strumienia informacje o produkcie AGD
	/**
	\param wejscie strumien wejsciowy
	*/
	virtual void wczytaj(istream& wejscie);
	
	/// zapisuje do pliku informacje o produkcie AGD
	/**
	\param plik_wyjsciowy plik wyjsciowy do zapisu
	\param flaga wypisuje rodzaj produktu AGD
	*/
	virtual void zapisz(ofstream& plik_wyjsciowy, bool flaga);
	
	/// wczytuje z pliku informacje o produkcie AGD
	/**
	\param nazwa_pliku nazwa pliku do odczytu
	*/
	void wczytaj(string nazwa_pliku);


	/// operator strumieniowy wypisujacy informacje o produkcie AGD
	/**
	\param os strumien wyjsciowy
	\param agd produkt AGD
	*/
	friend ostream& operator << (ostream& os, const AGD& agd);

	/// operator strumieniowy pobierajacy informacje o produkcie AGD
	/**
	\param os strumien wejsciowy
	\param agd produkt AGD
	*/
	friend istream& operator >> (istream& is, AGD& agd);
};