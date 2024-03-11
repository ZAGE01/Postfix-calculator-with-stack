#include <iostream>
#include <string>
#include "extendedStack.h"
#include "Utility.h"

using namespace std;

void postFix(string& expression) {
    // Luodaan stack
    Extended_stack stack;

    // Käyttäjän lausekkeen luvut
    double operand1, operand2;

    for (char character : expression) {
        // Hypätään välilyöntien yli
        if (character == ' ') {
            continue;
        }
        // Tarkistetaan onko merkki numero
        if (isdigit(character)) {
            // Muunnetaan merkki luvuksi ja työnnetään stäckkiin
            stack.push(character - '0');
        }
        else if (character == '+' || character == '-' || character == '*' || character == '/') {
            if (stack.size() < 2) {
                cout << "Error: invalid expression!" << endl;
                return;
            }

            // Sijoitetaan luvut stackistä muuttujiin ja poistetaan ne stackistä
            stack.top(operand2);
            stack.pop();
            stack.top(operand1);
            stack.pop();

            // Testataan switchillä mikä laskutoimitus on kyseessä
            switch (character) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        stack.push(operand1 / operand2);
                    }
                    else {
                        cout << "Error: division by zero!" << endl;
                        return;
                    }
                    break;
                default:
                    cout << "Error: invalid operator!" << endl;
                    return;
            }
        }
        // Vaihtofunktio
        else if (character == 'x') {
            if (stack.size() < 2) {
                cout << "Error: insufficient operands for exchange" << endl;
                return;
            }
            // Vaihdetaan operandien paikkaa stackissä
            stack.top(operand1);
            stack.pop();
            stack.top(operand2);
            stack.pop();
            stack.push(operand1);
            stack.push(operand2);
        }
        // Summa-toiminto ja keskiarvotoiminto
        else if (character == 's' || character == 'a') {
            double sum = 0;
            int count = 0;
            while (!stack.empty()) {
                stack.top(operand1);
                stack.pop();
                sum += operand1;
                count++;
            }
            if (character == 'a') {
                stack.push(sum / count);
            }
            else {
                stack.push(sum);
            }
        }
    }

    // Tulostetaan tulos stackistä
    double result;
    stack.top(result);
    cout << "Result: " << result << endl;
}

int main() {
    // Käyttäjän antama lauseke
    string expression;

    cout << "Enter an expression (for example: 12+). 'q' to quit: ";

    // Käyttäjältä pyydetään lausekkeita, kunnes vastaus on "q" tai "Q"
    while (getline(cin, expression) && expression != "q" && expression != "Q") {
        postFix(expression);
        cout << "Enter an expression (for example: 12+). 'q' to quit: ";
    }

    return 0;
}