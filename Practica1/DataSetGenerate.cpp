#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int onesCount(FILE *file);

void main()
{
    // We oppen the star lenguaje
    FILE *file;
    file = fopen("Output.txt", "r");
    // we create a output file
    FILE *newOutputFile;
    newOutputFile = fopen("plotDataSet.csv", "a+");
    fprintf(newOutputFile, "id,OnesNumber\n");

    // We update the preset position
    fseek(file, 3, SEEK_SET);
    // we define a id count
    int id = 0;
    int tmpOnesCount = 0;

    while (tmpOnesCount != -1)
    {
        tmpOnesCount = onesCount(file);
        fprintf(newOutputFile, "%d,%d\n", id, tmpOnesCount);
        id++;
    }
    fclose(file);
    fclose(newOutputFile);
}

int onesCount(FILE *file)
{
    // We definef onesCount as count of the ones in the string
    int onesCount = 0;
    // ElementCurr is a temporal variable
    char elementCurr;
    // we obtin a char
    elementCurr = 'a';

    while (elementCurr != ',' && elementCurr != EOF)
    {
        if (elementCurr == '1')
        {
            onesCount++;
        }
        // printf("%c",element);
        elementCurr = fgetc(file);
    }
    if (elementCurr != EOF)
    {
        return onesCount;
    }
    else
    {
        return -1;
    }
}