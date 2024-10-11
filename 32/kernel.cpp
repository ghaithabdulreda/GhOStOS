#include "cpp/stdint.cpp"
#include "cpp/string.cpp"
#include "cpp/io/stdio.cpp"
#include "cpp/main.cpp"
int x = 42;

void r(){
    // root@GhOSt:
        printf("\n");
        printf(users[userselect].user);
        printf("@");
        printf(users[userselect].name);
        printf(":# ");
}


extern "C" void main() {
    




    clear();
    const char* str1 = "Kernel Start...\nPlease Wait...\n";
    printf(str1);
    

    
    

    
    prem();

    


    char input[50];
    
    // set_cursor_position(10, 20); // Set cursor position
    
    while (True) {
        r();

        
        
        scanf(input, sizeof(input));
        bool isFound = false;
        for (int i = 0; i < COMMAND_COUNT; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                isFound = true;
   
                check_execute(input);
                break;
            }
        }
        if (!isFound)
        {
            printf("\nCommand Not Found");
        }
        

    
    }

    return;
}
