struct student
{
    char name[100];
    int age;
    char usn[100];
    int sem;
    char branch[10];
};
int main()
{
    struct student s1;
    strcpy(s1.name, "likith sg");
    s1.age = 18;
    strcpy(s1.usn, "1RVU23CSE236");
    s1.sem = 1;
    strcpy(s1.branch, "SoCse");

    printf("name:%s\n",s1.name);
    printf("age:%d\n",s1.age);
    printf("usn:%s\n",s1.usn);
    printf("sem:%d\n",s1.sem);
    printf("branch:%s\n",s1.branch);

    return 0;
}
