//
//  sm.h
//  
//
//  Created by home on 28/08/19.
//

#ifndef sm_h
#define sm_h

#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
void ls(int argc,char **argv, int x)
{
    struct dirent **namelist;
    int n;
    if(argc < 1)
    {
        exit(EXIT_FAILURE);
    }
    else if (argc == 1)
    {
        n=scandir(".",&namelist,NULL,alphasort);
    }
    else
    {
        n = scandir(argv[1], &namelist, NULL, alphasort);
    }
    if(n < 0)
    {
        perror("scandir");
        exit(EXIT_FAILURE);
    }
    else
    {
        while (n--)
        {
            char c =(char)46;;
            int pp = 0;
            
            if(namelist[n]->d_name[0] == c){
                pp=1;
            }
            //printf("%s 9990 \n",namelist[n]->d_name);
            if(x == 0 && pp == 0){
            printf("%s\n",namelist[n]->d_name);
            }
            else if(x == 1){
                printf("%s\n",namelist[n]->d_name);
            }
            free(namelist[n]);
        }
        free(namelist);
    }
    
}

#endif /* sm_h */
