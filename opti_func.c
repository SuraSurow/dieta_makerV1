//
// Created by surow on 26.12.2022.
//

#include "function.h"
void clear_buf()
{
    char enter = 0;
    while (enter != '\r' && enter != '\n') enter = getchar();

}
void enter_fun(){
    printf("\nWcisnij ENTER by kontynuowac");
    char enter = 0;
    while (enter != '\r' && enter != '\n') enter = getchar();
    printf("\n\n");
}

void gets_clear_array(char*table_buf,char*table){
    const char*allTableBuf;
    allTableBuf=table_buf;
    printf("%s",allTableBuf);
    strcpy(table,table_buf);

}

long gets_index() {
    char index[BUFOR_CHAR];
    long index_int;
    char string_trash[BUFOR_CHAR];
    char *wsk_string_trash=string_trash;
    fgets(index, BUFOR_INDEX, stdin);
    index_int = strtol(index, &wsk_string_trash, 0);
    return index_int;
}
float gets_float(){
    char temp[BUFOR_CHAR];
    float float_variable;
    char string_trash[BUFOR_CHAR];
    char *wsk_string_trash=string_trash;
    fgets(temp, sizeof(float)*BUFOR_INT, stdin);
    float_variable= strtof(temp, &wsk_string_trash);
    return float_variable;
}

int count_poems(FILE* file){
    int count = 0;
    char ch;
    while((ch= fgetc(file)) != EOF)
    {
        if(ch == '\n'){
            count++;}
    }
    return count+1;}

int gets_rand_tin(int lower, int upper){
    int num = (rand() %(upper - lower + 1)) + lower;
    return num;
}

void create_type(PRODUCT*prod,int *count,long *num,char ** trash,FILE*food_data_name){
    for(int i=0;i<*count;i++){
        fgets(prod[i].name, 32, food_data_name);
        long int prod_num=strtol(&prod[i].name[0],trash,0);
        //1==owoce 2==warzywa 3==bialko 4==weglowodany
        // 5==zdrowetTluszcze 6==prod_odzwierzece 7==przyprawy 8==napoje
        for (int j = 0; j < 8; j++){
            if (prod_num == num[j]) {   prod[i].type=&num[j]; }
        }
    }
}


void show_detail( long int *type,int count,PRODUCT*prod,char**trash,int **wsk_detail_tab){
    printf("K=Kilokalorie\tF=Tluszcz\tW=Weglowodany\tB=Bialko\n");
    for(int i=0;i<count;i++){
        long int prod_num=strtol(&prod[i].name[0],trash,0);
        for(int j=1;j<31;j++){
            if(prod_num==*type){
                if(prod[i].name[j]==NULL){break;}
                printf("%c",prod[i].name[j]);}
        }
        if (prod_num == *type) {
            (*prod).kcal = &wsk_detail_tab[i][0];
            (*prod).fat = &wsk_detail_tab[i][1];
            (*prod).carbs = &wsk_detail_tab[i][2];
            (*prod).protein = &wsk_detail_tab[i][3];
            printf("K:%d\tF:%d\tW:%d\tB:%d\t\n------\n", *(*prod).kcal, *(*prod).fat, *(*prod).carbs, *(*prod).protein);
        }

    }
}



void show_food(const long int *type,int count,PRODUCT*prod,char**trash){
    for(int i=0;i<count;i++){
        long int prod_num=strtol(&prod[i].name[0],trash,0);
        for(int j=1;j<31;j++){
            if(prod_num==*type){
                if(prod[i].name[j]==NULL){break;}
                printf("%c",prod[i].name[j]);}
        }
    }
}


int gets_rand_int(int lower, int upper){
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}


void gets_two_half(char* original,char* first,char* second) {
    char delimiter = ' ';
    for (int i = 0; i < strlen(original); i++) {
        if (original[i] == delimiter) {
            strncpy(first, original, i);
            first[i] = '\0';
            strcpy(second, original + i + 1);
            break;
        }
    }
}



