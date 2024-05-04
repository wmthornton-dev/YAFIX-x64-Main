#include "YaSH.h"

YaSH_Command* Shell_Command;

void YaSH_Initialize() {
    YASH_CLEAR_SCREEN;
    YASH_CURSOR_DEFAULT;

    GlobalRenderer->Print(YASH_VERSION);
    YASH_CURSOR_SINGLE;
    GlobalRenderer->Print(YASH_COPYRIGHT_STRING);
    YASH_CURSOR_SINGLE;
    GlobalRenderer->Print(YASH_DEVELOPER_INFO);
    YASH_CURSOR_SINGLE;
    GlobalRenderer->Print(YASH_LICENSE_INFO);
    YASH_CURSOR_DOUBLE;

    YaSH_Prompt();
    
}

void YaSH_Prompt() {
    GlobalRenderer->Print("YAFIX #: ");
    
    while(true) {
        //if (GlobalRenderer->PutChar(Enter)) {
            //YASH_CLEAR_SCREEN;
            //YASH_CURSOR_DEFAULT;
            //YaSH_Prompt();
        //}
    }
}