# Mergesort
## About
I've been very bored as of lately ~ courtesy of COVID-19 ~ and have made it a goal to start attempting to implement various algorithms to practice algorithmic approach and design -- starting relatively basic with the merge sort algorithm. I chose to implement this algorithm using C, as it is a language that I feel comfortable with when using recursive techniques.

This implementation of merge sort is done recursively, using the Mergesort() function to recursively *divide* the array into smaller, more manageable parts, and the Merge() function uses the concept of the "two finger algorithm" to sort the two subarrays and *conquer* them. In addition, the merging portion of the algorithm is done in-place, so no auxillary space in memory is used other than what is dynamically allocated using **malloc()**.

This also contains a simple bash script **ruh.sh** that both compiles and executes the program. If you download and attempt to run this, please note that the shebang and variable names are suited to my machine. You might have to add executable permissions in order to run it.

If you have any suggestions as to how to make this more efficient, please let me know!

Happy coding!

### Contents
- Mergesort.c
- run.sh
- input