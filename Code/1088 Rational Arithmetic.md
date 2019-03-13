## 1088 Rational Arithmetic （20 分)

For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.

### Input Specification:

Each input file contains one test case, which gives in one line the two rational numbers in the format `a1/b1 a2/b2`. The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.

### Output Specification:

For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is `number1 operator number2 = result`. Notice that all the rational numbers must be in their simplest form `k a/b`, where `k` is the integer part, and `a/b` is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output `Inf` as the result. It is guaranteed that all the output integers are in the range of **long int**.

### Sample Input 1:

```in
2/3 -4/2
```

### Sample Output 1:

```out
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
```

### Sample Input 2:

```in
5/3 0/6
```

### Sample Output 2:

```out
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
```

### Code

```c++
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;					//定义成long long型防止在分子分母相乘过程中超出int范围 
struct Fraction {
	ll up, down;
} a, b;								//a,b两个分数 
ll gcd (ll a, ll b) {					//最大公约数 
	return (b == 0) ? a : gcd (b, a % b);
}
Fraction reduction (Fraction result) {	//分数化简 
	if (result.down < 0) {
		result.up = -result.up;
		result.down = -result.down;
	}
	if (result.up == 0) {
		result.down = 1;
	} else {
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}
//加法 
Fraction add (Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down + f1.down * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}
//减法 
Fraction minu (Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down - f1.down * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
} 
//乘法 
Fraction multi (Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}
//除法 
Fraction divide (Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}
//结果按整数，假分数，真分数输出，且若是负数的话要加小括号括起来 
void showResult (Fraction r) {
	r = reduction (r);
	if (r.up < 0) printf ("(");
	if (r.down == 1) printf ("%lld", r.up);	//整数 
	else if (abs(r.up) > r.down) {			//假分数 
		printf ("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
	} else {
	printf ("%lld/%lld", r.up, r.down);	//真分数 
	}
	if (r.up < 0) printf (")");
}

int main () {
	scanf ("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	//加法 
	showResult (a);
	printf (" + ");
	showResult (b);
	printf (" = ");
	showResult (add(a, b));
	printf ("\n"); 
	//减法 
	showResult (a);
	printf (" - ");
	showResult (b);
	printf (" = ");
	showResult (minu(a, b)); 
	printf ("\n"); 
	//乘法 
	showResult (a);
	printf (" * ");
	showResult (b);
	printf (" = ");
	showResult (multi(a, b)); 
	printf ("\n"); 
	//除法 
	showResult (a);
	printf (" / ");
	showResult (b);
	printf (" = ");
	if (b.up == 0) {	//特判除以0 
		printf ("Inf");
	} else {
		showResult (divide(a, b));
	}
	return 0;
	
}


```

