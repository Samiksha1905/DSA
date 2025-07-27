#include<stdio.h>
#include<stdlib.h>
struct Student{
    int roll;
    char name[20];
    float marks;
};
void createFile(){
    FILE *fp=fopen("Student.txt","w");
    struct Student s;
    char ch;
    do{
        printf("Enter Roll,Name,Marks: ");
        scanf("%d %s %f",&s.roll,s.name,&s.marks);
        fwrite(&s,sizeof(s),1,fp);
        printf("Add another?(y/n): ");
        scanf("%c",&ch);
    }
    while(ch=='y' || ch=='Y');
    fclose(fp);
}
void displayFile(){
    FILE *fp=fopen("Student.txt","r");
    struct Student s;
    printf("\nRoll\tName\tMarks\n");
    while(fread(&s,sizeof(s),1,fp))
    printf("%d\t%s\t%.2f\n",s.roll,s.name,s.marks);
    fclose(fp);
}
void searchFile(){
    FILE *fp=fopen("Student.txt","r");
    struct Student s;
    int r,found=0;
    printf("Enter roll to search: ");
    scanf("%d",&r);
    while(fread(&s,sizeof(s),1,fp)){
        if(s.roll==r){
            printf("Found:%d %s %.2f\n",s.roll,s.name,s.marks);
            found=1;
            break;
        }
    }
    if(!found)
    printf("Record not found.\n");
    fclose(fp);
}
void appendFile(){
    FILE *fp=fopen("Student.txt","a");
    struct Student s;
    printf("Enter Roll,Name,Marks: ");
    scanf("%d %s %f",&s.roll,s.name,&s.marks);
    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);
    printf("Record added.\n");
}
int main(){
    int choice;
    do{
        printf("\n1.Create 2.Display 3.Search 4.Append 5.Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            createFile();
            break;

            case 2:
            displayFile();
            break;

            case 3:
            searchFile();
            break;

            case 4:
            appendFile();
            break;
        }
    }
    while(choice!=5);
    return 0;
}