//
//  pwd.h
//  
//
//  Created by home on 28/08/19.
//

#ifndef pwd_h
#define pwd_h

void printDir();
void printDir()
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("Dir: %s", cwd);
}
#endif /* pwd_h */
