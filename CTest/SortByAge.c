//
//  SortByAge.c
//  CTest
//
//  Created by wangyang on 2020/9/7.
//  Copyright © 2020 com.wy.personal. All rights reserved.
//

#include "SortByAge.h"
#include <stdio.h>
#include <string.h>

/*
 计数排序，员工年龄肯定在0-99之间
 */
void SortAge(int ages[],int len)
{
    if(ages == NULL || len < 1)
        return ;
    
    // timesOfAge相当于桶
    int timesOfAge[100];
    memset(timesOfAge,0,sizeof(timesOfAge));
    
    //计算每个年龄员工的个数
    for(int i = 0; i < len; i++)
    {
        // 对于正确的年龄，以年龄为索引，将该索引的桶取出来，并且++。每++一次表示该年龄人数+1
        if(ages[i] <= 99 && ages[i]>= 0) {
            timesOfAge[ages[i]]++;
        }
    }
    //
    /**
     此时，用了O(n)的空间timesOfAge，将所有员工的年龄换了一个方式存在了timesOfAge数组中：
     timesOfAge 的索引就是年龄
     timesOfAge 索引对应的value是该年龄的人数
     所以此时再遍历timesOfAge数组，把年龄大于0的取出来放到ages数组中。
     这样就以取巧的方式把原来的ages数组排序了。
     其实这道题算是桶排序的一个应用。
     */
    
    //对ages进行排序
    int index = 0;
    for(int i = 0; i < 100; i++)
    {
        for (int j = 0; j < timesOfAge[i]; j++) {
            ages[index] = i;
            ++index;
        }
    }
}

int testSortAge()
{
    int ages[] = {33,34,45,24,36,23,21,22,19,26,45,34,21,34,34,33,52,22,32,25,27,43,22,21,20,33,26,27,15,29};
    int len = 30;
    SortAge(ages,len);
    int i;
    for(i=0;i<len;i++)
        printf("%d ",ages[i]);
    printf("\n");
    return 0;
}
