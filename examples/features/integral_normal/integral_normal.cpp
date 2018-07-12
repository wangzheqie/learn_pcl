/*************************************************************************
	> File Name: integral_normal.cpp
	> Author: wangzheqie At: https://github.com/wangzheqie
	> Mail: wangzheqie@qq.com
	> Created Time: Wed 28 Mar 2018 03:23:54 PM CST
 ************************************************************************/

#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/features/integral_image_normal.h>
#include <pcl/visualization/cloud_viewer.h>

using namespace std;

typedef pcl::PointCloud<pcl::PointXYZ> PointT; 
typedef pcl::PointCloud<pcl::Normal> PNM;

int main(int argc, char** argv)
{
    PointT::Ptr cloud (new PointT);
//    pcl::io::loadPLYFile(argv[1], *cloud);
    pcl::io::loadPCDFile(argv[1], *cloud);
    PNM::Ptr normals (new PNM);

    pcl::IntegralImageNormalEstimation<pcl::PointXYZ, pcl::Normal> ne; 
    ne.setNormalEstimationMethod(ne.AVERAGE_3D_GRADIENT);
    ne.setMaxDepthChangeFactor(0.02f);
    ne.setNormalSmoothingSize(10.0f);
    ne.setInputCloud(cloud);
    ne.compute(*normals);

    pcl::visualization::PCLVisualizer viewer("Viewer");
    viewer.setBackgroundColor(0.0 , 0.0, 0.5f);
    viewer.addPointCloudNormals<pcl::PointXYZ, pcl::Normal>(cloud, normals);

    while(!viewer.wasStopped())
    {
        viewer.spinOnce();
    }
    
    return 0;

}

