/*
 Copyright (c) 2024 Wayne Michael Thornton

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

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

void YafSH_handleCommand() {

    /* DEFAULT_CURSOR_X;
    DEFAULT_CURSOR_Y;
    INPUT;

    if ((GlobalRenderer->CursorPosition.X) > (Default_Cursor_X)) {
        if (!input) {
            input = true;
        }
        GlobalRenderer->Print("TRUE");
    } */
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

void YafSH_ReInitialize() {
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
   
    DEFAULT_CURSOR_X;
    DEFAULT_CURSOR_Y;
    COMMAND;
    OUTPUT;
    INPUT;

    while(true) {

        if (GlobalRenderer->CursorPosition.Y == Default_Cursor_Y + 16) {
            if (!output) {
                output = true;
            }
            GlobalRenderer->Print("YAFIX #: ");
            Default_Cursor_Y = GlobalRenderer->CursorPosition.Y;
            Default_Cursor_X = GlobalRenderer->CursorPosition.X;
            
        }
        if (GlobalRenderer->CursorPosition.Y > 999) { // Need to set this to use targetframebuffer height so it is dynamic, otherwise buggy
            YafSH_ReInitialize();
        }
        YafSH_handleCommand();
    }
}