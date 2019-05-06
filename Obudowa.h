#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/// Klasa bedaca elementem klasy Golarka elektryczna
class Obudowa
{
private:
	string material; ///< okresla material obudowy
	string kolor; ///< okresla kolor obudowy
	unsigned int liczba_przyciskow; ///< okresla liczbe przyciskow obudowy

public:
	/// konstruktor domyslny obudowy
	Obudowa();

	/// konstruktor z parametrami obudowy
	Obudowa(string material_o, string kolor_o, unsigned int liczba_przyciskow_o);
	
	/// destruktor obudowy
	~Obudowa();

	
	/// ustawia material obudowy
	/**
	\param material_o material obudowy
	*/
	void ustawMaterial(string material_o);
	
	/// ustawia kolor obudowy
	/**
	\param kolor_o kolor obudowy
	*/
	void ustawKolor(string kolor_o);
	
	/// ustawia liczbe przyciskow obudowy
	/**
	\param liczba_przyciskow_o liczba przyciskow obudowy
	*/
	void ustawLiczbePrzyciskow(unsigned int liczba_przyciskow_o);

	
	/// zwraca material obudowy
	/**
	\return material material obudowy
	*/
	string zwrocMaterial() const
	{
		return material;
	}
	
	/// zwraca kolor obudowy
	/**
	\return kolor kolor obudowy
	*/
	string zwrocKolor() const
	{
		return kolor;
	}
	
	/// zwraca liczbe przyciskow obudowy
	/**
	\return liczba_przyciskow liczba przyciskow obudowy
	*/
	unsigned int zwrocLiczbePrzyciskow() const
	{
		return liczba_przyciskow;
	}


	/// operator zwiekszajacy liczbe przyciskow obudowy o 1
	/**
	\return zwraca obudowe ze zwiekszona liczba przyciskow
	*/
	Obudowa& operator ++();


	/// wczytuje ze strumienia informacje o obudowie
	/**
	\param wejscie strumien wejsciowy
	*/
	void wczytaj(istream& wejscie);

	/// zapisuje do pliku informacje o obudowie
	/**
	\param plik_wyjsciowy plik wyjsciowy do zapisu
	*/
	void zapisz(ofstream& plik_wyjsciowy);

	/// wczytuje z pliku informacje o obudowie
	/**
	\param nazwa_pliku nazwa pliku do odczytu
	*/
	void wczytaj(string nazwa_pliku);


	/// operator strumieniowy wypisujacy informacje o obudowie
	/**
	\param os strumien wyjsciowy
	\param o obudowa
	*/
	friend ostream& operator << (ostream& os, const Obudowa& o);
	
	/// operator strumieniowy pobierajacy informacje o obudowie
	/**
	\param is strumien wejsciowy
	\param o obudowa
	*/
	friend istream& operator >> (istream& is, Obudowa& o);
};
