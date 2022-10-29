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
 * @file stats.h
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author Shahar Barr
 * @date 28.11.2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

void print_statistics(unsigned char* array, unsigned int length);

void print_array(unsigned char* array, unsigned int length);

unsigned char find_median(unsigned char* array, unsigned int length);

unsigned char find_mean(unsigned char* array, unsigned int length);

unsigned char find_maximum(unsigned char* array, unsigned int length);

unsigned char find_minimum(unsigned char* array, unsigned int length);

void sort_array(unsigned char* array, unsigned int length);

/**=====================    Helper functions     =========================================*/
/**
 * @brief merge sort algorithm
 *
 * Merge sort algorithm sorting an array by divide-and-conquer approach
 * The algorithm devied an array by two recursively and then merging
 * them via megre functoin.
 * Sorting the array from index 'l' to index 'r'
 *
 * @param array  a pointer to an unsorted array of type char
 * @param l          starting sorting index array of type unsigned int
 * @param r          final sorting index array of  type unsined int
 */

void mergeSort(unsigned char* array,unsigned int l,unsigned int r);

/**
 * @brief helper function to mergeSort, merging between two sorted array
 *
 * merge function receive three indexes (l,q,r) and an array
 * array is sorted between indexes (l,q) and indexes (q,r)
 * the function returns a sorted array between indexes (l,r)
 *
 * @param array : pointer to the initial position of the array
 * @param l          : index of the first sorted array
 * @param q          : index of the seconed sorted array
 * @param r          : index of the final second array position
 *
 */
void merge(unsigned char* array,unsigned int l, unsigned int q, unsigned int r);

#endif /* __STATS_H__ */
