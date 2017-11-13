declblock{
	int n,i,j,ar[100000];
	int temp;
	int m,k;
}

codeblock{
	read n;
	for i = 1 , n 
	{
		read ar[i];
	}
	m = n-1;
	for i = 1 , m 
	{
		k = n-i;
		for j = 1, k
		{
			if(ar[j] > ar[j+1]){
				temp = ar[j+1];
				ar[j+1] = ar[j];
				ar[j] = temp;
			}
		}
	}
	for i = 1 , n {
		print ar[i];
	}
	println " ";
}

