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

#include "Panic.h"
#include "Basic_Renderer.h"

void Panic(const char* panicMessage){
    
    CLEAR_FAULT_COLOR;
    CLEAR_SCREEN;

    CURSOR_DEFAULT;

    GlobalRenderer->Color = 0;

    GlobalRenderer->Print("Kernel Panic");

    CURSOR_DOUBLE;

    GlobalRenderer->Print(panicMessage);
}

void DSYFX_Fault(const char* faultMessage){
    
    CLEAR_FAULT_COLOR;
    CLEAR_SCREEN;

    CURSOR_DEFAULT;

    GlobalRenderer->Color = 0;

    GlobalRenderer->Print("Security Fault");

    CURSOR_DOUBLE;

    GlobalRenderer->Print(faultMessage);
}

void YAFSH_Fault(const char* faultMessage){
    
    CLEAR_FAULT_COLOR;
    CLEAR_SCREEN;

    CURSOR_DEFAULT;

    GlobalRenderer->Color = 0;

    GlobalRenderer->Print("YafSH Fault");

    CURSOR_DOUBLE;

    GlobalRenderer->Print(faultMessage);
}
