#pragma once

#include <iostream>
#include <cstdlib>
#include <conio.h>

#if defined(_WIN32) //! Compiling for Windows

#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN
#include <windows.h>

inline static void clearConsole()
{
    system("CLS");
}

#elif defined(__linux__) || (defined(__APPLE__) && defined(__MACH__)) //! Compiling for Linux and Mac

#include <unistd.h>
#include <termios.h>

inline static void clearConsole()
{
    system("clear");
}

inline static void Sleep(useconds_t ms)
{
    usleep((ms)*1000);
}

static char _getch()
{
    char buf = 0;
    termios old = { 0 };

    if (tcgetattr(STDIN_FILENO, &old) < 0) {
        std::cerr << "Error: Unable to get terminal attributes." << std::endl;
        exit(-1);
    }

    old.c_lflag &= ~ICANON; // Disable canonical mode
    old.c_lflag &= ~ECHO;   // Disable echoing( letters don't appear )
    old.c_cc[VMIN] = 1;     // Accept just a single character a.k.a "unbuffered"
    old.c_cc[VTIME] = 0;    // Block until data is available

    if (tcsetattr(STDIN_FILENO, TCSANOW, &old) < 0) {
        std::cerr << "Error: Unable to alter terminal attributes." << std::endl;
        exit(-1);
    }

    if (read(STDIN_FILENO, &buf, 1) < 0) {
        std::cerr << "Error: Cannot receive input for some reason..." << std::endl;
        exit(-1);
    }

    old.c_lflag |= ICANON; // Re-enable canonical mode
    old.c_lflag |= ECHO;   // Re-enable echoing

    if(tcsetattr(STDIN_FILENO, TCSADRAIN, &old) < 0) {
        std::cerr << "Error: Unable to reset terminal attributes." << std::endl;
        exit(-1);
    }

    return buf;
}

typedef std::ostream& HANDLE;
//! A simple workaround to make everything compile
#define GetStdHandle(h) std::cout

#define FOREGROUND_RED       0x1
#define FOREGROUND_GREEN     0x2
#define FOREGROUND_BLUE      0x4
#define FOREGROUND_INTENSITY 0x8

static void SetConsoleTextAttribute(HANDLE h, unsigned flags)
{
    static const char* termColors[] = {
        "\033[22;30m", // Black
        "\033[22;31m", // Red
        "\033[22;32m", // Green
        "\033[22;33m", // Brown
        "\033[22;34m", // Blue
        "\033[22;35m", // Magenta
        "\033[22;36m", // Cyan
        "\033[22;37m", // Gray
        "\033[01;30m", // Dark gray
        "\033[01;31m", // Light red
        "\033[01;32m", // Light green
        "\033[01;33m", // Yellow
        "\033[01;34m", // Light Blue
        "\033[01;35m", // Light magenta
        "\033[01;36m", // Light cyan
        "\033[01;37m"  // White
    };

    if (flags >= 16) {
        h << termColors[0];
    } else {
        h << termColors[flags];
    }
}

#endif

inline static void pauseConsole()
{
    std::cout << "\nPress any key to continue...";
    std::cout.flush();
    _getch();
    std::cout << std::endl;
}
