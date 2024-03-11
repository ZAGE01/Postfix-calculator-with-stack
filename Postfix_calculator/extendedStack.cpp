#include "extendedStack.h"
#include "Utility.h"

// Tavallinen konstruktori
Extended_stack::Extended_stack() {
    count = 0;
}

// Parametrillinen konstruktori
Extended_stack::Extended_stack(int size, Stack_entry value) {
    for (int i = 0; i < size && i < maxstack; i++) {
        entry[i] = value;
        count ++;
    }
}

// Tyhjentää stackin countin
void Extended_stack::clear() {
    count = 0;
}

// Kopioidaan stack
void copy_stack(Extended_stack &dest, Extended_stack &source) {
    Extended_stack temp;

    while (!source.empty()) {
        Stack_entry item;

        source.top(item);
        dest.push(item);
        temp.push(item);
        source.pop();
    }

    while (!temp.empty()) {
        Stack_entry item;

        temp.top(item);
        source.push(item);
        temp.pop();
    }
}

// Lisätään uusi alkio stackkiin
Error_code Extended_stack::push(const Stack_entry &item) {
   Error_code outcome = success;
   if (count >= maxstack) {
        outcome = overflow;
   }
   else {
        entry[count++] = item;
   }
   return outcome;
}

// Poistetaan alkio stackin päältä
Error_code Extended_stack::pop() {
   Error_code outcome = success;

   if (count == 0) {
        outcome = underflow;
   }
   else {
        --count;
   }

   return outcome;
}

// Palautetaan päällimmäinen alkio mutta ei poisteta
Error_code Extended_stack::top(Stack_entry &item) const {
   Error_code outcome = success;
   if (count == 0) {
        outcome = underflow;
   }
   else {
        item = entry[count - 1];
   }

   return outcome;
}

// Tarkistaa onko stack täynnä
bool Extended_stack::full() const {
    return count == maxstack;
}

// Palauttaa stackin alkioiden määrän
int Extended_stack::size() const {
    return count;
}

// Tarkistaa onko stack tyhjä
bool Extended_stack::empty() const {
   if (count > 0) {
    return false;
   }

    return true;
}
