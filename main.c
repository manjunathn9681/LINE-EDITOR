#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 200

char lines[MAX_LINES][MAX_LEN];
int lineCount = 0;

/* M3 Logo */
#define ROWS 7
#define COLS 5
#define SCALE 2

const char *M[ROWS] = {
    "10001",
    "11011",
    "10101",
    "10001",
    "10001",
    "10001",
    "10001"
};

const char *THREE[ROWS] = {
    "11110",
    "00001",
    "00001",
    "01110",
    "00001",
    "00001",
    "11110"
};

void printLogo()
{
    int i, j, k;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (M[i][j] == '1')
            {
                for (k = 0; k < SCALE; k++)
                    printf("11");
            }
            else
            {
                for (k = 0; k < SCALE; k++)
                    printf("  ");
            }
        }

        printf("   ");

        for (j = 0; j < COLS; j++)
        {
            if (THREE[i][j] == '1')
            {
                for (k = 0; k < SCALE; k++)
                    printf("11");
            }
            else
            {
                for (k = 0; k < SCALE; k++)
                    printf("  ");
            }
        }

        printf("\n");
    }

    printf("              M3 LINE EDITOR\n");
    printf("       SIMPLE IDEAS . BETTER CODING\n\n");
}

void stripNewline(char *str)
{
    while (*str != '\0')
    {
        if (*str == '\n')
        {
            *str = '\0';
            break;
        }
        str++;
    }
}

void insertLine(int position, char text[])
{
    int i;

    if (lineCount >= MAX_LINES)
    {
        printf("Document is full.\n");
        return;
    }

    if (position < 1 || position > lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    for (i = lineCount; i >= position; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    strcpy(lines[position - 1], text);
    lineCount++;

    printf("Line inserted successfully.\n");
}

void deleteLine(int position)
{
    int i;

    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    if (position < 1 || position > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    for (i = position - 1; i < lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}
