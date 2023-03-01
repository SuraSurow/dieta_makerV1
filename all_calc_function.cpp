#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "function.h"

void diet_calculators() {
    puts("\nKALKULATORY DIETETYCZNE");
    puts("0.WYJSCIE");
    puts("1.BMI - Wskaznik Masy Ciala");
    puts("2.CPM - Calkowita Przemiana Materii");
    puts("3.WHR - Stosunek Talia-Biodra");
    puts("4 Nalezna Masa Ciala (wzor Lorentza)");
    puts("5 Procentowa zawartosc tkanki tluszczowej w organizmie - metoda YMCA");
    puts("6.PPM - Podstawowa Przemiana Materii wzor Mifflina");
    puts("7.PPM - Podstawowa Przemiana Materii wzor Harrisa-Benedicta");
    puts("8.PPM - Podstawowa Przemiana Materii wzor Cunninghama");
    puts("9.PPM - Podstawowa Przemiana Materii wzor Katch-McArdle");
    puts("10 Beztluszczowa Masa Ciala LBM");
    puts("11.Legenda (krotki opis kalkulatorow)");
    puts("WPROWADZ INDEKS WYBORU: ");
    int index=gets_index();
    int *wsk_index=&index;
    switch (index) {
        case 0:
            //clear_buf();
            head_menu();
        case 1:
            puts("1.BMI - Wskaznik Masy Ciala");
            get_calc(wsk_index);
            enter_fun();
            diet_calculators();
            break;
        case 2:
            puts("2.CPM - Calkowita Przemiana Materii");
            get_calc(wsk_index);
            enter_fun();
            diet_calculators();
            break;
        case 3:
            puts("3.WHR - Stosunek Talia-Biodra");
            get_calc(wsk_index);
            enter_fun();
            diet_calculators();
            break;
        case 4:
            puts("4 Nalezna Masa Ciala (wzor Lorentza)");
            get_calc(wsk_index);
            enter_fun();
            diet_calculators();
            break;
        case 5:
            puts("5 Procentowa zawartosc tkanki tluszczowej w organizmie - metoda YMCA");
            get_calc(wsk_index);
            enter_fun();
            diet_calculators();
            break;
        case 6:
            puts("6.PPM - Podstawowa Przemiana Materii wzor Mifflina");
            get_calc(wsk_index);
            enter_fun();
            diet_calculators();
            break;
        case 7:
            puts("7.PPM - Podstawowa Przemiana Materii wzor Harrisa-Benedicta");
            get_calc(wsk_index);
            enter_fun();
            diet_calculators();
            break;
        case 8:
            puts("8.PPM - Podstawowa Przemiana Materii wzor Cunninghama");
            get_calc(wsk_index);
            enter_fun();
            diet_calculators();
            break;
        case 9:
            puts("9.PPM - Podstawowa Przemiana Materii wzor Katch-McArdle");
            get_calc(wsk_index);
            enter_fun();
            diet_calculators();
            break;
        case 10:
            puts("10 Beztluszczowa Masa Ciala LBM");
            get_calc(wsk_index);
            enter_fun();
            diet_calculators();
            break;
        case 11:
            legends();
            enter_fun();
            //clear_buf();
            diet_calculators();
    }
}

float get_calc(int *choice) {
    USER user;
    char *name_file = (char *) malloc(sizeof(char) * BUFOR_CHAR);
    active_user_file(name_file);
    FILE *user_data_file;
    user_data_file = fopen(name_file, "r");
    if (user_data_file == NULL)printf("Blad otworzenia pliku!!!\nSprawdz czy plik aktualnego uzytkownika istnieje!!!");
    fscanf(user_data_file, "%s", user.sex);
    fscanf(user_data_file, "%s", user.name);
    fscanf(user_data_file, "%s", user.surname);
    fscanf(user_data_file, "%s", user.age);
    fscanf(user_data_file, "%s", user.height);
    fscanf(user_data_file, "%s", user.weight);
    fscanf(user_data_file, "%s", user.waist);
    fscanf(user_data_file, "%s", user.hips);
    fscanf(user_data_file, "%s", user.chest);
    fscanf(user_data_file, "%s", user.thigh);
    fscanf(user_data_file, "%s", user.arm);
    fscanf(user_data_file, "%s", user.belly);
    fclose(user_data_file);
    char *string_trash = (char *) malloc(sizeof(char) * BUFOR_CHAR);
    int choice_int = *choice;
    switch (choice_int) {
        case 1: {
            double weight_calc, height_calc, bmi;
            const double factor = 10000.0;
            weight_calc = strtof(user.weight, &string_trash);
            height_calc = strtof(user.height, &string_trash);
            height_calc = pow(height_calc, 2.0);
            bmi = weight_calc / height_calc;
            bmi = bmi * factor;
            printf("\tWYNIK\n####################\n\t%.2f\n####################", bmi);
            break;
        }
        case 2: {
            double weight_calc, height_calc, age_calc, ppm, cpm;
            if ((strcmp(user.sex, "k") == 0) || (strcmp(user.sex, "K") == 0)) {
                const float x = 665.09, y = 9.56, z = 1.85, a = 4.67;//stałe wynikajace ze wzoru na ppm dla kobiety
                height_calc = strtof(user.height, &string_trash);
                weight_calc = strtof(user.weight, &string_trash);
                age_calc = strtof(user.age, &string_trash);
                height_calc = height_calc * z;
                age_calc = age_calc * a;
                weight_calc = weight_calc * y;
                ppm = ((x) + (height_calc) + (weight_calc) - (age_calc));
                printf("\tPPM Wynosi =%.1f kCal\n", ppm);
                float coefficient;
                puts("Przykuty do lozka(stan chorobowy) = 1.2(K)");
                puts("Bardzo Lekka Aktywnosc = 1.3(K)");
                puts("Lekka Aktywnosc = 1.5(K)");
                puts("Srednia Aktywnosc = 1.6(K)");
                puts("Duza Aktywnosc = 1.9(K)");
                puts("Bardzo Duza Aktywnosc = 2.2(K)");
                printf("\nWpisz wspolczynnik Aktywnosci\n(M)-Mezczyzna  |  (K)-Kobieta\n");
                printf("\n:");
                coefficient = gets_float();
                cpm = ppm * coefficient;
            } else if ((strcmp(user.sex, "m") == 0) || (strcmp(user.sex, "M") == 0)) {
                const float x = 66.47, y = 13.75, z = 5, a = 6.75;//stałe wynikajace ze wzoru na ppm dla mezczycny
                height_calc = strtof(user.height, &string_trash);
                weight_calc = strtof(user.weight, &string_trash);
                age_calc = strtof(user.age, &string_trash);
                height_calc = height_calc * z;
                age_calc = age_calc * a;
                weight_calc = weight_calc * y;
                ppm = ((x) + (height_calc) + (weight_calc) - (age_calc));
                printf("\tPPM Wynosi =%.0f kCal\n", ppm);
                float coefficient;
                puts("Przykuty do lozka(stan chorobowy) = 1.2(M) ");
                puts("Bardzo Lekka Aktywnosc = 1.3(M)");
                puts("Lekka Aktywnosc = 1.6(M)");
                puts("Srednia Aktywnosc = 1.7(M)");
                puts("Duza Aktywnosc = 2.1(M)");
                puts("Bardzo Duza Aktywnosc = 2.4(M)");
                printf("\nWpisz wspolczynnik Aktywnosci\n(M)-Mezczyzna  |  (K)-Kobieta\n");
                printf("\n:");
                coefficient = gets_float();
                cpm = ppm * coefficient;
            }
            printf("\tWYNIK\n####################\n\t%.2f kCal\n####################", cpm);
        }

        case 3: {
            float hips_calc, waist_calc, whr;
            hips_calc = strtof(user.hips, &string_trash);
            waist_calc = strtof(user.waist, &string_trash);
            whr = waist_calc / hips_calc;
            printf("\tWYNIK\n####################\n\t%.2f\n####################", whr);
            //enter_fun();
            break;
        }

        case 4: {
            float height_calc;
            if ((strcmp(user.sex, "k") == 0) || (strcmp(user.sex, "K") == 0)) {
                height_calc = strtof(user.height, &string_trash);
                float nmc = height_calc;
                height_calc -= 150;
                height_calc /= 2.0;
                nmc -= 100;
                nmc -= height_calc;
                printf("\tWYNIK\n####################\n\t%.2f Kg\n####################", nmc);
                while (getchar() != '\n');
            } else if ((strcmp(user.sex, "m") == 0) || (strcmp(user.sex, "M") == 0)) {
                height_calc = strtof(user.height, &string_trash);
                float nmc = height_calc;
                height_calc -= 150;
                height_calc /= 4.0;
                nmc -= 100;
                nmc -= height_calc;
                printf("\tWYNIK\n####################\n\t%.2f Kg\n####################", nmc);
                //enter_fun();
            }
            break;
        }
        case 5: {
            double belly_cal, weight_calc, weight_calc2;
            const double hundred = 100;
            belly_cal = strtof(user.belly, &string_trash);
            weight_calc = strtof(user.weight, &string_trash);
            weight_calc2 = weight_calc;
            belly_cal *= 1.634;
            weight_calc *= 0.1804;
            belly_cal -= weight_calc;
            if ((strcmp(user.sex, "k") == 0) || (strcmp(user.sex, "K") == 0))belly_cal -= 76.76;//dla kobiety
            else if ((strcmp(user.sex, "m") == 0) || (strcmp(user.sex, "M") == 0))belly_cal -= 98.42;//dla mezczyzny
            weight_calc2 *= 2.2;
            belly_cal /= weight_calc2;
            float ymca = belly_cal * hundred;
            printf("\tWYNIK\n####################\n\t%.2f %c \n####################", ymca, 37);
            //enter_fun();
            break;
        }

        case 6: {
            float age_calc, weight_calc, height_calc;
            age_calc = strtof(user.age, &string_trash);
            weight_calc = strtof(user.weight, &string_trash);
            height_calc = strtof(user.height, &string_trash);
            weight_calc *= 10;
            height_calc *= 6.25;
            age_calc *= 5;
            weight_calc += height_calc;
            weight_calc -= age_calc;
            if ((strcmp(user.sex, "k") == 0) || (strcmp(user.sex, "K") == 0))weight_calc -= 161;
            else if ((strcmp(user.sex, "m") == 0) || (strcmp(user.sex, "M") == 0))weight_calc += 5;
            float wzor_milffina = weight_calc;
            printf("\tWYNIK\n####################\n\t%.2f kCal\n####################", wzor_milffina);
            //enter_fun();
            break;
        }
        case 7: {
            double weight_calc, height_calc, age_calc, ppm;
            if ((strcmp(user.sex, "k") == 0) || (strcmp(user.sex, "K") == 0)) {
                const float x = 665.09, y = 9.56, z = 1.85, a = 4.67;//stałe wynikajace ze wzoru na ppm dla kobiety
                height_calc = strtof(user.height, &string_trash);
                weight_calc = strtof(user.weight, &string_trash);
                age_calc = strtof(user.age, &string_trash);
                height_calc = height_calc * z;
                age_calc = age_calc * a;
                weight_calc = weight_calc * y;
                ppm = ((x) + (height_calc) + (weight_calc) - (age_calc));
                printf("\tWYNIK\n####################\n\t%.2f kCal\n####################", ppm);
            } else if ((strcmp(user.sex, "m") == 0) || (strcmp(user.sex, "M") == 0)) {
                const float x = 66.47, y = 13.75, z = 5, a = 6.75;//stałe wynikajace ze wzoru na ppm dla mezczycny
                height_calc = strtof(user.height, &string_trash);
                weight_calc = strtof(user.weight, &string_trash);
                age_calc = strtof(user.age, &string_trash);
                height_calc = height_calc * z;
                age_calc = age_calc * a;
                weight_calc = weight_calc * y;
                ppm = ((x) + (height_calc) + (weight_calc) - (age_calc));
                printf("\tWYNIK\n####################\n\t%.2f kCal\n####################", ppm);
            }
            //enter_fun();
            break;
        }
        case 8: {
            float weight_calc, height_calc, lmb, result_lmb, ppm;
            weight_calc = strtof(user.weight, &string_trash);
            height_calc = strtof(user.height, &string_trash);
            lmb = weight_calc / height_calc;
            lmb = pow(lmb, 2.0);
            if ((strcmp(user.sex, "k") == 0) || (strcmp(user.sex, "K") == 0)) {
                lmb *= 148;
                weight_calc *= 1.07;
            } else if ((strcmp(user.sex, "m") == 0) || (strcmp(user.sex, "M") == 0)) {
                lmb *= 128;
                weight_calc *= 1.1;
            }
            weight_calc -= lmb;
            result_lmb = weight_calc;
            result_lmb *= 22;
            ppm = 500 + result_lmb;
            printf("\tWYNIK\n####################\n\t%.2f kCal\n####################", ppm);
            //enter_fun();
            break;
        }
        case 9: {
            float weight_calc, height_calc, lmb, result_lmb, ppm;
            weight_calc = strtof(user.weight, &string_trash);
            height_calc = strtof(user.height, &string_trash);
            lmb = weight_calc / height_calc;
            lmb = pow(lmb, 2.0);
            if ((strcmp(user.sex, "k") == 0) || (strcmp(user.sex, "K") == 0)) {
                lmb *= 148;
                weight_calc *= 1.07;
            } else if ((strcmp(user.sex, "m") == 0) || (strcmp(user.sex, "M") == 0)) {
                lmb *= 128;
                weight_calc *= 1.1;
            }
            weight_calc -= lmb;
            result_lmb = weight_calc;
            result_lmb *= 21.6;
            ppm = 370 + result_lmb;
            printf("\tWYNIK\n####################\n\t%.2f kCal\n####################", ppm);
            //enter_fun();
            break;
            case 10: {
                float weight_cal, height_cal, lmb, result;
                weight_cal = strtof(user.weight, &string_trash);
                height_cal = strtof(user.height, &string_trash);
                lmb = weight_cal / height_cal;
                lmb = pow(lmb, 2.0);
                if ((strcmp(user.sex, "k") == 0) || (strcmp(user.sex, "K") == 0)) {
                    lmb *= 148;
                    weight_cal *= 1.07;
                    weight_cal -= lmb;
                    result = weight_cal;
                    printf("\tWYNIK\n####################\n\t%.2f Kg\n####################", result);
                } else if ((strcmp(user.sex, "m") == 0) || (strcmp(user.sex, "M") == 0)) {
                    lmb *= 128;
                    weight_cal *= 1.07;
                    weight_cal -= lmb;
                    result = weight_cal;
                    printf("\tWYNIK\n####################\n\t%.2f Kg\n####################", result);
                }
                break;
            }

            default: {
                printf("\n!!!Wprowadzono niepoprawna wartosc indeksu wyboru!!!\nSproboj ponownie");
                diet_calculators();
            }
        }

    }
    return 0;
}

void legends() {
    printf("\n\nLEGENDA\n\n");
    puts("1.BMI to wskaznik, ktory ocenia czy waga jest proporcjonalna do wzrostu ");
    printf("\n");
    puts("2.Calkowita przemiana materii (CPM) to inaczej dzienne zapotrzebowanie energetyczne.");
    printf("\n");
    puts("3.WHR - Stosunek Talia-Biodra jest kalkulatorem pozwalajacym na dokladne okreslenie typu sylwetki");
    puts(" oraz ew. typu nadwagi (brzuszna badz udowa).");
    printf("\n");
    puts("4.Nalezna masa ciala (NMC) to inaczej idealna lub pozadana masa ciala, taka, ktora chroni ");
    puts("zarowno przed niedozywieniem, jak i nadwaga i otyloscia.");
    printf("\n");
    puts("5.Kalkulator YMCA jest kalkulatorem obliczajacym poziom tkanki tluszczowej w organizmie czlowieka.");
    printf("\n");
    puts("6-9 PPM Podstawowa przemiana materii (PPM) to najnizszy poziom przemian energetycznych,ktory warunkuje ");
    puts("dostarczenie energii niezbednej do zachowania podstawowych funkcji zyciowych w warunkach optymalnych.");
    puts("Dla niezaawansowanych uzytkownikow polecane jest korzystanie z wzoru Harrisa-Benedicta (indeks 7) ");
    printf("\n");
    puts("10.Beztluszczowa masa ciala LBM (ang. lean body mass) oznacza mase ciala (tkanek aktywnych i koscca) z");
    puts("wylaczeniem tkanki tluszczowej.Okresla sie w ten sposob poziom odzywienia organizmu.");}