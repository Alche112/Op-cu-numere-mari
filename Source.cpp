#include<stdio.h>
#include<string.h>
int adunare(char num1[], char num2[])
{
	int a[255], b[255], sum[255];
	int ac = 0, bc = 0, sc = 0;
	int reminder = 0, i;
	char *pa, *pb;
	

	pa = num1; //pointer to first number
	pb = num2; //pointer to second number

	//storing  first string number in the integer array
	while (*pa){  //loop while run untill it get null character
		a[ac++] = *pa++ - 48;  //48 is ASCII value of character zero
	}

	//storing  first string number in the integer array
	while (*pb){
		b[bc++] = *pb++ - 48;
	}

	//additin of two numbers
	if (ac<bc){
		for (i = ac; i > 0; i--){
			sum[sc++] = ((a[i - 1] + b[--bc]) + reminder) % 10;
			reminder = ((a[i - 1] + b[bc]) + reminder) / 10;
		}
		while (bc > 0){
			sum[sc++] = b[--bc] + reminder;
			reminder = 0;
		}
	}
	else{
		for (i = bc; i > 0; i--){
			sum[sc++] = ((b[i - 1] + a[--ac]) + reminder) % 10;
			reminder = ((b[i - 1] + a[ac]) + reminder) / 10;
		}
		if (ac == 0 && reminder == 1)
			sum[sc++] = reminder;
		while (ac > 0){
			sum[sc++] = a[--ac] + reminder;
			reminder = 0;
		}
	}
	printf("Adunarea : ");
	for (i = sc - 1; i >= 0; i--){
		printf("%d", sum[i]);
	}
	return 0;

}
char * multiply(char a[], char b[]){
	static char mul[1000];
	char c[1000];
	char temp[1000];
	int la, lb;
	int i, j, k = 0, x = 0, y;
	long int r = 0;
	long sum = 0;
	la = strlen(a) - 1;
	lb = strlen(b) - 1;

	for (i = 0; i <= la; i++){
		a[i] = a[i] - 48;
	}

	for (i = 0; i <= lb; i++){
		b[i] = b[i] - 48;
	}

	for (i = lb; i >= 0; i--){
		r = 0;
		for (j = la; j >= 0; j--){
			temp[k++] = (b[i] * a[j] + r) % 10;
			r = (b[i] * a[j] + r) / 10;
		}
		temp[k++] = r;
		x++;
		for (y = 0; y<x; y++){
			temp[k++] = 0;
		}
	}

	k = 0;
	r = 0;
	for (i = 0; i<la + lb + 2; i++){
		sum = 0;
		y = 0;
		for (j = 1; j <= lb + 1; j++){
			if (i <= la + j){
				sum = sum + temp[y + i];
			}
			y += j + la + 1;
		}
		c[k++] = (sum + r) % 10;
		r = (sum + r) / 10;
	}
	c[k] = r;
	j = 0;
	for (i = k - 1; i >= 0; i--){
		mul[j++] = c[i] + 48;
	}
	mul[j] = '\0';
	return mul;
}
int main()
{
	char num1[255], num2[255];
	char *c;

	printf("Enter first number : ");
	scanf("%s", &num1); //taking first number from user in string format
	printf("\nEnter second number : ");
	scanf("%s", &num2); //taking second number from user in string format
	adunare(num1, num2);
	printf("Inmultirea : ");
	c = multiply(num1, num2);
	printf("%s \n", c);
	return 0;
}
