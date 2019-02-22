//由于分数的乘法和除法的过程中可能使分子或分母超过int型表示范围，因此一般情况下，分子和分母应当使用long long型来存储
struct Fraction {		//分数
	long long up, down;		//分子、分母
}

//分数的化简主要用来使Fraction变量满足分数表示的三项规定
Fraction reduction(Fraction result) {
	if(result.down < 0) {		//分母为负数，令分子和分母都变为相反数
		result.up = -result.up;
		result.down = -result.down;
	}
	if(result.up == 0) {		//如果分子为0
		result.down = 1;		//令分母为1
	}
	else {						//如果分子不为0，进行约分
		int d = gcd(abs(result.up), abs(result.down));		//分子分母的最大公约数
		result.up /= d;			//约去最大公约数
		result.down /= d;
	}
	return result;
}

//分数除法，除数不为0，故注意特判

//分数的输出根据题目的要求进行，大体注意以下几点
//输出分数前，需要先对其进行化简
//如果分数r的分母down为1，说明该分数是整数，一般说来题目会有要求直接输出分子，而省略分母的输出
//如果分数r的分子up的绝对值大于分母down，说明该分数是假分数，此时应按带分数的形式输出，即整数部分为r.up / r.down
//分子部分为abs(r.up) % r.down，分母部分为r.down
//以上均不满足时说明分数r是真分数，按原样输出

void showResult(Fraction r) {		//输出分数r
	r = reduction(r);	//化简
	if(r.down == 1) printf("%lld", r.up);		//整数
	else if(abs(r.up) > r.down) {		//假分数
		printf("%d %d/%d", r.up / r.down, abs(r.up) % r.down, r.down);
	}
	else {								//真分数
		printf("%d/%d", r.up, r.down);
	}
}
