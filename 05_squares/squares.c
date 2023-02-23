#include <stdio.h>
#include <stdlib.h>


/* 
 * Determines if coord is in range between
 * offset (INCLUSIVE) and offset + size (EXCLUSIVE)
 */
int isInRange(int coord, int offset, int size) {
        if(coord >= offset && coord <offset+size){
                return 1;
        }

  // if coord is in range, return 1
  // else, return 0
  return 0;
}

/*
 * Determines if coord is at border of offset or
 * offset + size
 */
int isAtBorder(int coord, int offset, int size) {
        if(coord ==offset || coord == offset+size){
        return 1;
        }
        // if coord is equal to offest or offset + size
  // return 1, else return 0
  return 0;
}

int max(int one, int two){
        if(one >two){
                return one;
        }
        else{
                return two;
        }
}

void squares(int size1, int x_offset, int y_offset, int size2) {
    int w = max(size1, (x_offset+size2));
    int h = max (size1, (y_offset+size2));
    for (int y=0; y<h; y++){
        for(int x =0; x<w;x++){
            if((isInRange(x, x_offset, size2) && (y==y_offset || y == y_offset+size2 -1)) || (isInRange(y, y_offset, size2) && (x == x_offset || x == x_offset +size2 -1))){
                printf("*");
            }
            else if ((x<size1 && (y == 0 || y == size1-1)) || (y<size1 && (x == 0 || x ==size1-1))){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

      //if not,
      // check if EITHER
      //    x is less than size1 AND (y is either 0 or size1-1)
      // OR
      //    y is less than size1 AND (x is either 0 or size1-1)
      //if so, print a #

      //else print a space
    //when you finish counting x from 0 to w, 
    //print a newline

}

