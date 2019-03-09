## 1073 Scientific Notation （20 分）

Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]`.`[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.

Now given a real number *A* in scientific notation, you are supposed to print *A* in the conventional notation while keeping all the significant figures.

### Input Specification:

Each input contains one test case. For each case, there is one line containing the real number *A* in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.

### Output Specification:

For each test case, print in one line the input number *A* in the conventional notation, with all the significant figures kept, including trailing zeros.

### Sample Input 1:

```in
+1.23400E-03
```

### Sample Output 1:

```out
0.00123400
```

### Sample Input 2:

```in
-1.2E+10
```

### Sample Output 2:

```out
-12000000000
```

### Code

```c++
#include <cstdio>
#include <cstring>
int main () {
	char str[10010] ;
	scanf ("%s", str) ;
	int len=strlen(str) ;
	if (str[0] == '-') printf ("-") ;   //若是负数先输出负号 
	int pos=0, exp=0 ;					//pos记录E的位置 exp记录次方数 
	while (str[pos]!='E') {
		pos ++ ;
	}
	for (int i=pos+2; i<len; i++) {		//算出exp 
		exp = exp * 10+(str[i]-'0');
	}
	if (exp==0) {						//exp为0 则直接输出第1位到第pos-1位的字符 
		for (int i=1; i<pos; i++) {
			printf ("%c", str[i]) ;
		}
	}
	if (str[pos+1]=='-') {				//E后面一位是'-'负号 
		printf ("0.") ;					//先输出0. 以及exp-1个0 再把前面的所有数字输出 
		for (int i=0; i<exp-1; i++) {
			printf ("0") ;
		}
		printf ("%c", str[1]) ;
		for (int i=3; i<pos; i++) {
			printf ("%c", str[i]) ;	
		}
	} else {							//E后面一位是'+'正号 
		for (int i=1; i<pos; i++) {		//小数点是向右移动 
			if (str[i]=='.') continue ; //遇到'.'直接跳过 
			printf ("%c", str[i]) ;		//输出字符 
			if (i==exp+2 && (pos-3)!=exp) {
				printf (".") ;			//小数点移动到exp+2位上 要求此时该位置不是最后一位 
			}
		}
		for (int i=0; i<exp-(pos-3); i++) {
			printf ("0") ;
		}
	}
	return 0 ;
}
```

