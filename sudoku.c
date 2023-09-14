# include<stdio.h>
int sudoku[4][4];
void solvesudoku(int,int);
int checkrow(int row,int num)
{
int column;
for(column=0;column<4;column++)
    if(sudoku[row][column]==num)
        return 0 ;
return 1;
}
int checkcolumn(int column,int num)
{
int row;
for(row=0;row<4;row++)
    if(sudoku[row][column]==num)
        return 0;
return 1;
}
int checkgrid(int row,int column,int num)
{
row=(row/2)*2 ;
column=(column/2)*2;
int r,c;
for(r=0;r<2;r++)
    for(c=0;c<2;c++)
         if(sudoku[row+r][column+c]==num)
            return 0;
return 1;
}
void navigate(int row,int column)
{
if(column<3)
        solvesudoku(row,column+1);
    else
       solvesudoku(row+1,0);
}
void display()
{
int row,column;
printf("THE SOLVED SUDOKU \n");
for(row=0;row<4;row++)
{
for(column=0;column<4;column++)
printf("%d ",sudoku[row][column]);
printf("\n");
}
getch();
}
void solvesudoku(int row,int column)
{
    if(row>3)
    display();
    if(sudoku[row][column]!=0)
    navigate(row,column);
    else
    {
        int ctr;
        for(ctr=1;ctr<=4;ctr++)
        {
        if((checkrow(row,ctr)==1)&&(checkcolumn(column,ctr)==1)&&(checkgrid(row,column,ctr)==1))
        {
            sudoku[row][column]=ctr;
             navigate(row,column);
        }
        }
        sudoku[row][column]=0;
    }
}
int main()
{
int row,column;
printf("Enter the desired sudoku and enter 0 for unknown entries\n");
for(row=0;row<4;row++)
for(column=0;column<4;column++)
scanf("%d",&sudoku[row][column]);
solvesudoku(0,0);
}