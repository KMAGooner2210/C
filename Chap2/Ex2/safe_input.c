#include <stdio.h>
#include <string.h>

void a_issue(){
     printf("--- PHAN A: LOI TROI LENH ---\n");
     int age;
     char blood_group;

     printf("Moi nhap tuoi: ");
     scanf("%d", &age);

     printf("Nhap nhom mau: A, B, O,...:  ");
     scanf("%c", &blood_group);
     printf("Tuoi: %d, Nhom mau:'%c'\n\n", age, blood_group);
}

void clear_stdin_buffer(){
     int c;
     while((c = getchar()) != '\n' && c != EOF){}
}

void b_fix(){
     printf("--- PHAN B: SUA LOI ---\n");
     int age;
     char blood_group;
      
     printf("Nhap tuoi: ");
     scanf("%d", &age);

     clear_stdin_buffer();
     printf("Nhap nhom mau: ");
     scanf("%c", &blood_group);
     
     printf("Tuoi: %d, Nhom mau: '%c'\n\n", age, blood_group);
}

void c_string_standard(){
    printf("--- PHAN C: DOC CHUOI DUNG ---\n");
    char name[20];
    
    printf("Nhap ho ten: ");
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Hello, [%s]!\n", name);
}
int main(){
    // a_issue();
    // b_fix();
    c_string_standard();
    return 0;
}


