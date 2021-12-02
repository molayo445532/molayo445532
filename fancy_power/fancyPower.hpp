#ifndef FANCYPOWER_HPP
#define FANCYPOWER_HPP

int fancyPower(int n, int m)
{
	if(n%2==0){
return pow(m,2)*(n/2);
	}
	else if(n%2==1){
n=n-1;
return m*fancyPower(n,m);
	}
	else return 0;
}

#endif
