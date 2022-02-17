//int
int push(int a[],int *t, int e,int n){
	if(*t <n){
		*t=*t+1;
		a[*t]=e;
		return 1;
	}
	else{
		printf("overflow");
		return 0;
	}
}

//char
int pushc(char a[],int *t, char e,int n){
	if(*t <n){
		*t=*t+1;
		a[*t]=e;
		return 1;
	}
	else if(*t==n || *t>n){
		printf("overflow");
		return 0;
	}
}

//int
int pop(int a[],int *t){
	if(*t == 0){
		printf("underflowed");
		return 0;
	}
	else{
		*t=*t-1;
		return a[*t+1];
	}
}

//char
char popc(char a[],int *t){
	if(*t == 0){
		printf("underflowed");
		return '0';
	}
	else{
		*t=*t-1;
		return a[*t+1];
	}
}

//int
int peep(int a[],int *t, int i){ 			////with reference to TOP
	if((*t-i+1) == 0){
		printf("Element underflowed");
		return '0';
	}

	else
		return a[*t-i+1];
}

//char
char peepc(char a[],int *t, int i){ 			////with reference to TOP
	if((*t-i+1) == 0){
		printf("Element underflowed");
		return 0;
	}

	else
		return a[*t-i+1];
}

//int
int change(int a[],int *t, int i,int x){		//// With refference to TOP
	if((*t-i+1) == 0){
		printf("Element  underflowed");
		return 0;
	}

	else{
		a[*t-i+1]=x;
		return a[*t-i+1];
	}
}

//char
char changec(char a[],int *t, int i,char x){		//// With refference to TOP
	if((*t-i+1) == 0){
		printf("\nElement  underflowed\n");
		return 0;
	}

	else{
		a[*t-i+1]=x;
		return a[*t-i+1];
	}
}

//int
void display(int a[],int lim){
	for(int i=lim;i>=1;i--){
		printf("%d\t",a[i]);	
	}
}

//char
void displayc(char a[],int lim){
	for(int i=lim;i>=1;i--){
		printf("%c\t",a[i]);	
	}
}
