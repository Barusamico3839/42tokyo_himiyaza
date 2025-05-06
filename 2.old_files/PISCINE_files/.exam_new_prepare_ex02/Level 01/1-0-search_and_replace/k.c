#include<unistd.h>

int main(int argc,char **argv)
{
	int str_len =0;
	int i =0;

	if(!(argc==4 || argv[2][1]==0 || argv[3][1]==0)
		|| ('0'<= argv[2][1]&& argv[2][1]<='9')|| ('0'<= argv[3][1]&& argv[3][1]<='9'))
	{
		write(1,"\n",1);
		return(0);
	}
	while(argv[1][str_len]!=0)
		str_len++;
	while(i<str_len)
	{
		if(argv[1][i]==argv[2][0])
		{
			argv[1][i]=argv[3][0];
		}
		write(1,&argv[1][i],1);
		i++;
	}
	write(1,"\n",1);
	return(0);
}
