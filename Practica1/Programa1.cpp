#include<stdio.h>
#include<stdlib.h>
#include <fstream>
#include "./AF/af"
void newElements(char* father, char* newElement);

bool  getElement(FILE* file, char* element);

void strCopy(char *dest,  char *src) ;

void strConcat(char *dest,  char *src);


void initializeString(char *str, int size) {
    int i;
    for (i = 0; i < size - 1; i++) {
        str[i] = '\0'; 
    }
    str[size - 1] = '\0'; 
}



int strLength(char *str) {
    size_t length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}
int main(){
    char newNumbers[2000];
    initializeString(newNumbers,2000);
    char currElement[1000];
    initializeString(currElement,1000);
    
    //We define K aspower of the set of numbers
    int k; 
    //scanf("%d",&k);
    k=11;
    //We definetwo pointers of the file.

    
    
    
   
    //while(strlen(currElement)<k){
    int curr = 0;
    int previous = -1;
    for (int i = 0; i<k-1;i++){
        FILE* read;
        FILE* write;
        char* numberCurr = (char*)calloc(5,sizeof(char));
        char* numberPrevious = (char*)calloc(5,sizeof(char));
        char* numberMinus2 = (char*)calloc(5,sizeof(char));
        sprintf(numberCurr,"%d",curr);
        sprintf(numberPrevious,"%d",previous);
        sprintf(numberMinus2,"%d",(curr-2));
        char extension[5] = ".txt";
        strConcat(numberCurr,extension);
        strConcat(numberPrevious,extension);
        strConcat(numberMinus2,extension);
        //puts(numberCurr);
        //puts(numberPrevious);
        clearFileContents(numberCurr);
        if(i!=1){
            clearFileContents(numberMinus2);
        }
        write = fopen(numberCurr,"a+");
        read = fopen(numberPrevious,"a+");


        fputc('{', write);
        char flag = true;
        while(flag){
            flag = getElement(read, currElement);    
            newElements(currElement, newNumbers);
            fputs(newNumbers, write);       
        }
        curr ++;
        previous++;
        fputc('}', write);
        fclose(read);
        fclose(write);
    }
    
    
    
    
    

    return 0; 

}

bool getElement(FILE* file, char* element){
    int elementCount = 1;
    char elementCurr;
    elementCurr = fgetc(file);
    if(elementCurr=='{'){
        elementCurr = fgetc(file);
    }
    if(elementCurr=='}'){
        return false;
    }
    char possibleElement[1000];
    int i = 0;
    while ( elementCurr != ','){
        //printf("%c",element);
        possibleElement[i]=elementCurr;
        elementCurr= fgetc(file);
        i++;
        elementCount++;

    }
    possibleElement[i]='\0';
    strCopy(element,possibleElement);
    return true;
    
}

void newElements(char* father, char* newNodes){
    if(father!=NULL){
       
        
        
        strCopy(newNodes,father);
        strConcat(newNodes,"0,");
        strConcat(newNodes,father);
        strConcat(newNodes,"1,");
        
        
    }else{
        
        strCopy(newNodes,"0,1,");
        
    }

}




void strCopy(char *dest, char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void strConcat(char *dest, char *src) {
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}




//char* decoNumbers(FILE* Archivo, )