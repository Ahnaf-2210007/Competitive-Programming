//Kadane's Algorithm
ll maxSubArraySum() {

	ll sum = 0;
	ll maxSum = LLONG_MIN;
	for(int i=0; i<n; i++) {
		sum += a[i];
		maxSum = max(maxSum, sum);
		if(sum<0) {
			sum = 0;
		}
	}
	return maxSum;
}
