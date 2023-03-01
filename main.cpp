
#include "function.h"

int main(){
    printf("Witaj w Aplikacji Konsolowej 'DIETA MAKER' \n");
    printf(" Jest to aplikacja wspomagajaca dbanie o zdrowa diete. \n");
    enter_fun();
    head_menu();
    return 0;
}

void head_menu(){
    puts("\n\t\tMENU");
    puts("0.WYJSCIE");
    puts("1.DANE UZYTKOWNIKA");
    puts("2.KALKULATORY DIETETYCZNE");
    puts("3.BAZA DANYCH PRODUKTOW SPOZYWCZYCH");
    puts("WPROWADZ INDEKS WYBORU: ");
    long index=gets_index();
    switch (index) {
        case 0:
            printf("Dziekujemy za skorzystanie z aplikacji 'DIETA MAKER'");
            enter_fun();
            exit(0);
        case 1:
            user_data_menu();
            break;
        case 2:
            diet_calculators();
            break;
        case 3:
            food_menu();
            break;
        default:
            printf("\n!!!Wprowadzono niepoprawna wartosc indeksu wyboru!!!\nSproboj ponownie");
            enter_fun();
            head_menu();
    }
}












