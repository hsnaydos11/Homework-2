#include <string.h>
#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define n5 3
using namespace std;

int lis(int arr[], int n){
	int lis[n];
	lis[0] = 1; //base case
	for(int i = 1; i < n; i++){ //to calculate values that entered user 
		lis[i] = 1;
		for(int j = 0; j < 1; j++){ 
			if(arr[i] > arr[j] && lis[i] < lis[j] + 1){
				lis[i] = lis[j] + 1;
			}
		}
	}
	return *max_element(lis, lis+n); //to back maximum value
}
int findMin(int arr[], int n){
    int sum = 0; 
    for (int i = 0; i < n; i++) 
        sum += arr[i];
 
    // Create an array to store results of subproblems
    bool dp[n+1][sum+1];
 
    // Initialize first column as true. 0 sum is possible 
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
 
    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
 
    
    for (int i=1; i<=n; i++)  //loop post to fill the partition chart.
    {
        for (int j=1; j<=sum; j++)
        {
            dp[i][j] = dp[i-1][j]; //This part if the i element is not included.
 
            if (arr[i-1] <= j) //this part if the i element is included.
                dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    }

    int diff = INT_MAX; //to determine difference of two sums.
     
    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j=sum/2; j>=0; j--)
    {
        // Find the 
        if (dp[n][j] == true)
        {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}
int printCountRec(int dist){
	int count[dist+1];  //to determine base values.
	count[0]=1;
	if(dist>=1){  //this part if dist is equal 1
		count[1]=1;
	}
	if(dist>=2){ //this part if dist is equal 2
		count[2]=2;
	}
	for(int i=3; i<=dist; i++){  //to complete array in bottom up manner.
		count[i]=count[i-1]+count[i-2]+count[i-3];
	}
	return count[dist];  //to back the count[dist]
}
int findLongestFromACell(int i, int j, int mat[n5][n5], int dp[n5][n5]) { 
    if (i < 0 || i >= n5 || j < 0 || j >= n5) 
        return 0; 

    if (dp[i][j] != -1) 
        return dp[i][j]; 
   
    int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN; 
 
    if (j < n5 - 1 && ((mat[i][j] + 1) == mat[i][j + 1])) 
        x = 1 + findLongestFromACell(i, j + 1, mat, dp); 
  
    if (j > 0 && (mat[i][j] + 1 == mat[i][j - 1])) 
        y = 1 + findLongestFromACell(i, j - 1, mat, dp); 
  
    if (i > 0 && (mat[i][j] + 1 == mat[i - 1][j])) 
        z = 1 + findLongestFromACell(i - 1, j, mat, dp); 
  
    if (i < n5 - 1 && (mat[i][j] + 1 == mat[i + 1][j])) 
        w = 1 + findLongestFromACell(i + 1, j, mat, dp); 
 
    return dp[i][j] = max(x, max(y, max(z, max(w, 1)))); 
}  
int finLongestOverAll(int mat[n5][n5]) { 
    int result = 1; 
    int dp[n5][n5]; 
    memset(dp, -1, sizeof dp); 
  
    for (int i = 0; i < n5; i++) { 
        for (int j = 0; j < n5; j++) { 
            if (dp[i][j] == -1) 
                findLongestFromACell(i, j, mat, dp); 
            result = max(result, dp[i][j]); 
        } 
    } 
    return result; 
}
int Eggmax(int a, int b){
	return (a>b)? a : b;
}
int eggDrop(int n, int k){ //k is number of floors and n is number of Eggs
    int eggFloor[n + 1][k + 1]; 
    int res; 
    int i, j, x; 
    for (i = 1; i <= n; i++) { // it is a trying for eggs ,so trying number and floor number is equal 
        eggFloor[i][1] = 1; 
        eggFloor[i][0] = 0; 
    } 
    for (j = 1; j <= k; j++) //every time need to try one egg and j floors.
        eggFloor[1][j] = j; 

    for (i = 2; i <= n; i++) { //start from second egg and second floor to n eggs and n floors
        for (j = 2; j <= k; j++) { 
            eggFloor[i][j] = INT_MAX; //to assign max value
            for (x = 1; x <= j; x++) { 
                res = 1 + Eggmax(eggFloor[i - 1][x - 1], eggFloor[i][j - x]); 
                if (res < eggFloor[i][j]) //this part if result is smaller than eggfloor 
                    eggFloor[i][j] = res; 
            } 
        } 
    } 
    return eggFloor[n][k]; // eggFloor[n][k] holds the result 
}
int Optmax(int x, int y){ 
	if(x > y){
		return x;
	}else{
		return y;
	}
}
int Optmin(int x, int y){
	if(x < y){
		return x;
	}else{
		return y;
	}
}
int optimalStrategyOfGame(int* arr, int n) { 
    int table[n][n];  //to create table
    for (int gap = 0; gap < n; ++gap) { 
        for (int i = 0, j = gap; j < n; ++i, ++j) { 
            int x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
            int z = (i <= (j - 2)) ? table[i][j - 2] : 0; 
            table[i][j] = Optmax(arr[i] + Optmin(x, y), arr[j] + Optmin(y, z)); 
        } 
    } 
    return table[0][n - 1]; 
} 
int Kmax(int a, int b){  //to return maximum of two integers
	return (a > b) ? a : b;
}
int knapSack(int W, int wt[], int val[], int n){
	int i, w; //to determine row anc column.
	int K[n + 1][W + 1];
	for(i = 0; i <= n; i++){ //to create table of K[][] in bottam up manner
		for(w = 0; w <= W; w++){  //it start first column and row zero.
			if(i == 0 || w == 0){  //if i and w is equal zero k
				K[i][w] = 0;
			}else if(wt[i - 1] <= w){  //if w is smaller than wt, K is equal kmax value.
				K[i][w] = Kmax(val[i - 1] + K[i-1][w-wt[i-1]] , K[i - 1][w]);
			}else{
				K[i][w] = K[i - 1][w];
			}
		}
	}
	return K[n][W];
}
int smax(int a, int b) { //maximum of 2 integers
	return (a > b) ? a : b; 
}
int slcs(char* X, char* Y, int m, int n); //to returns lCS
int shortestSS(char* X, char* Y){
	int m = strlen(X), n = strlen (Y);
	int l = slcs(X, Y, m, n); //to find lcs
	return (m + n - l);  //Result is sum of input string lengths - length of lcs
}
int slcs(char* X, char* Y, int m, int n){
    int dp[m + 1][n + 1];
 	int i, j;
    // Fill table in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}else if(X[i - 1] == Y[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = smax(dp[i - 1][j], dp[i][j - 1]); 
			}
        }
    }
    return dp[m][n];
}
bool findPartiion(int arr[], int n){
    int sum = 0;
    int i, j;

    for (i = 0; i < n; i++) // Calculate sum of all elements
        sum += arr[i];
 
    if (sum % 2 != 0)
        return false;
 
    bool part[sum / 2 + 1][n + 1];
 
    for (i = 0; i <= n; i++) // initialize top row as true
        part[0][i] = true;
    for (i = 1; i <= sum / 2; i++) //except i rows and zero columns, start zero.
        part[i][0] = false;
    for (i = 1; i <= sum / 2; i++) { //
        for (j = 1; j <= n; j++) {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j]
                             || part[i - arr[j - 1]][j - 1];
        }
    }
    return part[sum / 2][n];
}
int Cutmax(int a, int b){ // A utility function to get the maximum of two integers
	return(a > b)? a : b;
}
int CutRod(int price[], int n){
	int val[n + 1];
	val[0] = 0;
	int i, j;
	for(i = 1; i <= n; i++){ //to create table and later start from the last.
		int max_val = INT_MIN;  //to determine min and max values.
		for(j = 0; j < i; j++){  //to take different parts and compare them in different configurations.
			max_val = Cutmax(max_val, price[j] + val[i - j - 1]);
		}
		val[i] = max_val;
	}
	return val[n];
}
int Pmax(int a, int b) { //maximum of 2 integers
	return (a > b)? a : b;
} 
int Pmax(int a, int b, int c) { //maximum of 2 integers
	return Pmax(a, Pmax(b, c));
}
int maxProd(int n){ //n is length of rope.
	int val[n + 1];
	val[0] = val[1] = 0;
	for(int i = 1; i <= n; i++){
		int max_val = 0;  //to get the maximum value from the cuts made.
		for(int j = 1; j <= i/2; j++){
			max_val = Pmax(max_val, (i - j) * j, j * val[i - j]);
		}
		val[i] = max_val; //to equalize val and maximum value
	}
	return val[n]; //to back maximum value
}
int findWays(int m, int n, int x) { 
    int table[n + 1][x + 1]; 
    memset(table, 0, sizeof(table)); // Initialize all entries as 0 
  
    // Table entries for only one dice 
    for (int j = 1; j <= m && j <= x; j++) 
        table[1][j] = 1; 
  
    // Fill rest of the entries in table using recursive relation 
    // i: number of dice, j: sum 
    for (int i = 2; i <= n; i++) 
        for (int j = 1; j <= x; j++) 
            for (int k = 1; k <= m && k < j; k++) 
                table[i][j] += table[i-1][j-k]; 
  
    return table[n][x]; 
}
int Coincount( int S[], int m, int n ) { 
    int i, j, x, y; 
 
    int table[n+1][m]; 
      
    for (i=0; i<m; i++) //to enter values for zero value
        table[0][i] = 1; //n is equal zero.
     
    for (i = 1; i < n+1; i++) 
    { 
        for (j = 0; j < m; j++) 
        {  
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0; //x is the number of includings[j]
   
            y = (j >= 1)? table[i][j-1]: 0; //y is sum of solutions including s[j]
  
            table[i][j] = x + y; //it's total number.
        } 
    } 
    return table[n][m-1]; 
}
bool isSubsetSum(int set[], int n, int sum){ //bool is used true-false question.
    bool subset[n + 1][sum + 1]; //
 
    for (int i = 0; i <= n; i++) //if result is zero, answer is true in this part.
        subset[i][0] = true;
 
    for (int i = 1; i <= sum; i++) //if result is zero, answer is false in this part.
        subset[0][i] = false;
        
    for (int i = 1; i <= n; i++) { // to create subsetsum table. 
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1]) //if j is smaller than set
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1]) //if j is bigger than set[i-1], use this part.
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }
    return subset[n][sum];
}

int main(){
	int chart, option;
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; //for First case, it is a specific arrays
	int arr2[] = {3, 1, 4, 2, 2, 1};
	int arro[] = { 20, 30, 2, 2, 2, 10 };
    int n = sizeof(arr)/sizeof(arr[0]); 
    int n1 = sizeof(arr)/sizeof(arr[0]); 
    int no = sizeof(arro) / sizeof(arro[0]); 
    int dist = 4;
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n6 = sizeof(set) / sizeof(set[0]);
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n8 = sizeof(val) / sizeof(val[0]);
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    char X1[6];
    char Y1[7];
    int arr11[] = { 3, 1, 1, 2, 2, 1 };
    int n11 = sizeof(arr11) / sizeof(arr11[0]);
    int arr12[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int size12 = sizeof(arr12)/sizeof(arr12[0]);
    int arr13[] = {1, 2, 3}; 
    int m13 = sizeof(arr13)/sizeof(arr13[0]); 
    int n13 = 4;
	printf("DP-1: Longest Increasing Subsequence\nDP-2: Edit Distance\n");
	printf("DP-3: Partition a set into two subsets such that the difference of subset sums is minimum\nDP-4: Count number of ways to cover a distance\nDP-5: Find the longest path in a matrix with given constraints");
	printf("DP-6: Subset Sum Problem\nDP-7: Optimal Strategy for a Game\nDP-8: 0-1 Knapsack Problem\nDP-9: Boolean Parenthesization Problem\nDP-10: Shortest Common Supersequence\nDP-11: Partition Problem\nDP-12: Cutting a Rod");
	printf("DP-13: Coin Change\nDP-14: Word Break Problem\nDP-15: Maximum Product Cutting\nDP-16: Dice Throw\nDP-17: Box Stacking Problem\nDP-18: Egg Dropping Puzzle");
	printf("\nPlease enter the number to choose example algorithms!!\n");
	scanf("%d",&chart);
	
	switch(chart){  //to create application menu.
		case 1:
			printf("Which option do you want to look at the algorithm?\n1-)Set pre-defined inputs for easy testing\n2-)Enter input for manuel testing.\n");
			scanf("%d", &option);  //to take the entered number and process it.
			switch(option){  //to create 2 option manuel testing and easy testing. 
				case 1:
					printf("\nLength of lis is %dn\n", lis( arr, n )); //to show LIS results
					break;
				case 2:
					int x = 0; //to determine numbers will entered.
					printf("How many numbers do you want to be calculated ?");
					scanf("%d", &x);
					int arr1[x]; //to save and process the entered numbers as an array
					for(int i = 0; i < x; i++){ //loop through which numbers to be entered are printed.
						printf("Enter the %d number to calculate:", i + 1);
						scanf("%d", &arr1[i]);
					}
					int size = sizeof(arr1)/sizeof(arr1[0]);
					printf("\nLength of lis is %d\n", lis(arr1, size)); //to show LIS results
					break;
			}
			break;
		case 3:
			printf("Which option do you want to look at the algorithm?\n1-)Set pre-defined inputs for easy testing\n2-)Enter input for manuel testing.\n");
			scanf("%d", &option); //to take the entered number and process it
			switch(option){  //to create 2 option manuel testing and easy testing.
				case 1:
					printf("The minimum difference between 2 sets is %d\n", findMin(arr2,n1)); //to show findMin results
					break;
				case 2:
					int x = 0; //to save and process the entered numbers as an array
					printf("How many numbers do you want to be calculated ?");
					scanf("%d", &x);
					int arr21[x]; //to save and process the entered numbers as an array
					for(int i = 0; i < x; i++){ //loop through which numbers to be entered are printed.
						printf("Enter the %d number to calculate:", i + 1);
						scanf("%d", &arr21[i]);
					}
					int n12 = sizeof(arr21)/sizeof(arr21[0]);
					printf("\nThe minimum difference between 2 sets is %d\n", findMin(arr21, n12)); //to show findMin results
					break;		
			}
			break;
		case 4:
			printf("Which option do you want to look at the algorithm?\n1-)Set pre-defined inputs for easy testing\n2-)Enter input for manuel testing.\n");
			scanf("%d", &option); //to take the entered number and process it
			switch(option){  //to create 2 option manuel testing and easy testing.
				case 1:
					printf("%d", printCountRec(dist)); //to show printCountRec results
					return 0;
					break;
				case 2:
					int dist1;  //to specify integer for function
					printf("Please enter number for manuel calculation:");
					scanf("%d",&dist1);
					printf("Result is %d", printCountRec(dist1)); //to show printCountRec results
					return 0;
					break;
			}
			break;
		case 6:
			printf("Which option do you want to look at the algorithm?\n1-)Set pre-defined inputs for easy testing\n2-)Enter input for manuel testing.\n");
			scanf("%d", &option); //to take the entered number and process it
			switch(option){   //to create 2 option manuel testing and easy testing.
				case 1:
    				if (isSubsetSum(set, n6, sum) == true)  
        				printf("Found a subset with given sum");
    				else
        				printf("No subset with given sum");
    				return 0;
					break;
				case 2:
					int x = 0; //to save and process the entered numbers as an array
					printf("How many set numbers do you want to be calculated ?");
					scanf("%d", &x);
					int set[x]; //to save and process the entered numbers as an array
					for(int i = 0; i < x; i++){ //loop through which numbers to be entered are printed.
						printf("Enter the %d number to calculate:", i + 1);
						scanf("%d", &set[i]);
					}
					int sum;
					printf("Please enter number of sum:");
					scanf("%d", &sum);
					int n = sizeof(set)/sizeof(set[0]);
					if (isSubsetSum(set, n, sum) == true){
        			printf("Found a subset with given sum");
        			}
    				else
        			printf("No subset with given sum");
    				return 0;
					break;
			}
			break;		
		case 7:
			printf("Which option do you want to look at the algorithm?\n1-)Set pre-defined inputs for easy testing\n2-)Enter input for manuel testing.\n");
			scanf("%d", &option); //to take the entered number and process it
			switch(option){   //to create 2 option manuel testing and easy testing.
				case 1:
    				printf("%d\n", optimalStrategyOfGame(arro, no));  //to show optimalStrategyOfGame results
    				return 0;
					break;
				case 2:
					int x = 0; //to save and process the entered numbers as an array
					printf("How many numbers do you want to be calculated ?");
					scanf("%d", &x);
					int arr21[x]; //to save and process the entered numbers as an array
					for(int i = 0; i < x; i++){ //loop through which numbers to be entered are printed.
						printf("Enter the %d number to calculate:", i + 1);
						scanf("%d", &arr21[i]);
					}
					int n12 = sizeof(arr21)/sizeof(arr21[0]);
					printf("\nThe result of numbers entered is %d\n", optimalStrategyOfGame(arr21, n12)); //to show optimalStrategyOfGame results
					break;
			}
			break;
		case 8:
			printf("Which option do you want to look at the algorithm?\n1-)Set pre-defined inputs for easy testing\n2-)Enter input for manuel testing.\n");
			scanf("%d", &option); //to take the entered number and process it
			switch(option){   //to create 2 option manuel testing and easy testing.
				case 1:
					printf("%d", knapSack(W, wt, val, n8)); //to show knapSack results
    				return 0;
					break;
				case 2:
					int x =0; 
					printf("\nPlease enter how many value items do you want:\n");
					scanf("%d",&x);
					int val1[x]; //to save and process the entered numbers as an array
					for(int i = 0; i < x; i++){  //loop through which numbers to be entered are printed.
						printf("Please the %d value:", i + 1);
						scanf("%d", &val1[x]);
					}
					printf("\nPlease enter how many weight items do you want:\n");
					scanf("%d", &x);
					int wt1[x];
					for(int i = 0; i < x; i++){
						printf("Please the %d weight:", i + 1);
						scanf("%d", &wt1[x]);
					}
					int W1;
					printf("\nPlease enter W number:\n");
					scanf("%d", &W1);
					int n = sizeof(val1) / sizeof(val1[0]);
					printf("\n%d", knapSack(W1, wt1, val1, n)); //to show knapSack results
					return 0;
					break;
			}
			break;	
		case 10:
			printf("Which option do you want to look at the algorithm?\n1-)Set pre-defined inputs for easy testing\n2-)Enter input for manuel testing.\n");
			scanf("%d", &option);  //to take the entered number and process it
			switch(option){   //to create 2 option manuel testing and easy testing.
				case 1:
   					printf("Length of the shortest supersequence is %d", shortestSS(X, Y)); //to show shortestSS results
    				return 0;
    				break;
    			case 2:
    				printf("Please enter 6 X letters:");
    				scanf("%s", &X1);
    				printf("Please enter 7 Y letters:");
    				scanf("%s", &Y1);
    				printf("Length of the shortest supersequence is %d", shortestSS(X1, Y1)); //to show shortestSS results
    				break;
			}
			break;
		case 11:
			printf("Which option do you want to look at the algorithm?\n1-)Set pre-defined inputs for easy testing\n2-)Enter input for manuel testing.\n");
			scanf("%d", &option);  //to take the entered number and process it
			switch(option){   //to create 2 option manuel testing and easy testing.
				case 1: 
    				if (findPartiion(arr11, n11) == true){
        			printf("Can be divided into two subsets of equal sum");
					}else{
        			printf("Can not be divided into two subsets of ""equal sum");
					}
    				getchar();
    				return 0;
					break;
				case 2:
					int x = 6; 
					printf("Please enter 6 numbers:\n");
					int arr[x]; //to save and process the entered numbers as an array
					for(int i = 0; i < x; i++){  //loop through which numbers to be entered are printed.
						printf("Enter the %d number to calculate:", i + 1);
						scanf("%d", &arr[i]);
					}
					int n = sizeof(arr)/sizeof(arr[0]);
					if (findPartiion(arr, n) == true){
        			printf("Can be divided into two subsets of equal sum");
					}else{
        			printf("Can not be divided into two subsets of ""equal sum");
					}
    				getchar();
    				return 0;
					break;
			}
			break;
		case 12:
			printf("Which option do you want to look at the algorithm?\n1-)Set pre-defined inputs for easy testing\n2-)Enter input for manuel testing.\n");
			scanf("%d", &option);  //to take the entered number and process it
			switch(option){   //to create 2 option manuel testing and easy testing.
				case 1: 
    				printf("Maximum Obtainable Value is %dn", CutRod(arr12, size12));  //to show CutRod results
    				getchar(); 
    				return 0; 
					break;
				case 2:
					int x = 0; 
					printf("How many numbers do you want to be calculated ?");
					scanf("%d", &x);
					int arr[x]; //to save and process the entered numbers as an array
					for(int i = 0; i < x; i++){  //loop through which numbers to be entered are printed.
						printf("Enter the %d number to calculate:", i + 1);
						scanf("%d", &arr[i]);
					}
					int n = sizeof(arr)/sizeof(arr[0]);
					printf("\nMaximum Obtainable Value is %dn\n", CutRod(arr, n)); //to show CutRod results
					break;
			}
			break;
		case 13:
			printf("Which option do you want to look at the algorithm?\n1-)Set pre-defined inputs for easy testing\n2-)Enter input for manuel testing.\n");
			scanf("%d", &option);  //to take the entered number and process it
			switch(option){    //to create 2 option manuel testing and easy testing.
				case 1: 
    				printf(" %d ", Coincount(arr13, m13, n13)); //to show Coincount results
    				return 0;
					break;
				case 2:
					int x = 3; 
					printf("Please enter 3 numbers\n");
					int arr[x]; //to save and process the entered numbers as an array
					for(int i = 0; i < x; i++){  //loop through which numbers to be entered are printed.
						printf("Enter the %d number to calculate:", i + 1);
						scanf("%d", &arr[i]);
					}
					int n;
					printf("Please enter one number:\n");
					scanf("%d", &n);
					int m = sizeof(arr)/sizeof(arr[0]);
					printf("\nThe result is %d\n", Coincount(arr, m, n)); //to show Coincount results
					break;
				}
				break;
		case 15:
			printf("Which option do you want to look at the algorithm?\n1-)Set pre-defined inputs for easy testing\n2-)Enter input for manuel testing.\n");
			scanf("%d", &option);  //to take the entered number and process it
			switch(option){    //to create 2 option manuel testing and easy testing.
				case 1:
					printf("Maximum product is %d", maxProd(10)); //to show maxProd results
					return 0;
					break;
				case 2:
					int n; //to save and process the entered numbers as an array
					printf("Please enter number to calculate maximum product:");
					scanf("%d", &n);
					printf("Maximum product is %d", maxProd(n)); //to show maxProd results
					return 0;
					break;
			}
			break;
		case 16:
			printf("Which option do you want to look at the algorithm?\n1-)Set pre-defined inputs for easy testing\n2-)Enter input for manuel testing.\n");
			scanf("%d", &option);  //to take the entered number and process it
			switch(option){    //to create 2 option manuel testing and easy testing.
				case 1:
					printf("%d", findWays(4, 2, 1));  //to show findWays results
    				return 0; 
					break;
				case 2:
					int m16, n16, x16; //to save and process the entered numbers as an array
					printf("Enter Three numbers\n");
					printf("First:");  //to enter m value 
					scanf("%d", &m16);
					printf("Second:");  //to enter n value
					scanf("%d", &n16);
					printf("Third:");  //to enter x value
					scanf("%d", &x16);
					printf("The result is %d", findWays(m16, n16, x16)); //to show findWays results
					return 0;
					break;
			}
			break;
		case 18:
			printf("Which option do you want to look at the algorithm?\n1-)Set pre-defined inputs for easy testing\n2-)Enter input for manuel testing.\n");
			scanf("%d", &option);  //to take the entered number and process it
			int n = 2, k = 36;  //to determine integers in eggDrop
			int n1, k1;
			switch(option){   //to create 2 option manuel testing and easy testing.
				case 1:
					printf("\nMinimum number of trials in worst case with %d eggs and %d floors is %d \n", n, k, eggDrop(n, k)); //to show eggDrop results
					return 0;
					break;
				case 2:
					printf("Please enter two number for calculation\nFirst number:\n");
					scanf("%d", &n1);  //to enter n1 value
					printf("Second number:\n");
					scanf("%d", &k1);  //to enter k1 value
					printf("Minimum number of trials in worts case with %d eggs and %d floors is %d \n", n1, k1, eggDrop(n,k)); //to show eggDrop results
					break;
			}
			break;		
	}
	return 0;
}
