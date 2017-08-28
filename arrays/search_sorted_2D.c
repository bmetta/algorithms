#include <stdio.h>

// A divide and conquer method to search a given key in mat[]
// in rows from fromRow to toRow and columns from fromCol to
// toCol
void search(int mat[][4], int fromRow, int toRow, int fromCol, int toCol, int key, int index)
{
  printf("%*(%d %d) (%d %d)\n", 2*index, fromRow, toRow, fromCol, toCol);
  // Find middle and compare with middle 
  int i = fromRow + (toRow-fromRow )/2;
  int j = fromCol + (toCol-fromCol )/2;
  if (mat[i][j] == key) // If key is present at middle
    printf("Found at (%d %d)\n",  i, j);
  else
  {
    // right-up quarter of matrix is searched in all cases.
    // Provided it is different from current call
    if (i!=toRow || j!=fromCol)
      search(mat,fromRow,i,j,toCol,key, index+1);

    // Special case for iteration with 1*2 matrix
    // mat[i][j] and mat[i][j+1] are only two elements.
    // So just check second element
    if (fromRow == toRow && fromCol + 1 == toCol)
      if (mat[fromRow][toCol] == key)
        printf("Found at 2 (%d %d)\n", fromRow, toCol);

    // If middle key is lesser then search lower horizontal 
    // matrix and right hand side matrix
    if (mat[i][j] < key)
    {
      // search lower horizontal if such matrix exists
      if (i+1<=toRow)
        search(mat, i+1, toRow, fromCol, toCol, key, index+1);
    }

    // If middle key is greater then search left vertical 
    // matrix and right hand side matrix
    else
    {
      // search left vertical if such matrix exists
      if (j-1>=fromCol)
        search(mat, fromRow, toRow, fromCol, j-1, key, index+1);
    }
  }
}

int main()
{
  int mat[4][4] =  { {10, 20, 30, 40}, 
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};
//  int rowcount = 4,colCount=4,key=50;
//  for (int i=0; i<rowcount; i++)
//    for (int j=0; j<colCount; j++)
//    {
//      search(mat, 0, 3, 0, 3, mat[i][j], 1);
//      printf("**********************\n");
//    }
      search(mat, 0, 3, 0, 3, 40, 1);
}
