// João Guilherme Alves

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tot_student = 2;
#define tot_lesson 36
#define tot_grades 3
#define tot_class 3
// At the beginning, I defined some values to be used throughout the code

struct Student {
  int registration;
  char name[50];
  double grade[tot_grades];
  int absences;
  int class;
};
// Here I constructed a structure Student with registration, name, grade, absences, and class.

void sort_by_registration(struct Student students[tot_student], int num_students) {
  int i, j;
  struct Student temp;

  for (i = 0; i < num_students - 1; i++) {
    int min = i;
    for (j = i + 1; j < num_students; j++) {
      if (students[j].registration < students[min].registration) {
        min = j;
      }
    }
    if (min != i) {
      // swap students' positions
      temp = students[i];
      students[i] = students[min];
      students[min] = temp;
    }
  }
}
// The first function performed was to sort the students by registration. In which
// the students are presented from the lowest registration to the highest.

void register_students(struct Student students[tot_student]) {
  int i, j, q, r;

  for (i = 0; i < tot_student; i++) {
    printf("\nEnter the registration of student %d: ", i + 1);
    scanf("%d", &students[i].registration);

    printf("Enter the name of student %d: ", i + 1);
    scanf("%49s", students[i].name);

    for (j = 0; j < tot_grades; j++) {
      printf("Enter grade %d of student %d: ", j + 1, i + 1);
      scanf("%lf", &students[i].grade[j]);
    }

    printf("Enter the absences of student %d: ", i + 1);
    scanf("%d", &students[i].absences);

    printf("Enter the class of student %d: ", i + 1);
    scanf("%d", &students[i].class);
  }

  for (q = 0; q < tot_student; q++) {
    for (r = q + 1; r < tot_student; r++) {
      if (students[q].registration == students[r].registration) {
        printf("\nERROR: EQUAL REGISTRATIONS OF STUDENTS %d and %d\nPlease, "
               "register again\n",
               q + 1, r + 1);

        return;
      }
    }
  }
}
// This function is responsible for storing the data of the students (registration, name,
// grades, absences, and class). Besides informing if the students' registrations are equal.

void update_data(struct Student students[tot_student]) {
  int i, j;
  double average[tot_student];

  for (int i = 0; i < tot_student; i++) {
    for (j = 0; j < tot_grades; j++) {
      printf("Enter the grade of student %d: ", i + 1);
      scanf("%lf", &students[i].grade[j]);
    }

    printf("Enter the absences of student %d: ", i + 1);

    scanf("%d", &students[i].absences);

    printf("Enter the class of student %d: ", i + 1);
    scanf("%d", &students[i].class);
    printf("\n");
  }
}
// In this function, the user updates the grades, absences, and class of each student,
// that is, the grades, absences, and class before this function will be replaced by new ones.
// However, it is important to notice that registrations cannot be updated, considering that it is unique for each student.

void failed_due_to_absence(struct Student students[tot_student]) {
  int i;

  for (i = 0; i < tot_student; i++) {
    if (students[i].absences >= 22) {
      printf(
          "Student %d\nRegistration: %d\nAttendance: %d%\nClass: %d\nFAILED\n\n",
          i + 1, students[i].registration,
          ((tot_lesson - students[i].absences) * 100) / tot_lesson, students[i].class);
    }
  }
}
// This function prints which students failed due to absence only.
// Considering that the student's attendance must be greater than 60%. However,
// 60% of 36 is 21.6 and it is not possible for the student to be absent half a day, so
// I put 22 as the minimum number of absences for the student to fail

void failed_due_to_grade(struct Student students[tot_student]) {
  int i, h;
  double result, average;

  for (h = 0; h < tot_student; h++) {
    result = 0;
    for (i = 0; i < tot_grades; i++) {
      result = result + students[h].grade[i];
    }
    average = result / tot_grades;
    if (average < 7) {
      printf("Student %d\nRegistration: %d\nAverage: %.2lf\nClass: %d\nFAILED\n\n",
             h + 1, students[h].registration, average, students[h].class);
    }
  }
}
// In this function, the average of each student is calculated and so it is printed
// which ones failed due to the average. Considering that the average is 7

void passed(struct Student students[tot_student]) {

  int i, h;
  double result, average;

  for (h = 0; h < tot_student; h++) {
    result = 0;
    for (i = 0; i < tot_grades; i++) {
      result = result + students[h].grade[i];
    }
    average = result / tot_grades;
    if (students[h].absences <= 21 && average >= 7) {
      printf("\nStudent %d\nRegistration: %d\nAverage: %.2lf\nAttendance: "
             "%d%\nPASSED\n\n",
             h + 1, students[h].registration, average,
             ((tot_lesson - students[h].absences) * 100) / tot_lesson);
    }
  }
}
// This function shows which students passed

void all_students(struct Student students[tot_student]) {
  int r, i;
  double result, average;

  for (r = 0; r < tot_student; r++) {
    result = 0;

    for (i = 0; i < tot_grades; i++) {
      result = result + students[r].grade[i];
    }

    average = result / tot_grades;

    printf("Student %d\nName: %s\nRegistration: %d\nAverage: %.2lf\nAttendance: "
           "%d%\nClass: %d\n\n",
           r + 1, students[r].name, students[r].registration, average,
           ((36 - students[r].absences) * 100) / 36, students[r].class);
  }
}
// This function shows all students with their respective registrations, averages,
// attendance, and classes

void classes(struct Student students[tot_student]) {
  int i, r, q, n;
  double result, average;
  for (r = 0; r < tot_student; r++) {
    result = 0;
    for (i = 0; i < tot_grades; i++) {
      result = result + students[r].grade[i];
    }
    average = result / tot_grades;
  }

  for (q = 1; q <= tot_class; q++) {
    for (n = 0; n < tot_student; n++) {
      if (students[n].class == q) {
        printf("Class %d\n", q);
        printf("Name: %s\nRegistration: %d\nAverage: %.2lf\n\n", students[n].name,
               students[n].registration, average);
      }
    }
  }
}
// This function shows the existing classes and the students that are part of it.

void remove_student(struct Student students[tot_student]) {
  int position = -1;
  int num_students = tot_student;
  int registration;
  printf("Enter the registration you want to delete: ");
  scanf("%d", &registration);

  for (int i = 0; i < tot_student; i++) {
    if (students[i].registration == registration) {
      position = i;
      break;
    }
  }
  if (position != -1) {
    // Removes the student from the found position
    for (int i = position; i < tot_student - 1; i++) {
      students[i].registration = students[i + 1].registration;
      strcpy(students[i].name, students[i + 1].name);
      for (int j = 0; j < tot_grades; j++) {
        students[i].grade[j] = students[i + 1].grade[j];
      }
      students[i].absences = students[i + 1].absences;
      students[i].class = students[i + 1].class;
    }

    // Adjusts the total number of students
    tot_student--;
  }
}
// This function removes a student that was registered in the system

void save_data(struct Student students[tot_student]) {
  FILE *file;
  // pointer
  int r, i;
  double result, average;
  file = fopen("students.txt", "w");
  // create file
  if (file == NULL) {
    printf("Error creating the file!\n");
    return;
  } else {
    for (r = 0; r < tot_student; r++) {
      result = 0;

      for (i = 0; i < tot_grades; i++) {
        result = result + students[r].grade[i];
      }

      average = result / tot_grades;

      fprintf(file,
              "Student %d\nName: %s\nRegistration: %d\nAverage: %.2lf\nAttendance: %d\nClass: %d\n\n",
              r + 1, students[r].name, students[r].registration, average,
              ((36 - students[r].absences) * 100) / 36, students[r].class);
    }
  }
  fclose(file);
  printf("\nStudent saved successfully");
}
// This function is responsible for saving the students' data in the file
// students.txt

void exit_program() { printf("Goodbye"); }
// When selected, this function will cause the code to end

int main(void) {

  struct Student students[tot_student];
  int continue_option = 1;

  do {
    printf("\n\tMENU\n\n");
    printf("1. Register students\n");
    printf("2. Update Students' Data\n");
    printf("3. Failed due to Absence\n");
    printf("4. Failed due to Average\n");
    printf("5. Passed\n");
    printf("6. All Students\n");
    printf("7. Classes\n");
    printf("8. Remove Student\n");
    printf("0. Exit\n");
    // this printf sequence will be how the menu will be seen

    scanf("%d", &continue_option);
    system("cls || clear");
    // this scanf in continue_option serves so that the person can select the menu option
    // and the system serves to "clean up" after being typed

    switch (continue_option) {
    case 1:

      register_students(students);
      sort_by_registration(students, tot_student);
      save_data(students);
      break;

    case 2:

      update_data(students);
      save_data(students);
      break;

    case 3:

      failed_due_to_absence(students);
      break;

    case 4:

      failed_due_to_grade(students);
      break;

    case 5:

      passed(students);
      break;

    case 6:

      all_students(students);
      break;

    case 7:

      classes(students);
      break;

    case 8:

      remove_student(students);
      break;

    case 0:

      exit_program();
      break;

    default:
      printf("Enter a valid option\n");
    }
  } while (continue_option);
  // The switch case is responsible for forwarding the selected number in the menu to
  // some function. In addition to having a default that appears when there is no
  // valid option for the chosen number

  return 0;
}
