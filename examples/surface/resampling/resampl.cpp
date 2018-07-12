/*************************************************************************
	> File Name: resampling.cpp
	> Author: wangzheqie At: https://github.com/wangzheqie
	> Mail: wangzheqie@qq.com
	> Created Time: Tue 03 Apr 2018 11:07:17 AM CST
 ************************************************************************/

#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/mls.h>
#include <pcl/visualization/pcl_visualizer.h>

using namespace std;


typedef pcl::PointCloud<pcl::PointXYZ> PCT;
typedef pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> HANDLER;
typedef pcl::search::KdTree<pcl::PointXYZ> KDTREE;



void showCloud(PCT::Ptr cloud1, PCT::Ptr cloud2,  int *color1, int *color2,  std::string name="viewer")
{
    pcl::visualization::PCLVisualizer viewer(name);
    HANDLER  cloud1_color_h (cloud1, color1[0], color1[1], color1[2] );
    viewer.addPointCloud(cloud1, cloud1_color_h, "cloud1");
    HANDLER cloud2_color_h (cloud2, color2[0], color2[1], color2[2]);
    viewer.addPointCloud(cloud2, cloud2_color_h, "cloud2");

    viewer.setBackgroundColor(0,0,0);
    viewer.addCoordinateSystem(1.0);
    viewer.setSize(1280, 1024);

    while(!viewer.wasStopped())
    {
        viewer.spinOnce(0);
    }

};


int main(int argc, char** argv)
{
    PCT::Ptr cloud (new PCT);
    PCT::Ptr res_cloud (new PCT);
    std::string file(argv[1]);
    pcl::io::loadPLYFile(file , *cloud);

    KDTREE::Ptr tree (new KDTREE);

//    pcl::PointCloud<pcl::PointXYZ> mls_points;
    pcl::PointCloud<pcl::PointNormal> mls_points;
    pcl::MovingLeastSquares<pcl::PointXYZ, pcl::PointNormal> mls;
    //store the normals 
    mls.setComputeNormals (true);

    mls.setInputCloud(cloud);
    mls.setPolynomialOrder(3);
    mls.setSearchMethod(tree);
    mls.setSearchRadius(10);
    mls.process (mls_points);

    res_cloud->points.resize(mls_points.size());
    for(size_t i =0; i< mls_points.size() ; i++)
    {
        res_cloud->points[i].x = mls_points.points[i].x; 
        res_cloud->points[i].y = mls_points.points[i].y; 
        res_cloud->points[i].z = mls_points.points[i].z - 80; 
    }

    int color_yellow[3] ={255, 100,0}, color_blue[3] ={0, 100, 255};
    showCloud(cloud, res_cloud, color_yellow, color_blue, "cloud");

    return 0;
}

