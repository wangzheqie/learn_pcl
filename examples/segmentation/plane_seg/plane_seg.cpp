/*************************************************************************
	> File Name: plane_seg.cpp
	> Author: wangzheqie At: https://github.com/wangzheqie
	> Mail: wangzheqie@qq.com
	> Created Time: Tue 03 Apr 2018 09:01:11 AM CST
 ************************************************************************/

#include <iostream>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/visualization/pcl_visualizer.h>

using namespace std;

typedef pcl::PointCloud<pcl::PointXYZ> PCT;
typedef pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> HANDLER;

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
    PCT::Ptr cloud(new PCT);
    PCT::Ptr seg_cloud (new PCT);
    std::string dir(argv[1]);
    pcl::io::loadPLYFile(dir + "/PointCloud.ply", *cloud);

    pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
    pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
    pcl::SACSegmentation<pcl::PointXYZ> seg;

    
    seg.setOptimizeCoefficients(true);
    seg.setModelType (pcl::SACMODEL_PLANE);
    seg.setMethodType (pcl::SAC_RANSAC);
    seg.setMaxIterations(1000);
    seg.setDistanceThreshold(5);
    seg.setInputCloud(cloud);
    seg.segment (*inliers, *coefficients);

    cout<<inliers->indices.size()<<endl;
    size_t sz = inliers->indices.size();
    seg_cloud->points.resize(sz);
    for(size_t i =0; i<sz; i++)
    {
        seg_cloud->points[i] = cloud->points[inliers->indices[i]];
    }
        int color_red[3]={255, 100, 0}, color_blue[3]={0, 100, 255};
        showCloud(cloud, seg_cloud, color_red, color_blue ,"cloud");


    return 0;
}

