declblock{
	int i , temp , sum ,  j , a ,b,n,m,count;
	int ar[100000] ,k;	
}

codeblock{
	read n;
	read k;
	for i=1,n
	{
		read ar[i];
	}
	count=0;
	for i=1,n
	{
		m = i+1;
		for j=m,n
		{
			sum = ar[i] + ar[j];
			if(sum==k)
			{
				count = count + 1;
			}
		}
	}
	println "Count = " , count;
}