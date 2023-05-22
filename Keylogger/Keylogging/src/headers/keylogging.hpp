#ifndef __KEYLOGGING__
#define __KEYLOGGING__

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#include <iostream>
#include <fstream>
#else
#include <iostream>
#include <fstream>
#include <X11/Xlib.h>
#include <X11/XKBlib.h>
#include <X11/keysym.h>
#include <fmt/format.h>

/*https://stackoverflow.com/questions/30439094/how-to-represent-keys-in-c-likeenter-shift-alt-space-etc*/

// TODO:
// - Finish all key mappings from the link -> https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

#define VK_CLEAR          0x0C
#define VK_RETURN         0x0D
#define VK_BACK           0x08
#define VK_TAB            0X09
#define VK_SHIFT          0x10 
#define VK_CONTROL        0x11
#define VK_MENU           0x12
#define VK_PAUSE          0x13
#define VK_CAPITAL        0x14

#define VK_KANA           0x15
#define VK_HANGEUL        0x15
#define VK_HANGUL         0x15
#define VK_JUNJA          0x17
#define VK_FINAL          0x18
#define VK_HANJA          0x19

#define VK_ESCAPE         0x1B

#define VK_CONVERT        0x1C
#define VK_NONCONVERT     0x1D
#define VK_ACCEPT         0x1E
#define VK_MODECHANGE     0x1F

#define VK_SPACE          0x20
#define VK_PRIOR          0x21
#define VK_NEXT           0x22
#define VK_END            0x23
#define VK_HOME           0x24
#define VK_LEFT           0x25
#define VK_UP             0x26
#define VK_RIGHT          0x27
#define VK_DOWN           0x28
#define VK_SELECT         0x29
#define VK_PRINT          0x2A
#define VK_EXECUTE        0x2B
#define VK_SNAPSHOT       0x2C
#define VK_INSERT         0x2D
#define VK_DELETE         0x2F
#define VK_HELP           0x2E

#endif

//https://www.youtube.com/watch?v=6f1GUyY9TYE

#define LOG_FILE "keylogger.txt"

void saveData(std::string data);
std::string translateSpecialKey(int key);

#endif