#PROBLEM LINK:

[Practice][111]

[Contest][222]

#DIFFICULTY:
EASY

#PREREQUISITES:
Matrix Exponentiation, Modular Multiplication

#PROBLEM SUMMARY:
Calculate the number of times **fibonacci(k)** is called in the recursive function given for fibonacci sequence. 

#EXPLANATION:
The solution is basically **![equation](http://bit.ly/1OalLtt) Fibonacci number** for **k>=1**.

The above can be proved by induction. 

**Proof By Induction** (we will prove here for $k \geq 1$)

For n=0, there are no value of $k$ possible, so the proposition is trivially true. 

For n=1, we can only pick k=1. It is true that fibonacci(1) appears one time i.e. $F_{1−1+1} = F_{1} = 1$

Now we assume that our proposition is valid for all numbers smaller than n, (strong induction) and we’ll prove it for n. Let $1 \leq k \leq n$. Let us draw the recursion tree for $F_{n}$, which we call $T_{n}$. If $k = n$, then clearly $F_{n}$ only shows up 1 time in $T_{n}$ i.e at the root of the recusion tree, so the result holds. Likewise, if $k = (n−1)$, the only place we see $F_{n−1}$ is as the root of our left subtree, the larger one. So the result holds in that case as well, since $F_{n−(n−1)+1} = F_{2} = 1$.

Let us then assume that $k \leq (n-2)$, which allows us to use the inductive hypothesis on the left and right subtrees of $T_{n}$.

By induction, the number of times $F_{k}$ appears in the left subtree is $F_{n−1−k+1} = F_{n−k}$, and the number of times it appears in the right subtree is $F_{n−2−k+1} = F_{n−k−1}$. Thus the number of times it appears in $T_{n}$ is the sum of values at both the sub-trees, i.e. $F_{n−k} \ + \ F_{n−k−1} = F_{n−k+1}$, which was to be shown.

Hence By Principle of mathematical induction the result holds all **n** and **$k \geq 1$**.

But for **k=0** the answer is **$(n-1)^{th}$ Fibonacci number**. The corner case of **k=0** can be seen from the recursion tree ${T}_{n}$ drawn showing that it occurs the same number of time as **k=2**. So the formula is **(n-2+1) = (n-1)** as stated above.



To find the *$n^{th}$* fibonacci number, we can use Modular exponentiation which gives a complexity of **O(log n)**.

But there is a more faster way to do this. You can refer to [Codeforces blog][333] for this. My solution uses the same concept but in a bit different and faster way.

Also, the test cases were weak as most of the solutions should have failed. As per the constraints, the modulo should be taken **m** where **1<=m<=$10^{12}$**. As *($10^{12}$. $10^{12}$)* will overflow in C++, Java etc. without using big integer libraries, we needed to use Modular multiplication. One way to do this is using the same concept as modular multiplication and replacing the multipplication operations by additions. Below is the C++ function to do the same.

	long long mulmod(long long a,long long b,long long c)
	{
	    long long x = 0,y=a%c;
	    while(b '>' 0)
	    {
	        if(b%2 == 1)
	        {
	            x = (x+y)%c;
	        }
	        y = (y*2)%c;
	        b /= 2;
	    }
	    return x%c;
	}

You can also use a O(1) hack for the above as given in [Praveen Dhinwa's blog][444].

#COMPLEXITY
O(${log}^2$n) or O(logn), depending on implementation of Modular multiplication function.


[111]: https://www.codechef.com/problems/COPR16A
[222]: https://www.codechef.com/COPR2016/problems/COPR16A
[333]: http://codeforces.com/blog/entry/14516
[444]: http://praveendhinwacoding.blogspot.in/2014/01/multiplication-of-two-long-numbers.html