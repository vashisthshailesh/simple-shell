//
//  mkd.h
//  
//
//  Created by home on 28/08/19.
//

#ifndef mkd_h
#define mkd_h
#include <string.h>
#include <limits.h>
#include <sys/stat.h>
#include <errno.h>

int mkdir_p(const char *path)
{
    
    const size_t len = strlen(path);
    char _path[PATH_MAX];
    char *p;
    
    errno = 0;
    

    if (len > sizeof(_path)-1) {
        errno = ENAMETOOLONG;
        return -1;
    }
    strcpy(_path, path);
    
    /* Iterate the string */
    for (p = _path + 1; *p; p++) {
        if (*p == '/') {
            /* Temporarily truncate */
            *p = '\0';
            
            if (mkdir(_path, S_IRWXU) != 0) {
                if (errno != EEXIST)
                return -1;
            }
            
            *p = '/';
        }
    }
    
    if (mkdirr(_path, S_IRWXU) != 0) {
        if (errno != EEXIST)
        return -1;
    }
    
    return 0;
}

#endif /* mkd_h */
