#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/// Klasa bedaca elementem klasy Golarka elektryczna
class Akumulator
{
private:
	unsigned int pojemnosc; ///< okresla pojemnosc akumulatora
	unsigned int sprawnosc; ///< okresla sprawnosc akumulatora
	string elektrolit; ///< okresla elektrolit akumulatora

public:
	/// konstruktor domyslny akumulatora
	Akumulator();
	
	/// konstruktor z parametrami akumulatora
	Akumulator(unsigned int pojemnosc_a, unsigned int sprawnosc_a, string elektrolit_a);
	
	/// konstruktor kopiujacy akumulatora
	Akumulator(const Akumulator& a);
	
	/// destruktor akumulatora
	~Akumulator();


	/// ustawia pojemnosc akumulatora
	/**
	\param pojemnosc_a pojemnosc akumulatora
	*/
	void ustawPojemnosc(unsigned int pojemnosc_a); 
	
	/// ustawia sprawnosc akumulatora
	/**
	\param sprawnosc_a sprawnosc akumulatora
	*/
	void ustawSprawnosc(unsigned int sprawnosc_a);
	
	/// ustawia elektrolit akumulatora
	/**
	\param elektrolit_a elektrolit akumulatora
	*/
	void ustawElektrolit(string elektrolit_a);


	/// zwraca pojemnosc akumulatora
	/**
	\return pojemnosc pojemnosc akumulatora
	*/
	unsigned int zwrocPojemnosc() const
	{
		return pojemnosc; 
	}
	
	/// zwraca sprawnosc akumulatora
	/**
	\return sprawnosc sprawnosc akumulatora
	*/
	unsigned int zwrocSprawnosc() const
	{
		return sprawnosc; 
	}
	
	/// zwraca elektrolit akumulatora
	/**
	\return elektrolit elektrolit akumulatora
	*/
	string zwrocElektrolit() const
	{
		return elektrolit; 
	}


	/// operator porownujacy parametry akumulatora
	/**
	\param a akumulator
	\return zwraca "true" gdy parametry akumulatora sa rowne, w przeciwnym przypadku zwraca "false"
	*/
	bool operator == (const Akumulator& a) const;
	
	/// operator porownujacy sprawnosc akumulatora
	/**
	\param a akumulator
	\return zwraca "true" gdy sprawnosc akumulatora jest mniejsza, w przeciwnym przypadku zwraca "false"
	*/
	bool operator < (const Akumulator& a) const;
	
	/// operator porownujacy sprawnosc akumulatora
	/**
	\param a akumulator
	\return zwraca "true" gdy sprawnosc akumulatora jest wieksza, w przeciwnym przypadku zwraca "false"
	*/
	bool operator > (const Akumulator& a) const;


	/// wczytuje ze strumienia informacje o akumulatorze
	/**
	\param wejscie strumien wejsciowy
	*/
	void wczytaj(istream& wejscie);
	
	/// zapisuje do pliku informacje o akumulatorze
	/**
	\param plik_wyjsciowy plik wyjsciowy do zapisu
	*/
	void zapisz(ofstream& plik_wyjsciowy);

	/// wczytuje z pliku informacje o akumulatorze
	/**
	\param nazwa_pliku nazwa pliku do odczytu
	*/
	void wczytaj(string nazwa_pliku);


	/// operator strumieniowy wypisujacy informacje o akumulatorze
	/**
	\param os strumien wyjsciowy
	\param a akumulator
	*/
	friend ostream& operator << (ostream& os, const Akumulator& a);
	
	/// operator strumieniowy pobierajacy informacje o akumulatorze
	/**
	\param is strumien wejsciowy
	\param a akumulator
	*/
	friend istream& operator >> (istream& is, Akumulator& a);
};