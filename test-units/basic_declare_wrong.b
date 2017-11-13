declblock{
	int x0,yar;
	int zarray[102],tarrya;
	int i,t;
	int sum,n;
}

codeblock{
	x0=6;
	yar=7+x0-8*78;
	zarray[6]=7;
	x0 = zarray[6] + 1;
	read zarray[5];
	print zarray[5];

	x0=5;
	read n;
	for i=1,n {
		read t;
		sum = sum  + t;
	}
	print "New Sum =" , sum ;
	if(x0==5)
		{
			println "haha1";
		}
	if(yar>10)
	{
		println "qw";
	}
	else
	{
		println "ty";
	}
	while(x0<10)
	{
		x0 = x0 + 2;
		println "why?";
	}
}