#include <windows.h> // For Windows API functions
#include <cstdio>    // For printf and putchar
#include "codes.hpp"

void SetConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Map color codes to console colors
const int colors[] = {
    0,  // Black
    4,  // Red
    2,  // Green
    6,  // Yellow
    1,  // Blue
    5,  // Magenta
    3,  // Cyan
    7   // White
};

// Function to print colored text
void printColoredText(const char *text) {
    int colorCode = 7;  // Default color (White)
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] == '^' && text[i + 1] >= '0' && text[i + 1] <= '7') {
            colorCode = text[i + 1] - '0';  // Get the color code
            SetConsoleColor(colors[colorCode]);
            ++i;  // Skip the next character
        } else {
            putchar(text[i]);  // Print normal character
        }
    }
    SetConsoleColor(7);  // Reset to default color (White)
}
