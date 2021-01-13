#include <stdio.h>
// #include <conio.h>
#include <curses.h>
// #include <process.h>
#include <stdlib.h>

// student structure { subjects include Physics, maths, english, comp science}
struct sttudent {
  int regNumber;
  char name[50];
  int p_marks, c_marks, m_marks, e_marks, cs_marks;
  float per;
  char grade;
  int std;

} stdnt;

FILE *fptr;

void write_stdntudent() {
  fptr = fopen("student.dat", "ab");
  printf("\nPlease Enter The New Details of stdntudent \n");
  printf("\nEnter The roll number of stdntudent ");
  scanf("%d", &stdnt.regNumber);
  fflush(stdin);
  printf("\n\nEnter The Name of stdntudent ");
  gets(stdnt.name);
  printf("\nEnter The marks in physics out of 100 : ");
  scanf("%d", &stdnt.p_marks);
  printf("\nEnter The marks in chemistdntry out of 100 : ");
  scanf("%d", &stdnt.c_marks);
  printf("\nEnter The marks in maths out of 100 : ");
  scanf("%d", &stdnt.m_marks);
  printf("\nEnter The marks in english out of 100 : ");
  scanf("%d", &stdnt.e_marks);
  printf("\nEnter The marks in computer science out of 100 : ");
  scanf("%d", &stdnt.cs_marks);
  stdnt.per = (stdnt.p_marks + stdnt.c_marks + stdnt.m_marks + stdnt.e_marks +
               stdnt.cs_marks) /
              5.0;
  if (stdnt.per >= 60)
    stdnt.grade = 'A';
  else if (stdnt.per >= 50 && stdnt.per < 60)
    stdnt.grade = 'B';
  else if (stdnt.per >= 33 && stdnt.per < 50)
    stdnt.grade = 'C';
  else
    stdnt.grade = 'F';
  fwrite(&stdnt, sizeof(stdnt), 1, fptr);
  fclose(fptr);
  printf("\n\nstdntudent Record Has Been Created ");
  getch();
}