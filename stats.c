/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file <Add File Name>
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

    return 0;
}

/* Add other Implementation File Code Here */

void print_array(unsigned char* array, unsigned int length){
    printf("[");
    for (unsigned int i = 0; i < length - 1; ++i)
        printf("%d ", array[i]);
    printf("%d]\n", array[length-1]);
}

unsigned char find_median(unsigned char* array, unsigned int length){
    unsigned char c_arr[length]; // copy array
    for (unsigned int i = 0; i < length; ++i)
        c_arr[i] = array[i];
    
    // sort array
    sort_array(c_arr, length);
    
    // if length is odd, median = arr[N/2]
    // if length is even, median = 1/2(arr[n\2] + arr[n/2-1])
    if (length % 2 == 0) // length is even
        return (c_arr[length/2] + c_arr[length/2-1])/2;
    return c_arr[length/2];
}

unsigned char find_mean(unsigned char* array, unsigned int length){
    unsigned long sum = 0;
    for (unsigned int i = 0; i < length; ++i)
        sum += array[i];
    return (unsigned char) sum/length;
}


unsigned char find_maximum(unsigned char* array, unsigned int length){
    unsigned char max = array[0];
    for (unsigned int i = 1; i < length; ++i)
        if (array[i] > max)
            max = array[i];
    
    return max;
}

unsigned char find_minimum(unsigned char* array, unsigned int length){
    unsigned char min = array[0];
    for (unsigned int i = 1; i < length; ++i)
        if (array[i] < min)
            min = array[i];
    
    return min;
}

void merge(unsigned char* array,unsigned int l, unsigned int q, unsigned int r){
    /* creating copies of two sub arrays: */
    unsigned int n1, n2;
    n1 = q-l;
    n2 = r-q;
    unsigned char left_arr[n1];
    for (int i = 0; i < n1; ++i)
        left_arr[i] = array[i+l];
    unsigned char right_arr[n2];
    for (int i = 0; i < n2; ++i)
        right_arr[i] = array[i+q];

    /* merging left_arr and right_arr to array: */
    unsigned int l_i = 0, r_i = 0, i = l;
    while(l_i < n1 && r_i < n2)
    {
        if (left_arr[l_i] > right_arr[r_i]){
            array[i] = right_arr[r_i];
            r_i++;
        }
        else{
            array[i] = left_arr[l_i];
            l_i++;
        }
        i++;
    }

    while (l_i < n1){
        array[i] = left_arr[l_i];
        l_i++;
        i++;
    }
    
    while (r_i < n2){
        array[i] = right_arr[r_i];
        r_i++;
        i++;
    }
}

void mergeSort(unsigned char* array,unsigned int l,unsigned int r){
    if (r-l < 2)
        return;
    unsigned int q = (l+r)/2;
    mergeSort(array,l,q);
    mergeSort(array, q, r);
    merge(array,l,q,r);
    //print_array(array, size);
}

void sort_array(unsigned char* array, unsigned int length){
    mergeSort(array,0,length);
}
