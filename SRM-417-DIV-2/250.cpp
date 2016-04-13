class ReversedSum{
	public:
	int getReversedSum(int x, int y){
		return rev(rev(x) + rev(y));
	}
	
	int rev(int x){
		int r = 0;
		while(x > 0){
			int temp = x%10;
			x = x/10;
			
			r = r*10 + temp;
		}
		return r;
	}

};
