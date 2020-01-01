#include <stdio.h>
#include <stdlib.h>
#define NUM_ROWS  10
#define NUM_COLS  10
typedef struct
{
    short int row;
    short int col;
    short int dir;

} element;

typedef struct
{
    short int vert;
    short int horiz;
} offsets;

static short int maze[NUM_ROWS][NUM_COLS];  /* bottom boundary */
static short int mark[NUM_ROWS][NUM_COLS];
int top,topB;
element stack[NUM_ROWS*NUM_COLS];     /* global stack declaration */
offsets move[5],moveB[5];   /* array of moves for each direction,in this case setting two rats direction.*/
void setmaze();
void move_dir();
void move_dirB();
void print_maze();
void stack_full();
void stack_empty();
void add(element);
void addB(element);
void print_record(int,int,int);
void path();


int main()
{
    setmaze();
    print_maze();
    move_dir();
    path();
    return 0;
}

void setmaze() /*Load the information from txt file and set the maze*/
{
    FILE *fp;
    int row=0,col=0;
    char temp[15];
    fp = fopen( "input.txt","r");

    if(fp == NULL) //Display error when no file is readed.
    {
        printf("Cannot oepn the file");
    }
    while (!feof(fp)) // while not(!) the bottom of the file, still perform loop.
    {

        for (col=0; col<10; col++)
        {
            fscanf( fp,"%s",&temp);
            for(row=0; row<10; row++)
            {
                maze[row][col]=temp[row]-'0'; /*use ASCII number code change the char to int*/
            }
        }
    }
    fclose(fp);  /*close the txt file*/
}

void print_maze()
{
    int i, j;
    printf("Maze with the boundaries is: \n\n");
    for(j = 0; j <NUM_COLS; j++)
    {
        for (i = 0; i <NUM_ROWS; i++)
            printf("%3d",maze[i][j]);
        printf("\n");
    }
}

void move_dir()
{/* initial the table for the next row and column moves */
    move[1].vert =  0;  move[1].horiz =  1;   /*  right */
    move[2].vert =  1;  move[2].horiz =  0;   /*  down */
    move[3].vert = -1;  move[3].horiz =  0;   /*  up */
    move[4].vert =  0;  move[4].horiz = -1;   /*  left */
}

void stack_full()
{
   printf("The stack is full.  No item added \n");
}

void stack_empty()
{
  printf("The stack is empty.  No item deleted \n");
}

void add(element item)
{ /* add an item to the global stack
     top (also global) is the current top of the stack,
     MAX_STACK_SIZE is the maximum size */

   if (top == NUM_ROWS*NUM_COLS)
     stack_full();
   else
      stack[++top] = item;
}

element delete()
{ /* remove top element from the stack and put it in item */
  if (top < 0)
    stack_empty();
  else
    return stack[top--];
}

void path()
{

    int i, row, col, next_row, next_col, dir, found = 0,n;
    element position;
    mark[1][1] = 1;
    /* place the starting position, maze[1][1] onto the stack
       starting direction is 2  */
    top = 0;
    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 1;
    n=1;
    while (top > -1 && !found)
    {
        /* remove position at top of stack, and determine if
        there is a path from this position */
        if(dir==5||n==1)
        {
            position = delete();
            row = position.row;
            col = position.col;
            dir = position.dir;
            printf("( %d , %d )\n",row,col);
        }

        while ( dir <=  4 && !found )
        {
            /* check all of the remaining directions from the current
            position */
            next_row = row + move[dir].horiz;
            next_col = col + move[dir].vert;


            if (next_row == NUM_ROWS-2 && next_col == NUM_COLS-2)
            {
                /* path has been found, exit loop and print it out */
                printf("( %d , %d )\n",next_row,next_col);
                found = 1;
            }

            else if ( !maze[next_row][next_col] &&  !mark[next_row][next_col])
            {
                /* current position has not been checked, place it
                on the stack and continue */
                mark[next_row][next_col] = 1;
                position.row = row;
                position.col = col;
                position.dir = ++dir;
                add(position);
                row = next_row;
                col = next_col;
                dir = 1;
                printf("( %d , %d )\n",row,col);
            }
            else
            {
                ++dir;
            }
            n++;
        }
    }
}
