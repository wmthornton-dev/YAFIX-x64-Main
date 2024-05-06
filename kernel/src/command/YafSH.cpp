#include "YafSH.h"

YafSH_Command* Shell_Command;

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

    YafSH_Prompt();
    
}


void YafSH_Prompt() {
    GlobalRenderer->Print("YAFIX #: ");

    while(true) {
            
        }

}