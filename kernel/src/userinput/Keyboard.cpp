/**
 * Copyright (c) 2021 Wayne Michael Thornton <wmthornton>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "Keyboard.h"

    bool isLeftShiftPressed;
    bool isRightShiftPressed;

void HandleKeyboard(uint8_t scancode){

    // Code to check keyboard type could be placed here in future iterations. Only use
    // QWERTY for the moment.
    
    switch (scancode){
        case LeftShift:
            isLeftShiftPressed = true;
            return;
        case LeftShift + 0x80:
            isLeftShiftPressed = false;
            return;
        case RightShift:
            isRightShiftPressed = true;
            return;
        case RightShift + 0x80:
            isRightShiftPressed = false;
            return;
        case Enter:
            GlobalRenderer->Next();
            return;
        case Spacebar:
            GlobalRenderer->PutChar(' ');
            return;
        case BackSpace:
           GlobalRenderer->ClearChar();
            // Not elegant, but allows enter key to be pressed and new line to be created within the YafSH shell. Bug exists wherein new content
            // cannot be fully deleted if it started at CursorPostion.X = 0, leaving artifacts.
            if (GlobalRenderer->CursorPosition.X < 72) {
                GlobalRenderer->CursorPosition.X = 72; 
            }
           return;
    }

    char ascii = QWERTYKeyboard::Translate(scancode, isLeftShiftPressed | isRightShiftPressed);

    if (ascii != 0){
        GlobalRenderer->PutChar(ascii);
    }

}

