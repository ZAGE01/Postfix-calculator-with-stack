#pragma once
#include "Utility.h"

typedef double Stack_entry;

// Maksimi stackin koko
const int maxstack = 100;

class Extended_stack {
    public:
        Extended_stack( );
        Extended_stack(int size, Stack_entry value);
        friend void copy_stack(Extended_stack &dest, Extended_stack &source);
        Error_code pop();
        Error_code top(Stack_entry &item) const;
        Error_code push(const Stack_entry &item);
        void clear( ); // Tyhjennys
        bool full( ) const; // Tarkistetaan onko täynnä
        int size( ) const; // Tarkistetaan alkioiden määrä
        bool empty( ) const; // Tarkistetaan onko tyhjä

    private:
        int count;
        Stack_entry entry[maxstack];
  };
