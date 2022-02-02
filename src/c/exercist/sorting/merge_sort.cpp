/*
 * Created by gt on 2/2/22 - 3:36 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 *
 *
 * [16,21,11,8,12,22] -> Merge Sort
 *
 * Yukarıdaki dizinin sort türüne göre aşamalarını yazınız.
 * Big-O gösterimini yazınız.
 *
 *
 *
 *
 */

#include <stdio.h>

void merge(int a[],int low,int mid ,int high)
{
    int b[20]; //same size of a[]
    int i,j,k;
    i=low,j=mid+1,k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++]; //copying the elements
    }
    while (i<=mid)
        b[k++]=a[i++];
    while
            (j<=high) b[k++]=a[j++];
    for (k=low;k<=high;k++)
        a[k]=b[k];
}

// merge sort function
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low>=high)
        return;
    mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
}
