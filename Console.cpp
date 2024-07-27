#include <iostream>
#include "Console.h"

void Console::PrintState(bool state)
{
    if (state)
    {
        std::cout << "+---------- AutoClicker ----------+\n";
        std::cout << "|                                 |\n";
        std::cout << "|             Enabled             |\n";
        std::cout << "|                                 |\n";
        std::cout << "+---------------------------------+\n\n";
    }
    else
    {
        std::cout << "+---------- AutoClicker ----------+\n";
        std::cout << "|                                 |\n";
        std::cout << "|            Disabled             |\n";
        std::cout << "|                                 |\n";
        std::cout << "+---------------------------------+\n\n";
    }
}