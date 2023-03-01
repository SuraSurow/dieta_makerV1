
#ifndef PROGRAM_DIETA_MAKER_FUNCTION_H
#define PROGRAM_DIETA_MAKER_FUNCTION_H
#define BUFOR_INT 4
#define BUFOR_CHAR 32
#define BUFOR_INDEX 4
#define BUFOR_FLOAT 8
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct USER {
    char name[BUFOR_CHAR],surname[BUFOR_CHAR],
            sex[BUFOR_INT],age[BUFOR_INT],height[BUFOR_INT],
            weight[BUFOR_INT],waist[BUFOR_INT],hips[BUFOR_INT],chest[BUFOR_INT],
            thigh[BUFOR_INT],arm[BUFOR_INT],belly[BUFOR_INT];
    long age_long ,height_long,weight_long,waist_long,hips_long,
            chest_long,thigh_long,arm_long,belly_long;
    char *active_user_file=(char*)malloc(sizeof(char)*2*BUFOR_CHAR);
}USER;

typedef struct product{
    long int *type ;
    char name[BUFOR_CHAR];
    int *kcal;
    int *fat;
    int *carbs;
    int *protein;
}PRODUCT;

//schemat zainicjowanych funckcji został stworzony w taki sposob aby pokazac w jakim obszarze programu
//zostaja uzyte dane funckjie np w mamy // all calc function to wszystkie funckjie są uzyte do obszaru
//progeramu ktory słuzy do obliczen kalkulatora dietetycznego


    /*schemat jest taki
                                           main
                                            |
                                        head menu
                                            |
                user data            diet_calculator               food_database
                    |                        |                           |

*/
//    WSZYSTKIE ZDEFINIOWANE FUNCKJE
void head_menu();
//--------all-calc-function-------------------------------
void diet_calculators();
float get_calc(int *choice);
void legends();
//----------all_user_database_function--------------------
void user_data_menu();
void edit_data_user();
void active_user_file(char*);
void preview_data_user();
void choice_user(char *active_user_file);
void data_user_int_func(char unit[],char*trash,char memory[],char type[],long min,long max,int bufInt,int bufChar,long brokerLong,char orifVal[]);
//-----------opti_function-------------------
void clear_buf();
void enter_fun();
void gets_clear_array(char*table_buf,char*table);
long gets_index();
float gets_float();
int count_poems(FILE* file);
int gets_rand_int(int lower, int upper);
void gets_two_half(char* original,char* first,char* second);


//-------------gets_part_of_body_fun-------------------
void gets_sex_fun(char*user_sex);
void gets_name_fun(char*user_name);
void gets_surname_fun(char*user_surname);
void gets_age_fun(char*user_age,long user_age_long);
void gets_height_fun(char*user_height,long user_height_long);
void gets_weight_fun(char*user_weight,long user_weight_long);
void gets_waist_fun(char*user_waist,long user_waist_long);
void gets_hips_fun(char*user_hips,long user_hips_long);
void gets_chest_fun(char*user_chest,long user_chest_long);
void gets_thigh_fun(char*user_thigh,long user_thigh_long);
void gets_arm_fun(char*user_arm,long user_arm_long);
void gets_belly_fun(char*user_belly,long user_belly_long);
//--------------food_data_base_func---------------------
void food_menu();
void create_type(PRODUCT*prod,int *count,long *num,char ** trash,FILE*food_data_name);
void show_food(const long int *type,int count,PRODUCT*prod,char**trash);
void show_detail( long int *type,int count,PRODUCT*prod,char**trash,int **wsk_detail_tab);
#endif //PROGRAM_DIETA_MAKER_FUNCTION_H

