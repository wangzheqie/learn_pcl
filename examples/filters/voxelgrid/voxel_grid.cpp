/*************************************************************************
	> File Name: voxelgrid.cpp
	> Author: wangzheqie At: https://github.com/wangzheqie
	> Mail: wangzheqie@qq.com
	> Created Time: Mon 02 Apr 2018 11:04:39 AM CST
 ************************************************************************/

#include <iostream>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/filters/voxel_grid.h>
using namespace std;

typedef pcl::PointCloud<pcl::PointXYZ> PCT;

int main(int argc, char** argv)
{
    PCT::Ptr cloud (new PCT);
    PCT::Ptr cloud_filtered (new PCT);
    pcl::io::loadPLYFile(argv[1], *cloud);

    cout<<cloud->size()<<endl;

    pcl::VoxelGrid<pcl::PointXYZ> vg;
    vg.setInputCloud(cloud);
    vg.setLeafSize(2,2,2);
    vg.filter(*cloud_filtered);

    cout<<cloud_filtered->size()<<endl;

    return 0;
}

