/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

 #include <cs50.h>
 #include <stdio.h>
 #include "helpers.h"
 
 
 /**
  * Returns true if value is in array of n values, else false.
  */
 bool search(int value, int values[], int n)
 {
     // binary search algorithm
     int guess;
     int max = n - 1;
     int min = 0;
     do
     {
         // check the middle
         guess = (max + min) / 2;
 
         // if the target is in the middle, we're doneskies
         if (values[guess] == value) {
            return true;
 
         // if the target is less than the middle, set the "max" = middle minus 1
         // and search the left side
         } else if (values[guess] > value) {
             max = guess - 1;
 
         // if the target is greater than the middle, search the right side
         } else if (values[guess] < value) {
             min = guess + 1;
         }
 
         // if min becomes greater than max, the target is not here, exit
         if (max < min) {
             break;
         }
     } while (guess > 0);
     return false;
 }
 
 /**
  * Sorts array of n values.
  */
 void sort(int values[], int n)
 {
     // find highest number in values[] and create a new array
     // with a size = the highest number in values + 1
     int highest = 0;
     for (int i = 0; i < n; i++) {
         if (values[i] > highest) {
             highest = values[i];
         }
     }
     highest++;
     int count[highest];
 
     // initialize result array with a size of n + 1
     int temp[n];
 
     // set all values in the count array equal to zero
     for (int i = 0; i <= highest; i++) {
         count[i] = 0;
     }
 
     // add 1 to the index of count equal to the number in values for each item
     // i.e. 2 three's in values means there is a 2 at index 3 of count
     for (int i = 0; values[i]; i++) {
         count[values[i]]++;
     }
 
     // set each index of count equal to itself plus the item before it
     for (int i = 1; i < highest; i++) {
         count[i] += count[i - 1];
     }
 
 
     // create output array
     for (int i = n - 1; i >= 0; i--) {
         temp[count[values[i]] - 1] = values[i];
         count[values[i]] = count[values[i]] - 1;
     }
 
     // set our array equal to the temp array
     for (int i = 0; values[i]; i++) {
         values[i] = temp[i];
     }
 }
 