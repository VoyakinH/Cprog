#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ui.h"
#include "defines.h"
#include "func.h"

uiWindow * wndMain;

uiBox * bxMain;

uiButton * btnGo;

uiEntry * dateInput;
uiEntry * technicianInput;
uiEntry * dataInput;

uiLabel * dateOutput;
uiLabel * technicianOutput;
uiLabel * dataOutput;

static exp *experiments;
static int number_of_exp = 0;
char error_mes[100];

static void onMsgBoxErrorClicked()
{
    uiMsgBoxError(wndMain,"Error", error_mes);
}

int is_date_valid(const char *got_date, int date[])
{
    int count = 0;
    for (int i = 0; i < GOT_DATE_LEN - 1; i++)
    {
        if (got_date[i] == '.')
            count++;
        else if (!isdigit(got_date[i]))
            count = 3;
    }

    if (count != 2)
        return INVALID_DATE;
    if (got_date[2] != '.' || got_date[5] != '.')
        return INVALID_DATE;

    date[0] = atoi(got_date);
    date[1] = atoi(got_date + 3);
    date[2] = atoi(got_date + 6);

    if (((date[1] == 4 || date[1] == 6 || date[1] == 9 || date[1] == 11) && date[0] > 30)
        || date[0] > 31 || date[1] > 12 || date[0] <= 0 || date[1] <= 0 || date[2] < 1000)
    {
        return INVALID_DATE;
    }
    
    if (date[1] == 2 && (((date[2] % 4 != 0 || (date[2] % 100 == 0 && date[2] % 400 != 0)) && date[0] > 28) || date[0] > 29))
    {
        return INVALID_DATE;
    }

    return OK;
}

void free_arr(void)
{
    for (int i = 0; i < number_of_exp; i++)
    {
        free(experiments[i].technician);
    }
    return;
}

static int copy_to_struct(const int date[], const char *surname, const float data)
{
    experiments[number_of_exp].technician = calloc(strlen(surname) + 1, sizeof(char));
    if (!experiments[number_of_exp].technician)
    {
        return ALLOCATION_ERR;
    }

    for (int j = 0; j < DATE_LEN; j++)
    {
        experiments[number_of_exp].date[j] = date[j];
    }

    strncpy(experiments[number_of_exp].technician, surname, strlen(surname));
    
    experiments[number_of_exp].data = data;

    return OK;
}

void read_set_of_exp(uiButton * btn, void * data1)
{
    char got_date[100];
    char surname[100];
    char got_data[100];
    int date[DATE_LEN];
    float data;

    strncpy(got_date, uiEntryText(dateInput), 100);
    strncpy(surname, uiEntryText(technicianInput), 100);
    strncpy(got_data, uiEntryText(dataInput), 100);
    
    if (is_date_valid(got_date, date) != 0)
    {
        strcpy(error_mes, "Дата введена неверно.");
        onMsgBoxErrorClicked();
        return;
    }
    
    for (int j = 0; j < strlen(surname) - 1; j++)
    {
        if (!isalpha(surname[j]))
        {
            strcpy(error_mes, "Фамилия введена неверно.");
            onMsgBoxErrorClicked();
            return;
        }
    }

    data = atoi(got_data);
    if (data == 0 && got_data[0] != '0')
    {
        strcpy(error_mes, "Данные эксперимента введены неверно.");
        onMsgBoxErrorClicked();
        return;
    }

    copy_to_struct(date, surname, data);

    number_of_exp++;
    exp *new_experiments = realloc(experiments, (number_of_exp + 1) * sizeof(exp));
    if (new_experiments)
    {
        experiments = new_experiments;
        new_experiments = NULL;
    }

    //uiLabelSetText(lblOutput, s);
    return;
}

static int onClosing(uiWindow * w, void * data) {
    uiControlDestroy(uiControl(wndMain));
    uiQuit();
    return EXIT_SUCCESS;
}

static int onShouldQuit(void * data) {
    uiControlDestroy(uiControl(wndMain));
    return EXIT_FAILURE;
}

int main(void) {
    //requires
    uiInitOptions options;
    const char * err;

    memset( & options, 0, sizeof(uiInitOptions));
    err = uiInit( & options);
    if (err != NULL)
    {
        fprintf(stderr, "error initializing libui: %s", err);
        uiFreeInitError(err);
        return EXIT_FAILURE;
    }
    //endrequired

    wndMain = uiNewWindow("LAB_14", 300, 100, 0);
    uiWindowSetMargined(wndMain, 1);
    uiWindowOnClosing(wndMain, onClosing, NULL);
    uiOnShouldQuit(onShouldQuit, wndMain);

    bxMain = uiNewVerticalBox();
    uiBoxSetPadded(bxMain, 1);

    uiWindowSetChild(wndMain, uiControl(bxMain));

    btnGo = uiNewButton("Добавить структуру!");

    uiButtonOnClicked(btnGo, read_set_of_exp, NULL);

    uiBoxAppend(bxMain, uiControl(btnGo), 0);
    
    dateInput = uiNewEntry();
    technicianInput = uiNewEntry();
    dataInput = uiNewEntry();
    
    dateOutput = uiNewLabel("Ввод даты");
    technicianOutput = uiNewLabel("Ввод Фамилии");
    dataOutput = uiNewLabel("Ввод измерения");
    uiBoxAppend(bxMain, uiControl(dateOutput), 0);
    uiBoxAppend(bxMain, uiControl(dateInput), 0);
    uiBoxAppend(bxMain, uiControl(technicianOutput), 0);
    uiBoxAppend(bxMain, uiControl(technicianInput), 0);
    uiBoxAppend(bxMain, uiControl(dataOutput), 0);
    uiBoxAppend(bxMain, uiControl(dataInput), 0);

    experiments = malloc(sizeof(exp));
//    make_del(experiments, &number_of_exp);
//
//    if (number_of_exp == 0)
//    {
//        free_arr(&experiments, number_of_exp);
//        free(experiments);
//        return READ_EXP_ERR;
//    }
//
//    char key[KEY_LEN];
//
//    if (read_key(key, stdin) != OK || sort_arr(experiments, number_of_exp, key) != OK)
//    {
//        free_arr(&experiments, number_of_exp);
//        free(experiments);
//        return READ_KEY_ERR;
//    }
//
//    FILE *f = fopen("results.txt", "w");
//    if (!f)
//    {
//        free_arr(&experiments, number_of_exp);
//        free(experiments);
//        return FILE_OPEN_ERR;
//    }
//
//    write_to_file(f, experiments, number_of_exp);
//    free_arr(&experiments, number_of_exp);

    free_arr();
    free(experiments);
    
    uiControlShow(uiControl(wndMain));
    
    uiMain();
    return EXIT_SUCCESS;
}
