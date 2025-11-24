/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:09:14 by rick              #+#    #+#             */
/*   Updated: 2025/11/24 17:09:58 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Here is the logic for the Flood Fill Algorithm (often called the "Paint Bucket" algorithm).

This is the standard way to solve "pathfinding" in a grid without complex math.

The Concept: The Paint Bucket

Imagine your map is a floor plan. You are standing at P (Player). You spill a 
    giant bucket of red paint on the floor.

    The paint flows into every empty space (0), every collectible (C), and the exit (E).

    The paint stops when it hits a Wall (1) or a spot that is already red.

    After the paint stops spreading, you check the map: Is the Collectible (C) red?

        Yes: You can reach it.

        No: It is still dry, meaning walls are blocking it.

The 4 Steps to Code It

1. The Duplicate (Crucial)

You must never run this on your actual game map string. If you turn your 0s into Fs
     (Flooded), you can't play the game afterwards.

    Logic: malloc a fresh copy of your map->arr. You will destroy this copy when the check is done.

2. The Recursive Function (The "Spill")

This function takes the Copy and a coordinate (x, y). It calls itself recursively.

    Check Base Cases (Stop Conditions):

        Is (x, y) out of bounds? -> Stop.

        Is (x, y) a Wall (1)? -> Stop.

        Is (x, y) already Painted (F)? -> Stop.

    Action:

        Change the character at map[y][x] to F (or any "visited" marker).

    Recursion:

        Call the function on Right (x + 1).

        Call the function on Left (x - 1).

        Call the function on Down (y + 1).

        Call the function on Up (y - 1).

3. The Execution

You call this function once from your main validation logic. 
    You pass it the Player's starting coordinates (P_x, P_y). This starts the chain reaction.

4. The Verification

Once the function finishes (the paint has stopped spreading), 
    you iterate through your Map Copy one last time.

    Logic: Look for the character C.

    Result:

        If you find a C: Error. The paint didn't reach it. It is blocked.

        If you find 0 Cs: Success. All Cs were turned into Fs.

Summary of Flow

    Copy Map.

    Flood_Fill(copy, player_x, player_y).

    Scan(copy) -> Are there any 'C's or 'E's left?

        If yes -> Invalid Map.

        If no -> Valid Map.

    Free(copy).*/
