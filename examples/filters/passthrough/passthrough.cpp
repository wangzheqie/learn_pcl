/*************************************************************************
	> File Name: passthrough.cpp
	> Author: wangzheqie At: https://github.com/wangzheqie
	> Mail: wangzheqie@qq.com
	> Created Time: Thu 26 Apr 2018 11:34:53 AM CST
 ************************************************************************/

#include <iostream>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/passthrough.h> 
#include <pcl/visualization/pcl_visualizer.h>

using namespace std;

int main(int argc ,char** argv)
{

    pcl::PointCloud<pcl::PointXYZ>::Ptr  cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr  cloud_cropped(new pcl::PointCloud<pcl::PointXYZ>);


    pcl::io::loadPCDFile(argv[1],*cloud);

    cout<<cloud->size()<<endl; 

    pcl::PassThrough<pcl::PointXYZ> pass; 
    pass.setInputCloud(cloud);
    pass.setFilterFieldName("x");
    pass.setFilterLimits(-1.0, 0.0);
//    pass.setFilterLimitsNegative(true);
    pass.filter(*cloud_cropped);

    cout<<argv[2]<<endl;
    pcl::io::savePCDFile(argv[2], *cloud_cropped);

    return 0;
}


