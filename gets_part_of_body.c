//

#include "function.h"

void gets_sex_fun(char*user_sex) {
    printf("Wpisz Swoja Plec:");
    char *wsk_sex = (char *) malloc(BUFOR_CHAR);
    fgets(wsk_sex, BUFOR_CHAR, stdin);
    wsk_sex = (char *) realloc(wsk_sex, strlen(wsk_sex) + 1);
    char sexchar[] = {'k', 'K', 'm', 'M'};
    if ((sexchar[0] == wsk_sex[0]) || (sexchar[1] == wsk_sex[0])) {
        strcpy(user_sex, "K");
        printf("\n!!!Wpisano plec jako Kobieta!!!\n");
    } else if ((sexchar[2] == wsk_sex[0]) || (sexchar[3] == wsk_sex[0])) {
        strcpy(user_sex, "M");
        printf("\n!!!Wpisano plec jako Mezczyzna!!!\n");
    } else {
        printf("\n!!!Wpisano niepoprawny znak plci !!! \n!!! /M-mezczyzna/K-kobieta !!! \n!!! Sproboj ponownie !!!");
        user_data_menu();
    }
    free(wsk_sex);
}

void gets_name_fun(char*user_name){
    printf("\nWpisz swoje imie\n!!!Maksymalna ilosc znakow to %d!!!\n:", BUFOR_CHAR);
    char *wsk_name = (char *) malloc(BUFOR_CHAR);
    char *table_buf=(char*) malloc (sizeof(char)*BUFOR_CHAR);
    fgets(table_buf, BUFOR_CHAR, stdin);
    gets_clear_array(table_buf,wsk_name);
    wsk_name = (char *) realloc(wsk_name, strlen(table_buf)+1);
    strcpy(user_name, wsk_name);
    printf("Twoje imie to:-> %s ", user_name);
    free(table_buf);
    free(wsk_name);
}

void gets_surname_fun(char*user_surname){
    printf("\nWpisz swoje nazwisko\n!!!Maksymalna ilosc znakow to %d!!!\n:", BUFOR_CHAR);
    char *wsk_surname = (char *) malloc(BUFOR_CHAR);
    char *table_buf=(char*) malloc (sizeof(char)*BUFOR_CHAR);
    fgets(table_buf, BUFOR_CHAR, stdin);
    gets_clear_array(table_buf,wsk_surname);
    wsk_surname = (char *) realloc(wsk_surname, strlen(table_buf)+1);
    strcpy(user_surname, wsk_surname);
    printf("Twoje nazwisko to:-> %s ", user_surname);
    free(table_buf);
    free(wsk_surname);
    }

void gets_age_fun(char*user_age,long user_age_long){
    char*string_trash=(char*)malloc(sizeof(char)*BUFOR_CHAR);
    char typeVal[] = "Wiek", unit[] = "Lat";
    const long min = 1, max = 150;
    char temp_mem[BUFOR_CHAR];
    data_user_int_func(unit, string_trash,  temp_mem, typeVal, min, max, BUFOR_INT, BUFOR_CHAR, user_age_long,
                       user_age);
    free(string_trash);

}


void gets_height_fun(char*user_height,long user_height_long){
    char*string_trash=(char*)malloc(sizeof(char)*BUFOR_CHAR);
    char typeVal[] = "Wzrost", unit[] = "Cm";
    const long min = 100, max = 250;
    char *temp_mem = (char *) malloc(BUFOR_INT);
    data_user_int_func(unit, string_trash, temp_mem, typeVal, min, max, BUFOR_INT, BUFOR_CHAR, user_height_long,
    user_height);
    free(string_trash);
    free(temp_mem);
}

void gets_weight_fun(char*user_weight,long user_weight_long){
    char*string_trash=(char*)malloc(sizeof(char)*BUFOR_CHAR);
    char typeVal[] = "Waga", unit[] = "Kg";
    const long min = 30, max = 250;
    char *temp_mem = (char *) malloc(BUFOR_INT);
    data_user_int_func(unit, string_trash, temp_mem, typeVal, min, max, BUFOR_INT, BUFOR_CHAR, user_weight_long,
    user_weight);
    free(string_trash);
    free(temp_mem);
    }

void gets_waist_fun(char*user_waist,long user_waist_long){
    char*string_trash=(char*)malloc(sizeof(char)*BUFOR_CHAR);
    char typeVal[] = "Talia", unit[] = "Cm";
    const long min = 30, max = 250;
    char *temp_mem = (char *) malloc(BUFOR_INT);
    data_user_int_func(unit, string_trash, temp_mem, typeVal, min, max, BUFOR_INT, BUFOR_CHAR, user_waist_long,
    user_waist);
    free(string_trash);
    free(temp_mem);}

void gets_hips_fun(char*user_hips,long user_hips_long){
    char*string_trash=(char*)malloc(sizeof(char)*BUFOR_CHAR);
    char typeVal[] = "Biodra", unit[] = "Cm";
    const long min = 30, max = 250;
    char *temp_mem = (char *) malloc(BUFOR_INT);
    data_user_int_func(unit, string_trash, temp_mem, typeVal, min, max, BUFOR_INT, BUFOR_CHAR, user_hips_long,
    user_hips);
    free(string_trash);
    free(temp_mem);}

void gets_chest_fun(char*user_chest,long user_chest_long){
    char*string_trash=(char*)malloc(sizeof(char)*BUFOR_CHAR);
    char typeVal[] = "Klatka", unit[] = "Cm";
    const long min = 30, max = 250;
    char *temp_mem = (char *) malloc(BUFOR_INT);
    data_user_int_func(unit, string_trash, temp_mem, typeVal, min, max, BUFOR_INT, BUFOR_CHAR, user_chest_long,
    user_chest);
    free(string_trash);
    free(temp_mem);}

void gets_thigh_fun(char*user_thigh,long user_thigh_long){
    char*string_trash=(char*)malloc(sizeof(char)*BUFOR_CHAR);
    char typeVal[] = "Udo", unit[] = "Cm";
    const long min = 15, max = 150;
    char *temp_mem = (char *) malloc(BUFOR_INT);
    data_user_int_func(unit, string_trash, temp_mem, typeVal, min, max, BUFOR_INT, BUFOR_CHAR, user_thigh_long,
    user_thigh);
    free(string_trash);
    free(temp_mem);}

void gets_arm_fun(char*user_arm,long user_arm_long){
    char*string_trash=(char*)malloc(sizeof(char)*BUFOR_CHAR);
    char typeVal[] = "Ramie", unit[] = "Cm";
    const long min = 5, max = 100;
    char *temp_mem = (char *) malloc(BUFOR_INT);
    data_user_int_func(unit, string_trash, temp_mem, typeVal, min, max, BUFOR_INT, BUFOR_CHAR, user_arm_long,
    user_arm);
    free(string_trash);
    free(temp_mem);}

void gets_belly_fun(char*user_belly,long user_belly_long){
    char*string_trash=(char*)malloc(sizeof(char)*BUFOR_CHAR);
    char typeVal[] = "Brzuch", unit[] = "Cm";
    const long min = 30, max = 250;
    char *temp_mem = (char *) malloc(BUFOR_INT);
    data_user_int_func(unit, string_trash, temp_mem, typeVal, min, max, BUFOR_INT, BUFOR_CHAR, user_belly_long,
    user_belly);
    free(string_trash);
    free(temp_mem);}