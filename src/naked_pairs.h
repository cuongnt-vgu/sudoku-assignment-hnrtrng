#pragma once

#include "sudoku.h"

typedef struct NakedPair_impl
{
    Cell *cell_a;
    Cell *cell_b;
    int candidate_1;
    int candidate_2;
    int constraint_type; // 0:row 1:column 2:box
} NakedPair;

int naked_pairs(SudokuBoard *p_board);