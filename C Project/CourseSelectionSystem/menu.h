#include<stdio.h>
#include<displayCourseSources.h>
#include<inputCourseSources.h>
#include<queryCourseInfo.h>
#include<selectCourse.h>

int menu(){
    printf("1.录入课程\n2.查看所有课程\n3.查询课程\n4.选择课程\n请输入你想使用的功能");
    int n;
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        inputCourseSources();
        break;
    case 2:
        displayCourseSources();
        break;
    case 3:
        queryCourseInfo();
        break;
    case 4:
        selectCourse();
        break;
    case 5:
        return 0;
    default:
        return 1;
    }
}