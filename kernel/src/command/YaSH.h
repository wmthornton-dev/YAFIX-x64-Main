#pragma once

#include <stdint.h>
#include "../Basic_Renderer.h"
#include "../C_String.h"
#include "../EFI_Memory.h"
#include "../System_Memory.h"
#include "../Memory_Bitmap.h"
#include "../paging/PageFrameAllocator.h"
#include "../paging/PageMapIndexer.h"
#include "../paging/Paging.h"
#include "../paging/PageTableManager.h"
#include "../userinput/Mouse.h"
#include "../userinput/Keyboard.h"
#include "../ACPI.h"
#include "../PCI.h"
#include "../scheduling/PIT.h"

// Standard line placement definitions. Decreases typing during coding ops.
#define YASH_CURSOR_SINGLE  GlobalRenderer->Next()
#define YASH_CURSOR_DOUBLE  GlobalRenderer->CursorPosition = {0, GlobalRenderer->CursorPosition.Y + 32}
#define YASH_CURSOR_TRIPLE  GlobalRenderer->CursorPosition = {0, GlobalRenderer->CursorPosition.Y + 48}
#define YASH_CURSOR_DEFAULT GlobalRenderer->CursorPosition = {0,0}

// Shortcut to clear screen output using memset() function.
#define YASH_CLEAR_SCREEN_MEMSET memset(bootInfo->framebuffer->BaseAddress, 0, bootInfo->framebuffer->BufferSize)

// Standard screen state color definitions.
#define YASH_CLEAR_FAULT_COLOR GlobalRenderer->ClearColor = 0x00ff0000;
#define YASH_CLEAR_STD_COLOR   GlobalRenderer->ClearColor = 0x0000000;
#define YASH_CLEAR_SCREEN      GlobalRenderer->Clear();

// YaSH information strings. Change as necessary for your system.
#define YASH_VERSION "YaSH (Yet another SHell) Version Generic_12292021-01_i386_amd64 (64-bit)"
#define YASH_COPYRIGHT_STRING "Copyright 2020 - 2024 Wayne Michael Thornton. All rights reserved."
#define YASH_DEVELOPER_INFO "Developed by Wayne Michael Thornton (wmthornton)."
#define YASH_LICENSE_INFO "Use is subject to license terms."
#define YASH_VERSION_UNFORMATTED "003"

class YaSH_Command {
	public:
	void YaSH_Input();
    void YaSH_Escape();
	
};

void YaSH_Initialize();
void YaSH_Prompt();

extern YaSH_Command* Shell_Command;