# Lab 5 : Zuzana Czmelová

Link to your `Digital-electronics-2` GitHub repository:

 [https://github.com/Zuzanaczm/Digital_electronics_2/tree/main/Labs/05-segment](https://github.com/Zuzanaczm/Digital_electronics_2/tree/main/Labs/05-segment)


## Preparation tasks

Read the [7-segment display tutorial](https://www.electronics-tutorials.ws/blog/7-segment-display-tutorial.html) and find out what is the difference between:
   * Common Cathode 7-segment display (CC SSD)
   * Common Anode 7-segment display (CA SSD)

In the following table, write the binary values of the segments for display 0 to 9 on a common anode 7-segment display.

   | **Digit** | **A** | **B** | **C** | **D** | **E** | **F** | **G** | **DP** |
   | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
   | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 |
   | 1 |  1 | 0  | 0  |  1 | 1  |1   | 1  | 1  |
   | 2 | 0  | 0  |  1 |  0 |0   |  1 | 0  | 1  |
   | 3 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 1 |
   | 4 |  1 | 0  | 0  |  1 |1   |0   |  0 |1  |
   | 5 |  0 | 1  | 0  |  0 | 1  |  0 | 0  | 1  |
   | 6 | 0  | 1  | 0  | 0  | 0  | 0  | 0  |   1|
   | 7 | 0  |   0| 0  |  1 |  1 | 1  | 1  | 1  |
   | 8 | 0  |  0 | 0  |  0 |  0 | 0  | 0  | 1  |
   | 9 | 0  |  0 | 0  | 0  |  1 |  0 | 0  | 1  |

## Part 1 - 7_segment library
   * Listing of library source file `segment.c`,
    * Listing of decimal counter application `main.c` (at least two-digit decimal counter, ie. from 00 to 59),
    * Screenshot of SimulIDE circuit.
    *
## Part 2 - Snake
 * Look-up table with snake definition,
    * Listing of your snake cycling application `main.c` (at least one-digit snake).
