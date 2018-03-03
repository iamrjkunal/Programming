#!/usr/bin/gawk
BEGIN{
com_count=0
str_temp=0
str_count=0
flag=0
RS="[/][/]|[/][*]|\42"
}

{
if(RT=="//")
{
com_count++
RS="\n"
flag=1
}
else if(RT=="/*")
{
com_count++
RS="[*][/]|\n"
}
else if(RT=="\42")
{
	if(str_temp==0)
	{ str_count++
	  str_temp=1
	  RS="\42"
	}
	else
	{ str_temp=0
	  RS="[/][/]|[/][*]|\42"
	}
	
}
else if(RT=="*/")
{
RS="[/][/]|[/][*]|\42"
}
else if(RT=="\n")
{
	if(flag==1)
	{
	RS="[/][/]|[/][*]|\42"
	flag=0
	}
	else 
	{
	com_count++
	}

}


}

END{

print str_count" "com_count
}
