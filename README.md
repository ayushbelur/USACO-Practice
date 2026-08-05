# USACO Practice Solutions

**This repository contains USACO practice problems from past years that I complete.**

*In this README file, I will show the logic of every problem completed.*

---

## 🥉 Bronze Division

| Problem Name | Contest | Solution Link | Logic / Explanation |
| :--- | :--- | :--- | :--- |
| **Air Cownditioning** | 2021 December | [View Code](./USACO_Bronze_2021_Dec_AirCownditioning.cpp) | *To do this problem, we can notice that for every cow/stall, there is a certain temperature change needed to get to the optimal temperature. To represent this, we can use an array (called `needed`) that stores the amount of change per stall. We can observe that we need to make the difference of every adjacent value in this array 0, as all values in the array `needed` have to become 0. We can call this array of the difference of adjacent values `diff`, where `diff[i] = abs(needed[i + 1] - needed[i])`. Every time we change a certain range by -1 or +1, starting from `i` to `j`, we see that `diff[i - 1]` and `diff[j]` get closer to 0. To say this, we know that when reducing or adding a segment, every number in that segment should be the same sign, to reduce the number of operations. If we don't include `needed[i - 1]` and `needed[j]`, that means they are opposite signs from the values in between them, which is why when changing the range, `diff[i - 1]` and `diff[j]` get closer to 0. Remembering that we need to make all values in the array `diff` = 0, and every time we change a range, we get 2 values closer to 0, and so the answer to this problem will just become the sum of all values of `diff` divided by 2.* |
| **Lonely Photo** | 2021 December | [View Code](./USACO_Bronze_2021_Dec_LonelyPhoto.cpp) |  |
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
