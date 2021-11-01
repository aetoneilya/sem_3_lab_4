#include <iostream>
#include <vector>
#include "Fraction.hpp"

class UnitTest
{
private:
    std::vector<Fraction> left;
    std::vector<Fraction> right;
    int count;

    std::vector<Fraction> resultPlus;
    std::vector<Fraction> resultMinus;
    std::vector<Fraction> resultMultiply;
    std::vector<Fraction> resultDivide;

public:
    UnitTest(std::vector<Fraction> &left_, std::vector<Fraction> &right_)
    {
        left = left_;
        right = right_;
        count = 0;
    }

    void setPlusTest(std::vector<Fraction> &resultPlus_)
    {
        resultPlus = resultPlus_;
    }
    void setMinusTest(std::vector<Fraction> &resultMinus_)
    {
        resultMinus = resultMinus_;
    }
    void setMultiplyTest(std::vector<Fraction> &resultMultiply_)
    {
        resultMultiply = resultMultiply_;
    }
    void setDivideTest(std::vector<Fraction> &resultDivide_)
    {
        resultDivide = resultDivide_;
    }

    void runTest()
    {
        // plus test
        for (int i = 0; i < resultPlus.size(); i++)
        {
            std::cout << "Test[" << count << "] : "
                      << left[i] << " + " << right[i]
                      << " = " << left[i] + right[i];

            if (left[i] + right[i] == resultPlus[i])
                std::cout << "\tPASSED\n";
            else
                std::cout << "\tFAILED\n";

            count++;
        }
        std::cout << std::endl;

        // minus test
        for (int i = 0; i < resultMinus.size(); i++)
        {
            std::cout << "Test[" << count << "] : "
                      << left[i] << " - " << right[i]
                      << " = " << left[i] - right[i];

            if (left[i] - right[i] == resultMinus[i])
                std::cout << "\tPASSED\n";
            else
                std::cout << "\tFAILED\n";

            count++;
        }
        std::cout << std::endl;

        // multiply test
        for (int i = 0; i < resultMultiply.size(); i++)
        {
            std::cout << "Test[" << count << "] : "
                      << left[i] << " * " << right[i]
                      << " = " << left[i] * right[i];

            if (left[i] * right[i] == resultMultiply[i])
                std::cout << "\tPASSED\n";
            else
                std::cout << "\tFAILED\n";

            count++;
        }
        std::cout << std::endl;

        // divide test
        for (int i = 0; i < resultDivide.size(); i++)
        {
            Fraction res = left[i] / right[i];
            std::cout << "Test[" << count << "] : "
                      << left[i] << " / " << right[i]
                      << " = " << res;

            if (res == resultDivide[i])
                std::cout << "\tPASSED\n";
            else
                std::cout << "\tFAILED\n";

            count++;
        }
        std::cout << std::endl;
    }
};

main()
{
    std::vector<Fraction> left;
    std::vector<Fraction> right;

    std::vector<Fraction> Plus;
    std::vector<Fraction> Minus;
    std::vector<Fraction> Multiply;
    std::vector<Fraction> Divide;

    Fraction fraction1(1, 2);
    Fraction fraction2(12, 7);
    Fraction fraction3(-3, 2);
    Fraction fraction4(4, 5);
    Fraction fraction5(0, 7);
    Fraction fraction6(1, 1);

    Fraction fraction7(1, 2);
    Fraction fraction8(2, 37);
    Fraction fraction9(-3, -2);
    Fraction fraction10(24, 25);
    Fraction fraction11(0, 7);
    Fraction fraction12(1, 1);

    left.push_back(fraction1);
    left.push_back(fraction2);
    left.push_back(fraction3);
    left.push_back(fraction4);
    left.push_back(fraction5);
    left.push_back(fraction6);

    right.push_back(fraction7);
    right.push_back(fraction8);
    right.push_back(fraction9);
    right.push_back(fraction10);
    right.push_back(fraction11);
    right.push_back(fraction12);

    // Plus results;
    Fraction resPlus1(1, 1);
    Fraction resPlus2(458, 259);
    Fraction resPlus3(0, 4);
    Fraction resPlus4(44, 25);
    Fraction resPlus5(0, 1);
    Fraction resPlus6(2, 1);

    Plus.push_back(resPlus1);
    Plus.push_back(resPlus2);
    Plus.push_back(resPlus3);
    Plus.push_back(resPlus4);
    Plus.push_back(resPlus5);
    Plus.push_back(resPlus6);

    // Minus results
    Fraction resMinus1(0, 1);
    Fraction resMinus2(430, 259);
    Fraction resMinus3(-3, 1);
    Fraction resMinus4(-4, 25);
    Fraction resMinus5(0, 1);
    Fraction resMinus6(0, 1);

    Minus.push_back(resMinus1);
    Minus.push_back(resMinus2);
    Minus.push_back(resMinus3);
    Minus.push_back(resMinus4);
    Minus.push_back(resMinus5);
    Minus.push_back(resMinus6);

    // Multiply results
    Fraction resMultiply1(1, 4);
    Fraction resMultiply2(24, 259);
    Fraction resMultiply3(-9, 4);
    Fraction resMultiply4(96, 125);
    Fraction resMultiply5(0, 1);
    Fraction resMultiply6(1, 1);

    Multiply.push_back(resMultiply1);
    Multiply.push_back(resMultiply2);
    Multiply.push_back(resMultiply3);
    Multiply.push_back(resMultiply4);
    Multiply.push_back(resMultiply5);
    Multiply.push_back(resMultiply6);

    // Divide results
    Fraction resDivide1(1, 1);
    Fraction resDivide2(222, 7);
    Fraction resDivide3(-1, 1);
    Fraction resDivide4(5, 6);
    Fraction resDivide5(0, 1);
    Fraction resDivide6(1, 1);

    Divide.push_back(resDivide1);
    Divide.push_back(resDivide2);
    Divide.push_back(resDivide3);
    Divide.push_back(resDivide4);
    Divide.push_back(resDivide5);
    Divide.push_back(resDivide6);

    UnitTest frTest(left, right);
    frTest.setPlusTest(Plus);
    frTest.setMinusTest(Minus);
    frTest.setMultiplyTest(Multiply);
    frTest.setDivideTest(Divide);

    frTest.runTest();
    
    system("pause");
}