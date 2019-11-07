# simple-shell
Designed a simple shell which handles all the commands


this code excutes the following commands:-

ls - [-a] and -[e] 
history -  [c]
quit
echo- [-n] and [e]
clear
rm ,date ,mkdir ,cat - all commands for this will be excuted
pwd - [-p], [-e]
cd 

 - the ls command is imported from the header file "sm.h". it handles two commands namely it shows the hidden files when used -a and -e the default to print the 

- history one if the deafult one and the other one [c] is to clear the history which is imported from the header file "history.h"

- quit is just a break statement in the code ;

- the default one is implememented in the main itself and the same goes for [-n]

- clear just clears the current scrren

-rm , date , mkdir and cat are excuted by excecvp()-
the first arguemnt given to it is the string which contains the name of the file to be excuted
the second argument is a pointer to an array of char Strings.
child process are created for this using fork()

-pwd - is called after every command so as to tell in which directry you are currently . it is impoerted form "pwd.h", in turn which uses getcwd(); it excutes -L and -P.


-cd - changes the directory , implemented within the cm.c file;




testing  the program
--------------------
ls
(shows the files and directories in that directory)
date
(shows date)
mkdir check 
(check directory created)
rm -d check
ls
(check file not there)
rm -d check
(prompt: check file not there)
asdfasf
this command is not implemented







errors handled
--------------
- when rm is used on a non exsistent file it shows: "no such file or directory"
- when cd to a non exsistent directory it shows: no such directory
- when any other command is written other than the specifed 10 it pops "command not implemented"



