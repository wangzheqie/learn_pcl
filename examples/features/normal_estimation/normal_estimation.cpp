/*************************************************************************
	> File Name: normal_estimation.cpp
	> Author: wangzheqie At: https://github.com/wangzheqie
	> Mail: wangzheqie@qq.com
	> Created Time: Wed 28 Mar 2018 11:39:16 AM CST
 ************************************************************************/

#include <iostream>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>

using namespace std;

typedef pcl::PointCloud<pcl::PointXYZ> PointT;
typedef pcl::search::KdTree<pcl::PointXYZ> KDTREE;
typedef pcl::PointCloud<pcl::Normal> PNM;
typedef pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> NMEST;

void func1(int argc, char** argv)
{
    PointT::Ptr cloud (new PointT);
    pcl::io::loadPLYFile(argv[1], *cloud);
    cout<<"size : "<<cloud->points.size()<<endl;

    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne; 
    ne.setInputCloud(cloud);
    KDTREE::Ptr tree (new KDTREE);
    ne.setSearchMethod(tree);
    PNM::Ptr normals (new PNM);
    ne.setKSearch(200);
//    ne.setRadiusSearch(0.1);
    // use KSearch instead of radiusSearch when points is rare 
    ne.compute(*normals);
    
    cout<<"normal size: "<<normals->points.size()<<endl;
    
    for (size_t i = 0; i < normals->points.size(); i++)
    {
        cout<<normals->points[i].normal_x
        <<normals->points[i].normal_y
        <<normals->points[i].normal_z
        <<normals->points[i].curvature;
    }

}

void func2(int argc, char** argv)
{
    PointT::Ptr cloud (new PointT);
    pcl::io::loadPLYFile(argv[1], *cloud);
    cout<<"size : "<<cloud->points.size()<<endl;

    std::vector<int> indices (floor (cloud->points.size() / 10));
    for(size_t i = 0; i < indices.size(); i++)
    {
        indices[i] = i;
    }
    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne; 
    ne.setInputCloud(cloud);
    KDTREE::Ptr tree (new KDTREE);
    ne.setSearchMethod(tree);

    //pass the indices 
    boost::shared_ptr<std::vector<int> > indicesptr (new std::vector<int> (indices));
    ne.setIndices (indicesptr);

    PNM::Ptr normals  (new PNM);
    ne.setKSearch(100);
//    ne.setRadiusSearch(0.40);
    //TODO: determine how much points will be choose when use radius search 
    ne.compute(*normals);

    cout<<normals<<endl;

    cout<<"normal size: "<<normals->points.size()<<endl;
    
    for (size_t i = 0; i < normals->points.size(); i++)
    {
        cout<<normals->points[i].normal_x
        <<normals->points[i].normal_y
        <<normals->points[i].normal_z
        <<normals->points[i].curvature;
    }
    
}
void func3(int argc, char** argv)
{
    PointT::Ptr cloud (new PointT);
    PointT::Ptr cloud_downsampled (new PointT);
    pcl::io::loadPLYFile(argv[1], *cloud);
    pcl::io::loadPLYFile(argv[2], *cloud_downsampled);


    PNM::Ptr normals (new PNM);
    NMEST ne; 
    ne.setInputCloud(cloud_downsampled);
    ne.setSearchSurface(cloud);
    KDTREE::Ptr tree (new KDTREE);
    ne.setSearchMethod(tree);
//    ne.setRadiusSearch(0.3); //lots of nan 
    ne.setKSearch(100);
    ne.compute(*normals);

    cout<<normals<<endl;

    cout<<"normal size: "<<normals->points.size()<<endl;
    
    for (size_t i = 0; i < normals->points.size(); i++)
    {
        cout<<normals->points[i].normal_x
        <<normals->points[i].normal_y
        <<normals->points[i].normal_z
        <<normals->points[i].curvature;
    }



}
int main(int argc, char** argv)
{
//    func1(argc, argv);
//    func2(argc, argv);
    func3(argc, argv);
    return 0;
}

