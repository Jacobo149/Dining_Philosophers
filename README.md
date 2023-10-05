# Dining_Philosophers
![Dining Philosophers](https://res.cloudinary.com/practicaldev/image/fetch/s---imrjIOF--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://res.cloudinary.com/studio-mogwai/image/upload/v1581865192/Untitled_Artwork_5.png)
## What is the Dining Philosopher Problem
Five Philosophers, Sitting in a Circle  
Imagine that you're in charge of the eating arrangements of five sober philosophers sitting in a circle. On each side of them is a chopstick, which adds up to five chopsticks in total.  

The philosophers, naturally, love to think. But they're also there to eat. The only way that they can eat is if they have two chopsticks.  

How do you design a system (or algorithm, if you will) that ensures the philosophers can eat and think and eat and think and eat and think?  

System constraints  
There are three constraints to take into consideration here:  
a. Food is infinite, i.e. a philosopher can eat for as long as they want, and  
b. A philosopher can think for as long as they want.  
c. A philosopher can only eat when they have two chopsticks  

[Source](https://dev.to/vunderkind/the-dining-philosophers-problem-or-your-introduction-to-thinking-in-computer-science-8ii)


## Implemented Solution
In order to provide mutual exclusion, progress, and bounded waiting; we implemented a random napping() (Thread sleep() equivalent) time for each thread.  
Further odd threads reach for the left chopstick first while evens reach for the right.  
This provides a random and different behavior for each thread ensuring the algorithm does not reach deadlock.  

### Reliability
While the solution does its part to mitigate any deadlock, in certain situations (e.g. random function returns similar values) we achieve deadlock where all philosophers only have one chopstick.  
While the solution works 99.9% of the time, due to hinging on random function return values, it is not industry-implementable code.  

## How to Run

### Prerequisites
Download necessary packages (C, Make, GCC, Thread Library)

### Console Commands
- Navigate to dining_philosophers directory
- Compile to executable using Makefile
```
make
```
- Run executable
```
./dining_philosophers
```
