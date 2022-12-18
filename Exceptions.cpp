// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

// An AlexCustomException class is included which expands upon public std::exception
struct AlexCustomException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Alex Custom Exception";
    }
};

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception
  // Throws a standard exception.
    throw std::exception("Throwing a standard exception");

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    try
    {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    // Catch the standard exception thrown
    catch (const std::exception& exception)
    {
        // Prints out the exception message thrown
        std::cout << "The exception message thrown is - " << exception.what() << std::endl;
    }

    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main

    // AlexCustomException is thrown
    throw AlexCustomException();

    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception

    // If denominator of 0 is inputted then an error will be caught.
    if (den == 0)
    {
        // Throws a runtime error exception stating that dividing by zero is undefined.
        throw std::runtime_error("Dividing by zero is undefined ");
    }
    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    try
    {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    // This can catch the exception when the denominator is zero.  
    catch (const std::exception& exception)
    {
        std::cout << "Exception Result is - " << exception.what() << std::endl;
    }
}

int main()
{
    try
    {
        std::cout << "Exceptions Tests!" << std::endl;

        // TODO: Create exception handlers that catch (in this order):
        //  your custom exception
        //  std::exception
        //  uncaught exception 
        //  that wraps the whole main function, and displays a message to the console.
        do_division();
        do_custom_application_logic();
    }
    // Catch AlexCustomException
    catch (const AlexCustomException& exception)
    {
        std::cout << "Exception Result is - " << exception.what() << std::endl;
    }
    // Catches the standard exception  
    catch (const std::exception& exception)
    {
        std::cout << "Exception Result is - " << exception.what() << std::endl;
    }
    // This is to catch common exceptions.
    catch (...) {
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
