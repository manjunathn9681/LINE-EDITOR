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
void displayLines()
{
    int i;

    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (i = 0; i < lineCount; i++)
    {
        printf("%d. %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

void searchLines(char word[])
{
    int i;
    int found = 0;

    for (i = 0; i < lineCount; i++)
    {
        if (strstr(lines[i], word) != NULL)
        {
            printf("Found \"%s\" at line %d\n", word, i + 1);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\"%s\" not found.\n", word);
    }
}

void countWords()
{
    int i, j, words = 0;

    for (i = 0; i < lineCount; i++)
    {
        for (j = 0; lines[i][j] != '\0'; j++)
        {
            if (lines[i][j] != ' ' &&
                (j == 0 || lines[i][j - 1] == ' '))
            {
                words++;
            }
        }
    }

    printf("Lines: %d\n", lineCount);
    printf("Words: %d\n", words);
}
void saveFile()
{
    FILE *file;
    int i;

    file = fopen("document.txt", "w");

    if (file == NULL)
    {
        printf("Unable to save file.\n");
        return;
    }

    for (i = 0; i < lineCount; i++)
    {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("Document saved as document.txt\n");
}

void printHelp()
{
    printf("\n========== COMMANDS ==========\n");
    printf("insert <line>  - Insert a line\n");
    printf("delete <line>  - Delete a line\n");
    printf("display        - Display document\n");
    printf("search <word>  - Search for a word\n");
    printf("count          - Line and word count\n");
    printf("save           - Save document\n");
    printf("help           - Show commands\n");
    printf("exit           - Exit editor\n");
    printf("===============================\n\n");
}
int main()
{
    char input[300];
    char text[MAX_LEN];
    char word[MAX_LEN];
    int lineNumber;

    printLogo();
    printHelp();

    while (1)
    {
        printf("> ");

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        stripNewline(input);

        /* INSERT */
        if (sscanf(input, "insert %d", &lineNumber) == 1)
        {
            printf("Text: ");

            fgets(text, sizeof(text), stdin);
            stripNewline(text);

            insertLine(lineNumber, text);
        }

        /* DELETE */
        else if (sscanf(input, "delete %d", &lineNumber) == 1)
        {
            deleteLine(lineNumber);
        }

        /* DISPLAY */
        else if (strcmp(input, "display") == 0)
        {
            displayLines();
        }

        /* SEARCH */
        else if (sscanf(input, "search %s", word) == 1)
        {
            searchLines(word);
        }

        /* COUNT */
        else if (strcmp(input, "count") == 0)
        {
            countWords();
        }

        /* SAVE */
        else if (strcmp(input, "save") == 0)
        {
            saveFile();
        }

        /* HELP */
        else if (strcmp(input, "help") == 0)
        {
            printHelp();
        }

        /* EXIT */
        else if (strcmp(input, "exit") == 0)
        {
            printf("Goodbye!\n");
            break;
        }

        /* INVALID */
        else
        {
            printf("Invalid command. Type 'help'.\n");
        }
    }

    return 0;
}