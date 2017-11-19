#include <pcl/io/ply_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <string>
#include <iostream>
#include <boost/thread/thread.hpp>

using namespace pcl;
using namespace std;

PointCloud<PointXYZRGB>::Ptr loadPly(string path)
{
  PLYReader reader;
  PointCloud<PointXYZRGB>::Ptr cloud (new PointCloud<PointXYZRGB>);
  reader.read(path, *cloud);
  return cloud;
}

void showCloud(PointCloud<PointXYZRGB>::Ptr cloud)
{
  visualization::PCLVisualizer::Ptr viewer (new visualization::PCLVisualizer);
  viewer->addCoordinateSystem(1.0);
  viewer->setBackgroundColor (0, 0, 0);
  viewer->addPointCloud<PointXYZRGB> (cloud, "sample cloud");
  viewer->setPointCloudRenderingProperties (visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
  viewer->initCameraParameters ();
  while (!viewer->wasStopped())












  {
    viewer->spinOnce(100);
    boost::this_thread::sleep (boost::posix_time::microseconds (100000));
  }
}

int main(int argc, char ** args)
{
  if (argc != 2)
    cout << "Use: rosply cloud.ply. Go fuck yourself." << endl;
  string path (args[1]);
  PointCloud<PointXYZRGB>::Ptr c = loadPly(path);
  cout << c->size() << endl;
  showCloud(c);
  return 0;
}
