//
//  history.h
//  
//
//  Created by home on 28/08/19.
//

#ifndef history_h
#define history_h

#define HISTORY_COUNT 100
int history(char *hist[], int current)
{
    int i = current;
    int hist_num = 1;
    
    do {
        if (hist[i]) {
            printf("%4d  %s\n", hist_num, hist[i]);
            hist_num++;
        }
        
        i = (i + 1) % HISTORY_COUNT;
        
    } while (i != current);
    
    return 0;
}

void clear_historye(char *hist[])
{
    int i;
    
    for (i = 0; i < HISTORY_COUNT; i++) {
        free(hist[i]);
        hist[i] = NULL;
    }
    
    return ;
}

#endif /* history_h */
