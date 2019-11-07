#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include "initShell.h"
#include "sm.h"
#include "pwd.h"
#include "history.h"


#define MAXLIST 100
#define MAX_CMD_LEN  128
#define HISTORY_COUNT 100
void execArgs(char** parsed)
{
    // Forking a child
    pid_t pid = fork();
    
    if (pid == -1) {
        printf("\nFailed forking child..");
        return;
    } else if (pid == 0) {
        if (execvp(parsed[0], parsed) < 0) {
            printf("\nCould not execute command..");
        }
        exit(0);
    } else {
        // waiting for child to terminate

        wait(NULL);
        return;
    }
}



void parseSpace(char* str, char** parsed)
{
    int i;
    
    for (i = 0; i < MAXLIST; i++) {
        parsed[i] = strsep(&str, " ");
        
        if (parsed[i] == NULL)
        break;
        if (strlen(parsed[i]) == 0)
        i--;
    }
}



int main(int argc,char **argv){
    char* parsedArgsPiped[MAXLIST];
    char cmd[MAX_CMD_LEN];
    char *hist[HISTORY_COUNT];
    int i, current = 0;

    for (i = 0; i < HISTORY_COUNT; i++)
    hist[i] = NULL;
    init_shell();
    while(1){
        printf("user@shell # ");
        fgets(cmd, MAX_CMD_LEN, stdin);
        
        if (cmd[strlen(cmd) - 1] == '\n')
        cmd[strlen(cmd) - 1] = '\0';
        
        free(hist[current]);
        hist[current] = strdup(cmd);
        
        parseSpace(cmd ,parsedArgsPiped);
        current = (current + 1) % HISTORY_COUNT;

        if(strcmp(parsedArgsPiped[0], "pwd")==0){
            printDir();
            printf("\n");
        }
        
        else if(strcmp(parsedArgsPiped[0] ,"ls") == 0){
            if(parsedArgsPiped[1] == NULL ){
            ls(argc,argv, 0);
            }
            else if(parsedArgsPiped[1] != NULL && strcmp(parsedArgsPiped[1], "-a") != 0){
                ls(argc,argv, 0);
            }
            else{
                ls(argc,argv, 1);
            }
            printDir();
            printf("\n");
        }
        
        else if(strcmp(parsedArgsPiped[0], "cd") == 0){
            int y = chdir(parsedArgsPiped[1]);
            if(y != 0){
                printf("no such directory\n");
            }
            printDir();
            printf("\n");
        }
        
        else if (strcmp(parsedArgsPiped[0], "history") == 0){
            if(parsedArgsPiped[1] !=NULL && strcmp (parsedArgsPiped[1], "-c") == 0){
                clear_historye(hist);
                
            }
            else{
                history(hist, current);
            }
            printDir();
            printf("\n");
        }
        
        else if (strcmp(parsedArgsPiped[0], "quit") == 0){
            break;
        }
        
        else if(strcmp(parsedArgsPiped[0], "mkdir") == 0 || strcmp(parsedArgsPiped[0], "cat") == 0){
            execArgs(parsedArgsPiped);
            printDir();
            printf("\n");
        }
        
        else if(strcmp(parsedArgsPiped[0], "echo") == 0){
            
            if(strcmp(parsedArgsPiped[1], "-n") ==0){
                int m = 2;
                while(parsedArgsPiped[m] != NULL){
                printf("%s ", parsedArgsPiped[m]);
                    m++;
                }
                printDir();
                printf("\n");
            }
            
            else{
                int m = 1;
                while(parsedArgsPiped[m] != NULL){
                    printf("%s ", parsedArgsPiped[m]);
                    m++;
                }
                printf("\n");
                printDir();
                printf("\n");
            }
        }
        
        else if(strcmp(parsedArgsPiped[0], "clear") == 0){
            clear();
        }
        
        else if(strcmp(parsedArgsPiped[0], "rm") == 0 || strcmp(parsedArgsPiped[0], "date") == 0 ){
            execArgs(parsedArgsPiped);
            printDir();
            printf("\n");
        }
        else{
            printf("this command is not implemented\n");
            printDir();
            printf("\n");
        }
    }
}

