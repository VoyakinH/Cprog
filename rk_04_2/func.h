
typedef struct gorod
{
	char *name;
	char *region;
	char *fed_okr;
	int nas;
	int year;
} gorod;

typedef struct list
{
	struct gorod *gorod_info;
	struct list *next;
} list;
	
void init_list(list **cities);
int read_cities(list **cities);
int read_cities(list **cities);
void copy_to_list(list **cities, char name[], char region[], char fed_okr[], int nas, int year);
void create_next(list **cities);
void output_list(list *cities);