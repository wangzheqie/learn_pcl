/*************************************************************************
	> File Name: statistical_outlier_removal.cpp
	> Author: wangzheqie At: https://github.com/wangzheqie
	> Mail: wangzheqie@qq.com
	> Created Time: Wed 09 May 2018 09:24:00 AM CST
 ************************************************************************/

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>

using namespace std;
typedef pcl::PointCloud<pcl::PointXYZ> PCT;

int main(int argc, char** argv)
{

    PCT::Ptr cloud (new PCT); 
    PCT::Ptr cloud_filtered (new PCT) ;
    
    pcl::PCDReader reader; 
    reader.read<pcl::PointXYZ> ("PointCloud.pcd", *cloud) ;

    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor; 
    sor.setInputCloud(cloud) ;
    sor.setMeanK(1000);
    sor.setStddevMulThresh(0.05); 
    sor.filter(*cloud_filtered);
    
    pcl::PCDWriter writer;
    writer.write<pcl::PointXYZ> ("cropedPointCloud_inliers.pcd", *cloud_filtered, false);

    sor.setNegative(true);
    sor.filter(*cloud_filtered);
    writer.write<pcl::PointXYZ> ("cropedPointCloud_outliers.pcd", *cloud_filtered, false);

    return 0;

}

