#include<stdio.h>
void prn(int[][4]);
int main(){
	char name1[50],name2[50];
	int a=79,b=88,g=0,c=0,i,j,check,i1,j1;
	int arr[4][4];
	printf("Enter the name of players:\n");
	gets(name1);
	gets(name2);
	printf("Press 5 5 to undo. Undo upto one step is only allowed!\n");
	printf("The game starts!\n");
	for(i=1;i<=3;i++)
	for(j=1;j<=3;j++)
		arr[i][j]='.';
	while(g==0){
		c++;
		here:
		prn(arr);
		if(c%2==1)
		printf("Player 1, your turn\n");
		else
		printf("Player 2, your turn\n");
		scanf("%d%d",&i,&j);
		if(i==5 && j==5){
			c--;
			arr[i1][j1]='.';
			goto here;
		}
		i1=i,j1=j;
		if(arr[i][j]=='.'){
		if(c%2==1)
		arr[i][j]=a;
		else
		arr[i][j]=b;
	}
		else
		goto here;
		for(i=1;i<=3;i++){
			check=0;
			for(j=1;j<=3;j++){
				check+=arr[i][j];
			}
			if(check==3*a || check==3*b)
			goto hereee;
			check=0;
			for(j=1;j<=3;j++){
				check+=arr[j][i];
			}
			if(check==3*a || check==3*b) 
			goto hereee;
		}
		check=arr[1][1]+arr[2][2]+arr[3][3];
		if(check==3*a || check== 3*b)
		goto hereee;					
		check=arr[1][3]+arr[2][2]+arr[3][1];
		if(check==3*a || check== 3*b)
		goto hereee;
	if(c==9){  
		prn(arr);
	printf("It is a draw!");
	goto there;					
	}
}
hereee:
	if(c%2==1){
		prn(arr);		
	printf("%s you won!",name1);
}
	else{
		prn(arr);
	printf("%s you won!",name2);
}
	there:
	printf("\n You both played well!");
}
void prn(int prr[][4]){
	int i,j;
		printf("\n\n");
		for(i=1;i<=3;i++){
			printf("\t\t");
		for(j=1;j<=3;j++)
			printf("%c\t",prr[i][j]);
		printf("\n\n");
	}	
}
