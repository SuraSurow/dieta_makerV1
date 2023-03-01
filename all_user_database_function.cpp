
#include "function.h"

void user_data_menu(){
    USER user;
    printf("\tDANE UZYTKOWNIKA\n");
    printf("\t\tMENU\n\n");
    puts("0.WYJSCIE DO MENU GLOWNEGO");
    puts("1.PODGLAD DANYCH UZYTKOWNIKA");
    puts("2.EDYCJA DANYCH UZYTKOWNIKA");
    puts("3.WYBOR UZYTKOWNIKA");
    printf("\nWPROWADZ INDEKS WYBORU:");
    char index[16];
    long int index_int;
    char * string_trash;
    fgets(index,16,stdin);
    index_int=strtol(index,&string_trash,16);
    switch (index_int) {
        case 0:head_menu();
            break;
        case 1:preview_data_user();
            break;
        case 2:edit_data_user();
            break;
        case 3:choice_user(user.active_user_file);
            user_data_menu();
            break;
        default:printf("\n!!!Wprowadzono niepoprawna wartosc indeksu wyboru!!!\nSproboj ponownie");
            enter_fun();
            user_data_menu();
    }
}

void edit_data_user() {
    printf("\tEDYCJA DANYCH UZYTKOWNIKA\n");
    FILE *user_data_file;
    USER user;
    char *name_file=(char*)malloc(sizeof(char)*BUFOR_CHAR);
    active_user_file(name_file);
    user_data_file=fopen(name_file,"r");
    if (user_data_file == NULL)printf("Blad otworzenia pliku!!!\nSprawdz czy plik aktualnego uzytkownika istnieje!!!");
    printf("0.Wyjscie\n");
    fscanf(user_data_file, "%s", user.sex);
    printf("1.Plec:\t\t%s /M-Mezczyzna/K-Kobieta/\n", user.sex);
    fscanf(user_data_file, "%s", user.name);
    printf("2.Imie:\t\t%s\n", user.name);
    fscanf(user_data_file, "%s", user.surname);
    printf("3.Nazwisko:\t%s\n", user.surname);
    fscanf(user_data_file, "%s", user.age);
    printf("4.Wiek\t\t%s Lat \n", user.age);
    fscanf(user_data_file, "%s", user.height);
    printf("5.Wzrost:\t%s Cm\n", user.height);
    fscanf(user_data_file, "%s", user.weight);
    printf("6.Waga:\t\t%s Kg\n", user.weight);
    printf("OBWODY CIALA [cm]\n");
    fscanf(user_data_file, "%s", user.waist);
    printf("7.Talia:\t\t%s \n", user.waist);
    fscanf(user_data_file, "%s", user.hips);
    printf("8.Biodra:\t\t%s\n", user.hips);
    fscanf(user_data_file, "%s", user.chest);
    printf("9.Klatka Piersiowa:\t%s\n", user.chest);
    fscanf(user_data_file, "%s", user.thigh);
    printf("10.Udo\t\t\t%s\n", user.thigh);
    fscanf(user_data_file, "%s", user.arm);
    printf("11.Ramie:\t\t%s\n", user.arm);
    fscanf(user_data_file, "%s", user.belly);
    printf("12.Brzuch:\t\t%s\n", user.belly);
    fclose(user_data_file);
    printf("13.WPISZ DANE OD NOWA\n");
    printf("\nWybierz Index Wyboru:");
    int index=gets_index();
    switch (index) {
        case 0:
            user_data_menu();
            break;
        case 1: {
            char*wsk_user_sex=user.sex;
            gets_sex_fun(wsk_user_sex);
            break;}
        case 2: {
            char*wsk_user_name=user.name;
            gets_name_fun(wsk_user_name);
            break;}
        case 3: {
            char*wsk_user_surname=user.surname;
            gets_surname_fun(wsk_user_surname);
            break;}
        case 4:{
            char*wsk_user_age=user.age;
            gets_age_fun(wsk_user_age,user.age_long);
            break;}
        case 5:{
            char*wsk_user_height=user.height;
            gets_height_fun(wsk_user_height,user.height_long);
            break;}
        case 6:{
            char*wsk_user_weight=user.weight;
            gets_weight_fun(wsk_user_weight,user.weight_long);
            break;}
        case 7:{
            char*wsk_user_waist=user.waist;
            gets_waist_fun(wsk_user_waist,user.waist_long);
            break;}
        case 8:{
            char*wsk_user_hips=user.hips;
            gets_hips_fun(wsk_user_hips,user.hips_long);
            break;}

        case 9:{
            char*wsk_user_chest=user.chest;
            gets_hips_fun(wsk_user_chest,user.chest_long);
            break;
        }

        case 10:{
            char*wsk_user_thigh=user.thigh;
            gets_chest_fun(wsk_user_thigh,user.thigh_long);
            break;}
        case 11:{
            char*wsk_user_arm=user.arm;
            gets_arm_fun(wsk_user_arm,user.arm_long);
            break;}
        case 12:{
            char*wsk_user_belly=user.belly;
            gets_belly_fun(wsk_user_belly,user.arm_long);
            break;}
        case 13:{
            gets_sex_fun(user.sex);
            gets_name_fun(user.name);
            gets_surname_fun(user.surname);
            gets_age_fun(user.age,user.age_long);
            gets_weight_fun(user.weight,user.weight_long);
            gets_waist_fun(user.waist,user.waist_long);
            gets_hips_fun(user.hips,user.hips_long);
            gets_chest_fun(user.chest,user.chest_long);
            gets_thigh_fun(user.thigh,user.thigh_long);
            gets_belly_fun(user.belly,user.belly_long);
            gets_height_fun(user.height,user.height_long);
        }
        default:
            printf("Wpisano niepoprawny index wyboru!!!\nSproboj Ponownie!!!\n");
    }
    user_data_file=fopen(name_file,"w");
    fprintf(user_data_file,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",user.sex,user.name,user.surname,user.age,user.height,user.weight,user.waist,user.hips,user.chest,user.thigh,user.arm,user.belly);
    fclose(user_data_file);
    enter_fun();
    edit_data_user();
}

void active_user_file(char*file_name){
    USER user;
    FILE *file_data;
    file_data=fopen("file_data.txt","r");
    if (file_data == NULL)printf("Blad otworzenia pliku!!!\nSprawdz czy plik 'file_data.txt' istnieje!!!");
    fscanf(file_data, "%s", user.active_user_file);
    user.active_user_file=(char*)realloc(user.active_user_file,strlen(user.active_user_file));
    strcpy(file_name,user.active_user_file);}

void preview_data_user(){
    printf("\tPODGLAD DANYCH UZYTKOWNIKA\n");
    char *name_file=(char*)malloc(sizeof(char)*BUFOR_CHAR);
    active_user_file(name_file);
    puts("--------------------");
    FILE * user_data_file;
    USER user;
    user_data_file=fopen(name_file,"r");
    printf("0.Wyjscie\n");
    fscanf(user_data_file,"%s",user.sex);
    printf("1.Plec:\t\t%s /M-Mezczyzna/K-Kobieta/\n",user.sex);
    fscanf(user_data_file,"%s",user.name);
    printf("2.Imie:\t\t%s\n",user.name);
    fscanf(user_data_file,"%s",user.surname);
    printf("3.Nazwisko:\t%s\n",user.surname);
    fscanf(user_data_file,"%s",user.age);
    printf("4.Wiek\t\t%s Lat \n",user.age);
    fscanf(user_data_file,"%s",user.height);
    printf("5.Wzrost:\t%s Cm\n",user.height);
    fscanf(user_data_file,"%s",user.weight);
    printf("6.Waga:\t\t%s Kg\n",user.weight);
    printf("OBWODY CIALA [cm]\n");
    fscanf(user_data_file,"%s",user.waist);
    printf("7.Talia:\t\t%s \n",user.waist);
    fscanf(user_data_file,"%s",user.hips);
    printf("8.Biodra:\t\t%s\n",user.hips);
    fscanf(user_data_file,"%s",user.chest);
    printf("9.Klatka Piersiowa:\t%s\n",user.chest);
    fscanf(user_data_file,"%s",user.thigh);
    printf("10.Udo\t\t\t%s\n",user.thigh);
    fscanf(user_data_file,"%s",user.arm);
    printf("11.Ramie:\t\t%s\n",user.arm);
    fscanf(user_data_file,"%s",user.belly);
    printf("12.Brzuch:\t\t%s\n",user.belly);
    fclose(user_data_file);
    enter_fun();
    user_data_menu();
    free(name_file);
}

void choice_user(char*active_user_file) {
    printf("\nWYBOR UZYTKOWNIKA\n");
    puts("Wybierz indeks uzytkownika");
    int i = 1;
    printf("\nLista Uzytkownikow\n");
    for (; i < 10; i++) {
        char *path = (char *) malloc(sizeof(char) * BUFOR_CHAR);
        sprintf(path, "user_data%d%d.txt", 0, i);
        FILE *all_file;
        char *sex = (char *) malloc(sizeof(char) * BUFOR_CHAR);
        char *name = (char *) malloc(sizeof(char) * BUFOR_CHAR);
        char *surname = (char *) malloc(sizeof(char) * BUFOR_CHAR);
        all_file = fopen(path, "r");
        fscanf(all_file, "%s %s %s", sex, name, surname);
        printf("%d.\tplec:%s\t%s %s \n", i, sex, name, surname);
        free(sex);
        free(name);
        free(surname);
        fclose(all_file);
    }

    printf(":");

    int index=gets_index();
    if ((index >= 10) || (index <= 0)) {
        printf("!!!Wybrano niepoprawny indeks uzytkownika!!!\n!!!Sproboj ponownie!!");
        enter_fun();
        user_data_menu();}
    i = index;
    FILE *choice_active_file;
    choice_active_file = fopen("file_data.txt", "w");
    if (choice_active_file == NULL)printf("Blad otworzenia pliku!!!\nSprawdz czy plik aktualnego uzytkownika istnieje!!!");
    sprintf(active_user_file, "user_data%d%d.txt", 0, i);
    fprintf(choice_active_file,"%s",active_user_file);
    fclose(choice_active_file);
    printf("\n!!!Wybrano uzytkownika Nr %d!!!\n\n",i);
}

void data_user_int_func(char unit[],char*trash,char memory[],char type[],long min,long max,int bufInt,int bufChar,long brokerLong,char orifVal[]) {
    printf("\nWpisz %s\n!!! Zakres od %ld do %ld %s !!!\n:",type,min,max,unit);
    fgets(memory, bufInt, stdin);
    brokerLong= strtol(memory, &trash, 0);
    if ((brokerLong<min) || (brokerLong>max)) {
        printf("!!!Wpisano nieprawidlowa wartosc !!!\n!!!Zakres od %ld do %ld %s!!!\n!!!Sproboj ponownie!!!\n",min,max,unit);
        enter_fun();
        edit_data_user();}
    strcpy(orifVal, memory);
    printf("\nWpisana Wartosc %s  to : %s Jednostka: %s",type,orifVal,unit);
    free(memory);
}