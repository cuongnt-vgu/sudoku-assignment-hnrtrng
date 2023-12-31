#include <stdlib.h>
#include "naked_pairs.h"

int naked_pairs(SudokuBoard *p_board)
{
    int detects = 0;
    NakedPair *pairs = malloc(0);

    // row iteration
    for (int i = 0; i < BOARD_SIZE; i++) // iterate over every row
    {
        for (int j = 0; j < BOARD_SIZE; j++) // iterate over every cell
        {
            if (p_board->p_rows[i][j]->num_candidates == 2) // if the cell has 2 candidates
            {
                for (int k = j+1; k < BOARD_SIZE; k++) // iterate over every remaining unchecked cells
                {
                    if (p_board->p_rows[i][k]->num_candidates == 2) // if the cell has 2 candidates
                    {
                        int *candidates_a = malloc(8);
                        int *candidates_b = malloc(8);
                        int index = 0;
                        for (int l = 0; l < BOARD_SIZE; l++)
                        {
                            if (p_board->p_rows[i][j]->candidates[l])
                            {
                                candidates_a[index++] = l;
                            }
                        }
                        index = 0;
                        for (int l = 0; l < BOARD_SIZE; l++)
                        {
                            if (p_board->p_rows[i][k]->candidates[l])
                            {
                                candidates_b[index++] = l;
                            }
                        }
                        if (equal_arrays(candidates_a, candidates_b, 2)) // if the 2 cells have the same candidates
                        {
                            NakedPair temp;
                            temp.cell_a = p_board->p_rows[i][j];
                            temp.cell_b = p_board->p_rows[i][k];
                            temp.candidate_1 = candidates_a[0]+1;
                            temp.candidate_2 = candidates_a[1]+1;
                            temp.constraint_type = 0;
                            int already_checked = 0;
                            for (int l = 0; l < detects; l++)
                                if (pairs[l].cell_a == temp.cell_a && pairs[l].cell_b == temp.cell_b)
                                    already_checked = 1;
                            if (!already_checked)
                            {
                                detects++;
                                pairs = realloc(pairs, detects * sizeof(NakedPair));
                                pairs[detects - 1] = temp;
                            }
                            free(candidates_a);
                            free(candidates_b);
                            break;
                        }
                        free(candidates_a);
                        free(candidates_b);
                    }
                }
            }
        }
    }

    // column iteration
    for (int i = 0; i < BOARD_SIZE; i++) // iterate over every column
    {
        for (int j = 0; j < BOARD_SIZE; j++) // iterate over every cell
        {
            if (p_board->p_cols[i][j]->num_candidates == 2) // if the cell has 2 candidates
            {
                for (int k = j+1; k < BOARD_SIZE; k++) // iterate over every remaining unchecked cells
                {
                    if (p_board->p_cols[i][k]->num_candidates == 2) // if the cell has 2 candidates
                    {
                        int *candidates_a = malloc(8);
                        int *candidates_b = malloc(8);
                        int index = 0;
                        for (int l = 0; l < BOARD_SIZE; l++)
                        {
                            if (p_board->p_cols[i][j]->candidates[l])
                            {
                                candidates_a[index++] = l;
                            }
                        }
                        index = 0;
                        for (int l = 0; l < BOARD_SIZE; l++)
                        {
                            if (p_board->p_cols[i][k]->candidates[l])
                            {
                                candidates_b[index++] = l;
                            }
                        }
                        if (equal_arrays(candidates_a, candidates_b, 2)) // if the 2 cells have the same candidates
                        {
                            NakedPair temp;
                            temp.cell_a = p_board->p_cols[i][j];
                            temp.cell_b = p_board->p_cols[i][k];
                            temp.candidate_1 = candidates_a[0]+1;
                            temp.candidate_2 = candidates_a[1]+1;
                            temp.constraint_type = 1;
                            int already_checked = 0;
                            for (int l = 0; l < detects; l++)
                                if (pairs[l].cell_a == temp.cell_a && pairs[l].cell_b == temp.cell_b)
                                    already_checked = 1;
                            if (!already_checked)
                            {
                                detects++;
                                pairs = realloc(pairs, detects * sizeof(NakedPair));
                                pairs[detects - 1] = temp;
                            }
                            free(candidates_a);
                            free(candidates_b);
                            break;
                        }
                        free(candidates_a);
                        free(candidates_b);
                    }
                }
            }
        }
    }

    // box iteration
    for (int i = 0; i < BOARD_SIZE; i++) // iterate over every box
    {
        for (int j = 0; j < BOARD_SIZE; j++) // iterate over every cell
        {
            if (p_board->p_boxes[i][j]->num_candidates == 2) // if the cell has 2 candidates
            {
                for (int k = j+1; k < BOARD_SIZE; k++) // iterate over every remaining unchecked cells
                {
                    if (p_board->p_boxes[i][k]->num_candidates == 2) // if the cell has 2 candidates
                    {
                        int *candidates_a = malloc(8);
                        int *candidates_b = malloc(8);
                        int index = 0;
                        for (int l = 0; l < BOARD_SIZE; l++)
                        {
                            if (p_board->p_boxes[i][j]->candidates[l])
                            {
                                candidates_a[index++] = l;
                            }
                        }
                        index = 0;
                        for (int l = 0; l < BOARD_SIZE; l++)
                        {
                            if (p_board->p_boxes[i][k]->candidates[l])
                            {
                                candidates_b[index++] = l;
                            }
                        }
                        if (equal_arrays(candidates_a, candidates_b, 2)) // if the 2 cells have the same candidates
                        {
                            NakedPair temp;
                            temp.cell_a = p_board->p_boxes[i][j];
                            temp.cell_b = p_board->p_boxes[i][k];
                            temp.candidate_1 = candidates_a[0]+1;
                            temp.candidate_2 = candidates_a[1]+1;
                            temp.constraint_type = 2;
                            int already_checked = 0;
                            for (int l = 0; l < detects; l++)
                                if (pairs[l].cell_a == temp.cell_a && pairs[l].cell_b == temp.cell_b)
                                    already_checked = 1;
                            if (!already_checked)
                            {
                                detects++;
                                pairs = realloc(pairs, detects * sizeof(NakedPair));
                                pairs[detects - 1] = temp;
                            }
                            free(candidates_a);
                            free(candidates_b);
                            break;
                        }
                        free(candidates_a);
                        free(candidates_b);
                    }
                }
            }
        }
    }

    for (int i = 0; i < detects; i++)
    {
        int pair_candidates[2] = {pairs[i].candidate_1, pairs[i].candidate_2};
        switch (pairs[i].constraint_type)
        {
            case 0:
                apply_constraint(p_board->p_rows[pairs[i].cell_a->row_index], pairs[i].candidate_1);
                apply_constraint(p_board->p_rows[pairs[i].cell_a->row_index], pairs[i].candidate_2);
                set_candidates(pairs[i].cell_a, pair_candidates, 2);
                set_candidates(pairs[i].cell_b, pair_candidates, 2);
                break;
            case 1:
                apply_constraint(p_board->p_cols[pairs[i].cell_a->col_index], pairs[i].candidate_1);
                apply_constraint(p_board->p_cols[pairs[i].cell_a->col_index], pairs[i].candidate_2);
                set_candidates(pairs[i].cell_a, pair_candidates, 2);
                set_candidates(pairs[i].cell_b, pair_candidates, 2);
                break;
            case 2:
                apply_constraint(p_board->p_boxes[pairs[i].cell_a->box_index], pairs[i].candidate_1);
                apply_constraint(p_board->p_boxes[pairs[i].cell_a->box_index], pairs[i].candidate_2);
                set_candidates(pairs[i].cell_a, pair_candidates, 2);
                set_candidates(pairs[i].cell_b, pair_candidates, 2);
                break;
        }
    }
    free(pairs);

    return detects;
}