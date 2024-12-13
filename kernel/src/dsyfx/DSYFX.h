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

#pragma once

#include "../Kernel_Util.h"
#include "../Panic.h"
#include "../../../gnu-efi/bootloader/bootloader.h"


void _DSYFX_FAULT_DETECTED() {
    DSYFX_Fault("DSYFX Verification Failed. Key Mismatch!");
    while(true);
}

// Compare bootloader Magic Value with the one provided by the kernel and return either a 0 or 1 to be used by future functions.
int _DSYFX(int _DSYFX_CHALLENGE_INPUT) {

    int (BOOTLOADER)(_BOOTLOADER());

    int _DSYFX_BOOTLOADER_VALUE = BOOTLOADER;
    int _DSYFX_CHALLENGE_VALUE = _DSYFX_CHALLENGE_INPUT;
    
    if (_DSYFX_BOOTLOADER_VALUE != _DSYFX_CHALLENGE_VALUE) {
        return 0;
    } else {
        return 1;
    }
}

// Run the check at boot time and output to the console if the bootloader is valid. If not, the kernel will not boot.
int _DSYFX_BOOT_CHECK(int _DSYFX) {

    int (DSYFX_RETURN_VALUE)(_DSYFX);

    if (DSYFX_RETURN_VALUE == 1) {
        GlobalRenderer->Print("DSYFX Has Arrived");
        return 1;
    } else {
        _DSYFX_FAULT_DETECTED();
        return 0;
    }
}

