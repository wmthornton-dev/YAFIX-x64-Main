#pragma once

// DSYFX Magic Number
int _BOOTLOADER() {
    int _BOOTLOADER_RETURN_VALUE;

    // Can be any arbitrary value set by the developer so long as that number is not easily guessed.
    _BOOTLOADER_RETURN_VALUE = 0x6EA811; // Deanna's birthday in hex format

    return _BOOTLOADER_RETURN_VALUE;
}