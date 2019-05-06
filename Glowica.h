#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/// Klasa bedaca dynamicznym elementem klasy Golarka elektryczna
class Glowica
{
private:
	unsigned int liczba_glowic; ///< okresla liczbe glowic glowicy
	unsigned int liczba_oslonek; ///< okresla liczbe oslonek glowicy
	unsigned int liczba_nozykow; ///< okresla liczbe nozykow glowicy

public:
	/// konstruktor domyslny glowicy
	Glowica();
	
	/// konstruktor z parametrami glowicy
	Glowica(unsigned int l_glowic, unsigned int l_oslonek, unsigned int l_nozykow);
	
	/// destruktor glowicy
	~Glowica();

	
	/// ustawia liczbe glowic glowicy
	/**
	\param l_glowic liczba glowic glowicy
	*/
	void ustawLiczbeGlowic(unsigned int l_glowic);
	
	/// ustawia liczbe oslonek glowicy
	/**
	\param l_oslonek liczba oslonek glowicy
	*/
	void ustawLiczbeOslonek(unsigned int l_oslonek);
	
	/// ustawia liczbe nozykow glowicy
	/**
	\param l_nozykow liczba nozykow glowicy
	*/
	void ustawLiczbeNozykow(unsigned int l_nozykow);


	/// zwraca liczbe glowic glowicy
	/**
	\return liczba_glowic liczba glowic glowicy
	*/
	unsigned int zwrocLiczbeGlowic() const
	{
		return liczba_glowic;
	}
	
	/// zwraca liczbe oslonek glowicy
	/**
	\return liczba_oslonek liczba oslonek glowicy
	*/
	unsigned int zwrocLiczbeOslonek() const
	{
		return liczba_oslonek;
	}
	
	/// zwraca liczbe nozykow glowicy
	/**
	\return liczba_nozykow liczba nozykow glowicy
	*/
	unsigned int zwrocLiczbeNozykow() const
	{
		return liczba_nozykow;
	}


	/// operator porownujacy liczbe glowic glowicy
	/**
	\param g glowica
	\return zwraca "true" gdy liczba glowic glowicy jest mniejsza badz rowna, w przeciwnym przypadku zwraca "false"
	*/
	bool operator <= (const Glowica& g) const;
	
	/// operator porownujacy liczbe glowic glowicy
	/**
	\param g glowica
	\return zwraca "true" gdy liczba glowic glowicy jest wieksza badz rowna, w przeciwnym przypadku zwraca "false"
	*/
	bool operator >= (const Glowica& g) const;


	/// wczytuje ze strumienia informacje o glowicy
	/**
	\param wejscie strumien wejsciowy
	*/
	void wczytaj(istream& wejscie);
	
	/// zapisuje do pliku informacje o glowicy
	/**
	\param plik_wyjsciowy plik wyjsciowy do zapisu
	*/
	void zapisz(ofstream& plik_wyjsciowy);

	/// wczytuje z pliku informacje o glowicy
	/**
	\param nazwa_pliku nazwa pliku do odczytu
	*/
	void wczytaj(string nazwa_pliku);


	/// operator strumieniowy wypisujacy informacje o glowicy
	/**
	\param os strumien wyjsciowy
	\param g glowica
	*/
	friend ostream& operator << (ostream& os, const Glowica& g);

	/// operator strumieniowy pobierajacy informacje o glowicy
	/**
	\param is strumien wejsciowy
	\param g glowica
	*/
	friend istream& operator >> (istream& is, Glowica& g);
};