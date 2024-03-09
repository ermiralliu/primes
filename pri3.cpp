#include<iostream>
#include<math.h>
#include<time.h>
#include<vector>

//bool isPrime(int, const std::vector<int>&);
std::vector<int> primeCounter(int n);
inline bool isPrime(int number, const std::vector<int>& currentPrimes){
    const int max = (int) sqrt(number); //if a number doesn't have prime divisors root of itself it wont have any, since the divisors are kind of complemetary yk
    for(int j=0; currentPrimes[j]<= max; ++j)
        if(number % currentPrimes[j] == 0)
            return false;        
    return true;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n=1;
    while(n>0){
        std::cout<<"Number: ";
        std::cin>>n;
        std::cin.tie(NULL);
        if(n<=1){
            std::cout<<"\ninvalid input, enter n>1\n";
            continue;
        }
        clock_t start_time = clock();
        const std::vector<int> array = primeCounter(n);
        int manyPrimes = array.size(); //using vector.size was dumb af since we preallocated more than needed
        for(int i=0; i < manyPrimes; ++i)
             std::cout<<array[i]<<" ";
        double elapsed_time = (double)(clock() - start_time) / (CLOCKS_PER_SEC/1000); //in milliseconds
        std::cout<<"\nActual number of primes: "<< manyPrimes+1<<"\n";
        std::cout<<"\nElapsed time:" <<elapsed_time<< std::endl;
    }
    return 0;
}

std::vector<int> primeCounter(int n){
    int max_arr_size;
    if(n> 60184)
        max_arr_size= (int) (n/(log(n)-1.1));
    else if(n> 10)
        max_arr_size= (int) (n*log(4.0)/log(n));
    else
        max_arr_size = n/2 +1;
    std::cout<<"Expected no. of primes: "<<max_arr_size<<"\n";
    std::vector<int> array(max_arr_size);
    int array_index;
    if(n>1) array[0] = 2, array_index =0;
    if(n>=3) array[1] = 3, array_index =1;
    if(n>=5) array[2] = 5, array_index = 2;
    for(int i=7; i<=n; i+=2){
        if(isPrime(i, array))
            array[++array_index] = i;
        i+=4;
        if(i>n)
            break;
        if(isPrime(i, array))
            array[++array_index] = i;
    }
    return array;
}


