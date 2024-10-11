#define COMMAND_COUNT 9
#define USERS_COUNT 2
#define SHADOW_COUNT 2
#define USERS_COUNT 2

int userselect = 0;
bool prem();
struct _users{
    char id[4];
    char user[50];
    char name[50];
    char passwd[50];


};
struct _commands{
    const char* command;
    const char* des;


};


_users users[USERS_COUNT] = {
    {"0", "ROOT", "ghost","1234512"},
    {"1", "GHOST", "Ghaith","12345612"}
}; 
_commands commands[COMMAND_COUNT] = {
    {"","When user Press enter"},


    {"LS", "Lists the files and directories in the current directory."},
    {"PWD", "Prints the current working directory (full path)."},
    {"WHOAMI", "Displays the current user name."},
    {"ID","Displays the current user id"},
    {"CLEAR", "Clears the current screen."},
    {"EXIT", "Closes the current session and exits the system."},
    {"PASSWD", "Change user Password."},
    {"HELP", "Displays a list of available commands with their descriptions."}

}; 

bool check_execute(char* str);



bool check_execute(char* str){
    
    if (strcmp(str, "CLEAR") == 0) {
        clear(); // clear the screen
        
    }
    else if (strcmp(str, "WHOAMI") == 0) {
        printf("\nid=");
        printf(users[userselect].id);
        printf(" (");
        printf(users[userselect].user);
        printf(")");
        
        
    }
    else if (strcmp(str, "ID") == 0) {
        printf("\nid=");
        printf(users[userselect].id);
        
        
        
    }
    else if (strcmp(str, "PASSWD") == 0) {
        char passwd[50];

        printf("\nChange password for ");
        printf(users[userselect].user);
        printf("\nCurrent password: ");
        scanf(passwd, sizeof(passwd));
        // printf(users[userselect].passwd);
        if (strcmp(passwd, users[userselect].passwd) == 0)
        {

            printf("\nNew password: ");
            scanf(passwd, sizeof(passwd));
            int i = 0;
            
            for (i; passwd[i] != '\0' && i < 49; i++) {
                users[userselect].passwd[i] = passwd[i];

            }
            users[userselect].passwd[i] = '\0'; // END OF Bytes
            
            printf("\npasswd: password updated successfully\n");

        }else{
            printf("\npasswd: Authentication token manipulation error\npasswd: password unchanged\n");

        }

    }
    else if (strcmp(str, "EXIT") == 0) {
        prem();
    }else if (strcmp(str, "HELP") == 0) {
        printf("\n\n");
        for (int i = 1; i < COMMAND_COUNT; ++i)
        {
            printf(commands[i].command);
            printf("    ");
            printf(commands[i].des);
            printf("\n");
        }


    }
    else {
        // printf("FIND\n");
    }

    return false;

}


bool _prem(const char* user, const char* passwd) {\
    userselect = 0;

    for (int i = 0; i < USERS_COUNT; ++i) {
        if (strcmp(user, users[i].user) == 0 && strcmp(passwd, users[i].passwd) == 0) {
            // printf("XX");
            
            
            return true; 
        }
        userselect+=1;
    }
    return false; 
}

bool prem(){
    char user[50];
    char passwd[50];
    while (true){
        printf("\nEnter username: ");
        scanf(user, sizeof(user)); 

        printf("\nEnter password: ");
        scanf(passwd, sizeof(passwd)); 
        if (_prem(user, passwd)) {
            printf("\nLogin successful!\n");

            break;
        } else {
            printf("\nLogin failed!\n");
        }
    }
    return true;
}