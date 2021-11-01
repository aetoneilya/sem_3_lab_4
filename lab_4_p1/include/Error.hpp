#pragma once

#include <iostream>
#include <fstream>

class Exception
{
protected:
    std::string m_error;

public:
    Exception(std::string error) : m_error(error) {}

    const char *what() const noexcept
    {
        return m_error.c_str();
    }
    ~Exception()
    {
        std::ofstream f("error.txt", std::ios::app);
        f << "Error: " << m_error;
        f.close();
    }
};

class MathException : Exception
{
private:
    std::string m_mathError;

public:
    MathException(std::string error, int a, int b, char op) : Exception(error)
    {
        m_mathError = std::to_string(a) + " " + op + " " + std::to_string(a);
    }

    const char *what() const noexcept
    {
        std::string error = m_error + " : " + m_mathError;
        return error.c_str();
    }
};