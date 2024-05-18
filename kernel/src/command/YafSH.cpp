#include "YafSH.h"

YafSH_Command* Shell_Command;

void YafSH_displayHelp() {
    GlobalRenderer->Print("YAFIX Operating System");
    YAFSH_CURSOR_SINGLE;
    GlobalRenderer->Print("------------------------");
    YAFSH_CURSOR_SINGLE;
    GlobalRenderer->Print("YAFIX is a simple command-line operating system that aims to provide basic functionality.");
    YAFSH_CURSOR_DOUBLE;
    GlobalRenderer->Print("Available commands:");
    YAFSH_CURSOR_SINGLE;
    GlobalRenderer->Print("  help: Display this help message");
    YAFSH_CURSOR_SINGLE;
    GlobalRenderer->Print("  exit: Exit the operating system");
    YAFSH_CURSOR_SINGLE;
    GlobalRenderer->Print("  clear: Clear the screen");
    YAFSH_CURSOR_SINGLE;
    GlobalRenderer->Print("  ls: List files and directories");
    YAFSH_CURSOR_SINGLE;
    GlobalRenderer->Print("  cat: Display the contents of a file");
    YAFSH_CURSOR_SINGLE;
    GlobalRenderer->Print("  cd: Change the current directory");
    YAFSH_CURSOR_SINGLE;
    GlobalRenderer->Print("  mkdir: Create a new directory");
    YAFSH_CURSOR_SINGLE;
    GlobalRenderer->Print("  touch: Create a new empty file");
    YAFSH_CURSOR_SINGLE;
    GlobalRenderer->Print("  rm: Delete a file or directory");
    YAFSH_CURSOR_DOUBLE;
}

void YafSH_handleCommand(const char* command) {

    // if (strcmp(command, HELP)== 0 || strcmp(command, "-h") == 0)
    if (strcmp(command, HELP)== 0 || strcmp(command, HELP))
    {
        YafSH_displayHelp();
    }

}

void YafSH_Initialize() {
    YAFSH_CLEAR_SCREEN;
    YAFSH_CURSOR_DEFAULT;

    GlobalRenderer->Print(YAFSH_VERSION);
    YAFSH_CURSOR_SINGLE;
    GlobalRenderer->Print(YAFSH_COPYRIGHT_STRING);
    YAFSH_CURSOR_SINGLE;
    GlobalRenderer->Print(YAFSH_DEVELOPER_INFO);
    YAFSH_CURSOR_SINGLE;
    GlobalRenderer->Print(YAFSH_LICENSE_INFO);
    YAFSH_CURSOR_DOUBLE;

    YafSH_displayHelp();
    YafSH_Prompt();
    
}



void YafSH_Prompt() {
    GlobalRenderer->Print("YAFIX #: ");

    while(true) {
            //char command[256];
            //char* commandPtr = command;
            
            //YafSH_handleCommand(commandPtr);

        }

}