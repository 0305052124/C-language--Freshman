#define _CRT_SECURE_NO_WARNINGS 1
//在《英雄联盟》的世界中，有一个叫“提莫”的英雄。他的攻击可以让敌方英雄艾希进入中毒状态。
//当提莫攻击艾希，艾希的中毒状态正好持续 duration 秒。
//正式地讲，提莫在t发起发起攻击意味着艾希在时间区间[t, t + duration - 1]（含 t 和 t + duration - 1）处于中毒状态。
//如果提莫在中毒影响结束前再次攻击，中毒状态计时器将会重置 ，在新的攻击之后，中毒影响将会在 duration 秒后结束。
//给你一个非递减的整数数组 timeSeries ，其中 timeSeries[i] 表示提莫在 timeSeries[i] 秒时对艾希发起攻击，
//以及一个表示中毒持续时间的整数 duration 。
//返回艾希处于中毒状态的总秒数。

//输入：timeSeries = [1, 4], duration = 2
//输出：4
//解释：提莫攻击对艾希的影响如下：
//- 第 1 秒，提莫攻击艾希并使其立即中毒。中毒状态会维持 2 秒，即第 1 秒和第 2 秒。
//- 第 4 秒，提莫再次攻击艾希，艾希中毒状态又持续 2 秒，即第 4 秒和第 5 秒。
//艾希在第 1、2、4、5 秒处于中毒状态，所以总中毒秒数是 4 。
//
//
//输入：timeSeries = [1, 2], duration = 2
//输出：3
//解释：提莫攻击对艾希的影响如下：
//- 第 1 秒，提莫攻击艾希并使其立即中毒。中毒状态会维持 2 秒，即第 1 秒和第 2 秒。
//- 第 2 秒，提莫再次攻击艾希，并重置中毒计时器，艾希中毒状态需要持续 2 秒，即第 2 秒和第 3 秒。
//艾希在第 1、2、3 秒处于中毒状态，所以总中毒秒数是 3 。
#include<stdio.h>
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration)
{
    int time = duration;//起码有一个duration
    for (int i = 0; i < timeSeriesSize - 1; i++)
    {
        if (timeSeries[i] + duration > timeSeries[i + 1])
            time += (timeSeries[i + 1] - timeSeries[i]);
        else
            time += duration;
    }
    if (timeSeriesSize != 0)
        return time;
    else
        return 0;
}

int main()
{
    int a[2] = { 1,4 };
    printf("%d", findPoisonedDuration(a, 2, 2));
	return 0;
}
