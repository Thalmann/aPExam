#include "stdafx.h"
#include "point.h"
#include <vector>
#include <algorithm>

namespace DBScan{
	/*DBSCAN(D, eps, MinPts)
   C = 0
   for each unvisited point P in dataset D
      mark P as visited
      NeighborPts = regionQuery(P, eps)
      if sizeof(NeighborPts) < MinPts
         mark P as NOISE
      else
         C = next cluster
         expandCluster(P, NeighborPts, C, eps, MinPts)
          
expandCluster(P, NeighborPts, C, eps, MinPts)
   add P to cluster C
   for each point P' in NeighborPts 
      if P' is not visited
         mark P' as visited
         NeighborPts' = regionQuery(P', eps)
         if sizeof(NeighborPts') >= MinPts
            NeighborPts = NeighborPts joined with NeighborPts'
      if P' is not yet member of any cluster
         add P' to cluster C
          
regionQuery(P, eps)
   return all points within P's eps-neighborhood (including P)*/
	using namespace std;

	
	vector<vector<Point>> DBScan(vector<Point> points, double eps, int minPts){
		vector<vector<Point>> clusters;

		for (auto &it : points)
		{
			if (!it.visited)
			{
				it.visited = true;
				vector<Point> neighbourPoints;
			}
		}

		return clusters;
	}

	template <typename vector<Point>::iterator it>
	vector<Point> regionQuery(Point p, vector<Point> points, double eps){
		vector<Point> neighbourPoints;

		
		for ( it : points)
		{
			if (eps < distance(it, p))
				neighbourPoints.push_back(it);
		}
		return neighbourPoints;
	}

	double distance(Point p1, Point p2){
		return sqrt(pow((p1.getX() - p2.getX()), 2) + pow((p1.getY() - p2.getY()), 2));
	}
}