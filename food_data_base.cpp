
#include "function.h"


void food_menu() {
    printf("\tMENU PRODOKTOW SPOZYWYCZYCH\n\n");
    puts("0.Wyjscie");
    puts("1.Wyswietl Liste Produktow");
    puts("2.Wyswietl Dane Prodktow");
    puts("3.(coming soon!!!)Stworz Losowy Posilek(coming soon!!!)");
    printf("\nWpisz indeks wyboru:");

    FILE *food_data_name;
    char file[] = "food_data_name.txt";
    food_data_name = fopen(file, "r");
    int count = count_poems(food_data_name);//licznik linijek w pliku
    rewind(food_data_name);
    char **trash = (char **) malloc(sizeof(char) * BUFOR_CHAR);

    //stworzenie tablicy structow produktów spozywczych
    long int num[] = {1, 2, 3, 4, 5, 6, 7, 8};//typy prodoktow
    PRODUCT prod[count];
    //zaincjowanie tablicy oraz losowych wartosci od 0 do 500!!!
    int num_of_detail = 4;// uzywane w case 2:EDYCJA LISTY PLIKOW
    int detail_food_tab[count][num_of_detail];// uzywane w case 2:EDYCJA LISTY PLIKOW
    srand(time(NULL));
    int k, l;
    for (k = 0; k < count; k++) {
        for (l = 0; l < num_of_detail; l++) {
            detail_food_tab[k][l] = rand() % 500;
        }
    }


    create_type(prod, &count, num, trash, food_data_name);//tworzy typy produktów za pomoca
    //ktorych nastepnuje nizej sortowanie listy na poszczegolne rodzaje
    fclose(food_data_name);
    free(trash);
    trash = (char **) malloc(sizeof(char) * BUFOR_CHAR);
    int index = gets_index();
    printf("Liczba prodoktow:%d\n", count);
    switch (index) {
        case 0:
            head_menu();//WYJSCIE Z MENU PRODKOTOW
            break;
        case 1://PODGLAD PRODOKTOW
            printf("\nPODGLAD PRODUKTOW");
            printf("\nWybierz rodzaj!:\n0.Wyjscie\n1.Warzywa\n2.Owoce\n3.Prod. Bialkowe\n4.Weglowodany");
            printf("\n5.Zdrowe Tluszcze\n6.Prod. Odzwierzece\n7.Przyprawy\n8.Napoje\n");
            index = gets_index();
            switch (index) {
                case 0:
                    enter_fun();
                    head_menu();
                    break;
                case 1: {
                    printf("\nWARZYWA\n");
                    show_food(&num[0], count, prod, trash);
                    enter_fun();
                    food_menu();
                    break;
                }
                case 2: {
                    printf("\nOWOCE\n");
                    show_food(&num[1], count, prod, trash);
                    enter_fun();
                    food_menu();
                    break;
                }
                case 3: {
                    printf("\nPRODUKTY BIALKOWE\n");
                    show_food(&num[2], count, prod, trash);
                    enter_fun();
                    food_menu();
                    break;
                }
                case 4: {
                    printf("\nWEGLOWODANY\n");
                    show_food(&num[3], count, prod, trash);
                    enter_fun();
                    food_menu();
                    break;
                }
                case 5: {
                    printf("\nZDROWE TLUSZCZE\n");
                    show_food(&num[4], count, prod, trash);
                    enter_fun();
                    food_menu();
                    break;
                }
                case 6: {
                    printf("\nPRODUKTY ODZWIERZECE\n");
                    show_food(&num[5], count, prod, trash);
                    enter_fun();
                    food_menu();
                    break;
                }
                case 7: {
                    printf("\nPRZYPRAWY\n");
                    show_food(&num[6], count, prod, trash);
                    enter_fun();
                    food_menu();
                    break;
                }
                case 8: {
                    printf("\nNAPOJE\n");
                    show_food(&num[7], count, prod, trash);
                    enter_fun();
                    food_menu();
                    break;
                }
                default:
                    printf("\n!!!Wprowadzono niepoprawna wartosc indeksu wyboru!!!\nSproboj ponownie");
                    enter_fun();
                    head_menu();
                    break;
            }
        case 2: {//wyswietlanie danych
            int **wsk_detail_tab = (int **) malloc(count * sizeof(int **));
            for (int j = 0; j < count; j++) {
                wsk_detail_tab[j] = (int *) malloc(num_of_detail * sizeof(int *));
            }
            for (int i = 0; i < count; i++) {
                for (int j = 0; j < num_of_detail; j++) {
                    wsk_detail_tab[i][j] = detail_food_tab[i][j];
                }
            }

            printf("\n");
            printf("!!!WYSWIETLANIE PRODOKTOW!!!\n");
            printf("\nWybierz rodzaj!:\n1.Warzywa\n2.Owoce\n3.Prod. Bialkowe\n4.Weglowodany");
            printf("\n5.Zdrowe Tluszcze\n6.Prod. Odzwierzece\n7.Przyprawy\n8.Napoje\n");
            index = gets_index();
            switch (index) {
                case 0:
                    head_menu();
                    break;
                case 1: {
                    printf("\nWARZYWA\n");
                    //show_food(&num[0], count, prod, trash);
                    show_detail(&num[0], count, prod, trash, wsk_detail_tab);
                    enter_fun();
                    food_menu();
                    break;
                }
                case 2: {
                    printf("\nOWOCE\n");
                    show_detail(&num[1], count, prod, trash, wsk_detail_tab);
                    enter_fun();
                    food_menu();
                    break;
                }
                case 3: {
                    printf("\nPRODUKTY BIALKOWE\n");
                    show_detail(&num[2], count, prod, trash, wsk_detail_tab);
                    enter_fun();
                    food_menu();
                    break;
                }
                case 4: {
                    printf("\nWEGLOWODANY\n");
                    show_detail(&num[3], count, prod, trash, wsk_detail_tab);
                    enter_fun();
                    food_menu();
                    break;
                }
                case 5: {
                    printf("\nZDROWE TLUSZCZE\n");
                    show_detail(&num[4], count, prod, trash, wsk_detail_tab);
                    enter_fun();
                    food_menu();
                    break;
                }
                case 6: {
                    printf("\nPRODUKTY ODZWIERZECE\n");
                    show_detail(&num[5], count, prod, trash, wsk_detail_tab);
                    enter_fun();
                    food_menu();
                    break;
                }
                case 7: {
                    printf("\nPRZYPRAWY\n");
                    show_detail(&num[6], count, prod, trash, wsk_detail_tab);
                    enter_fun();
                    food_menu();
                    break;
                }
                case 8: {
                    printf("\nNAPOJE\n");
                    show_detail(&num[7], count, prod, trash, wsk_detail_tab);
                    enter_fun();
                    food_menu();
                    break;
                }
                default:
                    printf("\n!!!Wprowadzono niepoprawna wartosc indeksu wyboru!!!\nSproboj ponownie");
                    enter_fun();
                    head_menu();
                    break;
            }

            free(trash);
            free(detail_food_tab);
            food_menu();

        }
    }
}