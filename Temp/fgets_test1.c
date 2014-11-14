#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t,i,j;
    scanf("%d\n", &t);

    char line[100000];

    for(i=0; i < t; i++){
        //get string from user
        fgets(line, sizeof(line), stdin);
        //loop line and greedily solve this
        int deletions = 0;
        if(strlen > 0){
            char currentChar = line[0];
            for(j=1; j < strlen(line); j++){
                if(currentChar == line[j]){
                    deletions++;
                }else{
                    currentChar = line[j];
                }
            }
        }
        printf("%d\n", deletions);
        //empty string
        memset(line,0,strlen(line));
    }

    return 0;
}
