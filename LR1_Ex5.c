#include <stdio.h>

// settings
#define TABLE_HEIGHT 3
#define STRING_SIZE 16

typedef struct Student
{
	char FIO[STRING_SIZE];
	int kurs;
	char grupa[STRING_SIZE];
	float sr_bal;
	char stip;
} Student_t;


void print_table(const int HEIGHT, Student_t *st)
{
	printf("----------------------------------------------------------\n");
	printf("| # |     FIO        | kurs |      grupa    |Sr.bal |Stip|\n");
	printf("----------------------------------------------------------\n");

	for	(int i = 0; i < HEIGHT; i++)
	{
		printf("| %i |%16s| %3i  |%15s| %4.3f |  %c |\n",i+1,(st+i)->FIO, (st+i)->kurs, (st+i)->grupa,
				(st+i)->sr_bal, (st+i)->stip);
		printf("----------------------------------------------------------\n");
	}
}

int main()
{
	Student_t list_students[TABLE_HEIGHT];

	for (int i = 0; i < TABLE_HEIGHT; i++)
	{
		print_table(i, list_students);

		printf("\nFill the table");
		printf("\n\tfor #%i student:\n",i+1);
		printf("\t\tType FIO:\n");
		scanf("%16s", &list_students[i].FIO);
		printf("\t\tType kurs:\n");
		scanf("%i", &list_students[i].kurs);
		printf("\t\tType grupa:\n");
		scanf("%16s", &list_students[i].grupa);
		printf("\t\tType Sr.bal:\n");
		scanf("%f", &list_students[i].sr_bal);

		if (list_students[i].sr_bal >= 4)
		{
			list_students[i].stip = '+';
		} else {
			list_students[i].stip = '-';
		}
	}

	print_table(TABLE_HEIGHT, list_students);

	return 0;
}


