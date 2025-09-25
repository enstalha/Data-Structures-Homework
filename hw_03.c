// HW 3- Calculate the time complexity


// 1 -> time complexity -> O(n)
int fun(int n){
	int count = 0;
	for(int i = n; i > 0; i /= 2){
		for(int j = 0; j < i; j++){
			count += 1;
		}	
	}
	return count;
}


// 2 -> time complexity -> O(N+M)
int a = 0, b = 0;
for(i = 0, i < N, i++){
	a = a + rand();
}
for(j = 0; j < M; j++){
	b = b + rand();
}


// 3 -> time complexity -> O(n*log^2(n))
for(int i = n; i > 0; i = i / 2){
	for(int j = 1; j < n; j * 2){
		for(int k = 0; k < n; k = k + 2){
			//some logic with complexity X
		}
	}
}


// 4 -> time complexity -> O(log(n))
for(int i = 0; i < n; i++){
	i *=k;
}


// 5 -> time complexity -> O(n*log(n))
int i, j, k = 0;
for(i = n / 2; i <= n; i++){
	for(j = 2; j <= n; j = j * 2){
		k = k + n / 2;
	}
}


// 6 -> time complexity -> O(log(n))
int a = 0, i = N;
while(i > 0){
	a += i;
	i /= 2;
}
