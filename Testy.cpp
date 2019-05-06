#include <iostream>
#include "Golarka elektryczna.h"

using namespace std;

//static GolarkaElektryczna golarka_elektryczna1; // obiekt statyczny globalny

void testujKlasy()
{
	cout << endl << "\t\t\t\t\tTEST KLAS" << endl << endl;

	{
		GolarkaElektryczna golarka_elektryczna2; // obiekt automatyczny
	}
	GolarkaElektryczna *dyn = new GolarkaElektryczna(); // obiekt dynamiczny
	delete dyn;

	// TEST KONSTRUKTOROW KLASY GLOWNEJ

	GolarkaElektryczna golarka_elektryczna("PHILIPS", "Series 3000", 1, 512, 298, 15, 60, "kwas siarkowy", "plastik", "granatowy", 4);

	{
		// konstruktor bezparametrowy golarki elektrycznej
		GolarkaElektryczna golarka_elektryczna_moja;
		int licznik = 0;

		if (golarka_elektryczna_moja.zwrocProducenta() == "brak danych")
			licznik++;
		else
			cout << "Konstruktor zle ustawil producenta" << endl << "Powinien ustawic: brak danych, ustawil: " << golarka_elektryczna_moja.zwrocProducenta() << endl;

		if (golarka_elektryczna_moja.zwrocModel() == "brak danych")
			licznik++;
		else
			cout << "Konstruktor zle ustawil model" << endl << "Powinien ustawic: brak danych, ustawil: " << golarka_elektryczna_moja.zwrocModel() << endl;

		if (golarka_elektryczna_moja.zwrocStan() == 0)
			licznik++;
		else
			cout << "Konstruktor zle ustawil stan" << endl << "Powinien ustawic: 0, ustawil: " << golarka_elektryczna_moja.zwrocStan() << endl;

		if (golarka_elektryczna_moja.zwrocWage() == 0)
			licznik++;
		else
			cout << "Konstruktor zle ustawil wage" << endl << "Powinien ustawic: 0, ustawil: " << golarka_elektryczna_moja.zwrocWage() << endl;

		if (golarka_elektryczna_moja.zwrocCene() == 0)
			licznik++;
		else
			cout << "Konstruktor zle ustawil cene" << endl << "Powinien ustawic: 0, ustawil: " << golarka_elektryczna_moja.zwrocCene() << endl;

		if (licznik == 5)
			cout << endl << "Konstruktor bezparametrowy dziala prawidlowo" << endl << endl;
		else
			cout << endl << "Konstruktor bezparametrowy dziala nieprawidlowo" << endl << endl;
	}

	{
		// konstruktor z parametrami samej golarki elektrycznej
		GolarkaElektryczna golarka_elektryczna_moja("Test", "Tescik", 1, 300, 196);
		int licznik = 0;

		if (golarka_elektryczna_moja.zwrocProducenta() == "Test")
			licznik++;
		else
			cout << "Konstruktor zle ustawil producenta" << endl << "Powinien ustawic: Test, ustawil: " << golarka_elektryczna_moja.zwrocProducenta() << endl;

		if (golarka_elektryczna_moja.zwrocModel() == "Tescik")
			licznik++;
		else
			cout << "Konstruktor zle ustawil model" << endl << "Powinien ustawic: Tescik, ustawil: " << golarka_elektryczna_moja.zwrocModel() << endl;

		if (golarka_elektryczna_moja.zwrocStan() == 1)
			licznik++;
		else
			cout << "Konstruktor zle ustawil stan" << endl << "Powinien ustawic: 1, ustawil: " << golarka_elektryczna_moja.zwrocStan() << endl;

		if (golarka_elektryczna_moja.zwrocWage() == 300)
			licznik++;
		else
			cout << "Konstruktor zle ustawil wage" << endl << "Powinien ustawic: 300, ustawil: " << golarka_elektryczna_moja.zwrocWage() << endl;

		if (golarka_elektryczna_moja.zwrocCene() == 196)
			licznik++;
		else
			cout << "Konstruktor zle ustawil cene" << endl << "Powinien ustawic: 196, ustawil: " << golarka_elektryczna_moja.zwrocCene() << endl;

		if (licznik == 5)
			cout << endl << "Konstruktor z parametrami samej golarki elektrycznej dziala prawidlowo" << endl << endl;
		else
			cout << endl << "Konstruktor z parametrami samej golarki elektrycznej dziala nieprawidlowo" << endl << endl;
	}

	{
		// konstruktor z parametrami calej golarki elektrycznej
		GolarkaElektryczna golarka_elektryczna_moja("PHILIPS", "Series 2000", 1, 512, 298, 15, 60, "kwas siarkowy", "plastik", "granatowy", 4);
		int licznik = 0;

		if (golarka_elektryczna_moja.zwrocProducenta() == "PHILIPS")
			licznik++;
		else
			cout << "Konstruktor zle ustawil producenta" << endl << "Powinien ustawic: PHILIPS, ustawil: " << golarka_elektryczna_moja.zwrocProducenta() << endl;

		if (golarka_elektryczna_moja.zwrocModel() == "Series 2000")
			licznik++;
		else
			cout << "Konstruktor zle ustawil model" << endl << "Powinien ustawic: Series 2000, ustawil: " << golarka_elektryczna_moja.zwrocModel() << endl;

		if (golarka_elektryczna_moja.zwrocStan() == 1)
			licznik++;
		else
			cout << "Konstruktor zle ustawil stan" << endl << "Powinien ustawic: 1, ustawil: " << golarka_elektryczna_moja.zwrocStan() << endl;

		if (golarka_elektryczna_moja.zwrocWage() == 512)
			licznik++;
		else
			cout << "Konstruktor zle ustawil wage" << endl << "Powinien ustawic: 512, ustawil: " << golarka_elektryczna_moja.zwrocWage() << endl;

		if (golarka_elektryczna_moja.zwrocCene() == 298)
			licznik++;
		else
			cout << "Konstruktor zle ustawil cene" << endl << "Powinien ustawic: 298, ustawil: " << golarka_elektryczna_moja.zwrocCene() << endl;

		if (golarka_elektryczna_moja.zwrocPojemnoscAkumulatora() == 15)
			licznik++;
		else
			cout << "Konstruktor zle ustawil pojemnosc akumulatora" << endl << "Powinien ustawic: 15, ustawil: " << golarka_elektryczna_moja.zwrocPojemnoscAkumulatora() << endl;

		if (golarka_elektryczna_moja.zwrocSprawnoscAkumulatora() == 60)
			licznik++;
		else
			cout << "Konstruktor zle ustawil sprawnosc akumulatora" << endl << "Powinien ustawic: 60, ustawil: " << golarka_elektryczna_moja.zwrocSprawnoscAkumulatora() << endl;

		if (golarka_elektryczna_moja.zwrocElektrolitAkumulatora() == "kwas siarkowy")
			licznik++;
		else
			cout << "Konstruktor zle ustawil elektrolit akumulatora" << endl << "Powinien ustawic: kwas siarkowy, ustawil: " << golarka_elektryczna_moja.zwrocElektrolitAkumulatora() << endl;

		if (golarka_elektryczna_moja.zwrocMaterialObudowy() == "plastik")
			licznik++;
		else
			cout << "Konstruktor zle ustawil material obudowy" << endl << "Powinien ustawic: plastik, ustawil: " << golarka_elektryczna_moja.zwrocMaterialObudowy() << endl;

		if (golarka_elektryczna_moja.zwrocKolorObudowy() == "granatowy")
			licznik++;
		else
			cout << "Konstruktor zle ustawil kolor obudowy" << endl << "Powinien ustawic: granatowy, ustawil: " << golarka_elektryczna_moja.zwrocKolorObudowy() << endl;

		if (golarka_elektryczna_moja.zwrocLiczbePrzyciskowObudowy() == 4)
			licznik++;
		else
			cout << "Konstruktor zle ustawil liczbe przyciskow obudowy" << endl << "Powinien ustawic: 4, ustawil: " << golarka_elektryczna_moja.zwrocLiczbePrzyciskowObudowy() << endl;

		if (licznik == 11)
			cout << endl << "Konstruktor z parametrami calej golarki elektrycznej dziala prawidlowo" << endl << endl;
		else
			cout << endl << "Konstruktor z parametrami calej golarki elektrycznej dziala nieprawidlowo" << endl << endl;
	}

	{
		// konstruktor kopiujacy golarki elektrycznej
		GolarkaElektryczna golarka("PHILIPS", "Series 2000", 1, 512, 298, 15, 60, "kwas siarkowy", "plastik", "granatowy", 4);
		GolarkaElektryczna golarka_elektryczna_moja(golarka);
		int licznik = 0;

		if (golarka_elektryczna_moja.zwrocProducenta() == "PHILIPS")
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil producenta" << endl << "Powinien ustawic: PHILIPS, ustawil: " << golarka_elektryczna_moja.zwrocProducenta() << endl;

		if (golarka_elektryczna_moja.zwrocModel() == "Series 2000")
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil model" << endl << "Powinien ustawic: Series 2000, ustawil: " << golarka_elektryczna_moja.zwrocModel() << endl;

		if (golarka_elektryczna_moja.zwrocStan() == 1)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil stan" << endl << "Powinien ustawic: 1, ustawil: " << golarka_elektryczna_moja.zwrocStan() << endl;

		if (golarka_elektryczna_moja.zwrocWage() == 512)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil wage" << endl << "Powinien ustawic: 512, ustawil: " << golarka_elektryczna_moja.zwrocWage() << endl;

		if (golarka_elektryczna_moja.zwrocCene() == 298)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil cene" << endl << "Powinien ustawic: 298, ustawil: " << golarka_elektryczna_moja.zwrocCene() << endl;

		if (golarka_elektryczna_moja.zwrocPojemnoscAkumulatora() == 15)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil pojemnosc akumulatora" << endl << "Powinien ustawic: 15, ustawil: " << golarka_elektryczna_moja.zwrocPojemnoscAkumulatora() << endl;

		if (golarka_elektryczna_moja.zwrocSprawnoscAkumulatora() == 60)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil sprawnosc akumulatora" << endl << "Powinien ustawic: 60, ustawil: " << golarka_elektryczna_moja.zwrocSprawnoscAkumulatora() << endl;

		if (golarka_elektryczna_moja.zwrocElektrolitAkumulatora() == "kwas siarkowy")
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil elektrolit akumulatora" << endl << "Powinien ustawic: kwas siarkowy, ustawil: " << golarka_elektryczna_moja.zwrocElektrolitAkumulatora() << endl;

		if (golarka_elektryczna_moja.zwrocMaterialObudowy() == "plastik")
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil material obudowy" << endl << "Powinien ustawic: plastik, ustawil: " << golarka_elektryczna_moja.zwrocMaterialObudowy() << endl;

		if (golarka_elektryczna_moja.zwrocKolorObudowy() == "granatowy")
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil kolor obudowy" << endl << "Powinien ustawic: granatowy, ustawil: " << golarka_elektryczna_moja.zwrocKolorObudowy() << endl;

		if (golarka_elektryczna_moja.zwrocLiczbePrzyciskowObudowy() == 4)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil liczbe przyciskow obudowy" << endl << "Powinien ustawic: 4, ustawil: " << golarka_elektryczna_moja.zwrocLiczbePrzyciskowObudowy() << endl;

		if (licznik == 11)
			cout << endl << "Konstruktor kopiujacy golarki elektrycznej, akumulatora i obudowy dziala prawidlowo" << endl << endl;
		else
			cout << endl << "Konstruktor kopiujacy golarki elektrycznej, akumulatora i obudowy dziala nieprawidlowo" << endl << endl;
	}

	{
		// konstruktor bezparametrowy akumulatora
		cout << endl;
		Akumulator akumulator_moj;
		int licznik = 0;

		if (akumulator_moj.zwrocPojemnosc() == 0)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil pojemnosc" << endl << "Powinien ustawic: 0, ustawil: " << akumulator_moj.zwrocPojemnosc() << endl << endl;

		if (akumulator_moj.zwrocSprawnosc() == 0)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil sprawnosc" << endl << "Powinien ustawic: 0, ustawil: " << akumulator_moj.zwrocSprawnosc() << endl << endl;

		if (akumulator_moj.zwrocElektrolit() == "brak danych")
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil elektrolit" << endl << "Powinien ustawic: brak danych, ustawil: " << akumulator_moj.zwrocElektrolit() << endl << endl;

		if (licznik = 3)
			cout << endl << "Konstruktor bezparametrowy akumulatora dziala prawidlowo" << endl << endl;
		else
			cout << endl << "Konstruktor bezparametrowy akumulatora dzia³a nieprawidlowo" << endl << endl;
	}

	{
		// konstruktor z parametrami akumulatora
		Akumulator akumulator_moj(10, 70, "sol litowa");
		int licznik = 0;

		if (akumulator_moj.zwrocPojemnosc() == 10)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil pojemnosc" << endl << "Powinien ustawic: 10, ustawil: " << akumulator_moj.zwrocPojemnosc() << endl << endl;

		if (akumulator_moj.zwrocSprawnosc() == 70)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil sprawnosc" << endl << "Powinien ustawic: 70, ustawil: " << akumulator_moj.zwrocSprawnosc() << endl << endl;

		if (akumulator_moj.zwrocElektrolit() == "sol litowa")
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil elektrolit" << endl << "Powinien ustawic: sol litowa, ustawil: " << akumulator_moj.zwrocElektrolit() << endl << endl;

		if (licznik = 3)
			cout << endl << "Konstruktor z parametrami akumulatora dziala prawidlowo" << endl << endl;
		else
			cout << endl << "Konstruktor z parametrami akumulatora dzia³a nieprawidlowo" << endl << endl;
	}

	{
		// konstruktor kopiujacy akumulatora
		Akumulator akumulator(10, 70, "sol litowa");
		Akumulator akumulator_moj(akumulator);
		int licznik = 0;

		if (akumulator_moj.zwrocPojemnosc() == 10)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil pojemnosc" << endl << "Powinien ustawic: 10, ustawil: " << akumulator_moj.zwrocPojemnosc() << endl << endl;

		if (akumulator_moj.zwrocSprawnosc() == 70)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil sprawnosc" << endl << "Powinien ustawic: 70, ustawil: " << akumulator_moj.zwrocSprawnosc() << endl << endl;

		if (akumulator_moj.zwrocElektrolit() == "sol litowa")
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil elektrolit" << endl << "Powinien ustawic: sol litowa, ustawil: " << akumulator_moj.zwrocElektrolit() << endl << endl;

		if (licznik = 3)
			cout << endl << "Konstruktor kopiujacy akumulatora dziala prawidlowo" << endl << endl;
		else
			cout << endl << "Konstruktor kopiujacy akumulatora dzia³a nieprawidlowo" << endl << endl;
	}

	{
		// konstruktor bezparametrowy obudowy
		cout << endl;
		Obudowa obudowa_moja;
		int licznik = 0;

		if (obudowa_moja.zwrocMaterial() == "brak danych")
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil material" << endl << "Powinien ustawic: brak danych, ustawil: " << obudowa_moja.zwrocMaterial() << endl << endl;

		if (obudowa_moja.zwrocKolor() == "brak danych")
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil kolor" << endl << "Powinien ustawic: brak danych, ustawil: " << obudowa_moja.zwrocKolor() << endl << endl;

		if (obudowa_moja.zwrocLiczbePrzyciskow() == 0)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil liczbe przyciskow" << endl << "Powinien ustawic: 0, ustawil: " << obudowa_moja.zwrocLiczbePrzyciskow() << endl << endl;

		if (licznik = 3)
			cout << endl << "Konstruktor bezparametrowy obudowy dziala prawidlowo" << endl << endl;
		else
			cout << endl << "Konstruktor bezparametrowy obudowy dzia³a nieprawidlowo" << endl << endl;
	}

	{
		// konstruktor z parametrami obudowy
		Obudowa obudowa_moja("metal", "czarny", 5);
		int licznik = 0;

		if (obudowa_moja.zwrocMaterial() == "metal")
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil material" << endl << "Powinien ustawic: metal, ustawil: " << obudowa_moja.zwrocMaterial() << endl << endl;

		if (obudowa_moja.zwrocKolor() == "czarny")
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil kolor" << endl << "Powinien ustawic: czarny, ustawil: " << obudowa_moja.zwrocKolor() << endl << endl;

		if (obudowa_moja.zwrocLiczbePrzyciskow() == 5)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil liczbe przyciskow" << endl << "Powinien ustawic: 5, ustawil: " << obudowa_moja.zwrocLiczbePrzyciskow() << endl << endl;

		if (licznik = 3)
			cout << endl << "Konstruktor z parametrami obudowy dziala prawidlowo" << endl << endl;
		else
			cout << endl << "Konstruktor z parametrami obudowy dzia³a nieprawidlowo" << endl << endl;
	}

	{
		// konstruktor kopiujacy obudowy
		Obudowa obudowa("metal", "czarny", 5);
		Obudowa obudowa_moja(obudowa);
		int licznik = 0;

		if (obudowa_moja.zwrocMaterial() == "metal")
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil material" << endl << "Powinien ustawic: metal, ustawil: " << obudowa_moja.zwrocMaterial() << endl << endl;

		if (obudowa_moja.zwrocKolor() == "czarny")
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil kolor" << endl << "Powinien ustawic: czarny, ustawil: " << obudowa_moja.zwrocKolor() << endl << endl;

		if (obudowa_moja.zwrocLiczbePrzyciskow() == 5)
			licznik++;
		else
			cout << endl << "Konstruktor zle ustawil liczbe przyciskow" << endl << "Powinien ustawic: 5, ustawil: " << obudowa_moja.zwrocLiczbePrzyciskow() << endl << endl;

		if (licznik = 3)
			cout << endl << "Konstruktor kopiujacy obudowy dziala prawidlowo" << endl << endl;
		else
			cout << endl << "Konstruktor kopiujacy obudowy dzia³a nieprawidlowo" << endl << endl;
	}

	// METODY GOLARKI ELEKTRYCZNEJ
	//("PHILIPS", "Series 3000", 1, 512, 298, 15, 60, "kwas siarkowy", "plastik", "granatowy", 4)
	cout << endl << endl << "METODY GOLARKI ELEKTRYCZNEJ" << endl;

	if (GolarkaElektryczna::ileAktualnieIstniejacychGolarek() == 2)
		cout << "Metoda ileAktualnieIstniejacychGolarek() dziala prawidlowo (na ten moment istnieja 2 golarki)" << endl;
	else
		cout << "Metoda ileAktualnieIstniejacychGolarek() dziala nieprawidlowo (na ten moment powinny istniec 2 golarki)" << endl;

	if (GolarkaElektryczna::ileStworzonychGolarek() == 9)
		cout << "Metoda ileStworzonychGolarek() dziala prawidlowo (do tego momentu zaistnialo 9 golarek)" << endl;
	else
		cout << "Metoda ileStworzoonychGolarek() dziala nieprawidlowo (do tego momentu powinno zaistniec 9 golarek)" << endl;

	golarka_elektryczna.ustawProducenta("REMINGTON");
	if (golarka_elektryczna.zwrocProducenta() == "REMINGTON")
		cout << "Metody ustawProducenta() i zwrocProducenta() dzialaja prawidlowo" << endl;
	else
		cout << "Metody ustawProducenta() i zwrocProducenta() dzialaja nieprawidlowo" << endl;

	golarka_elektryczna.ustawModel("R9 Ultimate");
	if (golarka_elektryczna.zwrocModel() == "R9 Ultimate")
		cout << "Metody ustawModel() i zwrocModel() dzialaja prawidlowo" << endl;
	else
		cout << "Metody ustawModel() i zwrocModel() dzialaja nieprawidlowo" << endl;

	golarka_elektryczna.wlaczGolarke();
	if (golarka_elektryczna.zwrocStan() == 1)
		cout << "Metody wlaczGolarke() i zwrocStan() dzialaja prawidlowo" << endl;
	else
		cout << "Metody wlaczGolarke() i zwrocStan() dzialaja nieprawidlowo" << endl;

	golarka_elektryczna.wylaczGolarke();
	if (golarka_elektryczna.zwrocStan() == 0)
		cout << "Metody wylaczGolarke() i zwrocStan() dzialaja prawidlowo" << endl;
	else
		cout << "Metody wylaczGolarke() i zwrocStan() dzialaja nieprawidlowo" << endl;

	golarka_elektryczna.ustawWage(490);
	if (golarka_elektryczna.zwrocWage() == 490)
		cout << "Metody ustawWage() i zwrocWage() dzialaja prawidlowo" << endl;
	else
		cout << "Metody ustawWage() i zwrocWage() dzialaja nieprawidlowo" << endl;

	golarka_elektryczna.ustawCene(350);
	if (golarka_elektryczna.zwrocCene() == 350)
		cout << "Metody ustawCene() i zwrocCene() dzialaja prawidlowo" << endl;
	else
		cout << "Metody ustawCene() i zwrocCene() dzialaja nieprawidlowo" << endl;

	if (golarka_elektryczna.czyWlaczona() == "Golarka wylaczona")
		cout << "Metoda czyWlaczona() dziala prawidlowo" << endl;
	else
		cout << "Metoda czyWlaczona() dziala nieprawidlowo" << endl;

	cout << endl << "Metoda opiszAkumulator()" << endl;
	golarka_elektryczna.opiszAkumulator();

	cout << endl << "Metoda opiszObudowe()" << endl;
	golarka_elektryczna.opiszObudowe();

	cout << endl;

	if (golarka_elektryczna.zwrocPojemnoscAkumulatora() == 15)
		cout << "Metoda zwrocPojemnoscAkumulatora() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocPojemnoscAkumulatora() dziala nieprawidlowo" << endl << "Powinno zwrocic: 15, zwrocilo: " << golarka_elektryczna.zwrocPojemnoscAkumulatora() << endl;

	if (golarka_elektryczna.zwrocSprawnoscAkumulatora() == 60)
		cout << "Metoda zwrocSprawnoscAkumulatora() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocSprawnoscAkumulatora() dziala nieprawidlowo" << endl << "Powinno zwrocic: 60, zwrocilo: " << golarka_elektryczna.zwrocSprawnoscAkumulatora() << endl;

	if (golarka_elektryczna.zwrocElektrolitAkumulatora() == "kwas siarkowy")
		cout << "Metoda zwrocElektrolitAkumulatora() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocElektrolitAkumulatora() dziala nieprawidlowo" << endl << "Powinno zwrocic: kwas siarkowy, zwrocilo: " << golarka_elektryczna.zwrocElektrolitAkumulatora() << endl;

	if (golarka_elektryczna.zwrocMaterialObudowy() == "plastik")
		cout << "Metoda zwrocMaterialObudowy() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocMaterialObudowy() dziala nieprawidlowo" << endl << "Powinno zwrocic: plastik, zwrocilo: " << golarka_elektryczna.zwrocMaterialObudowy() << endl;

	if (golarka_elektryczna.zwrocKolorObudowy() == "granatowy")
		cout << "Metoda zwrocKolorObudowy() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocKolorObudowy() dziala nieprawidlowo" << endl << "Powinno zwrocic: granatowy, zwrocilo: " << golarka_elektryczna.zwrocKolorObudowy() << endl;

	if (golarka_elektryczna.zwrocLiczbePrzyciskowObudowy() == 4)
		cout << "Metoda zwrocLiczbePrzyciskowObudowy() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocLiczbePrzyciskowObudowy() dziala nieprawidlowo" << endl << "Powinno zwrocic: 4, zwrocilo: " << golarka_elektryczna.zwrocLiczbePrzyciskowObudowy() << endl;

	cout << endl;

	cout << "Metoda zainstalujGlowice(): ";
	golarka_elektryczna.zainstalujGlowice(3, 3, 2);

	cout << "Metoda opiszGlowice(): ";
	golarka_elektryczna.opiszGlowice();

	cout << "Metoda usunGlowice(): ";
	golarka_elektryczna.usunGlowice();

	cout << endl;

	// METODY AKUMULATORA
	Akumulator akumulator(25, 80, "poliakrylonitryl");
	cout << endl << "METODY AKUMULATORA" << endl;

	if (akumulator.zwrocPojemnosc() == 25)
		cout << "Metoda zwrocPojemnosc() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocPojemnosc() dziala nieprawidlowo" << endl << "Powinno zwrocic: 25, zwrocilo: " << akumulator.zwrocPojemnosc() << endl;

	if (akumulator.zwrocSprawnosc() == 80)
		cout << "Metoda zwrocSprawnosc() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocSprawnosc() dziala nieprawidlowo" << endl << "Powinno zwrocic: 80, zwrocilo: " << akumulator.zwrocSprawnosc() << endl;

	if (akumulator.zwrocElektrolit() == "poliakrylonitryl")
		cout << "Metoda zwrocElektrolit() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocElektrolit() dziala nieprawidlowo" << endl << "Powinno zwrocic: poliakrylonitryl, zwrocilo: " << akumulator.zwrocElektrolit() << endl;


	akumulator.ustawPojemnosc(20);
	if (akumulator.zwrocPojemnosc() == 20)
		cout << "Metoda ustawPojemnosc() dziala prawidlowo" << endl;
	else
		cout << "Metoda ustawPojemnosc() dziala nieprawidlowo" << endl;

	akumulator.ustawSprawnosc(85);
	if (akumulator.zwrocSprawnosc() == 85)
		cout << "Metoda ustawSprawnosc() dziala prawidlowo" << endl;
	else
		cout << "Metoda ustawSprawnosc() dziala nieprawidlowo" << endl;

	akumulator.ustawElektrolit("kwas chlorowy");
	if (akumulator.zwrocElektrolit() == "kwas chlorowy")
		cout << "Metoda ustawElektrolit() dziala prawidlowo" << endl;
	else
		cout << "Metoda ustawElektrolit() dziala nieprawidlowo" << endl;

	// METODY OBUDOWY
	Obudowa obudowa("metal", "srebrny", 2);
	cout << endl << "METODY OBUDOWY" << endl;

	if (obudowa.zwrocMaterial() == "metal")
		cout << "Metoda zwrocMaterial() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocMaterial() dziala nieprawidlowo" << endl << "Powinno zwrocic: metal, zwrocilo: " << obudowa.zwrocMaterial() << endl;

	if (obudowa.zwrocKolor() == "srebrny")
		cout << "Metoda zwrocKolor() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocKolor() dziala nieprawidlowo" << endl << "Powinno zwrocic: srebrny, zwrocilo: " << obudowa.zwrocKolor() << endl;

	if (obudowa.zwrocLiczbePrzyciskow() == 2)
		cout << "Metoda zwrocLiczbePrzyciskow() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocLiczbePrzyciskow() dziala nieprawidlowo" << endl << "Powinno zwrocic: 2, zwrocilo: " << obudowa.zwrocLiczbePrzyciskow() << endl;


	obudowa.ustawMaterial("guma");
	if (obudowa.zwrocMaterial() == "guma")
		cout << "Metoda ustawMaterial() dziala prawidlowo" << endl;
	else
		cout << "Metoda ustawMaterial() dziala nieprawidlowo" << endl;

	obudowa.ustawKolor("bialy");
	if (obudowa.zwrocKolor() == "bialy")
		cout << "Metoda ustawKolor() dziala prawidlowo" << endl;
	else
		cout << "Metoda ustawKolor() dziala nieprawidlowo" << endl;

	obudowa.ustawLiczbePrzyciskow(8);
	if (obudowa.zwrocLiczbePrzyciskow() == 8)
		cout << "Metoda ustawLiczbePrzyciskow() dziala prawidlowo" << endl;
	else
		cout << "Metoda ustawLiczbePrzyciskow() dziala nieprawidlowo" << endl;

	// METODY GLOWICY
	Glowica glowica(2, 2, 4);
	cout << endl << "METODY GLOWICY" << endl;

	if (glowica.zwrocLiczbeGlowic() == 2)
		cout << "Metoda zwrocLiczbeGlowic() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocLiczbeGlowic() dziala nieprawidlowo" << endl << "Powinno zwrocic: 2, zwrocilo: " << glowica.zwrocLiczbeGlowic() << endl;

	if (glowica.zwrocLiczbeOslonek() == 2)
		cout << "Metoda zwrocLiczbeOslonek() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocLiczbeOslonek() dziala nieprawidlowo" << endl << "Powinno zwrocic: 2, zwrocilo: " << glowica.zwrocLiczbeOslonek() << endl;

	if (glowica.zwrocLiczbeNozykow() == 4)
		cout << "Metoda zwrocLiczbeNozykow() dziala prawidlowo" << endl;
	else
		cout << "Metoda zwrocLiczbeNozykow() dziala nieprawidlowo" << endl << "Powinno zwrocic: 4, zwrocilo: " << glowica.zwrocLiczbeNozykow() << endl;


	glowica.ustawLiczbeGlowic(1);
	if (glowica.zwrocLiczbeGlowic() == 1)
		cout << "Metoda ustawLiczbeGlowic() dziala prawidlowo" << endl;
	else
		cout << "Metoda ustawLiczbeGlowic() dziala nieprawidlowo" << endl;

	glowica.ustawLiczbeOslonek(1);
	if (glowica.zwrocLiczbeOslonek() == 1)
		cout << "Metoda ustawLiczbeOslonek() dziala prawidlowo" << endl;
	else
		cout << "Metoda ustawLiczbeOslonek() dziala nieprawidlowo" << endl;

	glowica.ustawLiczbeNozykow(2);
	if (glowica.zwrocLiczbeNozykow() == 2)
		cout << "Metoda ustawLiczbeNozykow() dziala prawidlowo" << endl;
	else
		cout << "Metoda ustawLiczbeNozykow() dziala nieprawidlowo" << endl;
}

void testujOperatory()
{
	cout << endl << endl << "\t\t\t\t\tTEST OPERATOROW" << endl << endl;

	GolarkaElektryczna golarka;
	GolarkaElektryczna golarka1("PHILIPS", "Series 3000", 1, 512, 298, 15, 60, "kwas siarkowy", "plastik", "granatowy", 4);
	GolarkaElektryczna golarka2("REMINGTON", "R9", 1, 430, 338, 20, 70, "sol litowa", "metal", "rozowy", 2);
	GolarkaElektryczna golarka3("BRAUN", "3040", 1, 380, 412, 25, 75, "poliakrylonitryl", "guma", "szary", 3);
	GolarkaElektryczna golarka4(golarka1);

	Akumulator akumulator1(30, 65, "kwas chlorowy");
	Akumulator akumulator2(10, 55, "kwas siarkowy");
	Akumulator akumulator3(akumulator1);

	Obudowa obudowa1("plastik", "czerwony", 5);
	Obudowa obudowa2("szklo", "bialy", 3);
	Obudowa obudowa3(obudowa1);

	Glowica glowica1(1, 2, 3);
	Glowica glowica2(3, 3, 6);
	Glowica glowica3(glowica1);

	cout << endl;

	golarka = golarka2;
	if (golarka.zwrocProducenta() == "REMINGTON" && golarka.zwrocModel() == "R9" && golarka.zwrocStan() == 1 && golarka.zwrocWage() == 430 && golarka.zwrocCene() == 338 && golarka.zwrocPojemnoscAkumulatora() == 20 && golarka.zwrocSprawnoscAkumulatora() == 70 && golarka.zwrocElektrolitAkumulatora() == "sol litowa" && golarka.zwrocMaterialObudowy() == "metal" && golarka.zwrocKolorObudowy() == "rozowy" && golarka.zwrocLiczbePrzyciskowObudowy() == 2)
		cout << "Operator przypisania = dla golarki elektrycznej dziala prawidlowo" << endl;
	else
		cout << "Operator przypisania = dla golarki elektrycznej dziala nieprawidlowo" << endl;

	golarka4 += akumulator1;
	if (golarka4.zwrocPojemnoscAkumulatora() == 30 && golarka4.zwrocSprawnoscAkumulatora() == 65 && golarka4.zwrocElektrolitAkumulatora() == "kwas chlorowy")
		cout << "Operator golarki elektrycznej += dla akumulatora dziala prawidlowo" << endl;
	else
		cout << "Operator golarki elektrycznej += dla akumulatora dziala nieprawidlowo" << endl;

	golarka3 = golarka3 - obudowa1;
	if (golarka3.zwrocMaterialObudowy() == "plastik" && golarka3.zwrocKolorObudowy() == "czerwony" && golarka3.zwrocLiczbePrzyciskowObudowy() == 5)
		cout << "Operator golarki elektrycznej - dla obudowy dziala prawidlowo" << endl;
	else
		cout << "Operator golarki elektrycznej - dla obudowy dziala nieprawidlowo" << endl;

	cout << endl;

	if (akumulator3 == akumulator1)
		cout << "Operator == dla akumulatora dziala prawidlowo" << endl;
	else
		cout << "Operator == dla akumulatora dziala nieprawidlowo" << endl;

	if (akumulator1 > akumulator2)
		cout << "Operator > dla akumulatora dziala prawidlowo" << endl;
	else
		cout << "Operator > dla akumulatora dziala nieprawidlowo" << endl;

	if (akumulator2 < akumulator3)
		cout << "Operator < dla akumulatora dziala prawidlowo" << endl;
	else
		cout << "Operator < dla akumulatora dziala nieprawidlowo" << endl;

	++(obudowa2);
	if (obudowa2.zwrocLiczbePrzyciskow() == 4)
		cout << "Operator ++ dla obudowy dziala prawidlowo" << endl;
	else
		cout << "Operator ++ dla obudowy dziala nieprawidlowo" << endl;

	if (glowica2 >= glowica1)
		cout << "Operator >= dla glowicy dziala prawidlowo" << endl;
	else
		cout << "Operator >= dla glowicy dziala nieprawidlowo" << endl;

	if (glowica3 <= glowica1)
		cout << "Operator <= dla glowicy dziala prawidlowo" << endl;
	else
		cout << "Operator <= dla glowicy dziala nieprawidlowo" << endl;

	cout << endl;

	if ((int)golarka1 == 298)
		cout << "Operator konwersji na typ int dla golarki elektrycznej dziala prawidlowo";
	else
		cout << "Operator konwersji na typ int dla golarki elektrycznej dziala nieprawidlowo";

	cout << endl;

	cout << endl << "Operator strumieniowy << golarki elektrycznej:" << endl;
	cout << golarka1 << endl;
	cout << endl << "Operator strumieniowy << akumulatora:" << endl;
	cout << akumulator1 << endl;
	cout << endl << "Operator strumieniowy << obudowy:" << endl;
	cout << obudowa1 << endl;
	cout << endl << "Operator strumieniowy << glowicy:" << endl;
	cout << glowica1 << endl;
}