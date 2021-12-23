#include<iostream>
using namespace std;
struct elem {
	int value;
	elem* next;
	elem* prev;
};
struct List {
	elem* ListaPierwszy;
	elem* ListaOstatni;
	elem* KolejkaPierwszy;
	elem* KolejkaOstatni;
};
void generujListe(List* Lista, int wartosc) {
	elem* nowy = new elem;
	nowy->value = wartosc;
	nowy->next = NULL;
	nowy->prev = NULL;
	Lista->ListaPierwszy = nowy;
	Lista->ListaOstatni = nowy;
}
void dodajNaPoczatekListy(List* Lista, int wartosc) {
	//brak elementow
	if (Lista->ListaPierwszy == 0) {
		generujListe(Lista, wartosc);
	}
	//jeden element
	else if (Lista->ListaPierwszy == Lista->ListaOstatni) {
		elem* nowy = new elem;
		nowy->value = wartosc;
		nowy->next = Lista->ListaOstatni;
		nowy->prev = Lista->ListaOstatni;
		Lista->ListaOstatni->next = nowy;
		Lista->ListaOstatni->prev = nowy;
		Lista->ListaPierwszy = nowy;
	}
	//2 lub wiecej elementow
	else {
		elem* nowy = new elem;
		nowy->value = wartosc;
		nowy->prev = Lista->ListaOstatni;
		Lista->ListaOstatni->next = nowy;
		nowy->next = Lista->ListaPierwszy;
		Lista->ListaPierwszy->prev = nowy;
		Lista->ListaPierwszy = Lista->ListaPierwszy->prev;
	}
}
void dodajNaKoniecListy(List* Lista, int wartosc) {
	//brak elementow
	if (Lista->ListaPierwszy == 0) {
		generujListe(Lista, wartosc);
	}
	//jeden element
	else if (Lista->ListaPierwszy == Lista->ListaOstatni) {
		elem* nowy = new elem;
		nowy->value = wartosc;
		nowy->next = Lista->ListaPierwszy;
		nowy->prev = Lista->ListaPierwszy;
		Lista->ListaPierwszy->next = nowy;
		Lista->ListaPierwszy->prev = nowy;
		Lista->ListaOstatni = nowy;
	}
	//2 lub wiecej elementow
	else {
		elem* nowy = new elem;
		nowy->value = wartosc;
		nowy->next = Lista->ListaPierwszy;
		nowy->prev = Lista->ListaOstatni;
		Lista->ListaPierwszy->prev = nowy;
		Lista->ListaOstatni->next = nowy;
		Lista->ListaOstatni = Lista->ListaOstatni->next;
	}
}
void drukujNormalnie(List* Lista) {
	if (Lista->ListaPierwszy != 0) {
		elem* drukowany;
		drukowany = Lista->ListaPierwszy;
		while (drukowany != Lista->ListaOstatni) {
			cout << drukowany->value << " ";
			drukowany = drukowany->next;
		}
		cout << Lista->ListaOstatni->value << endl;
	}
	else
		cout << "NULL" << endl;
}
void drukujOdTylu(List* Lista) {
	if (Lista->ListaOstatni != 0) {
		elem* drukowany;
		drukowany = Lista->ListaOstatni;
		while (drukowany != Lista->ListaPierwszy) {
			cout << drukowany->value << " ";
			drukowany = drukowany->prev;
		}
		cout << Lista->ListaPierwszy->value << endl;
	}
	else
		cout << "NULL" << endl;
}
void drukujKolejke(List* Lista) {
	if (Lista->KolejkaPierwszy != 0) {
		elem* drukowany;
		drukowany = Lista->KolejkaPierwszy;
		while (drukowany != Lista->KolejkaOstatni) {
			cout << drukowany->value << " ";
			drukowany = drukowany->prev;
		}
		cout << Lista->KolejkaOstatni->value << endl;
	}
	else
		cout << "NULL" << endl;
}
int zwrocDlugoscListy(List* Lista) {
	int ilosc = 0;
	elem* Elem;
	if (Lista->ListaPierwszy != 0) {
		ilosc++;
		Elem = Lista->ListaPierwszy;
		while (Elem != Lista->ListaOstatni) {
			ilosc++;
			Elem = Elem->next;
		}
		return ilosc;

	}
	else
		return 0;
}
int zwrocDlugoscKolejki(List* Lista) {
	int ilosc = 0;
	elem* Elem;
	if (Lista->KolejkaPierwszy != 0) {
		ilosc++;
		Elem = Lista->KolejkaPierwszy;
		while (Elem != Lista->KolejkaOstatni) {
			ilosc++;
			Elem = Elem->prev;
		}
		return ilosc;
	}
	else
		return 0;
}

void usunElementListyZPrzodu(List* Lista) {
	if (Lista->ListaPierwszy) {
		if (Lista->ListaPierwszy == Lista->ListaOstatni) {
			Lista->ListaOstatni = NULL;
			Lista->ListaPierwszy = NULL;
		}
		else {
			Lista->ListaOstatni->next = Lista->ListaPierwszy->next;
			Lista->ListaPierwszy->prev = Lista->ListaOstatni;
			Lista->ListaPierwszy = Lista->ListaOstatni->next;
		}
	}
}
void dodajDoKolejki(List* Lista, int wartosc) {
	//czy Lista pusta
	if (Lista->ListaPierwszy == 0) {
		generujListe(Lista, wartosc);
		Lista->KolejkaPierwszy = Lista->ListaPierwszy;
		Lista->KolejkaOstatni = Lista->ListaPierwszy;
	}
	//lista niepusta
	else {
		//dlugosc listy jest wieksza niz kolejki
		if (zwrocDlugoscKolejki(Lista) < zwrocDlugoscListy(Lista)) {
			Lista->KolejkaOstatni->prev->value = wartosc;
			Lista->KolejkaOstatni = Lista->KolejkaOstatni->prev;
		}
		//kolejka i lista maja ta sama dlugosc
		else {
			elem* Nowy = new elem;
			Nowy->value = wartosc;
			if (zwrocDlugoscKolejki(Lista) == 1) {
				Nowy->next = Lista->ListaPierwszy;
				Nowy->prev = Lista->ListaPierwszy;
				Lista->ListaPierwszy->next = Nowy;
				Lista->ListaPierwszy->prev = Nowy;
				Lista->ListaPierwszy = Lista->ListaPierwszy->next;
			}
			else {
				Nowy->prev = Lista->KolejkaOstatni->prev;
				Nowy->next = Lista->KolejkaOstatni;
				if (Lista->ListaPierwszy == Lista->KolejkaOstatni) {
					Lista->ListaPierwszy = Nowy;
				}
				Lista->KolejkaOstatni->prev->next = Nowy;
				Lista->KolejkaOstatni->prev = Nowy;
			}
			Lista->KolejkaOstatni = Nowy;
		}
	}

}
void zdejmijZKolejki(List* Lista) {
	if (Lista->KolejkaPierwszy != 0) {
		cout << Lista->KolejkaPierwszy->value << endl;
		if (Lista->KolejkaPierwszy != Lista->KolejkaOstatni) {
			Lista->KolejkaPierwszy = Lista->KolejkaPierwszy->prev;
		}
		else {
			Lista->KolejkaOstatni = NULL;
			Lista->KolejkaPierwszy = NULL;
		}
	}
	else
		cout << "NULL" << endl;
}



void usunElementListyZTylu(List* Lista) {
	if (Lista->ListaPierwszy) {
		if (Lista->ListaPierwszy == Lista->ListaOstatni) {
			Lista->ListaOstatni = NULL;
			Lista->ListaPierwszy = NULL;
		}
		else {
			Lista->ListaPierwszy->prev = Lista->ListaOstatni->prev;
			Lista->ListaOstatni->prev->next = Lista->ListaPierwszy;
			Lista->ListaOstatni = Lista->ListaOstatni->prev;
		}
	}
}
int main() {
	List Lista;
	Lista.ListaPierwszy = NULL;
	Lista.ListaOstatni = NULL;
	Lista.KolejkaPierwszy = NULL;
	Lista.KolejkaOstatni = NULL;
	char komenda[20];
	int znak;
	while (cin >> komenda) {

		if (!strcmp(komenda, "ADD_BEG")) {
			cin >> znak;
			dodajNaPoczatekListy(&Lista, znak);
		}
		else if (!strcmp(komenda, "ADD_END")) {
			cin >> znak;
			dodajNaKoniecListy(&Lista, znak);
		}

		else if (!strcmp(komenda, "DEL_BEG")) {
			usunElementListyZPrzodu(&Lista);
		}
		else if (!strcmp(komenda, "DEL_END")) {
			usunElementListyZTylu(&Lista);
		}
		else if (!strcmp(komenda, "PRINT_FORWARD")) {
			drukujNormalnie(&Lista);
		}
		else if (!strcmp(komenda, "PRINT_BACKWARD")) {
			drukujOdTylu(&Lista);
		}
		else if (!strcmp(komenda, "SIZE")) {
			cout << zwrocDlugoscListy(&Lista) << endl;
		}
		else if (!strcmp(komenda, "PUSH")) {
			cin >> znak;
			dodajDoKolejki(&Lista, znak);
		}
		else if (!strcmp(komenda, "POP")) {
			zdejmijZKolejki(&Lista);
		}
		else if (!strcmp(komenda, "PRINT_QUEUE")) {
			drukujKolejke(&Lista);
		}
		else if (!strcmp(komenda, "COUNT")) {

			cout << zwrocDlugoscKolejki(&Lista) << endl;
		}
		else if (!strcmp(komenda, "GARBAGE_SOFT")) {

		}
		else if (!strcmp(komenda, "GARBAGE_HARD")) {

		}
	}
}