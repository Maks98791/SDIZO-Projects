#include <iostream>
#include <fstream>
#include <cmath>
#include <specstrings.h>
#include <afxres.h>


using namespace std;

int* DeleteItemFromTable(int* tab, int position, int tableSize);
int* AddItemToTable(int* tab, int item, int position, int tableSize);
int* BuildHeap(int* tab, int tableSize);
int* Heapify(int* tab, int tableSize, int i);
int* AddItemToHeap(int* tab, int item, int tableSize);
int* DeleteItemFromHeap(int* tab, int item, int tableSize);

struct Number {

    int value;
    Number* nextptr;

    Number()
    {
        nextptr = 0;
    }
};
struct List {

    Number* beginptr;

    void AddToList(int num);
    void DeleteFromList(int position);
    void DisplayList();
    void FindInList(int num);

    List()
    {
        beginptr = 0;
    }
};

int main() {

    char rpt;
    int number;
    int operacja;
    int tableSize;
    int *tab;
    List *lista = new List;

    //MENU
    do {
        cout << endl << endl << "WYBIERZ NUMER STRUKTURY I ZATWIERDŹ KLIKAJĄC ENTER" << endl << endl;
        cout << "1. Tablica" << endl;
        cout << "2. Lista" << endl;
        cout << "3. Kopiec binarny" << endl;
        cout << "Wpisz numer: ";
        cin >> number;

        switch (number) {
            // TABLICA
            case 1: {
                do {
                    cout << endl << endl << "WYBIERZ NUMER OPERACJI I ZATWIERDŹ KLIKAJĄC ENTER" << endl << endl;

                    cout << "1. Zbuduj z pliku" << endl;
                    cout << "2. Usuń element z tablicy" << endl;
                    cout << "3. Dodaj element do tablicy" << endl;
                    cout << "4. Znajdź element w tablicy" << endl;
                    cout << "5. Wyświetl tablice" << endl << endl;

                    cout << "Wpisz numer: ";
                    cin >> operacja;
                    cout << endl;

                    switch (operacja) {
                        // Budowanie tablicy z pliku
                        case 1: {

                            fstream file;
                            file.open("E://C++//SDIZO projekt//liczby.txt", ios::in);
                            file >> tableSize;

                            tab = new int[tableSize];

                            for (int i = 0; i < tableSize; i++)
                                file >> tab[i];

                            file.close();

                            cout << endl << "Zbudowana tablica:" << endl;

                            for (int i = 0; i < tableSize; i++)
                                cout << tab[i] << " ";

                            cout << endl;
                            break;
                        }
                            // Usuwanie elementu z wybranej pozycji z tablicy
                        case 2: {

                            int indeks;
                            cout << "Podaj indeks liczby, którą chcesz usunąć: ";
                            cin >> indeks;

                            tab = DeleteItemFromTable(tab, indeks, tableSize);

                            cout << endl << "Usunięto" << endl;

                            tableSize--;
                            cout << endl;
                            break;
                        }
                        case 3: {
                            int item;
                            int position;
                            cout << "Podaj element który chcesz dodać ";
                            cin >> item;
                            cout << "Podaj pozycje, na której ma się znajdować element: ";
                            cin >> position;

                            tab = AddItemToTable(tab, item, position, tableSize);

                            cout << endl << "Dodano" << endl;

                            tableSize++;
                            cout << endl;
                            break;
                        }
                        case 4: {
                            int item;
                            cout << "Podaj liczbe, którą chcesz wyszukać: ";
                            cin >> item;

                            for (int i = 0; i < tableSize; i++) {
                                if (tab[i] == item) {
                                    cout << endl << "Liczba znajduje się w tablicy" << endl;
                                    break;
                                }
                            }

                            cout << endl;
                            break;
                        }
                        case 5: {

                            for (int i = 0; i < tableSize; i++) {
                                cout << tab[i] << " ";
                            }

                            cout << endl;
                            break;
                        }
                    }
                    cout << endl << "Would you like to convert again? Type Y to try again OR N to exit. : ";
                    cin >> rpt;
                } while (rpt == 'Y');
                break;

                // LISTA
                case 2: {
                    do {
                        cout << "WYBIERZ NUMER OPERACJI I ZATWIERDŹ KLIKAJĄC ENTER" << endl << endl;

                        cout << "1. Zbuduj z pliku" << endl;
                        cout << "2. Usuń element z listy" << endl;
                        cout << "3. Dodaj element do listy" << endl;
                        cout << "4. Znajdź element w liscie" << endl;
                        cout << "5. Wyświetl liste" << endl << endl;

                        cout << "Wpisz numer: ";
                        cin >> operacja;
                        cout << endl;

                        switch (operacja) {
                            // Budowanie listy z pliku
                            case 1: {

                                fstream file;
                                file.open("E://C++//SDIZO projekt//liczby.txt", ios::in);
                                file >> tableSize;
                                int tempValue;

                                for (int i = 0; i < tableSize; i++) {
                                    file >> tempValue;
                                    lista->AddToList(tempValue);
                                }

                                file.close();

                                cout << endl << "Zbudowana lista:" << endl;

                                lista->DisplayList();

                                cout << endl;
                                break;
                            }
                                // Usuwanie wybranego elementu z listy
                            case 2: {

                                int indeks;
                                cout << "Podaj indeks liczby (licząc od 1, nie od 0), którą chcesz usunąć: ";
                                cin >> indeks;

                                lista->DeleteFromList(indeks);

                                cout << endl << "Usunięto" << endl;

                                break;
                            }
                            case 3: {
                                int item;
                                int position;
                                cout << "Podaj element który chcesz dodać ";
                                cin >> item;

                                lista->AddToList(item);

                                cout << endl << "Dodano" << endl;

                                break;
                            }
                            case 4: {
                                int item;
                                cout << "Podaj liczbe, którą chcesz wyszukać: ";
                                cin >> item;

                                lista->FindInList(item);

                                cout << endl;
                                break;
                            }

                            case 5: {

                                lista->DisplayList();

                                cout << endl;
                                break;
                            }
                        }
                        cout << endl << "Would you like to convert again? Type Y to try again OR N to exit. : ";
                        cin >> rpt;
                    } while (rpt == 'Y');
                    break;

                // KOPIEC
                case 3: {
                    do {
                        cout << "WYBIERZ NUMER OPERACJI I ZATWIERDŹ KLIKAJĄC ENTER" << endl << endl;

                        cout << "1. Zbuduj z pliku" << endl;
                        cout << "2. Usuń element z kopca" << endl;
                        cout << "3. Dodaj element do kopca" << endl;
                        cout << "4. Znajdź element w kopcu" << endl;
                        cout << "5. Wyświetl kopiec" << endl << endl;

                        cout << "Wpisz numer: ";
                        cin >> operacja;
                        cout << endl;

                        switch (operacja) {
                            // Budowanie kopca z pliku
                            case 1: {

                                fstream file;
                                file.open("E://C++//SDIZO projekt//liczby.txt", ios::in);
                                file >> tableSize;

                                tab = new int[tableSize];

                                for (int i = 0; i < tableSize; i++)
                                    file >> tab[i];

                                file.close();

                                tab = BuildHeap(tab, tableSize);

                                cout << endl << "Zbudowany kopiec:" << endl;

                                for (int i = 0; i < tableSize; i++)
                                    cout << tab[i] << " ";

                                cout << endl;
                                break;
                            }
                                // Usuwanie elementu z wybranej pozycji z kopca
                            case 2: {

                                int item;
                                cout << "Podaj liczbę, którą chcesz usunąć: ";
                                cin >> item;

                                tab = DeleteItemFromHeap(tab, item, tableSize);

                                BuildHeap(tab, tableSize);

                                cout << endl << "Usunięto" << endl;

                                tableSize--;
                                cout << endl;
                                break;
                            }
                            case 3: {
                                int item;
                                cout << "Podaj element który chcesz dodać ";
                                cin >> item;

                                tab = AddItemToHeap(tab, item, tableSize);
                                BuildHeap(tab, tableSize);

                                cout << endl << "Dodano" << endl;

                                tableSize++;
                                cout << endl;
                                break;
                            }
                            case 4: {
                                int item;
                                cout << "Podaj liczbe, którą chcesz wyszukać: ";
                                cin >> item;

                                for (int i = 0; i < tableSize; i++) {
                                    if (tab[i] == item) {
                                        cout << endl << "Liczba znajduje się w kopcu" << endl;
                                        break;
                                    }
                                }

                                cout << endl;
                                break;
                            }
                            case 5: {

                                int j = 0;
                                int counter = 0;

                                for (unsigned i = 0; i < tableSize; ++i) {
                                    cout << tab[i] << "  ";

                                    if (i == 0) {
                                        cout << endl << "----------------------" << endl;
                                        ++j;
                                    } else {
                                        if (counter == pow(2, j)) {
                                            cout << endl << "----------------------" << endl;
                                            ++j;
                                            counter = 0;
                                        }
                                    }
                                    ++counter;
                                }
                                cout << endl;
                                break;
                            }
                        }
                        cout << endl << "Would you like to convert again? Type Y to try again OR N to exit. : ";
                        cin >> rpt;
                    } while (rpt == 'Y');
                    break;
                }
            }
        }
    }
        cout << endl << "Would you like to come back to main MENU? Type Y to try again OR N to exit. : ";
        cin >> rpt;
    } while (rpt == 'Y');
}

int* DeleteItemFromTable(int* tab, int position, int tableSize)
{
    int newsize = tableSize - 1;
    int* temp = new int[newsize];

    if(position == 0)
    {
        for(int i=0; i < newsize; i++)
            temp[i] = tab[i+1];
    }
    else if(position == newsize)
    {
        for(int i=0; i < newsize; i++)
        {
            temp[i] = tab[i];
        }
    }
    else
    {
        for(int i=0; i < position; i++)
        {
            temp[i] = tab[i];
        }

        for(int i=position; i < newsize; i++)
        {
            temp[i] = tab[i+1];
        }
    }

    delete[] tab;
    return temp;
}
int* AddItemToTable(int* tab, int item, int position, int tableSize)
{
    int newsize = tableSize++;
    int* temp = new int[newsize];

    if(position == 0)
    {
        temp[0] = item;

        for(int i=1; i <= newsize; i++)
        {
            temp[i] = tab[i-1];
        }
    }
    else if(position == tableSize)
    {
        for(int i=0; i < tableSize; i++)
        {
            temp[i] = tab[i];
        }

        temp[tableSize] = item;
    }
    else
    {
        for(int i=0; i < position; i++)
        {
            temp[i] = tab[i];
        }

        temp[position] = item;

        for(int i=position+1; i <= newsize; i++)
        {
            temp[i] = tab[i-1];
        }
    }

    delete[] tab;
    return temp;
}
int* BuildHeap(int* tab, int tableSize)
{
    int i, heapsize;
    heapsize = tableSize;

    for(i=heapsize/2; i >= 0; i--)
        Heapify(tab, heapsize, i);

    return tab;
}
int* Heapify(int* tab, int tableSize, int i)
{
    int l, r, largest, temp;

    l = 2 * i;
    r = 2 * i + 1;

    if (l <= tableSize && tab[l] > tab[i])
        largest = l;
    else largest = i;

    if (r <= tableSize && tab[r] > tab[largest])
        largest = r;

    if (largest != i)
    {
        temp = tab[i];
        tab[i] = tab[largest];
        tab[largest] = temp;
        Heapify(tab, tableSize, largest);
    }

    return tab;
}
int* AddItemToHeap(int* tab, int item, int tableSize)
{
    int* temp = new int[tableSize+1];

    for(int i=0; i < tableSize; i++)
        temp[i] = tab[i];

    temp[tableSize] = item;

    delete[] tab;
    return temp;
}
int* DeleteItemFromHeap(int* tab, int item, int tableSize)
{
    int newsize = tableSize - 1;
    int* temp = new int[newsize];
    int position = 0;

    for(int k=0; k < newsize; k++)
    {
        if(tab[k] == item)
        {
            position = k;
            break;
        }
    }

    if(position == 0)
    {
        for(int i=0; i < newsize; i++) {
            temp[i] = tab[i + 1];
        }
    }
    else if(position == newsize)
    {
        for(int i=0; i < newsize; i++)
        {
            temp[i] = tab[i];
            cout << temp[i] << " ";
        }
    }
    else if(position > 0 && position < newsize)
    {
        for(int i=0; i < position; i++)
        {
            temp[i] = tab[i];
        }

        for(int i=position; i < newsize; i++)
        {
            temp[i] = tab[i+1];
        }
    }

    delete[] tab;
    return temp;
}
void List::DisplayList()
{
    // wskaznik na pierwszy element listy
    Number* temp = beginptr;

    // przewijamy wskazniki na nastepne elementy
    while(temp)
    {
        cout << temp->value << " ";
        temp = temp->nextptr;
    }
}
void List::AddToList(int num)
{
    Number *nowa = new Number;
    nowa->value = num;

    if (beginptr == 0) // sprawdzamy czy to pierwszy element listy
    {
        // jeżeli tak to nowy element jest teraz początkiem listy
        beginptr = nowa;
    }
    else
    {
        // w przeciwnym wypadku wędrujemy na koniec listy
        Number *temp = beginptr;

        while (temp->nextptr)
        {
            // znajdujemy wskaźnik na ostatni element
            temp = temp->nextptr;
        }

        temp->nextptr = nowa;  // ostatni element wskazuje na nasz nowy
        nowa->nextptr = 0;     // ostatni nie wskazuje na nic
    }
}
void List::FindInList(int num)
{
    Number* temp = beginptr;

    while(temp)
    {
        if(temp->value == num)
        {
            cout << "Wartość znajduje się w liście" << endl;
            break;
        }
        else
            temp = temp->nextptr;
    }
}
void List::DeleteFromList(int nr)
{
    // jezeli to pierwszy element listy
    if (nr == 1)
    {
        Number *temp = beginptr;
        beginptr = temp->nextptr; //poczatek listy, 1 el. wskazuje na 2 el. itd..
    }

    // jeżeli nie jest to pierwszy element
    if (nr >= 2)
    {
        int j = 1;

        // do usuniecia srodkowego elemetnu potrzebujemy wskaznika na osobe n-1
        // wskaznik *temp bedzie wskaznikiem na osobe poprzedzajaca osobe usuwana
        Number *temp = beginptr;

        while(temp)
        {
            // sprawdzamy czy wskaznik jest na osobie n-1 niz usuwana
            if ((j+1) == nr) break;

            // jezeli nie to przewijamy petle do przodu
            temp = temp->nextptr;
            j++;
        }

        // wskaznik *temp wskazuje teraz na osobe n-1
        // nadpisujemy wkaznik osoby n na osobe n+1
        // bezpowrotnie tracimy osobe n-ta

        // dodatkowo sprawdzamy czy aby nie jest to ostatni element
        // wtedy nalezy wyzerowac ostatni wskaznik
        if (temp->nextptr->nextptr == 0)
            temp->nextptr = 0;

            // jezeli nie byl to ostatni element
        else
            temp->nextptr = temp->nextptr->nextptr;
    }
}
