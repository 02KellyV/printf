#include <stdio.h>
void say_hello (void)
{
	printf("Hello\n");
}

int sum(int a, int b)
{
	return (a + b);
}

struct student_college_detail
{
	void (*a) (void);
	int (*b) (int, int);
};

struct student_detail
{
	char c;
	// structure within structure
	struct student_college_detail clg_data;
}stu_data;

int main() 
{
	int i = 0;
	struct student_detail stu_data [2] = { 
		{'a', say_hello},
		{'b', sum}
	};

	printf(" character is: %c \n", stu_data[0].c);
	stu_data[0].clg_data.a();
	i = stu_data[1].clg_data.b(20, 10);
	printf("Sum is : %d", i);
	/**
	  printf(" College Name is: %s \n", 
	  stu_data[0].clg_data.college_name);
	 */
	return 0;
}

