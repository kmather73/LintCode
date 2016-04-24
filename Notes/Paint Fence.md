This problem is in the form of a DP since there is optimal substructure.

First we start with the bases cases
1) if there is one post and K colors then we can color it in K ways

2) if there are two posts then we can color with one color in K ways and in two ways the first post in K ways and the second post can then be colored in K-1 ways hence we can color the fence in K * (K-1) + K


Now lets say that we have n posts. If we know how to color a fence with n-1 posts then we can add another post at the end and color it with a differnt colour we could pick any color different then the previous post i.e K-1 ways and put it at the end. And if we want the new post to be the same color as the previous post then it is the same as adding two post at the end of a fence with n-2 post. We then colour the two new posts in k-1 ways. Hence we get the recurence DP[n] = DP[n-1] * (k-1) + DP[n-2] * (k-1) 

Now since the number of ways to color a fence of size n only depends on the number of ways to color fences of size n-1 and n-2 we only need to store three values at a time.
