declblock{
	int x0,yar;
	int zarray[102],tarrya;
	int sum;
}

codeblock{
	x0=6;
	sum=0;
	yar=7+x0-8*78;
	if(x0>7)
	{
		yar = 9+x0;
	}
	else
	{
		yar = 8+x0;
	}
	if(x0>=10)
	{
		yar = 9+x0;
	}
	x0=5;
	while(x0<=10)
	{
		sum = sum + yar;
		x0 = x0+1;
	}
	x0 = sum;
}