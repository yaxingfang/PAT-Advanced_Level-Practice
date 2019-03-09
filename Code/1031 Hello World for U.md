## 1031 Hello World for U （20 分）

Given any string of *N* (≥5) characters, you are asked to form the characters into the shape of `U`. For example, `helloworld` can be printed as:

```
h  d
e  l
l  r
lowo
```

That is, the characters must be printed in the original order, starting top-down from the left vertical line with *n*1 characters, then left to right along the bottom line with *n*2 characters, and finally bottom-up along the vertical line with *n*3 characters. And more, we would like `U` to be as squared as possible -- that is, it must be satisfied that *n*1=*n*3=*m**a**x* { *k* | *k*≤*n*2 for all 3≤*n*2≤*N* } with *n*1+*n*2+*n*3−2=*N*.

### Input Specification:

Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

### Output Specification:

For each test case, print the input string in the shape of U as specified in the description.

### Sample Input:

```in
helloworld!
```

### Sample Output:

```out
h   !
e   d
l   l
lowor
```

### Code

```c++
#include <cstdio>
#include <cstring>
int main() {
	char str[85] ;
	int n, side, mid ;
	while (scanf ("%s",str)!=EOF) {		//多组数据 
		n = strlen (str) ;
		side = (n+2) / 3;				//side指的是两边垂直的字母数 
		mid = n - side*2 ;				//mid指的是中间空的空格数 
		for (int i=0; i<side; i++) {
			if (i!=side-1) {			//不是最后一行 
				printf ("%c", str[i]) ;
				for (int j=0; j<mid; j++) {
					printf (" ") ;
				}
				printf ("%c\n", str[n-1-i]) ;	
			} else {					//最后一行 
				for (int i=side-1; i<side+mid+1; i++) {
					printf ("%c", str[i]) ;
				}
			}
		}
	}
	return 0 ;
}

```

