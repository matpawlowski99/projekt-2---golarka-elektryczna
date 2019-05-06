#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "AGD.h"
#include "Akumulator.h"
#include "Glowica.h"
#include "Obudowa.h"

using namespace std;

/// Klasa dziedziczaca po klasie AGD
class GolarkaElektryczna : public AGD
{
private:
	string producent; ///< okresla producenta golarki elektrycznej
	string model; ///< okresla model golarki elektrycznej
	bool stan; ///< okresla stan golarki elektrycznej (0 - wylaczona lub 1 - wlaczona)
	unsigned int waga; ///< okresla wage golarki elektrycznej
	unsigned int cena; ///< okresla cene golarki elektrycznej
	static unsigned int licznik_stworzonych_golarek; ///< zmienna statyczna okreslajaca liczbe stworzonych golarek elektrycznych
	static unsigned int licznik_aktualnie_istniejacych_golarek; ///< zmienna statyczna okreslajaca liczbe aktualnie istniejacych golarek elektrycznych

	Akumulator akumulator; ///< obiekt akumulator
	Obudowa obudowa; ///< obiekt obudowa
	Glowica* glowica; ///< obiekt dynamiczny glowica

public:
	/// konstruktor domyslny golarki elektrycznej
	GolarkaElektryczna();
	
	/// konstruktor z parametrami samej golarki elektrycznej
	GolarkaElektryczna(string producent_golarki, string model_golarki, bool stan_golarki, unsigned int waga_golarki, unsigned int cena_golarki);
	
	/// konstruktor z parametrami golarki elektrycznej, akumulatora i obudowy
	GolarkaElektryczna(string producent_golarki, string model_golarki, bool stan_golarki, unsigned int waga_golarki, unsigned int cena_golarki,
		unsigned int pojemnosc_akumulatora, unsigned int sprawnosc_akumulatora, string elektrolit_akumulatora,
		string material_obudowy, string kolor_obudowy, unsigned int liczba_przyciskow_obudowy);
	
	/// konstruktor z parametrami golarki elektrycznej, akumulatora i obudowy oraz produktu AGD
	GolarkaElektryczna(int kod, string kategoria, string producent_golarki, string model_golarki, bool stan_golarki, unsigned int waga_golarki, unsigned int cena_golarki,
		unsigned int pojemnosc_akumulatora, unsigned int sprawnosc_akumulatora, string elektrolit_akumulatora,
		string material_obudowy, string kolor_obudowy, unsigned int liczba_przyciskow_obudowy);
	
	/// konstruktor kopiujacy golarki elektrycznej
	GolarkaElektryczna(const GolarkaElektryczna& gol);
	
	/// destruktor golarki elektrycznej
	~GolarkaElektryczna();


	/// ustawia producenta golarki elektrycznej
	/**
	\param producent_golarki producent golarki elektrycznej
	*/
	void ustawProducenta(string producent_golarki);

	/// ustawia model golarki elektrycznej
	/**
	\param model_golarki model golarki elektrycznej
	*/
	void ustawModel(string model_golarki);
	
	/// wlacza golarke elektryczna (ustawia jej stan na "1")
	void wlaczGolarke()
	{
		stan = 1; 
	}
	
	/// wylacza golarke elektryczna (ustawia jej stan na "0")
	void wylaczGolarke()
	{
		stan = 0; 
	}
	
	/// ustawia wage golarki elektrycznej
	/**
	\param waga_golarki waga golarki elektrycznej
	*/
	void ustawWage(unsigned int waga_golarki); 
	
	/// ustawia cene golarki elektrycznej
	/**
	\param cena_golarki cena golarki elektrycznej
	*/
	void ustawCene(unsigned int cena_golarki); 


	/// zwraca producenta golarki elektrycznej
	/**
	\return producent producent golarki elektrycznej
	*/
	string zwrocProducenta()
	{
		return producent; 
	}
	
	/// zwraca model golarki elektrycznej
	/**
	\return model model golarki elektrycznej
	*/
	string zwrocModel()
	{
		return model; 
	}
	
	/// zwraca stan golarki elektrycznej
	/**
	\return stan stan golarki elektrycznej ("true" lub "false")
	*/
	bool zwrocStan()
	{
		return stan; 
	}
	
	/// zwraca wage golarki elektrycznej
	/**
	\return waga waga golarki elektrycznej
	*/
	unsigned int zwrocWage()
	{
		return waga; 
	}
	
	/// zwraca cene golarki elektrycznej
	/**
	\return cena cena golarki elektrycznej
	*/
	unsigned int zwrocCene()
	{
		return cena; 
	}
	
	/// statyczna metoda zwracajaca liczbe wszystkich stworzonych golarek elektrycznych
	/**
	\return licznik_stworzonych_golarek liczba wszystkich stworzonych golarek elektrycznych
	*/
	static unsigned int ileStworzonychGolarek()
	{
		return licznik_stworzonych_golarek; 
	}
	
	/// statyczna metoda zwracajaca liczbe aktualnie istniejacych golarek elektrycznych
	/**
	\return licznik_aktualnie_istniejacych_golarek liczba aktualnie istniejacych golarek elektrycznych
	*/
	static unsigned int ileAktualnieIstniejacychGolarek()
	{
		return licznik_aktualnie_istniejacych_golarek; 
	}


	/// opisuje siebie samego
	void opiszSiebie();

	/// wypisuje dane o golarce elektrycznej
	void wypiszInformacje();


	/// zwraca pojemnosc akumulatora
	unsigned int zwrocPojemnoscAkumulatora()
	{
		return akumulator.zwrocPojemnosc(); 
	}
	
	/// zwraca sprawnosc akumulatora
	unsigned int zwrocSprawnoscAkumulatora()
	{
		return akumulator.zwrocSprawnosc(); 
	}
	
	/// zwraca elektrolit akumulatora
	string zwrocElektrolitAkumulatora()
	{
		return akumulator.zwrocElektrolit(); 
	}


	/// zwraca material obudowy
	string zwrocMaterialObudowy()
	{
		return obudowa.zwrocMaterial(); 
	}
	
	/// zwraca kolor obudowy
	string zwrocKolorObudowy()
	{
		return obudowa.zwrocKolor(); 
	}
	
	/// zwraca liczbe przyciskow obudowy
	unsigned int zwrocLiczbePrzyciskowObudowy()
	{
		return obudowa.zwrocLiczbePrzyciskow(); 
	}


	/// wypisuje dane o akumulatorze
	void opiszAkumulator() const;

	/// wypisuje dane o obudowie
	void opiszObudowe() const;

	/// zwraca stan golarki w formie bardziej zrozumialej dla uzytkownika (jako string) 
	string czyWlaczona() const; 


	/// dynamicznie tworzy obiekt glowica
	/**
	\param liczba_glowic liczba glowic glowicy
	\param liczba_oslonek liczba oslonek glowicy
	\param liczba_nozykow liczba nozykow glowicy
	*/
	void zainstalujGlowice(unsigned int liczba_glowic, unsigned int liczba_oslonek, unsigned int liczba_nozykow); 
	
	/// wypisuje dane o glowicy
	void opiszGlowice() const; 
	
	/// usuwa obiekt glowica
	void usunGlowice(); 


	/// operator przypisania
	/**
	\param gol golarka elektryczna
	\return zwraca golarke elektryczna z przypisanymi parametrami
	*/
	GolarkaElektryczna& operator = (const GolarkaElektryczna& gol);
	
	/// operator zamieniajacy obudowe
	/**
	\param o obudowa golarki elektrycznej
	\return zwraca golarke elektryczna z nowa obudowa
	*/
	GolarkaElektryczna& operator - (const Obudowa& o); 
	
	/// operator podmieniajacy akumulator
	/**
	\param a akumulator golarki elektrycznej
	\return zwraca golarke elektryczna z nowym akumulatorem
	*/
	GolarkaElektryczna& operator += (const Akumulator& a); 
	
	/// operator konwertujacy typ zmiennej "cena" na int
	/**
	return cena cena golarki elektrycznej typu int
	*/
	operator int()
	{
		return cena;
	}


	/// wczytuje ze strumienia informacje o golarce elektrycznej
	/**
	\param wejscie strumien wejsciowy
	*/
	void wczytaj(istream& wejscie);
	
	/// zapisuje do pliku informacje o golarce elektrycznej
	/**
	\param plik_wyjsciowy plik wyjsciowy do zapisu
	\param flaga wypisuje rodzaj produktu AGD
	*/
	void zapisz(ofstream& plik_wyjsciowy, bool flaga);
	
	/// wczytuje z pliku informacje o golarce elektrycznej
	/**
	\param nazwa_pliku nazwa pliku do odczytu
	*/
	void wczytaj(string nazwa_pliku);

	
	/// operator strumieniowy wypisujacy informacje o golarce elektrycznej i jej parametrach
	/**
	\param os strumien wyjsciowy
	\param gol golarka elektryczna
	*/
	friend ostream& operator << (ostream& os, const GolarkaElektryczna& gol);
	
	/// operator strumieniowy pobierajacy informacje o golarce elektrycznej i jej parametrach
	/**
	\param is strumien wejsciowy
	\param gol golarka elektryczna
	*/
	friend istream& operator >> (istream& is, GolarkaElektryczna& gol);
};