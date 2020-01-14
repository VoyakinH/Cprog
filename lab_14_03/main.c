#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ui.h"
#include "defines.h"
#include "func.h"
#include "test.h"

uiWindow * wndMain;
uiMultilineEntry *e;

uiBox * bxMain;

uiButton * btnGo;
uiButton * btnDel;
uiButton * btnAverage;

uiEntry * dateInput;
uiEntry * technicianInput;
uiEntry * dataInput;

uiLabel * dateOutput;
uiLabel * technicianOutput;
uiLabel * dataOutput;
static uiBox *table;

static uiTable *t;
static uiTableParams p;
static int checkStates[15];


static uiTableModelHandler tabl;
static uiTableModel *tabl_m;

static exp *experiments;
static int number_of_exp = 0;
static int prev_numb = 0;
char error_mes[100];
char average_data[100];

static int modelNumColumns(uiTableModelHandler *tabl, uiTableModel *tabl_m)
{
    return 3;
}

static int modelNumRows(uiTableModelHandler *tabl, uiTableModel *tabl_m)
{
    return number_of_exp;
}

static uiTableValueType modelColumnType(uiTableModelHandler *tabl, uiTableModel *tabl_m, int column)
{
    return uiTableValueTypeString;
}

static uiTableValue *modelCellValue(uiTableModelHandler *tabl, uiTableModel *tabl_mm, int row, int col)
{
    char buf_1[256];
    char buf_2[256];
    
    switch (col) {
        case 0:
            if (experiments[row].date[0] < 10)
            {
                sprintf(buf_1, "0%d.", experiments[row].date[0]);
            }
            else
            {
                sprintf(buf_1, "%d.", experiments[row].date[0]);
            }
            if (experiments[row].date[1] < 10)
            {
                sprintf(buf_2, "0%d.%d", experiments[row].date[1], experiments[row].date[2]);
            }
            else
            {
                sprintf(buf_2, "%d.%d", experiments[row].date[1], experiments[row].date[2]);
            }
                strcat(buf_1, buf_2);
            break;
        case 1:
            sprintf(buf_1, "%s\n", experiments[row].technician);
            break;
        case 2:
            sprintf(buf_1, "%f\n", experiments[row].data);
            break;
        }
        return uiNewTableValueString(buf_1);
}

static void onMsgBoxErrorClicked()
{
    uiMsgBoxError(wndMain,"Error", error_mes);
}

static void onMsgBoxAverageClicked()
{
    uiMsgBox(wndMain,"Среднее значение показаний", average_data);
}

uiBox *makePage16(void)
{
    uiBox *page16;
    memset(checkStates, 0, 15 * sizeof (int));

    page16 = uiNewVerticalBox();

    tabl.NumColumns = modelNumColumns;
    tabl.ColumnType = modelColumnType;
    tabl.NumRows = modelNumRows;
    tabl.CellValue = modelCellValue;
    tabl_m = uiNewTableModel(&tabl);

    memset(&p, 0, sizeof (uiTableParams));
    p.Model = tabl_m;
    p.RowBackgroundColorModelColumn = 3;
    t = uiNewTable(&p);
    uiBoxAppend(page16, uiControl(t), 1);

    uiTableAppendTextColumn(t, "Дата", 0, uiTableModelColumnNeverEditable, NULL);
    uiTableAppendTextColumn(t, "Фамилия", 1, uiTableModelColumnNeverEditable, NULL);
    uiTableAppendTextColumn(t, "Измерение", 2, uiTableModelColumnNeverEditable, NULL);


    return page16;
}

static void delete_all_table()
{
    if (prev_numb != 0)
        for (int i = 0; i < prev_numb; i++)
            uiTableModelRowDeleted(tabl_m, 0);
}

static void insert_to_table()
{
    for (int i = 0; i < number_of_exp; i++)
        uiTableModelRowInserted(tabl_m, i);
}

void output_arr(void)
{
    delete_all_table();
    insert_to_table();
    return;
}

static int check_date(exp experiment)
{
    int mounth = experiment.date[1];
    int year = experiment.date[2];

    if (year < 1993)
        return 1;

    if (mounth < 2 && year == 1993)
        return 1;

    return 0;
}

static void delete_exp(int i)
{
    free(experiments[i].technician);

    for (int j = i; j < number_of_exp - 1; j++)
    {
        experiments[j] = experiments[j + 1];
    }
    return;
}

void make_del(uiButton * btn, void * data1)
{
    int i = 0;
    while (i < number_of_exp)
    {
        if (check_date(experiments[i]) == 1)
        {
            delete_exp(i);
            prev_numb = number_of_exp;
            number_of_exp--;
            output_arr();
        }
        else
            i++;
    }
    return;
}

void count_average(uiButton * btn, void * data1)
{
    float s = 0;
    for (int i = 0; i < number_of_exp; i++)
    {
        s += experiments[i].data;
    }
    s /= number_of_exp;
    sprintf(average_data, "Результат: %f", s);
    onMsgBoxAverageClicked();
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

    prev_numb = number_of_exp;
    number_of_exp++;
    exp *new_experiments = realloc(experiments, (number_of_exp + 1) * sizeof(exp));
    if (new_experiments)
    {
        experiments = new_experiments;
        new_experiments = NULL;
    }
    output_arr();
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

    table = makePage16();
    wndMain = uiNewWindow("LAB_14", 500, 500, 0);
    uiWindowSetMargined(wndMain, 1);
    uiWindowOnClosing(wndMain, onClosing, NULL);
    uiOnShouldQuit(onShouldQuit, wndMain);

    bxMain = uiNewVerticalBox();
    uiBoxSetPadded(bxMain, 1);

    uiWindowSetChild(wndMain, uiControl(bxMain));
    uiBoxAppend(bxMain, uiControl(table), 1);
    
    //поля ввода
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
    
    //кнопка
    btnGo = uiNewButton("Добавить структуру!");
    uiButtonOnClicked(btnGo, read_set_of_exp, NULL);
    uiBoxAppend(bxMain, uiControl(btnGo), 0);
    
    btnDel = uiNewButton("Удалить записи проведённые не позже 1 февраля 1993 года.");
    uiButtonOnClicked(btnDel, make_del, NULL);
    uiBoxAppend(bxMain, uiControl(btnDel), 0);
    
    btnAverage = uiNewButton("Вычислить среднее значение измерений.");
    uiButtonOnClicked(btnAverage, count_average, NULL);
    uiBoxAppend(bxMain, uiControl(btnAverage), 0);

    experiments = malloc(sizeof(exp));

    free_arr();
    free(experiments);
    
    uiControlShow(uiControl(wndMain));
    
    uiMain();
    return EXIT_SUCCESS;
}
