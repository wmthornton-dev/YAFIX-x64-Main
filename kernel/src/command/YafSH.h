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
#define YAFSH_CURSOR_SINGLE  GlobalRenderer->Next()
#define YAFSH_CURSOR_DOUBLE  GlobalRenderer->CursorPosition = {0, GlobalRenderer->CursorPosition.Y + 32}
#define YAFSH_CURSOR_TRIPLE  GlobalRenderer->CursorPosition = {0, GlobalRenderer->CursorPosition.Y + 48}
#define YAFSH_CURSOR_DEFAULT GlobalRenderer->CursorPosition = {0,0}

// Shortcut to clear screen output using memset() function.
#define YAFSH_CLEAR_SCREEN_MEMSET memset(bootInfo->framebuffer->BaseAddress, 0, bootInfo->framebuffer->BufferSize)

// Standard screen state color definitions.
#define YAFSH_CLEAR_FAULT_COLOR GlobalRenderer->ClearColor = 0x00ff0000;
#define YAFSH_CLEAR_STD_COLOR   GlobalRenderer->ClearColor = 0x0000000;
#define YAFSH_CLEAR_SCREEN      GlobalRenderer->Clear();

// YaSH information strings. Change as necessary for your system.
#define YAFSH_VERSION "YafSH (Yet another fucking SHell) Version Generic_12292021-01_i386_amd64 (64-bit)"
#define YAFSH_COPYRIGHT_STRING "Copyright 2020 - 2024 Wayne Michael Thornton. All rights reserved."
#define YAFSH_DEVELOPER_INFO "Developed by Wayne Michael Thornton (wmthornton)."
#define YAFSH_LICENSE_INFO "Use is subject to license terms."
#define YAFSH_VERSION_UNFORMATTED "003"

class YafSH_Command {
	public:
	void YafSH_Input();
    void YafSH_Escape();
	
};

void YafSH_Initialize();
void YafSH_Prompt();

extern YafSH_Command* Shell_Command;