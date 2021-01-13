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
  printf("\nEnter The Reg Number of stdntudent ");
  scanf("%d", &stdnt.regNumber);
  fflush(stdin);
  printf("\n\nEnter The Name of student ");
  gets(stdnt.name);
  printf("\nEnter The marks in physics out of 100 : ");
  scanf("%d", &stdnt.p_marks);
  printf("\nEnter The marks in chemistry out of 100 : ");
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

void printInfo() {
  printf("\nReg Number of Student : %d", stdnt.regNumber);
  printf("\nName of student : %s", stdnt.name);
  printf("\nMarks in Physics : %d", stdnt.p_marks);
  printf("\nMarks in Chemistry : %d", stdnt.c_marks);
  printf("\nMarks in Maths : %d", stdnt.m_marks);
  printf("\nMarks in English : %d", stdnt.e_marks);
  printf("\nMarks in Computer Science : %d", stdnt.cs_marks);
  printf("\nPercentage of student is  : %.2f", stdnt.per);
  printf("\nGrade of student is : %c", stdnt.grade);
}

void display_all() {
  system("clear");
  printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
  fptr = fopen("student.dat", "rb");
  while ((fread(&stdnt, sizeof(stdnt), 1, fptr)) > 0) {
    printInfo();
    printf("\n\n====================================\n");
    getch();
  }
  fclose(fptr);
  getch();
}

void display_sp(int n) {
  int flag = 0;
  fptr = fopen("student.dat", "rb");
  while ((fread(&stdnt, sizeof(stdnt), 1, fptr)) > 0) {
    if (stdnt.regNumber == n) {
      system("clear");
      printInfo();
      flag = 1;
    }
  }
  fclose(fptr);
  if (flag == 0)
    printf("\n\nrecord not exist");
  getch();
}

void modify_student() {
  int no, found = 0;
  system("clear");
  printf("\n\n\tTo Modify ");
  printf("\n\n\tPlease Enter The Reg Number of student");
  scanf("%d", &no);
  fptr = fopen("student.dat", "rb+");
  while ((fread(&stdnt, sizeof(stdnt), 1, fptr)) > 0 && found == 0) {
    if (stdnt.regNumber == no) {
      printf("\nReg Number of student : %d", stdnt.regNumber);
      printf("\nName of student : %s", stdnt.name);
      printf("\nMarks in Physics : %d", stdnt.p_marks);
      printf("\nMarks in Chemistry : %d", stdnt.c_marks);
      printf("\nMarks in Maths : %d", stdnt.m_marks);
      printf("\nMarks in English : %d", stdnt.e_marks);
      printf("\nMarks in Computer Science : %d", stdnt.cs_marks);
      printf("\nPercentage of student is  : %.2f", stdnt.per);
      printf("\nGrade of student is : %c", stdnt.grade);
      printf("\nPlease Enter The New Details of student \n");
      printf("\nEnter The Reg Number of student ");
      scanf("%d", &stdnt.regNumber);
      fflush(stdin);
      printf("\n\nEnter The Name of student ");
      gets(stdnt.name);
      printf("\nEnter The marks in physics out of 100 : ");
      scanf("%d", &stdnt.p_marks);
      printf("\nEnter The marks in chemistry out of 100 : ");
      scanf("%d", &stdnt.c_marks);
      printf("\nEnter The marks in maths out of 100 : ");
      scanf("%d", &stdnt.m_marks);
      printf("\nEnter The marks in english out of 100 : ");
      scanf("%d", &stdnt.e_marks);
      printf("\nEnter The marks in computer science out of 100 : ");
      scanf("%d", &stdnt.cs_marks);
      stdnt.per = (stdnt.p_marks + stdnt.c_marks + stdnt.m_marks +
                   stdnt.e_marks + stdnt.cs_marks) /
                  5.0;
      if (stdnt.per >= 60)
        stdnt.grade = 'A';
      else if (stdnt.per >= 50 && stdnt.per < 60)
        stdnt.grade = 'B';
      else if (stdnt.per >= 33 && stdnt.per < 50)
        stdnt.grade = 'C';
      else
        stdnt.grade = 'F';
      fseek(fptr, -(long)sizeof(stdnt), 1);
      fwrite(&stdnt, sizeof(stdnt), 1, fptr);
      printf("\n\n\t Record Updated");
      found = 1;
    }
  }
  fclose(fptr);
  if (found == 0)
    printf("\n\n Record Not Found ");
  getch();
}

void delete_student() {
  int no;
  FILE *fptr2;
  system("clear");
  printf("\n\n\n\tDelete Record");
  printf("\n\nPlease Enter The roll number of student You Want To Delete");
  scanf("%d", &no);
  fptr = fopen("student.dat", "rb");

  fptr2 = fopen("Temp.dat", "wb");
  rewind(fptr);
  while ((fread(&stdnt, sizeof(stdnt), 1, fptr)) > 0) {
    if (stdnt.regNumber != no) {
      fwrite(&stdnt, sizeof(stdnt), 1, fptr2);
    }
  }
  fclose(fptr2);
  fclose(fptr);
  remove("student.dat");
  rename("Temp.dat", "student.dat");
  printf("\n\n\tRecord Deleted ..");
  getch();
}

void class_result() {
  system("clear");
  fptr = fopen("student.dat", "rb");
  if (fptr == NULL) {
    printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create "
           "File");
    printf("\n\n\n Program is closing ....");
    getch();
    exit(0);
  }

  printf("\n\n\t\tALL STUDENTS RESULT \n\n");
  printf("====================================================\n");
  printf("R.No.  Name       P   C   M   E   CS  %%age   Grade\n");
  printf("====================================================\n");

  while ((fread(&stdnt, sizeof(stdnt), 1, fptr)) > 0) {
    printf("%-6d %-10s %-3d %-3d %-3d %-3d %-3d %-3.2f  %-1c\n",
           stdnt.regNumber, stdnt.name, stdnt.p_marks, stdnt.c_marks,
           stdnt.m_marks, stdnt.e_marks, stdnt.cs_marks, stdnt.per,
           stdnt.grade);
  }
  fclose(fptr);
  getch();
}