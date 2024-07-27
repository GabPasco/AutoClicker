#define _WINSOCKAPI_
#include <windows.h>

#include <iostream>
#include <chrono>
#include <thread>
#include "Console.h"

void FunctionSleep(int time) //To avoid conflicts with the sleep() function of the windows.h library
{
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void Click()
{
    mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, 0, 0);
    FunctionSleep(1);
    mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, 0, 0);
}

int key;
int amount_of_clicks;
int delay;
bool done = false; //Global variable that will change if the operation is done

void GetInfo()
{
    system("cls");
    std::cout << "Key (1 = Mouse3, 2 = Mouse4, 3 = Insert):\n>";
    std::cin >> key;
    system("cls");

    std::cout << "Amount of clicks (0 for loop):\n>";
    std::cin >> amount_of_clicks;
    system("cls");

    std::cout << "Delay between clicks (miliseconds):\n>";
    std::cin >> delay;
    system("cls");

    switch (key)
    {
    case 1:
        key = VK_XBUTTON2;
        break;
    case 2:
        key = VK_XBUTTON1;
        break;
    case 3:
        key = VK_INSERT;
        break;
    }
}

void AutoClick()
{
    if (amount_of_clicks > 0)
    {
        for (int i = 0; i != amount_of_clicks; i++)
        {
            Click();
            FunctionSleep(delay);
        }

        done = true;
    }
    else //Loop
    {
        Click();
        FunctionSleep(delay);
    }
}

int main()
{
    static bool last_work_state = true; //I need to set this true to print the state
    static bool work = false;

    SetConsoleTitleA("AutoClicker");

    GetInfo();

    while (true)
    {
        if (GetAsyncKeyState(key) & 1) //Check if the activation key is pressed
        {
            done = false;
            work = !work;
        }
        else if (done)
            work = false;

        if (work)
            AutoClick();
        else
            FunctionSleep(100);

        if (last_work_state != work) //Optimizes the console print
        {
            system("cls");;
            Console::PrintState(work);
        }

        last_work_state = work;
    }

    return 0;
}