# USACO Practice Solutions

**This repository contains USACO practice problems from past years that I complete.**

*In this README file, I will show the logic of every problem completed.*

---

## 🥉 Bronze Division

| Problem Name | Contest | Solution Link | Logic / Explanation |
| :--- | :--- | :--- | :--- |
| **Air Cownditioning** | 2021 December | [View Code](./USACO_Bronze_2021_Dec_AirCownditioning.cpp) | *To do this problem, we can notice that for every cow/stall, there is a certain temperature change needed to get to the optimal temperature. To represent this, we can use an array (called `needed`) that stores the amount of change per stall. We can observe that we need to make the difference of every adjacent value in this array 0, as all values in the array `needed` have to become 0. We can call this array of the difference of adjacent values `diff`, where `diff[i] = abs(needed[i + 1] - needed[i])`. Every time we change a certain range by -1 or +1, starting from `i` to `j`, we see that `diff[i - 1]` and `diff[j]` get closer to 0. To say this, we know that when reducing or adding a segment, every number in that segment should be the same sign, to reduce the number of operations. If we don't include `needed[i - 1]` and `needed[j]`, that means they are opposite signs from the values in between them, which is why when changing the range, `diff[i - 1]` and `diff[j]` get closer to 0. Remembering that we need to make all values in the array `diff` = 0, and every time we change a range, we get 2 values closer to 0, and so the answer to this problem will just become the sum of all values of `diff` divided by 2.* |
| **Lonely Photo** | 2021 December | [View Code](./USACO_Bronze_2021_Dec_LonelyPhoto.cpp) | *To find the number of all the lonely photos, we can iterate across the array of `N` cows, and for each cow, see how many different photos will make that cow lonely. As only one cow per photo can be lonely for a lonely photo, by doing this, we make sure we aren't overcounting. To find the number of lonely photos for each cow, we first find the number of lonely photos we can make using that cow and all of its consecutive neighbors to the left. You can iterate to the left and see how many cows are different from the lonely cow. You can do the same for the right. We already have the number of lonely photos to just the left and right. We can notice that since there are only two breeds, the consecutive cows to the left and right must all be the same breed as each other. The result of any combination of the right and left cows will always end up as a lonely photo because of this. And so, the answer for the number of the lonely photos for that lonely cow is just the sum of the lonely photos to the left, the number of lonely photos to the right, and the number of combinations possible with the left and right cows. This can be represented as `left_photos[i] + right_photos[i] + (left_photos[i] + 1) * (right_photos[i] + 1)` for all `i` from 1 to `n`.* |
| **Hungry Cow** | 2023 February | [View Code](./USACO_Bronze_2023_Feb_HungryCow.cpp) |  |
| **Stamp Grid** | 2023 February | [View Code](./USACO_Bronze_2023_Feb_StampGrid.cpp) |  |
| **Watching MooLoo** | 2023 February | [View Code](./USACO_Bronze_2023_Feb_WatchingMooLoo.cpp) |  |

---

## 🥈 Silver Division

| Problem Name | Contest | Solution Link | Logic / Explanation |
| :--- | :--- | :--- | :--- |
| **Closest Cow Wins** | 2021 December | [View Code](./USACO_Silver_2021_Dec_ClosestCowWins.cpp) |  |
| **Connecting Two Barns** | 2021 December | [View Code](./USACO_Silver_2021_Dec_ConnectingTwoBarns.cpp) |  |
| **Convoluted Intervals** | 2021 December | [View Code](./USACO_Silver_2021_Dec_ConvolutedIntervals.cpp) |  |
| **Redistributing Gifts** | 2022 February | [View Code](./USACO_Silver_2022_Feb_RedistributingGifts.cpp) |  |
| **Robot Instructions** | 2022 February | [View Code](./USACO_Silver_2022_Feb_RobotInstructions.cpp) |  |
| **Cereal 2** | 2022 January | [View Code](./USACO_Silver_2022_Jan_Cereal2.cpp) |  |
| **Cow Frisbee** | 2022 January | [View Code](./USACO_Silver_2022_Jan_CowFrisbee.cpp) |  |
| **Searching For Soulmates** | 2022 January | [View Code](./USACO_Silver_2022_Jan_SearchingForSoulmates.cpp) |  |
| **Bakery** | 2023 February | [View Code](./USACO_Silver_2023_Feb_Bakery.cpp) |  |
| **Cow-Libi** | 2023 February | [View Code](./USACO_Silver_2023_Feb_Cow-Libi.cpp) |  |
| **Moo Route II** | 2023 February | [View Code](./USACO_Silver_2023_Feb_MooRoute_II.cpp) |  |
| **Find And Replace** | 2023 January | [View Code](./USACO_Silver_2023_Jan_FindAndReplace.cpp) |  |
| **Following Directions** | 2023 January | [View Code](./USACO_Silver_2023_Jan_FollowingDirections.cpp) |  |
| **Moo Route** | 2023 January | [View Code](./USACO_Silver_2023_Jan_MooRoute.cpp) |  |
