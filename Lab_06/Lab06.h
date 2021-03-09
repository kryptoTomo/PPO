#pragma once

#include<vector>

using Bits = std::vector<int>;
typedef void (*function)(Bits*,const Bits*);
void set(Bits * bin,int * buffer,int size);
void print(const Bits * bin);
Bits add_up(const Bits *vect_first,const Bits * vect_second);
void bit_and(Bits* bin,const Bits* mask);
void bit_xor(Bits* bin,const Bits* mask);
void doOperation(const function f,Bits* bin,const Bits* mask);
int to_decimal(const Bits * bin);