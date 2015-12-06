/*
*Problem Statement
*
*   You have a certain amount of money to give out as a bonus to employees. The trouble is, who do you pick to receive what bonus?
*   You decide to assign a number of points to each employee, which corresponds to how much they helped the company in the last year. 
*   You are given an int[] points, where each element contains the points earned by the corresponding employee (i.e. points[0] is the number of points awarded to employee 0). 
*   Using this, you are to calculate the bonuses as follows:
*     - First, add up all the points, this is the pool of total points awarded.
*     - Each employee gets a percentage of the bonus money, equal to the percentage of the point pool that the employee got.
*     - Employees can only receive whole percentage amounts, so if an employee's cut of the bonus has a fractional percentage, truncate it. 
*     - There may be some percentage of bonus left over (because of the fractional truncation). If n% of the bonus is left over, give the top n employees 1% of the bonus.
*         There will be no more bonus left after this. If two or more employees with the same number of points qualify for this "extra" bonus, but not enough bonus is left to give them all an extra 1%, give it to the employees that come first in points.
*
*   The return value should be a int[], one element per employee in the order they were passed in. 
*   Each element should be the percent of the bonus that the employee gets.
*
*Definition
*
*   Class:      Bonuses
*   Method:     getDivision
*   Parameters: int[]
*   Returns:    int[]
*   Method signature: int[] getDivision(int[] points)
*   (be sure your method is public)
*
*
*Limits
*
*   Time limit (s): 2.000
*   Memory limit (MB): 64
*
*Constraints
*   - points will have between 1 and 50 elements, inclusive.
*   -Each element of points will be between 1 and 500, inclusive.
*/


import java.util.Comparator;
import java.util.*;

public class Bonuses{
  public int[] getDivision(int[] points){
		int totalPoints = 0;    
		for(int num: points)
	    	totalPoints += num;
    
		int[] bonuses = new int[points.length];
		PriorityQueue<Tuple> maxHeap = new PriorityQueue<Tuple>(points.length, new MyComparator());

   		int pLeft = 100;
   		for(int i=0; i < points.length; i++){
     		bonuses[i] = (points[i] * 100) / totalPoints;
     		maxHeap.add(new Tuple(bonuses[i],i));
     		pLeft -= bonuses[i];    		
     	}   

  		 /*Start of adding the extra bit of % to the top employees */
   		while(pLeft > 0){
     		++bonuses[maxHeap.poll().val2];
	       	--pLeft;
       	}  	
   		return bonuses;
 	}
	
	public class Tuple{
		public int val1;
		public int val2;
		public Tuple(int a, int b){
			this.val1 = a;
			this.val2 = b;
		}
	}
	
	public class MyComparator implements Comparator<Tuple>
	{
    	public int compare( Tuple x, Tuple y )
	    {
    	    if(x.val1 != y.val1)
	    	    return y.val1 - x.val1;
	    	return  x.val2 - y.val2;
	    }
	}
}
