#include <stdlib.h>
#include "hidden_pairs.h"

int hidden_pairs(SudokuBoard *p_board)
{
    int detects = 0;

    // row iteration
    for (int i = 0; i < BOARD_SIZE; i++) // iterate over every row
    {
        for (int j = 0; j < BOARD_SIZE; j++) // iterate over every number 1-9
        {
            int candidate_count_a = 0;
            int *candidate_indices_a = malloc(0);
            for (int k = 0; k < BOARD_SIZE; k++) // iterate over every cell for those with candidate number j
            {
                if (p_board->p_rows[i][k]->candidates[j])
                {
                    candidate_count_a++;
                    candidate_indices_a = realloc(candidate_indices_a, candidate_count_a*4);
                    candidate_indices_a[candidate_count_a-1] = k;
                }
            }
            if (candidate_count_a == 2)
            {
                for (int l = j+1; l < BOARD_SIZE; l++) // iterate over every number j+1-9
                {
                    int candidate_count_b = 0;
                    int *candidate_indices_b = malloc(0);
                    for (int k = 0; k < BOARD_SIZE; k++) // iterate over every cell for those with candidate number l
                    {
                        if (p_board->p_rows[i][k]->candidates[l])
                        {
                            candidate_count_b++;
                            candidate_indices_b = realloc(candidate_indices_b, candidate_count_b*4);
                            candidate_indices_b[candidate_count_b-1] = k;
                        }
                    }
                    if (candidate_count_b == 2)
                    {
                        if (equal_arrays(candidate_indices_a, candidate_indices_b, 2)) // check if j and l have the same list of candidate indices
                        {
                            free(candidate_indices_b);
                            if (p_board->p_rows[i][candidate_indices_a[0]]->num_candidates == 2 && p_board->p_rows[i][candidate_indices_a[1]]->num_candidates == 2) break; // check if the "hidden" pair is actually naked
                            int hidden_pair_candidates[2] = {j+1, l+1};
                            set_candidates(p_board->p_cols[i][candidate_indices_a[0]], hidden_pair_candidates, 2); // remove every other candidates out of the cells
                            set_candidates(p_board->p_cols[i][candidate_indices_a[1]], hidden_pair_candidates, 2);
                            detects++;
                            break;
                        } else free(candidate_indices_b);
                    } else free(candidate_indices_b);
                }
            }
            free(candidate_indices_a);
        }
    }

    // column iteration
    for (int i = 0; i < BOARD_SIZE; i++) // iterate over every column
    {
        for (int j = 0; j < BOARD_SIZE; j++) // iterate over every number 1-9
        {
            int candidate_count_a = 0;
            int *candidate_indices_a = malloc(0);
            for (int k = 0; k < BOARD_SIZE; k++) // iterate over every cell for those with candidate number j
            {
                if (p_board->p_cols[i][k]->candidates[j])
                {
                    candidate_count_a++;
                    candidate_indices_a = realloc(candidate_indices_a, candidate_count_a*4);
                    candidate_indices_a[candidate_count_a-1] = k;
                }
            }
            if (candidate_count_a == 2)
            {
                for (int l = j+1; l < BOARD_SIZE; l++) // iterate over every number j+1-9
                {
                    int candidate_count_b = 0;
                    int *candidate_indices_b = malloc(0);
                    for (int k = 0; k < BOARD_SIZE; k++) // iterate over every cell for those with candidate number l
                    {
                        if (p_board->p_cols[i][k]->candidates[l])
                        {
                            candidate_count_b++;
                            candidate_indices_b = realloc(candidate_indices_b, candidate_count_b*4);
                            candidate_indices_b[candidate_count_b-1] = k;
                        }
                    }
                    if (candidate_count_b == 2)
                    {
                        if (equal_arrays(candidate_indices_a, candidate_indices_b, 2)) // check if j and l have the same list of candidate indices
                        {
                            free(candidate_indices_b);
                            if (p_board->p_cols[i][candidate_indices_a[0]]->num_candidates == 2 && p_board->p_cols[i][candidate_indices_a[1]]->num_candidates == 2) break; // check if the "hidden" pair is actually naked
                            int hidden_pair_candidates[2] = {j+1, l+1};
                            set_candidates(p_board->p_cols[i][candidate_indices_a[0]], hidden_pair_candidates, 2); // remove every other candidates out of the cells
                            set_candidates(p_board->p_cols[i][candidate_indices_a[1]], hidden_pair_candidates, 2);
                            detects++;
                            break;
                        } else free(candidate_indices_b);
                    } else free(candidate_indices_b);
                }
            }
            free(candidate_indices_a);
        }
    }

    // box iteration
    for (int i = 0; i < BOARD_SIZE; i++) // iterate over every box
    {
        for (int j = 0; j < BOARD_SIZE; j++) // iterate over every number 1-9
        {
            int candidate_count_a = 0;
            int *candidate_indices_a = malloc(0);
            for (int k = 0; k < BOARD_SIZE; k++) // iterate over every cell for those with candidate number j
            {
                if (p_board->p_boxes[i][k]->candidates[j])
                {
                    candidate_count_a++;
                    candidate_indices_a = realloc(candidate_indices_a, candidate_count_a*4);
                    candidate_indices_a[candidate_count_a-1] = k;
                }
            }
            if (candidate_count_a == 2)
            {
                for (int l = j+1; l < BOARD_SIZE; l++) // iterate over every number j+1-9
                {
                    int candidate_count_b = 0;
                    int *candidate_indices_b = malloc(0);
                    for (int k = 0; k < BOARD_SIZE; k++) // iterate over every cell for those with candidate number l
                    {
                        if (p_board->p_boxes[i][k]->candidates[l])
                        {
                            candidate_count_b++;
                            candidate_indices_b = realloc(candidate_indices_b, candidate_count_b*4);
                            candidate_indices_b[candidate_count_b-1] = k;
                        }
                    }
                    if (candidate_count_b == 2)
                    {
                        if (equal_arrays(candidate_indices_a, candidate_indices_b, 2)) // check if j and l have the same list of candidate indices
                        {
                            free(candidate_indices_b);
                            if (p_board->p_boxes[i][candidate_indices_a[0]]->num_candidates == 2 && p_board->p_boxes[i][candidate_indices_a[1]]->num_candidates == 2) break; // check if the "hidden" pair is actually naked
                            int hidden_pair_candidates[2] = {j+1, l+1};
                            set_candidates(p_board->p_boxes[i][candidate_indices_a[0]], hidden_pair_candidates, 2); // remove every other candidates out of the cells
                            set_candidates(p_board->p_boxes[i][candidate_indices_a[1]], hidden_pair_candidates, 2);
                            detects++;
                            break;
                        } else free(candidate_indices_b);
                    } else free(candidate_indices_b);
                }
            }
            free(candidate_indices_a);
        }
    }

    return detects;
}
