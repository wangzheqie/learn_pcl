/*************************************************************************
	> File Name: kdtree_search.cpp
	> Author: wangzheqie At: https://github.com/wangzheqie
	> Mail: wangzheqie@qq.com
	> Created Time: Mon 02 Apr 2018 10:25:09 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <ctime>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/kdtree/kdtree_flann.h>

using namespace std;

typedef pcl::PointCloud<pcl::PointXYZ> PCT;
typedef pcl::KdTreeFLANN<pcl::PointXYZ> KDTREE;

int main(int argc, char** argv)
{
    PCT::Ptr cloud (new PCT);
    if(pcl::io::loadPLYFile(argv[1], *cloud) < 0)
    {
        PCL_ERROR("cload file load error");
    }
    
    size_t sz = cloud->size();
    size_t k =10;
    std::vector<int> ids(k);
    std::vector<float> dists_sqr(k);
    KDTREE tree; 
    tree.setInputCloud(cloud);
    pcl::PointXYZ search_point = cloud->points[rand() % sz];

    tree.nearestKSearch(search_point, k, ids, dists_sqr);

    for(size_t i =0 ;i<k; i++)
    {
        cout<<ids[i]<<endl;
        cout<<dists_sqr[i]<<endl;
    }

    std::vector<int> ids_radius;
    std::vector<float> dists_sqr_radius;
    //search inside 10.0 mm^2 area
    float radius  = 1.0f * rand() /(RAND_MAX +1.0f);
    cout<<radius<<endl;

    tree.radiusSearch(search_point, radius, ids_radius, dists_sqr_radius);

    for(size_t i =0 ;i < ids_radius.size(); i++)
    {
        cout<<"the radius size is "<<ids_radius.size()<<endl;
        cout<<ids_radius[i]<<"  -- " <<dists_sqr_radius[i]<<endl;
    }
    return 0 ;

}
