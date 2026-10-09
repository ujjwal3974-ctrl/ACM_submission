# ACM Student Chapter - Competitive Programming Recruitment 2026

Hello! This is my submission for the Competitive Programming domain.
I explained every solution in my own simple words, how I understood it.

## My profiles

- CSES: `y_ujjwal`
- LeetCode: https://leetcode.com/u/Ujjwal_121/
- GitHub: https://github.com/ujjwal3974-ctrl

## What I did

| # | Problem | Code written | Tested on sample | Accepted on CSES |
|---|---------|--------------|------------------|------------------|
| 01 | Factory Machines (1620) | Yes | Yes | Not yet |
| 02 | Movie Festival (1629) | Yes | Yes | Not yet |
| 03 | Subarray Sums II (1661) | Yes | Yes | Not yet |

I solved 3 problems out of 8 in Part A, and I did Part B also.

About "Not yet": when I tried to submit on CSES, it was only showing Rust in the
language option, so I could not submit my C++ code. I am still trying to fix it.
I tested all three codes with the sample inputs from the problem pages and the
answers were correct. I will change this table when I get Accepted.

## Folders

```
partA/
  factoryMachines.cpp     -> Problem 01
  movieFestival.cpp       -> Problem 02
  maxSubOptimial.cpp      -> Problem 03 (optimized solution)
partB/
  maxSubarraySumII.cpp    -> brute force
  maxSubOptimial.cpp      -> optimized
```

---

# Part A

## 01. Factory Machines

**What the question is asking:**
We have some machines. Each machine takes some seconds to make 1 product.
All machines work together at the same time. We need `t` products.
We have to find the minimum time.

**Small example:**
Machines take 3, 2, 5 seconds. We need 7 products.
In 8 seconds: 8/3 = 2 products, 8/2 = 4 products, 8/5 = 1 product.
2 + 4 + 1 = 7. So answer is 8.

**How I solved it:**
First I thought how to find the time directly, but that was hard.
Then I thought: what if I just guess a time and check if it is enough?
To check, I take the guessed time and divide by each machine's time, then add everything.
- If total products is `t` or more, the time is enough. So I try a smaller time.
- If total is less than `t`, the time is not enough. So I try a bigger time.

Doing this one by one is slow, so I used **binary search** on the time.
Every step I cut the search in half.

**Range of the search:**
Smallest time is 1. Biggest time is (fastest machine time) x t,
because in the worst case only the fastest machine makes everything.

**Things to remember:**
- I used `long long` because the numbers can be very big (up to 10^18).
- If products already become `t` or more in the loop, I break early.

**Time and space:**
- Time: O(n log(answer)). Binary search takes around 60 steps and in each step I check n machines.
- Space: O(n) for storing the machine times.

---

## 02. Movie Festival

**What the question is asking:**
We have n movies with start and end time. We can watch only one movie at a time.
We have to find the maximum number of movies we can watch fully.

**Small example:**
Movies: (3,5), (4,9), (5,8).
I watch (3,5). Then (5,8) starts at 5, same time the first one ends, so I can watch it.
(4,9) is not possible. Answer is 2.

**How I solved it:**
This is a greedy problem. The idea is: **pick the movie which ends the earliest.**
Steps:
1. Sort the movies by end time.
2. Keep a variable `lastEnd` (when my last movie finished).
3. Go through movies in order. If a movie starts at or after `lastEnd`, I watch it, count + 1, and update `lastEnd`.

**Why this works (my understanding):**
If a movie ends early, I have more free time left for the other movies.
So choosing the early-ending movie first is always the best choice.
I tried sorting by start time in my mind, but it fails: one very long movie that starts
first can block many small movies.

**Time and space:**
- Time: O(n log n), because of sorting. The loop after that is only O(n).
- Space: O(n) for storing movies.

---

## 03. Subarray Sums II

**What the question is asking:**
We have an array of n numbers (numbers can be negative also) and a target number.
We need to count how many subarrays have sum equal to target.
Subarray means a continuous part of the array.

**Small example:**
Array: 2 -1 3 5 -2, target = 7.
`[-1, 3, 5]` has sum 7 and the whole array also has sum 7. Answer is 2.

**How I solved it:**
The easy way is brute force (I wrote it in Part B), but it is slow.
For the fast way I used **prefix sum**. Prefix sum means the sum from the start of the array till now.

The main idea:
If my prefix sum till now is `currSum`, and I want a subarray ending here with sum = target,
then the prefix sum before that subarray must be `currSum - target`.

So at every position I ask: "how many times did I see `currSum - target` before?"
That count is the number of good subarrays ending at this position.
To remember old prefix sums I used an `unordered_map` (a hash map).
It stores: prefix sum -> how many times it came.

I put `mp[0] = 1` at the start. This is for the subarrays which start from the first element
(because before the array starts, the sum is 0).

**Things to remember:**
- I used `long long` for the sum, because many big numbers added can go outside `int`.
- Numbers can be negative, so I cannot use the two pointer method here. That is why the map is needed.

**Time and space:**
- Time: O(n) on average, because each map operation is O(1) on average.
- Space: O(n) for the map.

---

# Part B - Brute force to optimized

Problem: Subarray Sums II (CSES 1661)

## Brute force (`partB/maxSubarraySumII.cpp`)

I take every starting point `i` and every ending point `j`, and keep adding numbers.
If the sum becomes equal to target, I do count++.
It is simple, and I can be sure it is correct.

**Why it is too slow:**
In CSES, n can be up to 2 x 10^5 (200000). Two loops mean about n x n / 2 steps,
which is around 2 x 10^10. A computer can do only around 10^8 or 10^9 steps in one second,
so this will give Time Limit Exceeded.

## Optimized (`partB/maxSubOptimial.cpp`)

This is the prefix sum + hash map solution from Problem 03.
I go through the array only one time.

## Complexity

| | Time | Space |
|---|------|-------|
| Brute force | O(n^2) | O(1) extra (only the array) |
| Optimized | O(n) average | O(n) |

**Main idea of the speed up:**
In brute force, I add the same numbers again and again for different starting points.
In the optimized one, I remember the old prefix sums in a map, so I do not need to start again.
It uses some extra memory, but it saves a lot of time.

---

## How to run my code

```
g++ -O2 -o sol partA/factoryMachines.cpp
./sol
```
Then give the input. Change the file name for the other problems.

## What I learned

- Binary search can be used on the answer also, not only on a sorted array.
- In greedy problems, choosing what to sort by is the main thing.
- Prefix sum with a hash map can change O(n^2) into O(n).
- Use `long long` when numbers are big, otherwise overflow happens.
