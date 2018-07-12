/*************************************************************************
	> File Name: cloud_viewer.cpp
	> Author: wangzheqie At: https://github.com/wangzheqie
	> Mail: wangzheqie@qq.com
	> Created Time: Tue 03 Apr 2018 01:30:01 PM CST
 ************************************************************************/

#include <iostream>
#include <pcl/io/ply_io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/io.h>
#include <pcl/visualization/cloud_viewer.h>


using namespace std;

typedef pcl::PointCloud<pcl::PointXYZRGBA> PCT;
typedef pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> HANDLER;

int main(int argc, char** argv)
{
    PCT::Ptr cloud(new PCT);
    std::string dir(argv[1]);
    pcl::io::loadPLYFile(dir , *cloud);
    cout<<cloud->points.size()<<endl;
    size_t sz = cloud->points.size();

    for (size_t i = 0; i < sz ; i++){
        cloud->points[i].x = cloud->points[i].x * 1000.0 ;
        cloud->points[i].y = cloud->points[i].y * 1000.0 ;
        cloud->points[i].z = cloud->points[i].z * 1000.0 ;
        cloud->points[i].rgba = 0;
    }

    pcl::io::savePCDFile(argv[2], *cloud);


    pcl::visualization::CloudViewer viewer("cloud viewer");
    viewer.showCloud(cloud);

//    viewer.runOnVisualizationThreadOnce(func);
//    viewer.runOnVisualizationThread(func)
    
//    viewer.spin();

    while(! viewer.wasStopped())
    {

    }
    return 0;

}
