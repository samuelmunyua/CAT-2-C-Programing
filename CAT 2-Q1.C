/*
Name:Samuel Munyua Gicheru
Reg:CT100/G/26198/25
Description:2D array
*/

#include <stdio.h>
int main(){
	int i,j;
 //declare and initialize
 int scores ['2']['4']={
 {65,92,35,70},
 {84,72,59,67},
 	
 };
 //print values
 for(i=0;i<2;i++){
 for(j=0;j<4;j++){
 	printf("%d/n",scores[i] [j]);
 }}
 return 0;}